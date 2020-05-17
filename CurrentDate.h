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
protected:
    int currentYear;
    int currentMonth;
    int currentDay;
    string currentYearStr;
    string currentMonthStr;
    string currentDayStr;
    //int currentDaysInMonth;
    int currentDateInt;
    string currentDateStr;

    void convertCurrentDateStringElementsToInt();

public:

    CurrentDate()
    {
        SYSTEMTIME st;
        GetSystemTime(&st);

        currentYear = st.wYear;
        currentMonth = st.wMonth;
        currentDay = st.wDay;
    }

    int getCurrentYear();
    int getCurrentMonth();
    int getCurrentDay();
    int getCurrentDateInt();
    int firstDayCurrentMonth();

    string convertIntYearToString();
    string convertIntMonthToString();
    string convertIntDayToString();
};

#endif
