// BaseDEM.cpp: implementation of the CBaseDEM class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "resource.h"
#include "BaseDEM.h"
#include "IO.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

#import "ImageX.tlb" no_namespace named_guids

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

#define BiLinear(Type) void Type##_BiLinear(BYTE *buf11,BYTE *buf21, \
									   BYTE *buf22,BYTE *buf12, \
									   double Dx,double Dy,     \
									   BYTE *pOut)				\
{																\
	*((Type *)pOut) = (Type)((1-Dx) * (1-Dy) * (*((Type*)buf11))			\
			 + Dx     * (1-Dy) * (*((Type*)buf21))				\
			 + Dx     * Dy     * (*((Type*)buf22))				\
			 + (1-Dx) * Dy     * (*((Type*)buf12)));			\
}

BiLinear(BYTE)
BiLinear(USHORT)
BiLinear(short)
BiLinear(UINT)
BiLinear(int)
BiLinear(float)
BiLinear(double)
BiLinear(__int64)

#define FuncName(Type) Type##_BiLinear

typedef void (* BiLinearFunc)(BYTE *buf11,BYTE *buf21, BYTE *buf22,BYTE *buf12,double Dx,double Dy, BYTE *pOut);

static BiLinearFunc FuncTable[9] = {FuncName(BYTE),
									FuncName(USHORT),
									FuncName(short),
									FuncName(UINT),
									FuncName(int),
									FuncName(float),
									FuncName(double),
									FuncName(__int64),
									FuncName(__int64)//the singed int64 is same as int64
									};

CBaseDEM::CBaseDEM()
{
	m_X0=m_Y0=m_XCellSize=m_YCellSize=m_Kappa=0;
	m_nRows=m_nCols=0;
	m_AveAltitude=0;
	m_MaxAltitude=0;
	m_MinAltitude=0;
	m_pImage=NULL;
	m_strDemImage="";
	m_lfAltitudeOffset=0;
	m_strDEMPathName="";

	memset(&in,0,sizeof(triangulateio));
	memset(&mid,0,sizeof(triangulateio));
	memset(&vorout,0,sizeof(triangulateio));

	m_nCacheRow0=-1;
	m_nCacheCol0=-1;
	m_nCacheRow1=-1;
	m_nCacheCol1=-1;
	m_pCacheBuffer=NULL;
}

CBaseDEM::~CBaseDEM()
{
	DestoryTIN();

	if(m_pCacheBuffer!=NULL)
	{
		delete m_pCacheBuffer;
		m_pCacheBuffer=NULL;
	}
}

void CBaseDEM::ContrustTIN(double *pX, double *pY, double *pZ, int nVertexNum)
{
	DestoryTIN();

	in.numOfPoints=nVertexNum;
	in.numOfPointAttrs=1;
	in.numOfTriangles=0;
	in.numOfCorners=0;
	in.numOfHoles=0;
	in.numOfRegions=0;
	in.numOfSegments=0;
				
	in.pointList=new REAL[in.numOfPoints*2];
	in.pointAttrList=new REAL[in.numOfPoints];
	in.pointMarkList=new int[in.numOfPoints];

	for(int i=0;i<nVertexNum;i++)
	{
		in.pointList[i*2+0]=pX[i];
		in.pointList[i*2+1]=pY[i];
		in.pointAttrList[i]=pZ[i];
		in.pointMarkList[i]=0;
	}

	ContrustTIN3();
}

void CBaseDEM::ContrustTIN2(CArray<double,double>& X,CArray<double,double>& Y,CArray<double,double>& Z)
{
	DestoryTIN();

	int nVertexNum=X.GetSize();

	in.numOfPoints=nVertexNum;
	in.numOfPointAttrs=1;
	in.numOfTriangles=0;
	in.numOfCorners=0;
	in.numOfHoles=0;
	in.numOfRegions=0;
	in.numOfSegments=0;
				
	in.pointList=new REAL[in.numOfPoints*2];
	in.pointAttrList=new REAL[in.numOfPoints];
	in.pointMarkList=new int[in.numOfPoints];

	for(int i=0;i<nVertexNum;i++)
	{
		in.pointList[i*2+0]=X[i];
		in.pointList[i*2+1]=Y[i];
		in.pointAttrList[i]=Z[i];
		in.pointMarkList[i]=0;
	}

	ContrustTIN3();
}

void CBaseDEM::ContrustTIN3()
{
	triangulate("pczAevnQ",&in,&mid,&vorout);//pcnz

	//在强制连接条件下，可能会产生增加点，因此需要为新引入的点内差高程
	for(int i=0;i<mid.numOfPoints;i++)
	{
		if((mid.pointMarkList[i]-in.numOfPoints)>=0)
		{
			int nSeg=mid.pointMarkList[i]-in.numOfPoints;
			mid.pointAttrList[i]=(mid.pointAttrList[in.segmentList[nSeg*2]]+mid.pointAttrList[in.segmentList[nSeg*2+1]])/2;
		}
	}
}

void CBaseDEM::DestoryTIN()
{
	//in
	if(in.pointList)
	{
		delete [] in.pointList;
		in.pointList=NULL;
	}
	if(in.pointAttrList)
	{
		delete [] in.pointAttrList;
		in.pointAttrList=NULL;
	}
	if(in.pointMarkList)
	{
		delete [] in.pointMarkList;
		in.pointMarkList=NULL;
	}
	if(in.triList)
	{
		delete [] in.triList;
		in.triList=NULL;
	}
	if(in.triAreaList)
	{
		delete [] in.triAreaList;
		in.triAreaList=NULL;
	}
	if(in.triAttrList)
	{
		delete [] in.triAttrList;
		in.triAttrList=NULL;
	}
	if(in.segmentList)
	{
		delete [] in.segmentList; 
		in.segmentList=NULL;
	}
	if(in.holeList)
	{
		delete [] in.holeList;
		in.holeList=NULL;
	}
	if(in.regionList)
	{
		delete [] in.regionList;
		in.regionList=NULL;
	}
	if(in.segMarkList)
	{
		delete [] in.segMarkList;
		in.segMarkList=NULL;
	}

	//mid
	if(mid.pointAttrList)
	{
		free(mid.pointAttrList);
		mid.pointAttrList=NULL;
	}
	if(mid.pointMarkList)
	{
		free(mid.pointMarkList);
		mid.pointMarkList=NULL;
	}
	if(mid.triList)
	{
		free(mid.triList);		
		mid.triList=NULL;
	}
	if(mid.neighborList)
	{
 		free(mid.neighborList);	
		mid.neighborList=NULL;
	}
	if(mid.segmentList)
	{
		free(mid.segmentList);	
		mid.segmentList=NULL;
	}
	if(mid.segMarkList)
	{
		free(mid.segMarkList);	
		mid.segMarkList=NULL;
	}
	if(mid.edgeList)
	{
		free(mid.edgeList);		
		mid.edgeList=NULL;
	}
	if(mid.edgeMarkList)
	{
		free(mid.edgeMarkList);	
		mid.edgeMarkList=NULL;
	}

	//out
	if(vorout.pointList)
	{
		free(vorout.pointList);
		vorout.pointList=NULL;
	}
	if(vorout.pointAttrList)
	{
		free(vorout.pointAttrList);
		vorout.pointAttrList=NULL;
	}
	if(vorout.pointMarkList)
	{
		free(vorout.pointMarkList);
		vorout.pointMarkList=NULL;
	}
	if(vorout.edgeList)
	{
		free(vorout.edgeList);
		vorout.edgeList=NULL;
	}
	if(vorout.normList)
	{
		free(vorout.normList);
		vorout.normList=NULL;
	}

	memset(&in,0,sizeof(triangulateio));
	memset(&mid,0,sizeof(triangulateio));
	memset(&vorout,0,sizeof(triangulateio));
}

int CBaseDEM::GetTriangleNum()
{
	return mid.numOfTriangles;
}

BOOL CBaseDEM::GetTriangleB(int nTriIndex, double *pX, double *pY, double *pZ)
{
	for(int i=0;i<3;i++)
	{
		pX[i]=mid.pointList[mid.triList[nTriIndex*3+i]*2+0];
		pY[i]=mid.pointList[mid.triList[nTriIndex*3+i]*2+1];
		pZ[i]=mid.pointAttrList[mid.triList[nTriIndex*3+i]];
		
		if(pZ[i]==DBL_MAX)
		{
			return FALSE;
		}
	}

	return TRUE;
}

BOOL CBaseDEM::GetTINB(DWORD ppTriangulateio)
{
	*((triangulateio**)ppTriangulateio)=&mid;

	return TRUE;
}

BOOL CBaseDEM::TIN2DEM(CString strDEMFile, 
					   double LBX, double LBY, 
					   double RTX, double RTY, 
					   double lfCellSize)
{
	if(mid.numOfTriangles==0)
	{
		ContrustTIN3();
	}

	if(mid.numOfTriangles==0||mid.numOfPoints==0)
	{
		return FALSE;
	}
	
	if(fabs(RTX-LBX)<1e-5||fabs(RTY-LBY)<1e-5)
	{
		LBX=mid.pointList[0];
		LBY=mid.pointList[1];
		RTX=LBX;
		RTY=LBY;

		for(int i=1;i<mid.numOfPoints;i++)
		{
			int xIndex=i*2;
			int yIndex=xIndex+1;
			
			if(LBX>mid.pointList[xIndex])
			{
				LBX=mid.pointList[xIndex];
			}
			if(RTX<mid.pointList[xIndex])
			{
				RTX=mid.pointList[xIndex];
			}
			
			if(LBY>mid.pointList[yIndex])
			{
				LBY=mid.pointList[yIndex];
			}
			if(RTY<mid.pointList[yIndex])
			{
				RTY=mid.pointList[yIndex];
			}
		}

		LBX=floor(LBX/lfCellSize)*lfCellSize;
		LBY=floor(LBY/lfCellSize)*lfCellSize;
		RTX=ceil(RTX/lfCellSize)*lfCellSize;
		RTY=ceil(RTY/lfCellSize)*lfCellSize;
	}

	int nRows=(int)((RTY-LBY)/lfCellSize+0.5);
	int nCols=(int)((RTX-LBX)/lfCellSize+0.5);
	float* pAltitude=new float[nRows*nCols];
	for(int i=0;i<nRows*nCols;i++)
	{
		pAltitude[i]=-9999.9f;
	}

	double X[3],Y[3],Z[3];
	for(int i=0;i<mid.numOfTriangles;i++)
	{
		double minx=mid.pointList[mid.triList[i*3+0]*2+0];
		double miny=mid.pointList[mid.triList[i*3+0]*2+1];
		double maxx=minx;
		double maxy=miny;

		BOOL bValidTriangle=TRUE;
		for(int j=0;j<3;j++)
		{
			X[j]=mid.pointList[mid.triList[i*3+j]*2+0];
			Y[j]=mid.pointList[mid.triList[i*3+j]*2+1];
			Z[j]=mid.pointAttrList[mid.triList[i*3+j]];

			if(fabs(Z[j]-INVALID_ALTITUDE)<1e-5)
			{
				bValidTriangle=FALSE;
				break;
			}
			
			if(minx>X[j])
			{
				minx=X[j];
			}
			if(maxx<X[j])
			{
				maxx=X[j];
			}
			if(miny>Y[j])
			{
				miny=Y[j];
			}
			if(maxy<Y[j])
			{
				maxy=Y[j];
			}
		}

		if(bValidTriangle==FALSE)
		{
			continue;
		}

		//判断此三角形范围内是否存在DEM格网点
		int nLBX=(int)((minx-LBX)/lfCellSize);
		int nLBY=(int)((miny-LBY)/lfCellSize);
		int nRTX=(int)((maxx-LBX)/lfCellSize+0.5);
		int nRTY=(int)((maxy-LBY)/lfCellSize+0.5);
		//为落在此三角形内的格网点内差高程
		for(int rowIndex=nLBY;rowIndex<=nRTY;rowIndex++)
		{
			if(rowIndex<0||rowIndex>=nRows)
			{
				continue;
			}
			double demY=LBY+rowIndex*lfCellSize;
			for(int colIndex=nLBX;colIndex<=nRTX;colIndex++)
			{
				if(colIndex<0||colIndex>=nCols)
				{
					continue;
				}
				double demX=LBX+colIndex*lfCellSize;

				double dx01=X[1]-X[0];
				double dy01=Y[1]-Y[0];
				double dx12=X[2]-X[1];
				double dy12=Y[2]-Y[1];
				double dx20=X[0]-X[2];
				double dy20=Y[0]-Y[2];
				double dx1=demX-X[1];
				double dy1=demY-Y[1];
				double dx2=demX-X[2];
				double dy2=demY-Y[2];
				double dx0=demX-X[0];
				double dy0=demY-Y[0];

				double v01=dx01*dy1-dx1*dy01;
				double v12=dx12*dy2-dx2*dy12;
				double v20=dx20*dy0-dx0*dy20;
				if((v01>1e-5&&v12>1e-5&&v20>1e-5)||(v01<1e-5&&v12<1e-5&&v20<1e-5))
				{
					double tempX,tempY;
					Intersect1(X[0],Y[0],demX,demY,X[1],Y[1],X[2],Y[2],tempX,tempY);

					double L12=sqrt((X[2]-X[1])*(X[2]-X[1])+(Y[2]-Y[1])*(Y[2]-Y[1]));
					double L1T=sqrt((tempX-X[1])*(tempX-X[1])+(tempY-Y[1])*(tempY-Y[1]));
					double L2T=sqrt((tempX-X[2])*(tempX-X[2])+(tempY-Y[2])*(tempY-Y[2]));
					double tempZ=Z[1]*L2T/L12+Z[2]*L1T/L12;

					double L0T=sqrt((tempX-X[0])*(tempX-X[0])+(tempY-Y[0])*(tempY-Y[0]));
					double L0D=sqrt((demX-X[0])*(demX-X[0])+(demY-Y[0])*(demY-Y[0]));
					double LTD=sqrt((demX-tempX)*(demX-tempX)+(demY-tempY)*(demY-tempY));
					pAltitude[rowIndex*nCols+colIndex]=(float)(Z[0]*LTD/L0T+tempZ*L0D/L0T);
				}
				else if(fabs(v01)<1e-5&&
						(demX-X[0])*(demX-X[1])<=1e-5&&
						(demY-Y[0])*(demY-Y[1])<=1e-5)
				{
					double L01=sqrt((X[0]-X[1])*(X[0]-X[1])+(Y[0]-Y[1])*(Y[0]-Y[1]));
					double L0D=sqrt((demX-X[0])*(demX-X[0])+(demY-Y[0])*(demY-Y[0]));
					double L1D=sqrt((demX-X[1])*(demX-X[1])+(demY-Y[1])*(demY-Y[1]));
					pAltitude[rowIndex*nCols+colIndex]=(float)(Z[0]*L1D/L01+Z[1]*L0D/L01);
				}
				else if(fabs(v12)<1e-5&&
						(demX-X[1])*(demX-X[2])<=1e-5&&
						(demY-Y[1])*(demY-Y[2])<=1e-5)
				{
					double L12=sqrt((X[2]-X[1])*(X[2]-X[1])+(Y[2]-Y[1])*(Y[2]-Y[1]));
					double L2D=sqrt((demX-X[2])*(demX-X[2])+(demY-Y[2])*(demY-Y[2]));
					double L1D=sqrt((demX-X[1])*(demX-X[1])+(demY-Y[1])*(demY-Y[1]));
					pAltitude[rowIndex*nCols+colIndex]=(float)(Z[1]*L2D/L12+Z[2]*L1D/L12);
				}
				else if(fabs(v20)<1e-5&&
						(demX-X[2])*(demX-X[0])<=1e-5&&
						(demY-Y[2])*(demY-Y[0])<=1e-5)
				{
					double L20=sqrt((X[2]-X[0])*(X[2]-X[0])+(Y[2]-Y[0])*(Y[2]-Y[0]));
					double L2D=sqrt((demX-X[2])*(demX-X[2])+(demY-Y[2])*(demY-Y[2]));
					double L0D=sqrt((demX-X[0])*(demX-X[0])+(demY-Y[0])*(demY-Y[0]));
					pAltitude[rowIndex*nCols+colIndex]=(float)(Z[0]*L2D/L20+Z[2]*L0D/L20);
				}
			}
		}
	}

	//保存至VirtuozoNT格式DEM
	FILE* fp=fopen(strDEMFile,"wt");

	fprintf(fp,"%lf %lf %lf %lf %lf %d %d\n",
			LBX,
			LBY,
			0.0,
			lfCellSize,
			lfCellSize,
			nCols,
			nRows);
	for(int i=0;i<nRows*nCols;i++)
	{
		fprintf(fp,"%10d",(int)(pAltitude[i]*10.0f));
		if((i+1)%10==0)
		{
			fprintf(fp,"\n");
		}
	}
	fclose(fp);

	delete [] pAltitude; pAltitude=NULL;

	return TRUE;
}

BOOL CBaseDEM::Intersect1(double X1,double Y1,double X2,double Y2,double X3,double Y3,double X4,double Y4,double& X,double& Y)
{
	double a1=Y2-Y1;
	double b1=X1-X2;
	double c1=Y1*(X2-X1)+X1*(Y1-Y2);

	double a2=Y4-Y3;
	double b2=X3-X4;
	double c2=Y3*(X4-X3)+X3*(Y3-Y4);

	//如果两条直线平行
	if(fabs(a1*b2-a2*b1)<1e-6)
	{
		return FALSE;
	}

	X=(b1*c2-b2*c1)/(a1*b2-a2*b1);
	Y=(a2*c1-a1*c2)/(a1*b2-a2*b1);
	
	if((X-X1)*(X-X2)<=1e-6&&(Y-Y1)*(Y-Y2)<=1e-6&&(X-X3)*(X-X4)<=1e-6&&(Y-Y3)*(Y-Y4)<=1e-6)
	{
		return TRUE;
	}

	return FALSE;
}

BOOL CBaseDEM::LineBuffer(double X0, double Y0, double X1, double Y1, double lfBufferSize, CRealRgn *pRgn)
{
	double a = (double)atan2(Y1-Y0,X1-X0);
	double cosa = (double)cos(a), sina = (double)sin(a);

	X0=X0-lfBufferSize*cosa;
	Y0=Y0-lfBufferSize*sina;

	X1=X1+lfBufferSize*cosa;
	Y1=Y1+lfBufferSize*sina;

	double X[4],Y[4];
	
	X[0]=X0-lfBufferSize*sina;
	Y[0]=Y0+lfBufferSize*cosa;

	X[1]=X0+lfBufferSize*sina;
	Y[1]=Y0-lfBufferSize*cosa;

	X[2]=X1+lfBufferSize*sina;
	Y[2]=Y1-lfBufferSize*cosa;

	X[3]=X1-lfBufferSize*sina;
	Y[3]=Y1+lfBufferSize*cosa;

	pRgn->CreatePolygonRgn(X,Y,4);

	return TRUE;
}

BOOL CBaseDEM::ResetCache(float x,float y)
{
	if(m_pImage==NULL)
	{
		return FALSE;
	}

	if(m_pCacheBuffer==NULL)
	{
		m_pImage->GetRows(&m_nRows);
		m_pImage->GetCols(&m_nCols);
		m_pImage->GetBandNum(&m_nBandNum);
		m_pImage->GetBPB(&m_nBPB);
		m_nBPP=m_nBPB*m_nBandNum;
		m_pImage->GetDataType(&m_nDataType);

		CACHE_SIZE_ROW=32;//m_nRows
		CACHE_SIZE_COL=32;//m_nCols
		while(m_pCacheBuffer==NULL&&CACHE_SIZE_ROW>0&&CACHE_SIZE_COL>0)
		{
			m_pCacheBuffer=new BYTE[CACHE_SIZE_ROW*CACHE_SIZE_COL*m_nBPP];
			if(m_pCacheBuffer==NULL)
			{
				CACHE_SIZE_ROW/=2;
				CACHE_SIZE_COL/=2;
			}
		};
	}

	m_nCacheCol0=(int)x-CACHE_SIZE_COL/2;
	m_nCacheRow0=(int)y-CACHE_SIZE_ROW/2;
	if(m_nCacheCol0<0)
	{
		m_nCacheCol0=0;
	}
	if(m_nCacheRow0<0)
	{
		m_nCacheRow0=0;
	}
	m_nCacheCol1=m_nCacheCol0+CACHE_SIZE_COL;
	m_nCacheRow1=m_nCacheRow0+CACHE_SIZE_ROW;
	if(m_nCacheCol1>m_nCols)
	{
		m_nCacheCol1=m_nCols;
	}
	if(m_nCacheRow1>m_nRows)
	{
		m_nCacheRow1=m_nRows;
	}
	m_nCacheCols=m_nCacheCol1-m_nCacheCol0;
	m_nCacheRows=m_nCacheRow1-m_nCacheRow0;
	//此处不能调用
	m_pImage->ReadImg(m_nCacheCol0,m_nCacheRow0,m_nCacheCol1,m_nCacheRow1,
			m_pCacheBuffer,m_nCacheCols,m_nCacheRows,m_nBandNum,
			0,0,m_nCacheCols,m_nCacheRows,
			-1,0);

	return TRUE;
}

HRESULT CBaseDEM::GetAltitudeRaster(double X,double Y,double* pZ, UINT uResampleMethod)
{
	*pZ=INVALID_ALTITUDE;
	if(m_pImage==NULL)
	{
		return S_FALSE;
	}

	float x,y;
	m_pImage->World2Image(X,Y,&x,&y);

	if((int)x<0||(int)x>=m_nCols||(int)y<0||(int)y>=m_nRows)
	{
		*pZ=INVALID_ALTITUDE;//m_AveAltitude
		
		return S_FALSE;
	}

	if(!(y>=m_nCacheRow0&&y<m_nCacheRow1-1&&
		x>=m_nCacheCol0&&x<m_nCacheCol1-1))
	{
		if(ResetCache(x,y)==FALSE)
		{
			return S_FALSE;
		}
	}
	
	switch(uResampleMethod)
	{
	case 1:
		{
			int x1=(int)x;
			int y1=(int)y;
			int x2=x1+1;
			int y2=y1+1;
			double dx=x-x1;
			double dy=y-y1;

			BYTE* pBuf11=m_pCacheBuffer+(y1-m_nCacheRow0)*m_nCacheCols*m_nBPP+(x1-m_nCacheCol0)*m_nBPP;
			BYTE* pBuf21=pBuf11+(x2-x1)*m_nBPP;
			BYTE* pBuf12=pBuf11+(y2-y1)*m_nCacheCols*m_nBPP;
			BYTE* pBuf22=pBuf12+(x2-x1)*m_nBPP;

			if(*((double*)pBuf11)!=DBL_MAX&&*((double*)pBuf21)!=DBL_MAX&&
				*((double*)pBuf12)!=DBL_MAX&&*((double*)pBuf22)!=DBL_MAX)
			{
				(* FuncTable[m_nDataType])(pBuf11,pBuf21,pBuf22,pBuf12,
								 dx,dy,
								 (BYTE*)pZ);

				return S_OK;
			}
			else
			{
				*pZ=INVALID_ALTITUDE;
				return S_FALSE;
			}
		}
		break;
	case 0:
		{
			int nx=(int)(x+0.5);
			int ny=(int)(y+0.5);
			if(nx<0||nx>=m_nCols||ny<0||ny>=m_nRows)
			{
				*pZ=INVALID_ALTITUDE;
				
				return S_FALSE;
			}
			memcpy((BYTE*)pZ,m_pCacheBuffer+(ny-m_nCacheRow0)*m_nCacheCols*m_nBPP+(nx-m_nCacheCol0)*m_nBPP,m_nBPB);
			if(*pZ!=DBL_MAX)
			{
				return S_OK;
			}
			else
			{
				*pZ=INVALID_ALTITUDE;
				return S_FALSE;
			}
		}
		break;
	}

	return S_FALSE;
}

HRESULT CBaseDEM::SetRange(double LBX,double LBY,double RTX,double RTY)
{
	return S_FALSE;
}

HRESULT CBaseDEM::CreateGCPDEM(BSTR bstrGcpFile)
{
	return S_FALSE;
}

HRESULT CBaseDEM::ExportTin(BSTR bstrTinFile)
{
	return S_FALSE;
}

HRESULT CBaseDEM::SetBufferSize(double lfBufferSize)
{
	return S_FALSE;
}

HRESULT CBaseDEM::GetBufferSize(double* pBufferSize)
{
	return S_FALSE;
}

HRESULT CBaseDEM::TIN2DEM(BSTR bstrDEMFile,double LBX,double LBY,double RTX,double RTY,double lfCellSize)
{
	return S_FALSE;
}

HRESULT CBaseDEM::CreateVectorDEM(BSTR bstrVectorFile)
{
	return S_FALSE;
}

HRESULT CBaseDEM::CreateFeatureDEM(BSTR bstrRasterDEMFile,BSTR bstrFeatureFile,double lfBufferSize)
{
	return S_FALSE;
}

HRESULT CBaseDEM::SetCellSize(double CellSize)
{
	return S_FALSE;
}

HRESULT CBaseDEM::SetFlatAltitude(double Z)
{
	return S_FALSE;
}

HRESULT CBaseDEM::CreateFlatDEM(int nRows, int nCols, double LBX, double LBY, double Altitude, double CellSize)
{
	return S_FALSE;
}

HRESULT CBaseDEM::GetSupExts(BYTE* lpszExts, UINT accMode)
{
	if(lpszExts==NULL)
	{
		return S_FALSE;
	}

	strcpy((char*)lpszExts,
		"Tiff DEM(*.tif)|*.tif|Tiff DEM(*.tiff)|*.tiff|Bil DEM(*.bil)|*.bil|\
		ArcInfo Grid(*.grd)|*.grd|ASCII Grid(*.asc)|*.asc|EGX DEM(*.egx)|*.egx|\
		Virtuozo DEM(*.dem)|*.dem|\
		NSDTF DEM(*.dem)|*.dem||");
	return S_OK;
}



