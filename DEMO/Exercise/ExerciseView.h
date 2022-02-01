// ExerciseView.h : interface of the CExerciseView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXERCISEVIEW_H__CC4DAB95_FD39_43FD_A900_FBFF093F66D8__INCLUDED_)
#define AFX_EXERCISEVIEW_H__CC4DAB95_FD39_43FD_A900_FBFF093F66D8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

typedef struct
{
	POINT center; //定义圆心
	int radius; //定义半径
}MyCircle; //定义圆对象


class CExerciseView : public CView
{
protected: // create from serialization only
	CExerciseView();
	DECLARE_DYNCREATE(CExerciseView)
	void OnInitialUpdate(); 


// Attributes
public:
	CExerciseDoc* GetDocument();
	MyCircle m_circle;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExerciseView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	int m_R;
	int m_Y;
	int m_X;
	int m_nPic;
	void DrawSin(CDC *pDC, CPoint orgPos, int a, int b, int c);
	void DrawCordinate(CDC *pDC, CPoint orgPos);
	void DrawSqure(CDC *pDC,int x,int y,int w,int h);
	void DrawCircle(CDC* pDC,int x,int y,int r);
	virtual ~CExerciseView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CExerciseView)
	afx_msg void OnMStart();
	afx_msg void OnMStop();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnMCls();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ExerciseView.cpp
inline CExerciseDoc* CExerciseView::GetDocument()
   { return (CExerciseDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXERCISEVIEW_H__CC4DAB95_FD39_43FD_A900_FBFF093F66D8__INCLUDED_)
