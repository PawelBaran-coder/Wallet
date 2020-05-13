#ifndef CURRENTDATE_H
#define CURRENTDATE_H

#include <iostream>
#include <windows.h>
#include <winbase.h>
#include "AdditionalMethods.h"
//#include "Date.h"
using namespace std;

class CurrentDate
{
    int currentYear;
    int currentMonth;
    int currentDay;
    string currentYearStr;
    string currentMonthStr;
    string currentDayStr;
    //int currentDaysInMonth;
    int currentDateInt;
    string currentDateStr;
    string convertIntYearToString();
    string convertIntMonthToString();
    string convertIntDayToString();
    void convertCurrentDateStringElementsToInt();

public:

    CurrentDate();

    int getCurrentYear();
    int getCurrentMonth();
    int getCurrentDay();
    int getCurrentDateInt();
    int firstDayCurrentMonth();

};

#endif
