#ifndef CURRENTDATE_H
#define CURRENTDATE_H

#include <iostream>
#include <windows.h>
#include <winbase.h>

using namespace std;

class CurrentDate
{
    int currentYear;
    int currentMonth;
    int currentDay;
    int currentDaysInMonth;
    int currentDateInt;
    string currentDateStr;
    void setCurrentDate();

public:

    int getCurrentYear();
    int getCurrentMonth();
    int getCurrentDay();

};

#endif
