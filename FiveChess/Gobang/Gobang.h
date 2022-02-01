// Gobang.h : main header file for the GOBANG application
//

#if !defined(AFX_GOBANG_H__BE6D5DE0_BCFE_4A52_A45F_BB3194E6A330__INCLUDED_)
#define AFX_GOBANG_H__BE6D5DE0_BCFE_4A52_A45F_BB3194E6A330__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CGobangApp:
// See Gobang.cpp for the implementation of this class
//

class CGobangApp : public CWinApp
{
public:
	CGobangApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGobangApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CGobangApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GOBANG_H__BE6D5DE0_BCFE_4A52_A45F_BB3194E6A330__INCLUDED_)
