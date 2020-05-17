#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>
#include "Income.h"
//#include "Date.h"

using namespace std;

class Expense : public Income
{

public:

bool operator < (const Expense &x)const
    {
        return date < x.date;
    }
};

#endif
