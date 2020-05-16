#ifndef INCOME_H
#define INCOME_H

#include <iostream>

using namespace std;

class Income
{
    int incomeId;
    int userId;
    int incomeDate;
    float incomeAmount;
    string description;



public:

bool operator < (const Income &x)const
    {
        return incomeDate < x.incomeDate;
    }
    void setIncomeDate (int newIncomeDate);
    void setIncomeId(int newIncomeId);
    void setUserId(int newUserId);
    void setIncomeAmount(float newIncomeAmount);
    void setDescription(string newDescription);

    int getIncomeDate();
    int getIncomeId();
    int getUserId();
    float getIncomeAmount();
    string getDescription();

};

#endif
