#include "Income.h"

void Income::setIncomeDate (int newIncomeDate)
{
    if(newIncomeDate >= 20000101)
        incomeDate = newIncomeDate;
}
void Income::setIncomeId(int newIncomeId)
{
    if(newIncomeId >= 0)
        incomeId = newIncomeId;
}
void Income::setUserId(int newUserId)
{
    if(newUserId >= 0)
        userId = newUserId;
}
void Income::setIncomeAmount(float newIncomeAmount)
{
    if(newIncomeAmount >= 0)
        incomeAmount = newIncomeAmount;
}
void Income::setDescription(string newDescription)
{
    description = newDescription;
}

int Income::getIncomeDate()
{
    return incomeDate;
}
int Income::getIncomeId()
{
    return incomeId;
}
int Income::getUserId()
{
    return userId;
}
float Income::getIncomeAmount()
{
    return incomeAmount;
}
string Income::getDescription()
{
    return description;
}
