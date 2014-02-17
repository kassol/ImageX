#pragma once
#include "baseraster.h"
class CSatRaster :
	public CBaseRaster
{
public:
	CSatRaster(void);
	~CSatRaster(void);

public:
	HRESULT Open(BSTR bstrPathPathName, UINT uMode);
	HRESULT ReadImg(int nSrcLeft, int nSrcTop, int nSrcRight, int nSrcBottom, 
		BYTE* pBuf, int nBufWid, int nBufHeight, int nBandNum, 
		int nDestLeft, int nDestTop, int nDestRight, int nDestBottom, int nSrcSkip, int nDestSkip);
};

