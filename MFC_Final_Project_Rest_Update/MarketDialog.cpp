// MarketDialog.cpp : implementation file
//

#include "pch.h"
#include "MFC_Final_Project_Rest_Update.h"
#include "MarketDialog.h"
#include "afxdialogex.h"


// MarketDialog dialog

IMPLEMENT_DYNAMIC(MarketDialog, CDialogEx)

MarketDialog::MarketDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(Market_DLG, pParent)
	, ColaQtyVar(_T(""))
	, SodaQtyVal(_T(""))
	, LemonadeQtyVal(_T(""))
	, PinkLemonadeQtyVal(_T(""))
	, TomatoQtyVal(_T(""))
	, PickleQtyVal(_T(""))
	, OnionQtyVal(_T(""))
	, LettuceQtyVal(_T(""))
	, PotatoQtyVal(_T(""))
	, BurgerKgVal(_T(""))
	, WagyuKgVal(_T(""))
	, AngusKgVal(_T(""))
	, RibsKgVal(_T(""))
	, WhiteQtyVal(_T(""))
	, WholeWheatQtyVal(_T(""))
	, Total_strVal(_T(""))
{

}

MarketDialog::~MarketDialog()
{
}

void MarketDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, ColaQty, ColaQtyVar);
	DDX_Text(pDX, SodaQty, SodaQtyVal);
	DDX_Text(pDX, LemonadeQty, LemonadeQtyVal);
	DDX_Text(pDX, PinkLemonadeQty, PinkLemonadeQtyVal);
	DDX_Text(pDX, TomatoQty, TomatoQtyVal);
	DDX_Text(pDX, PickleQty, PickleQtyVal);
	DDX_Text(pDX, OnionQty, OnionQtyVal);
	DDX_Text(pDX, LettuceQty, LettuceQtyVal);
	DDX_Text(pDX, PotatoQty, PotatoQtyVal);
	DDX_Text(pDX, BurgerKg, BurgerKgVal);
	DDX_Text(pDX, WagyuKg, WagyuKgVal);
	DDX_Text(pDX, AngusKg, AngusKgVal);
	DDX_Text(pDX, RibsKg, RibsKgVal);
	DDX_Text(pDX, WhiteQty, WhiteQtyVal);
	DDX_Text(pDX, WholeWheatQty, WholeWheatQtyVal);
	DDX_Text(pDX, Total_str, Total_strVal);
}


BEGIN_MESSAGE_MAP(MarketDialog, CDialogEx)
	ON_EN_CHANGE(ColaQty, &MarketDialog::OnEnChangeColaqty)
	ON_BN_CLICKED(IDOK, &MarketDialog::OnBnClickedOk)
	ON_EN_CHANGE(SodaQty, &MarketDialog::OnEnChangeSodaqty)
	ON_EN_CHANGE(LemonadeQty, &MarketDialog::OnEnChangeLemonadeqty)
	ON_EN_CHANGE(PinkLemonadeQty, &MarketDialog::OnEnChangePinklemonadeqty)
	ON_EN_CHANGE(TomatoQty, &MarketDialog::OnEnChangeTomatoqty)
	ON_EN_CHANGE(OnionQty, &MarketDialog::OnEnChangeOnionqty)
	ON_EN_CHANGE(LettuceQty, &MarketDialog::OnEnChangeLettuceqty)
	ON_EN_CHANGE(PotatoQty, &MarketDialog::OnEnChangePotatoqty)
	ON_EN_CHANGE(BurgerKg, &MarketDialog::OnEnChangeBurgerkg)
	ON_EN_CHANGE(PickleQty, &MarketDialog::OnEnChangePickleqty)
	ON_EN_CHANGE(WagyuKg, &MarketDialog::OnEnChangeWagyukg)
	ON_EN_CHANGE(AngusKg, &MarketDialog::OnEnChangeAnguskg)
	ON_EN_CHANGE(RibsKg, &MarketDialog::OnEnChangeRibskg)
	ON_EN_CHANGE(WhiteQty, &MarketDialog::OnEnChangeWhiteqty)
	ON_EN_CHANGE(WholeWheatQty, &MarketDialog::OnEnChangeWholewheatqty)
END_MESSAGE_MAP()


// MarketDialog message handlers


BOOL MarketDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	CString balance;
	balance.Format(_T("%.2lf"), Balance);
	SetDlgItemTextW(BalanceMarket, balance);
	balance.Format(_T("%.2lf"), 0.0);
	SetDlgItemTextW(Total_str, balance);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}




void MarketDialog::OnEnChangeColaqty()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here

	CString Qty; 
	GetDlgItemTextW(ColaQty, Qty);
	ItemPrice[0] = _wtof(Qty);
	ItemPrice[0] *= 2.5;
	Total = 0;
	for (int i = 0; i < 15; i++) {
		Total += ItemPrice[i];
	}
	Qty.Format(_T("%.2lf"), Total);
	SetDlgItemTextW(Total_str, Qty);
}


void MarketDialog::OnBnClickedOk() // Buy Button
{
	// TODO: Add your control notification handler code here

	CDialogEx::OnOK();
}


void MarketDialog::OnEnChangeSodaqty()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString Qty;
	GetDlgItemTextW(SodaQty, Qty);
	ItemPrice[1] = _wtof(Qty);
	ItemPrice[1] *= 2;
	Total = 0;
	for (int i = 0; i < 15; i++) {
		Total += ItemPrice[i];
	}
	Qty.Format(_T("%.2lf"), Total);
	SetDlgItemTextW(Total_str, Qty);
}


void MarketDialog::OnEnChangeLemonadeqty()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString Qty;
	GetDlgItemTextW(LemonadeQty, Qty);
	ItemPrice[2] = _wtof(Qty);
	ItemPrice[2] *= 1.5;
	Total = 0;
	for (int i = 0; i < 15; i++) {
		Total += ItemPrice[i];
	}
	Qty.Format(_T("%.2lf"), Total);
	SetDlgItemTextW(Total_str, Qty);
}


void MarketDialog::OnEnChangePinklemonadeqty()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString Qty;
	GetDlgItemTextW(PinkLemonadeQty, Qty);
	ItemPrice[3] = _wtof(Qty);
	ItemPrice[3] *= 3;
	Total = 0;
	for (int i = 0; i < 15; i++) {
		Total += ItemPrice[i];
	}
	Qty.Format(_T("%.2lf"), Total);
	SetDlgItemTextW(Total_str, Qty);

}


void MarketDialog::OnEnChangeTomatoqty()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString Qty;
	GetDlgItemTextW(TomatoQty, Qty);
	ItemPrice[4] = _wtof(Qty);
	ItemPrice[4] *= 0.3;
	Total = 0;
	for (int i = 0; i < 15; i++) {
		Total += ItemPrice[i];
	}
	Qty.Format(_T("%.2lf"), Total);
	SetDlgItemTextW(Total_str, Qty);
}


void MarketDialog::OnEnChangeOnionqty()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString Qty;
	GetDlgItemTextW(OnionQty, Qty);
	ItemPrice[6] = _wtof(Qty);
	ItemPrice[6] *= 0.2;
	Total = 0;
	for (int i = 0; i < 15; i++) {
		Total += ItemPrice[i];
	}
	Qty.Format(_T("%.2lf"), Total);
	SetDlgItemTextW(Total_str, Qty);
}


void MarketDialog::OnEnChangeLettuceqty()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString Qty;
	GetDlgItemTextW(LettuceQty, Qty);
	ItemPrice[7] = _wtof(Qty);
	ItemPrice[7] *= 0.5;
	Total = 0;
	for (int i = 0; i < 15; i++) {
		Total += ItemPrice[i];
	}
	Qty.Format(_T("%.2lf"), Total);
	SetDlgItemTextW(Total_str, Qty);
}


void MarketDialog::OnEnChangePotatoqty()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString Qty;
	GetDlgItemTextW(PotatoQty, Qty);
	ItemPrice[8] = _wtof(Qty);
	ItemPrice[8] *= 4;
	Total = 0;
	for (int i = 0; i < 15; i++) {
		Total += ItemPrice[i];
	}
	Qty.Format(_T("%.2lf"), Total);
	SetDlgItemTextW(Total_str, Qty);
}


void MarketDialog::OnEnChangeBurgerkg()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString Qty;
	GetDlgItemTextW(BurgerKg, Qty);
	ItemPrice[9] = _wtof(Qty);
	ItemPrice[9] *= 15;
	Total = 0;
	for (int i = 0; i < 15; i++) {
		Total += ItemPrice[i];
	}
	Qty.Format(_T("%.2lf"), Total);
	SetDlgItemTextW(Total_str, Qty);
}


void MarketDialog::OnEnChangePickleqty()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString Qty;
	GetDlgItemTextW(PickleQty, Qty);
	ItemPrice[5] = _wtof(Qty);
	ItemPrice[5] *= 0.5;
	Total = 0;
	for (int i = 0; i < 15; i++) {
		Total += ItemPrice[i];
	}
	Qty.Format(_T("%.2lf"), Total);
	SetDlgItemTextW(Total_str, Qty);
}


void MarketDialog::OnEnChangeWagyukg()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString Qty;
	GetDlgItemTextW(WagyuKg, Qty);
	ItemPrice[10] = _wtof(Qty);
	ItemPrice[10] *= 90;
	Total = 0;
	for (int i = 0; i < 15; i++) {
		Total += ItemPrice[i];
	}
	Qty.Format(_T("%.2lf"), Total);
	SetDlgItemTextW(Total_str, Qty);
}


void MarketDialog::OnEnChangeAnguskg()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString Qty;
	GetDlgItemTextW(AngusKg, Qty);
	ItemPrice[11] = _wtof(Qty);
	ItemPrice[11] *= 40;
	Total = 0;
	for (int i = 0; i < 15; i++) {
		Total += ItemPrice[i];
	}
	Qty.Format(_T("%.2lf"), Total);
	SetDlgItemTextW(Total_str, Qty);
}


void MarketDialog::OnEnChangeRibskg()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString Qty;
	GetDlgItemTextW(RibsKg, Qty);
	ItemPrice[12] = _wtof(Qty);
	ItemPrice[12] *= 50;
	Total = 0;
	for (int i = 0; i < 15; i++) {
		Total += ItemPrice[i];
	}
	Qty.Format(_T("%.2lf"), Total);
	SetDlgItemTextW(Total_str, Qty);
}


void MarketDialog::OnEnChangeWhiteqty()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString Qty;
	GetDlgItemTextW(WhiteQty, Qty);
	ItemPrice[13] = _wtof(Qty);
	ItemPrice[13] *= 1;
	Total = 0;
	for (int i = 0; i < 15; i++) {
		Total += ItemPrice[i];
	}
	Qty.Format(_T("%.2lf"), Total);
	SetDlgItemTextW(Total_str, Qty);
}


void MarketDialog::OnEnChangeWholewheatqty()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString Qty;
	GetDlgItemTextW(WholeWheatQty, Qty);
	ItemPrice[14] = _wtof(Qty);
	ItemPrice[14] *= 1;
	Total = 0;
	for (int i = 0; i < 15; i++) {
		Total += ItemPrice[i];
	}
	Qty.Format(_T("%.2lf"), Total);
	SetDlgItemTextW(Total_str, Qty);
}
