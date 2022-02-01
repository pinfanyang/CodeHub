// ExerciseDoc.h : interface of the CExerciseDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXERCISEDOC_H__E4516517_C99B_4E53_A5EA_457E31BD9909__INCLUDED_)
#define AFX_EXERCISEDOC_H__E4516517_C99B_4E53_A5EA_457E31BD9909__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CExerciseDoc : public CDocument
{
protected: // create from serialization only
	CExerciseDoc();
	DECLARE_DYNCREATE(CExerciseDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExerciseDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CExerciseDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CExerciseDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXERCISEDOC_H__E4516517_C99B_4E53_A5EA_457E31BD9909__INCLUDED_)
