#pragma once
#include "Customer.h"
#include "Business.h"
#include "Butcher.h"
#include "Supply.h"
#include "Finance.h"
#include "Orders.h"
#include <vector>
using std::vector;

// ManagerDLG dialog

class ManagerDLG : public CDialogEx
{
	DECLARE_DYNAMIC(ManagerDLG)

public:
	ManagerDLG(CWnd* pParent = nullptr);   // standard constructor
	virtual ~ManagerDLG();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = ManagerDialog };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	
	Finance Finance;
	Business *business[2];
	Customer* newCustomer;
	Supply Supply;
	vector <Customer*> CustomerList;
	vector <Orders*> OrdersList;
	
	void UpdateSupply();
	DECLARE_MESSAGE_MAP()
public:
	double BuyItemsSum;
	virtual BOOL OnInitDialog();
	CListCtrl Customer_List;
	afx_msg void OnBnClickedNeworderclick();
	CButton CTRLorderRest;
	CButton CTRLorderButcher;
	CStatic CFirsrN_V01;
	CStatic CFirsrN_V02;
	CStatic CFirsrN_V03;
	CStatic CFirsrN_V04;
	CStatic CFirsrN_X01;
	CStatic CFirsrN_X02;
	CStatic CFirsrN_X03;
	CStatic CFirsrN_X04;
	CString InputCust_Fname;
	CString InputCust_Lname;
	CString InputCust_Pnum;
	CString InputCust_Address;
	afx_msg void OnBnClickedAddcustomerclick();
	bool validFlag;
	bool Valid_Text(const CString&);
	bool Valid_Digits(const CString&);
	bool Valid_Address(const CString&);
	bool FindDup(const CString&);
	CStatic Eror_DupPhone;
	CButton Edit_Customer;
	CButton Delete_Customer;
	afx_msg void OnLvnItemActivateCustomerslist(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnLvnItemchangedCustomerslist(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBnClickedEditcus();
	afx_msg void OnBnClickedDeletecus();
	CButton SearchClick;
	CString Search_Field;
	afx_msg void OnBnClickedSearchbtn();
	CString ColaSup;
	afx_msg void OnBnClickedOpenmarket();
	afx_msg void OnBnHotItemChangeOpenmarket(NMHDR* pNMHDR, LRESULT* pResult);
	CListCtrl Order_List;
	CTabCtrl Orders_Tab;
	afx_msg void OnTcnSelchangeOrderstab(NMHDR* pNMHDR, LRESULT* pResult);
	CListCtrl OrdersList_Butcher;
	CButton New_OrderVar;
	afx_msg void OnBnClickedNewrestorder();
	afx_msg void OnBnClickedOrderbutcherradio();
	afx_msg void OnBnClickedbtnordercomplete();
	CStatic ErrorOrder;
	afx_msg void Onaboutdlg();
	afx_msg void Onsaveserialize();
	afx_msg void OnOpenserialize();
	CStatic m_Balance;
	CString m_balanceFinance;
	CString m_totalprofit;
	CString m_totalFinance;
	CString m_totalButcher;
	CString m_totalRest;
	CStatic errorOrderCTRL;
};
