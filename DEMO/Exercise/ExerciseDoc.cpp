// ExerciseDoc.cpp : implementation of the CExerciseDoc class
//

#include "stdafx.h"
#include "Exercise.h"

#include "ExerciseDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CExerciseDoc

IMPLEMENT_DYNCREATE(CExerciseDoc, CDocument)

BEGIN_MESSAGE_MAP(CExerciseDoc, CDocument)
	//{{AFX_MSG_MAP(CExerciseDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExerciseDoc construction/destruction

CExerciseDoc::CExerciseDoc()
{
	// TODO: add one-time construction code here

}

CExerciseDoc::~CExerciseDoc()
{
}

BOOL CExerciseDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CExerciseDoc serialization

void CExerciseDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CExerciseDoc diagnostics

#ifdef _DEBUG
void CExerciseDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CExerciseDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CExerciseDoc commands
