#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>

//#include "Date.h"

using namespace std;

class Expense
{
    //Date date;
    int expenseId;
    int userId;
    float expenseAmount;
    string description;

public:

    void setExpenseId(int newExpenseId);
    void setExpenseAmount(float newExpenseAmount);
    void setDescription(string newDescription);

    int getExpenseId();
    float getExpenseAmount();
    string getDescription();

};

#endif
