#include "StdAfx.h"
#include "ArcGridDEM.h"
#include <io.h>

#import "Reference.tlb" no_namespace named_guids
#import "ImageX.tlb" no_namespace named_guids

#define PI 3.141592653589793238462643383279502884197169399375105820974944592308


HRESULT CArcGridDEM::Open(BSTR bstrPathName, double lfAltitudeOffset, UINT accMode)
{
	CString strPathName=CString(bstrPathName);
	m_strDEMPathName=strPathName;
	m_lfAltitudeOffset=lfAltitudeOffset;

	if(IsSupported(bstrPathName,accMode))
	{
		return S_FALSE;
	}

	if(_access(strPathName,0)==-1)
	{
		CString strMsg;
		strMsg.Format(IDS_FILE_OPEN_FAILED,strPathName);
		AfxMessageBox(strMsg);

		return S_FALSE;
	}
	//读取数据
	FILE* fp=fopen(strPathName,"rt");
	if(fp==NULL)
	{
		return S_FALSE;
	}

	char  keyword[50];  
	BOOL bEdgeX,bEdgeY;
	bEdgeX = FALSE;
	bEdgeY = FALSE;
	m_Kappa=0.0;
	double lfInvalideValue;
	for ( int num = 0 ; num<6 ; num++ )
	{
		fscanf(fp,"%s",keyword);
		if      ( _stricmp(keyword,"ncols")==0 )        fscanf(fp,"%d",&m_nCols);
		else if ( _stricmp(keyword,"nrows")==0 )        fscanf(fp,"%d",&m_nRows);
		else if ( _stricmp(keyword,"cellsize")==0 )     { fscanf(fp,"%lf",&m_XCellSize);  m_YCellSize = m_XCellSize; }
		else if ( _stricmp(keyword,"xllcenter")==0 )    fscanf(fp,"%lf",&m_X0);
		else if ( _stricmp(keyword,"xllcorner")==0 )    { fscanf(fp,"%lf",&m_X0);bEdgeX=TRUE; }
		else if ( _stricmp(keyword,"yllcenter")==0 )    fscanf(fp,"%lf",&m_Y0);
		else if ( _stricmp(keyword,"yllcorner")==0 )    { fscanf(fp,"%lf",&m_Y0);bEdgeY=TRUE;}
		else if ( _stricmp(keyword,"nodata_value")==0 ) fscanf(fp,"%lf",&lfInvalideValue);
		else if( 0==_stricmp(keyword,"xdim") )		{fscanf(fp,"%lf",&m_XCellSize);}
		else if( 0==_stricmp(keyword,"ydim") )		{fscanf(fp,"%lf",&m_YCellSize);}
		else 
		{
			continue;
		}
	}
	if( bEdgeX )
	{
		m_X0 += m_XCellSize*0.5;
	}
	if( bEdgeY )
	{
		m_Y0 += m_YCellSize*0.5;
	}

	m_AveAltitude=0;
	m_MaxAltitude=-99999.9;
	m_MinAltitude=99999.9;
	int nCount=0;
	double* pAltitude=new double[m_nRows*m_nCols];
	for(int i=0;i<m_nRows;i++)
	{
		double temp=0;
		int nCount=0;
		double* pAltitudeIndex=pAltitude+(m_nRows-1-i)*m_nCols;
		for(int j=0;j<m_nCols;j++)
		{
			fscanf(fp,"%lf",pAltitudeIndex+j);

			if(fabs(pAltitudeIndex[j]+lfInvalideValue)<1e-5)
			{
				pAltitudeIndex[j]=DBL_MAX;
			}
			else
			{
				pAltitudeIndex[j]+=m_lfAltitudeOffset;

				if(pAltitudeIndex[j]>m_MaxAltitude)
				{
					m_MaxAltitude=pAltitudeIndex[j];
				}
				if(pAltitudeIndex[j]<m_MinAltitude)
				{
					m_MinAltitude=pAltitudeIndex[j];
				}

				temp+=pAltitudeIndex[j];
				nCount++;
			}
		}
		if(nCount>0)
		{
			m_AveAltitude+=(temp/nCount);
		}
	}

	m_AveAltitude/=m_nRows;
	fclose(fp);

	//将经纬度格网DEM转换位WGS84 UTM投影
	CString strPrjFile=m_strDEMPathName.Left(m_strDEMPathName.ReverseFind('.'))+".prj";
	FILE* fpPrj=fopen(strPrjFile,"rt");
	if(fpPrj!=NULL)
	{
		char szTag[100],szProjection[100];
		fscanf(fp,"%s%s",szTag,szProjection);
		fclose(fpPrj);
		if(CString(szProjection).CompareNoCase(_T("GEOGRAPHIC"))==0)
		{
			IProjectionPtr spWGS84(CLSID_ProjectWGS84);
			spWGS84->CreateProject(L"WGS-84");
			if(spWGS84!=NULL)
			{
				double X[4],Y[4];
				double lat[4],lon[4];
				double* pTMAltitude=new double[m_nRows*m_nCols];
				memset(pTMAltitude,0,sizeof(double)*m_nRows*m_nCols);

				double lfLongitude,lfLatitude;
				lfLongitude=(m_X0+m_X0+m_nCols*m_XCellSize)/2/3600*PI/180;
				lfLatitude=(m_Y0+m_Y0+m_nRows*m_YCellSize)/2/3600*PI/180;
				long nZone;
				spWGS84->CalcZone(lfLatitude,lfLongitude,&nZone);
				spWGS84->SetZone(nZone);

				lon[0]=m_X0/3600*PI/180;
				lat[0]=m_Y0/3600*PI/180;
				spWGS84->Geodetic2Map(lat[0],lon[0],&X[0],&Y[0]);

				lon[1]=(m_X0+m_nCols*m_XCellSize)/3600*PI/180;
				lat[1]=m_Y0/3600*PI/180;
				spWGS84->Geodetic2Map(lat[1],lon[1],&X[1],&Y[1]);

				lon[2]=(m_X0+m_nCols*m_XCellSize)/3600*PI/180;
				lat[2]=(m_Y0+m_nRows*m_YCellSize)/3600*PI/180;
				spWGS84->Geodetic2Map(lat[2],lon[2],&X[2],&Y[2]);

				lon[3]=m_X0/3600*PI/180;
				lat[3]=(m_Y0+m_nRows*m_YCellSize)/3600*PI/180;
				spWGS84->Geodetic2Map(lat[3],lon[3],&X[3],&Y[3]);

				double LBX=min(min(X[0],X[1]),min(X[2],X[3]));
				double LBY=min(min(Y[0],Y[1]),min(Y[2],Y[3]));

				double RTX=max(max(X[0],X[1]),max(X[2],X[3]));
				double RTY=max(max(Y[0],Y[1]),max(Y[2],Y[3]));

				double lfCellSize=max((RTX-LBX)/m_XCellSize,(RTY-LBY)/m_YCellSize);

				for(int i=0;i<m_nRows;i++)
				{
					double tmY=LBY+i*lfCellSize;
					double* pTMAltitudeIndex=pTMAltitude+m_nCols*i;

					for(int j=0;j<m_nCols;j++)
					{
						double tmX=LBX+j*lfCellSize;

						spWGS84->Map2Geodetic(tmX,tmY,&lfLatitude,&lfLongitude);
						double x=(lfLongitude-m_X0)/m_XCellSize;
						double y=(lfLatitude-m_Y0)/m_YCellSize;

						int nCol0=int(x);
						int nRow0=int(y);
						int nCol2=nCol0+1;
						int nRow2=nRow0+1;
						if((nCol0<0||nCol0>=m_nCols||nRow0<0||nRow0>=m_nRows)&&
							(nCol2<0||nCol2>=m_nCols||nRow2<0||nRow2>=m_nRows))
						{
							pTMAltitudeIndex[j]=DBL_MAX;
							continue;
						}

						nCol0=max(nCol0,0);
						nRow0=max(nRow0,0);
						nCol0=min(nCol0,m_nCols-1);
						nRow0=min(nRow0,m_nRows-1);
						nCol2=max(nCol2,0);
						nRow2=max(nRow2,0);
						nCol2=min(nCol2,m_nCols-1);
						nRow2=min(nRow2,m_nRows-1);

						double dx=x-nCol0;
						double dy=y-nRow0;

						double Z0=pAltitude[nRow0*m_nCols+nCol0];
						double Z1=pAltitude[nRow0*m_nCols+nCol2];
						double Z2=pAltitude[nRow2*m_nCols+nCol2];
						double Z3=pAltitude[nRow2*m_nCols+nCol0];

						if(Z0!=DBL_MAX&&Z1!=DBL_MAX&&Z2!=DBL_MAX&&Z3!=DBL_MAX)
						{
							pTMAltitudeIndex[j]=(1.0-dx)   *  (1.0-dy)  *  Z0+
								dx    *  (1.0-dy)  *  Z1+
								dx    *  dy        *  Z2+
								(1.0-dx) *  dy        *  Z3;
						}
						else
						{
							pTMAltitudeIndex[j]=DBL_MAX;
						}
					}
				}

				memcpy(pAltitude,pTMAltitude,sizeof(double)*m_nRows*m_nCols);

				delete [] pTMAltitude;
				pTMAltitude=NULL;

				m_X0=LBX;
				m_Y0=LBY;
				m_XCellSize=lfCellSize;
				m_YCellSize=lfCellSize;
			}
		}
	}

	//构造DEM栅格影像
	if(m_pImage!=NULL)
	{
		m_pImage->Close();
		m_pImage->Release();
		m_pImage=NULL;
		DeleteFile(m_strDemImage);
		DeleteFile(m_strDemImage.Left(m_strDemImage.ReverseFind('.'))+".img");
	}

	HRESULT hRes=CoCreateInstance(CLSID_ImageDriverX,NULL,CLSCTX_ALL,IID_IImageX,(void**)&m_pImage);
	if(FAILED(hRes))
	{
		AfxMessageBox(IDS_IMGDRIVER_FAIL);
		delete [] pAltitude;
		pAltitude=NULL;

		return S_FALSE;
	}

	m_strDemImage=strPathName.Left(strPathName.ReverseFind('.'))+_T("~~.hdr");
	int index=1;
	while(_access(m_strDemImage,0)!=-1)
	{
		CString strTemp;
		strTemp.Format(_T("~~%d.hdr"),index++);
		m_strDemImage=strPathName.Left(strPathName.ReverseFind('.'))+strTemp;
	}
	_bstr_t bstrDemImage=m_strDemImage;
	if(m_pImage->CreateImg(bstrDemImage,modeCreate|modeWrite,
		m_nCols,m_nRows,Pixel_Double,
		1,BSQ,
		m_X0,m_Y0,m_XCellSize)!=S_OK)
	{
		CString strMsg;
		strMsg.Format(IDS_FILE_OPEN_FAILED,m_strDemImage);
		AfxMessageBox(strMsg);

		m_pImage->Release();
		m_pImage=NULL;

		delete [] pAltitude;
		pAltitude=NULL;

		return S_FALSE;
	}

	m_pImage->WriteImg(0,0,m_nCols,m_nRows,
		(BYTE*)pAltitude,m_nCols,m_nRows,
		1,
		0,0,m_nCols,m_nRows,
		-1,0);

	delete [] pAltitude;
	pAltitude=NULL;

	return S_OK;
}

HRESULT CArcGridDEM::Create(BSTR bstrPathName, BSTR bstrFormat, UINT accMode, int nRows, int nCols, double LBX, double LBY, double XCellSize, double YCellSize)
{
	return S_OK;
}

HRESULT CArcGridDEM::Close()
{
	if(m_pImage!=NULL)
	{
		m_pImage->Close();
		m_pImage->Release();
		m_pImage=NULL;
	}
	DeleteFile(m_strDemImage);
	DeleteFile(m_strDemImage.Left(m_strDemImage.ReverseFind('.'))+".img");

	if(m_pCacheBuffer!=NULL)
	{
		delete m_pCacheBuffer;
		m_pCacheBuffer=NULL;
	}

	m_lfAltitudeOffset=0;

	return S_OK;
}

HRESULT CArcGridDEM::GetSupExts(BYTE* lpszExts, UINT accMode)
{
	if(lpszExts==NULL)
	{
		return S_FALSE;
	}

	strcpy((char*)lpszExts,"ArcInfo Grid(*.grd)|*.grd|ASCII Grid(*.asc)|*.asc|EGX DEM(*.egx)|*.egx");

	return S_OK;
}

HRESULT CArcGridDEM::GetSupFormats(BYTE* lpszFormats, UINT accMode)
{
	if(lpszFormats==NULL)
	{
		return S_FALSE;
	}

	strcpy((char*)lpszFormats,"ArcInfo-Grid");

	return S_OK;
}

HRESULT CArcGridDEM::GetIImage(IImageX** ppIImage)
{
	if(ppIImage==NULL)
	{
		return S_FALSE;
	}

	*ppIImage=m_pImage;

	return S_OK;
}

HRESULT CArcGridDEM::GetVertex(double* pX, double* pY, double* pZ, int* pVertexNum)
{
	if(m_pImage==NULL)
	{
		return S_FALSE;
	}

	if(pX==NULL||pY==NULL||pZ==NULL)
	{
		if(pVertexNum!=NULL)
		{
			*pVertexNum=m_nRows*m_nCols;
		}

		return S_FALSE;
	}

	if(pVertexNum==NULL)
	{
		return S_FALSE;
	}
	if(*pVertexNum<m_nRows*m_nCols)
	{
		return S_FALSE;
	}

	//获取DEM起点
	double X0,Y0,CellSize;
	m_pImage->GetGrdInfo(&X0,&Y0,&CellSize);
	//获取DEM格网点
	for(int i=0;i<m_nRows;i++)
	{
		double* pXIndex=pX+i*m_nCols;
		double* pYIndex=pY+i*m_nCols;

		double X=X0;
		double Y=Y0+i*CellSize;

		for(int j=0;j<m_nCols;j++)
		{
			pXIndex[j]=X;
			pYIndex[j]=Y;

			X+=CellSize;
		}
	}
	m_pImage->ReadImg(0,0,m_nCols,m_nRows,
		(BYTE*)pZ,m_nCols,m_nRows,
		1,
		0,0,m_nCols,m_nRows,
		0,0);

	return S_OK;
}

HRESULT CArcGridDEM::GetTriangle(int nTriIndex, double* pX, double* pY, double* pZ)
{
	return CBaseDEM::GetTriangleB(nTriIndex,pX,pY,pZ)==TRUE?S_OK:S_FALSE;
}

HRESULT CArcGridDEM::GetTriangleNum(int* pTriangleNum)
{
	*pTriangleNum=CBaseDEM::GetTriangleNum();

	return S_OK;
}

HRESULT CArcGridDEM::ConstrustTIN()
{
	//获取DEM起点
	double X0,Y0,CellSize;
	m_pImage->GetGrdInfo(&X0,&Y0,&CellSize);
	//获取DEM格网点
	double* pX=new double[m_nRows*m_nCols];
	double* pY=new double[m_nRows*m_nCols];
	double* pZ=new double[m_nRows*m_nCols];

	for(int i=0;i<m_nRows;i++)
	{
		double* pXIndex=pX+i*m_nCols;
		double* pYIndex=pY+i*m_nCols;

		double X=X0;
		double Y=Y0+i*CellSize;

		for(int j=0;j<m_nCols;j++)
		{
			pXIndex[j]=X;
			pYIndex[j]=Y;

			X+=CellSize;
		}
	}
	m_pImage->ReadImg(0,0,m_nCols,m_nRows,
		(BYTE*)pZ,m_nCols,m_nRows,
		1,
		0,0,m_nCols,m_nRows,
		0,0);

	for(int i=0;i<m_nRows*m_nCols;i++)
	{
		if(pZ[i]==DBL_MAX)
		{
			pZ[i]=INVALID_ALTITUDE;
		}
	}
	//构造三角网
	CBaseDEM::ContrustTIN(pX,pY,pZ,m_nRows*m_nCols);

	delete [] pX; pX=NULL;
	delete [] pY; pY=NULL;
	delete [] pZ; pZ=NULL;

	return S_OK;
}

HRESULT CArcGridDEM::GetAverageAltitude(double* pZ)
{
	if(pZ==NULL)
	{
		return S_FALSE;
	}

	*pZ=m_AveAltitude;

	return S_OK;
}

HRESULT CArcGridDEM::GetAltitude(double X, double Y, double* pZ, UINT uResampleMethod)
{
	return CBaseDEM::GetAltitudeRaster(X,Y,pZ,uResampleMethod);
}

HRESULT CArcGridDEM::GetTIN(DWORD ppTriangulateio)
{
	return CBaseDEM::GetTINB(ppTriangulateio)==TRUE?S_OK:S_FALSE;
}

HRESULT CArcGridDEM::GetRange(double* pLBX, double* pLBY, double* pRTX, double* pRTY)
{
	if(m_pImage)
	{
		double CellSize;
		m_pImage->GetGrdInfo(pLBX,pLBY,&CellSize);
		int nRows,nCols;
		m_pImage->GetRows(&nRows);
		m_pImage->GetCols(&nCols);
		*pRTX=*pLBX+nCols*CellSize;
		*pRTY=*pLBY+nRows*CellSize;

		return S_OK;
	}

	return S_FALSE;
}

HRESULT CArcGridDEM::GetCellSize(double* pXCellSize, double* pYCellSize)
{
	if(m_pImage)
	{
		double LBX,LBY;
		double CellSize;
		m_pImage->GetGrdInfo(&LBX,&LBY,&CellSize);
		*pXCellSize=CellSize;
		*pYCellSize=CellSize;

		return S_OK;
	}

	return S_FALSE;
}

HRESULT CArcGridDEM::GetMaxAltitude(double* pZ)
{
	if(pZ==NULL)
	{
		return S_FALSE;
	}

	*pZ=m_MaxAltitude;

	return S_OK;
}

HRESULT CArcGridDEM::GetMinAltitude(double* pZ)
{
	if(pZ==NULL)
	{
		return S_FALSE;
	}

	*pZ=m_MinAltitude;

	return S_OK;
}

HRESULT CArcGridDEM::GetType(UINT* pType)
{
	*pType=DT_GRID;

	return S_OK;
}

HRESULT CArcGridDEM::GetRows(int* pRows)
{
	*pRows=m_nRows;

	return S_OK;
}

HRESULT CArcGridDEM::GetCols(int* pCols)
{
	*pCols=m_nCols;

	return S_OK;
}

HRESULT CArcGridDEM::GetStartPos(double* pX0, double* pY0)
{
	double temp;
	m_pImage->GetGrdInfo(pX0,pY0,&temp);

	return S_OK;
}

HRESULT CArcGridDEM::GetAltitudeValues(double* pZ)
{
	m_pImage->ReadImg(0,0,m_nCols,m_nRows,
		(BYTE*)pZ,m_nCols,m_nRows,
		1,
		0,0,m_nCols,m_nRows,
		0,0);

	for(int i=0;i<m_nRows*m_nCols;i++)
	{
		if(pZ[i]==DBL_MAX)
		{
			pZ[i]=INVALID_ALTITUDE;
		}
	}

	return S_OK;
}

HRESULT CArcGridDEM::IsSupported(BSTR bstrPathName, UINT accMode)
{
	//读取数据
	if(accMode&modeWrite||accMode&modeCreate)
	{
		return S_FALSE;
	}

	CString strPathName=CString(bstrPathName);
	CString strExt=strPathName.Right(strPathName.GetLength()-strPathName.ReverseFind('.')-1);
	if(strExt.CompareNoCase(_T("grd"))!=0&&
		strExt.CompareNoCase(_T("asc"))!=0&&
		strExt.CompareNoCase(_T("egx"))!=0)
	{
		return S_FALSE;
	}

	return S_OK;
}

