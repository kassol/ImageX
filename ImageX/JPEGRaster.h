#pragma once
#include "baseraster.h"
class CJPEGRaster :
	public CBaseRaster
{
public:
	CJPEGRaster(void);
	~CJPEGRaster(void);

public:
	HRESULT Open(BSTR bstrPathPathName, UINT uMode);
	HRESULT CreateImg(BSTR bstrFilePath, UINT uMode, int Cols, int Rows, UINT DataType, int nBandNum, UINT BandType, DOUBLE xStart, DOUBLE yStart, DOUBLE cellSize);
	HRESULT Close(void);
};

