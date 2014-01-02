#include "StdAfx.h"
#include "BaseRaster.h"

#include "ImageX_i.h"


CBaseRaster::CBaseRaster(void)
	:m_poDataset(NULL)
	, m_nWidth(0)
	, m_nHeight(0)
	, m_nBandNum(0)
	, m_nDataType(-1)
	, m_bIsGeoCoded(false)
	, m_nBytesPerBand(0)
	, m_nOldBytesPerBand(0)
	, m_nResampleMethod(0)
	, m_nBPB(0)
	, m_nBPP(0)
	, m_strPathName(_T(""))
	, m_lfxStart(0)
	, m_lfyStart(0)
	, m_lfCellSize(1)
	, m_uMode(0)
	, m_fxDPI(0)
	, m_fyDPI(0)
	,m_fResolution(0)
	, m_fXResolution(0)
	, m_fYResolution(0)
	, m_bTranto8bit(false)
	, m_plut(NULL)
{
}


CBaseRaster::~CBaseRaster(void)
{
}

HRESULT CBaseRaster::Open(BSTR bstrPathPathName, UINT uMode)
{
	GDALAllRegister();

	if ((uMode & modeAqlut) == modeAqlut)
	{
		m_bTranto8bit = true;
	}
	else
	{
		m_bTranto8bit = false;
	}

	return S_OK;
}
