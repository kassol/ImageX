#include "StdAfx.h"
#include "AdsRaster.h"
#include <fstream>
#include "TiffRaster.h"

CAdsRaster::CAdsRaster(void)
	: m_nLinePerBlock(0)
	, m_nSamplePerBlock(0)
	, m_nHBlockNum(0)
	, m_nVBlockNum(0)
{
}


CAdsRaster::~CAdsRaster(void)
{
	m_vecImgList.clear();
}

HRESULT CAdsRaster::Open(BSTR bstrPathPathName, UINT uMode)
{
	m_strPathName = bstrPathPathName;

	using namespace std;

	int nline = 0, nsample = 0, nlineperblock = 0, nsampleperblock = 0, nblock = 0;
	bool islineblock = false;

	ifstream infile;
	infile.open(m_strPathName.GetBuffer(0), ios::in);
	if (!infile)
	{
		return S_FALSE;
	}

	int temp = 0;

	char *p = new char[500];
	char ch[500];
	infile.getline(p, 500);
	infile.getline(p, 500);
	infile.getline(p, 500);
	infile.getline(p, 500);
	infile>>ch;
	infile>>nline;
	infile>>ch;
	infile>>nsample;
	m_nWidth = nsample;
	m_nHeight = nline;
	infile.getline(p, 500);
	infile.getline(p, 500);
	infile.getline(p, 500);
	infile.getline(p, 500);
	infile>>ch;
	infile>>nlineperblock;
	infile>>ch;
	infile>>nsampleperblock;
	m_nVBlockNum = (nline+nlineperblock-1)/nlineperblock;
	m_nHBlockNum = (nsample+nsampleperblock-1)/nsampleperblock;

	m_nLinePerBlock = nlineperblock;
	m_nSamplePerBlock = nsampleperblock;

	if (!m_vecImgList.empty())
	{
		m_vecImgList.clear();
	}

	m_vecImgList.resize(m_nHBlockNum*m_nVBlockNum, _T(""));

	int ncolindex = 0;
	int nrowindex = 0;
	for (int n = 0; n < m_nHBlockNum*m_nVBlockNum; ++n)
	{
		infile>>ch;
		infile>>ncolindex;
		infile>>nrowindex;
		infile>>ch;

		int index = nrowindex*m_nHBlockNum+ncolindex;

		CString strImageName(ch);
		strImageName = m_strPathName.Left(m_strPathName.ReverseFind('\\')+1)+strImageName;
		m_vecImgList[index] = strImageName;
	}

	CString strImgPath = m_vecImgList.front();

	CBaseRaster* pRaster = new CTiffRaster();

	pRaster->Open(strImgPath.AllocSysString(), modeRead);

	pRaster->GetBandNum(&m_nBandNum);
	pRaster->GetDataType(&m_nDataType);
	pRaster->GetBPB(&m_nBPB);
	pRaster->GetBPP(&m_nBPP);

	pRaster->GetGrdInfo(&m_lfxStart, &m_lfyStart, &m_lfCellSize);

	m_lfyStart += m_nLinePerBlock*m_lfCellSize;
	m_lfyStart -= m_nHeight*m_lfCellSize;

	pRaster->Close();
	delete pRaster;
	pRaster = NULL;

	infile.close();
	delete []p;
	p = NULL;
	return S_OK;
}

HRESULT CAdsRaster::ReadImg(int nSrcLeft, int nSrcTop, int nSrcRight, int nSrcBottom, 
	BYTE* pBuf, int nBufWid, int nBufHeight, int nBandNum, 
	int nDestLeft, int nDestTop, int nDestRight, int nDestBottom, int nSrcSkip, int nDestSkip)
{
	double lfScale = (nDestRight-nDestLeft)/(double)(nSrcRight-nSrcLeft);

	if (nSrcLeft >= m_nWidth || nSrcTop >= m_nHeight || nSrcRight <= 0 || nSrcBottom <= 0)
	{
		return S_FALSE;
	}

	int nStartRowOffset = 0, nStartColOffset = 0, nEndRowOffset = 0, nEndColOffset = 0;

	if (nSrcLeft < 0)
	{
		nStartColOffset = -nSrcLeft;
	}
	if (nSrcTop < 0)
	{
		nStartRowOffset = -nSrcTop;
	}
	if (nSrcRight > m_nWidth)
	{
		nEndColOffset = m_nWidth-nSrcRight;
	}
	if (nSrcBottom > m_nHeight)
	{
		nEndRowOffset = m_nHeight-nSrcBottom;
	}

	nSrcLeft += nStartColOffset;
	nSrcRight += nEndColOffset;
	nSrcTop += nStartRowOffset;
	nSrcBottom += nEndRowOffset;

	nDestLeft += int(nStartColOffset*lfScale);
	nDestRight += int(nEndColOffset*lfScale);
	nDestTop += int(nStartRowOffset*lfScale);
	nDestBottom += int(nEndRowOffset*lfScale);

	int left = 0, right = 0, top = 0, bottom = 0;
	for (int n = 0; n < m_nHBlockNum*m_nVBlockNum; ++n)
	{
		left = n%m_nHBlockNum*m_nSamplePerBlock;
		if (n%m_nHBlockNum != m_nHBlockNum-1)
		{
			right = (n%m_nHBlockNum+1)*m_nSamplePerBlock;
		}
		else
		{
			right = m_nWidth;
		}
		bottom = m_nHeight-m_nLinePerBlock*(n/m_nHBlockNum);
		if (n/m_nHBlockNum != m_nVBlockNum-1)
		{
			top = m_nHeight-m_nLinePerBlock*(n/m_nHBlockNum+1);
		}
		else
		{
			top = 0;
		}

		int nTileSrcLeft = left;
		int nTileSrcRight = right;
		int nTileSrcTop = top;
		int nTileSrcBottom = bottom;

		if (nSrcLeft > left)
		{
			nTileSrcLeft = nSrcLeft;
		}
		if (nSrcRight < right)
		{
			nTileSrcRight = nSrcRight;
		}
		if (nSrcTop > top)
		{
			nTileSrcTop = nSrcTop;
		}
		if (nSrcBottom < bottom)
		{
			nTileSrcBottom = nSrcBottom;
		}

		if (nTileSrcBottom < nTileSrcTop || nTileSrcRight < nTileSrcLeft)
		{
			continue;
		}

		int nSrcLeftTmp = nTileSrcLeft-left;
		int nSrcRightTmp = nTileSrcRight-left;
		int nSrcTopTmp = nTileSrcTop-top;
		int nSrcBottomTmp = nTileSrcBottom-top;

		int nDestLeftTmp = int((nTileSrcLeft-nSrcLeft)*lfScale);
		int nDestRightTmp = int((nTileSrcRight-nSrcLeft)*lfScale);
		int nDestTopTmp = int((nTileSrcTop-nSrcTop)*lfScale);
		int nDestBottomTmp = int((nTileSrcBottom-nSrcTop)*lfScale);

		CString strImagePath = m_vecImgList[n];
		if (nSrcSkip == -1)
		{
			if (nBandNum != m_nBandNum)
			{
				return S_FALSE;
			}
			CBaseRaster* pRaster = new CTiffRaster();
			if(S_FALSE == pRaster->Open(strImagePath.AllocSysString(), modeRead))
			{
				return S_FALSE;
			}

			HRESULT hr = pRaster->ReadImg(nSrcLeftTmp, nSrcTopTmp, nSrcRightTmp, nSrcBottomTmp, 
				pBuf, nBufWid, nBufHeight, nBandNum, 
				nDestLeftTmp, nDestTopTmp, nDestRightTmp, nDestBottomTmp, -1, 0);
			if (FAILED(hr))
			{
				pRaster->Close();
				delete pRaster;
				pRaster = NULL;
				return S_FALSE;
			}
			pRaster->Close();
			delete pRaster;
			pRaster = NULL;
		}
		else
		{
			if (nDestSkip > nBandNum-1)
			{
				return S_FALSE;
			}
			CBaseRaster* pRaster = new CTiffRaster();
			if(S_FALSE == pRaster->Open(strImagePath.AllocSysString(), modeRead))
			{
				return S_FALSE;
			}

			HRESULT hr = pRaster->ReadImg(nSrcLeftTmp, nSrcTopTmp, nSrcRightTmp, nSrcBottomTmp, 
				pBuf, nBufWid, nBufHeight, nBandNum,
				nDestLeftTmp, nDestTopTmp, nDestRightTmp, nDestBottomTmp, nSrcSkip, nDestSkip);

			if (FAILED(hr))
			{
				pRaster->Close();
				delete pRaster;
				pRaster = NULL;
				return S_FALSE;
			}
			pRaster->Close();
			delete pRaster;
			pRaster = NULL;
		}
	}

	return S_OK;
}
