
// MFC_NETDlg.cpp: 實作檔案
//

#include "pch.h"
#include "framework.h"
#include "MFC_NET.h"
#include "MFC_NETDlg.h"
#include "afxdialogex.h"
#include "DlgNETUI.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

extern TCHAR g_szModulePath[MAX_PATH];

void MoveXXYPLT(float fX, float fY, float fR)
{
}

BOOL IsXXYPLTMoving()
{
	return FALSE;
}

void AlarmMessage(CString strMsg)
{
}


// 對 App About 使用 CAboutDlg 對話方塊

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 對話方塊資料
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

// 程式碼實作
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCNETDlg 對話方塊



CMFCNETDlg::CMFCNETDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFC_NET_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCNETDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCNETDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CMFCNETDlg 訊息處理常式

BOOL CMFCNETDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 將 [關於...] 功能表加入系統功能表。

	// IDM_ABOUTBOX 必須在系統命令範圍之中。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 設定此對話方塊的圖示。當應用程式的主視窗不是對話方塊時，
	// 框架會自動從事此作業
	SetIcon(m_hIcon, TRUE);			// 設定大圖示
	SetIcon(m_hIcon, FALSE);		// 設定小圖示

	if (LoadNETLib())
	{
		CRect rectWindow;
		GetDlgItem(IDC_STATIC_NET_UI)->GetWindowRect(rectWindow);
		ScreenToClient(rectWindow);

		m_lptrNETDlg = m_NETCreateDlg();
		if (m_NETInitWindow(m_lptrNETDlg, rectWindow.Width(), rectWindow.Height()))
		{
			HWND hCLRWnd = m_NETGetHandle(m_lptrNETDlg);
			m_pNETWindow = new CDlgNETUI;
			m_pNETWindow->InitWindow(rectWindow, this, hCLRWnd);

			m_NETSetCbMove(m_lptrNETDlg, (LONG_PTR)MoveXXYPLT);
			m_NETSetCbMoveDone(m_lptrNETDlg, (LONG_PTR)IsXXYPLTMoving);
			m_NETSetCbAlarmMessage(m_lptrNETDlg, (LONG_PTR)AlarmMessage);
		}
		else
		{
			m_NETFreeDlg(m_lptrNETDlg);
			m_lptrNETDlg = NULL;
		}
	}

	return TRUE;  // 傳回 TRUE，除非您對控制項設定焦點
}

void CMFCNETDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

BOOL CMFCNETDlg::DestroyWindow()
{
	if (m_lptrNETDlg)
	{
		if (m_NETClose)
			m_NETClose(m_lptrNETDlg);

		if (m_NETFreeDlg)
			m_NETFreeDlg(m_lptrNETDlg);
	}

	if (m_pNETWindow)
	{
		delete m_pNETWindow;
		m_pNETWindow = NULL;
	}

	if (m_hNETDriver)
		FreeLibrary(m_hNETDriver);

	return CDialogEx::DestroyWindow();
}

// 如果將最小化按鈕加入您的對話方塊，您需要下列的程式碼，
// 以便繪製圖示。對於使用文件/檢視模式的 MFC 應用程式，
// 框架會自動完成此作業。

void CMFCNETDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 繪製的裝置內容

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 將圖示置中於用戶端矩形
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 描繪圖示
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 當使用者拖曳最小化視窗時，
// 系統呼叫這個功能取得游標顯示。
HCURSOR CMFCNETDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


BOOL CMFCNETDlg::LoadNETLib()
{
	CString strDll;
	strDll.Format(_T("%sUICLR.dll"), g_szModulePath);

	m_hNETDriver = LoadLibrary(strDll);
	if (!m_hNETDriver)
		return FALSE;

	m_NETCreateDlg = (NET_CREATE_DLG)GetProcAddress(m_hNETDriver, "CLR_CreateDialog");
	if (!m_NETCreateDlg)
		return FALSE;

	m_NETFreeDlg = (NET_FREE_DLG)GetProcAddress(m_hNETDriver, "CLR_FreeDialog");
	if (!m_NETFreeDlg)
		return FALSE;

	m_NETInitWindow = (NET_INIT_WINDOW)GetProcAddress(m_hNETDriver, "CLR_InitWindow");
	if (!m_NETInitWindow)
		return FALSE;

	m_NETClose = (NET_CLOSE)GetProcAddress(m_hNETDriver, "CLR_Close");
	if (!m_NETClose)
		return FALSE;

	m_NETGetHandle = (NET_GET_HANDLE)GetProcAddress(m_hNETDriver, "CLR_GetHandle");
	if (!m_NETGetHandle)
		return FALSE;

	m_NETAligLaserCali = (NET_ALIG_LASER_CALI)GetProcAddress(m_hNETDriver, "CLR_AlignmentLaserCali");
	if (!m_NETAligLaserCali)
		return FALSE;

	m_NETContourLaserCali = (NET_CONTOUR_LASER_CALI)GetProcAddress(m_hNETDriver, "CLR_ContourLaserCali");
	if (!m_NETContourLaserCali)
		return FALSE;

	m_NETContourLaserOffset = (NET_CONTOUR_LASER_OFFSET)GetProcAddress(m_hNETDriver, "CLR_ContourLaserOffset");
	if (!m_NETContourLaserOffset)
		return FALSE;

	m_NETAligAxisCali = (NET_ALIG_AXIS_CALI)GetProcAddress(m_hNETDriver, "CLR_AlignmentAxisCali");
	if (!m_NETAligAxisCali)
		return FALSE;

	m_NETAligRegi = (NET_ALIG_REGI)GetProcAddress(m_hNETDriver, "CLR_AlignmentRegi");
	if (!m_NETAligRegi)
		return FALSE;

	m_NETAlig = (NET_ALIG)GetProcAddress(m_hNETDriver, "CLR_Alignment");
	if (!m_NETAlig)
		return FALSE;

	m_NETContour = (NET_CONTOUR)GetProcAddress(m_hNETDriver, "CLR_Contour");
	if (!m_NETContour)
		return FALSE;

	m_NETIsAligDone = (NET_IS_ALIG_DONE)GetProcAddress(m_hNETDriver, "CLR_IsAlignmentActionFinish");
	if (!m_NETIsAligDone)
		return FALSE;

	m_NETIsContourDone = (NET_IS_CONTOUR_DONE)GetProcAddress(m_hNETDriver, "CLR_IsContourActionFinish");
	if (!m_NETIsContourDone)
		return FALSE;

	m_NETAligReset = (NET_ALIG_RESET)GetProcAddress(m_hNETDriver, "CLR_AlignmentReset");
	if (!m_NETAligReset)
		return FALSE;

	m_NETContourReset = (NET_CONTOUR_RESET)GetProcAddress(m_hNETDriver, "CLR_ContourReset");
	if (!m_NETContourReset)
		return FALSE;

	m_NETSaveParam = (NET_SAVE_PARAM)GetProcAddress(m_hNETDriver, "CLR_SaveParam");
	if (!m_NETSaveParam)
		return FALSE;

	m_NETSaveAsRecipe = (NET_SAVE_AS_RECIPE)GetProcAddress(m_hNETDriver, "CLR_SaveAsRecipe");
	if (!m_NETSaveAsRecipe)
		return FALSE;

	m_NETLoadRecipe = (NET_LOAD_RECIPE)GetProcAddress(m_hNETDriver, "CLR_LoadRecipe");
	if (!m_NETLoadRecipe)
		return FALSE;

	m_NETContourFinderShow = (NET_CONTOUR_FINDER_SHOW)GetProcAddress(m_hNETDriver, "CLR_ContourFinderShow");
	if (!m_NETContourFinderShow)
		return FALSE;

	m_NETMarkerFinderShow = (NET_MARK_FINDER_SHOW)GetProcAddress(m_hNETDriver, "CLR_MarkFinderShow");
	if (!m_NETMarkerFinderShow)
		return FALSE;

	m_NETSetCbMove = (NET_SET_CALLBACK)GetProcAddress(m_hNETDriver, "CLR_SetCallBack_Move");
	if (!m_NETSetCbMove)
		return FALSE;

	m_NETSetCbMoveDone = (NET_SET_CALLBACK)GetProcAddress(m_hNETDriver, "CLR_SetCallBack_MoveDone");
	if (!m_NETSetCbMoveDone)
		return FALSE;

	m_NETSetCbAlarmMessage = (NET_SET_CALLBACK)GetProcAddress(m_hNETDriver, "CLR_SetCallBack_AlarmMessage");
	if (!m_NETSetCbAlarmMessage)
		return FALSE;

	return TRUE;
}
