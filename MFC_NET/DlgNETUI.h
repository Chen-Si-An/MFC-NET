#pragma once


// CDlgNETUI 對話方塊

class CDlgNETUI : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgNETUI)

public:
	CDlgNETUI(CWnd* pParent = nullptr);   // 標準建構函式
	virtual ~CDlgNETUI();

// 對話方塊資料
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_NET_UI };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

	DECLARE_MESSAGE_MAP()
public:
	BOOL InitWindow(CRect rectView, CWnd *pParent, HWND hCLRWnd);
};
