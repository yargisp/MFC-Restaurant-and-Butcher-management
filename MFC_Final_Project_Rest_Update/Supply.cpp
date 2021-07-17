#include "pch.h"
#include "Supply.h"

Supply::Supply() {
	for (int i = 0; i < 5; i++) {
		this->Vegetables[i] = 0;
		if (i < 4)
		{
			this->Meat[i] = 0;
			this->Drink[i] = 0;
		}
		if (i < 2) {
			this->Breads[i] = 0;
			this->Extras[i] = 0;
		}
	}
}

Supply::~Supply() {

}

Supply::Supply(const double*M, const int*D, const int*V, const int*B, const int*E)
{
	for (int i = 0; i < 5; i++) {
		this->Vegetables[i] = V[i];
		if (i<4)
		{
			this->Meat[i] = M[i];
			this->Drink[i] = D[i];
		}
		if (i < 2) {
			this->Breads[i] = B[i];
			this->Extras[i] = E[i];
		}
	}
}

void Supply::SetMeat(const double*Meat)
{
	for (int i = 0; i < 4; i++) {
		this->Meat[i] = Meat[i];
	}
}

const double* Supply::GetMeat()
{
	return Meat;
}

void Supply::SetDrink(const int&i, const int&Qty)
{
	Drink[i] = Qty;
}

void Supply::SetMeat(const int& i, const double& Qty)
{
	Meat[i] = Qty;
}

void Supply::SetBread(const int& i, const int& Qty)
{
	Breads[i] = Qty;
}

void Supply::SetVegs(const int& i, const int& Qty)
{
	Vegetables[i] = Qty;
}

void Supply::SetSide(const int& i, const int& Qty)
{
	Extras[i] = Qty;
}

void Supply::SetDrinks(const int*Drink)
{
	for (int i = 0; i < 4; i++) {
		this->Drink[i] = Drink[i];
	}
}

const int* Supply::GetDrinks()
{
	return Drink;
}

void Supply::SetVegetables(const int*Vegs)
{
	for (int i = 0; i < 5; i++) {
		this->Vegetables[i] = Vegs[i];
	}
}

const int* Supply::GetVegetables()
{
	return Vegetables;
}

void Supply::SetBreads(const int*Breads)
{
	for (int i = 0; i < 2; i++) {
		this->Breads[i] = Breads[i];
	}
}

const int* Supply::GetBreads()
{
	return Breads;
}

void Supply::SetExtras(const int*Extras)
{
	for (int i = 0; i < 2; i++) {
		this->Extras[i] = Extras[i];
	}
}

const int* Supply::GetExtras()
{
	return Extras;
}

