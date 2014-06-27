// ImageDriver.cpp : Implementation of CImageDriver

#include "stdafx.h"
#include "ImageDriver.h"
#include <comutil.h>
#include <fstream>
#include <io.h>
#include <string>
#include "TiffRaster.h"
#include "JPEGRaster.h"
#include "SatRaster.h"
#include "AdsRaster.h"
using namespace std;

STDMETHODIMP CImageDriver::Open(BSTR bstrPathName, UINT uMode)
{
	CString strPathName;
	strPathName = bstrPathName;

	if (_access(strPathName, 0) == -1)
	{
		return S_FALSE;
	}

	CString strExt = strPathName.Right(strPathName.GetLength()-strPathName.ReverseFind('.')-1);

	if (strExt.CompareNoCase("tif") == 0 || strExt.CompareNoCase("tiff") == 0)
	{
		pRaster = new CTiffRaster();
	}
	else if (strExt.CompareNoCase("jpg") == 0 || strExt.CompareNoCase("jpeg") == 0)
	{
		pRaster = new CJPEGRaster();
	}
	else if (strExt.CompareNoCase("sat") == 0)
	{
		pRaster = new CSatRaster();
	}
	else if (strExt.CompareNoCase("sup") == 0)
	{	
		ifstream infile;
		infile.open(strPathName.GetBuffer(0), ios::in);
		if (!infile)
		{
			return S_FALSE;
		}

		char ch[500];
		memset(ch, 0, 500);
		infile.getline(ch, 500);
		infile.getline(ch, 500);

		int nPyramid = 0;
		infile>>ch;
		infile>>nPyramid;
		infile>>ch;

		CString strAdaFilePath = ch;

		strAdaFilePath = strAdaFilePath.Right(strAdaFilePath.GetLength() - 1);
		strAdaFilePath = strAdaFilePath.Left(strAdaFilePath.GetLength() - 1);

		while(1)
		{
			int nIndex = strAdaFilePath.ReverseFind('/');
			if (nIndex == -1)
			{
				break;
			}

			strAdaFilePath = strAdaFilePath.Left(nIndex) + "\\" + strAdaFilePath.Right(strAdaFilePath.GetLength() - nIndex - 1);

		}

		if (_access(strAdaFilePath, 0) == -1)
		{
			return S_FALSE;
		}

		pRaster = new CAdsRaster();
		return pRaster->Open(_bstr_t(strAdaFilePath), uMode);
	}
	else
	{
		pRaster = new CBaseRaster();
	}

	return pRaster->Open(bstrPathName, uMode);
}


STDMETHODIMP CImageDriver::CreateImg(BSTR bstrFilePath, UINT uMode, int Cols, int Rows, 
														UINT DataType, int nBandNum, UINT BandType, DOUBLE xStart, DOUBLE yStart, DOUBLE cellSize)
{
	CString strPathName;
	strPathName = bstrFilePath;
	CString strExt = strPathName.Right(strPathName.GetLength()-strPathName.ReverseFind('.')-1);

	if (strExt.CompareNoCase("tif") == 0 || strExt.CompareNoCase("tiff") == 0)
	{
		pRaster = new CTiffRaster();
	}
	else if (strExt.CompareNoCase("jpg") == 0 || strExt.CompareNoCase("jpeg") == 0)
	{
		pRaster = new CJPEGRaster();
	}
	else
	{
		pRaster = new CBaseRaster();
	}

	return pRaster->CreateImg(bstrFilePath, uMode, Cols, Rows, DataType, nBandNum, BandType, xStart, yStart, cellSize);
}


STDMETHODIMP CImageDriver::Close(void)
{
	if (pRaster != NULL)
	{
		pRaster->Close();
		delete pRaster;
		pRaster = NULL;
	}
	return S_OK;
}


STDMETHODIMP CImageDriver::IsGeoCoded(void)
{
	return pRaster->IsGeoCoded();
}


STDMETHODIMP CImageDriver::GetBandFormat(UINT* pBandFormat)
{
	return pRaster->GetBandFormat(pBandFormat);
}


STDMETHODIMP CImageDriver::GetBandNum(int* pBandNum)
{
	return pRaster->GetBandNum(pBandNum);
}


STDMETHODIMP CImageDriver::GetRows(int* pRows)
{
	return pRaster->GetRows(pRows);
}


STDMETHODIMP CImageDriver::GetCols(int* pCols)
{
	return pRaster->GetCols(pCols);
}


STDMETHODIMP CImageDriver::GetDataType(UINT* pDataType)
{
	return pRaster->GetDataType(pDataType);
}


STDMETHODIMP CImageDriver::GetByteOrder(UINT* pByteOrder)
{
	return pRaster->GetByteOrder(pByteOrder);
}


STDMETHODIMP CImageDriver::GetScale(FLOAT* pScale)
{
	return pRaster->GetScale(pScale);
}


STDMETHODIMP CImageDriver::SetScale(FLOAT Scale)
{
	return S_FALSE;
}


STDMETHODIMP CImageDriver::GetGrdInfo(DOUBLE* xStart, DOUBLE* yStart, DOUBLE* cellSize)
{
	return pRaster->GetGrdInfo(xStart, yStart, cellSize);
}

STDMETHODIMP CImageDriver::SetGrdInfo(DOUBLE xStart, DOUBLE yStart, DOUBLE cellSize)
{
	return pRaster->SetGrdInfo(xStart, yStart, cellSize);
}


STDMETHODIMP CImageDriver::HaveColorTable(void)
{
	return pRaster->HaveColorTable();
}


STDMETHODIMP CImageDriver::GetEntryNum(int* pEntryNum)
{
	return pRaster->GetEntryNum(pEntryNum);
}


STDMETHODIMP CImageDriver::GetColorTable(BYTE* pColorTable)
{
	return S_FALSE;
}


STDMETHODIMP CImageDriver::SetColorTable(BYTE* pColorTable, int nEntryNum)
{
	return S_FALSE;
}


STDMETHODIMP CImageDriver::GetResampleMethod(int* pResampleMethod)
{
	return pRaster->GetResampleMethod(pResampleMethod);
}


STDMETHODIMP CImageDriver::SetResampleMethod(int nResampleMethod)
{
	return pRaster->SetResampleMethod(nResampleMethod);
}


STDMETHODIMP CImageDriver::GetScanSize(FLOAT* pScanSize)
{
	return pRaster->GetScanSize(pScanSize);
}


STDMETHODIMP CImageDriver::SetScanSize(FLOAT ScanSize)
{
	return S_FALSE;
}


STDMETHODIMP CImageDriver::GetBPB(int* pBPB)
{
	return pRaster->GetBPB(pBPB);
}


STDMETHODIMP CImageDriver::GetBPP(int* pBPP)
{
	return pRaster->GetBPP(pBPP);
}


STDMETHODIMP CImageDriver::GetPathName(BSTR* bstrPathName)
{
	return pRaster->GetPathName(bstrPathName);
}


STDMETHODIMP CImageDriver::GetPixel(int nRows, int nCols, BYTE* pPixel)
{
	return pRaster->GetPixel(nRows, nCols, pPixel);
}


STDMETHODIMP CImageDriver::SetPixel(int nRows, int nCols, BYTE* pPixel)
{
	return pRaster->SetPixel(nRows, nCols, pPixel);
}


STDMETHODIMP CImageDriver::GetGray(int nRows, int nCols, int nBand, BYTE* gray)
{
	return pRaster->GetGray(nRows, nCols, nBand, gray);
}


STDMETHODIMP CImageDriver::SetGray(int nRows, int nCols, int nBand, BYTE* gray)
{
	return pRaster->SetGray(nRows, nCols, nBand, gray);
}


STDMETHODIMP CImageDriver::GetPixelF(FLOAT x, FLOAT y, BYTE* pPixel, UINT nResampleMethod)
{
	return pRaster->GetPixelF(x, y, pPixel, nResampleMethod);
}


STDMETHODIMP CImageDriver::GetGrayF(FLOAT x, FLOAT y, int nBand, BYTE* pGray, int nResampleMethod)
{
	return pRaster->GetGrayF(x, y, nBand, pGray, nResampleMethod);
}


STDMETHODIMP CImageDriver::ReadImg(int nSrcLeft, int nSrcTop, int nSrcRight, int nSrcBottom, 
									BYTE* pBuf, int nBufWid, int nBufHeight, int nBandNum, 
									int nDestLeft, int nDestTop, int nDestRight, int nDestBottom, 
									int nSrcSkip, int nDestSkip)
{
	return pRaster->ReadImg(nSrcLeft, nSrcTop, nSrcRight, nSrcBottom, pBuf, nBufWid, nBufHeight, nBandNum,
		 nDestLeft, nDestTop, nDestRight, nDestBottom, nSrcSkip, nDestSkip);
}


STDMETHODIMP CImageDriver::WriteImg(int nSrcLeft, int nSrcTop, int nSrcRight, int nSrcBottom, 
									BYTE* pBuf, int nBufWid, int nBufHeight, int nBandNum, 
									int nDestLeft, int nDestTop, int nDestRight, int nDestBottom, 
									int nSrcSkip, int nDestSkip)
{
	return pRaster->WriteImg(nSrcLeft, nSrcTop, nSrcRight, nSrcBottom, pBuf, nBufWid, nBufHeight, nBandNum, 
		nDestLeft, nDestTop, nDestRight, nDestBottom, nSrcSkip, nDestSkip);
}


STDMETHODIMP CImageDriver::SetProgressInterface(IUnknown* pIUnknown)
{
	return S_FALSE;
}


STDMETHODIMP CImageDriver::GetSupExts(BYTE* lpszExts, UINT flags)
{
	return CBaseRaster::GetSupExts(lpszExts, flags);
}


STDMETHODIMP CImageDriver::Image2World(FLOAT x, FLOAT y, DOUBLE* pX, DOUBLE* pY)
{
	return pRaster->Image2World(x, y, pX, pY);
}


STDMETHODIMP CImageDriver::World2Image(DOUBLE X, DOUBLE Y, int* px, int* py)
{
	return pRaster->World2Image(X, Y, px, py);
}


STDMETHODIMP CImageDriver::GetDefaultBand(int* nBandIndex)
{
	return pRaster->GetDefaultBand(nBandIndex);
}


STDMETHODIMP CImageDriver::GetCamera(BSTR* bstrCamera)
{
	return pRaster->GetCamera(bstrCamera);
}


STDMETHODIMP CImageDriver::SetCamera(BSTR bstrCamera)
{
	return S_FALSE;
}


STDMETHODIMP CImageDriver::GetSensorType(int* pSensorType)
{
	return pRaster->GetSensorType(pSensorType);
}


STDMETHODIMP CImageDriver::SetSensorType(int nSensorType)
{
	return S_FALSE;
}


STDMETHODIMP CImageDriver::GetDPI(FLOAT* pxDPI, FLOAT* pyDPI)
{
	return pRaster->GetDPI(pxDPI, pyDPI);
}


STDMETHODIMP CImageDriver::SetDPI(FLOAT xDPI, FLOAT yDPI)
{
	return pRaster->SetDPI(xDPI, yDPI);
}


STDMETHODIMP CImageDriver::Tiff2JPG(BSTR bstrTiffPath, BSTR bstrJPGPath)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	
	return pRaster->Tiff2JPG(bstrTiffPath, bstrJPGPath);
}


STDMETHODIMP CImageDriver::GetTiledSize(int* nXBlockSize, int* nYBlockSize)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	return pRaster->GetTiledSize(nXBlockSize, nYBlockSize);
}


STDMETHODIMP CImageDriver::Translate(BSTR bstrImgPath)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here

	return pRaster->Translate(bstrImgPath);
}
