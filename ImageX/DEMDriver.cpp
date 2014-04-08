// DEMDriver.cpp : Implementation of CDEMDriver

#include "stdafx.h"
#include "DEMDriver.h"
#include "NSDTFDEM.h"
#include "TiffDEM.h"
#include "ArcGridDEM.h"
#include "BilDEM.h"
#include "VirtuozoDEM.h"


// CDEMDriver



STDMETHODIMP CDEMDriver::GetCellSize(DOUBLE* pXCellSize, DOUBLE* pYCellSize)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	if (m_pBaseDEM == NULL)
	{
		return S_FALSE;
	}
	m_pBaseDEM->GetCellSize(pXCellSize, pYCellSize);
	return S_OK;
}


STDMETHODIMP CDEMDriver::GetRange(DOUBLE* pLBX, DOUBLE* pLBY, DOUBLE* pRTX, DOUBLE* pRTY)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	if (m_pBaseDEM == NULL)
	{
		return S_FALSE;
	}
	m_pBaseDEM->GetRange(pLBX, pLBY, pRTX, pRTY);
	return S_OK;
}


STDMETHODIMP CDEMDriver::GetTIN(DWORD ppTriangulateio)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	if (m_pBaseDEM == NULL)
	{
		return S_FALSE;
	}
	return m_pBaseDEM->GetTIN(ppTriangulateio);
}


STDMETHODIMP CDEMDriver::Close(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	if (m_pBaseDEM == NULL)
	{
		return S_FALSE;
	}
	m_pBaseDEM->Close();
	delete m_pBaseDEM;
	m_pBaseDEM = NULL;
	return S_OK;
}


STDMETHODIMP CDEMDriver::GetSupExts(BYTE* lpszExts, UINT accMode)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	if (m_pBaseDEM == NULL)
	{
		return S_FALSE;
	}
	m_pBaseDEM->GetSupExts(lpszExts, accMode);
	return S_OK;
}


STDMETHODIMP CDEMDriver::GetSupFormats(BYTE* lpszFormats, UINT accMode)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	if (m_pBaseDEM == NULL)
	{
		return S_FALSE;
	}
	m_pBaseDEM->GetSupFormats(lpszFormats, accMode);
	return S_OK;
}


STDMETHODIMP CDEMDriver::GetIImage(IImageX** ppIImage)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	if (m_pBaseDEM == NULL)
	{
		return S_FALSE;
	}
	m_pBaseDEM->GetIImage(ppIImage);
	return S_OK;
}


STDMETHODIMP CDEMDriver::GetVertex(DOUBLE* pX, DOUBLE* pY, DOUBLE* pZ, int* pVertexNum)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	if (m_pBaseDEM == NULL)
	{
		return S_FALSE;
	}
	m_pBaseDEM->GetVertex(pX, pY, pZ, pVertexNum);
	return S_OK;
}


STDMETHODIMP CDEMDriver::GetTriangle(int nTriIndex, DOUBLE* pX, DOUBLE* pY, DOUBLE* pZ)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	if (m_pBaseDEM == NULL)
	{
		return S_FALSE;
	}
	return m_pBaseDEM->GetTriangle(nTriIndex, pX, pY, pZ);
}


STDMETHODIMP CDEMDriver::GetTriangleNum(int* pTriangleNum)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	if (m_pBaseDEM == NULL)
	{
		return S_FALSE;
	}
	m_pBaseDEM->GetTriangleNum(pTriangleNum);
	return S_OK;
}


STDMETHODIMP CDEMDriver::ConstrustTIN(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	if (m_pBaseDEM == NULL)
	{
		return S_FALSE;
	}
	m_pBaseDEM->ConstrustTIN();
	return S_OK;
}



STDMETHODIMP CDEMDriver::GetAverageAltitude(DOUBLE* pZ)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	if (m_pBaseDEM == NULL)
	{
		return S_FALSE;
	}
	m_pBaseDEM->GetAverageAltitude(pZ);
	return S_OK;
}


STDMETHODIMP CDEMDriver::GetAltitude(DOUBLE X, DOUBLE Y, DOUBLE* pZ, UINT uResampleMethod)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	if (m_pBaseDEM == NULL)
	{
		return S_FALSE;
	}
	m_pBaseDEM->GetAltitude(X, Y, pZ, uResampleMethod);
	return S_OK;
}


STDMETHODIMP CDEMDriver::Create(BSTR bstrPathName, BSTR bstrFormat, UINT accMode, int nRows, int nCols, DOUBLE LBX, DOUBLE LBY, DOUBLE XCellSize, DOUBLE YCellSize)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	if (m_pBaseDEM == NULL)
	{
		return S_FALSE;
	}
	m_pBaseDEM->Create(bstrPathName, bstrFormat, accMode, nRows, nCols, LBX, LBY, XCellSize, YCellSize);
	return S_OK;
}


STDMETHODIMP CDEMDriver::Open(BSTR bstrPathName, DOUBLE lfAltitudeOffset, UINT accMode)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	CString strPathName=CString(bstrPathName);
	CString strExt=strPathName.Right(strPathName.GetLength()-strPathName.ReverseFind('.')-1);
	if (strExt.CompareNoCase(_T("dem")) == 0)
	{
		FILE* fp=fopen(strPathName,"rt");
		if(fp==NULL)
		{
			return S_FALSE;
		}
		char NSDTFHEADER[20];
		fscanf(fp,"%s",NSDTFHEADER);
		fclose(fp);
		CString temp;
		temp.Format("%s", NSDTFHEADER);
		if (temp.CompareNoCase(_T("NSDTF-DEM")) == 0)
		{
			m_pBaseDEM = new CNSDTFDEM();
		}
		else
		{
			m_pBaseDEM = new CVirtuozoDEM();
		}
	}
	else if (strExt.CompareNoCase(_T("tif"))==0 || strExt.CompareNoCase(_T("tiff"))==0)
	{
		m_pBaseDEM = new CTiffDEM();
	}
	else if (strExt.CompareNoCase(_T("grd"))==0 ||strExt.CompareNoCase(_T("asc"))==0 || strExt.Compare(_T("egx"))==0)
	{
		m_pBaseDEM = new CArcGridDEM();
	}
	else if (strExt.Compare(_T("bil")) == 0)
	{
		m_pBaseDEM = new CBilDEM();
	}
	else
	{
		return S_FALSE;
	}
	m_pBaseDEM->Open(bstrPathName, lfAltitudeOffset, accMode);
	return S_OK;
}


STDMETHODIMP CDEMDriver::GetMaxAltitude(DOUBLE* pZ)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	if (m_pBaseDEM == NULL)
	{
		return S_FALSE;
	}
	m_pBaseDEM->GetMaxAltitude(pZ);
	return S_OK;
}


STDMETHODIMP CDEMDriver::GetMinAltitude(DOUBLE* pZ)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	if (m_pBaseDEM == NULL)
	{
		return S_FALSE;
	}
	m_pBaseDEM->GetMinAltitude(pZ);
	return S_OK;
}


STDMETHODIMP CDEMDriver::GetType(UINT* pType)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	if (m_pBaseDEM == NULL)
	{
		return S_FALSE;
	}
	m_pBaseDEM->GetType(pType);
	return S_OK;
}


STDMETHODIMP CDEMDriver::GetRows(int* pRows)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	if (m_pBaseDEM == NULL)
	{
		return S_FALSE;
	}
	m_pBaseDEM->GetRows(pRows);
	return S_OK;
}


STDMETHODIMP CDEMDriver::GetCols(int* pCols)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	if (m_pBaseDEM == NULL)
	{
		return S_FALSE;
	}
	m_pBaseDEM->GetCols(pCols);
	return S_OK;
}


STDMETHODIMP CDEMDriver::GetStartPos(DOUBLE* pX0, DOUBLE* pY0)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	if (m_pBaseDEM == NULL)
	{
		return S_FALSE;
	}
	m_pBaseDEM->GetStartPos(pX0, pY0);
	return S_OK;
}


STDMETHODIMP CDEMDriver::GetAltitudeValues(DOUBLE* pZ)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	if (m_pBaseDEM == NULL)
	{
		return S_FALSE;
	}
	m_pBaseDEM->GetAltitudeValues(pZ);
	return S_OK;
}


STDMETHODIMP CDEMDriver::IsSupported(BSTR bstrPathName, UINT accMode)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	if (m_pBaseDEM == NULL)
	{
		return S_FALSE;
	}
	return m_pBaseDEM->IsSupported(bstrPathName, accMode);
	
}


STDMETHODIMP CDEMDriver::ExportTin(BSTR bstrTinFile)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here

	return S_FALSE;
}


STDMETHODIMP CDEMDriver::TIN2DEM(BSTR bstrDEMFile, DOUBLE LBX, DOUBLE LBY, DOUBLE RTX, DOUBLE RTY, DOUBLE lfCellSize)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here

	return S_FALSE;
}


STDMETHODIMP CDEMDriver::CreateFeatureDEM(BSTR bstrRasterDEMFile, BSTR bstrFeatureFile, DOUBLE lfBufferSize)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here

	return S_FALSE;
}


STDMETHODIMP CDEMDriver::SetRange(DOUBLE LBX, DOUBLE LBY, DOUBLE RTX, DOUBLE RTY, DOUBLE CellSize)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here

	return S_FALSE;
}


STDMETHODIMP CDEMDriver::SetCellSize(DOUBLE CellSize)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here

	return S_FALSE;
}


STDMETHODIMP CDEMDriver::SetFlatAltitude(DOUBLE Z)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here

	return S_FALSE;
}


STDMETHODIMP CDEMDriver::CreateFlatDEM(int nRows , int nCols, DOUBLE LBX, DOUBLE LBY, DOUBLE Altitude, DOUBLE CellSize)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here

	return S_FALSE;
}


STDMETHODIMP CDEMDriver::CreateGCPDEM(BSTR bstrGcpFile)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here

	return S_FALSE;
}


STDMETHODIMP CDEMDriver::SetBufferSize(DOUBLE lfBufferSize)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here

	return S_FALSE;
}


STDMETHODIMP CDEMDriver::GetBufferSize(DOUBLE* pBufferSize)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here

	return S_FALSE;
}


STDMETHODIMP CDEMDriver::CreateVectorDEM(BSTR bstrVectorFile)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here

	return S_FALSE;
}
