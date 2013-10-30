#include "StdAfx.h"
#include "TiffDEM.h"
#include <io.h>

#import "ImageX.tlb" no_namespace named_guids


HRESULT CTiffDEM::Open(BSTR bstrPathName, double lfAltitudeOffset, UINT accMode)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

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
	//打开DEM栅格影像
	if(m_pImage!=NULL)
	{
		m_pImage->Close();
		m_pImage->Release();
		m_pImage=NULL;
	}

	HRESULT hRes=CoCreateInstance(CLSID_ImageDriver,NULL,CLSCTX_ALL,IID_IImage,(void**)&m_pImage);
	if(FAILED(hRes))
	{
		AfxMessageBox(IDS_IMGDRIVER_FAIL);

		return S_FALSE;
	}

	_bstr_t bstrDemImage=strPathName;
	if(m_pImage->Open(bstrDemImage,modeRead)==S_FALSE)
	{
		return S_FALSE;
	}
	m_AveAltitude=0;
	m_MaxAltitude=-99999.9;
	m_MinAltitude=99999.9;
	m_pImage->GetRows(&m_nRows);
	m_pImage->GetCols(&m_nCols);
	int nBPB;
	m_pImage->GetBPB(&nBPB);
	UINT nDataType;
	m_pImage->GetDataType(&nDataType);
	m_pImage->GetGrdInfo(&m_X0,&m_Y0,&m_XCellSize);
	m_YCellSize=m_XCellSize;
	m_Kappa=0;
	BYTE* pBuffer=new BYTE[m_nCols*nBPB];
	for(int i=0;i<m_nRows;i++)
	{
		m_pImage->ReadImg(0,i,m_nCols,i+1,
			(BYTE*)pBuffer,m_nCols,1,
			1,
			0,0,m_nCols,1,
			0,0);

		double temp=0;
		int nCount=0;
		switch(nDataType)
		{
		case Pixel_Byte:
			{
				BYTE* pAltitude=(BYTE*)pBuffer;
				for(int j=0;j<m_nCols;j++)
				{
					if(pAltitude[j]>m_MaxAltitude)
					{
						m_MaxAltitude=pAltitude[j];
					}
					if(pAltitude[j]<m_MinAltitude)
					{
						m_MinAltitude=pAltitude[j];
					}

					temp+=pAltitude[j];
					nCount++;
				}
			}
			break;
		case Pixel_Int16:
			{
				unsigned short* pAltitude=(unsigned short*)pBuffer;
				for(int j=0;j<m_nCols;j++)
				{
					if(pAltitude[j]>m_MaxAltitude)
					{
						m_MaxAltitude=pAltitude[j];
					}
					if(pAltitude[j]<m_MinAltitude)
					{
						m_MinAltitude=pAltitude[j];
					}

					temp+=pAltitude[j];
					nCount++;
				}
			}
			break;
		case Pixel_SInt16:
			{
				short* pAltitude=(short*)pBuffer;
				for(int j=0;j<m_nCols;j++)
				{
					if(pAltitude[j]>m_MaxAltitude)
					{
						m_MaxAltitude=pAltitude[j];
					}
					if(pAltitude[j]<m_MinAltitude)
					{
						m_MinAltitude=pAltitude[j];
					}

					temp+=pAltitude[j];
					nCount++;
				}
			}
			break;
		case Pixel_Int32:
			{
				unsigned int* pAltitude=(unsigned int*)pBuffer;
				for(int j=0;j<m_nCols;j++)
				{
					if(pAltitude[j]>m_MaxAltitude)
					{
						m_MaxAltitude=pAltitude[j];
					}
					if(pAltitude[j]<m_MinAltitude)
					{
						m_MinAltitude=pAltitude[j];
					}

					temp+=pAltitude[j];
					nCount++;
				}
			}
			break;
		case Pixel_SInt32:
			{
				int* pAltitude=(int*)pBuffer;
				for(int j=0;j<m_nCols;j++)
				{
					if(pAltitude[j]>m_MaxAltitude)
					{
						m_MaxAltitude=pAltitude[j];
					}
					if(pAltitude[j]<m_MinAltitude)
					{
						m_MinAltitude=pAltitude[j];
					}

					temp+=pAltitude[j];
					nCount++;
				}
			}
			break;
		case Pixel_Float:
			{
				float* pAltitude=(float*)pBuffer;
				for(int j=0;j<m_nCols;j++)
				{
					if(pAltitude[j]>m_MaxAltitude)
					{
						m_MaxAltitude=pAltitude[j];
					}
					if(pAltitude[j]<m_MinAltitude)
					{
						m_MinAltitude=pAltitude[j];
					}

					temp+=pAltitude[j];
					nCount++;
				}
			}
			break;
		case Pixel_Double:
			{
				double* pAltitude=(double*)pBuffer;
				for(int j=0;j<m_nCols;j++)
				{
					if(pAltitude[j]>m_MaxAltitude)
					{
						m_MaxAltitude=pAltitude[j];
					}
					if(pAltitude[j]<m_MinAltitude)
					{
						m_MinAltitude=pAltitude[j];
					}

					temp+=pAltitude[j];
					nCount++;
				}
			}
			break;
		}
		if(nCount>0)
		{
			temp/=nCount;
			m_AveAltitude+=temp;
		}
	}
	m_AveAltitude/=m_nRows;
	delete [] pBuffer;
	pBuffer=NULL;

	return S_OK;
}

HRESULT CTiffDEM::Create(BSTR bstrPathName, BSTR bstrFormat, UINT accMode, int nRows, int nCols, double LBX, double LBY, double XCellSize, double YCellSize)
{
	return S_OK;
}

HRESULT CTiffDEM::Close()
{
	if(m_pImage!=NULL)
	{
		m_pImage->Close();
		m_pImage->Release();
		m_pImage=NULL;
	}
	return S_OK;
}

HRESULT CTiffDEM::GetSupExts(BYTE* lpszExts, UINT accMode)
{
	if(lpszExts==NULL)
	{
		return S_FALSE;
	}

	strcpy((char*)lpszExts,"Tiff DEM(*.tif)|*.tif|Tiff DEM(*.tiff)|*.tiff");

	return S_OK;
}

HRESULT CTiffDEM::GetSupFormats(BYTE* lpszFormats, UINT accMode)
{
	if(lpszFormats==NULL)
	{
		return S_FALSE;
	}

	strcpy((char*)lpszFormats,"TIFF-DEM");

	return S_OK;
}

HRESULT CTiffDEM::GetIImage(IImage** ppIImage)
{
	if(ppIImage==NULL)
	{
		return S_FALSE;
	}

	*ppIImage=m_pImage;

	return S_OK;
}

HRESULT CTiffDEM::GetVertex(double* pX, double* pY, double* pZ, int* pVertexNum)
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
	GetAltitudeValues(pZ);

	return S_OK;
}

HRESULT CTiffDEM::GetTriangle(int nTriIndex, double* pX, double* pY, double* pZ)
{
	return CBaseDEM::GetTriangleB(nTriIndex,pX,pY,pZ)==TRUE?S_OK:S_FALSE;
}

HRESULT CTiffDEM::GetTriangleNum(int* pTriangleNum)
{
	*pTriangleNum=CBaseDEM::GetTriangleNum();

	return S_OK;
}

HRESULT CTiffDEM::ConstrustTIN()
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
	GetAltitudeValues(pZ);

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

HRESULT CTiffDEM::GetAverageAltitude(double* pZ)
{
	if(pZ==NULL)
	{
		return S_FALSE;
	}

	*pZ=m_AveAltitude+m_lfAltitudeOffset;

	return S_OK;
}

HRESULT CTiffDEM::GetAltitude(double X, double Y, double* pZ, UINT uResampleMethod)
{
	*pZ=INVALID_ALTITUDE;
	if(m_pImage==NULL)
	{
		return S_FALSE;
	}

	float x,y;
	m_pImage->World2Image(X,Y,&x,&y);
	int nCol0=int(x);
	int nRow0=int(y);
	int nCol2=nCol0+1;
	int nRow2=nRow0+1;
	if((nCol0<0||nCol0>=m_nCols||nRow0<0||nRow0>=m_nRows)&&
		(nCol2<0||nCol2>=m_nCols||nRow2<0||nRow2>=m_nRows))
	{
		*pZ=INVALID_ALTITUDE;//m_AveAltitude

		return S_FALSE;
	}

	double dx=x-nCol0;
	double dy=y-nRow0;

	UINT nDataType;
	m_pImage->GetDataType(&nDataType);
	switch(nDataType)
	{
	case Pixel_Byte:
		{
			BYTE Z0,Z1,Z2,Z3;
			m_pImage->GetGray(nRow0,nCol0,0,(BYTE*)&Z0);
			m_pImage->GetGray(nRow0,nCol2,0,(BYTE*)&Z1);
			m_pImage->GetGray(nRow2,nCol2,0,(BYTE*)&Z2);
			m_pImage->GetGray(nRow2,nCol0,0,(BYTE*)&Z3);

			//if(Z0!=DBL_MAX&&Z1!=DBL_MAX&&Z2!=DBL_MAX&&Z3!=DBL_MAX)
			{
				*pZ=(1.0-dx) *  (1.0-dy)  *  Z0+
					dx    *  (1.0-dy)  *  Z1+
					dx    *  dy        *  Z2+
					(1.0-dx) *  dy        *  Z3;

				*pZ+=m_lfAltitudeOffset;

				return S_OK;
			}
			//else
			//{
			//	return S_FALSE;
			//}
		}
		break;
	case Pixel_Int16:
		{
			unsigned short Z0,Z1,Z2,Z3;
			m_pImage->GetGray(nRow0,nCol0,0,(BYTE*)&Z0);
			m_pImage->GetGray(nRow0,nCol2,0,(BYTE*)&Z1);
			m_pImage->GetGray(nRow2,nCol2,0,(BYTE*)&Z2);
			m_pImage->GetGray(nRow2,nCol0,0,(BYTE*)&Z3);

			//if(Z0!=DBL_MAX&&Z1!=DBL_MAX&&Z2!=DBL_MAX&&Z3!=DBL_MAX)
			{
				*pZ=(1.0-dx) *  (1.0-dy)  *  Z0+
					dx    *  (1.0-dy)  *  Z1+
					dx    *  dy        *  Z2+
					(1.0-dx) *  dy        *  Z3;

				*pZ+=m_lfAltitudeOffset;

				return S_OK;
			}
			//else
			//{
			//	return S_FALSE;
			//}
		}
		break;
	case Pixel_SInt16:
		{
			short Z0,Z1,Z2,Z3;
			m_pImage->GetGray(nRow0,nCol0,0,(BYTE*)&Z0);
			m_pImage->GetGray(nRow0,nCol2,0,(BYTE*)&Z1);
			m_pImage->GetGray(nRow2,nCol2,0,(BYTE*)&Z2);
			m_pImage->GetGray(nRow2,nCol0,0,(BYTE*)&Z3);

			//if(Z0!=DBL_MAX&&Z1!=DBL_MAX&&Z2!=DBL_MAX&&Z3!=DBL_MAX)
			{
				*pZ=(1.0-dx) *  (1.0-dy)  *  Z0+
					dx    *  (1.0-dy)  *  Z1+
					dx    *  dy        *  Z2+
					(1.0-dx) *  dy        *  Z3;

				*pZ+=m_lfAltitudeOffset;

				return S_OK;
			}
			//else
			//{
			//	return S_FALSE;
			//}
		}
		break;
	case Pixel_Int32:
		{
			unsigned int Z0,Z1,Z2,Z3;
			m_pImage->GetGray(nRow0,nCol0,0,(BYTE*)&Z0);
			m_pImage->GetGray(nRow0,nCol2,0,(BYTE*)&Z1);
			m_pImage->GetGray(nRow2,nCol2,0,(BYTE*)&Z2);
			m_pImage->GetGray(nRow2,nCol0,0,(BYTE*)&Z3);

			//if(Z0!=DBL_MAX&&Z1!=DBL_MAX&&Z2!=DBL_MAX&&Z3!=DBL_MAX)
			{
				*pZ=(1.0-dx) *  (1.0-dy)  *  Z0+
					dx    *  (1.0-dy)  *  Z1+
					dx    *  dy        *  Z2+
					(1.0-dx) *  dy        *  Z3;

				*pZ+=m_lfAltitudeOffset;

				return S_OK;
			}
			//else
			//{
			//	return S_FALSE;
			//}
		}
		break;
	case Pixel_SInt32:
		{
			int Z0,Z1,Z2,Z3;
			m_pImage->GetGray(nRow0,nCol0,0,(BYTE*)&Z0);
			m_pImage->GetGray(nRow0,nCol2,0,(BYTE*)&Z1);
			m_pImage->GetGray(nRow2,nCol2,0,(BYTE*)&Z2);
			m_pImage->GetGray(nRow2,nCol0,0,(BYTE*)&Z3);

			//if(Z0!=DBL_MAX&&Z1!=DBL_MAX&&Z2!=DBL_MAX&&Z3!=DBL_MAX)
			{
				*pZ=(1.0-dx) *  (1.0-dy)  *  Z0+
					dx    *  (1.0-dy)  *  Z1+
					dx    *  dy        *  Z2+
					(1.0-dx) *  dy        *  Z3;

				*pZ+=m_lfAltitudeOffset;

				return S_OK;
			}
			//else
			//{
			//	return S_FALSE;
			//}
		}
		break;
	case Pixel_Float:
		{
			float Z0,Z1,Z2,Z3;
			m_pImage->GetGray(nRow0,nCol0,0,(BYTE*)&Z0);
			m_pImage->GetGray(nRow0,nCol2,0,(BYTE*)&Z1);
			m_pImage->GetGray(nRow2,nCol2,0,(BYTE*)&Z2);
			m_pImage->GetGray(nRow2,nCol0,0,(BYTE*)&Z3);

			//if(Z0!=DBL_MAX&&Z1!=DBL_MAX&&Z2!=DBL_MAX&&Z3!=DBL_MAX)
			{
				*pZ=(1.0-dx) *  (1.0-dy)  *  Z0+
					dx    *  (1.0-dy)  *  Z1+
					dx    *  dy        *  Z2+
					(1.0-dx) *  dy        *  Z3;

				*pZ+=m_lfAltitudeOffset;

				return S_OK;
			}
			//else
			//{
			//	return S_FALSE;
			//}
		}
		break;
	case Pixel_Double:
		{
			double Z0,Z1,Z2,Z3;
			m_pImage->GetGray(nRow0,nCol0,0,(BYTE*)&Z0);
			m_pImage->GetGray(nRow0,nCol2,0,(BYTE*)&Z1);
			m_pImage->GetGray(nRow2,nCol2,0,(BYTE*)&Z2);
			m_pImage->GetGray(nRow2,nCol0,0,(BYTE*)&Z3);

			if(Z0!=DBL_MAX&&Z1!=DBL_MAX&&Z2!=DBL_MAX&&Z3!=DBL_MAX)
			{
				*pZ=(1.0-dx) *  (1.0-dy)  *  Z0+
					dx    *  (1.0-dy)  *  Z1+
					dx    *  dy        *  Z2+
					(1.0-dx) *  dy        *  Z3;

				*pZ+=m_lfAltitudeOffset;

				return S_OK;
			}
			else
			{
				return S_FALSE;
			}
		}
		break;
	}

	return S_FALSE;
}

HRESULT CTiffDEM::GetTIN(DWORD ppTriangulateio)
{
	return CBaseDEM::GetTINB(ppTriangulateio)==TRUE?S_OK:S_FALSE;
}

HRESULT CTiffDEM::GetRange(double* pLBX, double* pLBY, double* pRTX, double* pRTY)
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

HRESULT CTiffDEM::GetCellSize(double* pXCellSize, double* pYCellSize)
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

HRESULT CTiffDEM::GetMaxAltitude(double* pZ)
{
	if(pZ==NULL)
	{
		return S_FALSE;
	}

	*pZ=m_MaxAltitude+m_lfAltitudeOffset;

	return S_OK;
}

HRESULT CTiffDEM::GetMinAltitude(double* pZ)
{
	if(pZ==NULL)
	{
		return S_FALSE;
	}

	*pZ=m_MinAltitude+m_lfAltitudeOffset;

	return S_OK;
}

HRESULT CTiffDEM::GetType(UINT* pType)
{
	*pType=DT_GRID;

	return S_OK;
}

HRESULT CTiffDEM::GetRows(int* pRows)
{
	*pRows=m_nRows;

	return S_OK;
}

HRESULT CTiffDEM::GetCols(int* pCols)
{
	*pCols=m_nCols;

	return S_OK;
}

HRESULT CTiffDEM::GetStartPos(double* pX0, double* pY0)
{
	double temp;
	m_pImage->GetGrdInfo(pX0,pY0,&temp);

	return S_OK;
}

HRESULT CTiffDEM::GetAltitudeValues(double* pZ)
{
	if(m_pImage==NULL)
	{
		return S_FALSE;
	}
	UINT nDataType;
	m_pImage->GetDataType(&nDataType);
	int nBPB;
	m_pImage->GetBPB(&nBPB);
	switch(nDataType)
	{
	case Pixel_Byte:
		{
			BYTE* pBuffer=new BYTE[m_nRows*m_nCols*nBPB];
			m_pImage->ReadImg(0,0,m_nCols,m_nRows,
				(BYTE*)pBuffer,m_nCols,m_nRows,
				1,
				0,0,m_nCols,m_nRows,
				0,0);
			for(int i=0;i<m_nRows*m_nCols;i++)
			{
				pZ[i]=pBuffer[i];
			}
			delete [] pBuffer;
			pBuffer=NULL;
		}
		break;
	case Pixel_Int16:
		{
			BYTE* pBuffer=new BYTE[m_nRows*m_nCols*nBPB];
			m_pImage->ReadImg(0,0,m_nCols,m_nRows,
				(BYTE*)pBuffer,m_nCols,m_nRows,
				1,
				0,0,m_nCols,m_nRows,
				0,0);
			for(int i=0;i<m_nRows*m_nCols;i++)
			{
				pZ[i]=((unsigned short*)pBuffer)[i];
			}
			delete [] pBuffer;
			pBuffer=NULL;
		}
		break;
	case Pixel_SInt16:
		{
			BYTE* pBuffer=new BYTE[m_nRows*m_nCols*nBPB];
			m_pImage->ReadImg(0,0,m_nCols,m_nRows,
				(BYTE*)pBuffer,m_nCols,m_nRows,
				1,
				0,0,m_nCols,m_nRows,
				0,0);
			for(int i=0;i<m_nRows*m_nCols;i++)
			{
				pZ[i]=((short*)pBuffer)[i];
			}
			delete [] pBuffer;
			pBuffer=NULL;
		}
		break;
	case Pixel_Int32:
		{
			BYTE* pBuffer=new BYTE[m_nRows*m_nCols*nBPB];
			m_pImage->ReadImg(0,0,m_nCols,m_nRows,
				(BYTE*)pBuffer,m_nCols,m_nRows,
				1,
				0,0,m_nCols,m_nRows,
				0,0);
			for(int i=0;i<m_nRows*m_nCols;i++)
			{
				pZ[i]=((unsigned int*)pBuffer)[i];
			}
			delete [] pBuffer;
			pBuffer=NULL;
		}
		break;
	case Pixel_SInt32:
		{
			BYTE* pBuffer=new BYTE[m_nRows*m_nCols*nBPB];
			m_pImage->ReadImg(0,0,m_nCols,m_nRows,
				(BYTE*)pBuffer,m_nCols,m_nRows,
				1,
				0,0,m_nCols,m_nRows,
				0,0);
			for(int i=0;i<m_nRows*m_nCols;i++)
			{
				pZ[i]=((int*)pBuffer)[i];
			}
			delete [] pBuffer;
			pBuffer=NULL;
		}
		break;
	case Pixel_Float:
		{
			BYTE* pBuffer=new BYTE[m_nRows*m_nCols*nBPB];
			m_pImage->ReadImg(0,0,m_nCols,m_nRows,
				(BYTE*)pBuffer,m_nCols,m_nRows,
				1,
				0,0,m_nCols,m_nRows,
				0,0);
			for(int i=0;i<m_nRows*m_nCols;i++)
			{
				pZ[i]=((float*)pBuffer)[i];
			}
			delete [] pBuffer;
			pBuffer=NULL;
		}
		break;
	case Pixel_Double:
		m_pImage->ReadImg(0,0,m_nCols,m_nRows,
			(BYTE*)pZ,m_nCols,m_nRows,
			1,
			0,0,m_nCols,m_nRows,
			0,0);
		break;
	}

	for(int i=0;i<m_nRows*m_nCols;i++)
	{
		if(pZ[i]==DBL_MAX)
		{
			pZ[i]=INVALID_ALTITUDE;
		}
		else
		{
			pZ[i]+=m_lfAltitudeOffset;
		}
	}

	return S_OK;
}

HRESULT CTiffDEM::IsSupported(BSTR bstrPathName, UINT accMode)
{
	//读取数据
	if(accMode&modeWrite||accMode&modeCreate)
	{
		return S_FALSE;
	}

	CString strPathName=CString(bstrPathName);
	CString strExt=strPathName.Right(strPathName.GetLength()-strPathName.ReverseFind('.')-1);
	if(strExt.CompareNoCase(_T("tif"))==0||strExt.CompareNoCase(_T("tiff"))==0)
	{
		return S_OK;
	}

	return S_FALSE;
}
