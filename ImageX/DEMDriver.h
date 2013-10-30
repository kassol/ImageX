// DEMDriver.h : Declaration of the CDEMDriver

#pragma once
#include "resource.h"       // main symbols



#include "ImageX_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;


// CDEMDriver

class CBaseDEM;

class ATL_NO_VTABLE CDEMDriver :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CDEMDriver, &CLSID_DEMDriver>,
	public IDispatchImpl<IDEM, &IID_IDEM, &LIBID_ImageXLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CDEMDriver()
	{
		m_pBaseDEM = NULL;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_DEMDRIVER)


BEGIN_COM_MAP(CDEMDriver)
	COM_INTERFACE_ENTRY(IDEM)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:

	STDMETHOD(GetCellSize)(DOUBLE* pXCellSize, DOUBLE* pYCellSize);
	STDMETHOD(GetRange)(DOUBLE* pLBX, DOUBLE* pLBY, DOUBLE* pRTX, DOUBLE* pRTY);
	STDMETHOD(GetTIN)(DWORD ppTriangulateio);
	STDMETHOD(Close)(void);
	STDMETHOD(GetSupExts)(BYTE* lpszExts, UINT accMode);
	STDMETHOD(GetSupFormats)(BYTE* lpszFormats, UINT accMode);
	STDMETHOD(GetIImage)(IImage** ppIImage);
	STDMETHOD(GetVertex)(DOUBLE* pX, DOUBLE* pY, DOUBLE* pZ, int* pVertexNum);
	STDMETHOD(GetTriangle)(int nTriIndex, DOUBLE* pX, DOUBLE* pY, DOUBLE* pZ);
	STDMETHOD(GetTriangleNum)(int* pTriangleNum);
	STDMETHOD(ConstrustTIN)(void);
	STDMETHOD(GetAverageAltitude)(DOUBLE* pZ);
	STDMETHOD(GetAltitude)(DOUBLE X, DOUBLE Y, DOUBLE* pZ, UINT uResampleMethod);
	STDMETHOD(Create)(BSTR bstrPathName, BSTR bstrFormat, UINT accMode, int nRows, int nCols, DOUBLE LBX, DOUBLE LBY, DOUBLE XCellSize, DOUBLE YCellSize);
	STDMETHOD(Open)(BSTR bstrPathName, DOUBLE lfAltitudeOffset, UINT accMode);
	STDMETHOD(GetMaxAltitude)(DOUBLE* pZ);
	STDMETHOD(GetMinAltitude)(DOUBLE* pZ);
	STDMETHOD(GetType)(UINT* pType);
	STDMETHOD(GetRows)(int* pRows);
	STDMETHOD(GetCols)(int* pCols);
	STDMETHOD(GetStartPos)(DOUBLE* pX0, DOUBLE* pY0);
	STDMETHOD(GetAltitudeValues)(DOUBLE* pZ);
	STDMETHOD(IsSupported)(BSTR bstrPathName, UINT accMode);

private:
	CBaseDEM* m_pBaseDEM;
public:
	STDMETHOD(ExportTin)(BSTR bstrTinFile);
	STDMETHOD(TIN2DEM)(BSTR bstrDEMFile, DOUBLE LBX, DOUBLE LBY, DOUBLE RTX, DOUBLE RTY, DOUBLE lfCellSize);
	STDMETHOD(CreateFeatureDEM)(BSTR bstrRasterDEMFile, BSTR bstrFeatureFile, DOUBLE lfBufferSize);
	STDMETHOD(SetRange)(DOUBLE LBX, DOUBLE LBY, DOUBLE RTX, DOUBLE RTY, DOUBLE CellSize);
	STDMETHOD(SetCellSize)(DOUBLE CellSize);
	STDMETHOD(SetFlatAltitude)(DOUBLE Z);
	STDMETHOD(CreateFlatDEM)(int nRows , int nCols, DOUBLE LBX, DOUBLE LBY, DOUBLE Altitude, DOUBLE CellSize);
	STDMETHOD(CreateGCPDEM)(BSTR bstrGcpFile);
	STDMETHOD(SetBufferSize)(DOUBLE lfBufferSize);
	STDMETHOD(GetBufferSize)(DOUBLE* pBufferSize);
	STDMETHOD(CreateVectorDEM)(BSTR bstrVectorFile);
};

OBJECT_ENTRY_AUTO(__uuidof(DEMDriver), CDEMDriver)
