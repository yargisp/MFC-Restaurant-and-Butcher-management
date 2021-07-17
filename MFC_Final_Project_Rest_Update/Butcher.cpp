#include "pch.h"
#include "Butcher.h"
#include <iostream>

using namespace std;

Butcher::Butcher()
{
}

Butcher::Butcher(const CString&Name, const CString&Add, const CString&Tel, const CString&Oh, const CString&Ch) : Business(Name,Add,Tel,Oh,Ch)
{
}

Butcher::~Butcher()
{
}

void Butcher::show()
{
	cout << "im Butcher" << endl;
}
