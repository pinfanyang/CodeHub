// DlgJiSuanQi.cpp : implementation file
//

#include "stdafx.h"
#include "Exercise.h"
#include "DlgJiSuanQi.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgJiSuanQi dialog


CDlgJiSuanQi::CDlgJiSuanQi(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgJiSuanQi::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgJiSuanQi)
	m_chu = 0.0;
	m_a = 0.0;
	m_b = 0.0;
	m_cha = 0.0;
	m_ji = 0.0;
	m_he = 0.0;
	m_yu = 0.0;
	//}}AFX_DATA_INIT
}


void CDlgJiSuanQi::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgJiSuanQi)
	DDX_Text(pDX, IDC_Chu, m_chu);
	DDX_Text(pDX, IDC_a, m_a);
	DDX_Text(pDX, IDC_b, m_b);
	DDX_Text(pDX, IDC_Cha, m_cha);
	DDX_Text(pDX, IDC_Ji, m_ji);
	DDX_Text(pDX, IDC_SUM, m_he);
	DDX_Text(pDX, IDC_Yu, m_yu);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgJiSuanQi, CDialog)
	//{{AFX_MSG_MAP(CDlgJiSuanQi)
	ON_BN_CLICKED(IDC_QiuHe, OnQiuHe)
	ON_BN_CLICKED(IDC_QiuCha, OnQiuCha)
	ON_BN_CLICKED(IDC_QiuJi, OnQiuJi)
	ON_BN_CLICKED(IDC_QiuChu, OnQiuChu)
	ON_BN_CLICKED(IDC_QiuYu, OnQiuYu)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgJiSuanQi message handlers

int CDlgJiSuanQi::DoModal() 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CDialog::DoModal();
}

void CDlgJiSuanQi::OnQiuHe() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	m_he=m_a+m_b;
	UpdateData(false);
	
}



void CDlgJiSuanQi::OnQiuCha() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	m_cha=m_a-m_b;
	UpdateData(false);
}

void CDlgJiSuanQi::OnQiuJi() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	m_ji=m_a*m_b;
	UpdateData(false);
}

void CDlgJiSuanQi::OnQiuChu() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	m_chu=m_a/m_b;
	UpdateData(false);
}

void CDlgJiSuanQi::OnQiuYu() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	m_yu=(int)m_a%(int)m_b;
	UpdateData(false);
}

void CDlgJiSuanQi::OnPaint()			//BUG
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	CBitmap bmp;
	bmp.LoadBitmap(IDB_BeiJing);
	BITMAP bmpInfo;
	bmp.GetBitmap(&bmpInfo);
	CDC dcMemory;
	dcMemory.CreateCompatibleDC(&dc);
	CBitmap *pOldBmp=dcMemory.SelectObject(&bmp);
	dc.BitBlt(0,0,bmpInfo.bmWidth,bmpInfo.bmHeight,&dcMemory,0,0,SRCCOPY);
	dcMemory.SelectObject(pOldBmp);
//	CDialog::OnPaint();
	
	// Do not call CDialog::OnPaint() for painting messages
}
