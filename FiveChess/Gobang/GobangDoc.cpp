// GobangDoc.cpp : implementation of the CGobangDoc class
//

#include "stdafx.h"
#include "Gobang.h"

#include "GobangDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGobangDoc

IMPLEMENT_DYNCREATE(CGobangDoc, CDocument)

BEGIN_MESSAGE_MAP(CGobangDoc, CDocument)
	//{{AFX_MSG_MAP(CGobangDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGobangDoc construction/destruction

CGobangDoc::CGobangDoc()
{
	// TODO: add one-time construction code here

}

CGobangDoc::~CGobangDoc()
{
}

BOOL CGobangDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
	SetTitle("This is a demo!");

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CGobangDoc serialization

void CGobangDoc::Serialize(CArchive& ar)
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
// CGobangDoc diagnostics

#ifdef _DEBUG
void CGobangDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CGobangDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGobangDoc commands
