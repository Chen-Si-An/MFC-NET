// UICLR.h: UICLR DLL 的主要標頭檔
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// 主要符號


// CUICLRApp
// 此類別的實作請參閱 UICLR.cpp
//

class CUICLRApp : public CWinApp
{
public:
	CUICLRApp();

// 覆寫
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
