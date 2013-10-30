#pragma once
#include "BaseDEM.h"


class CArcGridDEM :
	public CBaseDEM
{
public:
	CArcGridDEM(void)
	{
		m_strDEMPathName="";
	}

public:
	HRESULT GetCellSize(double* pXCellSize, double* pYCellSize);
	HRESULT GetRange(double* pLBX, double* pLBY, double* pRTX, double* pRTY);
	HRESULT GetTIN(DWORD ppTriangulateio);
	HRESULT Close(void);
	HRESULT GetSupExts(BYTE* lpszExts, UINT accMode);
	HRESULT GetSupFormats(BYTE* lpszFormats, UINT accMode);
	HRESULT GetIImage(IImage** ppIImage);
	HRESULT GetVertex(double* pX, double* pY, double* pZ, int* pVertexNum);
	HRESULT GetTriangle(int nTriIndex, double* pX, double* pY, double* pZ);
	HRESULT GetTriangleNum(int* pTriangleNum);
	HRESULT ConstrustTIN(void);
	HRESULT GetAverageAltitude(double* pZ);
	HRESULT GetAltitude(double X, double Y, double* pZ, UINT uResampleMethod);
	HRESULT Create(BSTR bstrPathName, BSTR bstrFormat, UINT accMode, int nRows, int nCols, double LBX, double LBY, double XCellSize, double YCellSize);
	HRESULT Open(BSTR bstrPathName, double lfAltitudeOffset, UINT accMode);
	HRESULT GetMaxAltitude(double* pZ);
	HRESULT GetMinAltitude(double* pZ);
	HRESULT GetType(UINT* pType);
	HRESULT GetRows(int* pRows);
	HRESULT GetCols(int* pCols);
	HRESULT GetStartPos(double* pX0, double* pY0);
	HRESULT GetAltitudeValues(double* pZ);
	HRESULT IsSupported(BSTR bstrPathName, UINT accMode);
};

