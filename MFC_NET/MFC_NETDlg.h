
// MFC_NETDlg.h: 標頭檔
//

#pragma once

typedef LONG_PTR(__stdcall* NET_CREATE_DLG)();
typedef void(__stdcall* NET_FREE_DLG)(LONG_PTR lLibPtr);
typedef BOOL(__stdcall* NET_INIT_WINDOW)(LONG_PTR lLibPtr, int iViewWidth, int iViewHeight);
typedef void(__stdcall* NET_CLOSE)(LONG_PTR lLibPtr);
typedef HWND(__stdcall* NET_GET_HANDLE)(LONG_PTR lLibPtr);
typedef BOOL(__stdcall* NET_ALIG_LASER_CALI)(LONG_PTR lLibPtr);
typedef BOOL(__stdcall* NET_CONTOUR_LASER_CALI)(LONG_PTR lLibPtr);
typedef BOOL(__stdcall* NET_CONTOUR_LASER_OFFSET)(LONG_PTR lLibPtr);
typedef BOOL(__stdcall* NET_ALIG_AXIS_CALI)(LONG_PTR lLibPtr);
typedef BOOL(__stdcall* NET_ALIG_REGI)(LONG_PTR lLibPtr);
typedef BOOL(__stdcall* NET_ALIG)(LONG_PTR lLibPtr);
typedef BOOL(__stdcall* NET_CONTOUR)(LONG_PTR lLibPtr);
typedef int(__stdcall* NET_IS_ALIG_DONE)(LONG_PTR lLibPtr);
typedef int(__stdcall* NET_IS_CONTOUR_DONE)(LONG_PTR lLibPtr);
typedef void(__stdcall* NET_ALIG_RESET)(LONG_PTR lLibPtr);
typedef void(__stdcall* NET_CONTOUR_RESET)(LONG_PTR lLibPtr);
typedef void(__stdcall* NET_SAVE_PARAM)(LONG_PTR lLibPtr);
typedef void(__stdcall* NET_SAVE_AS_RECIPE)(LONG_PTR lLibPtr, CString strRecipe);
typedef void(__stdcall* NET_LOAD_RECIPE)(LONG_PTR lLibPtr, CString strRecipe);
typedef void(__stdcall* NET_CONTOUR_FINDER_SHOW)(LONG_PTR lLibPtr);
typedef void(__stdcall* NET_MARK_FINDER_SHOW)(LONG_PTR lLibPtr);
typedef void(__stdcall* NET_SET_CALLBACK)(LONG_PTR lLibPtr, LONG_PTR pFunc);

class CDlgNETUI;


// CMFCNETDlg 對話方塊
class CMFCNETDlg : public CDialogEx
{
// 建構
public:
	CMFCNETDlg(CWnd* pParent = nullptr);	// 標準建構函式

// 對話方塊資料
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_NET_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支援


// 程式碼實作
protected:
	HICON m_hIcon;

	// 產生的訊息對應函式
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual BOOL DestroyWindow();
	DECLARE_MESSAGE_MAP()
public:
	HINSTANCE m_hNETDriver;
	NET_CREATE_DLG m_NETCreateDlg;
	NET_FREE_DLG m_NETFreeDlg;
	NET_INIT_WINDOW m_NETInitWindow;
	NET_CLOSE m_NETClose;
	NET_GET_HANDLE m_NETGetHandle;
	NET_ALIG_LASER_CALI m_NETAligLaserCali;
	NET_CONTOUR_LASER_CALI m_NETContourLaserCali;
	NET_CONTOUR_LASER_OFFSET m_NETContourLaserOffset;
	NET_ALIG_AXIS_CALI m_NETAligAxisCali;
	NET_ALIG_REGI m_NETAligRegi;
	NET_ALIG m_NETAlig;
	NET_CONTOUR m_NETContour;
	NET_IS_ALIG_DONE m_NETIsAligDone;
	NET_IS_CONTOUR_DONE m_NETIsContourDone;
	NET_ALIG_RESET m_NETAligReset;
	NET_CONTOUR_RESET m_NETContourReset;
	NET_SAVE_PARAM m_NETSaveParam;
	NET_SAVE_AS_RECIPE m_NETSaveAsRecipe;
	NET_LOAD_RECIPE	m_NETLoadRecipe;
	NET_CONTOUR_FINDER_SHOW m_NETContourFinderShow;
	NET_MARK_FINDER_SHOW m_NETMarkerFinderShow;
	NET_SET_CALLBACK m_NETSetCbMove;
	NET_SET_CALLBACK m_NETSetCbMoveDone;
	NET_SET_CALLBACK m_NETSetCbAlarmMessage;
	BOOL LoadNETLib();

	LONG_PTR m_lptrNETDlg;
	CDlgNETUI *m_pNETWindow;
};
