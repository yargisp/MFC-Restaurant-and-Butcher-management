#include "pch.h"
#include "Finance.h"

IMPLEMENT_SERIAL(Finance, CObject, 0)

Finance::Finance()
{
    this->Balance = 10000;
    this->ProfitRest = 0;
    this->ProfitButcher = 0;
    this->ProfitPercent = 0;
}

Finance::Finance(const double&sum)
{
    this->Balance = sum;
    this->ProfitRest = 0;
    this->ProfitButcher = 0;
    this->ProfitPercent = 0;
}

Finance::~Finance()
{
}

double Finance::GetBalance()
{
    return Balance;
}

void Finance::SetBalance(const double&balance)
{
    this->Balance = balance;
}

void Finance::Witdhraw(const double&sum)
{
    this->Balance -= sum;
}

void Finance::deposit(const double&sum)
{
    this->Balance += sum;
}

double Finance::GetProfitButcher()
{
    return ProfitButcher;
}

void Finance::SetProfitButcher(const double& ProfitButcher)
{
    this->ProfitButcher = ProfitButcher;
}

void Finance::AddProfitButcher(const double&profit)
{
    this->ProfitButcher += profit;
}

double Finance::GetProfitRest()
{
    return ProfitRest;
}

void Finance::SetProfitRest(const double& ProfitRest)
{
    this->ProfitRest = ProfitRest;
}

void Finance::AddProfitRest(const double&profit)
{
    this->ProfitRest += profit;
}

double Finance::GetProfitPercent()
{
    this->ProfitPercent = (ProfitRest / ProfitRest) * 100;
    return ProfitPercent;
}

void Finance::Serialize(CArchive& archive)
{
// call base class function first
// base class is CObject in this case
    CObject::Serialize(archive);

    // now do the stuff for our specific class
    if (archive.IsStoring())
        archive << Balance << ProfitRest << ProfitButcher << ProfitPercent;
    else
        archive >> Balance >> ProfitRest >> ProfitButcher >> ProfitPercent;
}
