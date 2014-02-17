#pragma once
#include "baseraster.h"
#include <vector>

class CAdsRaster :
	public CBaseRaster
{
public:
	CAdsRaster(void);
	~CAdsRaster(void);

public:
	HRESULT Open(BSTR bstrPathPathName, UINT uMode);
	HRESULT ReadImg(int nSrcLeft, int nSrcTop, int nSrcRight, int nSrcBottom, 
		BYTE* pBuf, int nBufWid, int nBufHeight, int nBandNum, 
		int nDestLeft, int nDestTop, int nDestRight, int nDestBottom, int nSrcSkip, int nDestSkip);

private:
	std::vector<CString> m_vecImgList;
	bool m_bIsLineBlock;
	int m_nBlockNum;
	int m_nLinePerBlock;
	int m_nSamplePerBlock;
};

