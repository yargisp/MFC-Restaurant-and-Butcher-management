// NewOrderButcher.cpp : implementation file
//

#include "pch.h"
#include "MFC_Final_Project_Rest_Update.h"
#include "NewOrderButcher.h"
#include "afxdialogex.h"


// NewOrderButcher dialog

IMPLEMENT_DYNAMIC(NewOrderButcher, CDialogEx)

NewOrderButcher::NewOrderButcher(CWnd* pParent /*=nullptr*/)
	: CDialogEx(NewOrderB, pParent)
	, BoolBurger(FALSE)
	, ValSlideBurger(0)
	, boolAngus(FALSE)
	, boolWagyu(FALSE)
	, boolRibs(FALSE)
{

}

NewOrderButcher::~NewOrderButcher()
{
}

void NewOrderButcher::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Check(pDX, Cb_Burger, BoolBurger);
	DDX_Control(pDX, RangeBurger, SlideBurger);
	DDX_Control(pDX, Cb_Burger, ValBurger);
	DDX_Control(pDX, BurgerKgText, BurgerTXT);
	DDX_Slider(pDX, RangeBurger, ValSlideBurger);
	DDX_Control(pDX, Cb_Angus, ValAngus);
	DDX_Control(pDX, Cb_Wagyu, ValWagyu);
	DDX_Control(pDX, Cb_Ribs, ValRibs);
	DDX_Control(pDX, RangeAngus, SlideAngus);
	DDX_Control(pDX, RangeWagyu, SlideWagyu);
	DDX_Control(pDX, RangeRibs, SlideRibs);
	DDX_Control(pDX, AngusKgText, AngusTXT);
	DDX_Control(pDX, WagyuKgText, WagyuTXT);
	DDX_Control(pDX, RibsKgText, RibsTXT);
	DDX_Check(pDX, Cb_Angus, boolAngus);
	DDX_Check(pDX, Cb_Wagyu, boolWagyu);
	DDX_Check(pDX, Cb_Ribs, boolRibs);
	DDX_Control(pDX, IDC_errorIMG, VarError);
	DDX_Control(pDX, IDC_errorTXT, VarErrorText);
}


BEGIN_MESSAGE_MAP(NewOrderButcher, CDialogEx)
	ON_BN_CLICKED(Cb_Burger, &NewOrderButcher::OnBnClickedBurger)
	ON_NOTIFY(NM_RELEASEDCAPTURE, RangeBurger, &NewOrderButcher::OnNMReleasedcaptureRangeburger)
	ON_BN_CLICKED(Cb_Angus, &NewOrderButcher::OnBnClickedAngus)
	ON_NOTIFY(NM_RELEASEDCAPTURE, RangeAngus, &NewOrderButcher::OnNMReleasedcaptureRangeangus)
	ON_BN_CLICKED(Cb_Wagyu, &NewOrderButcher::OnBnClickedWagyu)
	ON_NOTIFY(NM_RELEASEDCAPTURE, RangeWagyu, &NewOrderButcher::OnNMReleasedcaptureRangewagyu)
	ON_BN_CLICKED(Cb_Ribs, &NewOrderButcher::OnBnClickedRibs)
	ON_NOTIFY(NM_RELEASEDCAPTURE, RangeRibs, &NewOrderButcher::OnNMReleasedcaptureRangeribs)
	ON_BN_CLICKED(IDOK, &NewOrderButcher::OnBnClickedOk)
END_MESSAGE_MAP()


// NewOrderButcher message handlers


void NewOrderButcher::OnBnClickedBurger()
{
	// TODO: Add your control notification handler code here
	if (ValBurger.GetCheck()) {
		BurgerTXT.ShowWindow(true);
		SlideBurger.EnableWindow(true);
	}
	else {
		SlideBurger.EnableWindow(false);
		BurgerTXT.ShowWindow(false);
		WeightM[0] = 0;
	}
}


void NewOrderButcher::OnNMReleasedcaptureRangeburger(NMHDR* pNMHDR, LRESULT* pResult)
{
	// TODO: Add your control notification handler code here
			//BurgerKgText
	SlideBurger.SetRange(0, 100, TRUE);

	CString counter;
	counter.Format(_T("%d Kg"), SlideBurger.GetPos());
	SetDlgItemText(BurgerKgText, counter);
	BurgerTXT.ShowWindow(true);

	WeightM[0] = _wtoi(counter); //////////////////////////////// Need To check

	ItemPrice[0] = SlideBurger.GetPos() * 65;
	Total = 0;
	for (int i = 0; i < 4; i++) {
		Total += ItemPrice[i];
	}
	CString TotalStr;
	TotalStr.Format(_T("%.2lf"), Total);
	SetDlgItemText(IDTotal, TotalStr);
	*pResult = 0;
}

void NewOrderButcher::OnBnClickedAngus()
{
	// TODO: Add your control notification handler code here
	if (ValAngus.GetCheck()) {
		AngusTXT.ShowWindow(true);
		SlideAngus.EnableWindow(true);
	}
	else {
		SlideAngus.EnableWindow(false);
		AngusTXT.ShowWindow(false);
		WeightM[2] = 0;
	}
}


void NewOrderButcher::OnNMReleasedcaptureRangeangus(NMHDR* pNMHDR, LRESULT* pResult)
{
	// TODO: Add your control notification handler code here
	SlideAngus.SetRange(0, 100, TRUE);

	CString counter;
	counter.Format(_T("%d Kg"), SlideAngus.GetPos());
	SetDlgItemText(AngusKgText, counter);
	AngusTXT.ShowWindow(true);

	WeightM[2] = _wtoi(counter);

	ItemPrice[2] = SlideAngus.GetPos() * 80;
	Total = 0;
	for (int i = 0; i < 4; i++) {
		Total += ItemPrice[i];
	}
	CString TotalStr;
	TotalStr.Format(_T("%.2lf"), Total);
	SetDlgItemText(IDTotal, TotalStr);
	*pResult = 0;
}


void NewOrderButcher::OnBnClickedWagyu()
{
	// TODO: Add your control notification handler code here
	if (ValWagyu.GetCheck()) {
		WagyuTXT.ShowWindow(true);
		SlideWagyu.EnableWindow(true);
	}
	else {
		SlideWagyu.EnableWindow(false);
		WagyuTXT.ShowWindow(false);
		WeightM[1] = 0;
	}
}


void NewOrderButcher::OnNMReleasedcaptureRangewagyu(NMHDR* pNMHDR, LRESULT* pResult)
{
	// TODO: Add your control notification handler code here
	SlideWagyu.SetRange(0, 100, TRUE);

	CString counter;
	counter.Format(_T("%d Kg"), SlideWagyu.GetPos());
	SetDlgItemText(WagyuKgText, counter);
	WagyuTXT.ShowWindow(true);

	WeightM[1] = _wtoi(counter);

	ItemPrice[1] = SlideWagyu.GetPos() * 200;
	Total = 0;
	for (int i = 0; i < 4; i++) {
		Total += ItemPrice[i];
	}
	CString TotalStr;
	TotalStr.Format(_T("%.2lf"), Total);
	SetDlgItemText(IDTotal, TotalStr);
	*pResult = 0;
}


void NewOrderButcher::OnBnClickedRibs()
{
	// TODO: Add your control notification handler code here
	if (ValRibs.GetCheck()) {
		RibsTXT.ShowWindow(true);
		SlideRibs.EnableWindow(true);
	}
	else {
		SlideRibs.EnableWindow(false);
		RibsTXT.ShowWindow(false);
		WeightM[3] = 0;
	}
}


void NewOrderButcher::OnNMReleasedcaptureRangeribs(NMHDR* pNMHDR, LRESULT* pResult)
{
	// TODO: Add your control notification handler code here
	SlideRibs.SetRange(0, 100, TRUE);

	CString counter;
	counter.Format(_T("%d Kg"), SlideRibs.GetPos());
	SetDlgItemText(RibsKgText, counter);
	RibsTXT.ShowWindow(true);

	WeightM[3] = _wtoi(counter);

	ItemPrice[3] = SlideRibs.GetPos() * 95;
	Total = 0;
	for (int i = 0; i < 4; i++) {
		Total += ItemPrice[i];
	}
	CString TotalStr;
	TotalStr.Format(_T("%.2lf"), Total);
	SetDlgItemText(IDTotal, TotalStr);
	*pResult = 0;
}


BOOL NewOrderButcher::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	Total = 0.00;
	CString TotalStr;
	TotalStr.Format(_T("%.2lf"), Total);
	SetDlgItemText(IDTotal, TotalStr);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


void NewOrderButcher::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	bool flag = false;
	bool inStock = true;
	for (int i = 0; i < 4; i++) {
		if (WeightM[i] != 0)
			flag = true;
		if (WeightM[i] != 0 && WeightM[i] > Supply[i])
			inStock = false;
	}

	if(flag && inStock) CDialogEx::OnOK();

	else {
		VarError.ShowWindow(true);
		VarErrorText.ShowWindow(true);
		if(!inStock)
		SetDlgItemText(IDC_errorTXT, _T("Error: Not in Stock"));
		else
			SetDlgItemText(IDC_errorTXT, _T("Error: Please Select Meat Type"));
	}
}
