#include "pch.h"
#include "Burger.h"
Burger::Burger(CString name, CString size, CString level, CString bread, CString sides, int* veg,double price,bool Db,int *drink) : Dish(size, level, bread, veg,drink)
{
	this->SetName(name);
	this->SetSides(sides);
	this->Price += price;
	this->SetDrinks(drink);
	SetDoubleBurger(Db);
}

Burger::~Burger()
{
}

void Burger::SetDoubleBurger(bool DB)
{
	this->doubleBurger = DB;
}

bool Burger::Getdoubleburger()
{
	return doubleBurger;
}

void Burger::SetName(const CString&BurgerName)
{
	this->Name = BurgerName;
}
