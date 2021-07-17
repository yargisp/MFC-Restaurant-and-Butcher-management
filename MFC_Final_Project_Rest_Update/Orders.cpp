#include "pch.h"
#include "Orders.h"


int Orders::count = 1000;

Orders::Orders() : orderID(count), date(""), time(""), Price(0)
{
	this->count++;
	this->dish = NULL;
	this->cust = NULL;
}

Orders::Orders(const vector<Customer*>&person,const int&index,  int*Weight, const double&price)
{
	this->orderID = count++;
	CTime time = CTime::GetCurrentTime(); // Set Cuurent Time in static text
	this->date = time.Format("%d/%m/%y");
	this->time = time.Format("%H:%M");
	this->Price = price;
	SetMeat(Weight);
	//this->setCust(*person);
	this->cust = person[index];
	this->dish = NULL;
}

Orders::Orders(const vector<Customer*>&person, const int&index,  Dish *burger, const double&gram, const double&price)
{
	this->orderID = count++;
	CTime time = CTime::GetCurrentTime(); // Set Cuurent Time in static text
	this->date = time.Format("%d/%m/%y");
	this->time = time.Format("%H:%M");
	this->Price = price;
	this->Meat_W[0] = gram;
	this->cust = person[index];
	this->dish = burger;
}

Orders::~Orders()
{
}

int Orders::getOrderID() const
{
	return orderID;
}

int Orders::getCount() const
{
	return count;
}

CString Orders::getDate() const
{
	return date;
}

CString Orders::getTime() const
{
	return time;
}

double Orders::getPrice() const
{
	return Price;
}

Customer* Orders::getCust() const
{
	return cust;
}

Dish* Orders::getDish() const
{
	return dish;
}

double* Orders::GetMeatW()
{
	return Meat_W;
}

void Orders::setOrderID(const int& order_id)
{
	this->orderID = order_id;
}

void Orders::setDate(const CString& currDate)
{
	this->date = currDate;
}

void Orders::setTime(const CString& currTime)
{
	this->time = currTime;
}

void Orders::setPrice(const double& sum)
{
	this->Price = sum;
}

void Orders::setCust(const Customer& newCust)
{
	//*this->cust = *newCust;
	//*this->cust = newCust;
}

void Orders::SetMeat(const int*arr)
{
	for (int i = 0; i < 4; i++) {
		this->Meat_W[i] = arr[i];
	}
}

