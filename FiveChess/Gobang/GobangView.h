// GobangView.h : interface of the CGobangView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_GOBANGVIEW_H__78BBC296_1C80_4504_871F_279FB9257800__INCLUDED_)
#define AFX_GOBANGVIEW_H__78BBC296_1C80_4504_871F_279FB9257800__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CGobangView : public CView
{
protected: // create from serialization only
	CGobangView();
	DECLARE_DYNCREATE(CGobangView)

// Attributes
public:
	CGobangDoc* GetDocument();

// Operations
public:
	CBitmap bitmap;
	CDC BEGIN;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGobangView)
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
	virtual ~CGobangView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CGobangView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in GobangView.cpp
inline CGobangDoc* CGobangView::GetDocument()
   { return (CGobangDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GOBANGVIEW_H__78BBC296_1C80_4504_871F_279FB9257800__INCLUDED_)
