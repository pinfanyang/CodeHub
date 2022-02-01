#if !defined(AFX_DLGJISUANQI_H__DACE1A2E_FC1F_47B6_A60C_C5D3C7DB3A2E__INCLUDED_)
#define AFX_DLGJISUANQI_H__DACE1A2E_FC1F_47B6_A60C_C5D3C7DB3A2E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgJiSuanQi.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgJiSuanQi dialog

class CDlgJiSuanQi : public CDialog
{
// Construction
public:
	CDlgJiSuanQi(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgJiSuanQi)
	enum { IDD = IDD_JiSuan };
	double	m_chu;
	double	m_a;
	double	m_b;
	double	m_cha;
	double	m_ji;
	double	m_he;
	double	m_yu;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgJiSuanQi)
	public:
	virtual int DoModal();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgJiSuanQi)
	afx_msg void OnQiuHe();
	afx_msg void OnQiuCha();
	afx_msg void OnQiuJi();
	afx_msg void OnQiuChu();
	afx_msg void OnQiuYu();
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGJISUANQI_H__DACE1A2E_FC1F_47B6_A60C_C5D3C7DB3A2E__INCLUDED_)
