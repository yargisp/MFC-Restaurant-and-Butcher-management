#pragma once
#include "Orders.h"
#include "Burger.h"
#include "Salad.h"

// NewOrder_Dialog dialog

class NewOrder_Dialog : public CDialogEx
{
	DECLARE_DYNAMIC(NewOrder_Dialog)

public:
	NewOrder_Dialog(CWnd* pParent = nullptr);   // standard constructor
	virtual ~NewOrder_Dialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = NewOrder };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	//Orders* newOrder;
	//Burger* BurgerNew;
	Dish* NewDish[2];
	CString SizeStr;
	int Size;
	CString LevelStr;
	int Drinks[4];
	int BurgerVegs[4];
	int SaladVegs[4];
	int Breads;
	int Sides[2];
	CString SidesStr;
	CString Bread;
	CString VegsStr;
	CString SaladStr;
	CString DrinkStr;
	double price;
	bool salad;

	double SupplyBurger;
	const int* SupplyBread;
	const int* SupplyDrink;
	// const int* SupplySides;
	const int* SupplyVegs;

	double BurgerGram;
	int VegsQty[5];
	int DrinkQty[4];
	int BreadQty[4];

	bool BurgerF;
	bool BurgerL;
	bool BurgerB;
	bool DBurger;

	CButton TomatoS;
	CButton PickleS;
	CButton OnionS;
	CButton LettuceS;
	afx_msg void OnBnClickedId();
	CButton AddS;
	CButton g100_var;
	CButton g220_var;
	CButton g350_var;
	CButton DoubleBurger_var;
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClicked100g();
	afx_msg void OnBnClicked220g();
	afx_msg void OnBnClicked350g();
	afx_msg void OnBnClickedDoubleburger();
	CButton M_var;
	CButton MW_var;
	CButton WD_var;
	CButton NoT_var;
	CButton NoP_var;
	CButton NoO_var;
	CButton NoL_var;
	afx_msg void OnBnClickedWithoutallBtn();
	CButton Bread_w;
	CButton Bread_wholew;
	CButton var_OnionRings;
	CButton var_Fries;
	CButton PLemonade;
	CButton Lemonade;
	CButton Soda;
	CButton Cola;
	afx_msg void OnClickedMediumId();
	
	afx_msg void OnBnClickedNotomato();
	afx_msg void OnBnClickedMediumWell();
	afx_msg void OnBnClickedWellDone();
	afx_msg void OnBnClickedNopickle();
	afx_msg void OnBnClickedNoonion();
	afx_msg void OnBnClickedNolettuce();
	afx_msg void OnBnClickedbw();
	afx_msg void OnBnClickedbwhole();
	afx_msg void OnBnClickedfries();
	afx_msg void OnBnClickedOnionrings();
	afx_msg void OnBnClickedPlemonade();
	afx_msg void OnBnClickedLemonade();
	afx_msg void OnBnClickedSoda();
	afx_msg void OnBnClickedCola();
	afx_msg void OnBnClickedTomatoSalad();
	afx_msg void OnBnClickedPickleSalad();
	afx_msg void OnBnClickedOnionSalad();
	afx_msg void OnBnClickedLettuceSalad();
	CStatic errTXT;
	CStatic errorIMG;
	CStatic errMSG;
};
