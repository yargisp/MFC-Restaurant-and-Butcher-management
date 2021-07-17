#pragma once


// AboutDLG dialog

class AboutDLG : public CDialogEx
{
	DECLARE_DYNAMIC(AboutDLG)

public:
	AboutDLG(CWnd* pParent = nullptr);   // standard constructor
	virtual ~AboutDLG();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
