// DlgNETUI.cpp: 實作檔案
//

#include "pch.h"
#include "MFC_NET.h"
#include "DlgNETUI.h"
#include "afxdialogex.h"


// CDlgNETUI 對話方塊

IMPLEMENT_DYNAMIC(CDlgNETUI, CDialogEx)

CDlgNETUI::CDlgNETUI(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_NET_UI, pParent)
{

}

CDlgNETUI::~CDlgNETUI()
{
}

void CDlgNETUI::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgNETUI, CDialogEx)
END_MESSAGE_MAP()


// CDlgNETUI 訊息處理常式


BOOL CDlgNETUI::InitWindow(CRect rectView, CWnd *pParent, HWND hCLRWnd)
{
	if (!m_hWnd)
		if (!Create(IDD_DIALOG_NET_UI, pParent))
			return FALSE;
	::SetParent(hCLRWnd, m_hWnd);

	CWnd *pCWnd;
	pCWnd = FromHandle(hCLRWnd);
	pCWnd->ShowWindow(SW_SHOW);

	MoveWindow(rectView);
	ShowWindow(SW_SHOW);

	return TRUE;
}
