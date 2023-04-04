// UICLR.cpp: 定義 DLL 的初始化常式。
//

#include "pch.h"
#include "framework.h"
#include "UICLR.h"
#include "DlgUICLR.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO:  如果這個 DLL 是動態地對 MFC DLL 連結，
//		那麼從這個 DLL 匯出的任何會呼叫
//		MFC 內部的函式，都必須在函式一開頭加上 AFX_MANAGE_STATE
//		巨集。
//
//		例如: 
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// 此處為正常函式主體
//		}
//
//		這個巨集一定要出現在每一個
//		函式中，才能夠呼叫 MFC 的內部。這意味著
//		其必須是函式內的第一個陳述式
//		，甚至必須在任何物件變數宣告前面
//		，因為它們的建構函式可能會產生對 MFC
//		DLL 內部的呼叫。
//
//		請參閱 MFC 技術提示 33 和 58 中的
//		詳細資料。
//

// CUICLRApp

BEGIN_MESSAGE_MAP(CUICLRApp, CWinApp)
END_MESSAGE_MAP()


// CUICLRApp 建構

CUICLRApp::CUICLRApp()
{
	// TODO:  在此加入建構程式碼，
	// 將所有重要的初始設定加入 InitInstance 中
}


// 唯一一個 CUICLRApp 物件

CUICLRApp theApp;


// CUICLRApp 初始化

BOOL CUICLRApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}


LONG_PTR FAR PASCAL CLR_CreateDialog()
{
	CDlgUICLR *pDlg = new CDlgUICLR;
	return (LONG_PTR)pDlg;
}


void FAR PASCAL CLR_FreeDialog(LONG_PTR lLibPtr)
{
	if (!lLibPtr)
		return;

	CDlgUICLR *pDlg = (CDlgUICLR*)lLibPtr;
	delete pDlg;
}


BOOL FAR PASCAL CLR_InitWindow(LONG_PTR lLibPtr, int iViewWidth, int iViewHeight)
{
	if (!lLibPtr)
		return FALSE;

	HINSTANCE hCurInstance = AfxGetResourceHandle();
	AfxSetResourceHandle(theApp.m_hInstance);

	CDlgUICLR *pDlg = (CDlgUICLR*)lLibPtr;
	BOOL bRet = pDlg->InitWindow(iViewWidth, iViewHeight);

	AfxSetResourceHandle(hCurInstance);

	return bRet;
}


void FAR PASCAL CLR_Close(LONG_PTR lLibPtr)
{
	if (!lLibPtr)
		return;

	CDlgUICLR *pDlg = (CDlgUICLR*)lLibPtr;
	pDlg->Close();
}


HWND FAR PASCAL CLR_GetHandle(LONG_PTR lLibPtr)
{
	if (!lLibPtr)
		return NULL;

	CDlgUICLR *pDlg = (CDlgUICLR*)lLibPtr;
	return pDlg->m_hWnd;
}


BOOL FAR PASCAL CLR_AlignmentLaserCali(LONG_PTR lLibPtr)
{
	if (!lLibPtr)
		return FALSE;

	CDlgUICLR *pDlg = (CDlgUICLR*)lLibPtr;
	return pDlg->AlignmentLaserCali();
}


BOOL FAR PASCAL CLR_ContourLaserCali(LONG_PTR lLibPtr)
{
	if (!lLibPtr)
		return FALSE;

	CDlgUICLR *pDlg = (CDlgUICLR*)lLibPtr;
	return pDlg->ContourLaserCali();
}


BOOL FAR PASCAL CLR_ContourLaserOffset(LONG_PTR lLibPtr)
{
	if (!lLibPtr)
		return FALSE;

	CDlgUICLR *pDlg = (CDlgUICLR*)lLibPtr;
	return pDlg->ContourLaserOffset();
}


BOOL FAR PASCAL CLR_AlignmentAxisCali(LONG_PTR lLibPtr)
{
	if (!lLibPtr)
		return FALSE;

	CDlgUICLR *pDlg = (CDlgUICLR*)lLibPtr;
	return pDlg->AlignmentAxisCali();
}


BOOL FAR PASCAL CLR_AlignmentRegi(LONG_PTR lLibPtr)
{
	if (!lLibPtr)
		return FALSE;

	CDlgUICLR *pDlg = (CDlgUICLR*)lLibPtr;
	return pDlg->AlignmentRegi();
}


BOOL FAR PASCAL CLR_Alignment(LONG_PTR lLibPtr)
{
	if (!lLibPtr)
		return FALSE;

	CDlgUICLR *pDlg = (CDlgUICLR*)lLibPtr;
	return pDlg->Alignment();
}


BOOL FAR PASCAL CLR_Contour(LONG_PTR lLibPtr)
{
	if (!lLibPtr)
		return FALSE;

	CDlgUICLR *pDlg = (CDlgUICLR*)lLibPtr;
	return pDlg->Contour();
}


int  FAR PASCAL CLR_IsAlignmentActionFinish(LONG_PTR lLibPtr)
{
	if (!lLibPtr)
		return 0;

	CDlgUICLR *pDlg = (CDlgUICLR*)lLibPtr;
	return pDlg->IsAlignmentActionFinish();
}


int  FAR PASCAL CLR_IsContourActionFinish(LONG_PTR lLibPtr)
{
	if (!lLibPtr)
		return 0;

	CDlgUICLR *pDlg = (CDlgUICLR*)lLibPtr;
	return pDlg->IsContourActionFinish();
}


void FAR PASCAL CLR_AlignmentReset(LONG_PTR lLibPtr)
{
	if (!lLibPtr)
		return;

	CDlgUICLR *pDlg = (CDlgUICLR*)lLibPtr;
	return pDlg->AlignmentReset();
}


void FAR PASCAL CLR_ContourReset(LONG_PTR lLibPtr)
{
	if (!lLibPtr)
		return;

	CDlgUICLR *pDlg = (CDlgUICLR*)lLibPtr;
	return pDlg->ContourReset();
}


void FAR PASCAL CLR_SaveParam(LONG_PTR lLibPtr)
{
	if (!lLibPtr)
		return;

	CDlgUICLR *pDlg = (CDlgUICLR*)lLibPtr;
	return pDlg->SaveParam();
}


void FAR PASCAL CLR_SaveAsRecipe(LONG_PTR lLibPtr, CString strRecipe)
{
	if (!lLibPtr)
		return;

	CDlgUICLR *pDlg = (CDlgUICLR*)lLibPtr;
	return pDlg->SaveAsRecipe(strRecipe);
}


void FAR PASCAL CLR_LoadRecipe(LONG_PTR lLibPtr, CString strRecipe)
{
	if (!lLibPtr)
		return;

	CDlgUICLR *pDlg = (CDlgUICLR*)lLibPtr;
	return pDlg->LoadRecipe(strRecipe);
}


void FAR PASCAL CLR_ContourFinderShow(LONG_PTR lLibPtr)
{
	if (!lLibPtr)
		return;

	CDlgUICLR *pDlg = (CDlgUICLR*)lLibPtr;
	return pDlg->ContourFinderShow();
}


void FAR PASCAL CLR_MarkFinderShow(LONG_PTR lLibPtr)
{
	if (!lLibPtr)
		return;

	CDlgUICLR *pDlg = (CDlgUICLR*)lLibPtr;
	return pDlg->MarkFinderShow();
}


void FAR PASCAL CLR_SetCallBack_Move(LONG_PTR lLibPtr, LONG_PTR pFunc)
{
	if (!lLibPtr)
		return;

	CDlgUICLR *pDlg = (CDlgUICLR*)lLibPtr;
	return pDlg->SetCallBack_Move((MOVE)pFunc);
}


void FAR PASCAL CLR_SetCallBack_MoveDone(LONG_PTR lLibPtr, LONG_PTR pFunc)
{
	if (!lLibPtr)
		return;

	CDlgUICLR *pDlg = (CDlgUICLR*)lLibPtr;
	return pDlg->SetCallBack_MoveDone((MOVE_DONE)pFunc);
}


void FAR PASCAL CLR_SetCallBack_AlarmMessage(LONG_PTR lLibPtr, LONG_PTR pFunc)
{
	if (!lLibPtr)
		return;

	CDlgUICLR *pDlg = (CDlgUICLR*)lLibPtr;
	return pDlg->SetCallBack_AlarmMessage((ALARM_MESSAGE)pFunc);
}
