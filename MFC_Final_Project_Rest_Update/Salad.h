#pragma once
#include "Dish.h"
class Salad : public Dish
{
    public:
        Salad(CString, CString,CString, double, int*,int*);
        ~Salad();
        void SetName(const CString&);
};

