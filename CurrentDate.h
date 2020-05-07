#ifndef CURRENTDATE_H
#define CURRENTDATE_H

#include <iostream>

using namespace std;

class CurrentDate
{
    int currentYear;
    int currentMonth;
    int currentDay;
    int currentDaysInMonth;
    int currentDateInt;
    string currentDateStr;

public:

    void setCurrentYear(int newCurrentYear);
    void setCurrentMonth(int newCurrentMonth);
    void setCurrentDay(int newCurrentDay);

    int getCurrentYear();
    int getCurrentMonth();


};

#endif
