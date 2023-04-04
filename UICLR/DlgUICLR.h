#pragma once

#include "afxwinforms.h"

using namespace TPK_Laser;

typedef void(*MOVE)(float, float, float);
typedef BOOL(*MOVE_DONE)();
typedef void(*ALARM_MESSAGE)(CString);


// CDlgUICLR 對話方塊

class CDlgUICLR : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgUICLR)

public:
	CDlgUICLR(CWnd* pParent = nullptr);   // 標準建構函式
	virtual ~CDlgUICLR();

// 對話方塊資料
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_UI_CLR };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

	DECLARE_MESSAGE_MAP()
public:
	CWinFormsControl<frmAOI_UI> m_pAOIUI;	//Declare C# class in CLR project

	BOOL InitWindow(int iViewWidth, int iViewHeight);
	void Close();
	BOOL AlignmentLaserCali();
	BOOL ContourLaserCali();
	BOOL ContourLaserOffset();
	BOOL AlignmentAxisCali();
	BOOL AlignmentRegi();
	BOOL Alignment();
	BOOL Contour();
	int  IsAlignmentActionFinish();
	int  IsContourActionFinish();
	void AlignmentReset();
	void ContourReset();
	void SaveParam();
	void SaveAsRecipe(CString strRecipe);
	void LoadRecipe(CString strRecipe);
	void ContourFinderShow();
	void MarkFinderShow();
	void SetCallBack_Move(MOVE pFunc);
	void SetCallBack_MoveDone(MOVE_DONE pFunc);
	void SetCallBack_AlarmMessage(ALARM_MESSAGE pFunc);
};
