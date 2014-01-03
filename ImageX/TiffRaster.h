#pragma once
#include "baseraster.h"
class CTiffRaster :
	public CBaseRaster
{
public:
	CTiffRaster(void);
	~CTiffRaster(void);
	HRESULT Open(BSTR bstrPathPathName, UINT uMode);
	HRESULT CreateImg(BSTR bstrFilePath, UINT uMode, int Cols, int Rows, UINT DataType, int nBandNum, UINT BandType, DOUBLE xStart, DOUBLE yStart, DOUBLE cellSize);


protected:
	void InitGeoInfo();
};

