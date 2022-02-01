// FiveChessView.h : interface of the CFiveChessView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_FIVECHESSVIEW_H__B4280A4F_3570_47B2_A454_01D781244C93__INCLUDED_)
#define AFX_FIVECHESSVIEW_H__B4280A4F_3570_47B2_A454_01D781244C93__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CFiveChessView : public CView
{
protected: // create from serialization only
	CFiveChessView();
	DECLARE_DYNCREATE(CFiveChessView)

// Attributes
public:
	CFiveChessDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFiveChessView)
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
	virtual ~CFiveChessView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CFiveChessView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in FiveChessView.cpp
inline CFiveChessDoc* CFiveChessView::GetDocument()
   { return (CFiveChessDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FIVECHESSVIEW_H__B4280A4F_3570_47B2_A454_01D781244C93__INCLUDED_)
