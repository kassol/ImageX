#include "StdAfx.h"
#include "FlatDEM.h"

#import "ImageX.tlb" no_namespace named_guids



HRESULT CFlatDEM::Open(BSTR bstrPathName, double lfAltitudeOffset, UINT accMode)
{
	return S_FALSE;
}

HRESULT CFlatDEM::Create(BSTR bstrPathName, BSTR bstrFormat, UINT accMode, int nRows, int nCols, double LBX, double LBY, double XCellSize, double YCellSize)
{
	CString strPathName=CString(bstrPathName);
	m_strDEMPathName=strPathName;

	m_nRows=nRows;
	m_nCols=nCols;
	m_X0=LBX;
	m_Y0=LBY;
	m_XCellSize=XCellSize;
	m_YCellSize=YCellSize;

	/*//构造DEM栅格影像
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
		
		return S_FALSE;
	}

	m_strDemImage=strPathName.Left(strPathName.ReverseFind('.')-1)+"~~.hdr";
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

		return S_FALSE;
	}*/

	return S_OK;
}

HRESULT CFlatDEM::Close()
{
	/*if(m_pImage!=NULL)
	{
		m_pImage->Close();
		m_pImage->Release();
		m_pImage=NULL;
	}
	DeleteFile(m_strDemImage);
	DeleteFile(m_strDemImage.Left(m_strDemImage.ReverseFind('.'))+".img");*/

	return S_OK;
}

HRESULT CFlatDEM::GetSupExts(BYTE* lpszExts, UINT accMode)
{
	strcpy((char*)lpszExts,"");

	return S_FALSE;
}

HRESULT CFlatDEM::GetSupFormats(BYTE* lpszFormats, UINT accMode)
{
	strcpy((char*)lpszFormats,"");

	return S_FALSE;
}

HRESULT CFlatDEM::GetIImage(IImage** ppIImage)
{
	*ppIImage=m_pImage;

	return S_OK;
}

HRESULT CFlatDEM::GetVertex(double* pX, double* pY, double* pZ, int* pVertexNum)
{
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
	double X0=m_X0;
	double Y0=m_Y0;
	double CellSize=m_XCellSize;
	*pVertexNum=m_nRows*m_nCols;
	//获取DEM格网点
	for(int i=0;i<m_nRows;i++)
	{
		double* pXIndex=pX+i*m_nCols;
		double* pYIndex=pY+i*m_nCols;
		double* pZIndex=pZ+i*m_nCols;

		double X=X0;
		double Y=Y0+i*CellSize;
		double Z=m_AveAltitude;

		for(int j=0;j<m_nCols;j++)
		{
			pXIndex[j]=X;
			pYIndex[j]=Y;
			pZIndex[j]=Z;

			X+=CellSize;
		}
	}

	return S_OK;
}

HRESULT CFlatDEM::GetTriangle(int nTriIndex, double* pX, double* pY, double* pZ)
{
	return CBaseDEM::GetTriangleB(nTriIndex,pX,pY,pZ)==TRUE?S_OK:S_FALSE;
}

HRESULT CFlatDEM::GetTriangleNum(int* pTriangleNum)
{
	*pTriangleNum=CBaseDEM::GetTriangleNum();

	return S_OK;
}

HRESULT CFlatDEM::ConstrustTIN()
{
	//获取DEM起点
	double X0=m_X0;
	double Y0=m_Y0;
	double CellSize=m_XCellSize;
	//获取DEM格网点
	double* pX=new double[m_nRows*m_nCols];
	double* pY=new double[m_nRows*m_nCols];
	double* pZ=new double[m_nRows*m_nCols];

	for(int i=0;i<m_nRows;i++)
	{
		double* pXIndex=pX+i*m_nCols;
		double* pYIndex=pY+i*m_nCols;
		double* pZIndex=pZ+i*m_nCols;

		double X=X0;
		double Y=Y0+i*CellSize;
		double Z=m_AveAltitude;

		for(int j=0;j<m_nCols;j++)
		{
			pXIndex[j]=X;
			pYIndex[j]=Y;
			pZIndex[j]=Z;

			X+=CellSize;
		}
	}

	//构造三角网
	CBaseDEM::ContrustTIN(pX,pY,pZ,m_nRows*m_nCols);

	delete [] pX; pX=NULL;
	delete [] pY; pY=NULL;
	delete [] pZ; pZ=NULL;

	return S_FALSE;
}

HRESULT CFlatDEM::GetAverageAltitude(double* pZ)
{
	*pZ=m_AveAltitude;

	return S_OK;
}

HRESULT CFlatDEM::GetAltitude(double X, double Y, double* pZ, UINT uResampleMethod)
{
	*pZ=m_AveAltitude;

	return S_OK;
}

HRESULT CFlatDEM::SetFlatAltitude(double Z)
{
	m_AveAltitude=Z;
	m_MaxAltitude=Z;
	m_MinAltitude=Z;

	return S_OK;
}

HRESULT CFlatDEM::GetTIN(DWORD ppTriangulateio)
{
	return CBaseDEM::GetTINB(ppTriangulateio)==TRUE?S_OK:S_FALSE;
}

HRESULT CFlatDEM::CreateFlatDEM(int nRows, int nCols, double LBX, double LBY, double Altitude, double CellSize)
{
	m_nRows=nRows;
	m_nCols=nCols;
	m_X0=LBX;
	m_Y0=LBY;
	m_XCellSize=CellSize;
	m_YCellSize=CellSize;
	m_AveAltitude=Altitude;
	m_MaxAltitude=Altitude;
	m_MinAltitude=Altitude;

	return S_OK;
}

HRESULT CFlatDEM::SetRange(double LBX,double LBY,double RTX,double RTY,double CellSize)
{
	m_XCellSize=CellSize;
	m_YCellSize=CellSize;
	m_nRows=(int)((RTY-LBY+m_YCellSize-1)/m_YCellSize);
	m_nCols=(int)((RTX-LBX+m_XCellSize-1)/m_XCellSize);

	m_X0=LBX;
	m_Y0=LBY;

	return S_OK;
}

HRESULT CFlatDEM::SetCellSize(double CellSize)
{
	double RTX=m_X0+m_XCellSize*m_nCols;
	double RTY=m_Y0+m_YCellSize*m_nRows;

	m_XCellSize=CellSize;
	m_YCellSize=CellSize;

	m_nRows=(int)((RTY-m_Y0)/m_YCellSize+0.5);
	m_nCols=(int)((RTX-m_X0)/m_XCellSize+0.5);

	return S_OK;
}

HRESULT CFlatDEM::GetRange(double* pLBX, double* pLBY, double* pRTX, double* pRTY)
{
	*pLBX=m_X0;
	*pLBY=m_Y0;
	*pRTX=m_X0+m_XCellSize*m_nCols;
	*pRTY=m_Y0+m_YCellSize*m_nRows;

	return S_OK;
}

HRESULT CFlatDEM::GetCellSize(double* pXCellSize, double* pYCellSize)
{
	*pXCellSize=m_XCellSize;
	*pYCellSize=m_YCellSize;

	return S_OK;
}

HRESULT CFlatDEM::GetMaxAltitude(double* pZ)
{
	*pZ=m_MaxAltitude;

	return S_OK;
}

HRESULT CFlatDEM::GetMinAltitude(double* pZ)
{
	*pZ=m_MinAltitude;

	return S_OK;
}

HRESULT CFlatDEM::GetType(UINT* pType)
{
	*pType=DT_GRID;

	return S_OK;
}

HRESULT CFlatDEM::GetRows(int* pRows)
{
	*pRows=m_nRows;

	return S_OK;
}

HRESULT CFlatDEM::GetCols(int* pCols)
{
	*pCols=m_nCols;

	return S_OK;
}

HRESULT CFlatDEM::GetStartPos(double* pX0, double* pY0)
{
	*pX0=m_X0;
	*pY0=m_Y0;

	return S_OK;
}

HRESULT CFlatDEM::GetAltitudeValues(double* pZ)
{
	for(int i=0;i<m_nRows*m_nCols;i++)
	{
		pZ[i]=m_AveAltitude;
	}

	return S_OK;
}

HRESULT CFlatDEM::IsSupported(BSTR bstrPathName, UINT accMode)
{
	return S_FALSE;
}

