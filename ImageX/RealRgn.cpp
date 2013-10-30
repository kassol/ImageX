 // RealRgn.cpp: implementation of the CRealRgn class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "RealRgn.h"
#include <math.h>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CRealRgn::CRealRgn()
{
	m_pX=NULL;
	m_pY=NULL;
	m_pZ=NULL;
	m_bVertex=NULL;
	m_VertexState=NULL;
	m_nDirection = -1;
}

CRealRgn::~CRealRgn()
{
	if(m_pX) delete [] m_pX;
	if(m_pY) delete [] m_pY;
	if(m_pZ) delete [] m_pZ;
	if(m_bVertex) delete [] m_bVertex;
	if(m_VertexState) delete [] m_VertexState;
}

void CRealRgn::DestoryMe()
{
	if(m_pX)
	{
		delete [] m_pX;
		m_pX=NULL;
	}
	if(m_pY)
	{
		delete [] m_pY;
		m_pY=NULL;
	}
	if(m_pZ)
	{
		delete [] m_pZ;
		m_pZ=NULL;
	}
	if(m_bVertex)
	{
		delete [] m_bVertex;
		m_bVertex=NULL;
	}
	if(m_VertexState)
	{
		delete [] m_VertexState;
		m_VertexState=NULL;
	}
}

bool CRealRgn::CreatePolygonRgn(double* pX,double* pY,int nCount,BOOL bAutoAntiClock)
{
	if(nCount<=0||pX==NULL||pY==NULL)
		return false;

	if(m_pX) delete [] m_pX;
	if(m_pY) delete [] m_pY;
	if(m_bVertex) delete [] m_bVertex;

	m_nBufferSize=nCount;
	m_pX=new double[m_nBufferSize+1];
	m_pY=new double[m_nBufferSize+1];
	m_bVertex=new bool[m_nBufferSize+1];
	ASSERT(m_pX!=NULL);
	ASSERT(m_pY!=NULL);
	ASSERT(m_bVertex!=NULL);

	memcpy(m_pX,pX,sizeof(double)*nCount);
	memcpy(m_pY,pY,sizeof(double)*nCount);
	m_pX[m_nBufferSize]=pX[0];
	m_pY[m_nBufferSize]=pY[0];

	m_Box.left=pX[0];
	m_Box.bottom=pY[0];
	m_Box.right=pX[0];
	m_Box.top=pY[0];
	for(int i=1;i<m_nBufferSize;i++)
	{
		if(m_pX[i]>m_Box.right) m_Box.right=m_pX[i];
		else if(m_pX[i]<m_Box.left) m_Box.left=m_pX[i];
		if(m_pY[i]>m_Box.top) m_Box.top=m_pY[i];
		else if(m_pY[i]<m_Box.bottom) m_Box.bottom=m_pY[i];
	}
	
	InitVertexState();
	//自动调整为逆时针顺序
	if(bAutoAntiClock)
	{
		if(GetRgnDirection()!=1)
		{
			for(int i=0;i<m_nBufferSize/2;i++)
			{
				double tempX=m_pX[i];
				double tempY=m_pY[i];
				m_pX[i]=m_pX[m_nBufferSize-1-i];
				m_pY[i]=m_pY[m_nBufferSize-1-i];
				m_pX[m_nBufferSize-1-i]=tempX;
				m_pY[m_nBufferSize-1-i]=tempY;
			}
			
			m_pX[m_nBufferSize]=m_pX[0];
			m_pY[m_nBufferSize]=m_pY[0];

			InitVertexState();
		}
	}

	return true;
}
bool CRealRgn::CreatePolygonRgn(double* pX,double* pY,double* pZ,int nCount,BOOL bAutoAntiClock)
{
	if(nCount<=0||pX==NULL||pY==NULL||pZ==NULL)
		return false;

	if(m_pX) delete [] m_pX;
	if(m_pY) delete [] m_pY;
	if(m_pZ) delete [] m_pZ;
	if(m_bVertex) delete [] m_bVertex;

	m_nBufferSize=nCount;
	m_pX=new double[m_nBufferSize+1];
	m_pY=new double[m_nBufferSize+1];
	m_pZ=new double[m_nBufferSize+1];
	m_bVertex=new bool[m_nBufferSize+1];
	ASSERT(m_pX!=NULL);
	ASSERT(m_pY!=NULL);
	ASSERT(m_pZ!=NULL);
	ASSERT(m_bVertex!=NULL);

	memcpy(m_pX,pX,sizeof(double)*nCount);
	memcpy(m_pY,pY,sizeof(double)*nCount);
	memcpy(m_pZ,pZ,sizeof(double)*nCount);
	m_pX[m_nBufferSize]=pX[0];
	m_pY[m_nBufferSize]=pY[0];
	m_pZ[m_nBufferSize]=pZ[0];

	m_Box.left=pX[0];
	m_Box.bottom=pY[0];
	m_Box.right=pX[0];
	m_Box.top=pY[0];
	for(int i=1;i<m_nBufferSize;i++)
	{
		if(m_pX[i]>m_Box.right) m_Box.right=m_pX[i];
		else if(m_pX[i]<m_Box.left) m_Box.left=m_pX[i];
		if(m_pY[i]>m_Box.top) m_Box.top=m_pY[i];
		else if(m_pY[i]<m_Box.bottom) m_Box.bottom=m_pY[i];
	}
	
	InitVertexState();
	//自动调整为逆时针顺序
	if(bAutoAntiClock)
	{
		if(GetRgnDirection()!=1)
		{
			for(int i=0;i<m_nBufferSize/2;i++)
			{
				double tempX=m_pX[i];
				double tempY=m_pY[i];
				double tempZ=m_pZ[i];
				m_pX[i]=m_pX[m_nBufferSize-1-i];
				m_pY[i]=m_pY[m_nBufferSize-1-i];
				m_pZ[i]=m_pZ[m_nBufferSize-1-i];
				m_pX[m_nBufferSize-1-i]=tempX;
				m_pY[m_nBufferSize-1-i]=tempY;
				m_pZ[m_nBufferSize-1-i]=tempZ;
			}
			
			m_pX[m_nBufferSize]=m_pX[0];
			m_pY[m_nBufferSize]=m_pY[0];
			m_pZ[m_nBufferSize]=m_pZ[0];

			InitVertexState();
		}
	}

	return true;
}
bool CRealRgn::CreatePolygonRgn(RGN_REALPOINT* pRealPt,int nCount,BOOL bAutoAntiClock)
{
	if(nCount<=0||pRealPt==NULL)
		return false;

	if(m_pX) delete [] m_pX;
	if(m_pY) delete [] m_pY;
	if(m_bVertex) delete [] m_bVertex;

	m_nBufferSize=nCount;
	m_pX=new double[m_nBufferSize+1];
	m_pY=new double[m_nBufferSize+1];
	m_bVertex=new bool[m_nBufferSize+1];
	ASSERT(m_pX!=NULL);
	ASSERT(m_pY!=NULL);
	ASSERT(m_bVertex!=NULL);

	m_Box.left=pRealPt[0].x;
	m_Box.bottom=pRealPt[0].y;
	m_Box.right=pRealPt[0].x;
	m_Box.top=pRealPt[0].y;

	m_pX[0]=pRealPt[0].x;
	m_pY[0]=pRealPt[0].y;
	
	for(int i=1;i<m_nBufferSize;i++)
	{
		m_pX[i]=pRealPt[i].x;
		m_pY[i]=pRealPt[i].y;
		
		if(m_pX[i]>m_Box.right) m_Box.right=m_pX[i];
		else if(m_pX[i]<m_Box.left) m_Box.left=m_pX[i];
		if(m_pY[i]>m_Box.top) m_Box.top=m_pY[i];
		else if(m_pY[i]<m_Box.bottom) m_Box.bottom=m_pY[i];
	}
	m_pX[m_nBufferSize]=pRealPt[0].x;
	m_pY[m_nBufferSize]=pRealPt[0].y;

	InitVertexState();
	//自动调整为逆时针顺序
	if(bAutoAntiClock)
	{
		if(GetRgnDirection()!=1)
		{
			for(int i=0;i<m_nBufferSize/2;i++)
			{
				double tempX=m_pX[i];
				double tempY=m_pY[i];
				m_pX[i]=m_pX[m_nBufferSize-1-i];
				m_pY[i]=m_pY[m_nBufferSize-1-i];
				m_pX[m_nBufferSize-1-i]=tempX;
				m_pY[m_nBufferSize-1-i]=tempY;
			}
			
			m_pX[m_nBufferSize]=m_pX[0];
			m_pY[m_nBufferSize]=m_pY[0];

			InitVertexState();
		}
	}

	return true;
}

int  CRealRgn::GetRgnBox(RGN_REALRECT* pRgnBox)
{
	memcpy(pRgnBox,&m_Box,sizeof(RGN_REALRECT));
	return 0;//no error happen
}

int CRealRgn::PtInRegion(double x,double y,double snap)
{
	return IsPtInRegion(x,y,snap);
}

int CRealRgn::PtInRegion(RGN_REALPOINT point,double snap)
{
	return IsPtInRegion(point.x,point.y,snap);
}

inline int CRealRgn::Intersect(double x0,double y0,double x1,double y1,
								double x2,double y2,double x3,double y3,int ptIndex2,int ptIndex3,
								double *x,double *y,
								double minXSrc,double minYSrc,double maxXSrc,double maxYSrc,
								int nCount
								)
{
	if(x2>maxXSrc&&x3>maxXSrc)
		return 0;
	else if(x2<minXSrc&&x3<minXSrc)
		return 0;
	else if(y2>maxYSrc&&y3>maxYSrc)
		return 0;
	else if(y2<minYSrc&&y3<minYSrc)
		return 0;

	int bRet = 0;
	if( fabs(y2-y3)<ZERO_ERROR )//same height
	{
		if( fabs(y2-y1)<ZERO_ERROR )
		{
			if( fabs( x2-x1 )<ZERO_ERROR || fabs( x3-x1 )<ZERO_ERROR )
			{
				return -1;//the vertex
			}
			if( ( x2-x1<ZERO_ERROR && x3-x1>ZERO_ERROR ) || ( x2-x1>ZERO_ERROR && x3-x1<ZERO_ERROR ) )
			{
				return -1;//in the edge
			}
			if( ( x2-x1<ZERO_ERROR && x3-x1<ZERO_ERROR ) && m_VertexState[ptIndex2] )
			{
				return 1;
			}
		}
	}
	else// intersect
	{
		if( fabs(y2-y1)<ZERO_ERROR && fabs(x2-x1)<ZERO_ERROR )
		{
			if( m_VertexState[ptIndex2] )
			{
				return 1;//Second
			}
			else 
			{
				return 0;
			}
		}
		if( fabs(y3-y1)<ZERO_ERROR && fabs(x3-x1)<ZERO_ERROR )
		{
			return 1;//First
		}
		double dy21 = y2-y1;
		double dy31 = y1-y3;
		*y = y1;
		*x = (x2*dy31 + x3*dy21)/(dy31+dy21);
		if( *x<x0 || *x-x1>ZERO_ERROR )
		{
			return 0;//not in
		}
		else if(m_VertexState[ptIndex2]==false&&fabs(*x-x2)<ZERO_ERROR&&fabs(*y-y2)<ZERO_ERROR)
		{
			return 0;
		}
		return 1;
	}
	return bRet;
}

#define _SnapSame( x1, x2, lfSnap )		(0==lfSnap? x1==x2:fabs(x1-x2)<lfSnap)
#define _SnapLarge( x1, x2, lfSnap )	(x1>x2-lfSnap)
#define _SnapLarge2( x1, x2, lfSnap )	(x1>x2+lfSnap)
// x,y 点坐标
// pX,pY 多边形顶点数组
// nSum 多边形顶点数
// lfSnap 捕捉范围，用来处理栅格数据的边界
int PtInRegionEx( double x,double y, double *pX,double *pY, int nSum,double lfSnap )
{
	if( nSum<=0 || NULL==pX || NULL==pY )return FALSE;
	
	int i0,i1,i2, ret=0;
	double xmin1, xmax1, ymin1, ymax1;
	for( int i=0; i<nSum; i++ )
	{
		i0 = i;
		i1 = (i0+1)%nSum;

		// 顶点重合判断
//		if( pX[i0] == x && pY[i0] == y )
		if( _SnapSame( pX[i0],x,lfSnap ) && _SnapSame( pY[i0],y,lfSnap ) )
			return 0;

		// 判断是否存在相交的可能
		if( pX[i0]<pX[i1] ){ xmin1 = pX[i0]; xmax1 = pX[i1]; }
		else { xmin1 = pX[i1]; xmax1 = pX[i0]; }
		if( pY[i0]<pY[i1] ){ ymin1 = pY[i0]; ymax1 = pY[i1]; }
		else { ymin1 = pY[i1]; ymax1 = pY[i0]; }
//		if( y<ymin1 || y>ymax1 || x>xmax1 )continue;
		if( _SnapLarge2(ymin1,y,lfSnap) || _SnapLarge2(y,ymax1,lfSnap) || _SnapLarge2(x,xmax1,lfSnap) )
			continue;

		//判断是否在边上
		

		// 水平边界处理，只需要判断点是否在边界上
		if( pY[i1] == pY[i0] )
//		if( _SnapSame(pY[i1],pY[i0],lfSnap) )
		{
//			if( pY[i0]==y )
			if( _SnapSame(pY[i0],y,lfSnap) )
			{
//				if( ( pX[i0]>x && pX[i1]<x ) ||
//					( pX[i0]<x && pX[i1]>x ) )
				if( ( _SnapLarge(pX[i0],x,lfSnap) && _SnapLarge(x,pX[i1],lfSnap) ) ||
					( _SnapLarge(x,pX[i0],lfSnap) && _SnapLarge(pX[i1],x,lfSnap) ) )
					return 0;
			}
		}
		// 相交极限判断：只与顶点相交
		// 这里不会有点在边界上的可能
//		if( y==ymin1 || y==ymax1 )
		else if( _SnapSame(y,ymin1,lfSnap) || _SnapSame(y,ymax1,lfSnap) )
		{
			if(_SnapSame(y,ymin1,lfSnap) && _SnapSame(y,ymax1,lfSnap)&&
				(( _SnapLarge(pX[i0],x,lfSnap) && _SnapLarge(x,pX[i1],lfSnap) ) ||
					( _SnapLarge(x,pX[i0],lfSnap) && _SnapLarge(pX[i1],x,lfSnap) )))
			{
				return 0;
			}
//			if( y==pY[i0] && x<pX[i0] )
			if( _SnapSame(y,pY[i0],lfSnap) && _SnapLarge(pX[i0],x,lfSnap) )
			{
				// 判断前一个点和后一个点是否在两侧，在两侧的话ret加1
				i2 = i0;
				while( true )
				{
					i2 = (i2-1+nSum)%nSum;
					if( pY[i2] == pY[i0] )
					{
						if( i2 == i1 || i2 == i0 )break;
						continue;
					}
//					if( ( pY[i2]<y && pY[i1]>y ) ||
//						( pY[i2]>y && pY[i1]<y ) )
					if( ( _SnapLarge(y,pY[i2],lfSnap) && _SnapLarge(pY[i1],y,lfSnap) ) ||
						( _SnapLarge(pY[i2],y,lfSnap) && _SnapLarge(y,pY[i1],lfSnap) ) )
					{
						ret ++;
					}
					break;
				}
			}
		}
//		else if( x==xmin1 || x==xmax1 )
		else if( _SnapSame(x,xmin1,lfSnap) || _SnapSame(x,xmax1,lfSnap))
		{
			if(_SnapSame(x,xmin1,lfSnap) && _SnapSame(x,xmax1,lfSnap)&&
				(( _SnapLarge(y,pY[i0],lfSnap) && _SnapLarge(pY[i1],y,lfSnap) ) ||
						( _SnapLarge(pY[i0],y,lfSnap) && _SnapLarge(y,pY[i1],lfSnap) )))
			{
				return 0;
			}
//			if( x==xmin1 )
			if( _SnapSame(x,xmin1,lfSnap) )
			{
				ret ++;
			}
		}
//		if( x<xmin1 )ret++;
		else if( _SnapLarge(xmin1,x,lfSnap) )
			ret ++;
		else
		{
			xmax1 = (y-pY[i0])*(pX[i1]-pX[i0])/(pY[i1]-pY[i0])+pX[i0];
//			if( x==xmax1 )return 0;//边界上
			if( _SnapSame(x,xmax1,lfSnap) )return 0;
//			if( x<xmax1 )ret++;
			if( _SnapLarge(xmax1,x,lfSnap) )ret ++;
		}
	}
	return 1==ret%2? 1:-1;
}

int CRealRgn::IsPtInRegion(double x,double y,double snap)
{
	int nRet=PtInRegionEx(x,y,m_pX,m_pY,m_nBufferSize,snap);
	if(nRet==-1)
	{
		return 0;
	}
	else if(nRet==0)
	{
		return -1;
	}
	else
	{
		return 1;
	}

	if(m_nBufferSize<3)
	{
		return -2;
	}

	if(m_pX==NULL||m_pY==NULL)
		return 0;
	
	if(x<m_Box.left||x>m_Box.right||y<m_Box.bottom||y>m_Box.top)
		return 0;

	memcpy(m_bVertex,m_VertexState,sizeof(bool)*(m_nBufferSize+1));

	double x0=m_Box.left-1000;
	double y0=y;
	double intersectX,intersectY;

	double minXSrc,minYSrc,maxXSrc,maxYSrc;
	minXSrc=min(x0,x);
	maxXSrc=max(x0,x);
	minYSrc=min(y0,y)-ZERO_ERROR;
	maxYSrc=max(y0,y)+ZERO_ERROR;

	int nCount=0;
	for(int i=0;i<m_nBufferSize;i++)
	{
		int nRet=Intersect(x0,y0,x,y,m_pX[i],m_pY[i],m_pX[i+1],m_pY[i+1],i,i+1,&intersectX,&intersectY,minXSrc,minYSrc,maxXSrc,maxYSrc,nCount);
		if(nRet==1)
		{
			nCount++;
		}
		else if(nRet==-1)
		{
			return -1;
		}
	}
	return nCount%2;
}

bool CRealRgn::InitVertexState()
{
	if(m_VertexState) delete [] m_VertexState;
	m_VertexState=new bool[m_nBufferSize+1];
	ASSERT(m_VertexState!=NULL);

	if((m_pY[1]>m_pY[0]&&m_pY[0]>m_pY[m_nBufferSize-1])||
	   (m_pY[1]<m_pY[0]&&m_pY[0]<m_pY[m_nBufferSize-1]))
	{
		m_VertexState[0]=false;
		m_VertexState[m_nBufferSize]=false;
	}
	else
	{
		m_VertexState[0]=true;
		m_VertexState[m_nBufferSize]=true;
	}
	for(int i=1;i<m_nBufferSize;i++)
	{
		if((m_pY[i+1]>m_pY[i]&&m_pY[i]>m_pY[i-1])||(m_pY[i+1]<m_pY[i]&&m_pY[i]<m_pY[i-1]))
		{
			m_VertexState[i]=false;
		}
		else
		{
			m_VertexState[i]=true;
		}
	}

	m_nDirection = CalRgnDirection();
	return true;
}

int CRealRgn::CalRgnDirection()
{
	int nClock=0,nAntiClock=0;
	for(int i=1;i<m_nBufferSize;i++)
	{
		double dx0=m_pX[i]-m_pX[i-1];  
		double dy0=m_pY[i]-m_pY[i-1];
		double dx2=m_pX[i+1]-m_pX[i]; 
		double dy2=m_pY[i+1]-m_pY[i];
		double tmp1 = dx2*dy0-dx0*dy2;
		if( (tmp1<0?-tmp1:tmp1)<1.0e-5 ) 
		{
			continue;
		}

		
		double dx=m_pX[i+1]-m_pX[i-1];
		double dy=m_pY[i+1]-m_pY[i-1];
		double x,y;
		x = (m_pX[i+1]+m_pX[i-1])/2;
		y = (m_pY[i+1]+m_pY[i-1])/2;

		double newX,newY;
		dx=x-m_pX[i];
		dy=y-m_pY[i];
		if(fabs(dx)<ZERO_ERROR)
		{
			newX=m_pX[i];
			newY=m_pY[i]+1e-3;
		}
		else
		{
			double k=dy/dx;
			if(m_pX[i]>x)
			{
				newX=m_pX[i]-1e-3;
			}
			else
			{
				newX=m_pX[i]+1e-3;
			}
			newY=k*newX+m_pY[i]-k*m_pX[i];
		}

		BOOL bInRgn=PtInRegion(newX,newY,0.0);
		BOOL bAccumulate=(m_pX[i]-m_pX[i-1])*(m_pY[i+1]-m_pY[i])-(m_pY[i]-m_pY[i-1])*(m_pX[i+1]-m_pX[i])>0;
		
		if( bInRgn == bAccumulate )
			nAntiClock ++;
		else
			nClock ++;
	}
	if( nClock > nAntiClock )return 0;
	else if( nClock < nAntiClock )return 1;
	return -1;
}

double CRealRgn::GetCircumference()
{
	double Circumference=(double)0.0;
	for(int i=0;i<m_nBufferSize;i++)
	{
		Circumference+=sqrt(pow((m_pX[i+1]-m_pX[i]),2)+pow((m_pY[i+1]-m_pY[i]),2));
	}
	return Circumference;
}

double CRealRgn::GetArea()
{
	if(m_nBufferSize<3)
		return (double)0.0;

	double Area=(double)0.0;
	for(int i=0;i<m_nBufferSize;i++)
	{
		Area+=(m_pY[i]+m_pY[i+1])*(m_pX[i+1]-m_pX[i])/2.0;
	}

	return Area;
}

bool CRealRgn::IsValid()
{
	return (m_pX!=NULL&&m_pY!=NULL&&m_bVertex!=NULL);
}

BOOL CRealRgn::Intersect1(double X1,double Y1,double X2,double Y2,double X3,double Y3,double X4,double Y4,double& X,double& Y)
{
	double a1=Y2-Y1;
	double b1=X1-X2;
	double c1=Y1*(X2-X1)+X1*(Y1-Y2);

	double a2=Y4-Y3;
	double b2=X3-X4;
	double c2=Y3*(X4-X3)+X3*(Y3-Y4);

	//如果两条直线平行
	if(fabs(a1*b2-a2*b1)<ZERO_ERROR)
	{
		return FALSE;
	}

	X=(b1*c2-b2*c1)/(a1*b2-a2*b1);
	Y=(a2*c1-a1*c2)/(a1*b2-a2*b1);
	
	if((X-X1)*(X-X2)<=ZERO_ERROR&&(Y-Y1)*(Y-Y2)<=ZERO_ERROR&&(X-X3)*(X-X4)<=ZERO_ERROR&&(Y-Y3)*(Y-Y4)<=ZERO_ERROR)
	{
		return TRUE;
	}

	return FALSE;
}

bool CRealRgn::CombineRgn(CRealRgn* pRgn1,CRealRgn* pRgn2,int nCombineMode)
{
	ASSERT(pRgn1!=NULL);
	ASSERT(pRgn2!=NULL);

	switch(nCombineMode)
	{
	case RGN_AND:
		{
			RGN_REALRECT rc1;
			pRgn1->GetRgnBox(&rc1);
			RGN_REALRECT rc2;
			pRgn2->GetRgnBox(&rc2);
			if(rc1.left>rc2.right||rc1.right<rc2.left||rc1.top<rc2.bottom||rc1.bottom>rc2.top)
			{
				return false;
			}

			CRealRgn *pLeftRgn=NULL,*pRightRgn=NULL;
			if(rc1.left<rc2.left)
			{
				pLeftRgn=pRgn1;
				pRightRgn=pRgn2;
			}
			else
			{
				pLeftRgn=pRgn2;
				pRightRgn=pRgn1;
			}

			int nVertexNumL;
			double *pLeftRgnX,*pLeftRgnY;
			pLeftRgn->GetVertex(&pLeftRgnX,&pLeftRgnY,&nVertexNumL);
			int nVertexNumR;
			double *pRightRgnX,*pRightRgnY;
			pRightRgn->GetVertex(&pRightRgnX,&pRightRgnY,&nVertexNumR);

			//计算左多边形进出右多边形的边
			int LinR=-1,LoutR=-1;//左多边形进出右多边形的边的左顶点的索引号
			int RoutL=-1,RinL=-1;//右多边形进出左多边形的边的左顶点索引号
			double LinRX,LinRY;
			double LoutRX,LoutRY;
			for(int i=0;i<nVertexNumL;i++)
			{
				double Xi0=pLeftRgnX[i];
				double Yi0=pLeftRgnY[i];
				int npti0inRgn=pRightRgn->PtInRegion(Xi0,Yi0,0.0);
				double Xi1=pLeftRgnX[(i+1)%nVertexNumL];
				double Yi1=pLeftRgnY[(i+1)%nVertexNumL];
				int npti1inRgn=pRightRgn->PtInRegion(Xi1,Yi1,0.0);
				
				BOOL pti0inRgn=npti0inRgn==1;
				BOOL pti1inRgn=npti1inRgn==1;
				if(npti0inRgn==-1)
				{
					if(pti1inRgn==TRUE)
					{
						pti0inRgn=FALSE;
					}
					else
					{
						pti0inRgn=TRUE;
					}
				}
				if(npti1inRgn==-1)
				{
					if(pti0inRgn==TRUE)
					{
						pti1inRgn=FALSE;
					}
					else
					{
						pti1inRgn=TRUE;
					}
				}

				for(int j=0;j<nVertexNumR;j++)
				{
					double Xj0=pRightRgnX[j];
					double Yj0=pRightRgnY[j];
					int nptj0inRgn=pLeftRgn->PtInRegion(Xj0,Yj0,0.0);
					double Xj1=pRightRgnX[(j+1)%nVertexNumR];
					double Yj1=pRightRgnY[(j+1)%nVertexNumR];
					int nptj1inRgn=pLeftRgn->PtInRegion(Xj1,Yj1,0.0);

					BOOL ptj0inRgn=nptj0inRgn==1;
					BOOL ptj1inRgn=nptj1inRgn==1;
					if(nptj0inRgn==-1)
					{
						if(ptj1inRgn==TRUE)
						{
							ptj0inRgn=FALSE;
						}
						else
						{
							ptj0inRgn=TRUE;
						}
					}
					if(nptj1inRgn==-1)
					{
						if(ptj0inRgn==TRUE)
						{
							ptj1inRgn=FALSE;
						}
						else
						{
							ptj1inRgn=TRUE;
						}
					}

					double X,Y;
					if(Intersect1(Xi0,Yi0,Xi1,Yi1,Xj0,Yj0,Xj1,Yj1,X,Y))
					{
						if(pti0inRgn==FALSE&&pti1inRgn==TRUE)
						{
							LinRX=X;
							LinRY=Y;
							LinR=i;
						}
						else if(pti0inRgn==TRUE&&pti1inRgn==FALSE)
						{
							LoutRX=X;
							LoutRY=Y;
							LoutR=i;
						}
						else
						{
							for(int m=j+1;m<nVertexNumR;m++)
							{
								double Xm0=pRightRgnX[m%nVertexNumR];
								double Ym0=pRightRgnY[m%nVertexNumR];
								BOOL ptm0inRgn=pLeftRgn->PtInRegion(Xm0,Ym0,0.0);
								double Xm1=pRightRgnX[(m+1)%nVertexNumR];
								double Ym1=pRightRgnY[(m+1)%nVertexNumR];
								BOOL ptm1inRgn=pLeftRgn->PtInRegion(Xm1,Ym1,0.0);

								double X1,Y1;
								if(Intersect1(Xi0,Yi0,Xi1,Yi1,Xm0,Ym0,Xm1,Ym1,X1,Y1))
								{
									double disj=(X-Xi0)*(X-Xi0)+(Y-Yi0)*(Y-Yi0);
									double dism=(X1-Xi0)*(X1-Xi0)+(Y1-Yi0)*(Y1-Yi0);
									if(disj<dism)
									{
										LinRX=X;
										LinRY=Y;
										LoutRX=X1;
										LoutRY=Y1;
										if(ptj0inRgn==TRUE&&ptj1inRgn==FALSE)
										{
											RoutL=j;
											RinL=m;
										}
										else if(ptj0inRgn==FALSE&&ptj1inRgn==TRUE)
										{
											RinL=j;
											RoutL=m;
										}
									}
									else
									{
										LinRX=X1;
										LinRY=Y1;
										LoutRX=X;
										LoutRY=Y;
										if(ptm0inRgn==TRUE&&ptm1inRgn==FALSE)
										{
											RoutL=m;
											RinL=j;
										}
										else if(ptm0inRgn==FALSE&&ptm1inRgn==TRUE)
										{
											RinL=m;
											RoutL=j;
										}
									}
								}
							}
							break;
						}
						if(ptj0inRgn==TRUE&&ptj1inRgn==FALSE)
						{
							RoutL=j;
						}
						else if(ptj0inRgn==FALSE&&ptj1inRgn==TRUE)
						{
							RinL=j;
						}
					}
				}
			}

			//两多边形不相交
			if(LinR==-1&&LoutR==-1&&RinL==-1&&RoutL==-1)
			{
				return false;
			}

			double* pX=new double[nVertexNumL+nVertexNumR+2];
			double* pY=new double[nVertexNumL+nVertexNumR+2];
			int nVertexNum=0;
			
			pX[nVertexNum]=LinRX;
			pY[nVertexNum]=LinRY;
			nVertexNum++;

			if(LoutR<LinR)
			{
				LoutR+=nVertexNumL;
			}
			for(int i=LinR+1;i<=LoutR;i++)
			{
				pX[nVertexNum]=pLeftRgnX[i%nVertexNumL];
				pY[nVertexNum]=pLeftRgnY[i%nVertexNumL];
				nVertexNum++;
			}
			pX[nVertexNum]=LoutRX;
			pY[nVertexNum]=LoutRY;
			nVertexNum++;
			if(RoutL<RinL)
			{
				RoutL+=nVertexNumR;
			}
			for(int i=RinL+1;i<=RoutL;i++)
			{
				pX[nVertexNum]=pRightRgnX[i%nVertexNumR];
				pY[nVertexNum]=pRightRgnY[i%nVertexNumR];
				nVertexNum++;
			}

			CreatePolygonRgn(pX,pY,nVertexNum);

			delete [] pX; pX=NULL;
			delete [] pY; pY=NULL;
			return true;
		}
		break;
	case RGN_OR:
		{
			RGN_REALRECT rc1;
			pRgn1->GetRgnBox(&rc1);
			RGN_REALRECT rc2;
			pRgn2->GetRgnBox(&rc2);
			if(rc1.left>rc2.right||rc1.right<rc2.left||rc1.top<rc2.bottom||rc1.bottom>rc2.top)
			{
				return FALSE;
			}

			CRealRgn *pLeftRgn=NULL,*pRightRgn=NULL;
			if(rc1.left<rc2.left)
			{
				pLeftRgn=pRgn1;
				pRightRgn=pRgn2;
			}
			else
			{
				pLeftRgn=pRgn2;
				pRightRgn=pRgn1;
			}

			int nVertexNumL;
			double *pLeftRgnX,*pLeftRgnY;
			pLeftRgn->GetVertex(&pLeftRgnX,&pLeftRgnY,&nVertexNumL);
			int nVertexNumR;
			double *pRightRgnX,*pRightRgnY;
			pRightRgn->GetVertex(&pRightRgnX,&pRightRgnY,&nVertexNumR);

			//计算左多边形进出右多边形的边
			int LinR=-1,LoutR=-1;//左多边形进出右多边形的边的前顶点的索引号
			int RoutL=-1,RinL=-1;//右多边形进出左多边形的边的前顶点索引号
			double LinRX,LinRY;
			double LoutRX,LoutRY;
			for(int i=0;i<nVertexNumL;i++)
			{
				double Xi0=pLeftRgnX[i];
				double Yi0=pLeftRgnY[i];
				BOOL pti0inRgn=pRightRgn->PtInRegion(Xi0,Yi0,0.0);
				double Xi1=pLeftRgnX[(i+1)%nVertexNumL];
				double Yi1=pLeftRgnY[(i+1)%nVertexNumL];
				BOOL pti1inRgn=pRightRgn->PtInRegion(Xi1,Yi1,0.0);

				for(int j=0;j<nVertexNumR;j++)
				{
					double Xj0=pRightRgnX[j];
					double Yj0=pRightRgnY[j];
					BOOL ptj0inRgn=pLeftRgn->PtInRegion(Xj0,Yj0,0.0);
					double Xj1=pRightRgnX[(j+1)%nVertexNumR];
					double Yj1=pRightRgnY[(j+1)%nVertexNumR];
					BOOL ptj1inRgn=pLeftRgn->PtInRegion(Xj1,Yj1,0.0);

					double X,Y;
					if(Intersect1(Xi0,Yi0,Xi1,Yi1,Xj0,Yj0,Xj1,Yj1,X,Y))
					{
						if(pti0inRgn==FALSE&&pti1inRgn==TRUE)
						{
							LinRX=X;
							LinRY=Y;
							LinR=i;
						}
						else if(pti0inRgn==TRUE&&pti1inRgn==FALSE)
						{
							LoutRX=X;
							LoutRY=Y;
							LoutR=i;
						}
						else
						{
							for(int m=j+1;m<nVertexNumR;m++)
							{
								double Xm0=pRightRgnX[m%nVertexNumR];
								double Ym0=pRightRgnY[m%nVertexNumR];
								BOOL ptm0inRgn=pLeftRgn->PtInRegion(Xm0,Ym0,0.0);
								double Xm1=pRightRgnX[(m+1)%nVertexNumR];
								double Ym1=pRightRgnY[(m+1)%nVertexNumR];
								BOOL ptm1inRgn=pLeftRgn->PtInRegion(Xm1,Ym1,0.0);

								double X1,Y1;
								if(Intersect1(Xi0,Yi0,Xi1,Yi1,Xm0,Ym0,Xm1,Ym1,X1,Y1))
								{
									double disj=(X-Xi0)*(X-Xi0)+(Y-Yi0)*(Y-Yi0);
									double dism=(X1-Xi0)*(X1-Xi0)+(Y1-Yi0)*(Y1-Yi0);
									if(disj<dism)
									{
										LinRX=X;
										LinRY=Y;
										LoutRX=X1;
										LoutRY=Y1;
										if(ptj0inRgn==TRUE&&ptj1inRgn==FALSE)
										{
											RoutL=j;
											RinL=m;
										}
										else if(ptj0inRgn==FALSE&&ptj1inRgn==TRUE)
										{
											RinL=j;
											RoutL=m;
										}
									}
									else
									{
										LinRX=X1;
										LinRY=Y1;
										LoutRX=X;
										LoutRY=Y;
										if(ptm0inRgn==TRUE&&ptm1inRgn==FALSE)
										{
											RoutL=m;
											RinL=j;
										}
										else if(ptm0inRgn==FALSE&&ptm1inRgn==TRUE)
										{
											RinL=m;
											RoutL=j;
										}
									}
								}
							}
							break;
						}
						if(ptj0inRgn==TRUE&&ptj1inRgn==FALSE)
						{
							RoutL=j;
						}
						else if(ptj0inRgn==FALSE&&ptj1inRgn==TRUE)
						{
							RinL=j;
						}
					}
				}
			}

			//两多边形不相交
			if(LinR==-1&&LoutR==-1&&RinL==-1&&RoutL==-1)
			{
				return FALSE;
			}

			double* pX=new double[nVertexNumL+nVertexNumR+2];
			double* pY=new double[nVertexNumL+nVertexNumR+2];
			int nVertexNum=0;
			
			pX[nVertexNum]=LoutRX;
			pY[nVertexNum]=LoutRY;
			nVertexNum++;
			//左多边形有一条边穿过了右多边形
			if(LinR==-1&&LoutR==-1)
			{
				for(int i=0;i<nVertexNumL;i++)
				{
					double X0=pLeftRgnX[i];
					double Y0=pLeftRgnY[i];
					double X1=pLeftRgnX[(i+1)%nVertexNumL];
					double Y1=pLeftRgnY[(i+1)%nVertexNumL];
					for(int j=0;j<nVertexNumR;j++)
					{
						double X2=pRightRgnX[j];
						double Y2=pRightRgnY[j];
						double X3=pRightRgnX[(j+1)%nVertexNumR];
						double Y3=pRightRgnY[(j+1)%nVertexNumR];
						double X,Y;
						if(CRealRgn::Intersect1(X0,Y0,X1,Y1,X2,Y2,X3,Y3,X,Y))
						{
							LinR=i;
							LoutR=i;
							break;
						}
					}
				}
			}
			if(LinR<=LoutR)
			{
				LinR+=nVertexNumL;
			}
			for(int i=LoutR+1;i<=LinR;i++)
			{
				pX[nVertexNum]=pLeftRgnX[i%nVertexNumL];
				pY[nVertexNum]=pLeftRgnY[i%nVertexNumL];
				nVertexNum++;
			}
			pX[nVertexNum]=LinRX;
			pY[nVertexNum]=LinRY;
			nVertexNum++;
			//右多边形有一条边穿过了左多边形
			if(RinL==-1&&RoutL==-1)
			{
				for(int i=0;i<nVertexNumR;i++)
				{
					double X0=pRightRgnX[i];
					double Y0=pRightRgnY[i];
					double X1=pRightRgnX[(i+1)%nVertexNumR];
					double Y1=pRightRgnY[(i+1)%nVertexNumR];
					for(int j=0;j<nVertexNumL;j++)
					{
						double X2=pLeftRgnX[j];
						double Y2=pLeftRgnY[j];
						double X3=pLeftRgnX[(j+1)%nVertexNumL];
						double Y3=pLeftRgnY[(j+1)%nVertexNumL];
						double X,Y;
						if(CRealRgn::Intersect1(X0,Y0,X1,Y1,X2,Y2,X3,Y3,X,Y))
						{
							RinL=i;
							RoutL=i;
							break;
						}
					}
				}
			}
			if(RinL<=RoutL)
			{
				RinL+=nVertexNumR;
			}
			for(int i=RoutL+1;i<=RinL;i++)
			{
				pX[nVertexNum]=pRightRgnX[i%nVertexNumR];
				pY[nVertexNum]=pRightRgnY[i%nVertexNumR];
				nVertexNum++;
			}

			CreatePolygonRgn(pX,pY,nVertexNum);

			delete [] pX; pX=NULL;
			delete [] pY; pY=NULL;
			return true;
		}
		break;
	default:
		return false;
	}

	return false;
}
/*
bool CRealRgn::CombineRgn(CRealRgn* pRgn1,CRealRgn* pRgn2,int nCombineMode)
{
	ASSERT(pRgn1!=NULL);
	ASSERT(pRgn2!=NULL);

	switch(nCombineMode)
	{
	case RGN_AND:
		{
			bool bRet=false;
			RGN_REALRECT rc1;
			pRgn1->GetRgnBox(&rc1);
			RGN_REALRECT rc2;
			pRgn2->GetRgnBox(&rc2);
			if(rc1.left>rc2.right||rc1.right<rc2.left||rc1.top<rc2.bottom||rc1.bottom>rc2.top)
			{
				return false;
			}

			CRealRgn *pLeftRgn=NULL,*pRightRgn=NULL;
			if(rc1.left<rc2.left)
			{
				pLeftRgn=pRgn1;
				pRightRgn=pRgn2;
			}
			else
			{
				pLeftRgn=pRgn2;
				pRightRgn=pRgn1;
			}

			int nVertexNumL=pLeftRgn->GetVertexNum();
			int nVertexNumR=pRightRgn->GetVertexNum();

			double* ptLinRX=new double[nVertexNumL];
			double* ptLinRY=new double[nVertexNumL];
			double* ptRinLX=new double[nVertexNumR];
			double* ptRinLY=new double[nVertexNumR];
			
			double *pX=NULL,*pY=NULL;
			int nFirstIn=-1,nFirstOut=-1;
			
			int nPtLinR=0;
			pLeftRgn->GetVertex(&pX,&pY,NULL);
			for(int i=0;i<nVertexNumL;i++)
			{
				if(pRightRgn->PtInRegion(pX[i],pY[i]))
				{
					ptLinRX[nPtLinR]=pX[i];
					ptLinRY[nPtLinR]=pY[i];
					nPtLinR++;
					if(nFirstIn==-1)
					{
						nFirstIn=i;
					}
				}
				else if(nFirstIn!=-1)
				{
					nFirstOut=i;
				}
			}

			int nPtRinL=0;
			pRightRgn->GetVertex(&pX,&pY,NULL);
			for(i=0;i<nVertexNumR;i++)
			{
				if(pLeftRgn->PtInRegion(pX[i],pY[i]))
				{
					ptRinLX[nPtRinL]=pX[i];
					ptRinLY[nPtRinL]=pY[i];
					nPtRinL++;
				}
			}

			double *pX0=NULL,*pY0=NULL,*pX1=NULL,*pY1=NULL;
			pLeftRgn->GetVertex(&pX0,&pY0,NULL);
			pRightRgn->GetVertex(&pX1,&pY1,NULL);
			int nIntersect=0;
			double* ptIntersectX=new double[nVertexNumL+nVertexNumR];
			double* ptIntersectY=new double[nVertexNumL+nVertexNumR];
			for(i=0;i<nVertexNumL;i++)
			{
				double x0=pX0[i];
				double y0=pY0[i];
				double x1=pX0[(i+1)%nVertexNumL];
				double y1=pY0[(i+1)%nVertexNumL];
				for(int j=0;j<nVertexNumR;j++)
				{
					double x2=pX1[j];
					double y2=pY1[j];
					double x3=pX1[(j+1)%nVertexNumR];
					double y3=pY1[(j+1)%nVertexNumR];
					double x,y;
					
					if(Intersect1(x0,y0,x1,y1,x2,y2,x3,y3,x,y))
					{
						ptIntersectX[nIntersect]=x;
						ptIntersectY[nIntersect]=y;
						nIntersect++;
					}
				}
			}

			int nNewRgnVertexNum=nPtLinR+nPtRinL+nIntersect;
			if(nNewRgnVertexNum>0&&nIntersect>0)
			{
				double* pCombinX=new double[nNewRgnVertexNum];
				double* pCombinY=new double[nNewRgnVertexNum];

				pCombinX[0]=ptIntersectX[0];
				pCombinY[0]=ptIntersectY[0];
				for(int m=0;m<nPtLinR;m++)
				{
					pCombinX[m+1]=ptLinRX[m];
					pCombinY[m+1]=ptLinRY[m];
				}
				for(m=1;m<nIntersect;m++)
				{
					pCombinX[m+nPtLinR]=ptIntersectX[m];
					pCombinY[m+nPtLinR]=ptIntersectY[m];
				}
				for(m=0;m<nPtRinL;m++)
				{
					pCombinX[m+nIntersect+nPtLinR]=ptRinLX[nPtRinL-1-m];
					pCombinY[m+nIntersect+nPtLinR]=ptRinLY[nPtRinL-1-m];
				}

				CreatePolygonRgn(pCombinX,pCombinY,nNewRgnVertexNum);

				delete [] pCombinX; pCombinX=NULL;
				delete [] pCombinY; pCombinY=NULL;
				bRet=true;
			}
			
			delete [] ptLinRX; ptLinRX=NULL;
			delete [] ptLinRY; ptLinRY=NULL;
			delete [] ptRinLX; ptRinLX=NULL;
			delete [] ptRinLY; ptRinLY=NULL;
			delete [] ptIntersectX; ptIntersectX=NULL;
			delete [] ptIntersectY; ptIntersectY=NULL;

			return bRet;
		}
		break;
	default:
		return false;
	}

	return false;
}*/

int CRealRgn::GetVertexNum()
{
	return m_nBufferSize;
}

bool CRealRgn::GetVertex(double** ppX,double** ppY,int* pCount)
{
	if(ppX!=NULL)
	{
		*ppX=m_pX;
	}
	if(ppY!=NULL)
	{
		*ppY=m_pY;
	}
	if(pCount!=NULL)
	{
		*pCount=m_nBufferSize;
	}

	return true;
}

bool CRealRgn::GetVertex(double** ppX,double** ppY,double** ppZ,int* pCount)
{
	if(ppX!=NULL)
	{
		*ppX=m_pX;
	}
	if(ppY!=NULL)
	{
		*ppY=m_pY;
	}
	if(ppZ!=NULL)
	{
		*ppZ=m_pZ;
	}
	if(pCount!=NULL)
	{
		*pCount=m_nBufferSize;
	}

	return true;
}
