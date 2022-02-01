// FiveChessView.cpp : implementation of the CFiveChessView class
//

#include "stdafx.h"
#include "FiveChess.h"

#include "FiveChessDoc.h"
#include "FiveChessView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFiveChessView

IMPLEMENT_DYNCREATE(CFiveChessView, CView)

BEGIN_MESSAGE_MAP(CFiveChessView, CView)
	//{{AFX_MSG_MAP(CFiveChessView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFiveChessView construction/destruction

CFiveChessView::CFiveChessView()
{
	// TODO: add construction code here

}

CFiveChessView::~CFiveChessView()
{
}

BOOL CFiveChessView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CFiveChessView drawing

void CFiveChessView::OnDraw(CDC* pDC)
{
	CFiveChessDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CFiveChessView printing

BOOL CFiveChessView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CFiveChessView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CFiveChessView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CFiveChessView diagnostics

#ifdef _DEBUG
void CFiveChessView::AssertValid() const
{
	CView::AssertValid();
}

void CFiveChessView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFiveChessDoc* CFiveChessView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFiveChessDoc)));
	return (CFiveChessDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFiveChessView message handlers
