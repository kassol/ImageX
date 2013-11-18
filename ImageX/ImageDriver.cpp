// ImageDriver.cpp : Implementation of CImageDriver

#include "stdafx.h"
#include "ImageDriver.h"
#include <comutil.h>
#include <fstream>
#include <io.h>
using namespace std;

HANDLE hmutex2 = CreateMutex(NULL, FALSE, _T("RW"));

// CImageDriver
#define BiLinear_img(Type) void Type##_BiLinear_img(BYTE *buf11,BYTE *buf21, \
	BYTE *buf22,BYTE *buf12, \
	double Dx,double Dy,     \
	BYTE *pOut)				\
{																\
	*((Type *)pOut) = (Type)((1-Dx) * (1-Dy) * (*((Type*)buf11))			\
	+ Dx     * (1-Dy) * (*((Type*)buf21))				\
	+ Dx     * Dy     * (*((Type*)buf22))				\
	+ (1-Dx) * Dy     * (*((Type*)buf12)));			\
}

	inline BiLinear_img(BYTE)
	inline BiLinear_img(USHORT)
	inline BiLinear_img(short)
	inline BiLinear_img(UINT)
	inline BiLinear_img(int)
	inline BiLinear_img(float)
	inline BiLinear_img(double)
	inline BiLinear_img(__int64)

#define FuncName_img(Type) Type##_BiLinear_img

	typedef void (* BiLinearFunc_img)(BYTE *buf11,BYTE *buf21, BYTE *buf22,BYTE *buf12,double Dx,double Dy, BYTE *pOut);

static BiLinearFunc_img FuncTable_img[9] = {FuncName_img(BYTE),
	FuncName_img(USHORT),
	FuncName_img(short),
	FuncName_img(UINT),
	FuncName_img(int),
	FuncName_img(float),
	FuncName_img(double),
	FuncName_img(__int64),
	FuncName_img(__int64)//the singed int64 is same as int64
};


STDMETHODIMP CImageDriver::Open(BSTR bstrPathName, UINT uMode)
{
	// TODO: Add your implementation code here
	GDALAllRegister();
	if ((uMode & modeAqlut) == modeAqlut)
	{
		m_bTranto8bit = true;
	}
	else
	{
		m_bTranto8bit = false;
	}

	_bstr_t bstrtPathName = bstrPathName;
	m_strPathName = (const char*)bstrtPathName;
	m_uMode = uMode;
	CString strPathName = bstrtPathName;

	if(strPathName.Right(strPathName.GetLength()-strPathName.ReverseFind('.')-1).CompareNoCase("hdr")==0)
	{
		strPathName = strPathName.Left(strPathName.ReverseFind('.'))+_T(".img");
		m_strPathName = strPathName.LockBuffer();
	}

	if ( (uMode & modeReadWrite) == modeReadWrite )
	{
		CString strExt = strPathName.Right(strPathName.GetLength()-strPathName.ReverseFind('.')-1);
		if (strExt.CompareNoCase("jpg") == 0 || strExt.CompareNoCase("jpeg") == 0 || strExt.CompareNoCase("ecw") == 0)
		{
			m_poDataset = (GDALDataset*)GDALOpen(m_strPathName, GA_ReadOnly);
		}
		else
		{
			m_poDataset = (GDALDataset*)GDALOpen(m_strPathName, GA_Update);
		}
	}
	else if ( ((uMode & modeRead) == modeRead) && ((uMode & modePyramidCreate) == modePyramidCreate) )
	{
		m_poDataset = (GDALDataset*)GDALOpen( m_strPathName, GA_Update);
	}
	else if ( ((uMode & modeRead) == modeRead) && ((uMode & modePyramidCreate) != modePyramidCreate) )
	{
		m_poDataset = (GDALDataset*)GDALOpen( m_strPathName, GA_ReadOnly);
	}
	else
		return S_FALSE;


	m_nWidth = m_poDataset->GetRasterXSize();
	m_nHeight = m_poDataset->GetRasterYSize();
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

	if (m_nDataType == Pixel_Byte)
	{
		m_bTranto8bit = false;
	}
	if (m_bTranto8bit)
	{
		m_plut = new BYTE[m_nBandNum*65536];
		m_nOldBytesPerBand = m_nBytesPerBand;
		m_nBytesPerBand = 1;
		WaitForSingleObject(hmutex2, INFINITE);
		FILE* stream;
		CString strLutPath = strPathName + _T(".lut");
		if (_access(strLutPath, 0) != -1)
		{
			if(fopen_s(&stream, strLutPath.LockBuffer(), "rt") == 0)
			{
				fread(m_plut, sizeof(BYTE), 65536*m_nBandNum, stream);
			}
			fclose(stream);
		}
		else
		{
			const int nState = 1000;
			int nCols = m_nWidth>nState? nState:m_nWidth;
			int nRows = m_nHeight>nState? nState:m_nHeight;
			switch(m_nDataType)
			{
			case Pixel_Int16:
				{
					unsigned short* pOverview = new unsigned short[nCols*nRows*m_nBandNum];
					int* bandmap = new int[m_nBandNum];
					for (int i = 0; i < m_nBandNum; ++i)
					{
						bandmap[i] = i+1;
					}
					m_poDataset->RasterIO(GF_Read, 0, 0, m_nWidth, m_nHeight, pOverview, nCols, nRows, m_eGDALType, m_nBandNum, bandmap, 0, 0, 0);
					int nodata = (int)m_poDataset->GetRasterBand(1)->GetNoDataValue();
					delete []bandmap;
					bandmap = NULL;
					double*pHistogram = new double[65536];
					for (int nb =  0; nb < m_nBandNum; ++nb)
					{
						memset(pHistogram, 0, sizeof(double)*65536);
						for (int n = nb; n < nCols*nRows*m_nBandNum; n += m_nBandNum)
						{
							pHistogram[pOverview[n]]++;
						}
						double SamplesOfPixel = 0;
						for (int n = 1; n < 65535; ++n)
						{
							SamplesOfPixel += pHistogram[n];
						}
						double noiseLimit = 0.0001, noise = 0, lfNoiseLimit = 0.001;
						int nBandMin = 0, nBandMax = 65535;
						for (int n = 1; n < 65535; ++n)
						{
							noise += pHistogram[n];
							if (noise/SamplesOfPixel > noiseLimit)
							{
								nBandMin = n;
								break;
							}
						}
						
						noise = 0;
						for (int n = 65534; n >= 1; --n)
						{
							noise += pHistogram[n];
							if (noise/SamplesOfPixel > lfNoiseLimit)
							{
								nBandMax = n;
								break;
							}
						}
						for (int n = 0; n <= 65535; ++n)
						{
							double temp = double(n-nBandMin)/(nBandMax-nBandMin)*255+0.5;
							if (temp > 255)
							{
								m_plut[nb*65536+n] = 255;
							}
							else if (temp < 0)
							{
								m_plut[nb*65536+n] = 0;
							}
							else
							{
								m_plut[nb*65536+n] = (BYTE)temp;
							}
						}
					}
					delete []pHistogram;
					pHistogram = NULL;
					delete []pOverview;
					pOverview = NULL;
					break;
				}
			case Pixel_SInt16:
				{
					short* pOverview = new short[nCols*nRows*m_nBandNum];
					int* bandmap = new int[m_nBandNum];
					for (int i = 0; i < m_nBandNum; ++i)
					{
						bandmap[i] = i+1;
					}
					m_poDataset->RasterIO(GF_Read, 0, 0, m_nWidth, m_nHeight, pOverview, nCols, nRows, m_eGDALType, m_nBandNum, bandmap, 0, 0, 0);
					int nodata = (int)m_poDataset->GetRasterBand(1)->GetNoDataValue();
					delete []bandmap;
					bandmap = NULL;
					double*pHistogram = new double[65536];
					for (int nb =  0; nb < m_nBandNum; ++nb)
					{
						memset(pHistogram, 0, sizeof(double)*65536);
						for (int n = nb; n < nCols*nRows*m_nBandNum; n += m_nBandNum)
						{
							pHistogram[pOverview[n]]++;
						}
						double SamplesOfPixel = 0;
						for (int n = 1; n < 65535; ++n)
						{
							SamplesOfPixel += pHistogram[n];
						}
						double noiseLimit = 0.0001, noise = 0, lfNoiseLimit = 0.001;
						int nBandMin = 0, nBandMax = 65535;
						for (int n = 1; n < 65535; ++n)
						{
							noise += pHistogram[n];
							if (noise/SamplesOfPixel > noiseLimit)
							{
								nBandMin = n;
								break;
							}
						}

						noise = 0;
						for (int n = 65534; n >= 1; --n)
						{
							noise += pHistogram[n];
							if (noise/SamplesOfPixel > lfNoiseLimit)
							{
								nBandMax = n;
								break;
							}
						}
						for (int n = 0; n <= 65535; ++n)
						{
							double temp = double(n-nBandMin)/(nBandMax-nBandMin)*255+0.5;
							if (temp > 255)
							{
								m_plut[nb*65536+n] = 255;
							}
							else if (temp < 0)
							{
								m_plut[nb*65536+n] = 0;
							}
							else
							{
								m_plut[nb*65536+n] = (BYTE)temp;
							}
						}
					}
					delete []pHistogram;
					pHistogram = NULL;
					delete []pOverview;
					pOverview = NULL;
					break;
				}
			}
			if(fopen_s(&stream, strLutPath.LockBuffer(), "wt") == 0)
			{
				fwrite(m_plut, sizeof(BYTE), 65536*m_nBandNum, stream);
			}
			fclose(stream);
		}
		ReleaseMutex(hmutex2);
	}

	m_nBPB = m_nBytesPerBand;
	m_nBPP = m_nBandNum * m_nBPB;
	if (m_nWidth == 0 || m_nHeight == 0 && m_nBandNum == 0 || m_nDataType == -1)
	{
		return S_FALSE;
	}
	//TFW
	if (strPathName.Right(strPathName.GetLength()-strPathName.ReverseFind('.')-1).CompareNoCase("tiff") == 0 || 
		strPathName.Right(strPathName.GetLength()-strPathName.ReverseFind('.')-1).CompareNoCase("tif") == 0)
	{
		CString strExt = strPathName.Left(strPathName.ReverseFind('.'))+_T(".tfw");
		fstream infile;
		infile.open(strExt.LockBuffer(), ios::in);
		if (infile != NULL)
		{
			infile>>m_lfCellsize;
			double temp;
			infile>>temp;
			infile>>temp;
			infile>>temp;
			infile>>m_pGeoTrans[0];
			infile>>m_pGeoTrans[3];
			m_pGeoTrans[1] = m_lfCellsize;
			m_pGeoTrans[2] = 0;
			m_pGeoTrans[4] = 0;
			m_pGeoTrans[5] = -m_lfCellsize;
			m_bIsGeoCoded = true;
		}
		else
		{
			if (m_poDataset->GetGeoTransform(m_pGeoTrans) == CE_None)
			{
				m_bIsGeoCoded = true;
			}
			else
			{
				m_bIsGeoCoded = false;
			}
		}
		infile.clear();
		infile.close();
	}
	else
	{
		if (m_poDataset->GetGeoTransform(m_pGeoTrans) == CE_None)
		{
			m_bIsGeoCoded = true;
		}
		else
		{
			m_bIsGeoCoded = false;
		}
	}
	
	if (m_bIsGeoCoded == false)
	{
		m_lfxStart = 0;
		m_lfyStart = 0;
		m_lfCellsize = 1;
	}
	else
	{
		m_lfxStart = m_pGeoTrans[0];
		if (abs(m_pGeoTrans[1]) != abs(m_pGeoTrans[5]))
		{
			m_lfCellsize = 1;
		}
		else
		{
			m_lfCellsize = abs(m_pGeoTrans[1]);
		}
		m_lfyStart = m_pGeoTrans[3] - m_nHeight*m_lfCellsize;
	}

	char **pszMetadata = m_poDataset->GetMetadata();
	const char * dpitmp = CSLFetchNameValue(pszMetadata, "TIFFTAG_RESOLUTIONUNIT");
	if (dpitmp == NULL)
	{
		m_fResolution = -1;
	}
	else if (dpitmp[0] == '2')//inch
	{
		const char* xdpi = CSLFetchNameValue(pszMetadata, "TIFFTAG_XRESOLUTION");
		const char* ydpi = CSLFetchNameValue(pszMetadata, "TIFFTAG_YRESOLUTION");
		m_fXResolution = (float)atof(xdpi);
		m_fYResolution = (float)atof(ydpi);
		m_fResolution = (float)25.4/m_fXResolution;
	}
	else if (dpitmp[0] == '3')//cm
	{
		const char* xdpi = CSLFetchNameValue(pszMetadata, "TIFFTAG_XRESOLUTION");
		const char* ydpi = CSLFetchNameValue(pszMetadata, "TIFFTAG_YRESOLUTION");
		m_fXResolution = (float)(atof(xdpi)*2.54);
		m_fYResolution = (float)(atof(ydpi)*2.54);
		m_fResolution = (float)(10.0/atof(xdpi));
	}
	else
	{
		m_fResolution = -1;
	}
	//½ð×ÖËþ
	const char* pszResampling = "NEAREST";

	if ((uMode & modePyramidClean) == modePyramidClean)
	{
		GDALBuildOverviews( (GDALDatasetH)m_poDataset, pszResampling, 0, 0, 0, NULL, NULL, NULL );
	}

	if ((uMode & modePyramidCreate) == modePyramidCreate)
	{
		CPLSetConfigOption( "USE_RRD", "YES" );
		int nLevelCount = 0;
		int *pOverviewList = NULL;
		int i = 0;
		while(1)
		{
			int n = (int)pow(2.0, i);
			if (m_nWidth/n < 128 || m_nHeight/n <128)
			{
				nLevelCount = i;
				pOverviewList = new int [nLevelCount];
				for (int n = 0; n < nLevelCount; ++n)
				{
					pOverviewList[n] = (int)pow(2.0, n+1);
				}
				break;
			}
			++i;
		}
		GDALBuildOverviews((GDALDatasetH)m_poDataset, pszResampling, nLevelCount, pOverviewList, 0, NULL, NULL, NULL);
	}
	
	return S_OK;
}


STDMETHODIMP CImageDriver::CreateImg(BSTR bstrFilePath, UINT uMode, int Cols, int Rows, 
																			   UINT DataType, int nBandNum, UINT BandType, DOUBLE xStart, DOUBLE yStart, DOUBLE cellSize)
{
	// TODO: Add your implementation code here
	m_bTranto8bit = false;
	if ((uMode & modeCreate) != modeCreate)
	{
		return S_FALSE;
	}
	GDALAllRegister();
	_bstr_t bstrtPathName = bstrFilePath;
	
	CString strFilePath = bstrtPathName;
	CString strExt = strFilePath.Right(strFilePath.GetLength() - strFilePath.ReverseFind('.')-1);

	char* pszDriverName;
	if (strExt.CompareNoCase("tiff") == 0 || strExt.CompareNoCase("tif") == 0)
	{
		pszDriverName = "GTIFF";
	}
	else if (strExt.CompareNoCase("bmp") == 0)
	{
		pszDriverName = "BMP";
	}
	else if (strExt.CompareNoCase("img") == 0)
	{
		pszDriverName = "HFA";
	}
	else if (strExt.CompareNoCase("jpeg") == 0 || strExt.CompareNoCase("jpg") == 0)
	{
		pszDriverName = "JPEG";
	}
	else if (strExt.CompareNoCase("ntf") == 0)
	{
		pszDriverName = "NITF";
	}
	else if (strExt.CompareNoCase("hdr") == 0)
	{
		pszDriverName = "ENVI";
		strFilePath.Left(strFilePath.Find('.'));
		strFilePath += _T(".img");
	}
	else if (strExt.CompareNoCase("raw") == 0)
	{
		pszDriverName = "EIR";
	}
	else
	{
		return S_FALSE;
	}

	GDALDriver *poDriver;
	poDriver = GetGDALDriverManager()->GetDriverByName(pszDriverName);
	if( poDriver == NULL )
	{
		return S_FALSE;
	}
	char** ppszMetaData = poDriver->GetMetadata();
	if ( CSLFetchBoolean( ppszMetaData, GDAL_DCAP_CREATE, FALSE ) != TRUE && CSLFetchBoolean(ppszMetaData, GDAL_DCAP_CREATECOPY, FALSE) != TRUE)
	{
		return S_FALSE;
	}

	m_nWidth = Cols;
	m_nHeight = Rows;
	m_nBandNum = nBandNum;
	m_strPathName = strFilePath.LockBuffer();
	m_nDataType = DataType;
	m_uMode = uMode;

	switch(m_nDataType)
	{
	case Pixel_Byte:
		m_eGDALType = GDT_Byte;
		m_nBytesPerBand = 1;
		break;
	case Pixel_Int16:
		m_eGDALType = GDT_UInt16;
		m_nBytesPerBand = 2;
		break;
	case Pixel_SInt16:
		m_eGDALType = GDT_Int16;
		m_nBytesPerBand = 2;
		break;
	case Pixel_Int32:
		m_eGDALType = GDT_UInt32;
		m_nBytesPerBand = 4;
		break;
	case Pixel_SInt32:
		m_eGDALType = GDT_Int32;
		m_nBytesPerBand = 4;
		break;
	case Pixel_Float:
		m_eGDALType = GDT_Float32;
		m_nBytesPerBand = 4;
		break;
	case Pixel_Double:
		m_eGDALType = GDT_Float64;
		m_nBytesPerBand = 8;
		break;
	case Pixel_Int64:
	case Pixel_SInt64:
		m_eGDALType = GDT_Unknown;
		m_nBytesPerBand = 0;
		break;
	default:
		m_eGDALType = GDT_Byte;
		m_nBytesPerBand = 1;
	}
	m_nBPB = m_nBytesPerBand;
	m_nBPP = m_nBPB* m_nBandNum;

	char** ppszOptions = NULL;
	if (strcmp(pszDriverName, "GTIFF") == 0)
	{
		//ppszOptions = CSLSetNameValue(ppszOptions, "TFW", "YES");
		ppszOptions = CSLSetNameValue(ppszOptions, "BIGTIFF", "IF_NEEDED");
		//ppszOptions = CSLSetNameValue(ppszOptions, "TILED", "YES");
		//ppszOptions = CSLSetNameValue(ppszOptions, "BLOCKXSIZE", "128");
		//ppszOptions = CSLSetNameValue(ppszOptions, "BLOCKYSIZE", "128");
		switch(BandType)
		{
		case BIL:
			break;
		case BSQ:
			ppszOptions = CSLSetNameValue(ppszOptions, "INTERLEAVE", "BAND");
			break;
		case BIP:
			ppszOptions = CSLSetNameValue(ppszOptions, "INTERLEAVE", "PIXEL");
			break;
		}
	}
	else if (strcmp(pszDriverName, "ENVI") == 0)
	{
		switch(BandType)
		{
		case BIL:
			ppszOptions = CSLSetNameValue(ppszOptions, "INTERLEAVE", "BIL");
			break;
		case BSQ:
			ppszOptions = CSLSetNameValue(ppszOptions, "INTERLEAVE", "BSQ");
			break;
		case BIP:
			ppszOptions = CSLSetNameValue(ppszOptions, "INTERLEAVE", "BIP");
			break;
		}
	}
	else if (strcmp(pszDriverName, "HFA") == 0)
	{
		ppszOptions = CSLSetNameValue(ppszOptions, "BLOCKSIZE", "128");
	}
	else if (strcmp(pszDriverName, "NITF") == 0)
	{
		ppszOptions = CSLSetNameValue(ppszOptions, "BLOCKXSIZE", "128");
		ppszOptions = CSLSetNameValue(ppszOptions, "BLOCKYSIZE", "128");
	}
	if (CSLFetchBoolean( ppszMetaData, GDAL_DCAP_CREATE, FALSE ) != TRUE)
	{
		CString temPathName = strFilePath.Left(strFilePath.ReverseFind('.'))+_T("_temp.tif");
		GDALDriver *tempoDriver = GetGDALDriverManager()->GetDriverByName("GTIFF");
		m_poDataset = tempoDriver->Create(temPathName.LockBuffer(), Cols, Rows, nBandNum, m_eGDALType, ppszOptions);
	}
	else
	{
		m_poDataset = poDriver->Create( m_strPathName, Cols, Rows, nBandNum, m_eGDALType, ppszOptions );
	}
	if ( m_poDataset == NULL )
	{
		return S_FALSE;
	}

	m_pGeoTrans[0] = xStart;
	m_pGeoTrans[1] = cellSize;
	m_pGeoTrans[2] = 0;
	m_pGeoTrans[3] = yStart + cellSize * m_nHeight;
	m_pGeoTrans[4] = 0;
	m_pGeoTrans[5] = 0.0-cellSize;
	m_lfxStart = xStart;
	m_lfyStart = yStart;
	m_lfCellsize = cellSize;
	m_bIsGeoCoded = true;
	m_nResampleMethod = 0;

	if (strcmp(pszDriverName, "GTIFF") == 0)			//TFW
	{
		strFilePath = m_poDataset->GetDescription();
		CString strTFWPath = strFilePath.Left(strFilePath.ReverseFind('.'));
		strTFWPath += _T(".tfw");

		fstream outfile;
		outfile.open(strTFWPath.LockBuffer(), ios::out);
		char *temp = new char[50];
		memset(temp, 0, 50*sizeof(char));
		sprintf(temp, "%.6f\n", m_lfCellsize);
		outfile<<temp;
		sprintf(temp, "%.6f\n", 0.0);
		outfile<<temp;
		sprintf(temp, "%.6f\n", 0.0);
		outfile<<temp;
		sprintf(temp, "%.6f\n", -m_lfCellsize);
		outfile<<temp;
		sprintf(temp, "%.6f\n", m_lfxStart);
		outfile<<temp;
		sprintf(temp, "%.6f\n", m_lfyStart+m_lfCellsize*m_nHeight);
		outfile<<temp;
		outfile.clear();
		outfile.close();
		delete []temp;
		temp = NULL;
	}
	m_poDataset->SetGeoTransform(m_pGeoTrans);

	if (strcmp(pszDriverName, "ENVI") == 0)
	{
		for (int n = 0; n < m_nBandNum; ++n)
		{
			m_poDataset->GetRasterBand(n+1)->Fill(0);
		}
	}
	return S_OK;
}


STDMETHODIMP CImageDriver::Close(void)
{
	// TODO: Add your implementation code here
	CString strPathName = m_strPathName;
	if (strPathName.Right(strPathName.GetLength()-strPathName.ReverseFind('.')-1).CompareNoCase("jpg") == 0 ||
		strPathName.Right(strPathName.GetLength()-strPathName.ReverseFind('.')-1).CompareNoCase("jpeg") == 0)
	{
		if ((m_uMode&modeCreate) == modeCreate)
		{
			GDALDriver* tempoDriver = GetGDALDriverManager()->GetDriverByName("JPEG");
			GDALDataset* tempoDataset = tempoDriver->CreateCopy(m_strPathName, m_poDataset, TRUE, NULL, NULL, NULL);
			GDALClose((GDALDatasetH)tempoDataset);
			GDALClose((GDALDatasetH)m_poDataset);
			CString temPathName = strPathName.Left(strPathName.ReverseFind('.'))+_T("_temp.tif");
			DeleteFileA(temPathName);
		}
		else
		{
			GDALClose((GDALDatasetH)m_poDataset);
		}
	}
	else
	{
		GDALClose((GDALDatasetH)m_poDataset);
	}
	if (m_bTranto8bit)
	{
		delete []m_plut;
		m_plut = NULL;
	}
	m_bIsGeoCoded = false;
	m_bTranto8bit = false;
	return S_OK;
}


STDMETHODIMP CImageDriver::IsGeoCoded(void)
{
	// TODO: Add your implementation code here
	if ( m_bIsGeoCoded == true )
		return S_OK;
	else
		return S_FALSE;
}


STDMETHODIMP CImageDriver::GetBandFormat(UINT* pBandFormat)
{
	// TODO: Add your implementation code here
	char** pszMetaData = m_poDataset->GetMetadata("IMAGE_STRUCTURE");
	if (pszMetaData == NULL)
	{
		return S_FALSE;
	}
	const char* pszBand = CSLFetchNameValue(pszMetaData, "INTERLEAVE");
	if (pszBand == NULL)
	{
		return S_FALSE;
	}
	if (strcmp(pszBand, "LINE") == 0)
	{
		*pBandFormat = BIL;
	}
	else if (strcmp(pszBand, "BAND") == 0)
	{
		*pBandFormat = BSQ;
	}
	else if (strcmp(pszBand, "PIXEL")==0)
	{
		*pBandFormat = BIP;
	}
	else
	{
		*pBandFormat = BSQ;
	}
	return S_OK;
}


STDMETHODIMP CImageDriver::GetBandNum(int* pBandNum)
{
	// TODO: Add your implementation code here
	*pBandNum = m_nBandNum;
	return S_OK;
}


STDMETHODIMP CImageDriver::GetRows(int* pRows)
{
	// TODO: Add your implementation code here
	*pRows = m_nHeight;
	return S_OK;
}


STDMETHODIMP CImageDriver::GetCols(int* pCols)
{
	// TODO: Add your implementation code here
	*pCols = m_nWidth;
	return S_OK;
}


STDMETHODIMP CImageDriver::GetDataType(UINT* pDataType)
{
	// TODO: Add your implementation code here
	*pDataType = m_nDataType;
	return S_OK;
}


STDMETHODIMP CImageDriver::GetByteOrder(UINT* pByteOrder)
{
	// TODO: Add your implementation code here
	*pByteOrder = Intel;
	return S_OK;
}


STDMETHODIMP CImageDriver::GetScale(FLOAT* pScale)
{
	// TODO: Add your implementation code here
	if (m_fResolution != -1.0)
	{
		*pScale = (FLOAT)(m_lfCellsize/m_fResolution*1000);
		return S_OK;
	}
	return S_FALSE;
}


STDMETHODIMP CImageDriver::SetScale(FLOAT Scale)
{
	// TODO: Add your implementation code here

	return S_FALSE;
}


STDMETHODIMP CImageDriver::GetGrdInfo(DOUBLE* xStart, DOUBLE* yStart, DOUBLE* cellSize)
{
	// TODO: Add your implementation code here
	*xStart = m_lfxStart;
	*yStart = m_lfyStart;
	*cellSize = m_lfCellsize;
	return S_OK;
}


STDMETHODIMP CImageDriver::SetGrdInfo(DOUBLE xStart, DOUBLE yStart, DOUBLE cellSize)
{
	// TODO: Add your implementation code here
	m_lfxStart = xStart;
	m_lfyStart = yStart;
	m_lfCellsize = cellSize;
	m_pGeoTrans[0] = xStart;
	m_pGeoTrans[3] = yStart + m_nHeight*cellSize;
	m_pGeoTrans[1] = cellSize;
	m_pGeoTrans[5] = 0.0-cellSize;
	m_pGeoTrans[2] = m_pGeoTrans[4] = 0;
	if(CE_Failure == m_poDataset->SetGeoTransform(m_pGeoTrans))
	{
		return S_FALSE;
	}
	CString strTFW = m_strPathName.Left(m_strPathName.ReverseFind('.'))+_T(".tfw");
	CString strExt = m_strPathName.Right(m_strPathName.GetLength()-m_strPathName.ReverseFind('.')-1);
	if (strExt.CompareNoCase("tiff") == 0 || strExt.CompareNoCase("tif") == 0)
	{
		fstream outfile;
		outfile.open(strTFW.LockBuffer(), ios::out);
		char *temp = new char[50];
		memset(temp, 0, 50*sizeof(char));
		sprintf(temp, "%.6f\n", m_lfCellsize);
		outfile<<temp;
		sprintf(temp, "%.6f\n", 0.0);
		outfile<<temp;
		sprintf(temp, "%.6f\n", 0.0);
		outfile<<temp;
		sprintf(temp, "%.6f\n", -m_lfCellsize);
		outfile<<temp;
		sprintf(temp, "%.6f\n", m_lfxStart);
		outfile<<temp;
		sprintf(temp, "%.6f\n", m_pGeoTrans[3]);
		outfile<<temp;
		outfile.clear();
		outfile.close();
		delete []temp;
		temp = NULL;
	}
	return S_OK;
}


STDMETHODIMP CImageDriver::HaveColorTable(void)
{
	// TODO: Add your implementation code here
	if (m_poDataset->GetRasterBand(1)->GetColorTable() == NULL)
	{
		return S_FALSE;
	}
	return S_OK;
}


STDMETHODIMP CImageDriver::GetEntryNum(int* pEntryNum)
{
	// TODO: Add your implementation code here
	if (m_poDataset->GetRasterBand(1)->GetColorTable() == NULL)
	{
		return S_FALSE;
	}
	*pEntryNum = m_poDataset->GetRasterBand(1)->GetColorTable()->GetColorEntryCount();
	return S_OK;
}


STDMETHODIMP CImageDriver::GetColorTable(BYTE* pColorTable)
{
	// TODO: Add your implementation code here

	return S_FALSE;
}


STDMETHODIMP CImageDriver::SetColorTable(BYTE* pColorTable, int nEntryNum)
{
	// TODO: Add your implementation code here

	return S_FALSE;
}


STDMETHODIMP CImageDriver::GetResampleMethod(int* pResampleMethod)
{
	// TODO: Add your implementation code here
	*pResampleMethod = m_nResampleMethod;
	return S_OK;
}


STDMETHODIMP CImageDriver::SetResampleMethod(int nResampleMethod)
{
	// TODO: Add your implementation code here
	m_nResampleMethod = nResampleMethod;
	return S_OK;
}


STDMETHODIMP CImageDriver::GetScanSize(FLOAT* pScanSize)
{
	// TODO: Add your implementation code here
	*pScanSize = (FLOAT)(1.0/m_fXResolution);
	return S_OK;
}


STDMETHODIMP CImageDriver::SetScanSize(FLOAT ScanSize)
{
	// TODO: Add your implementation code here

	return S_FALSE;
}


STDMETHODIMP CImageDriver::GetBPB(int* pBPB)
{
	// TODO: Add your implementation code here
	*pBPB = m_nBPB;
	return S_OK;
}


STDMETHODIMP CImageDriver::GetBPP(int* pBPP)
{
	// TODO: Add your implementation code here
	*pBPP = m_nBPP;
	return S_OK;
}


STDMETHODIMP CImageDriver::GetPathName(BSTR* bstrPathName)
{
	// TODO: Add your implementation code here
	*bstrPathName = (_bstr_t)m_strPathName;
	return S_OK;
}


STDMETHODIMP CImageDriver::GetPixel(int nRows, int nCols, BYTE* pPixel)
{
	// TODO: Add your implementation code here
	if (nRows < 0 || nCols < 0 || nRows >= m_nHeight || nCols >= m_nWidth)
	{
		memset(pPixel,0,m_nBPP);
		return S_FALSE;
	}
	BYTE* pTmpPixel = (BYTE*)calloc(m_nBandNum,m_nBytesPerBand);
	m_poDataset->RasterIO(GF_Read, nCols, nRows, 1, 1, pTmpPixel, 1, 1, m_eGDALType, m_nBandNum, NULL, 0, 0, 0);
	memcpy(pPixel,pTmpPixel,m_nBandNum*m_nBytesPerBand*sizeof(BYTE));
	free( pTmpPixel );
	pTmpPixel = NULL;
	return S_OK;
}


STDMETHODIMP CImageDriver::SetPixel(int nRows, int nCols, BYTE* pPixel)
{
	// TODO: Add your implementation code here
	m_poDataset->RasterIO(GF_Write, nCols, nRows, 1, 1, pPixel, 1, 1, m_eGDALType, m_nBandNum, NULL, 0, 0, 0);
	return S_OK;
}


STDMETHODIMP CImageDriver::GetGray(int nRows, int nCols, int nBand, BYTE* gray)
{
	// TODO: Add your implementation code here
	BYTE *pTmpData = new BYTE[m_nBPB];
	memset( pTmpData, 0, m_nBPB);
	m_poDataset->GetRasterBand(nBand+1)->RasterIO(GF_Read,nCols,nRows,1,1,pTmpData,1,1,m_eGDALType,0,0);
	memcpy( gray, pTmpData, m_nBPB);
	delete[] pTmpData;
	pTmpData = NULL;
	return S_OK;
}


STDMETHODIMP CImageDriver::SetGray(int nRows, int nCols, int nBand, BYTE* gray)
{
	// TODO: Add your implementation code here
	m_poDataset->GetRasterBand(nBand+1)->RasterIO(GF_Read,nCols,nRows,1,1,gray,1,1,m_eGDALType,0,0);
	return S_OK;
}


STDMETHODIMP CImageDriver::GetPixelF(FLOAT x, FLOAT y, BYTE* pPixel, UINT nResampleMethod)
{
	// TODO: Add your implementation code here
	int nCols = m_nWidth;
	int nRows = m_nHeight;
	if (nResampleMethod == 0)
	{
		int nCol, nRow;
		nCol = int(x + 0.5);
		nRow = int(y + 0.5);
		if (nCol >= 0 && nCol < nCols && nRow >= 0 && nRow < nRows)
		{
			GetPixel(nRow, nCol, pPixel);
		}
	}
	else
	{
		int nCol1, nRow1, nCol2, nRow2;
		float fx, fy;
		static BYTE pBuf11[512], pBuf12[512], pBuf21[512], pBuf22[512], pBufDest[512];

		nCol1 = int(x);
		nRow1 = int(y);
		nCol2 = nCol1 + 1;
		nRow2 = nRow1 + 1;

		nCol2 = min(nCol2,nCols-1);
		nRow2 = min(nRow2,nRows-1);

		fx = x - nCol1;
		fy = y - nRow1;

		if (nRow1 >= 0 && nRow1 < nRows && nCol1 >= 0 && nCol1 < nCols)
		{
			GetPixel(nRow1,nCol1,pBuf11);
			GetPixel(nRow1,nCol2,pBuf21);
			GetPixel(nRow2,nCol1,pBuf12);
			GetPixel(nRow2,nCol2,pBuf22);

			for ( int i = 0; i < m_nBandNum; i++ )
			{
				(*FuncTable_img[m_nDataType])(pBuf11+m_nBPB*i,
					pBuf21+m_nBPB*i,pBuf22+m_nBPB*i,pBuf12+m_nBPB*i,fx,fy,pPixel+m_nBPB*i);
			}
		}
	}
	return S_OK;
}


STDMETHODIMP CImageDriver::GetGrayF(FLOAT x, FLOAT y, int nBand, BYTE* pGray, int nResampleMethod)
{
	// TODO: Add your implementation code here
	int nCols = m_nWidth;
	int nRows = m_nHeight;
	if (nResampleMethod == 0)
	{
		int nCol, nRow;
		nCol = int(x+0.5);
		nRow = int(y+0.5);

		if (nRow >= 0 && nRow < nRows && nCol >=0 && nCol < nCols)
		{
			GetGray(nRow,nCol,nBand,pGray);
		}
	}
	else
	{
		int nCol1, nRow1, nCol2, nRow2;
		float fx, fy;

		static BYTE pBuf11[512], pBuf12[512], pBuf22[512], pBuf21[512], pBufDest[512];

		nCol1 = int(x);
		nRow1 = int(y);
		nCol2 = int(x+0.5);
		nRow2 = int(y+0.5);

		nCol2 = min(nCol2,nCols-1);
		nRow2 = min(nRow2,nRows-1);

		fx = x - nCol1;
		fy = y - nRow1;

		if (nCol1 >= 0 && nCol1 < nCols && nRow1 >= 0 && nRow1 < nRows)
		{
			GetGray(nRow1,nCol1,nBand,pBuf11);
			GetGray(nRow1,nCol2,nBand,pBuf21);
			GetGray(nRow2,nCol1,nBand,pBuf12);
			GetGray(nRow2,nCol2,nBand,pBuf22);

			(*FuncTable_img[m_nDataType])(pBuf11,pBuf21,pBuf22,pBuf12,fx,fy,pGray);
		}
	}
	return S_OK;
}


STDMETHODIMP CImageDriver::ReadImg(int nSrcLeft, int nSrcTop, int nSrcRight, int nSrcBottom, 
									BYTE* pBuf, int nBufWid, int nBufHeight, int nBandNum, 
									int nDestLeft, int nDestTop, int nDestRight, int nDestBottom, 
									int nSrcSkip, int nDestSkip)
{
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
		nEndColOffset = m_nWidth - nSrcRight;
	}
	if (nSrcBottom > m_nHeight)
	{
		nEndRowOffset = m_nHeight - nSrcBottom;
	}

	nSrcLeft += nStartColOffset;
	nSrcRight += nEndColOffset;
	nSrcTop += nStartRowOffset;
	nSrcBottom += nEndRowOffset;

	nDestLeft += nStartColOffset;
	nDestRight += nEndColOffset;
	nDestTop += nStartRowOffset;
	nDestBottom += nEndRowOffset;

	if (nDestSkip > nBandNum - 1)
	{
		return S_FALSE;
	}

	if (nSrcSkip == -1)
	{
		if (nBandNum != m_nBandNum)
		{
			return S_FALSE;
		}

		int *bandmap = new int[nBandNum];
		for (int i = 0; i < nBandNum; ++i)
		{
			bandmap[i] = i + 1;
		}
		if (!m_bTranto8bit)
		{
			m_poDataset->RasterIO(GF_Read, nSrcLeft, m_nHeight - nSrcBottom, nSrcRight - nSrcLeft, nSrcBottom - nSrcTop,
				pBuf + (nDestBottom - 1) * nBufWid * m_nBPP + nDestLeft * m_nBPP, nDestRight - nDestLeft, nDestBottom - nDestTop, m_eGDALType, nBandNum, bandmap,
				m_nBPP, -m_nBPP * nBufWid, m_nBPB);
		}
		else
		{
			BYTE *temBuf = new BYTE[m_nOldBytesPerBand*m_nBandNum*nBufHeight*nBufWid];
			m_poDataset->RasterIO(GF_Read, nSrcLeft, m_nHeight - nSrcBottom, nSrcRight - nSrcLeft, nSrcBottom - nSrcTop,
				temBuf + (nDestBottom - 1) * nBufWid * m_nOldBytesPerBand*nBandNum + nDestLeft * m_nOldBytesPerBand*nBandNum, nDestRight - nDestLeft, nDestBottom - nDestTop, m_eGDALType, nBandNum, bandmap,
				m_nOldBytesPerBand*nBandNum, -m_nOldBytesPerBand*nBandNum * nBufWid, m_nOldBytesPerBand*nBandNum);
			switch(m_nDataType)
			{
			case Pixel_Int16:
				{
					unsigned short* pp = (unsigned short*)temBuf;
					for (int j = nDestTop; j < nDestBottom;++j)
					{
						for (int i = nDestLeft; i < nDestRight; ++i)
						{
							for (int nb = 0; nb < nBandNum; ++nb)
							{
								pBuf[j*nBufWid*nBandNum+i*nBandNum+nb] = m_plut[nb*65536+pp[j*nBufWid*nBandNum+i*nBandNum+nb]];
							}
						}
					}
					break;
				}
			case Pixel_SInt16:
				{
					short* pp = (short*)temBuf;
					for (int j = nDestTop; j < nDestBottom;++j)
					{
						for (int i = nDestLeft; i < nDestRight; ++i)
						{
							for (int nb = 0; nb < m_nBandNum; ++nb)
							{
								pBuf[j*nBufWid*nBandNum+i*nBandNum+nb] = m_plut[nb*65536+pp[j*nBufWid*nBandNum+i*nBandNum+nb]];
							}
						}
					}
					break;
				}
			}
			delete []temBuf;
			temBuf = NULL;
		}

		delete [] bandmap;
		bandmap = NULL;
	}
	else
	{
		if (!m_bTranto8bit)
		{
			m_poDataset->GetRasterBand(nSrcSkip+1)->RasterIO(GF_Read, nSrcLeft, m_nHeight - nSrcBottom, nSrcRight - nSrcLeft, nSrcBottom - nSrcTop,
				pBuf + (nDestBottom - 1) * nBufWid * nBandNum* m_nBPB + nDestLeft * nBandNum * m_nBPB + nDestSkip * m_nBPB, nDestRight - nDestLeft, nDestBottom - nDestTop, m_eGDALType, 
				nBandNum * m_nBPB, -nBandNum * m_nBPB * nBufWid);
		}
		else
		{
			BYTE *temBuf = new BYTE[m_nOldBytesPerBand*nBufHeight*nBufWid];
			m_poDataset->GetRasterBand(nSrcSkip+1)->RasterIO(GF_Read, nSrcLeft, m_nHeight - nSrcBottom, nSrcRight - nSrcLeft, nSrcBottom - nSrcTop,
				temBuf + (nDestBottom - 1) * nBufWid * m_nOldBytesPerBand + nDestLeft * m_nOldBytesPerBand, nDestRight - nDestLeft, nDestBottom - nDestTop, m_eGDALType, 
				m_nOldBytesPerBand, -m_nOldBytesPerBand * nBufWid);
			switch(m_nDataType)
			{
			case Pixel_Int16:
				{
					unsigned short* pp = (unsigned short*)temBuf;
					for (int j = nDestTop; j < nDestBottom; ++j)
					{
						for(int i = nDestLeft; i < nDestRight; ++i)
						{
							pBuf[j*nBufWid*nBandNum+i*nBandNum+nDestSkip] = m_plut[nSrcSkip*65536+pp[j*nBufWid+i]];
						}
					}
					break;
				}
			case Pixel_SInt16:
				{
					short* pp = (short*)temBuf;
					for (int j = nDestTop; j < nDestBottom; ++j)
					{
						for(int i = nDestLeft; i < nDestRight; ++i)
						{
							pBuf[j*nBufWid*nBandNum+i*nBandNum+nDestSkip] = m_plut[nSrcSkip*65536+pp[j*nBufWid+i]];
						}
					}
					break;
				}
			}
			delete []temBuf;
			temBuf = NULL;
		}
	}
	return S_OK;
}


STDMETHODIMP CImageDriver::WriteImg(int nSrcLeft, int nSrcTop, int nSrcRight, int nSrcBottom, 
									BYTE* pBuf, int nBufWid, int nBufHeight, int nBandNum, 
									int nDestLeft, int nDestTop, int nDestRight, int nDestBottom, 
									int nSrcSkip, int nDestSkip)
{
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
		nEndColOffset = m_nWidth - nSrcRight;
	}
	if (nSrcBottom > m_nHeight)
	{
		nEndRowOffset = m_nHeight - nSrcBottom;
	}

	nSrcLeft += nStartColOffset;
	nSrcRight += nEndColOffset;
	nSrcTop += nStartRowOffset;
	nSrcBottom += nEndRowOffset;

	nDestLeft += nStartColOffset;
	nDestRight += nEndColOffset;
	nDestTop += nStartRowOffset;
	nDestBottom += nEndRowOffset;

	if (nDestSkip > nBandNum - 1)
	{
		return S_FALSE;
	}
	if (nSrcSkip == -1)
	{
		if (nBandNum != m_nBandNum)
		{
			return S_FALSE;
		}

		int *bandmap = new int[nBandNum];
		for (int i = 0; i < nBandNum; ++i)
		{
			bandmap[i] = i+1;
		}

		m_poDataset->RasterIO(GF_Write, nSrcLeft, m_nHeight - nSrcBottom, nSrcRight - nSrcLeft, nSrcBottom - nSrcTop,
			pBuf + (nDestBottom - 1) * nBufWid * m_nBPP + nDestLeft * m_nBPP, nDestRight - nDestLeft, nDestBottom - nDestTop, m_eGDALType, nBandNum, bandmap,
			m_nBPP, -m_nBPP * nBufWid, m_nBPB);

		delete [] bandmap;
		bandmap = NULL;

	}
	else
	{
		m_poDataset->GetRasterBand(nSrcSkip+1)->RasterIO(GF_Write, nSrcLeft, m_nHeight-nSrcBottom, nSrcRight-nSrcLeft, nSrcBottom-nSrcTop,
			pBuf + (nDestBottom - 1) * nBufWid * nBandNum * m_nBPB + nDestLeft * nBandNum * m_nBPB+nDestSkip*m_nBPB, nDestRight-nDestLeft, nDestBottom-nDestTop, m_eGDALType, 
			nBandNum*m_nBPB, -nBandNum*m_nBPB*nBufWid);
	}
	return S_OK;
}


STDMETHODIMP CImageDriver::SetProgressInterface(IUnknown* pIUnknown)
{
	// TODO: Add your implementation code here

	return S_FALSE;
}


STDMETHODIMP CImageDriver::GetSupExts(BYTE* lpszExts, UINT flags)
{
	// TODO: Add your implementation code here
	strcpy((char*)lpszExts, "Tiff file(*.tif;*.tiff)|*.tif;*.tiff|Ecw file(*.ecw)|*.ecw|Erdas file(*.img)|*.img|Hdr file(*.hdr)|*.hdr|Jpeg file(*.jpeg;*.jpg)|*.jpeg;*.jpg|Nitf file(*.ntf)|*.ntf|Bitmap file(*.bmp)|*.bmp|All file(*.*)|*.*||");
	return S_OK;
}


STDMETHODIMP CImageDriver::Image2World(FLOAT x, FLOAT y, DOUBLE* pX, DOUBLE* pY)
{
	// TODO: Add your implementation code here
	*pX = DOUBLE(x) * m_lfCellsize + m_lfxStart;
	*pY = DOUBLE(y) * m_lfCellsize + m_lfyStart;
	return S_OK;
}


STDMETHODIMP CImageDriver::World2Image(DOUBLE X, DOUBLE Y, FLOAT* px, FLOAT* py)
{
	// TODO: Add your implementation code here
	*px = FLOAT((X-m_lfxStart)/m_lfCellsize);
	*py = FLOAT((Y-m_lfyStart)/m_lfCellsize);
	return S_OK;
}


STDMETHODIMP CImageDriver::GetDefaultBand(int* nBandIndex)
{
	// TODO: Add your implementation code here
	if (nBandIndex)
	{
		if ( m_nBandNum >= 3 )
		{
			nBandIndex[0] = 2;
			nBandIndex[1] = 1;
			nBandIndex[2] = 0;
		}
		else
		{
			nBandIndex[0] = 0;
			nBandIndex[1] = 0;
			nBandIndex[2] = 0;
		}
		return S_OK;
	}
	return S_FALSE;
}


STDMETHODIMP CImageDriver::GetCamera(BSTR* bstrCamera)
{
	// TODO: Add your implementation code here
	_bstr_t bstrtCameraName = "";
	*bstrCamera = bstrtCameraName;
	return S_OK;
}


STDMETHODIMP CImageDriver::SetCamera(BSTR bstrCamera)
{
	// TODO: Add your implementation code here

	return S_FALSE;
}


STDMETHODIMP CImageDriver::GetSensorType(int* pSensorType)
{
	// TODO: Add your implementation code here
	*pSensorType = -1;
	return S_OK;
}


STDMETHODIMP CImageDriver::SetSensorType(int nSensorType)
{
	// TODO: Add your implementation code here

	return S_FALSE;
}


STDMETHODIMP CImageDriver::GetDPI(FLOAT* pxDPI, FLOAT* pyDPI)
{
	// TODO: Add your implementation code here
	*pxDPI = m_fxDPI;
	*pyDPI = m_fyDPI;
	return S_OK;
}


STDMETHODIMP CImageDriver::SetDPI(FLOAT xDPI, FLOAT yDPI)
{
	// TODO: Add your implementation code here
	char **pszMetadata = m_poDataset->GetMetadata();
	char *p = new char[20];
	sprintf(p, "%s", "2 (pixels/inch)");
	pszMetadata = CSLSetNameValue(pszMetadata, "TIFFTAG_RESOLUTIONUNIT", p);
	char *xdpi = new char[20];
	sprintf(xdpi, "%f", xDPI);
	pszMetadata = CSLSetNameValue(pszMetadata, "TIFFTAG_XRESOLUTION", xdpi);
	char *ydpi = new char[20];
	sprintf(ydpi, "%f", yDPI);
	pszMetadata = CSLSetNameValue(pszMetadata, "TIFFTAG_YRESOLUTION", ydpi);
	m_poDataset->SetMetadata(pszMetadata);
	delete []p;
	delete []xdpi;
	delete []ydpi;
	p = NULL;
	xdpi = NULL;
	ydpi = NULL;
	return S_OK;
}


STDMETHODIMP CImageDriver::Tiff2JPG(BSTR bstrTiffPath, BSTR bstrJPGPath)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	GDALAllRegister();
	// TODO: Add your implementation code here
	_bstr_t bstrTiffName = bstrTiffPath;
	_bstr_t bstrJPGName = bstrJPGPath;
	CString strTiffPath = bstrTiffName;
	CString strJPGPath = bstrJPGName;
	m_poDataset  = (GDALDataset*)GDALOpen( strTiffPath, GA_ReadOnly);
	GDALDriver* tempoDriver = GetGDALDriverManager()->GetDriverByName("JPEG");
	GDALDataset* tempoDataset = tempoDriver->CreateCopy(strJPGPath, m_poDataset, TRUE, NULL, NULL, NULL);
	GDALClose((GDALDatasetH)tempoDataset);
	return S_OK;
}
