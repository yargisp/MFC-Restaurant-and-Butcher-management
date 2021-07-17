#pragma once

// MarketDialog dialog

class MarketDialog : public CDialogEx
{
	DECLARE_DYNAMIC(MarketDialog)

public:
	MarketDialog(CWnd* pParent = nullptr);   // standard constructor
	virtual ~MarketDialog();
	double Balance;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = Market_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnEnChangeColaqty();
	double ItemPrice[15];
	double Total;
	afx_msg void OnBnClickedOk();
	CString ColaQtyVar;
	CString SodaQtyVal;
	CString LemonadeQtyVal;
	CString PinkLemonadeQtyVal;
	CString TomatoQtyVal;
	CString PickleQtyVal;
	CString OnionQtyVal;
	CString LettuceQtyVal;
	CString PotatoQtyVal;
	CString BurgerKgVal;
	CString WagyuKgVal;
	CString AngusKgVal;
	CString RibsKgVal;
	CString WhiteQtyVal;
	CString WholeWheatQtyVal;
	CString Total_strVal;
	afx_msg void OnEnChangeSodaqty();
	afx_msg void OnEnChangeLemonadeqty();
	afx_msg void OnEnChangePinklemonadeqty();
	afx_msg void OnEnChangeTomatoqty();
	afx_msg void OnEnChangeOnionqty();
	afx_msg void OnEnChangeLettuceqty();
	afx_msg void OnEnChangePotatoqty();
	afx_msg void OnEnChangeBurgerkg();
	afx_msg void OnEnChangePickleqty();
	afx_msg void OnEnChangeWagyukg();
	afx_msg void OnEnChangeAnguskg();
	afx_msg void OnEnChangeRibskg();
	afx_msg void OnEnChangeWhiteqty();
	afx_msg void OnEnChangeWholewheatqty();
};
