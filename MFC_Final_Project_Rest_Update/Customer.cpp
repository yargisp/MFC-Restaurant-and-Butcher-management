#include "pch.h"
#include "Customer.h"


int Customer::ActiveCustomers = 1;

Customer::Customer() : FirstName(""), LastName(""), PhoneNum(""), Adress(""), City(""),id(100+ActiveCustomers)
{
    ActiveCustomers++;
}

Customer::Customer(const CString& firstN, const CString& lastN, const CString& phoneNum, const CString& adrs, const CString& city)
{
    this->FirstName = firstN;
    this->LastName = lastN;
    this->PhoneNum = phoneNum;
    this->Adress = adrs;
    this->City = city;
    this->id = ActiveCustomers+100;
    ActiveCustomers++;
}

Customer::Customer(const Customer& newC)
{
    this->id = ActiveCustomers+100;
    this->Adress = newC.Adress;
    this->City = newC.City;
    this->ActiveCustomers = ActiveCustomers++;
    this->FirstName = newC.FirstName;
    this->LastName = newC.LastName;
    this->PhoneNum = newC.PhoneNum;
}

Customer::~Customer()
{
}

CString Customer::getFirstN() const
{
    return FirstName;
}

CString Customer::getLastN() const
{
    return LastName;
}

CString Customer::getPhone() const
{
    return PhoneNum;
}

CString Customer::getAdress() const
{
    return Adress;
}

CString Customer::getCity() const
{
    return City;
}

int Customer::getID() const
{
    return id;
}

int Customer::getActiveCustomers() const
{
    return ActiveCustomers;
}

void Customer::setFirstN(const CString& name)
{
     this->FirstName = name;
}

void Customer::setLastN(const CString& last)
{
     this->LastName = last;
}

void Customer::setPhoneN(const CString& num)
{
    this->PhoneNum = num;
}

void Customer::setAdress(const CString& adrs)
{
    this->Adress = adrs;
}

void Customer::setCity(const CString& city)
{
      this->City = city;
}
