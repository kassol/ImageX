#include "StdAfx.h"
#include "FeatureDEM.h"
#include "CadLib.h"


#import "ImageX.tlb" no_namespace named_guids

HRESULT CFeatureDEM::CreateFeatureDEM(BSTR bstrRasterDEMFile,BSTR bstrFeatureFile,double lfBufferSize)
{
	//打开栅格DEM文件
	IDEM* pRasterDEM=NULL;
	HRESULT hRes=CoCreateInstance(CLSID_DEMDriver,NULL,CLSCTX_ALL,IID_IDEM,(void**)&pRasterDEM);
	if(FAILED(hRes))
	{
		return S_FALSE;
	}
	
	hRes=pRasterDEM->Open(bstrRasterDEMFile,0,modeRead);
	if(hRes==S_FALSE)
	{
		return S_FALSE;
	}
	double lfCellSizeX,lfCellSizeY;
	pRasterDEM->GetCellSize(&lfCellSizeX,&lfCellSizeY);
	lfBufferSize=lfBufferSize*lfCellSizeX;
	//处理特征文件
	CString strVectorFile=CString(bstrFeatureFile);
	if(strVectorFile.IsEmpty())
	{
		CString strMsg;
		strMsg.Format(IDS_FILE_OPEN_FAILED,strVectorFile);
		AfxMessageBox(strMsg);

		return S_FALSE;
	}
	//读取dxf文件
	CDxfDrawing dxffile;
	BOOL bRes=dxffile.Create();
	if(bRes==FALSE)
	{
		return S_FALSE;
	}
	bRes=dxffile.LoadDXFFile(strVectorFile);
	if(bRes==FALSE)
	{
		CString strMsg;
		strMsg.Format(IDS_FILE_OPEN_FAILED,strVectorFile);
		AfxMessageBox(strMsg);

		return S_FALSE;
	}

	//读取dxf文件中实体部分的所有Polyline实体
	int numOfPoints=0;
	int numOfSegments=0;
	CArray<CRealRgn*,CRealRgn*> rgnPolygon;
	CArray<CRealRgn*,CRealRgn*> rgnPolyline;

	ENTITYHEADER	EntityHeader;
	char			EntityData[4096];
	OBJHANDLE hEntity;
	hEntity=dxffile.FindEntity(FIND_FIRST,&EntityHeader,EntityData,NULL);
	while(hEntity)
	{
		switch(EntityHeader.EntityType)
		{
		case ENT_POLYLINE:
		case ENT_LINE3D:
			{
				PENTPOLYLINE pPolyline=(PENTPOLYLINE)EntityData;
				unsigned short flag=pPolyline->Flag;

				numOfPoints+=pPolyline->nVertex;
				if(pPolyline->nVertex>1)
				{
					numOfSegments+=pPolyline->nVertex-1;
				}
				if(pPolyline->nVertex>=3&&
					((fabs(pPolyline->pVertex[0].Point.x-pPolyline->pVertex[pPolyline->nVertex-1].Point.x)<1e-5&&
					fabs(pPolyline->pVertex[0].Point.y-pPolyline->pVertex[pPolyline->nVertex-1].Point.y)<1e-5)|| ((flag&0x0001)==1)))
				{
					int nVertexNum=pPolyline->nVertex;
					if(fabs(pPolyline->pVertex[0].Point.x-pPolyline->pVertex[pPolyline->nVertex-1].Point.x)<1e-5&&fabs(pPolyline->pVertex[0].Point.y-pPolyline->pVertex[pPolyline->nVertex-1].Point.y)<1e-5)
					{
						nVertexNum-=1;
					}

					double* X=new double[nVertexNum];
					double* Y=new double[nVertexNum];
					for(int i=0;i<nVertexNum;i++)
					{
						X[i]=pPolyline->pVertex[i].Point.x;
						Y[i]=pPolyline->pVertex[i].Point.y;
					}

					CRealRgn* pRgn=new CRealRgn;
					pRgn->CreatePolygonRgn(X,Y,nVertexNum);
					
					delete [] X; X=NULL;
					delete [] Y; Y=NULL;

					rgnPolygon.Add(pRgn);
					//增加此特征面在dem表面的投影连接
					numOfSegments+=pPolyline->nVertex-1;
				}
				else if(lfBufferSize>1e-5)
				{
					for(int i=0;i<pPolyline->nVertex-1;i++)
					{
						CRealRgn* pRgn=new CRealRgn;
						if(LineBuffer(pPolyline->pVertex[i].Point.x,pPolyline->pVertex[i].Point.y,
									pPolyline->pVertex[i+1].Point.x,pPolyline->pVertex[i+1].Point.y,
									lfBufferSize,
									pRgn))
						{
							rgnPolyline.Add(pRgn);
						}
						else
						{
							delete pRgn;
							pRgn=NULL;
						}
					}
				}
			}
			break;
		case ENT_LINE:
			{
				PENTLINE pLine=(PENTLINE)EntityData;

				numOfPoints+=2;
				numOfSegments+=1;

				if(lfBufferSize>1e-5)
				{
					CRealRgn* pRgn=new CRealRgn;
					if(LineBuffer(pLine->Point0.x,pLine->Point0.y,
								pLine->Point1.x,pLine->Point1.y,
								lfBufferSize,
								pRgn))
					{
						rgnPolyline.Add(pRgn);
					}
					else
					{
						delete pRgn;
						pRgn=NULL;
					}
				}
			}
			break;
		case ENT_POINT:
			{
				numOfPoints+=1;
			}
			break;
		}

		hEntity=dxffile.FindEntity(FIND_NEXT,&EntityHeader,EntityData,NULL);
	}

	//销毁原有的三角网
	DestoryTIN();
	//统计特征面顶点数和立面边数
	int nFeatureVertex=0;
	int nFeatureSegment=0;
	for(int i=0;i<rgnPolygon.GetSize();i++)
	{
		nFeatureVertex+=rgnPolygon[i]->GetVertexNum();
		nFeatureSegment+=rgnPolygon[i]->GetVertexNum();
	}

	//增加栅格DEM格网点
	int nRows,nCols;
	pRasterDEM->GetRows(&nRows);
	pRasterDEM->GetCols(&nCols);
	numOfPoints=numOfPoints+nRows*nCols+nFeatureVertex;
	//补充四个角点
	numOfPoints+=4;

	in.numOfPoints=numOfPoints;
	in.numOfPointAttrs=1;
	in.numOfTriangles=0;
	in.numOfCorners=0;
	in.numOfHoles=0;
	in.numOfRegions=0;
	in.numOfSegments=numOfSegments+nFeatureSegment;
				
	in.pointList=new REAL[in.numOfPoints*2];
	in.pointAttrList=new REAL[in.numOfPoints];
	in.pointMarkList=new int[in.numOfPoints];
	if(in.numOfSegments>0)
	{
		in.segmentList=new int[in.numOfSegments*2];
		in.segMarkList=new int[in.numOfSegments];
		memset(in.segMarkList,0,sizeof(int)*in.numOfSegments);
	}

	int nPointIndex=0;
	int nSegmentIndex=0;
	hEntity=dxffile.FindEntity(FIND_FIRST,&EntityHeader,EntityData,NULL);
	while(hEntity)
	{
		switch(EntityHeader.EntityType)
		{
		case ENT_POLYLINE:
		case ENT_LINE3D:
			{
				PENTPOLYLINE pPolyline=(PENTPOLYLINE)EntityData;
				unsigned short flag=pPolyline->Flag;
				int nVerticalSegmentVertexIndex=0;

				for(int i=0;i<pPolyline->nVertex;i++)
				{
					in.pointList[nPointIndex*2+0]=pPolyline->pVertex[i].Point.x;
					in.pointList[nPointIndex*2+1]=pPolyline->pVertex[i].Point.y;
					in.pointAttrList[nPointIndex]=pPolyline->pVertex[i].Point.z;
					in.pointMarkList[nPointIndex]=0;

					if(i>0)
					{
						in.segmentList[nSegmentIndex*2+0]=nPointIndex-1;
						in.segmentList[nSegmentIndex*2+1]=nPointIndex;

						nSegmentIndex++;
					}
					if(i==0)
					{
						nVerticalSegmentVertexIndex=nPointIndex;
					}

					nPointIndex++;
				}
				//将特征面投影至dem表面，并且增加立面约束
				/*if(pPolyline->nVertex>=3&&
					((fabs(pPolyline->pVertex[0].Point.x-pPolyline->pVertex[pPolyline->nVertex-1].Point.x)<1e-5&&
					fabs(pPolyline->pVertex[0].Point.y-pPolyline->pVertex[pPolyline->nVertex-1].Point.y)<1e-5)||flag&0x0001==1))
				{
					for(int i=0;i<pPolyline->nVertex;i++)
					{
						double demz=INVALID_ALTITUDE;
						HRESULT hRes=pRasterDEM->GetAltitude(pPolyline->pVertex[i].Point.x,pPolyline->pVertex[i].Point.y,&demz,1);
						if(hRes==S_FALSE)
						{
							pRasterDEM->GetAverageAltitude(&demz);
						}
						in.pointList[nPointIndex*2+0]=pPolyline->pVertex[i].Point.x;
						in.pointList[nPointIndex*2+1]=pPolyline->pVertex[i].Point.y;
						in.pointAttrList[nPointIndex]=demz;
						in.pointMarkList[nPointIndex]=0;
						//增加沿dem表面的连接约束
						//if(i>0)
						//{
						//	in.segmentList[nSegmentIndex*2+0]=nPointIndex-1;
						//	in.segmentList[nSegmentIndex*2+1]=nPointIndex;

						//	nSegmentIndex++;
						//}
						//增加立面约束
						in.segmentList[nSegmentIndex*2+0]=nVerticalSegmentVertexIndex;
						in.segmentList[nSegmentIndex*2+1]=nPointIndex;
						nSegmentIndex++;
						nVerticalSegmentVertexIndex++;

						nPointIndex++;
					}
				}*/
			}
			break;
		case ENT_LINE:
			{
				PENTLINE pLine=(PENTLINE)EntityData;

				in.pointList[nPointIndex*2+0]=pLine->Point0.x;
				in.pointList[nPointIndex*2+1]=pLine->Point0.y;
				in.pointAttrList[nPointIndex]=pLine->Point0.z;
				in.pointMarkList[nPointIndex]=0;

				nPointIndex++;

				in.pointList[nPointIndex*2+0]=pLine->Point1.x;
				in.pointList[nPointIndex*2+1]=pLine->Point1.y;
				in.pointAttrList[nPointIndex]=pLine->Point1.z;
				in.pointMarkList[nPointIndex]=0;

				nPointIndex++;

				in.segmentList[nSegmentIndex*2+0]=nPointIndex-2;
				in.segmentList[nSegmentIndex*2+1]=nPointIndex-1;

				nSegmentIndex++;
			}
			break;
		case ENT_POINT:
			{
				PENTPOINT pPoint=(PENTPOINT)EntityData;

				in.pointList[nPointIndex*2+0]=pPoint->Point0.x;
				in.pointList[nPointIndex*2+1]=pPoint->Point0.y;
				in.pointAttrList[nPointIndex]=pPoint->Point0.z;
				in.pointMarkList[nPointIndex]=0;
			
				nPointIndex++;
			}
			break;
		}

		hEntity=dxffile.FindEntity(FIND_NEXT,&EntityHeader,EntityData,NULL);
	}

	if(dxffile.isOpen())
	{
		dxffile.Destroy();
	}

	//添加DEM格网点
	double* pZ=new double[nRows*nCols];
	pRasterDEM->GetAltitudeValues(pZ);
	double LBX,LBY,RTX,RTY;
	pRasterDEM->GetRange(&LBX,&LBY,&RTX,&RTY);
	double lfXCellSize,lfYCellSize;
	pRasterDEM->GetCellSize(&lfXCellSize,&lfYCellSize);
	lfYCellSize=lfXCellSize;
	for(int i=0;i<nRows;i++)
	{
		double Y=LBY+i*lfYCellSize;
		double* pZIndex=pZ+i*nCols;
		for(int j=0;j<nCols;j++)
		{
			double X=LBX+j*lfXCellSize;
			double Z=pZIndex[j];
			if(fabs(Z-INVALID_ALTITUDE)<1e-5)
			{
				continue;
			}

			BOOL bValid=TRUE;
			for(int k=0;k<rgnPolygon.GetSize();k++)
			{
				if(rgnPolygon[k]->PtInRegion(X,Y,0)!=0||
					rgnPolygon[k]->PtInRegion(X,Y,lfBufferSize)==-1)
				{
					bValid=FALSE;
					break;
				}
			}
			if(bValid&&lfBufferSize>1e-5)
			{
				for(int k=0;k<rgnPolyline.GetSize();k++)
				{
					if(rgnPolyline[k]->PtInRegion(X,Y,0)!=0)
					{
						bValid=FALSE;
						break;
					}
				}
			}
			if(bValid)
			{
				in.pointList[nPointIndex*2+0]=X;
				in.pointList[nPointIndex*2+1]=Y;
				in.pointAttrList[nPointIndex]=Z;
				in.pointMarkList[nPointIndex]=0;
			
				nPointIndex++;
			}
		}
	}

	delete [] pZ; pZ=NULL;

	for(int i=0;i<rgnPolygon.GetSize();i++)
	{
		delete rgnPolygon[i];
		rgnPolygon[i]=NULL;
	}
	rgnPolygon.RemoveAll();

	for(int i=0;i<rgnPolyline.GetSize();i++)
	{
		delete rgnPolyline[i];
		rgnPolyline[i]=NULL;
	}
	rgnPolyline.RemoveAll();

	//////////////////////////////////////
	int nGcpNum=nPointIndex;
	m_X0=0;
	m_Y0=0;
	m_X2=0;
	m_Y2=0;
	//修改DEM范围计算方法
	pRasterDEM->GetRange(&m_X0,&m_Y0,&m_X2,&m_Y2);
	/*if(nGcpNum>0)
	{
		double minX=in.pointList[0],minY=in.pointList[1];
		double maxX=in.pointList[0],maxY=in.pointList[1];
		double minZ=in.pointAttrList[0],maxZ=in.pointAttrList[0];
		double sumZ=in.pointAttrList[0];
		for(int i=1;i<nGcpNum;i++)
		{
			if(in.pointList[i*2+0]<minX)
			{
				minX=in.pointList[i*2+0];
			}
			if(in.pointList[i*2+0]>maxX)
			{
				maxX=in.pointList[i*2+0];
			}
			if(in.pointList[i*2+1]<minY)
			{
				minY=in.pointList[i*2+1];
			}
			if(in.pointList[i*2+1]>maxY)
			{
				maxY=in.pointList[i*2+1];
			}
			if(in.pointAttrList[i]<minZ)
			{
				minZ=in.pointAttrList[i];
			}
			if(in.pointAttrList[i]>maxZ)
			{
				maxZ=in.pointAttrList[i];
			}
			sumZ+=in.pointAttrList[i];
		}

		m_AveAltitude=sumZ/nGcpNum;
		m_MaxAltitude=maxZ;
		m_MinAltitude=minZ;

		m_X0=minX;
		m_Y0=minY;
		m_X2=maxX;
		m_Y2=maxY;
	}*/
	//补充四个角点
/*	in.pointList[nPointIndex*2+0]=m_X0;
	in.pointList[nPointIndex*2+1]=m_Y0;
	in.pointAttrList[nPointIndex]=m_AveAltitude;
	in.pointMarkList[nPointIndex]=0;
	nPointIndex++;

	in.pointList[nPointIndex*2+0]=m_X2;
	in.pointList[nPointIndex*2+1]=m_Y0;
	in.pointAttrList[nPointIndex]=m_AveAltitude;
	in.pointMarkList[nPointIndex]=0;
	nPointIndex++;

	in.pointList[nPointIndex*2+0]=m_X2;
	in.pointList[nPointIndex*2+1]=m_Y2;
	in.pointAttrList[nPointIndex]=m_AveAltitude;
	in.pointMarkList[nPointIndex]=0;
	nPointIndex++;

	in.pointList[nPointIndex*2+0]=m_X0;
	in.pointList[nPointIndex*2+1]=m_Y2;
	in.pointAttrList[nPointIndex]=m_AveAltitude;
	in.pointMarkList[nPointIndex]=0;
	nPointIndex++;
*/
	in.numOfPoints=nPointIndex;
	in.numOfSegments=nSegmentIndex;
	CBaseDEM::ContrustTIN3();

	//关闭并清理数据

	pRasterDEM->Close();

	if(pRasterDEM!=NULL)
	{
		pRasterDEM->Release();
		pRasterDEM=NULL;
	}

	CString strTinFile=(CString)bstrFeatureFile;
	strTinFile=strTinFile.Left(strTinFile.ReverseFind('.'))+"_tin.dxf";
	ExportTin(_bstr_t(strTinFile));

	return S_OK;
}

HRESULT CFeatureDEM::TIN2DEM(BSTR bstrDEMFile, double LBX, double LBY, double RTX, double RTY, double lfCellSize)
{
	BOOL bRet=CBaseDEM::TIN2DEM(CString(bstrDEMFile),LBX,LBY,RTX,RTY,lfCellSize);

	return bRet?S_OK:S_FALSE;
}

HRESULT CFeatureDEM::ExportTin(BSTR bstrTinFile)
{
	//保存三角网到dxf文件中
	BOOL result=TRUE;
	CDxfDrawing tinfile;
	result &= tinfile.Create();
	LTYPE ltype;
	ZeroMemory(&ltype,sizeof(ltype));
	strcpy(ltype.Name,"Continuous");
	strcpy(ltype.DescriptiveText,"Solid line");
	OBJHANDLE LineHandle=tinfile.AddLinetype(&ltype);
	LAYER layer;
	CString strLayerName="TIN";
	ZeroMemory(&layer,sizeof(layer));
	strcpy(layer.Name,strLayerName.GetBuffer(0));
	layer.Color = 3;
	layer.LineTypeObjhandle=LineHandle;
	tinfile.AddLayer(&layer);
	result &= tinfile.SetLayer(strLayerName.GetBuffer(0));
	result &= tinfile.SetLineType("Continuous");
	ENTVERTEX* vertex=new ENTVERTEX[4];
	ZeroMemory(vertex,sizeof(ENTVERTEX)*4);
	for(int nTriIndex=0;nTriIndex<mid.numOfTriangles;nTriIndex++)
	{
		for(int nTinPtIndex=0;nTinPtIndex<3;nTinPtIndex++)
		{
			vertex[nTinPtIndex].Point.x=mid.pointList[mid.triList[nTriIndex*3+nTinPtIndex]*2+0];
			vertex[nTinPtIndex].Point.y=mid.pointList[mid.triList[nTriIndex*3+nTinPtIndex]*2+1];
			vertex[nTinPtIndex].Point.z=mid.pointAttrList[mid.triList[nTriIndex*3+nTinPtIndex]];
			if(mid.triList[nTriIndex*3+nTinPtIndex]>in.numOfPoints)
			{
				int hhh=0;
			}
		}
		vertex[3].Point.x=vertex[0].Point.x;
		vertex[3].Point.y=vertex[0].Point.y;
		vertex[3].Point.z=vertex[0].Point.z;
		result &= tinfile.PolyLine(vertex,4);
	}
	delete [] vertex; vertex=NULL;
	//画强制连接线
	LAYER layerSeg;
	strLayerName="TIN_SEGMENT";
	ZeroMemory(&layerSeg,sizeof(layerSeg));
	strcpy(layerSeg.Name,strLayerName.GetBuffer(0));
	layerSeg.Color = 1;
	layerSeg.LineTypeObjhandle=LineHandle;
	tinfile.AddLayer(&layerSeg);
	result &= tinfile.SetLayer(strLayerName.GetBuffer(0));
	result &= tinfile.SetLineType("Continuous");
	vertex=new ENTVERTEX[2];
	ZeroMemory(vertex,sizeof(ENTVERTEX)*2);
	for(int nSegIndex=0;nSegIndex<mid.numOfSegments;nSegIndex++)
	{
		for(int nSegPtIndex=0;nSegPtIndex<2;nSegPtIndex++)
		{
			vertex[nSegPtIndex].Point.x=mid.pointList[mid.segmentList[nSegIndex*2+nSegPtIndex]*2+0];
			vertex[nSegPtIndex].Point.y=mid.pointList[mid.segmentList[nSegIndex*2+nSegPtIndex]*2+1];
			vertex[nSegPtIndex].Point.z=mid.pointAttrList[mid.segmentList[nSegIndex*2+nSegPtIndex]];
			if(mid.segmentList[nSegIndex*2+nSegPtIndex]>in.numOfPoints)
			{
				int hh=0;
			}
		}
		result &= tinfile.PolyLine(vertex,2);
	}
	delete [] vertex; vertex=NULL;

	result &= tinfile.SaveDXFFile(CString(bstrTinFile));
	if(tinfile.isOpen())
	{
		tinfile.Destroy();
	}

	return result==TRUE?S_OK:S_FALSE;
}


HRESULT CFeatureDEM::Open(BSTR bstrPathName, double lfAltitudeOffset, UINT accMode)
{
	return S_FALSE;
}

HRESULT CFeatureDEM::Create(BSTR bstrPathName, BSTR bstrFormat, UINT accMode, int nRows, int nCols, double LBX, double LBY, double XCellSize, double YCellSize)
{
	return S_FALSE;
}

HRESULT CFeatureDEM::Close()
{

	m_strFeatureFile="";
	m_strRasterFile="";
	CBaseDEM::DestoryTIN();

	return S_OK;
}

HRESULT CFeatureDEM::GetSupExts(BYTE* lpszExts, UINT accMode)
{
	strcpy((char*)lpszExts,"");

	return S_FALSE;
}

HRESULT CFeatureDEM::GetSupFormats(BYTE* lpszFormats, UINT accMode)
{
	strcpy((char*)lpszFormats,"");

	return S_FALSE;
}

HRESULT CFeatureDEM::GetIImage(IImage** ppIImage)
{
	return S_FALSE;
}

HRESULT CFeatureDEM::GetVertex(double* pX, double* pY, double* pZ, int* pVertexNum)
{
	return S_FALSE;
}

HRESULT CFeatureDEM::GetTriangle(int nTriIndex, double* pX, double* pY, double* pZ)
{
	return CBaseDEM::GetTriangleB(nTriIndex,pX,pY,pZ)==TRUE?S_OK:S_FALSE;
}

HRESULT CFeatureDEM::GetTriangleNum(int* pTriangleNum)
{
	*pTriangleNum=CBaseDEM::GetTriangleNum();

	return S_OK;
}

HRESULT CFeatureDEM::ConstrustTIN()
{
	//在创建时已经构造三角网，此处直接返回

	return S_OK;
}

HRESULT CFeatureDEM::GetAverageAltitude(double* pZ)
{
	*pZ=m_AveAltitude;

	return S_OK;
}

HRESULT CFeatureDEM::GetAltitude(double X, double Y, double* pZ, UINT uResampleMethod)
{
	if(X<m_X0||X>m_X2||Y<m_Y0||Y>m_Y2)
	{
		*pZ=INVALID_ALTITUDE;//m_AveAltitude

		return S_FALSE;
	}

	for(int i=0;i<mid.numOfTriangles;i++)
	{
		double triX[3],triY[3],triZ[3];
		for(int j=0;j<3;j++)
		{
			triX[j]=mid.pointList[mid.triList[i*3+j]*2+0];
			triY[j]=mid.pointList[mid.triList[i*3+j]*2+1];
			triZ[j]=mid.pointAttrList[mid.triList[i*3+j]];
		}

		double dx01=triX[1]-triX[0];
		double dy01=triY[1]-triY[0];
		double dx12=triX[2]-triX[1];
		double dy12=triY[2]-triY[1];
		double dx20=triX[0]-triX[2];
		double dy20=triY[0]-triY[2];
		double dx1=X-triX[1];
		double dy1=Y-triY[1];
		double dx2=X-triX[2];
		double dy2=Y-triY[2];
		double dx0=X-triX[0];
		double dy0=Y-triY[0];

		if(((dx01*dy1-dx1*dy01)>=0&&(dx12*dy2-dx2*dy12)>=0&&(dx20*dy0-dx0*dy20)>=0)||
			((dx01*dy1-dx1*dy01)<=0&&(dx12*dy2-dx2*dy12)<=0&&(dx20*dy0-dx0*dy20)<=0))
		{
			double vx01=triX[1]-triX[0];
			double vy01=triY[1]-triY[0];
			double vz01=triZ[1]-triZ[0];

			double vx02=triX[2]-triX[0];
			double vy02=triY[2]-triY[0];
			double vz02=triZ[2]-triZ[0];

			double vx=vy01*vz02-vz01*vy02;
			double vy=vz01*vx02-vx01*vz02;
			double vz=vx01*vy02-vy01*vx02;
			double mod=sqrt(vx*vx+vy*vy+vz*vz);
			double a=vx/mod;
			double b=vy/mod;
			double c=vz/mod;
			double d=-(a*triX[0]+b*triY[0]+c*triZ[0]);
			*pZ=-(a*X+b*Y+d)/c;


			return S_OK;
		}
	}

	return S_FALSE;
}

HRESULT CFeatureDEM::GetTIN(DWORD ppTriangulateio)
{
	return CBaseDEM::GetTINB(ppTriangulateio)==TRUE?S_OK:S_FALSE;
}

HRESULT CFeatureDEM::GetRange(double* pLBX, double* pLBY, double* pRTX, double* pRTY)
{
	*pLBX=m_X0;
	*pLBY=m_Y0;
	*pRTX=m_X2;
	*pRTY=m_Y2;

	return S_OK;
}

HRESULT CFeatureDEM::GetCellSize(double* pXCellSize, double* pYCellSize)
{
	return S_FALSE;
}

HRESULT CFeatureDEM::GetMaxAltitude(double* pZ)
{
	*pZ=m_MaxAltitude;

	return S_OK;
}

HRESULT CFeatureDEM::GetMinAltitude(double* pZ)
{
	*pZ=m_MinAltitude;

	return S_OK;
}

HRESULT CFeatureDEM::GetType(UINT* pType)
{
	*pType=DT_TIN;

	return S_OK;
}

HRESULT CFeatureDEM::GetRows(int* pRows)
{
	return S_FALSE;
}

HRESULT CFeatureDEM::GetCols(int* pCols)
{
	return S_FALSE;
}

HRESULT CFeatureDEM::GetStartPos(double* pX0, double* pY0)
{
	return S_FALSE;
}

HRESULT CFeatureDEM::GetAltitudeValues(double* pZ)
{
	return S_FALSE;
}

HRESULT CFeatureDEM::IsSupported(BSTR bstrPathName, UINT accMode)
{
	return S_FALSE;
}





