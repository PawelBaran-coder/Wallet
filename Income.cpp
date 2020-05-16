#include "Income.h"

void Income::setDate (int newDate)
{
    if(newDate >= 20000101)
        date = newDate;
}
void Income::setId(int newId)
{
    if(newId >= 0)
        id = newId;
}
void Income::setUserId(int newUserId)
{
    if(newUserId >= 0)
        userId = newUserId;
}
void Income::setAmount(float newAmount)
{
    if(newAmount >= 0)
        amount = newAmount;
}
void Income::setDescription(string newDescription)
{
    description = newDescription;
}

int Income::getDate()
{
    return date;
}
int Income::getId()
{
    return id;
}
int Income::getUserId()
{
    return userId;
}
float Income::getAmount()
{
    return amount;
}
string Income::getDescription()
{
    return description;
}
