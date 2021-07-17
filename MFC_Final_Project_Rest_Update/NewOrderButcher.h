#pragma once


// NewOrderButcher dialog

class NewOrderButcher : public CDialogEx
{
	DECLARE_DYNAMIC(NewOrderButcher)

public:
	NewOrderButcher(CWnd* pParent = nullptr);   // standard constructor
	virtual ~NewOrderButcher();
	int WeightM[4] = { 0 };
	double GetTotalPrice() { return Total; };
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = NewOrderB };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	double Total;
	double ItemPrice[4];
	DECLARE_MESSAGE_MAP()
public:
	const double*Supply;
	BOOL BoolBurger;
	afx_msg void OnBnClickedBurger();
	CSliderCtrl SlideBurger;
	CButton ValBurger;
	CStatic BurgerTXT;
	int ValSlideBurger;
	afx_msg void OnNMReleasedcaptureRangeburger(NMHDR* pNMHDR, LRESULT* pResult);
	CButton ValAngus;
	CButton ValWagyu;
	CButton ValRibs;
	CSliderCtrl SlideAngus;
	CSliderCtrl SlideWagyu;
	CSliderCtrl SlideRibs;
	afx_msg void OnBnClickedAngus();
	CStatic AngusTXT;
	CStatic WagyuTXT;
	CStatic RibsTXT;
	afx_msg void OnNMReleasedcaptureRangeangus(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBnClickedWagyu();
	afx_msg void OnNMReleasedcaptureRangewagyu(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBnClickedRibs();
	afx_msg void OnNMReleasedcaptureRangeribs(NMHDR* pNMHDR, LRESULT* pResult);
	virtual BOOL OnInitDialog();
	BOOL boolAngus;
	BOOL boolWagyu;
	BOOL boolRibs;
	afx_msg void OnBnClickedOk();
	CStatic VarError;
	CStatic VarErrorText;
};
