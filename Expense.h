#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>
#include "Income.h"
//#include "Date.h"

using namespace std;

class Expense : public Income
{
    //Date date;
    //int id;
    //int userId;
    //float amount;
    //string description;

public:

bool operator < (const Expense &x)const
    {
        return date < x.date;
    }


//Expense(int id, int userId, float amount, string description/*, string fileNameExpenses*/)
  //      : Income(id, userId, amount, description/*, fileNameExpenses*/)
  //  {}


};

#endif
