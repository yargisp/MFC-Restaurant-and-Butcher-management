#include "pch.h"
#include "Business.h"


Business::Business() : Name(""), Address(""), Telephone(""),OpenHours(""),CloseHours("") {
}

Business::Business(const CString&Name, const CString&Add, const CString&Tel, const CString&Oh, const CString&Ch) : Name(Name),Telephone(Tel),OpenHours(Oh),CloseHours(Ch)
{
}

Business::~Business()
{
}

CString Business::GetName()
{
    return Name;
}

CString Business::GetAddress()
{
    return Address;
}

CString Business::GetTel()
{
    return Telephone;
}

CString Business::GetOpenH()
{
    return OpenHours;
}

CString Business::GetCloseH()
{
    return CloseHours;
}

void Business::SetName(const CString&name)
{
    this->Name = name;
}

void Business::SetAddress(const CString&add)
{
    this->Address = add;
}

void Business::SetTel(const CString&tel)
{
    this->Telephone = tel;
}

void Business::SetOpenH(const CString&open)
{
    this->OpenHours = open;
}

void Business::SetCloseH(const CString&close)
{
    this->CloseHours = close;
}

