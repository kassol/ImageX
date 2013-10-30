#include "StdAfx.h"
#include "VirtuozoDEM.h"
#include <io.h>

#import "ImageX.tlb" no_namespace named_guids


HRESULT CVirtuozoDEM::Open(BSTR bstrPathName, double lfAltitudeOffset, UINT accMode)
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

	int	nHZoom=1;
	char szTemp[20];
	fscanf(fp,"%lf%lf%lf%lf%lf%d%d%s",
		&m_X0,
		&m_Y0,
		&m_Kappa,
		&m_XCellSize,
		&m_YCellSize,
		&m_nCols,
		&m_nRows,
		szTemp);
	if(strchr(szTemp,'.')==NULL)
	{
		nHZoom=10;
	}
	fseek(fp,0,SEEK_SET);
	fscanf(fp,"%lf%lf%lf%lf%lf%d%d",
		&m_X0,
		&m_Y0,
		&m_Kappa,
		&m_XCellSize,
		&m_YCellSize,
		&m_nCols,
		&m_nRows);

	m_AveAltitude=0;
	m_MaxAltitude=-99999.9;
	m_MinAltitude=99999.9;
	double* pAltitude=new double[m_nRows*m_nCols];
	if(fabs(m_Kappa)<1e-5)
	{
		for(int i=0;i<m_nRows;i++)
		{
			double temp=0;
			int nCount=0;
			double* pAltitudeIndex=pAltitude+m_nCols*i;
			for(int j=0;j<m_nCols;j++)
			{
				fscanf(fp,"%lf",pAltitudeIndex+j);
				pAltitudeIndex[j]/=nHZoom;

				if(fabs(pAltitudeIndex[j]+9999.9)<1e-5)
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
	}
	else
	{
		for(int i=0;i<m_nRows;i++)
		{
			double temp=0;
			int nCount=0;
			double* pAltitudeIndex=pAltitude+m_nCols*i;
			for(int j=0;j<m_nCols;j++)
			{
				fscanf(fp,"%lf",pAltitudeIndex+j);

				pAltitudeIndex[j]/=nHZoom;
				if(fabs(pAltitudeIndex[j]+9999.9)<1e-5)
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
	}
	m_AveAltitude/=m_nRows;
	fclose(fp);

	//构造DEM栅格影像
	if(m_pImage!=NULL)
	{
		m_pImage->Close();
		m_pImage->Release();
		m_pImage=NULL;
		DeleteFile(m_strDemImage);
		DeleteFile(m_strDemImage.Left(m_strDemImage.ReverseFind('.'))+".img");
	}

	HRESULT hRes=CoCreateInstance(CLSID_ImageDriver,NULL,CLSCTX_ALL,IID_IImage,(void**)&m_pImage);
	if(FAILED(hRes))
	{
		AfxMessageBox(IDS_IMGDRIVER_FAIL);
		delete [] pAltitude;
		pAltitude=NULL;

		return S_FALSE;
	}
	m_strDemImage=strPathName.Left(strPathName.ReverseFind('.'))+"~~.hdr";
	int index=1;

	while(_access(m_strDemImage,0)!=-1)
	{
		CString strTemp;
		strTemp.Format("~~%d.hdr",index++);
		m_strDemImage=strPathName.Left(strPathName.ReverseFind('.'))+strTemp;
	}

	_bstr_t bstrDemImage=m_strDemImage;
	if(fabs(m_Kappa)<1e-5)
	{
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
	}
	else
	{
		double cosk=cos(m_Kappa);
		double sink=sin(m_Kappa);
		double dX=m_nCols*m_XCellSize;
		double dY=-m_nRows*m_YCellSize;

		//	0	1
		//	3	2
		double X0=m_X0;
		double Y0=m_Y0;

		double X1=m_X0+dX*cosk-0*sink;
		double Y1=m_Y0+dX*sink+0*cosk;

		double X2=m_X0+dX*cosk-dY*sink;
		double Y2=m_Y0+dX*sink+dY*cosk;

		double X3=m_X0+0*cosk-dY*sink;
		double Y3=m_Y0+0*sink+dY*cosk;

		double LBX=min(min(X0,X1),min(X2,X3));
		double LBY=min(min(Y0,Y1),min(Y2,Y3));
		double RTX=max(max(X0,X1),max(X2,X3));
		double RTY=max(max(Y0,Y1),max(Y2,Y3));

		int nRows=(int)((RTY-LBY)/m_YCellSize+0.5);
		int nCols=(int)((RTX-LBX)/m_XCellSize+0.5);

		if(m_pImage->CreateImg(bstrDemImage,modeCreate|modeWrite,
			nCols,nRows,Pixel_Double,
			1,BSQ,
			LBX,LBY,m_XCellSize)!=S_OK)
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
		for(int i=0;i<nRows;i++)
		{
			for(int j=0;j<nCols;j++)
			{
				double X=LBX+j*m_XCellSize;
				double Y=LBY+i*m_YCellSize;
				double dX=X-m_X0;
				double dY=Y-m_Y0;
				double x=(dX*cosk+dY*sink)/m_XCellSize;
				double y=-(-dX*sink+dY*cosk)/m_YCellSize;

				int nCol0=int(x);
				int nRow0=int(y);
				int nCol2=nCol0+1;
				int nRow2=nRow0+1;
				if((nCol0<0||nCol0>=m_nCols||nRow0<0||nRow0>=m_nRows)&&
					(nCol2<0||nCol2>=m_nCols||nRow2<0||nRow2>=m_nRows))
				{
					double Z=DBL_MAX;
					m_pImage->SetPixel(i,j,(BYTE*)&Z);
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

				double Z=DBL_MAX;
				if(Z0!=DBL_MAX&&Z1!=DBL_MAX&&Z2!=DBL_MAX&&Z3!=DBL_MAX)
				{
					Z=(1.0-dx) *  (1.0-dy)  *  Z0+
						dx    *  (1.0-dy)  *  Z1+
						dx    *  dy        *  Z2+
						(1.0-dx) *  dy        *  Z3;

					Z+=m_lfAltitudeOffset;
				}

				m_pImage->SetPixel(i,j,(BYTE*)&Z);
			}
		}
	}

	delete [] pAltitude;
	pAltitude=NULL;

	return S_OK;
}

HRESULT CVirtuozoDEM::Create(BSTR bstrPathName, BSTR bstrFormat, UINT accMode, int nRows, int nCols, double LBX, double LBY, double XCellSize, double YCellSize)
{
	return S_OK;
}

HRESULT CVirtuozoDEM::Close()
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

	return S_OK;
}

HRESULT CVirtuozoDEM::GetSupExts(BYTE* lpszExts, UINT accMode)
{
	if(lpszExts==NULL)
	{
		return S_FALSE;
	}

	strcpy((char*)lpszExts,"Virtuozo DEM(*.dem)|*.dem");

	return S_OK;
}

HRESULT CVirtuozoDEM::GetSupFormats(BYTE* lpszFormats, UINT accMode)
{
	if(lpszFormats==NULL)
	{
		return S_FALSE;
	}

	strcpy((char*)lpszFormats,"Virtuozo-DEM");

	return S_OK;
}

HRESULT CVirtuozoDEM::GetIImage(IImage** ppIImage)
{
	if(ppIImage==NULL)
	{
		return S_FALSE;
	}

	*ppIImage=m_pImage;

	return S_OK;
}

HRESULT CVirtuozoDEM::GetVertex(double* pX, double* pY, double* pZ, int* pVertexNum)
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

HRESULT CVirtuozoDEM::GetTriangle(int nTriIndex, double* pX, double* pY, double* pZ)
{
	return CBaseDEM::GetTriangleB(nTriIndex,pX,pY,pZ)==TRUE?S_OK:S_FALSE;
}

HRESULT CVirtuozoDEM::GetTriangleNum(int* pTriangleNum)
{
	*pTriangleNum=CBaseDEM::GetTriangleNum();

	return S_OK;
}

HRESULT CVirtuozoDEM::ConstrustTIN()
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

HRESULT CVirtuozoDEM::GetAverageAltitude(double* pZ)
{
	if(pZ==NULL)
	{
		return S_FALSE;
	}

	*pZ=m_AveAltitude;

	return S_OK;
}

HRESULT CVirtuozoDEM::GetAltitude(double X, double Y, double* pZ, UINT uResampleMethod)
{
	return CBaseDEM::GetAltitudeRaster(X,Y,pZ,uResampleMethod);
}

HRESULT CVirtuozoDEM::GetTIN(DWORD ppTriangulateio)
{
	return CBaseDEM::GetTINB(ppTriangulateio)==TRUE?S_OK:S_FALSE;
}

HRESULT CVirtuozoDEM::GetRange(double* pLBX, double* pLBY, double* pRTX, double* pRTY)
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

HRESULT CVirtuozoDEM::GetCellSize(double* pXCellSize, double* pYCellSize)
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

HRESULT CVirtuozoDEM::GetMaxAltitude(double* pZ)
{
	if(pZ==NULL)
	{
		return S_FALSE;
	}

	*pZ=m_MaxAltitude;

	return S_OK;
}

HRESULT CVirtuozoDEM::GetMinAltitude(double* pZ)
{
	if(pZ==NULL)
	{
		return S_FALSE;
	}

	*pZ=m_MinAltitude;

	return S_OK;
}

HRESULT CVirtuozoDEM::GetType(UINT* pType)
{
	*pType=DT_GRID;

	return S_OK;
}

HRESULT CVirtuozoDEM::GetRows(int* pRows)
{
	*pRows=m_nRows;

	return S_OK;
}

HRESULT CVirtuozoDEM::GetCols(int* pCols)
{
	*pCols=m_nCols;

	return S_OK;
}

HRESULT CVirtuozoDEM::GetStartPos(double* pX0, double* pY0)
{
	double temp;
	m_pImage->GetGrdInfo(pX0,pY0,&temp);

	return S_OK;
}

HRESULT CVirtuozoDEM::GetAltitudeValues(double* pZ)
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

HRESULT CVirtuozoDEM::IsSupported(BSTR bstrPathName, UINT accMode)
{
	//读取数据
	if(accMode&modeWrite||accMode&modeCreate)
	{
		return S_FALSE;
	}

	CString strPathName=CString(bstrPathName);
	CString strExt=strPathName.Right(strPathName.GetLength()-strPathName.ReverseFind('.')-1);
	if(strExt.CompareNoCase("dem")!=0)
	{
		return S_FALSE;
	}
	FILE* fp=fopen(strPathName,"rt");
	if(fp==NULL)
	{
		return S_FALSE;
	}

	double temp[7];
	int nRet=fscanf(fp,"%lf%lf%lf%lf%lf%lf%lf",&temp[0],&temp[1],
		&temp[2],&temp[3],
		&temp[4],&temp[5],
		&temp[6]);
	fclose(fp);

	if(nRet==7)
	{
		return S_OK;
	}

	return S_FALSE;
}

