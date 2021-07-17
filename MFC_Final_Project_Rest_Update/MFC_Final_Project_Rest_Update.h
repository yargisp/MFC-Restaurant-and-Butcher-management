
// MFC_Final_Project_Rest_Update.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMFCFinalProjectRestUpdateApp:
// See MFC_Final_Project_Rest_Update.cpp for the implementation of this class
//

class CMFCFinalProjectRestUpdateApp : public CWinApp
{
public:
	CMFCFinalProjectRestUpdateApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMFCFinalProjectRestUpdateApp theApp;
