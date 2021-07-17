#pragma once
#include "Customer.h"
#include "Dish.h"
#include <vector>
using std::vector;

class Orders
{
protected:
	static int count;
	int orderID;
	CString date;
	CString time;
	double Price;
	Customer *cust;
	Dish* dish;
	double Meat_W[4];

public:
	Orders();
	Orders(const vector<Customer*>&, const int& , int *,const double&); // Butcher
	Orders(const vector<Customer*>&, const int&,Dish*,const double&,const double&); // rest
	~Orders();



	//get's
	int getOrderID() const;
	int getCount() const;
	CString getDate() const;
	CString getTime() const;
	double getPrice() const;
	Customer* getCust() const;
	Dish* getDish() const;
	double* GetMeatW();

	//set's
	void setOrderID(const int&);
	void setDate(const CString&);
	void setTime(const CString&);
	void setPrice(const double&);
	void setCust(const Customer&);
	void SetMeat(const int*);
};

