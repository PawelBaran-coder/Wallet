#ifndef INCOME_H
#define INCOME_H

#include <iostream>

using namespace std;

class Income
{
    //Date date;
    int incomeDate;
    int incomeId;
    int userId;
    float incomeAmount;
    string description;

public:

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
