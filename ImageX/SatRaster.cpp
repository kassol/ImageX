#include "StdAfx.h"
#include "SatRaster.h"

#include <string>
#include <fstream>
using namespace std;


CSatRaster::CSatRaster(void)
{
}


CSatRaster::~CSatRaster(void)
{
}

HRESULT CSatRaster::Open(BSTR bstrPathPathName, UINT uMode)
{
	if ((uMode & modeAqlut) == modeAqlut)
	{
		m_bTranto8bit = true;
	}
	else
	{
		m_bTranto8bit = false;
	}
	m_strPathName = bstrPathPathName;
	string temp;
	ifstream srcSat;
	srcSat.open(m_strPathName.GetBuffer(0), ios::in);
	if (!srcSat)
	{
		return S_FALSE;
	}
	int nTileCount = 0;
	getline(srcSat, temp);
	nTileCount = atoi(temp.c_str());
	if (nTileCount == 0)
	{
		srcSat.close();
		return S_FALSE;
	}
	srcSat>>m_nWidth>>m_nHeight;
	getline(srcSat, temp);
	CString strImgPath;
	getline(srcSat, temp);
	strImgPath = m_strPathName.Left(m_strPathName.ReverseFind('\\'))+temp.c_str();
	CString strFindPath = strImgPath.Left(strImgPath.ReverseFind('\\'))+_T("\\*.*");
	m_poDataset = (GDALDataset*)GDALOpen(strImgPath.GetBuffer(0), GA_ReadOnly);
	if (m_poDataset == NULL)
	{
		srcSat.close();
		return S_FALSE;
	}
	m_nBandNum = m_poDataset->GetRasterCount();
	m_eGDALType = m_poDataset->GetRasterBand(1)->GetRasterDataType();

	switch(m_eGDALType)
	{
	case 1:
		m_nDataType = Pixel_Byte;
		m_nBytesPerBand = 1;
		break;
	case 2:
		m_nDataType = Pixel_Int16;
		m_nBytesPerBand = 2;
		break;
	case 3:
		m_nDataType = Pixel_SInt16;
		m_nBytesPerBand = 2;
		break;
	case 4:
		m_nDataType = Pixel_Int32;
		m_nBytesPerBand = 4;
		break;
	case 5:
		m_nDataType = Pixel_SInt32;
		m_nBytesPerBand = 4;
		break;
	case 6:
		m_nDataType = Pixel_Float;
		m_nBytesPerBand = 4;
		break;
	case 7:
		m_nDataType = Pixel_Double;
		m_nBytesPerBand = 8;
		break;
	case 0:
	case 8:
	case 9:
	case 10:
	case 11:
	case 12:
		m_nDataType = -1;
		m_nBytesPerBand = 0;
		break;
	default:
		m_nDataType = -1;
		m_nBytesPerBand = 0;
	}

	if (m_bTranto8bit)
	{
		m_nOldBytesPerBand = m_nBytesPerBand;
		m_nBytesPerBand = 1;
	}

	m_nBPB = m_nBytesPerBand;
	m_nBPP = m_nBandNum * m_nBPB;
	srcSat.close();

	CFileFind find;
	BOOL bf = find.FindFile(strFindPath);
	CString strTILPathName;
	bool bHasTIL = false;
	while (bf)
	{
		bf = find.FindNextFile();
		strTILPathName = find.GetFilePath();
		if (strTILPathName.Right(3).CompareNoCase("til") == 0)
		{
			bHasTIL = true;
			break;
		}
	}
	if (bHasTIL)
	{
		ifstream til;
		til.open(strTILPathName.GetBuffer(0), ios::in);
		getline(til, temp);
		getline(til, temp);
		getline(til, temp);
		getline(til, temp);
		getline(til, temp);
		getline(til, temp);
		double tmpXStart, tmpYStart;
		m_lfxStart = 0;
		m_lfyStart = 0;
		for (int i = 0; i < nTileCount; ++i)
		{
			getline(til, temp);
			getline(til, temp);

			temp = temp.substr(temp.find_first_of('\"')+1, temp.find_last_of('\"')-
				temp.find_first_of('\"')-1);
			strImgPath = strTILPathName.Left(strTILPathName.ReverseFind('\\'))+_T("\\")+temp.c_str();
			GDALClose((GDALDatasetH)m_poDataset);
			m_poDataset = (GDALDataset*)GDALOpen(strImgPath.GetBuffer(0), GA_ReadOnly);

			m_poDataset->GetGeoTransform(m_pGeoTrans);
			int nYSize = m_poDataset->GetRasterYSize();

			m_lfCellSize = abs(m_pGeoTrans[1]);
			tmpXStart = m_pGeoTrans[0];
			tmpYStart = m_pGeoTrans[3]-nYSize*m_lfCellSize;
			
			if (m_lfxStart == 0 || m_lfxStart-tmpXStart > 0.00001)
			{
				m_lfxStart = tmpXStart;
			}
			if (m_lfyStart == 0 || m_lfyStart-tmpYStart > 0.00001)
			{
				m_lfyStart = tmpYStart;
			}

			for (int j = 0; j < 25; ++j)
			{
				getline(til, temp);
			}
		}
		til.close();
	}

	return S_OK;
}

HRESULT CSatRaster::ReadImg(int nSrcLeft, int nSrcTop, int nSrcRight, int nSrcBottom, BYTE* pBuf, int nBufWid, int nBufHeight, int nBandNum, int nDestLeft, int nDestTop, int nDestRight, int nDestBottom, int nSrcSkip, int nDestSkip)
{
	double lfScale = (nDestRight-nDestLeft)/(double)(nSrcRight-nSrcLeft);

	string temp;
	ifstream srcSat;
	srcSat.open(m_strPathName.GetBuffer(0), ios::in);
	int nTileCount = 0;
	getline(srcSat, temp);
	nTileCount = atoi(temp.c_str());

	if (nSrcLeft >= m_nWidth || nSrcTop >= m_nHeight || nSrcRight <= 0 || nSrcBottom <= 0)
	{
		srcSat.close();
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

	int nReadWidth = nSrcRight-nSrcLeft;
	int nBufWidth = nDestRight-nDestLeft;

	getline(srcSat, temp);
	getline(srcSat, temp);
	temp = temp.substr(0, temp.find_last_of('\\'));
	CString strFindPath;
	strFindPath = m_strPathName.Left(m_strPathName.ReverseFind('\\'))+temp.c_str()+_T("\\*.*");
	CFileFind find;
	BOOL bf = find.FindFile(strFindPath);
	CString strTILPathName;
	bool bHasTIL = false;
	while(bf)
	{
		bf = find.FindNextFile();
		strTILPathName = find.GetFilePath();
		if (strTILPathName.Right(3).CompareNoCase("til") == 0)
		{
			bHasTIL = true;
			break;
		}
	}
	if (bHasTIL)
	{
		ifstream til;
		til.open(strTILPathName.GetBuffer(0), ios::in);
		getline(til, temp);
		getline(til, temp);
		getline(til, temp);
		getline(til, temp);
		getline(til, temp);
		getline(til, temp);

		CString strImagePath;
		CString strLutPath;
		int left = 0, right = 0, top = 0, bottom = 0;

		for (int i = 0; i < nTileCount; ++i)
		{
			getline(til, temp);
			getline(til, temp);
			temp = temp.substr(temp.find_first_of('\"')+1, temp.find_last_of('\"')-
				temp.find_first_of('\"')-1);
			strImagePath = strTILPathName.Left(strTILPathName.ReverseFind('\\'))+_T("\\")+temp.c_str();
			strLutPath = strImagePath+_T("_lut.txt");

			getline(til, temp);
			temp = temp.substr(temp.find_last_of(' ')+1, temp.find_last_of(';')-
				temp.find_last_of(' ')-1);
			left = atoi(temp.c_str());

			getline(til, temp);
			temp = temp.substr(temp.find_last_of(' ')+1, temp.find_last_of(';')-
				temp.find_last_of(' ')-1);
			top = atoi(temp.c_str());

			getline(til, temp);
			temp = temp.substr(temp.find_last_of(' ')+1, temp.find_last_of(';')-
				temp.find_last_of(' ')-1);
			right = atoi(temp.c_str())+1;

			getline(til, temp);
			getline(til, temp);
			getline(til, temp);
			temp = temp.substr(temp.find_last_of(' ')+1, temp.find_last_of(';')-
				temp.find_last_of(' ')-1);
			bottom = atoi(temp.c_str())+1;

			int tembottom = bottom;
			int temtop = top;
			top = m_nHeight-tembottom;
			bottom = m_nHeight-temtop;

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
				for (int restline = 0; restline <19; ++restline)
				{
					getline(til, temp);
				}
				continue;
			}
			int nSrcLeftTmp = nTileSrcLeft-left;
			int nSrcRightTmp = nTileSrcRight-left;
			int nSrcTopTmp = bottom-nTileSrcBottom;
			int nSrcBottomTmp = bottom-nTileSrcTop;

			int nDestLeftTmp = int((nTileSrcLeft-nSrcLeft)*lfScale);
			int nDestRightTmp = int((nTileSrcRight-nSrcLeft)*lfScale);
			int nDestTopTmp = int((nTileSrcTop-nSrcTop)*lfScale);
			int nDestBottomTmp = int((nTileSrcBottom-nSrcTop)*lfScale);

			FILE* stream;
			m_plut = new BYTE[m_nBandNum*65536];
			if(fopen_s(&stream, strLutPath.LockBuffer(), "rb") == 0)
			{
				fread(m_plut, sizeof(BYTE), 65536*m_nBandNum, stream);
			}
			fclose(stream);


			if (nSrcSkip == -1)
			{
				if (nBandNum != m_nBandNum)
				{
					return S_FALSE;
				}
				GDALClose((GDALDatasetH)m_poDataset);
				m_poDataset = (GDALDataset*)GDALOpen(strImagePath.GetBuffer(0), GA_ReadOnly);
				if (m_poDataset == NULL)
				{
					return S_FALSE;
				}
				int *bandmap = new int[nBandNum];
				for (int i = 0; i < nBandNum; ++i)
				{
					bandmap[i] = i+1;
				}
				if (!m_bTranto8bit)
				{
					CPLErr er = m_poDataset->RasterIO(GF_Read, nSrcLeftTmp, nSrcTopTmp, 
						nSrcRightTmp-nSrcLeftTmp, nSrcBottomTmp-nSrcTopTmp, 
						pBuf+(nDestBottomTmp-1)*nBufWid*m_nBPP+nDestLeftTmp*m_nBPP,
						nDestRightTmp-nDestLeftTmp, nDestBottomTmp-nDestTopTmp, m_eGDALType, nBandNum,
						bandmap, m_nBPP, -m_nBPP*nBufWid, m_nBPB);
					if (CE_Failure == er)
					{
						return S_FALSE;
					}
				}
				else
				{
					BYTE *temBuf = new BYTE[m_nOldBytesPerBand*m_nBandNum*nBufHeight*nBufWid];
					CPLErr er = m_poDataset->RasterIO(GF_Read, nSrcLeftTmp, nSrcTopTmp, 
						nSrcRightTmp-nSrcLeftTmp, nSrcBottomTmp-nSrcTopTmp,
						temBuf+(nDestBottomTmp-1)*m_nOldBytesPerBand*nBandNum*nBufWid
						+nDestLeftTmp*m_nOldBytesPerBand*nBandNum, nDestRightTmp-nDestLeftTmp,
						nDestBottomTmp-nDestTopTmp, m_eGDALType, nBandNum, bandmap,
						m_nOldBytesPerBand*nBandNum, -m_nOldBytesPerBand*nBandNum*nBufWid, m_nOldBytesPerBand);
					if (CE_Failure == er)
					{
						return S_FALSE;
					}
					switch(m_nDataType)
					{
					case Pixel_Int16:
						{
							unsigned short* pp = (unsigned short*)temBuf;
							for (int j = nDestTopTmp; j < nDestBottomTmp; ++j)
							{
								for (int i = nDestLeftTmp; i < nDestRightTmp; ++i)
								{
									for (int nb = 0; nb < nBandNum; ++nb)
									{
										pBuf[j*nBufWid*nBandNum+i*nBandNum+nb] = m_plut[nb*65536
											+pp[j*nBufWid*nBandNum+i*nBandNum+nb]];
									}
								}
							}
							break;
						}
					}
					delete []temBuf;
					temBuf = NULL;
				}
				delete []bandmap;
				bandmap = NULL;
			}
			else
			{
				if (nDestSkip > nBandNum - 1)
				{
					return S_FALSE;
				}
				GDALClose((GDALDatasetH)m_poDataset);
				m_poDataset = (GDALDataset*)GDALOpen(strImagePath.GetBuffer(0), GA_ReadOnly);
				if (m_poDataset == NULL)
				{
					return S_FALSE;
				}
				if (!m_bTranto8bit)
				{
					CPLErr er = m_poDataset->GetRasterBand(nSrcSkip+1)->RasterIO(GF_Read, nSrcLeftTmp,
						nSrcTopTmp, nSrcRightTmp-nSrcLeftTmp, nSrcBottomTmp-nSrcTopTmp, 
						pBuf+(nDestBottomTmp-1)*nBufWid*nBandNum*m_nBPB+nDestLeftTmp*nBandNum
						*m_nBPB+nDestSkip*m_nBPB, nDestRightTmp-nDestLeftTmp,
						nDestBottomTmp-nDestTopTmp, m_eGDALType, nBandNum*m_nBPB,
						-nBandNum*m_nBPB*nBufWidth);
					if (CE_Failure == er)
					{
						return S_FALSE;
					}
				}
				else
				{
					BYTE *temBuf = new BYTE[m_nOldBytesPerBand*nBufHeight*nBufWid];
					CPLErr er = m_poDataset->GetRasterBand(nSrcSkip+1)->RasterIO(GF_Read, nSrcLeftTmp,
						nSrcTopTmp, nSrcRightTmp-nSrcLeftTmp, nSrcBottomTmp-nSrcTopTmp,
						temBuf+(nDestBottomTmp-1)*nBufWid*m_nOldBytesPerBand+nDestLeftTmp*m_nOldBytesPerBand,
						nDestRightTmp-nDestLeftTmp, nDestBottomTmp-nDestTopTmp, m_eGDALType,
						m_nOldBytesPerBand, -m_nOldBytesPerBand*nBufWid);
					if (CE_Failure == er)
					{
						return S_FALSE;
					}
					switch(m_nDataType)
					{
					case Pixel_Int16:
						{
							unsigned short* pp = (unsigned short*)temBuf;
							for (int j = nDestTopTmp; j < nDestBottomTmp; ++j)
							{
								for (int i = nDestLeftTmp; i < nDestRightTmp; ++i)
								{
									pBuf[j*nBufWid*nBandNum+i*nBandNum+nDestSkip] = 
										m_plut[nSrcSkip*65536+pp[j*nBufWid+i]];
								}
							}
							break;
						}
					}
					delete []temBuf;
					temBuf = NULL;
				}
			}


			for (int restline = 0; restline <19; ++restline)
			{
				getline(til, temp);
			}
		}
		til.close();
	}
	srcSat.close();
	return S_OK;
}
