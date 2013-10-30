// RealRgn.h: interface for the CRealRgn class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_REALRGN_H__174C525E_7051_4055_8E03_EED4FF111474__INCLUDED_)
#define AFX_REALRGN_H__174C525E_7051_4055_8E03_EED4FF111474__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#define ZERO_ERROR 1e-6

typedef struct tagREALPOINT 
{
   double x;
   double y;
} RGN_REALPOINT;

#define POINTX RGN_REALPOINT

typedef struct tagREALRECT
{
	double left;
	double right;
	double bottom;
	double top;

	tagREALRECT()
	{
		left=0;
		right=0;
		bottom=0;
		top=0;
	};
	tagREALRECT(double left,double bottom,double right,double top)
	{
		this->left=left;
		this->right=right;
		this->bottom=bottom;
		this->top=top;
	};
} RGN_REALRECT;

class CRealRgn
{
protected:
	double* m_pX;
	double* m_pY;
	double* m_pZ;
	bool* m_bVertex;
	bool* m_VertexState;
	int m_nBufferSize;
	RGN_REALRECT m_Box;

	//CRgn m_msRgn;//使用MFC的RGN做测试
private:
	int m_nDirection;
	int	CalRgnDirection();
	bool InitVertexState();
	int IsPtInRegion(double x,double y,double snap);
	inline int Intersect(double x0,double y0,double x1,double y1,double x2,double y2,double x3,double y3,int ptIndex2,int ptIndex3,double *x,double *y,double minXSrc,double minYSrc,double maxXSrc,double maxYSrc,int nCount);
public:
	void DestoryMe();
	static BOOL Intersect1(double X1,double Y1,double X2,double Y2,double X3,double Y3,double X4,double Y4,double& X,double& Y);
	int GetVertexNum();
	bool GetVertex(double** ppX,double** ppY,int* pCount);
	bool GetVertex(double** ppX,double** ppY,double** ppZ,int* pCount);
	bool CombineRgn(CRealRgn* pRgn1,CRealRgn* pRgn2,int nCombineMode);
	inline int GetRgnDirection(){return m_nDirection;};//0 顺时针 1逆时针 -1 error
	bool CreatePolygonRgn(RGN_REALPOINT* pRealPt,int nCount,BOOL bAutoAntiClock=FALSE);//pRealPt指向用于构造对边形的点,nCount为点的个数
	bool CreatePolygonRgn(double* pX,double* pY,int nCount,BOOL bAutoAntiClock=FALSE);//pX,pY分别指向count个点的x坐标和y坐标
	bool CreatePolygonRgn(double* pX,double* pY,double* pZ,int nCount,BOOL bAutoAntiClock=FALSE);
	int  GetRgnBox(RGN_REALRECT* pRgnBox);//得到多边形的最大外廓
	int PtInRegion(double x,double y,double snap=0.5);//判断一个点是否在多边形内部,0外部 1 内部 -1 边界上
	int PtInRegion(RGN_REALPOINT point,double snap=0.5);//判断一个点是否在多边形内部

	double GetCircumference();
	double GetArea();
	bool IsValid();

	CRealRgn();
	virtual ~CRealRgn();
};

#endif // !defined(AFX_REALRGN_H__174C525E_7051_4055_8E03_EED4FF111474__INCLUDED_)
