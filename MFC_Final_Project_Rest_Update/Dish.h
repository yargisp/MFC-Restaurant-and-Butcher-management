#pragma once
#include "pch.h"
#include "Restaurant.h"
//#include "Supply.h"

class Dish : public Restaurant
{
public:
	Dish();
	Dish(const double&, CString);
	Dish(CString, CString, CString, int*,int* );//for burger dish
	Dish(CString, CString, double, int*,int*); //for salad
	//Dish(Dish&);//copy
	~Dish();

	// Get's Functions
	virtual double GetPrice() const;
	CString GetName() const;
	CString GetSize() const;
	CString GetLevel() const;
	CString GetBread() const;
	CString GetSides() const;
	int* GetVegs();

	int* getDrinks();

	//Set's Functions
	void SetPrice(const double&);
	virtual void SetName(const CString&) = 0;
	virtual void SetSize(const CString&);
	virtual void SetLevel(const CString&);
	virtual void SetBread(const CString&);
	virtual void SetSides(const CString&);
	virtual void SetVegs(int*);
	//void SetSalad(bool);
	//void SetSaladArr(int*);
	void SetDrinks(const int*);
	void remTomato();
	void remPic();
	void remOnion();
	void remLet();
	//virtual bool Getdoubleburger() = 0;
	//virtual void SetDoubleBurger(bool) = 0;
	void DishPrice();


protected:
	double Price;
	CString Name;
	CString Size;
	CString Level;
	CString Bread;
	CString Sides;
	int Vegs[5];
	int Drink[4];
};

