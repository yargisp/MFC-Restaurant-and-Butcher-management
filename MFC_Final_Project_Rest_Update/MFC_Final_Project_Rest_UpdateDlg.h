
// MFC_Final_Project_Rest_UpdateDlg.h : header file
//

#pragma once
#include "Butcher.h"

// CMFCFinalProjectRestUpdateDlg dialog
class CMFCFinalProjectRestUpdateDlg : public CDialogEx
{
// Construction
public:
	CMFCFinalProjectRestUpdateDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_FINAL_PROJECT_REST_UPDATE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

	// Edit By Niv --> Business Application ---------------------------

	// Business *biz[2]; // Polymorphisem


	// Business Apllication --------------------------------------------

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedSaveBSettings();
	CString BusinessName;
	CString BusinessTel;
	CString BusinessAddress;
	CString BusinessOh;
	CString BusinessCh;
	CEdit Bname;
	bool validFlag;
	bool Valid_Text(const CString&);
	bool Valid_Digits(const CString&);
	bool Valid_Address(const CString&);
	void next_window(bool);
	CEdit BTel;	
	CStatic S1;
	CStatic E1;
	CStatic S2;
	CStatic S3;
	CStatic S4;
	CStatic S5;
	CStatic E2;
	CStatic E3;
	CStatic E4;
	CStatic E5;
};
