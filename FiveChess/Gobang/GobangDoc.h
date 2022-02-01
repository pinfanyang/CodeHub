// GobangDoc.h : interface of the CGobangDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_GOBANGDOC_H__B0FFF5AF_95F1_4299_8806_5A6DBFD7E8CC__INCLUDED_)
#define AFX_GOBANGDOC_H__B0FFF5AF_95F1_4299_8806_5A6DBFD7E8CC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CGobangDoc : public CDocument
{
protected: // create from serialization only
	CGobangDoc();
	DECLARE_DYNCREATE(CGobangDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGobangDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CGobangDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CGobangDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GOBANGDOC_H__B0FFF5AF_95F1_4299_8806_5A6DBFD7E8CC__INCLUDED_)
