#include "pch.h"
#include "Restaurant.h"
#include <iostream>

using namespace std;

Restaurant::Restaurant()
{
}

Restaurant::Restaurant(const CString& Name, const CString& Add, const CString& Tel, const CString& Oh, const CString& Ch) : Business(Name, Add, Tel, Oh, Ch)
{
}

Restaurant::~Restaurant()
{
}

void Restaurant::show()
{
	cout << "im Butcher" << endl;
}