#pragma once
#include "Dish.h"
class Burger : public Dish
{

public:
	Burger(CString, CString, CString, CString, CString, int*,double,bool,int *);
	~Burger();

	void SetDoubleBurger(bool);
	bool Getdoubleburger();
	void SetName(const CString&);

private:
	bool doubleBurger;

};

