// GobangView.cpp : implementation of the CGobangView class
//

#include "stdafx.h"
#include "Gobang.h"

#include "GobangDoc.h"
#include "GobangView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGobangView

IMPLEMENT_DYNCREATE(CGobangView, CView)

BEGIN_MESSAGE_MAP(CGobangView, CView)
	//{{AFX_MSG_MAP(CGobangView)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGobangView construction/destruction

CGobangView::CGobangView()
{
	// TODO: add construction code here

}

CGobangView::~CGobangView()
{
}

BOOL CGobangView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CGobangView drawing

void CGobangView::OnDraw(CDC* pDC)
{
	CGobangDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
	static int i=0;
	if(i==0)
	{
		bitmap.LoadBitmap(IDB_BgPe);
		BEGIN.CreateCompatibleDC(pDC);
		BEGIN.SelectObject(bitmap);
		i=1;
	}
	pDC->BitBlt(0,0,653,1024,&BEGIN,0,0,SRCCOPY);

}

/////////////////////////////////////////////////////////////////////////////
// CGobangView printing

BOOL CGobangView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CGobangView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CGobangView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CGobangView diagnostics

#ifdef _DEBUG
void CGobangView::AssertValid() const
{
	CView::AssertValid();
}

void CGobangView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGobangDoc* CGobangView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGobangDoc)));
	return (CGobangDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGobangView message handlers

void CGobangView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	int x=point.x;
	int y=point.y;
	//判断鼠标点的位置是否在图片内
	if(x>=0 && x<=653 && y>=0 && y<=1024)
		MessageBox("鼠标左键点击在图片内部");
	
	CView::OnLButtonDown(nFlags, point);
}

void CGobangView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	//获取光标当前所指的点的坐标
	int x=point.x;
	int y=point.y;
	CString st;
	st.Format(("%d,%d"),x,y);	//用String的format函数对st进行初始化
	CDC *pDC=GetDC();
	pDC->TextOut(200,200,st);	//用标准库函数在指定位置输出字符串
	ReleaseDC(pDC);				//释放pDC
	SetCursor(LoadCursor(NULL,IDC_CROSS));	//通过LoadCursor来获得一种鼠标的形状，然后用SetCursor进行设置，如此达到改变鼠标形状的效果

	CView::OnMouseMove(nFlags, point);
}
