// DlgUICLR.cpp: 實作檔案
//

#include "pch.h"
#include "UICLR.h"
#include "DlgUICLR.h"
#include "afxdialogex.h"

MOVE g_pMove = NULL;
MOVE_DONE g_pMoveDone = NULL;
ALARM_MESSAGE g_pAlarmMessage = NULL;

void CB_Move(float fX, float fY, float fR)
{
	if (g_pMove)
		g_pMove(fX, fY, fR);
}

bool CB_MoveDone()
{
	return g_pMoveDone ? g_pMoveDone() : false;
}

void CB_AlarmMessage(System::String^ strCLR)
{
	CString strMsg = strCLR;
	if (g_pAlarmMessage)
		g_pAlarmMessage(strMsg);
}


// CDlgUICLR 對話方塊

IMPLEMENT_DYNAMIC(CDlgUICLR, CDialogEx)

CDlgUICLR::CDlgUICLR(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_UI_CLR, pParent)
{

}

CDlgUICLR::~CDlgUICLR()
{
}

void CDlgUICLR::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_ManagedControl(pDX, IDC_BUTTON_DISPLAY, m_pAOIUI);
}


BEGIN_MESSAGE_MAP(CDlgUICLR, CDialogEx)
END_MESSAGE_MAP()


// CDlgUICLR 訊息處理常式


BOOL CDlgUICLR::InitWindow(int iViewWidth, int iViewHeight)
{
	if (!m_hWnd)
		if (!Create(IDD_DIALOG_UI_CLR))
			return FALSE;
	ShowWindow(SW_HIDE);
	MoveWindow(0, 0, iViewWidth, iViewHeight);
	GetDlgItem(IDC_BUTTON_DISPLAY)->SetWindowPos(NULL, 0, 0, iViewWidth, iViewHeight, SWP_NOMOVE);

	m_pAOIUI->AOI_Move += gcnew frmAOI_UI::DelMoveCallback(CB_Move);
	m_pAOIUI->AOI_MoveDone += gcnew frmAOI_UI::DelMoveDoneCallback(CB_MoveDone);
	m_pAOIUI->AOI_AlarmMessage += gcnew frmAOI_UI::DelMsg(CB_AlarmMessage);

	return TRUE;
}


void CDlgUICLR::Close()
{
	m_pAOIUI->AOI_Close();
}


BOOL CDlgUICLR::AlignmentLaserCali()
{
	return m_pAOIUI->AOI_AlignmentLaserCali();
}


BOOL CDlgUICLR::ContourLaserCali()
{
	return m_pAOIUI->AOI_ContourLaserCali();
}


BOOL CDlgUICLR::ContourLaserOffset()
{
	return m_pAOIUI->AOI_ContourLaserOffset();
}


BOOL CDlgUICLR::AlignmentAxisCali()
{
	return m_pAOIUI->AOI_AlignmentAxisCali();
}


BOOL CDlgUICLR::AlignmentRegi()
{
	return m_pAOIUI->AOI_AlignmentRegi();
}


BOOL CDlgUICLR::Alignment()
{
	return m_pAOIUI->AOI_Alignment();
}


BOOL CDlgUICLR::Contour()
{
	return m_pAOIUI->AOI_Contour();
}

int  CDlgUICLR::IsAlignmentActionFinish()
{
	return m_pAOIUI->AOI_IsAligmentActionFinish();
}


int  CDlgUICLR::IsContourActionFinish()
{
	return m_pAOIUI->AOI_IsContourActionFinish();
}

void CDlgUICLR::AlignmentReset()
{
	m_pAOIUI->AOI_AlinmentReset();
}


void CDlgUICLR::ContourReset()
{
	m_pAOIUI->AOI_ContourReset();
}


void CDlgUICLR::SaveParam()
{
	m_pAOIUI->AOI_SaveaParam();
}


void CDlgUICLR::SaveAsRecipe(CString strRecipe)
{
	System::String^ strCLR = gcnew System::String(strRecipe);
	m_pAOIUI->AOI_SaveAsRecipe(strCLR);
}


void CDlgUICLR::LoadRecipe(CString strRecipe)
{
	System::String^ strCLR = gcnew System::String(strRecipe);
	m_pAOIUI->AOI_LoadRecipe(strCLR);
}


void CDlgUICLR::ContourFinderShow()
{
	m_pAOIUI->AOI_ContourFinderShow();
}


void CDlgUICLR::MarkFinderShow()
{
	m_pAOIUI->AOI_MarkFinderShow();
}


void CDlgUICLR::SetCallBack_Move(MOVE pFunc)
{
	g_pMove = pFunc;
}


void CDlgUICLR::SetCallBack_MoveDone(MOVE_DONE pFunc)
{
	g_pMoveDone = pFunc;
}


void CDlgUICLR::SetCallBack_AlarmMessage(ALARM_MESSAGE pFunc)
{
	g_pAlarmMessage = pFunc;
}