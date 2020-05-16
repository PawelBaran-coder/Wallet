#ifndef INCOME_H
#define INCOME_H

#include <iostream>

using namespace std;

class Income
{
protected:

    int id;
    int userId;
    int date;
    float amount;
    string description;

public:

    bool operator < (const Income &x)const
    {
        return date < x.date;
    }
    void setDate (int newDate);
    void setId(int newId);
    void setUserId(int newUserId);
    void setAmount(float newAmount);
    void setDescription(string newDescription);

    int getDate();
    int getId();
    int getUserId();
    float getAmount();
    string getDescription();

};

#endif
