// NewOrder_Dialog.cpp : implementation file
//

#include "pch.h"
#include "MFC_Final_Project_Rest_Update.h"
#include "NewOrder_Dialog.h"
#include "afxdialogex.h"


// NewOrder_Dialog dialog

IMPLEMENT_DYNAMIC(NewOrder_Dialog, CDialogEx)

NewOrder_Dialog::NewOrder_Dialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(NewOrder, pParent)
{

}

NewOrder_Dialog::~NewOrder_Dialog()
{
}

void NewOrder_Dialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, Cb_Tomato_Salad, TomatoS);
	DDX_Control(pDX, Cb_Pickle_Salad, PickleS);
	DDX_Control(pDX, Cb_Onion_Salad, OnionS);
	DDX_Control(pDX, Cb_Lettuce_Salad, LettuceS);
	DDX_Control(pDX, AddSalad_ID, AddS);
	DDX_Control(pDX, Id_100g, g100_var);
	DDX_Control(pDX, Id_220g, g220_var);
	DDX_Control(pDX, Id_350g, g350_var);
	DDX_Control(pDX, ID_DoubleBurger, DoubleBurger_var);
	DDX_Control(pDX, M_ID, M_var);
	DDX_Control(pDX, MW_ID, MW_var);
	DDX_Control(pDX, WD_ID, WD_var);
	DDX_Control(pDX, id_NoTomato, NoT_var);
	DDX_Control(pDX, id_NoPickle, NoP_var);
	DDX_Control(pDX, id_NoOnion, NoO_var);
	DDX_Control(pDX, id_NoLettuce, NoL_var);
	DDX_Control(pDX, ID_b_w, Bread_w);
	DDX_Control(pDX, ID_b_whole, Bread_wholew);
	DDX_Control(pDX, id_OnionRings, var_OnionRings);
	DDX_Control(pDX, id_fries, var_Fries);
	DDX_Control(pDX, id_PLemonade, PLemonade);
	DDX_Control(pDX, id_Lemonade, Lemonade);
	DDX_Control(pDX, id_Soda, Soda);
	DDX_Control(pDX, id_Cola, Cola);
	DDX_Control(pDX, error_txt, errTXT);
	DDX_Control(pDX, error_img, errorIMG);
	DDX_Control(pDX, error_msg, errMSG);
}


BEGIN_MESSAGE_MAP(NewOrder_Dialog, CDialogEx)
	ON_BN_CLICKED(AddSalad_ID, &NewOrder_Dialog::OnBnClickedId)
	ON_BN_CLICKED(IDOK, &NewOrder_Dialog::OnBnClickedOk)
	ON_BN_CLICKED(Id_100g, &NewOrder_Dialog::OnBnClicked100g)
	ON_BN_CLICKED(Id_220g, &NewOrder_Dialog::OnBnClicked220g)
	ON_BN_CLICKED(Id_350g, &NewOrder_Dialog::OnBnClicked350g)
	ON_BN_CLICKED(ID_DoubleBurger, &NewOrder_Dialog::OnBnClickedDoubleburger)
	ON_BN_CLICKED(id_WithoutAll_Btn, &NewOrder_Dialog::OnBnClickedWithoutallBtn)
	ON_BN_CLICKED(M_ID, &NewOrder_Dialog::OnClickedMediumId)
	ON_BN_CLICKED(id_NoTomato, &NewOrder_Dialog::OnBnClickedNotomato)
	ON_BN_CLICKED(MW_ID, &NewOrder_Dialog::OnBnClickedMediumWell)
	ON_BN_CLICKED(WD_ID, &NewOrder_Dialog::OnBnClickedWellDone)
	ON_BN_CLICKED(id_NoPickle, &NewOrder_Dialog::OnBnClickedNopickle)
	ON_BN_CLICKED(id_NoOnion, &NewOrder_Dialog::OnBnClickedNoonion)
	ON_BN_CLICKED(id_NoLettuce, &NewOrder_Dialog::OnBnClickedNolettuce)
	ON_BN_CLICKED(ID_b_w, &NewOrder_Dialog::OnBnClickedbw)
	ON_BN_CLICKED(ID_b_whole, &NewOrder_Dialog::OnBnClickedbwhole)
	ON_BN_CLICKED(id_fries, &NewOrder_Dialog::OnBnClickedfries)
	ON_BN_CLICKED(id_OnionRings, &NewOrder_Dialog::OnBnClickedOnionrings)
	ON_BN_CLICKED(id_PLemonade, &NewOrder_Dialog::OnBnClickedPlemonade)
	ON_BN_CLICKED(id_Lemonade, &NewOrder_Dialog::OnBnClickedLemonade)
	ON_BN_CLICKED(id_Soda, &NewOrder_Dialog::OnBnClickedSoda)
	ON_BN_CLICKED(id_Cola, &NewOrder_Dialog::OnBnClickedCola)
	ON_BN_CLICKED(Cb_Tomato_Salad, &NewOrder_Dialog::OnBnClickedTomatoSalad)
	ON_BN_CLICKED(Cb_Pickle_Salad, &NewOrder_Dialog::OnBnClickedPickleSalad)
	ON_BN_CLICKED(Cb_Onion_Salad, &NewOrder_Dialog::OnBnClickedOnionSalad)
	ON_BN_CLICKED(Cb_Lettuce_Salad, &NewOrder_Dialog::OnBnClickedLettuceSalad)
END_MESSAGE_MAP()


// NewOrder_Dialog message handlers


void NewOrder_Dialog::OnBnClickedId()
{
	// TODO: Add your control notification handler code here
	if (AddS.GetCheck()) {
		salad = true;
		TomatoS.EnableWindow(true);
		PickleS.EnableWindow(true);
		LettuceS.EnableWindow(true);
		OnionS.EnableWindow(true);
	}
	else {
		salad = false;
		TomatoS.EnableWindow(false);
		PickleS.EnableWindow(false);
		LettuceS.EnableWindow(false);
		OnionS.EnableWindow(false);
	}
}


void NewOrder_Dialog::OnBnClickedOk()
{
	bool inStock = true;
	for (int i = 0; i < 4; i++) {
		VegsQty[i] += BurgerVegs[i];
		if(salad) VegsQty[i] += SaladVegs[i];
	}
	if (Sides[0] == 1) VegsQty[4] += 3;
	if (Sides[1] == 1) VegsQty[2] += 2;

	for (int i = 0; i < 5; i++) {
		if (SupplyVegs[i] < VegsQty[i])
			inStock = false;

		if (i < 4) {
			if(Drinks[i] > SupplyDrink[i])
			inStock = false;
		}
	}
		if (BurgerGram > SupplyBurger)
			inStock = false;
	
			if (Breads == 1 && 1 <= SupplyBread[0])
				inStock = false;
			if (Breads == 2 && 1 <= SupplyBread[1])
				inStock = false;

	if (g100_var.GetCheck() || g220_var.GetCheck() || g350_var.GetCheck()) {
		BurgerF = true;
	}


	// Error Msg
	if (!BurgerF && !salad) {
		errorIMG.ShowWindow(true);
		errTXT.ShowWindow(true);
		errMSG.ShowWindow(true);
		SetDlgItemText(error_msg, _T("You Must Add Burger / Salad !"));
	}
	else if ((!BurgerF || !BurgerB || !BurgerL) && (BurgerF || BurgerL)) {
		errorIMG.ShowWindow(true);
		errTXT.ShowWindow(true);
		errMSG.ShowWindow(true);
		SetDlgItemText(error_msg, _T("You Must To fill all the fields of Burger !"));
	}
	else {
		if (BurgerF && salad) {
			CString NoVegs[4];
			NoVegs[0] = _T("No Tomato");
			NoVegs[1] = _T("No Pickle");
			NoVegs[2] = _T("No Onion");
			NoVegs[3] = _T("No Lettuce");

			for (int i = 0; i < 4; i++) {
				if (!BurgerVegs[i]) {
					VegsStr += NoVegs[i];
					VegsStr += _T(" , ");
				}
				if (!SaladVegs[i]) {
					SaladStr += NoVegs[i];
					SaladStr += _T(" , ");
				}
			}

			VegsStr.Delete(VegsStr.GetLength() - 3, VegsStr.GetLength() - 1);
			SaladStr.Delete(SaladStr.GetLength() - 3, SaladStr.GetLength() - 1);

			CString side[2];
			side[0] = _T("French Fries");
			side[1] = _T("Onion Rings");

			for (int i = 0; i < 2; i++) {
				if (Sides[i]) {
					SidesStr += side[i];
					SidesStr += _T(" , ");
				}
			}
			SidesStr.Delete(SidesStr.GetLength() - 3, SidesStr.GetLength() - 1);

			CString drink[4];
			drink[0] = _T("Pink Lemonade");
			drink[1] = _T("Lemonade");
			drink[2] = _T("Soda");
			drink[3] = _T("Cola");

			for (int i = 0; i < 4; i++) {
				if (Drinks[i]) {
					DrinkStr += drink[i];
					DrinkStr += _T(" , ");
				}
			}

			DrinkStr.Delete(DrinkStr.GetLength() - 3, DrinkStr.GetLength() - 1);
			price = 9.9;
			if (DBurger) {
				if (SizeStr == _T("100g")) {
					SizeStr = _T("200g");
					BurgerGram = 0.200;
					price += 7;
				}
				else if (SizeStr == _T("220g")) {
					SizeStr = _T("440g");
					BurgerGram = 0.440;
					price += 10;
				}
				else if (SizeStr == _T("350g")) {
					SizeStr = _T("700g");
					BurgerGram = 0.700;
					price += 13;
				}
			}
			for (int i = 0; i < 2; i++) {
				if (Sides[i]) {
					price += 5;
				}
			}

			NewDish[0] = new Burger(_T("Burger") + SizeStr, SizeStr, LevelStr, Bread, SidesStr, VegsQty, price, DBurger, Drinks);
			int tmp[4] = { 0 };
			NewDish[1] = new Salad(_T("Salad"), _T(""), _T(""), 9.9, VegsQty, tmp);

		}
		else if (BurgerF) {
			CString NoVegs[4];
			NoVegs[0] = _T("No Tomato");
			NoVegs[1] = _T("No Pickle");
			NoVegs[2] = _T("No Onion");
			NoVegs[3] = _T("No Lettuce");

			for (int i = 0; i < 4; i++) {
				if (!BurgerVegs[i]) {
					VegsStr += NoVegs[i];
					VegsStr += _T(" , ");
				}
			}

			VegsStr.Delete(VegsStr.GetLength() - 3, VegsStr.GetLength() - 1);

			CString side[2];
			side[0] = _T("French Fries");
			side[1] = _T("Onion Rings");

			for (int i = 0; i < 2; i++) {
				if (Sides[i]) {
					SidesStr += side[i];
					SidesStr += _T(" , ");
				}
			}
			SidesStr.Delete(SidesStr.GetLength() - 3, SidesStr.GetLength() - 1);

			CString drink[4];
			drink[0] = _T("Pink Lemonade");
			drink[1] = _T("Lemonade");
			drink[2] = _T("Soda");
			drink[3] = _T("Cola");

			for (int i = 0; i < 4; i++) {
				if (Drinks[i]) {
					DrinkStr += drink[i];
					DrinkStr += _T(" , ");
				}
			}

			DrinkStr.Delete(DrinkStr.GetLength() - 3, DrinkStr.GetLength() - 1);
			price = 0;
			if (DBurger) {
				if (SizeStr == _T("100g")) {
					SizeStr = _T("200g");
					BurgerGram = 0.200;
					price += 7;
				}
				else if (SizeStr == _T("220g")) {
					SizeStr = _T("440g");
					BurgerGram = 0.440;
					price += 10;
				}
				else if (SizeStr == _T("350g")) {
					SizeStr = _T("700g");
					BurgerGram = 0.700;
					price += 13;
				}
			}
			for (int i = 0; i < 2; i++) {
				if (Sides[i]) {
					price += 5;
				}
			}
			NewDish[0] = new Burger(_T("Burger") + SizeStr, SizeStr, LevelStr, Bread, SidesStr, VegsQty, price, DBurger, Drinks);
			NewDish[1] = NULL;
		}
		else if (salad) {
			CString NoVegs[4];
			NoVegs[0] = _T("No Tomato");
			NoVegs[1] = _T("No Pickle");
			NoVegs[2] = _T("No Onion");
			NoVegs[3] = _T("No Lettuce");

			for (int i = 0; i < 4; i++) {
				if (!SaladVegs[i]) {
					SaladStr += NoVegs[i];
					SaladStr += _T(" , ");
				}
				VegsQty[i]-=1;
			}
			SaladStr.Delete(SaladStr.GetLength() - 3, SaladStr.GetLength() - 1);
			CString side[2];
			side[0] = _T("French Fries");
			side[1] = _T("Onion Rings");

			for (int i = 0; i < 2; i++) {
				if (Sides[i]) {
					SidesStr += side[i];
					SidesStr += _T(" , ");
				}
			}
			SidesStr.Delete(SidesStr.GetLength() - 3, SidesStr.GetLength() - 1);

			CString drink[4];
			drink[0] = _T("Pink Lemonade");
			drink[1] = _T("Lemonade");
			drink[2] = _T("Soda");
			drink[3] = _T("Cola");

			for (int i = 0; i < 4; i++) {
				if (Drinks[i]) {
					DrinkStr += drink[i];
					DrinkStr += _T(" , ");
				}
			}

			DrinkStr.Delete(DrinkStr.GetLength() - 3, DrinkStr.GetLength() - 1);

			for (int i = 0; i < 4; i++) {
				if (Drinks[i]) {
					price += 2.5;
				}
				if (i < 2 && Sides[i]) {
					price += 5;
				}
			}

			NewDish[0] = NULL;
			NewDish[1] = new Salad(_T("Salad"), Bread, SidesStr, price + 9.9, VegsQty, Drinks);
		}

		if(!inStock) CDialogEx::OnOK(); 
		else {
			if (inStock && salad) CDialogEx::OnOK();
			errorIMG.ShowWindow(true);
			errTXT.ShowWindow(true);
			errMSG.ShowWindow(true);
			SetDlgItemText(error_msg, _T("Have items that Not in Stock !"));
		}
	}
}


BOOL NewOrder_Dialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here

	BurgerF = false;
	BurgerL = false;
	BurgerB = false;
	Breads = 0;
	BurgerGram = 0;
	for (int i = 0; i < 5; i++) {
		VegsQty[i] = 0;
		if (i < 4) {
			BurgerVegs[i] = 1;
			SaladVegs[i] = 1;
			Drinks[i] = 0;
			DrinkQty[i] = 0;
			BreadQty[i] = 0;
		}
	}
	Sides[0] = 0;
	Sides[1] = 0;

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


void NewOrder_Dialog::OnBnClicked100g()
{
	// TODO: Add your control notification handler code here
	SizeStr.Format(_T("100g"));
	Size = 100;
	DoubleBurger_var.EnableWindow(true);
	BurgerGram = 0.100;
}


void NewOrder_Dialog::OnBnClicked220g()
{
	// TODO: Add your control notification handler code here
	SizeStr.Format(_T("220g"));
	Size = 220;
	DoubleBurger_var.EnableWindow(true);
	BurgerGram = 0.220;
}


void NewOrder_Dialog::OnBnClicked350g()
{
	// TODO: Add your control notification handler code here
	SizeStr.Format(_T("350g"));
	Size = 350;
	DoubleBurger_var.EnableWindow(true);
	BurgerGram = 0.350;
}


void NewOrder_Dialog::OnBnClickedDoubleburger()
{
	// TODO: Add your control notification handler code here
	if (DoubleBurger_var.GetCheck()){
		DBurger = true;
	}
	else {
		DBurger = false;
	}
	//SetDlgItemText(ID_print, SizeStr);
}


void NewOrder_Dialog::OnBnClickedWithoutallBtn()
{
	// TODO: Add your control notification handler code here
	NoT_var.SetCheck(true);
	NoP_var.SetCheck(true);
	NoO_var.SetCheck(true);
	NoL_var.SetCheck(true);
}


void NewOrder_Dialog::OnClickedMediumId()
{
	// TODO: Add your control notification handler code here
	LevelStr.Format(_T("Medium"));
	BurgerL = true;
}


void NewOrder_Dialog::OnBnClickedNotomato()
{
	// TODO: Add your control notification handler code here
	if (NoT_var.GetCheck()) {
		BurgerVegs[0] = 0;
	}
	else
		BurgerVegs[0] = 1;
}


void NewOrder_Dialog::OnBnClickedMediumWell()
{
	// TODO: Add your control notification handler code here
	LevelStr.Format(_T("Medium-Well"));
	BurgerL = true;
}


void NewOrder_Dialog::OnBnClickedWellDone()
{
	// TODO: Add your control notification handler code here
	LevelStr.Format(_T("Well-Done"));
	BurgerL = true;
}


void NewOrder_Dialog::OnBnClickedNopickle()
{
	// TODO: Add your control notification handler code here
	if (NoP_var.GetCheck()) {
		BurgerVegs[1] = 0;
	}
	else
		BurgerVegs[1] = 1;
}


void NewOrder_Dialog::OnBnClickedNoonion()
{
	// TODO: Add your control notification handler code here
	if (NoO_var.GetCheck()) {
		BurgerVegs[2] = 0;
	}
	else
		BurgerVegs[2] = 1;
}


void NewOrder_Dialog::OnBnClickedNolettuce()
{
	// TODO: Add your control notification handler code here
	if (NoL_var.GetCheck()) {
		BurgerVegs[3] = 0;
	}
	else
		BurgerVegs[3] = 1;
}


void NewOrder_Dialog::OnBnClickedbw()
{
	// TODO: Add your control notification handler code here
	Bread.Format(_T("White"));
	Breads = 1;
	BurgerB = true;
}


void NewOrder_Dialog::OnBnClickedbwhole()
{
	// TODO: Add your control notification handler code here
	Bread.Format(_T("Whole Wheat"));
	Breads = 2;
	BurgerB = true;
}


void NewOrder_Dialog::OnBnClickedfries()
{
	// TODO: Add your control notification handler code here
	if (var_Fries.GetCheck()) {
		Sides[0] = 1;
	}
	else {
		Sides[0] = 0;
	}
}


void NewOrder_Dialog::OnBnClickedOnionrings()
{
	// TODO: Add your control notification handler code here
	if (var_OnionRings.GetCheck()) {
		Sides[1] = 1;
	}
	else {
		Sides[1] = 0;
	}
}


void NewOrder_Dialog::OnBnClickedPlemonade()
{
	// TODO: Add your control notification handler code here
	if (PLemonade.GetCheck()) {
		Drinks[0] = 1;
	}
	else {
		Drinks[0] = 0;
	}
}


void NewOrder_Dialog::OnBnClickedLemonade()
{
	// TODO: Add your control notification handler code here
	if (Lemonade.GetCheck()) {
		Drinks[1] = 1;
	}
	else {
		Drinks[1] = 0;
	}
}


void NewOrder_Dialog::OnBnClickedSoda()
{
	// TODO: Add your control notification handler code here
	if (Soda.GetCheck()) {
		Drinks[2] = 1;
	}
	else {
		Drinks[2] = 0;
	}
}


void NewOrder_Dialog::OnBnClickedCola()
{
	// TODO: Add your control notification handler code here
	if (Cola.GetCheck()) {
		Drinks[3] = 1;
	}
	else {
		Drinks[3] = 0;
	}
}


void NewOrder_Dialog::OnBnClickedTomatoSalad()
{
	// TODO: Add your control notification handler code here
	if (TomatoS.GetCheck())
	{
		SaladVegs[0] = 0;
	}
	else
	{
		SaladVegs[0] = 1;
	}

}


void NewOrder_Dialog::OnBnClickedPickleSalad()
{
	// TODO: Add your control notification handler code here
	if (PickleS.GetCheck())
	{
		SaladVegs[1] = 0;
	}
	else
	{
		SaladVegs[1] = 1;
	}
}


void NewOrder_Dialog::OnBnClickedOnionSalad()
{
	// TODO: Add your control notification handler code here
	if (OnionS.GetCheck())
	{
		SaladVegs[2] = 0;
	}
	else
	{
		SaladVegs[2] = 1;
	}
}


void NewOrder_Dialog::OnBnClickedLettuceSalad()
{
	// TODO: Add your control notification handler code here
	if (LettuceS.GetCheck())
	{
		SaladVegs[3] = 0;
	}
	else
	{
		SaladVegs[3] = 1;
	}
}
