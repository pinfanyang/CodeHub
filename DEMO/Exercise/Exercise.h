// Exercise.h : main header file for the EXERCISE application
//

#if !defined(AFX_EXERCISE_H__E3E2F2AB_3CE5_41AA_A86C_E3B813CA1A47__INCLUDED_)
#define AFX_EXERCISE_H__E3E2F2AB_3CE5_41AA_A86C_E3B813CA1A47__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CExerciseApp:
// See Exercise.cpp for the implementation of this class
//

class CExerciseApp : public CWinApp
{
public:
	CExerciseApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExerciseApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CExerciseApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXERCISE_H__E3E2F2AB_3CE5_41AA_A86C_E3B813CA1A47__INCLUDED_)
