
// MFC_Final_Project_Rest_UpdateDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MFC_Final_Project_Rest_Update.h"
#include "MFC_Final_Project_Rest_UpdateDlg.h"
#include "afxdialogex.h"
#include "ManagerDLG.h"
#include <fstream>


using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
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


// CMFCFinalProjectRestUpdateDlg dialog



CMFCFinalProjectRestUpdateDlg::CMFCFinalProjectRestUpdateDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFC_FINAL_PROJECT_REST_UPDATE_DIALOG, pParent)
	, BusinessName(_T(""))
	, BusinessTel(_T(""))
	, BusinessAddress(_T(""))
	, BusinessOh(_T(""))
	, BusinessCh(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCFinalProjectRestUpdateDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_B_Name, BusinessName);
	DDX_Text(pDX, IDC_EDIT_B_Telephone, BusinessTel);
	DDX_Text(pDX, IDC_EDIT_B_Address, BusinessAddress);
	DDX_Text(pDX, IDC_EDIT_OpenHours, BusinessOh);
	DDX_Text(pDX, IDC_EDIT_CloseHours, BusinessCh);
	DDX_Control(pDX, IDC_EDIT_B_Name, Bname);
	DDX_Control(pDX, IDC_EDIT_B_Telephone, BTel);
	DDX_Control(pDX, validate_s1, S1);
	DDX_Control(pDX, validate_e1, E1);
	DDX_Control(pDX, validate_s2, S2);
	DDX_Control(pDX, validate_s3, S3);
	DDX_Control(pDX, validate_s4, S4);
	DDX_Control(pDX, validate_s5, S5);
	DDX_Control(pDX, validate_e2, E2);
	DDX_Control(pDX, validate_e3, E3);
	DDX_Control(pDX, validate_e4, E4);
	DDX_Control(pDX, validate_e5, E5);
}

BEGIN_MESSAGE_MAP(CMFCFinalProjectRestUpdateDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_Save_B_Settings, &CMFCFinalProjectRestUpdateDlg::OnBnClickedSaveBSettings)
END_MESSAGE_MAP()


// CMFCFinalProjectRestUpdateDlg message handlers

BOOL CMFCFinalProjectRestUpdateDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	/// Resturant App --> Niv & Yarden
	/// 
	/// 
	/// 
	
	ifstream main("BusinessData.txt"); // open file
	if(main.is_open()){
		main.close(); // Close the file
		CMFCFinalProjectRestUpdateDlg::OnCancel(); // to close Settings Windows
		ManagerDLG window;
		window.DoModal(); // Open Main Screen of Application 
	}

	CTime time = CTime::GetCurrentTime(); // Set Cuurent Time in static text
	CString s = time.Format("%d/%m/%Y");
	SetDlgItemText(curr_date, s);

	

	///

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCFinalProjectRestUpdateDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCFinalProjectRestUpdateDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCFinalProjectRestUpdateDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMFCFinalProjectRestUpdateDlg::OnBnClickedSaveBSettings()
{
	// TODO: Add your control notification handler code here
	
	//Bname.EnableWindow(FALSE); // enable edit control

	 UpdateData(); // important

	// initial NewBussines with Rest & Butcher
	//biz[0] = new Butcher();
	//biz[1] = new Butcher();

	CString input_data[5];
	input_data[0] = BusinessName;
	input_data[1] = BusinessTel;
	input_data[2] = BusinessAddress;
	input_data[3] = BusinessOh;
	input_data[4] = BusinessCh;

	validFlag = true;

	// Valid Name
	if(Valid_Text(BusinessName)) {
		S1.ShowWindow(true);
		E1.ShowWindow(false);
	}
	else {
		S1.ShowWindow(false);
		E1.ShowWindow(true);
		validFlag = false;
	}

	// Valid Tel
	if (Valid_Digits(BusinessTel)) {
		S2.ShowWindow(true);
		E2.ShowWindow(false);
	}
	else {
		S2.ShowWindow(false);
		E2.ShowWindow(true);
		validFlag = false;
	}

	// Valid Address
	if (Valid_Address(BusinessAddress)) {
		S3.ShowWindow(true);
		E3.ShowWindow(false);
	}
	else {
		S3.ShowWindow(false);
		E3.ShowWindow(true);
		validFlag = false;
	}

	// Valid OpenHours
	if (BusinessOh != BusinessCh) {
		S4.ShowWindow(true);
		E4.ShowWindow(false);
	}
	else {
		S4.ShowWindow(false);
		E4.ShowWindow(true);
		validFlag = false;
	}

	// Valid CloseHours
	if (BusinessOh != BusinessCh) {
		S5.ShowWindow(true);
		E5.ShowWindow(false);
	}
	else {
		S5.ShowWindow(false);
		E5.ShowWindow(true);
		validFlag = false;
	}



	// show name fields in static text ctrl

	CMFCFinalProjectRestUpdateDlg::GetDlgItemText(IDC_EDIT_B_Name, input_data[0]);
	SetDlgItemText(n_test, input_data[0]);


	// if all fields validate --> Open New File and save Data
	
	if (validFlag) { 
		
		// Convert CString to String

		CT2A str(input_data[0]);

		string strVal(str);

		//

		// Create and open a text file
		ofstream MyFile("BusinessData.txt");

		// Write to the file
		for (int i = 0; i < 5; i++)
		{
			CT2A str(input_data[i]);

			string strVal(str);
			MyFile << strVal << endl;
		}
		//MyFile << "Files can be tricky, but it is fun enough!" << endl << strVal ;

		// Close the file
		MyFile.close();
	}

	next_window(validFlag);
	
}

bool CMFCFinalProjectRestUpdateDlg::Valid_Text(const CString&field)
{
	int len = field.GetLength();
	bool flag = false;
	for (int i = 0; i < len ; i++)
	{
		if (!isalpha(field[i]) && !isspace(field[i])) {
			return false;
		}
		if (isalpha(field[i])) {
			flag = true;
		}
	}
	if (flag) // check if have letter
		return true;
	else
		return false;
}

bool CMFCFinalProjectRestUpdateDlg::Valid_Digits(const CString&field)
{
	int len = field.GetLength();
	bool flag = false;
	for (int i = 0; i < len; i++)
	{
		if (!isdigit(field[i])) {
			return false;
		}
		if (isdigit(field[i])) {
			flag = true;
		}
	}
	if (flag) // check if have Digit
		return true;
	else
		return false;
}

bool CMFCFinalProjectRestUpdateDlg::Valid_Address(const CString&field)
{
	int len = field.GetLength();
	bool flag = false;
	for (int i = 0; i < len; i++)
	{
		if (!isalpha(field[i]) && !isspace(field[i]) && !isdigit(field[i]) &&field[i] != ',') {
			return false;
		}
		if (isalpha(field[i])) {
			flag = true;
		}
	}
	if (flag) // check if have letter
		return true;
	else
		return false;
}

void CMFCFinalProjectRestUpdateDlg::next_window(bool flag)
{
	if (flag) {
		CMFCFinalProjectRestUpdateDlg::OnCancel(); // to close Settings Windows
		ManagerDLG window;
		window.DoModal(); // Open Main Screen of Application 
	}
}


