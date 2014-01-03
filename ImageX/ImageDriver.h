// ImageDriver.h : Declaration of the CImageDriver

#pragma once
#include "resource.h"       // main symbols
#include "ImageX_i.h"
#include "BaseRaster.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;


// CImageDriver

class ATL_NO_VTABLE CImageDriver :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CImageDriver, &CLSID_ImageDriverX>,
	public IDispatchImpl<IImageX, &IID_IImageX, &LIBID_ImageXLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CImageDriver()
		:pRaster(NULL)
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_IMAGEDRIVER)


BEGIN_COM_MAP(CImageDriver)
	COM_INTERFACE_ENTRY(IImageX)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
		if(pRaster != NULL)
		{
			delete pRaster;
			pRaster = NULL;
		}
	}

public:
	STDMETHOD(Open)(BSTR bstrPathName, UINT uMode);
	STDMETHOD(CreateImg)(BSTR bstrFilePath, UINT uMode, int Cols, int Rows, UINT DataType, int nBandNum, UINT BandType, DOUBLE xStart, DOUBLE yStart, DOUBLE cellSize);
	STDMETHOD(Close)(void);
	STDMETHOD(IsGeoCoded)(void);
	STDMETHOD(GetBandFormat)(UINT* pBandFormat);
	STDMETHOD(GetBandNum)(int* pBandNum);
	STDMETHOD(GetRows)(int* pRows);
	STDMETHOD(GetCols)(int* pCols);
	STDMETHOD(GetDataType)(UINT* pDataType);
	STDMETHOD(GetByteOrder)(UINT* pByteOrder);
	STDMETHOD(GetScale)(FLOAT* pScale);
	STDMETHOD(SetScale)(FLOAT Scale);
	STDMETHOD(GetGrdInfo)(DOUBLE* xStart, DOUBLE* yStart, DOUBLE* cellSize);
	STDMETHOD(SetGrdInfo)(DOUBLE xStart, DOUBLE yStart, DOUBLE cellSize);
	STDMETHOD(HaveColorTable)(void);
	STDMETHOD(GetEntryNum)(int* pEntryNum);
	STDMETHOD(GetColorTable)(BYTE* pColorTable);
	STDMETHOD(SetColorTable)(BYTE* pColorTable, int nEntryNum);
	STDMETHOD(GetResampleMethod)(int* pResampleMethod);
	STDMETHOD(SetResampleMethod)(int nResampleMethod);
	STDMETHOD(GetScanSize)(FLOAT* pScanSize);
	STDMETHOD(SetScanSize)(FLOAT ScanSize);
	STDMETHOD(GetBPB)(int* pBPB);
	STDMETHOD(GetBPP)(int* pBPP);
	STDMETHOD(GetPathName)(BSTR* bstrPathName);
	STDMETHOD(GetPixel)(int nRows, int nCols, BYTE* pPixel);
	STDMETHOD(SetPixel)(int nRows, int nCols, BYTE* pPixel);
	STDMETHOD(GetGray)(int nRows, int nCols, int nBand, BYTE* gray);
	STDMETHOD(SetGray)(int nRows, int nCols, int nBand, BYTE* gray);
	STDMETHOD(GetPixelF)(FLOAT x, FLOAT y, BYTE* pPixel, UINT nResampleMethod);
	STDMETHOD(GetGrayF)(FLOAT x, FLOAT y, int nBand, BYTE* pGray, int nResampleMethod);
	STDMETHOD(ReadImg)(int nSrcLeft, int nSrcTop, int nSrcRight, int nSrcBottom, BYTE* pBuf, int nBufWid, int nBufHeight, int nBandNum, int nDestLeft, int nDestTop, int nDestRight, int nDestBottom, int nSrcSkip, int nDestSkip);
	STDMETHOD(WriteImg)(int nSrcLeft, int nSrcTop, int nSrcRight, int nSrcBottom, BYTE* pBuf, int nBufWid, int nBufHeight, int nBandNum, int nDestLeft, int nDestTop, int nDestRight, int nDestBottom, int nSrcSkip, int nDestSkip);
	STDMETHOD(SetProgressInterface)(IUnknown* pIUnknown);
	STDMETHOD(GetSupExts)(BYTE* lpszExts, UINT flags);
	STDMETHOD(Image2World)(FLOAT x, FLOAT y, DOUBLE* pX, DOUBLE* pY);
	STDMETHOD(World2Image)(DOUBLE X, DOUBLE Y, FLOAT* px, FLOAT* py);
	STDMETHOD(GetDefaultBand)(int* nBandIndex);
	STDMETHOD(GetCamera)(BSTR* bstrCamera);
	STDMETHOD(SetCamera)(BSTR bstrCamera);
	STDMETHOD(GetSensorType)(int* pSensorType);
	STDMETHOD(SetSensorType)(int nSensorType);
	STDMETHOD(GetDPI)(FLOAT* pxDPI, FLOAT* pyDPI);
	STDMETHOD(SetDPI)(FLOAT xDPI, FLOAT yDPI);
	STDMETHOD(Tiff2JPG)(BSTR bstrTiffPath, BSTR bstrJPGPath);
	STDMETHOD(GetTiledSize)(int* nXBlockSize, int* nYBlockSize);

private:
	CBaseRaster* pRaster;
};

OBJECT_ENTRY_AUTO(__uuidof(ImageDriverX), CImageDriver)
