#pragma once
#include "basedem.h"


class CVectorDEM :
	public CBaseDEM
{
public:
	CVectorDEM(void)
	{
		m_strVectorFile="";
		m_lfBufferSize=15;
	}

public:
	HRESULT ExportTin(BSTR bstrTinFile);
	HRESULT SetBufferSize(double lfBufferSize);
	HRESULT GetBufferSize(double* pBufferSize);
	HRESULT TIN2DEM(BSTR bstrDEMFile,double LBX,double LBY,double RTX,double RTY,double lfCellSize);
	HRESULT SetRange(double LBX,double LBY,double RTX,double RTY);
	HRESULT CreateVectorDEM(BSTR bstrVectorFile);



	HRESULT GetCellSize(double* pXCellSize, double* pYCellSize);
	HRESULT GetRange(double* pLBX, double* pLBY, double* pRTX, double* pRTY);
	HRESULT GetTIN(DWORD ppTriangulateio);
	HRESULT Close(void);
	HRESULT GetSupExts(BYTE* lpszExts, UINT accMode);
	HRESULT GetSupFormats(BYTE* lpszFormats, UINT accMode);
	HRESULT GetIImage(IImageX** ppIImage);
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



private:
	CString m_strVectorFile;
	double m_X2,m_Y2;
	double m_lfBufferSize;//»º³åÇø´óÐ¡
};

