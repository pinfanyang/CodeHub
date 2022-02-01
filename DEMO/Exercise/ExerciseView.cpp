// ExerciseView.cpp : implementation of the CExerciseView class
//

#include "stdafx.h"
#include "Exercise.h"
#include "math.h"
#include "DlgHuaYuan.h"
#include "ExerciseDoc.h"
#include "ExerciseView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CExerciseView

IMPLEMENT_DYNCREATE(CExerciseView, CView)

BEGIN_MESSAGE_MAP(CExerciseView, CView)
	//{{AFX_MSG_MAP(CExerciseView)
	ON_COMMAND(ID_M_Start, OnMStart)
	ON_COMMAND(ID_M_Stop, OnMStop)
	ON_WM_TIMER()
	ON_COMMAND(ID_M_Cls, OnMCls)
	ON_WM_ERASEBKGND()
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExerciseView construction/destruction

CExerciseView::CExerciseView()
{
	// TODO: add construction code here

}

CExerciseView::~CExerciseView()
{
}

BOOL CExerciseView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CExerciseView drawing

void CExerciseView::OnDraw(CDC* pDC)
{
	CExerciseDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here


//�������̣�15*15��
	int len=30;
	for(int i=0;i<19;i++)		//����
	{
		pDC->MoveTo(60,60+i*len);
		pDC->LineTo(600,60+i*len);
	}
	for(int j=0;j<19;j++)
	{
		pDC->MoveTo(60+j*len,60);
		pDC->LineTo(60+j*len,600);
	}							//����  ��������
//���滭��λ
	for(int k=0;k<3;k++)
	{
		for(int l=0;l<3;l++)
		{	
			DrawCircle(pDC,150+180*k,150+180*l,4);
		}
	}
	
	//���
	DrawSqure(pDC,10,10,640,640);
	CFont ft;
//	ft.CreateFont(20,10,0,0,600,false,false,false,false,false,false,false,false,0);
	ft.CreatePointFont(240,_T("����"),NULL);
	pDC->SelectObject(&ft);
	pDC->SetTextColor(RGB(123,0,0));
	pDC->TextOut(300,15,"������");
// ���ֱʵ�ʵ��
	CPen cPen0,cPen1,cPen2;
	cPen0.CreatePen(PS_SOLID,1,RGB(100,100,100));//ʵ��
	cPen1.CreatePen(PS_DASH,2,RGB(200,200,200));//����
	cPen2.CreatePen(PS_DOT,3,RGB(300,300,300));//����
	pDC->SelectObject(&cPen0);
	pDC->MoveTo(1024,512);
	pDC->LineTo(1124,512);
	pDC->SelectObject(&cPen1);
	pDC->LineTo(1074,480);
	pDC->SelectObject(&cPen2);
	pDC->LineTo(1024,512);

//������ʵ��
	CPoint orgPos;
	orgPos.x=800;
	orgPos.y=250;
	DrawCordinate(pDC,orgPos);
	DrawCircle(pDC, m_circle.center.x, m_circle.center.y,m_circle.radius);
	DrawSin(pDC,orgPos,4,4,0); //�ڶ���4�����ڣ�0�Ǵ�����ԭ�㿪ʼ

}

void CExerciseView::OnInitialUpdate() 
{
	CView::OnInitialUpdate();
	// TODO: Add your specialized code here and/or call the base class
	m_circle.center.x=800;
	m_circle.center.y = 250;
	m_circle.radius = 10;
}


/////////////////////////////////////////////////////////////////////////////
// CExerciseView printing

BOOL CExerciseView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CExerciseView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CExerciseView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CExerciseView diagnostics

#ifdef _DEBUG
void CExerciseView::AssertValid() const
{
	CView::AssertValid();
}

void CExerciseView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExerciseDoc* CExerciseView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExerciseDoc)));
	return (CExerciseDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CExerciseView message handlers

void CExerciseView::DrawCircle(CDC *pDC, int x, int y, int r)
{
	CBrush Brush;
	Brush.CreateSolidBrush(RGB(0,0,0));
	pDC->BeginPath();
	pDC->Ellipse(x-r,y-r,x+r,y+r);
	pDC->EndPath();
	pDC->SelectObject(&Brush);
	pDC->FillPath();
}

void CExerciseView::DrawSqure(CDC *pDC, int x, int y, int w, int h)
{
	pDC->MoveTo(x,y);
	pDC->LineTo(x+w,y);
	pDC->LineTo(x+w,y+h);
	pDC->LineTo(x,y+h);
	pDC->LineTo(x,y);
}

void CExerciseView::DrawCordinate(CDC *pDC, CPoint orgPos)	//��������
{
	//x��
	pDC->MoveTo(orgPos.x - 200,orgPos.y);
	pDC->LineTo(orgPos.x + 1000,orgPos.y);
	//y��
	pDC->MoveTo(orgPos.x,orgPos.y - 200);
	pDC->LineTo(orgPos.x,orgPos.y + 200);
}

void CExerciseView::DrawSin(CDC *pDC, CPoint orgPos, int a, int b, int c)
//��y=a*sin(b*x)+c 0<=x<=900 ���ȣ�x*3.14159/180
{	
	int x, y;
	pDC->MoveTo(orgPos); //��sin����Ƶ�����ԭ��
	for(x = 0; x <= 900; x++)
	{
		y = 50 *a *sin(b *x *3.14159/180) + c; //50�ǷŴ��������ֵ
		y = - y; //��ֱ����Ϊy��������
		pDC->LineTo(orgPos.x + x,orgPos.y + y);
	}

}



void CExerciseView::OnMStart() 
{
	// TODO: Add your command handler code here
	SetTimer(1,200,NULL);
	//������ʱ������һ��������ʱ��ID�ţ��ڶ����Ǽ�ϵ�ʱ�䣬
	//����ʱ��ÿ���ӱ����ö��ٴΣ��������ǻص�������Ĭ�Ͽգ���
	//1s�ж�10�εĻ���100��λ�Ǻ��룬Ҳ����0.1�룬0.1s/�Σ���1s/10��
}

void CExerciseView::OnMStop() 
{
	// TODO: Add your command handler code here
	KillTimer(1);//ֹͣʱ��
}

void CExerciseView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	//m_circle.center.x += 10;//1s�ж�10�Σ���ÿ���жϵ�ʱ����Բ���ƶ�10�����صĵ�λ 
	int dcircle = 0;
	int dsin = 0;
	dcircle = m_circle.center.x  - 800 + 2;
	dsin = -50 *4 *sin(4 *dcircle *3.14159/180);
	m_circle.center.x += 2;
	m_circle.center.y = dsin + 250 ;
	Invalidate(true);
	CView::OnTimer(nIDEvent);
}

void CExerciseView::OnMCls() 
{
	// TODO: Add your command handler code here
	Invalidate(true);
	
}

BOOL CExerciseView::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	
	return CView::OnEraseBkgnd(pDC);
}

void CExerciseView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CString str;
	str.Format("x=%d,y=%d",point.x,point.y);
	AfxMessageBox(str);
	CView::OnLButtonDown(nFlags, point);
}

//DEL void CExerciseView::OnMHuaYuan() 
//DEL {
//DEL 	// TODO: Add your command handler code here
//DEL 	CDlgHuaYuan dlg;
//DEL 	if(dlg.DoModal()==IDC_HuaYuan_Draw)
//DEL 	{
//DEL 		m_X=dlg.m_x;
//DEL 		m_Y=dlg.m_y;
//DEL 		m_R=dlg.m_r;
//DEL 	}
//DEL 	CExerciseView::DrawCircle(CDC *pDC,m_X,m_Y,m_R);
//DEL 	Invalidate(true);
//DEL }
