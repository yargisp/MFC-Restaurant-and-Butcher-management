// ManagerDLG.cpp : implementation file
//

#include "pch.h"
#include "MFC_Final_Project_Rest_Update.h"
#include "ManagerDLG.h"
#include "afxdialogex.h"
#include "NewOrder_Dialog.h"
#include "NewOrderButcher.h"
#include "AboutDLG.h"
#include "MarketDialog.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


// ManagerDLG dialog

IMPLEMENT_DYNAMIC(ManagerDLG, CDialogEx)

ManagerDLG::ManagerDLG(CWnd* pParent /*=nullptr*/)
	: CDialogEx(ManagerDialog, pParent)
	, InputCust_Fname(_T(""))
	, InputCust_Lname(_T(""))
	, InputCust_Pnum(_T(""))
	, InputCust_Address(_T(""))
	, Search_Field(_T(""))
	, ColaSup(_T(""))
	, m_balanceFinance(_T(""))
	, m_totalprofit(_T(""))
	, m_totalFinance(_T(""))
	, m_totalButcher(_T(""))
	, m_totalRest(_T(""))
{

}

ManagerDLG::~ManagerDLG()
{
	// Delete Dynamic Memory
	delete business[0];
	delete business[1];
	delete newCustomer;
	for (int i = 0; i < CustomerList.size(); i++) {
		delete CustomerList[i];
	}
	for (int i = 0; i < OrdersList.size(); i++) {
		delete OrdersList[i];
	}
}

void ManagerDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, CustomersList, Customer_List);
	DDX_Control(pDX, NewRestOrder, CTRLorderRest);
	DDX_Control(pDX, OrderButcherRadio, CTRLorderButcher);
	DDX_Control(pDX, CFirsrN_V1, CFirsrN_V01);
	DDX_Control(pDX, CFirsrN_V2, CFirsrN_V02);
	DDX_Control(pDX, CFirsrN_V3, CFirsrN_V03);
	DDX_Control(pDX, CFirsrN_V4, CFirsrN_V04);
	DDX_Control(pDX, CFirsrN_X1, CFirsrN_X01);
	DDX_Control(pDX, CFirsrN_X2, CFirsrN_X02);
	DDX_Control(pDX, CFirsrN_X3, CFirsrN_X03);
	DDX_Control(pDX, CFirsrN_X4, CFirsrN_X04);
	DDX_Text(pDX, InputCustFname, InputCust_Fname);
	DDX_Text(pDX, InputCustLname, InputCust_Lname);
	DDX_Text(pDX, InputCustPNum, InputCust_Pnum);
	DDX_Text(pDX, InputCustAddress, InputCust_Address);
	DDX_Control(pDX, Err_PhoneNum, Eror_DupPhone);
	DDX_Control(pDX, EditCus, Edit_Customer);
	DDX_Control(pDX, DeleteCus, Delete_Customer);
	DDX_Control(pDX, SearchBTN, SearchClick);
	DDX_Text(pDX, SearchField, Search_Field);
	DDX_Text(pDX, Cola_sup, ColaSup);
	DDX_Control(pDX, OrderList, Order_List);
	DDX_Control(pDX, OrdersTab, Orders_Tab);
	DDX_Control(pDX, OrderListButcher, OrdersList_Butcher);
	DDX_Control(pDX, NewOrderClick, New_OrderVar);
	DDX_Control(pDX, Err_order, ErrorOrder);
	DDX_Control(pDX, BalanceText, m_Balance);
	DDX_Text(pDX, BalanceText, m_balanceFinance);
	DDX_Text(pDX, TotalProfit, m_totalprofit);
	DDX_Text(pDX, TotalProfitFinance, m_totalFinance);
	DDX_Text(pDX, TotalProfitB, m_totalButcher);
	DDX_Text(pDX, TotalProfitRe, m_totalRest);
	DDX_Control(pDX, errorOrders, errorOrderCTRL);
}


BEGIN_MESSAGE_MAP(ManagerDLG, CDialogEx)
	ON_BN_CLICKED(NewOrderClick, &ManagerDLG::OnBnClickedNeworderclick)
	ON_BN_CLICKED(AddCustomerClick, &ManagerDLG::OnBnClickedAddcustomerclick)
	ON_NOTIFY(LVN_ITEMACTIVATE, CustomersList, &ManagerDLG::OnLvnItemActivateCustomerslist)
	ON_NOTIFY(LVN_ITEMCHANGED, CustomersList, &ManagerDLG::OnLvnItemchangedCustomerslist)
	ON_BN_CLICKED(EditCus, &ManagerDLG::OnBnClickedEditcus)
	ON_BN_CLICKED(DeleteCus, &ManagerDLG::OnBnClickedDeletecus)
	ON_BN_CLICKED(SearchBTN, &ManagerDLG::OnBnClickedSearchbtn)

	ON_BN_CLICKED(OpenMarket, &ManagerDLG::OnBnClickedOpenmarket)
	ON_NOTIFY(BCN_HOTITEMCHANGE, OpenMarket, &ManagerDLG::OnBnHotItemChangeOpenmarket)
	ON_NOTIFY(TCN_SELCHANGE, OrdersTab, &ManagerDLG::OnTcnSelchangeOrderstab)
	ON_BN_CLICKED(NewRestOrder, &ManagerDLG::OnBnClickedNewrestorder)
	ON_BN_CLICKED(OrderButcherRadio, &ManagerDLG::OnBnClickedOrderbutcherradio)
	ON_BN_CLICKED(btnOrderComplete, &ManagerDLG::OnBnClickedbtnordercomplete)
	ON_COMMAND(aboutdlg, &ManagerDLG::Onaboutdlg)
	ON_COMMAND(saveSerialize, &ManagerDLG::Onsaveserialize)
	ON_COMMAND(OpenSerialize, &ManagerDLG::OnOpenserialize)
END_MESSAGE_MAP()


// ManagerDLG message handlers


void ManagerDLG::UpdateSupply()
{
	CString amount;

	// Drinks Supply 
	const int* Drinks = Supply.GetDrinks();
	amount.Format(_T("%d"), Drinks[0]);
	SetDlgItemText(Cola_sup, amount);

	amount.Format(_T("%d"), Drinks[1]);
	SetDlgItemText(Soda_sup, amount);

	amount.Format(_T("%d"), Drinks[2]);
	SetDlgItemText(Lemonade_sup, amount);

	amount.Format(_T("%d"), Drinks[3]);
	SetDlgItemText(PinkLemonade_sup, amount);

	// Vegs Supply 
	const int* Vegs = Supply.GetVegetables();
	amount.Format(_T("%d"), Vegs[0]);
	SetDlgItemText(Tomato_sup, amount);

	amount.Format(_T("%d"), Vegs[1]);
	SetDlgItemText(Pickle_sup, amount);

	amount.Format(_T("%d"), Vegs[2]);
	SetDlgItemText(Onion_sup, amount);

	amount.Format(_T("%d"), Vegs[3]);
	SetDlgItemText(Lettuce_sup, amount);

	amount.Format(_T("%d"), Vegs[4]);
	SetDlgItemText(Potato_sup, amount);

	// Meat Supply 
	const double* Meat = Supply.GetMeat();
	amount.Format(_T("%.2lf"), Meat[0]);
	SetDlgItemText(Burger_sup, amount);

	amount.Format(_T("%.2lf"), Meat[1]);
	SetDlgItemText(Wagyu_sup, amount);

	amount.Format(_T("%.2lf"), Meat[2]);
	SetDlgItemText(Angus_sup, amount);

	amount.Format(_T("%.2lf"), Meat[3]);
	SetDlgItemText(Ribs_sup, amount);

	// Bread Supply 
	const int* Bread = Supply.GetBreads();
	amount.Format(_T("%d"), Bread[0]);
	SetDlgItemText(White_sup, amount);

	amount.Format(_T("%d"), Bread[1]);
	SetDlgItemText(WholeWheat_sup, amount);

	// Sides Supply 
	const int* Sides = Supply.GetExtras();
	amount.Format(_T("%d"), Sides[0]);
	SetDlgItemText(FrenchFries_sup, amount);

	amount.Format(_T("%d"), Sides[1]);
	SetDlgItemText(OnionRings_Sup, amount);

	////////////////////////////////////////////////// Init Suuply
}

BOOL ManagerDLG::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here

	// Business Manager Niv & Yarden ///////////////////////
	CTime time = CTime::GetCurrentTime(); // Set Cuurent Time in static text
	CString s = time.Format("%d/%m/%y");
	SetDlgItemText(DateID, s);

	// Create a text string, which is used to output the text file
	CString BusinessD[3];
	string str;
	// Read from the text file
	ifstream MyReadFile("BusinessData.txt");

	// Use a while loop together with the getline() function to read the file line by line
	int line = 0;
	while (getline(MyReadFile, str)) {
		if (line < 3) {
			BusinessD[line++] = str.c_str();
		}
	}
	SetDlgItemText(B_nameID, BusinessD[0]);
	SetDlgItemText(B_TelID, BusinessD[1]);
	SetDlgItemText(B_AddID, BusinessD[2]);

	CString ActiveCus;
	ActiveCus.Format(_T("%d"), CustomerList.size());
	SetDlgItemText(ActiveCustomerss, ActiveCus);

	// Close the file
	MyReadFile.close();

	CString balance;
	double b = Finance.GetBalance();
	balance.Format(_T("%.2lf"), b);
	SetDlgItemText(BalanceText, balance);
	balance.Format(_T("%d"), 0);
	SetDlgItemText(TotalOrdersID, balance);

	business[0] = new Butcher;
	business[1] = new Restaurant;
	
	
	UpdateSupply();


	CString stri;
	stri.Format(_T("%.2lf"), Finance.GetProfitButcher() + Finance.GetProfitRest());
	SetDlgItemText(TotalProfit, stri);
	SetDlgItemText(TotalProfitFinance, stri);
	balance.Format(_T("%.2lf"), Finance.GetProfitButcher());
	SetDlgItemText(TotalProfitB, stri);
	SetDlgItemText(TotalProfitRe, stri);

	///


	ShowWindow(SW_MAXIMIZE);
	Customer_List.SetExtendedStyle(LVS_EX_FULLROWSELECT); // Full Row Select


	// Set Font of Summary
//CFont font;
//font.CreateFont(
//	22,                        // nHeight
//	0,                         // nWidth
//	0,                         // nEscapement
//	0,                         // nOrientation
//	FW_NORMAL,                 // nWeight
//	FALSE,                     // bItalic
//	FALSE,                     // bUnderline
//	0,                         // cStrikeOut
//	ANSI_CHARSET,              // nCharSet
//	OUT_DEFAULT_PRECIS,        // nOutPrecision
//	CLIP_DEFAULT_PRECIS,       // nClipPrecision
//	DEFAULT_QUALITY,           // nQuality
//	DEFAULT_PITCH | FF_SWISS,  // nPitchAndFamily
//	_T("Arial"));               // lpszFacename

// insert Columns to Customer List
	Customer_List.InsertColumn(0, L"id", LVCFMT_LEFT, 30);
	Customer_List.InsertColumn(1, L"First Name", LVCFMT_LEFT, 80);
	Customer_List.InsertColumn(2, L"Last Name", LVCFMT_LEFT, 80);
	Customer_List.InsertColumn(3, L"Phone", LVCFMT_LEFT, 100);
	Customer_List.InsertColumn(4, L"Address", LVCFMT_LEFT, 120);

// insert Columns to Order List
	Order_List.InsertColumn(0, L"Time", LVCFMT_LEFT, 40);
	Order_List.InsertColumn(1, L"Order Number", LVCFMT_LEFT, 90);
	Order_List.InsertColumn(3, L"Customer", LVCFMT_LEFT, 60);
	Order_List.InsertColumn(4, L"Dish", LVCFMT_LEFT, 50);
	Order_List.InsertColumn(5, L"Level", LVCFMT_LEFT, 50);
	Order_List.InsertColumn(6, L"Size", LVCFMT_LEFT, 50);
	Order_List.InsertColumn(7, L"Bread", LVCFMT_LEFT, 50);
	Order_List.InsertColumn(8, L"Vegs", LVCFMT_LEFT, 100);
	Order_List.InsertColumn(9, L"Sides", LVCFMT_LEFT, 80);
	Order_List.InsertColumn(10, L"Drink", LVCFMT_LEFT, 60);
	Order_List.InsertColumn(11, L"Price", LVCFMT_LEFT, 100);

	// Insert Cols to OrdersList_Butcher
	OrdersList_Butcher.InsertColumn(0, L"Time", LVCFMT_LEFT, 40);
	OrdersList_Butcher.InsertColumn(1, L"Order Number", LVCFMT_LEFT, 90);
	OrdersList_Butcher.InsertColumn(3, L"Customer", LVCFMT_LEFT, 120);
	OrdersList_Butcher.InsertColumn(4, L"Type of Meat", LVCFMT_LEFT, 160);
	OrdersList_Butcher.InsertColumn(5, L"Weight", LVCFMT_LEFT, 220);
	OrdersList_Butcher.InsertColumn(6, L"Price", LVCFMT_LEFT, 80);

	OrdersList_Butcher.ShowWindow(false);

	Orders_Tab.InsertItem(0, L"Restaurant", 100);
	Orders_Tab.InsertItem(1, L"Butcher", 100);
	//CTRLorderRest.SetCheck(false);

	// Full Row Select
	OrdersList_Butcher.SetExtendedStyle(LVS_EX_FULLROWSELECT); // Full Row Select
	Order_List.SetExtendedStyle(LVS_EX_FULLROWSELECT); // Full Row Select


	///////////////////////////////////////////////////////////////////


	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


void ManagerDLG::OnBnClickedNeworderclick()
{
	// TODO: Add your control notification handler code here
	Edit_Customer.EnableWindow(false);
	Delete_Customer.EnableWindow(false);

	if (CTRLorderRest.GetCheck()) {
		Customer_List.EnsureVisible(Customer_List.GetSelectionMark(), FALSE);
		Customer_List.SetFocus();
		Customer_List.SetItemState(Customer_List.GetSelectionMark(), LVIS_FOCUSED | LVIS_SELECTED, LVIS_FOCUSED | LVIS_SELECTED);
		Customer_List.SetSelectionMark(Customer_List.GetSelectionMark());
		NewOrder_Dialog window;

		window.SupplyBurger = Supply.GetMeat(0);
		window.SupplyBread = Supply.GetBreads();
		window.SupplyDrink = Supply.GetDrinks();
		window.SupplyVegs = Supply.GetVegetables();

		
		if (window.DoModal() == IDOK) // child dialog saves the value in a CString member variable m_str
		{
			CTime time = CTime::GetCurrentTime(); // Set Cuurent Time in static text
			CString s = time.Format("%H:%M");
			//////
			int pos = Customer_List.GetSelectionMark();
			CString id = Customer_List.GetItemText(pos, 0);
			int int_id = _ttoi(id);

			auto found = std::find_if(CustomerList.begin(), CustomerList.end(), [&](auto const& e) {
				return e->getID() == int_id; });

			int index = distance(CustomerList.begin(), found);
			/////
			
			if (window.BurgerF && window.salad) {
				Orders* newOrderB = new Orders(CustomerList, index, window.NewDish[0],window.BurgerGram, window.NewDish[0]->GetPrice());
				OrdersList.insert(OrdersList.end(), 1, newOrderB); // Add Order To Vector
				CString Totalorder;
				Totalorder.Format(_T("%d"), OrdersList.size());
				SetDlgItemText(TotalOrdersID, Totalorder);

				CString ID_order;
				ID_order.Format(_T("%d"), newOrderB->getOrderID());

				CString FLname;
				FLname = newOrderB->getCust()->getFirstN();
				FLname += _T(" ");
				FLname += newOrderB->getCust()->getLastN();

				CString ConvertPrice;
				ConvertPrice.Format(_T("%.2lf$"), newOrderB->getPrice() - 9.9);


				int idOrder = Order_List.InsertItem(0, newOrderB->getTime());
				Order_List.SetItemText(idOrder, 1, ID_order);
				Order_List.SetItemText(idOrder, 2, FLname);
				Order_List.SetItemText(idOrder, 3, newOrderB->getDish()->GetName());
				Order_List.SetItemText(idOrder, 4, newOrderB->getDish()->GetLevel());
				Order_List.SetItemText(idOrder, 5, newOrderB->getDish()->GetSize());
				Order_List.SetItemText(idOrder, 6, newOrderB->getDish()->GetBread());
				Order_List.SetItemText(idOrder, 7, window.VegsStr);
				Order_List.SetItemText(idOrder, 8, window.SidesStr);
				Order_List.SetItemText(idOrder, 9, window.DrinkStr);
				Order_List.SetItemText(idOrder, 10, ConvertPrice);

				ConvertPrice.Format(_T("%.2lf$"), 9.9);
				int idSalad = Order_List.InsertItem(0, newOrderB->getTime());
				Order_List.SetItemText(idSalad, 1, ID_order);
				Order_List.SetItemText(idSalad, 2, FLname);
				Order_List.SetItemText(idSalad, 3, window.NewDish[1]->GetName());
				Order_List.SetItemText(idSalad, 7, window.SaladStr);
				Order_List.SetItemText(idSalad, 10, ConvertPrice);
			}
			else if (window.BurgerF) {
				Orders* newOrderB = new Orders(CustomerList, index, window.NewDish[0],window.BurgerGram, window.NewDish[0]->GetPrice());
				OrdersList.insert(OrdersList.end(), 1, newOrderB); // Add Order To Vector
				CString Totalorder;
				Totalorder.Format(_T("%d"), OrdersList.size());
				SetDlgItemText(TotalOrdersID, Totalorder);

				CString ID_order;
				ID_order.Format(_T("%d"), newOrderB->getOrderID());

				CString FLname;
				FLname = newOrderB->getCust()->getFirstN();
				FLname += _T(" ");
				FLname += newOrderB->getCust()->getLastN();

				CString ConvertPrice;
				ConvertPrice.Format(_T("%.2lf$"), newOrderB->getPrice());


				int idOrder = Order_List.InsertItem(0, newOrderB->getTime());
				Order_List.SetItemText(idOrder, 1, ID_order);
				Order_List.SetItemText(idOrder, 2, FLname);
				Order_List.SetItemText(idOrder, 3, newOrderB->getDish()->GetName());
				Order_List.SetItemText(idOrder, 4, newOrderB->getDish()->GetLevel());
				Order_List.SetItemText(idOrder, 5, newOrderB->getDish()->GetSize());
				Order_List.SetItemText(idOrder, 6, newOrderB->getDish()->GetBread());
				Order_List.SetItemText(idOrder, 7, window.VegsStr);
				Order_List.SetItemText(idOrder, 8, window.SidesStr);
				Order_List.SetItemText(idOrder, 9, window.DrinkStr);
				Order_List.SetItemText(idOrder, 10, ConvertPrice);
			}
			else if (window.salad) {
				Orders* newOrderB = new Orders(CustomerList, index, window.NewDish[1],0, window.NewDish[1]->GetPrice());
				OrdersList.insert(OrdersList.end(), 1, newOrderB); // Add Order To Vector
				CString Totalorder;
				Totalorder.Format(_T("%d"), OrdersList.size());
				SetDlgItemText(TotalOrdersID, Totalorder);

				CString ID_order;
				ID_order.Format(_T("%d"), newOrderB->getOrderID());

				CString FLname;
				FLname = newOrderB->getCust()->getFirstN();
				FLname += _T(" ");
				FLname += newOrderB->getCust()->getLastN();

				CString ConvertPrice;
				ConvertPrice.Format(_T("%.2lf$"), newOrderB->getPrice());


				int idOrder = Order_List.InsertItem(0, newOrderB->getTime());
				Order_List.SetItemText(idOrder, 1, ID_order);
				Order_List.SetItemText(idOrder, 2, FLname);
				Order_List.SetItemText(idOrder, 3, newOrderB->getDish()->GetName());
				Order_List.SetItemText(idOrder, 6, newOrderB->getDish()->GetBread());
				Order_List.SetItemText(idOrder, 7, window.SaladStr);
				Order_List.SetItemText(idOrder, 8, window.SidesStr);
				Order_List.SetItemText(idOrder, 9, window.DrinkStr);
				Order_List.SetItemText(idOrder, 10, ConvertPrice);
			}
		}
	



	}
	else if (CTRLorderButcher.GetCheck()) {

	Customer_List.EnsureVisible(Customer_List.GetSelectionMark(), FALSE);
	Customer_List.SetFocus();
	Customer_List.SetItemState(Customer_List.GetSelectionMark(), LVIS_FOCUSED | LVIS_SELECTED, LVIS_FOCUSED | LVIS_SELECTED);
	Customer_List.SetSelectionMark(Customer_List.GetSelectionMark());


		NewOrderButcher window;
		window.Supply = Supply.GetMeat();

		if (window.DoModal() == IDOK) // child dialog saves the value in a CString member variable m_str
		{
			CTime time = CTime::GetCurrentTime(); // Set Cuurent Time in static text
			CString s = time.Format("%H:%M");


			//////

			int pos = Customer_List.GetSelectionMark();
			CString id = Customer_List.GetItemText(pos, 0);
			int int_id = _ttoi(id);

			auto found = std::find_if(CustomerList.begin(), CustomerList.end(), [&](auto const& e) {
				return e->getID() == int_id; });

			int index = distance(CustomerList.begin(), found);

			
			/////
			
			int TypeMeat[4] = { 0 };
			TypeMeat[0] = window.BoolBurger;
			TypeMeat[1] = window.boolWagyu;
			TypeMeat[2] = window.boolAngus;
			TypeMeat[3] = window.boolRibs;


			CString Type[4];
		    Type[0] = _T("Burger");
			Type[1] = _T("Wagyu");
			Type[2] = _T("Angus");
			Type[3] = _T("Ribs");
			CString SumOrder;
			CString SumWeight;
			CString ConvertKg;

			for (int i = 0; i < 4; i++) {
				if (TypeMeat[i]) {
					SumOrder += Type[i];
					SumWeight += Type[i] + _T(": ");
					ConvertKg.Format(_T("%d Kg"), window.WeightM[i]);
					SumWeight += ConvertKg;
				}
				if (TypeMeat[i])
				{
					SumOrder += _T(" , ");
					SumWeight += _T(" , ");
				}
			}
			SumOrder.Delete(SumOrder.GetLength() - 3, SumOrder.GetLength() - 1);
			SumWeight.Delete(SumWeight.GetLength() - 3, SumWeight.GetLength() - 1);

			Orders *newOrderB = new Orders(CustomerList,index,window.WeightM,window.GetTotalPrice());
			OrdersList.insert(OrdersList.end(), 1, newOrderB); // Add Order To Vector
			
			CString Totalorder;
			Totalorder.Format(_T("%d"), OrdersList.size());
			SetDlgItemText(TotalOrdersID, Totalorder);

			CString ID_order;
			ID_order.Format(_T("%d"), newOrderB->getOrderID());

			CString FLname;
			FLname = newOrderB->getCust()->getFirstN();
			FLname += _T(" ");
			FLname += newOrderB->getCust()->getLastN();
			
			CString ConvertPrice;
			ConvertPrice.Format(_T("%.2lf$"), window.GetTotalPrice());


			int idOrder = OrdersList_Butcher.InsertItem(0, newOrderB->getTime());
			OrdersList_Butcher.SetItemText(idOrder, 1,ID_order);
			OrdersList_Butcher.SetItemText(idOrder, 2, FLname);
			OrdersList_Butcher.SetItemText(idOrder, 3, SumOrder);
			OrdersList_Butcher.SetItemText(idOrder, 4, SumWeight);
			OrdersList_Butcher.SetItemText(idOrder, 5, ConvertPrice);
		}
	}
}


void ManagerDLG::OnBnClickedAddcustomerclick()
{
	// TODO: Add your control notification handler code here
	UpdateData();
	CString btnTEXT;
	GetDlgItemText(AddCustomerClick, btnTEXT);


	validFlag = true;

	// Valid First Name
	if (Valid_Text(InputCust_Fname)) {
		CFirsrN_V01.ShowWindow(true);
		CFirsrN_X01.ShowWindow(false);
	}
	else {
		CFirsrN_V01.ShowWindow(false);
		CFirsrN_X01.ShowWindow(true);
		validFlag = false;
	}

	// Valid Last Name
	if (Valid_Text(InputCust_Lname)) {
		CFirsrN_V02.ShowWindow(true);
		CFirsrN_X02.ShowWindow(false);
	}
	else {
		CFirsrN_V02.ShowWindow(false);
		CFirsrN_X02.ShowWindow(true);
		validFlag = false;
	}

	// Valid Tel
	if (Valid_Digits(InputCust_Pnum)) {
		CFirsrN_V03.ShowWindow(true);
		CFirsrN_X03.ShowWindow(false);
	}
	else {
		CFirsrN_V03.ShowWindow(false);
		CFirsrN_X03.ShowWindow(true);
		validFlag = false;
	}

	// Valid Address
	if (Valid_Address(InputCust_Address)) {
		CFirsrN_V04.ShowWindow(true);
		CFirsrN_X04.ShowWindow(false);
	}
	else {
		CFirsrN_V04.ShowWindow(false);
		CFirsrN_X04.ShowWindow(true);
		validFlag = false;
	}
	
	if (validFlag && FindDup(InputCust_Pnum) && btnTEXT != _T("update")) {
		// Update Active Customers 
		CString ActiveCus;
		ActiveCus.Format(_T("%d"), CustomerList.size()+1);
		SetDlgItemText(ActiveCustomerss, ActiveCus);
		//

		Eror_DupPhone.ShowWindow(false);
		newCustomer = new Customer;
		newCustomer->setFirstN(InputCust_Fname);
		newCustomer->setLastN(InputCust_Lname);
		newCustomer->setPhoneN(InputCust_Pnum);
		newCustomer->setAdress(InputCust_Address);
		CustomerList.insert(CustomerList.end(),1,newCustomer);
		CString id;
		id.Format(_T("%d"),newCustomer->getID());

		int idc = Customer_List.InsertItem(0, id);
		Customer_List.SetItemText(idc, 1, newCustomer->getFirstN());
		Customer_List.SetItemText(idc, 2, newCustomer->getLastN());
		Customer_List.SetItemText(idc, 3, newCustomer->getPhone());
		Customer_List.SetItemText(idc, 4, newCustomer->getAdress());


		// Clear Add new Customer
		CString Clear = _T("");
		SetDlgItemText(InputCustFname, Clear);
		SetDlgItemText(InputCustLname, Clear);
		SetDlgItemText(InputCustPNum, Clear);
		SetDlgItemText(InputCustAddress, Clear);
		
		CFirsrN_V01.ShowWindow(false);
		CFirsrN_V02.ShowWindow(false);
		CFirsrN_V03.ShowWindow(false);
		CFirsrN_V04.ShowWindow(false);
		
	}
	else if (!FindDup(InputCust_Pnum) && btnTEXT != _T("update")) {
		Eror_DupPhone.ShowWindow(true);
		CFirsrN_V03.ShowWindow(false);
		CFirsrN_X03.ShowWindow(true);
	}

	if (btnTEXT == _T("update")) {
		int pos = Customer_List.GetSelectionMark();
		CString id = Customer_List.GetItemText(pos, 0);
		int int_id = _ttoi(id);

		auto found = std::find_if(CustomerList.begin(), CustomerList.end(), [&](auto const& e) {
			return e->getID() == int_id;});
		
		// Test 
		//if (found != CustomerList.end())
		//	SetDlgItemText(AddCustomerClick, _T("Found Customer"));
		//else
		//	SetDlgItemText(AddCustomerClick, _T("not found!"));


		SetDlgItemText(AddCustomerClick, _T("Add Customer"));

		Eror_DupPhone.ShowWindow(false);
		Edit_Customer.EnableWindow(false);
		Delete_Customer.EnableWindow(false);
		
		/*CString strpos;
		strpos.Format(_T("%d"), pos);*/

		// Debug   ----- >SetDlgItemText(AddCustomerClick, strpos);

		int index = distance(CustomerList.begin(), found);

		CustomerList[index]->setFirstN(InputCust_Fname);
		CustomerList[index]->setLastN(InputCust_Lname);
		CustomerList[index]->setPhoneN(InputCust_Pnum);
		CustomerList[index]->setAdress(InputCust_Address);

		
		// Update Data inside list
		Customer_List.SetItemText(pos, 1, InputCust_Fname);
		Customer_List.SetItemText(pos, 2, InputCust_Lname);
		Customer_List.SetItemText(pos, 3, InputCust_Pnum);
		Customer_List.SetItemText(pos, 4, InputCust_Address);


		// Clear Add new Customer
		CString Clear = _T("");
		SetDlgItemText(InputCustFname, Clear);
		SetDlgItemText(InputCustLname, Clear);
		SetDlgItemText(InputCustPNum, Clear);
		SetDlgItemText(InputCustAddress, Clear);

		CFirsrN_V01.ShowWindow(false);
		CFirsrN_V02.ShowWindow(false);
		CFirsrN_V03.ShowWindow(false);
		CFirsrN_V04.ShowWindow(false);




		// Debug
		// Create and open a text file
		ofstream MyFile("debug.txt");

		for (int i = 0; i < CustomerList.size(); i++) {
			CT2A cLn(CustomerList[i]->getLastN());
			string str_Ln(cLn);
			CT2A cFn(CustomerList[i]->getFirstN());
			string str_Fn(cLn);
			MyFile << CustomerList[i]->getID() << "\t" << cFn << "\t" << cLn << endl;
		}

		// Close the file
		MyFile.close();
	}

	
}


bool ManagerDLG::Valid_Text(const CString &field)
{
	int len = field.GetLength();
	bool flag = false;
	for (int i = 0; i < len; i++)
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

bool ManagerDLG::Valid_Digits(const CString& field)
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

bool ManagerDLG::Valid_Address(const CString& field)
{
	int len = field.GetLength();
	bool flag = false;
	for (int i = 0; i < len; i++)
	{
		if (!isalpha(field[i]) && !isspace(field[i]) && !isdigit(field[i]) && field[i] != ',') {
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

bool ManagerDLG::FindDup(const CString&Phone)
{
	for (int i = 0; i < CustomerList.size() ; i++) {
		if (CustomerList[i]->getPhone() == Phone) 
			return false;
	}
	return true;

}



void ManagerDLG::OnLvnItemActivateCustomerslist(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMITEMACTIVATE pNMIA = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: Add your control notification handler code here
	Edit_Customer.EnableWindow(true);
	Delete_Customer.EnableWindow(true);
	New_OrderVar.EnableWindow(true);
	*pResult = 0;
}


void ManagerDLG::OnLvnItemchangedCustomerslist(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	Edit_Customer.EnableWindow(false);
	Delete_Customer.EnableWindow(false);
	New_OrderVar.EnableWindow(false);
	*pResult = 0;
}



void ManagerDLG::OnBnClickedEditcus()
{
	// TODO: Add your control notification handler code here
	Eror_DupPhone.ShowWindow(false);
	CFirsrN_V01.ShowWindow(false);
	CFirsrN_V02.ShowWindow(false);
	CFirsrN_V03.ShowWindow(false);
	CFirsrN_V04.ShowWindow(false);
	CFirsrN_X01.ShowWindow(false);
	CFirsrN_X02.ShowWindow(false);
	CFirsrN_X03.ShowWindow(false);
	CFirsrN_X04.ShowWindow(false);

	Delete_Customer.EnableWindow(false);

	int pos = Customer_List.GetSelectionMark();
	CString  data = Customer_List.GetItemText(pos, 1);
	CString  data2 = Customer_List.GetItemText(pos, 2);
	CString  data3 = Customer_List.GetItemText(pos, 3);
	CString  data4 = Customer_List.GetItemText(pos, 4);
	//CString Clear = _T("");
	SetDlgItemText(InputCustFname, data);
	SetDlgItemText(InputCustLname, data2);
	SetDlgItemText(InputCustPNum, data3);
	SetDlgItemText(InputCustAddress, data4);
	SetDlgItemText(AddCustomerClick, _T("update"));
}


void ManagerDLG::OnBnClickedDeletecus()
{
	// TODO: Add your control notification handler code here

	int pos = Customer_List.GetSelectionMark();
	CString id = Customer_List.GetItemText(pos, 0);
	int int_id = _ttoi(id);

	auto found = std::find_if(CustomerList.begin(), CustomerList.end(), [&](auto const& e) {
		return e->getID() == int_id; });


	if (!CustomerList.empty()) {
		int index = distance(CustomerList.begin(), found);
		delete CustomerList[index];
		CustomerList.erase(found);
	}
	Customer_List.DeleteItem(pos);

	// Debug
		// Create and open a text file
	ofstream MyFile("debug.txt");

	for (int i = 0; i < CustomerList.size(); i++) {
		CT2A cLn(CustomerList[i]->getLastN());
		string str_Ln(cLn);
		CT2A cFn(CustomerList[i]->getFirstN());
		string str_Fn(cLn);
		MyFile << CustomerList[i]->getID() << "\t" << cFn << "\t" << cLn << endl;
	}

	// Close the file
	MyFile.close();

	// Update Active Customers 
	CString ActiveCus;
	int s = CustomerList.size() == 0 ? 0 : CustomerList.size() + 1;
	ActiveCus.Format(_T("%d"), s);
	SetDlgItemText(ActiveCustomerss, ActiveCus);
	//
}


void ManagerDLG::OnBnClickedSearchbtn()
{
	// TODO: Add your control notification handler code here
		int col = 3;
		bool foundit = false;
		CString data;
		CString sizetxt;
		GetDlgItemTextW(SearchField, data);//insert the text to data
		for (int i = 0; i < Customer_List.GetItemCount(); i++)
		{
			sizetxt = Customer_List.GetItemText(i, col);
			if (sizetxt == data)
			{
				foundit = true;
				Customer_List.EnsureVisible(i, FALSE);
				Customer_List.SetFocus();
				Customer_List.SetItemState(i, LVIS_FOCUSED | LVIS_SELECTED, LVIS_FOCUSED | LVIS_SELECTED);
				Customer_List.SetSelectionMark(i);
				Edit_Customer.EnableWindow(true);
				Delete_Customer.EnableWindow(true);
			}
		}
		if (!foundit) {
			SetDlgItemText(SearchField, _T("No Exist!"));
		}
}


void ManagerDLG::OnBnClickedOpenmarket()
{
	// TODO: Add your control notification handler code here
	MarketDialog window;
	window.Balance = Finance.GetBalance();

	if (window.DoModal() == IDOK) // child dialog saves the value in a CString member variable m_str
	{
		// Witdhraw Money From Finanace
		double temp = window.Total;
		Finance.Witdhraw(temp);
		
		// Update Date in Balance 
		CString str;
		str.Format(_T("%.2lf"), Finance.GetBalance());
		SetDlgItemTextW(BalanceText, str);

		// Update Supply AND edit Text
		// Drinks
		int newQty[15];
		newQty[0] = Supply.GetDrink(0) + _wtoi(window.ColaQtyVar);
		newQty[1] = Supply.GetDrink(1) + _wtoi(window.SodaQtyVal);
		newQty[2] = Supply.GetDrink(2) + _wtoi(window.LemonadeQtyVal);
		newQty[3] = Supply.GetDrink(3) + _wtoi(window.PinkLemonadeQtyVal);

		newQty[4] = Supply.GetVegs(0) + _wtoi(window.TomatoQtyVal);
		newQty[5] = Supply.GetVegs(1) + _wtoi(window.PickleQtyVal);
		newQty[6] = Supply.GetVegs(2) + _wtoi(window.OnionQtyVal);
		newQty[7] = Supply.GetVegs(3) + _wtoi(window.LettuceQtyVal);
		newQty[8] = Supply.GetVegs(4) + _wtoi(window.PotatoQtyVal);

		newQty[9] = int(Supply.GetMeat(0)) + _wtoi(window.BurgerKgVal);
		newQty[10] = int(Supply.GetMeat(1)) + _wtoi(window.WagyuKgVal);
		newQty[11] = int(Supply.GetMeat(2)) + _wtoi(window.AngusKgVal);
		newQty[12] = int(Supply.GetMeat(3)) + _wtoi(window.RibsKgVal);


		newQty[13] = Supply.GetBread(0) + _wtoi(window.WhiteQtyVal);
		newQty[14] = Supply.GetBread(1) + _wtoi(window.WholeWheatQtyVal);

		for (int i = 0; i < 4; i++)
		{
			Supply.SetDrink(i, newQty[i]);
		}

		for (int i = 0; i < 5; i++)
		{
			Supply.SetVegs(i, newQty[i+4]);
		}
		for (int i = 0; i < 4; i++)
		{
			Supply.SetMeat(i, newQty[i + 9]);
		}
		for (int i = 0; i < 2; i++)
		{
			Supply.SetBread(i, newQty[i + 13]);
		}
		
		UpdateSupply();
		
		
		//

	}
	
}


void ManagerDLG::OnBnHotItemChangeOpenmarket(NMHDR* pNMHDR, LRESULT* pResult)
{
	// This feature requires Internet Explorer 6 or greater.
	// The symbol _WIN32_IE must be >= 0x0600.
	LPNMBCHOTITEM pHotItem = reinterpret_cast<LPNMBCHOTITEM>(pNMHDR);
	// TODO: Add your control notification handler code here


	*pResult = 0;
}



void ManagerDLG::OnTcnSelchangeOrderstab(NMHDR* pNMHDR, LRESULT* pResult)
{
	// TODO: Add your control notification handler code here
	if (Orders_Tab.GetCurFocus() == 0) {
		Order_List.ShowWindow(true);
		OrdersList_Butcher.ShowWindow(false);
		//List1.InsertColumn(0, L"Time", LVCFMT_LEFT, 40);
		//List1.InsertColumn(1, L"Order Number", LVCFMT_LEFT, 40);
		//List1.InsertColumn(2, L"Restaurant / Butcher", LVCFMT_LEFT, 60);
	}
	else {
		Order_List.ShowWindow(false);
		OrdersList_Butcher.ShowWindow(true);
	}
	*pResult = 0;
}


void ManagerDLG::OnBnClickedNewrestorder()
{
	// TODO: Add your control notification handler code here
	Customer_List.EnsureVisible(Customer_List.GetSelectionMark(), FALSE);
	Customer_List.SetFocus();
	Customer_List.SetItemState(Customer_List.GetSelectionMark(), LVIS_FOCUSED | LVIS_SELECTED, LVIS_FOCUSED | LVIS_SELECTED);
	Customer_List.SetSelectionMark(Customer_List.GetSelectionMark());
}


void ManagerDLG::OnBnClickedOrderbutcherradio()
{
	// TODO: Add your control notification handler code here
	Customer_List.EnsureVisible(Customer_List.GetSelectionMark(), FALSE);
	Customer_List.SetFocus();
	Customer_List.SetItemState(Customer_List.GetSelectionMark(), LVIS_FOCUSED | LVIS_SELECTED, LVIS_FOCUSED | LVIS_SELECTED);
	Customer_List.SetSelectionMark(Customer_List.GetSelectionMark());
}


void ManagerDLG::OnBnClickedbtnordercomplete()
{
	// TODO: Add your control notification handler code here
	int pos;
	CString id;
	if (Orders_Tab.GetCurFocus() == 0) {
		pos = Order_List.GetSelectionMark();
		id = Order_List.GetItemText(pos, 1);
	}
	else {
		pos = OrdersList_Butcher.GetSelectionMark();
		id = OrdersList_Butcher.GetItemText(pos, 1);
	}
	if (!OrdersList.empty()) {

		int int_id = _ttoi(id);

		auto found = std::find_if(OrdersList.begin(), OrdersList.end(), [&](auto const& e) {
			return e->getOrderID() == int_id; });

		int index = distance(OrdersList.begin(), found);

		if (Orders_Tab.GetCurFocus() == 0 && Order_List.GetItemCount()) {



			double* arr = OrdersList[index]->GetMeatW();

			bool flag = true;


			int* arrVeg = OrdersList[index]->getDish()->GetVegs();
			int* arrDrink = OrdersList[index]->getDish()->getDrinks();

			int bread;
			if (OrdersList[index]->getDish()->GetBread() == _T("White"))
				bread = 0;
			else bread = 1;


			for (int i = 0; i < 5; i++) {
				int tmp = Supply.GetVegs(i);
				int tmpD = Supply.GetDrink(i);
				if (arrVeg[i] > tmp)
					flag = false;
				if ((i < 4) && (arrDrink[i] > tmpD))
					flag = false;
			}

			// Check Burger Supply
			double tmp = Supply.GetMeat(0);
			if (arr[0] > tmp)
				flag = false;

			// Check Bread
			int tmpB = Supply.GetBread(bread);
			if (tmpB < 1) flag = false;

			if (flag) {
				// Update Burger Supply

				int tmp;
				double tmpi = Supply.GetMeat(0) - arr[0];
				Supply.SetMeat(0, tmpi);

				int qty;
				CString br;
				br = OrdersList[index]->getDish()->GetBread();
				if (br == _T("")) qty = 0;
				else qty = 1;
				tmp = Supply.GetBread(bread) - qty;
				Supply.SetBread(bread, tmp);

				for (int i = 0; i < 5; i++) {

					tmp = Supply.GetVegs(i);
					Supply.SetVegs(i, tmp - arrVeg[i]);

					if (i < 4) {
						tmp = Supply.GetDrink(3 - i);
						Supply.SetDrink(3 - i, tmp - arrDrink[i]);
					}
				}

				UpdateSupply();
				CString balance;
				Finance.AddProfitRest(OrdersList[index]->getPrice());
				Finance.deposit(OrdersList[index]->getPrice());
				double b = Finance.GetBalance();
				balance.Format(_T("%.2lf"), b);
				SetDlgItemText(BalanceText, balance);
				balance.Format(_T("%.2lf"), Finance.GetProfitButcher() + Finance.GetProfitRest());
				SetDlgItemText(TotalProfit, balance);
				SetDlgItemText(TotalProfitFinance, balance);
				balance.Format(_T("%.2lf"), Finance.GetProfitRest());
				SetDlgItemText(TotalProfitRe, balance);


				if (!OrdersList.empty())OrdersList.erase(found); // Remove From Vector
				Order_List.DeleteItem(pos);
				ErrorOrder.ShowWindow(false);
				errorOrderCTRL.ShowWindow(false);

				CString Totalorder;
				Totalorder.Format(_T("%d"), OrdersList.size());
				SetDlgItemText(TotalOrdersID, Totalorder);

			}
			else {
				ErrorOrder.ShowWindow(true);
				errorOrderCTRL.ShowWindow(true);
			}


			/////////////////////////////////////////////////////////////////////////////
		}
		else if(OrdersList_Butcher.GetItemCount()){
			double* arr = OrdersList[index]->GetMeatW();
			bool flag = true;
			for (int i = 0; i < 4; i++) {
				double tmp = Supply.GetMeat(i);
				if (arr[i] > tmp)
					flag = false;
			}
			if (flag) {

				double tmp;
				for (int i = 0; i < 4; i++) {
					tmp = Supply.GetMeat(i);
					Supply.SetMeat(i, tmp - arr[i]);
				}
				UpdateSupply();
				CString balance;
				Finance.AddProfitButcher(OrdersList[index]->getPrice());
				Finance.deposit(OrdersList[index]->getPrice());
				double b = Finance.GetBalance();
				balance.Format(_T("%.2lf"), b);
				SetDlgItemText(BalanceText, balance);
				balance.Format(_T("%.2lf"), Finance.GetProfitButcher() + Finance.GetProfitRest());
				SetDlgItemText(TotalProfit, balance);
				SetDlgItemText(TotalProfitFinance, balance);
				balance.Format(_T("%.2lf"), Finance.GetProfitButcher());
				SetDlgItemText(TotalProfitB, balance);


				if (!OrdersList.empty()) OrdersList.erase(found); // Remove From Vector
				OrdersList_Butcher.DeleteItem(pos);
				ErrorOrder.ShowWindow(false);
				errorOrderCTRL.ShowWindow(false);

				CString Totalorder;
				Totalorder.Format(_T("%d"), OrdersList.size());
				SetDlgItemText(TotalOrdersID, Totalorder);
			}
			else {
				ErrorOrder.ShowWindow(true);
				errorOrderCTRL.ShowWindow(true);
			}
		}
	} else
	Order_List.DeleteItem(pos);
}


void ManagerDLG::Onaboutdlg()
{
	// TODO: Add your command handler code here
	AboutDLG window;
	window.DoModal();
}


void ManagerDLG::Onsaveserialize()
{
	// TODO: Add your command handler code here
	   // TODO: Add your control notification handler code here
	UpdateData(TRUE);
	CFile file;
	file.Open(L"FinanceData.hse", CFile::modeCreate | CFile::modeWrite);
	CArchive ar(&file, CArchive::store);

	Finance.Serialize(ar);
	ar.Close();
	MessageBox(_T("File Saved."), _T("Yarden And Niv Business Managment"),
		MB_ICONASTERISK | MB_OK);
}


void ManagerDLG::OnOpenserialize()
{
	// TODO: Add your command handler code here
	UpdateData(TRUE);

	CFile file;

	file.Open(L"FinanceData.hse", CFile::modeRead);
	CArchive ar(&file, CArchive::load);

	Finance.Serialize(ar);
	CString str;
	str.Format(_T("%.2lf"), Finance.GetBalance());
	m_balanceFinance = str;
	str.Format(_T("%.2lf"), Finance.GetProfitRest());
	m_totalRest = str;
	str.Format(_T("%.2lf"), Finance.GetProfitButcher());
	m_totalButcher = str;
	str.Format(_T("%.2lf"), Finance.GetProfitButcher() + Finance.GetProfitRest());
	m_totalFinance = str;
	m_totalprofit = str;


	ar.Close();
	file.Close();

	Invalidate();
	UpdateData(FALSE);
}


