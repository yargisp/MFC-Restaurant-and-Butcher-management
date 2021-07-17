#include "pch.h"
#include "Dish.h"

Dish::Dish() : Price(0), Name(_T("")), Size(_T("")), Level(_T("")), Bread(_T("")), Sides(_T(""))
{
	*this->Vegs = { 1 };
	*this->Drink = { 0 };
}

Dish::Dish(const double& pr, CString Dname) :Name(Dname), Price(pr), Size(_T("")), Level(_T("")), Bread(_T("")), Sides(_T(""))
{
	*this->Vegs = { 1 };
	*this->Drink = NULL;
}

Dish::Dish(CString sz, CString lev, CString bre, int* veg,int *drink) : Size(sz), Level(lev), Bread(bre), Price(0), Sides(_T("")), Name(_T(""))
{
	SetVegs(veg);
	SetDrinks(drink);
	DishPrice();

}

Dish::Dish(CString name, CString bread, double price, int* vegs,int *drink) : Name(name), Price(price), Bread(bread),Size(_T("")), Level(_T("")), Sides(_T(""))
{
	SetVegs(vegs);
	SetDrinks(drink);
}
//
//Dish::Dish(Dish& newD):Restaurant(), Name(newD.GetPrice())
//{
//	this->Price = newD.Price;
//	//this->Name = newD.Name;
//	this->Size = newD.Size;
//	this->Bread = newD.Bread;
//	this->Level = newD.Level;
//	this->Sides = newD.Sides;
//	Salad = SetSaladArr(newD.Salad);
//	*this->Drink = newD.Drink;
//	*this->Vegs = newD.Vegs;
//
//
//}

Dish::~Dish()
{

}

double Dish::GetPrice() const
{
	return Price;
}

CString Dish::GetName() const
{
	return Name;
}

CString Dish::GetSize() const
{
	return Size;
}

CString Dish::GetLevel() const
{
	return Level;
}

CString Dish::GetBread() const
{
	return Bread;
}

CString Dish::GetSides() const
{
	return Sides;
}

int* Dish::GetVegs()
{
	return Vegs;
}


int* Dish::getDrinks()
{
	return Drink;
}

void Dish::SetPrice(const double& sum)
{
	this->Price = sum;
}

void Dish::SetName(const CString& Dname)
{
	this->Name = Dname;
}

void Dish::SetSize(const CString& sz)
{
	this->Size = sz;
}

void Dish::SetLevel(const CString& lev)
{
	this->Level = lev;
}

void Dish::SetBread(const CString& Br)
{
	this->Bread = Br;
}

void Dish::SetSides(const CString& Sd)
{
	this->Sides = Sd;
}

//void Dish::SetSaladArr(int* arr)
//{
//	for (int i = 0; i <= 3; i++)
//	{
//		this->Salad[i] = arr[i];
//	}
//}

void Dish::SetDrinks(const int* arr)
{
	for (int i = 0; i < 5 ; i++)
	{
		this->Drink[i] = arr[i];
	}
}

void Dish::remTomato()//tomato, pic,onion, let
{
	Vegs[0]--;

}

void Dish::remPic()
{
	Vegs[1]--;
}

void Dish::remOnion()
{
	Vegs[2]--;
}

void Dish::remLet()
{
	Vegs[3]--;
}

void Dish::SetVegs(int* arr)
{
	for (int i = 0; i < 5; i++)
	{
		this->Vegs[i] = arr[i];
	}
}
//
//void Dish::SetSalad(bool flag)
//{
//	SaladFlag = flag;
//}
//

void Dish::DishPrice() {
	if (Size == _T("100g") || Size == _T("200g")) {
		Price += 10;
	}
	else if (Size == _T("220g") || Size == _T("440g")) {
		Price += 18.9;
	}
	else if (Size == _T("350g") || Size == _T("700g")) {
		Price += 24.9;
	}
	for (int i = 0; i < 4; i++) {
		if (this->Drink[i]) {
			Price += 2.5;
		}
	}
}