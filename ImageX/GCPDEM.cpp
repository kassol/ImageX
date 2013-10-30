#include "StdAfx.h"
#include "GCPDEM.h"

#import "ImageX.tlb" no_namespace named_guids


HRESULT CGCPDEM::Open(BSTR bstrPathName, double lfAltitudeOffset, UINT accMode)
{
	return S_FALSE;
}

HRESULT CGCPDEM::Close()
{
	m_strGcpFile="";
	CBaseDEM::DestoryTIN();

	return S_OK;
}

HRESULT CGCPDEM::GetSupExts(BYTE* lpszExts, UINT accMode)
{
	strcpy((char*)lpszExts,"");

	return S_FALSE;
}

HRESULT CGCPDEM::GetSupFormats(BYTE* lpszFormats, UINT accMode)
{
	strcpy((char*)lpszFormats,"");

	return S_FALSE;
}

HRESULT CGCPDEM::GetIImage(IImage** ppIImage)
{
	return S_FALSE;
}

HRESULT CGCPDEM::GetVertex(double* pX, double* pY, double* pZ, int* pVertexNum)
{
	return S_FALSE;
}

HRESULT CGCPDEM::GetTriangle(int nTriIndex, double* pX, double* pY, double* pZ)
{
	return CBaseDEM::GetTriangleB(nTriIndex,pX,pY,pZ)==TRUE?S_OK:S_FALSE;
}

HRESULT CGCPDEM::GetTriangleNum(int* pTriangleNum)
{
	*pTriangleNum=CBaseDEM::GetTriangleNum();

	return S_OK;
}

HRESULT CGCPDEM::ConstrustTIN()
{
	//在创建时已经构造三角网，此处直接返回

	return S_OK;
}

HRESULT CGCPDEM::GetAverageAltitude(double* pZ)
{
	*pZ=m_AveAltitude;

	return S_OK;
}

HRESULT CGCPDEM::GetAltitude(double X, double Y, double* pZ, UINT uResampleMethod)
{
	if(X<m_X0||X>m_X2||Y<m_Y0||Y>m_Y2)
	{
		*pZ=INVALID_ALTITUDE;//m_AveAltitude

		return S_FALSE;
	}

	for(int i=0;i<mid.numOfTriangles;i++)
	{
		double triX[3],triY[3],triZ[3];
		for(int j=0;j<3;j++)
		{
			triX[j]=mid.pointList[mid.triList[i*3+j]*2+0];
			triY[j]=mid.pointList[mid.triList[i*3+j]*2+1];
			triZ[j]=mid.pointAttrList[mid.triList[i*3+j]];
		}

		double dx01=triX[1]-triX[0];
		double dy01=triY[1]-triY[0];
		double dx12=triX[2]-triX[1];
		double dy12=triY[2]-triY[1];
		double dx20=triX[0]-triX[2];
		double dy20=triY[0]-triY[2];
		double dx1=X-triX[1];
		double dy1=Y-triY[1];
		double dx2=X-triX[2];
		double dy2=Y-triY[2];
		double dx0=X-triX[0];
		double dy0=Y-triY[0];

		if(((dx01*dy1-dx1*dy01)>=0&&(dx12*dy2-dx2*dy12)>=0&&(dx20*dy0-dx0*dy20)>=0)||
			((dx01*dy1-dx1*dy01)<=0&&(dx12*dy2-dx2*dy12)<=0&&(dx20*dy0-dx0*dy20)<=0))
		{
			double vx01=triX[1]-triX[0];
			double vy01=triY[1]-triY[0];
			double vz01=triZ[1]-triZ[0];

			double vx02=triX[2]-triX[0];
			double vy02=triY[2]-triY[0];
			double vz02=triZ[2]-triZ[0];

			double vx=vy01*vz02-vz01*vy02;
			double vy=vz01*vx02-vx01*vz02;
			double vz=vx01*vy02-vy01*vx02;
			double mod=sqrt(vx*vx+vy*vy+vz*vz);
			double a=vx/mod;
			double b=vy/mod;
			double c=vz/mod;
			double d=-(a*triX[0]+b*triY[0]+c*triZ[0]);
			*pZ=-(a*X+b*Y+d)/c;


			return S_OK;
		}
	}

	return S_FALSE;
}

HRESULT CGCPDEM::GetTIN(DWORD ppTriangulateio)
{
	return CBaseDEM::GetTINB(ppTriangulateio)==TRUE?S_OK:S_FALSE;
}

HRESULT CGCPDEM::GetRange(double* pLBX, double* pLBY, double* pRTX, double* pRTY)
{
	return S_FALSE;
}

HRESULT CGCPDEM::CreateGCPDEM(BSTR bstrGcpFile)
{
	m_strGcpFile=CString(bstrGcpFile);
	if(m_strGcpFile.IsEmpty())
	{
		CString strMsg;
		strMsg.Format(IDS_FILE_OPEN_FAILED,m_strGcpFile);
		AfxMessageBox(strMsg);

		return S_FALSE;
	}

	FILE* fp=fopen(m_strGcpFile,"rt");
	if(fp==NULL)
	{
		CString strMsg;
		strMsg.Format(IDS_FILE_OPEN_FAILED,m_strGcpFile);
		AfxMessageBox(strMsg);

		return S_FALSE;
	}

	int nGcpNum=0;
	if(fscanf(fp,"%d",&nGcpNum)!=1)
	{
		CString strMsg;
		strMsg.Format(IDS_GCP_FILE_ERROR,m_strGcpFile);
		AfxMessageBox(strMsg);

		fclose(fp);
		fp=NULL;

		return S_FALSE;
	}
	if(nGcpNum<3)
	{
		CString strMsg;
		strMsg.Format(IDS_GCP_FILE_ERROR,m_strGcpFile);
		AfxMessageBox(strMsg);

		fclose(fp);
		fp=NULL;

		return S_FALSE;
	}

	char szGcpID[30];
	double* X=new double[nGcpNum+4];
	double* Y=new double[nGcpNum+4];
	double* Z=new double[nGcpNum+4];

	if(fscanf(fp,"%s%lf%lf%lf",szGcpID,&X[0],&Y[0],&Z[0])!=4)
	{
		CString strMsg;
		strMsg.Format(IDS_GCP_FILE_ERROR,m_strGcpFile);
		AfxMessageBox(strMsg);

		fclose(fp);
		fp=NULL;

		return S_FALSE;
	}
	double minX=X[0],minY=Y[0],maxX=X[0],maxY=Y[0],minZ=Z[0],maxZ=Z[0];
	double sumZ=0.0;
	for(int i=1;i<nGcpNum;i++)
	{
		if(fscanf(fp,"%s%lf%lf%lf",szGcpID,&X[i],&Y[i],&Z[i])!=4)
		{
			CString strMsg;
			strMsg.Format(IDS_GCP_FILE_ERROR,m_strGcpFile);
			AfxMessageBox(strMsg);

			fclose(fp);
			fp=NULL;

			return S_FALSE;
		}
		if(X[i]<minX)
		{
			minX=X[i];
		}
		if(X[i]>maxX)
		{
			maxX=X[i];
		}
		if(Y[i]<minY)
		{
			minY=Y[i];
		}
		if(Y[i]>maxY)
		{
			maxY=Y[i];
		}
		if(Z[i]<minZ)
		{
			minZ=Z[i];
		}
		if(Z[i]>maxZ)
		{
			maxZ=Z[i];
		}
		sumZ+=Z[i];
	}

	m_AveAltitude=sumZ/nGcpNum;
	m_MaxAltitude=maxZ;
	m_MinAltitude=minZ;
	m_X0=minX;
	m_Y0=minY;
	m_X2=maxX;
	m_Y2=maxY;
	/*X[nGcpNum+0]=m_X0;
	Y[nGcpNum+0]=m_Y0;
	Z[nGcpNum+0]=m_AveAltitude;
	X[nGcpNum+1]=m_X2;
	Y[nGcpNum+1]=m_Y0;
	Z[nGcpNum+1]=m_AveAltitude;
	X[nGcpNum+2]=m_X2;
	Y[nGcpNum+2]=m_Y2;
	Z[nGcpNum+2]=m_AveAltitude;
	X[nGcpNum+3]=m_X0;
	Y[nGcpNum+3]=m_Y2;
	Z[nGcpNum+3]=m_AveAltitude;
	*/
	CBaseDEM::ContrustTIN(X,Y,Z,nGcpNum/*+4*/);

	delete [] X; X=NULL;
	delete [] Y; Y=NULL;
	delete [] Z; Z=NULL;

	return S_OK;
}

HRESULT CGCPDEM::SetRange(double LBX,double LBY,double RTX,double RTY)
{
	int nGcpNum=mid.numOfPoints;
	double* X=new double[nGcpNum+4];
	double* Y=new double[nGcpNum+4];
	double* Z=new double[nGcpNum+4];

	for(int i=0;i<nGcpNum;i++)
	{
		X[i]=mid.pointList[i*2+0];
		Y[i]=mid.pointList[i*2+1];
		Z[i]=mid.pointAttrList[i];
	}

	if(LBX<m_X0||LBY<m_Y0)
	{
		X[nGcpNum]=LBX;
		Y[nGcpNum]=LBY;
		Z[nGcpNum]=m_AveAltitude;

		nGcpNum++;
	}
	if(RTX>m_X2||LBY<m_Y0)
	{
		X[nGcpNum]=RTX;
		Y[nGcpNum]=LBY;
		Z[nGcpNum]=m_AveAltitude;

		nGcpNum++;
	}
	if(RTX>m_X2||RTY>m_Y2)
	{
		X[nGcpNum]=RTX;
		Y[nGcpNum]=RTY;
		Z[nGcpNum]=m_AveAltitude;

		nGcpNum++;
	}
	if(LBX<m_X0||RTY>m_Y2)
	{
		X[nGcpNum]=LBX;
		Y[nGcpNum]=RTY;
		Z[nGcpNum]=m_AveAltitude;

		nGcpNum++;
	}

	m_X0=LBX;
	m_Y0=LBY;
	m_X2=RTX;
	m_Y2=RTY;

	CBaseDEM::ContrustTIN(X,Y,Z,nGcpNum);

	delete [] X; X=NULL;
	delete [] Y; Y=NULL;
	delete [] Z; Z=NULL;

	return S_OK;
}

HRESULT CGCPDEM::GetMaxAltitude(double* pZ)
{
	*pZ=m_MaxAltitude;

	return S_OK;
}

HRESULT CGCPDEM::GetMinAltitude(double* pZ)
{
	*pZ=m_MinAltitude;

	return S_OK;
}

HRESULT CGCPDEM::GetType(UINT* pType)
{
	*pType=DT_TIN;

	return S_OK;
}

HRESULT CGCPDEM::GetRows(int* pRows)
{
	return S_FALSE;
}

HRESULT CGCPDEM::GetCols(int* pCols)
{
	return S_FALSE;
}

HRESULT CGCPDEM::GetStartPos(double* pX0, double* pY0)
{
	return S_FALSE;
}

HRESULT CGCPDEM::GetAltitudeValues(double* pZ)
{
	return S_FALSE;
}

HRESULT CGCPDEM::IsSupported(BSTR bstrPathName, UINT accMode)
{
	return S_FALSE;
}



