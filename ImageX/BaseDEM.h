// BaseDEM.h: interface for the CBaseDEM class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BASEDEM_H__0DD19C22_30FF_4C29_BD57_91AFC39D03D7__INCLUDED_)
#define AFX_BASEDEM_H__0DD19C22_30FF_4C29_BD57_91AFC39D03D7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Tin.h"
#include "RealRgn.h"


interface IImage;


//#define INVALID_ALTITUDE	-99999.9
class CBaseDEM  
{
public:
	BOOL TIN2DEM(CString strDEMFile, double LBX, double LBY, double RTX, double RTY, double lfCellSize);
	CBaseDEM();
	virtual ~CBaseDEM();

	virtual HRESULT GetCellSize(double* pXCellSize, double* pYCellSize) = 0;
	virtual HRESULT GetRange(double* pLBX, double* pLBY, double* pRTX, double* pRTY) = 0;
	virtual HRESULT GetTIN(DWORD ppTriangulateio) = 0;
	virtual HRESULT Close(void) = 0;
	HRESULT GetSupExts(BYTE* lpszExts, UINT accMode);
	virtual HRESULT GetSupFormats(BYTE* lpszFormats, UINT accMode) = 0;
	virtual HRESULT GetIImage(IImage** ppIImage) = 0;
	virtual HRESULT GetVertex(double* pX, double* pY, double* pZ, int* pVertexNum) = 0;
	virtual HRESULT GetTriangle(int nTriIndex, double* pX, double* pY, double* pZ) = 0;
	virtual HRESULT GetTriangleNum(int* pTriangleNum) = 0;
	virtual HRESULT ConstrustTIN(void) = 0;
	virtual HRESULT GetAverageAltitude(double* pZ) = 0;
	virtual HRESULT GetAltitude(double X, double Y, double* pZ, UINT uResampleMethod) = 0;
	virtual HRESULT Create(BSTR bstrPathName, BSTR bstrFormat, UINT accMode, int nRows, int nCols, double LBX, double LBY, double XCellSize, double YCellSize) = 0;
	virtual HRESULT Open(BSTR bstrPathName, double lfAltitudeOffset, UINT accMode) = 0;
	virtual HRESULT GetMaxAltitude(double* pZ) = 0;
	virtual HRESULT GetMinAltitude(double* pZ) = 0;
	virtual HRESULT GetType(UINT* pType) = 0;
	virtual HRESULT GetRows(int* pRows) = 0;
	virtual HRESULT GetCols(int* pCols) = 0;
	virtual HRESULT GetStartPos(double* pX0, double* pY0) = 0;
	virtual HRESULT GetAltitudeValues(double* pZ) = 0;
	virtual HRESULT IsSupported(BSTR bstrPathName, UINT accMode) = 0;


	virtual HRESULT SetRange(double LBX,double LBY,double RTX,double RTY);
	virtual HRESULT CreateGCPDEM(BSTR bstrGcpFile);
	virtual HRESULT ExportTin(BSTR bstrTinFile);
	virtual HRESULT SetBufferSize(double lfBufferSize);
	virtual HRESULT GetBufferSize(double* pBufferSize);
	virtual HRESULT TIN2DEM(BSTR bstrDEMFile,double LBX,double LBY,double RTX,double RTY,double lfCellSize);
	virtual HRESULT CreateVectorDEM(BSTR bstrVectorFile);
	virtual HRESULT CreateFeatureDEM(BSTR bstrRasterDEMFile,BSTR bstrFeatureFile,double lfBufferSize);
	virtual HRESULT SetCellSize(double CellSize);
	virtual HRESULT SetFlatAltitude(double Z);
	virtual HRESULT CreateFlatDEM(int nRows, int nCols, double LBX, double LBY, double Altitude, double CellSize);

protected:
	HRESULT GetAltitudeRaster(double X,double Y,double* pZ, UINT uResampleMethod);
	virtual BOOL ResetCache(float x,float y);
	BOOL LineBuffer(double X0,double Y0,double X1,double Y1,double lfBufferSize,CRealRgn* pRgn);
	BOOL Intersect1(double X1,double Y1,double X2,double Y2,double X3,double Y3,double X4,double Y4,double& X,double& Y);
	BOOL GetTINB(DWORD ppTriangulateio);
	BOOL GetTriangleB(int nTriIndex,double* pX,double* pY,double* pZ);
	int GetTriangleNum();
	void DestoryTIN();
	void ContrustTIN(double* pX,double* pY,double* pZ,int nVertexNum);
	void ContrustTIN2(CArray<double,double>& X,CArray<double,double>& Y,CArray<double,double>& Z);
	void ContrustTIN3();
protected:
	//DEM基本属性
	double m_X0,m_Y0,m_XCellSize,m_YCellSize,m_Kappa;
	int m_nRows,m_nCols;
	double m_AveAltitude,m_MaxAltitude,m_MinAltitude;
	 IImage* m_pImage;//DEM影像
	CString m_strDemImage;//DEM影像名称
	triangulateio in,mid,vorout;
	double m_lfAltitudeOffset;
	CString m_strDEMPathName;
	//缓冲池参数，加速GetAltitude(X,Y,Z,1);
	int m_nCacheRow0,m_nCacheCol0;//[0,1)
	int m_nCacheRow1,m_nCacheCol1;//[0,1)
	BYTE *m_pCacheBuffer;
	int m_nBandNum;
	int m_nBPB,m_nBPP;
	UINT m_nDataType;
	int m_nCacheRows,m_nCacheCols;
	int CACHE_SIZE_ROW,CACHE_SIZE_COL;
};

#endif // !defined(AFX_BASEDEM_H__0DD19C22_30FF_4C29_BD57_91AFC39D03D7__INCLUDED_)
