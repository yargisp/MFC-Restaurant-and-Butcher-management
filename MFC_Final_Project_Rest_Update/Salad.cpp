#include "pch.h"
#include "Salad.h"


Salad::Salad(CString name,CString bread,CString sides,double price, int* vegs,int *drink) :Dish(name, bread, price, vegs,drink)
{
	this->SetName(name);
	this->SetSides(sides);
}

Salad::~Salad()
{
}

void Salad::SetName(const CString&DishName)
{ 
	this->Name.Format(_T("Salad"));
}
