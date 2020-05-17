#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <sstream>
#include <windows.h>
#include "CurrentDate.h"

using namespace std;

class Date : public CurrentDate
{
    int year;
    int month;
    int day;
    int daysInMonth;
    int dateInt;
    string dateStr;

public:

    void setYear(int newYear);
    void setMonth(int newMonth);
    void setDay(int newDay);

    int getYear();
    int getMonth();
    int getDay();

    int firstDayPreviousMonth();
    string convertIntegerDateToStringDate(int dateInt);
    int convertStringDateToIntegerDate(string dateStringDash);
    /*
    int calculateNumberOfDaysInMonth();
    void displayDate();
    bool isLeapYear();
    int calculateNumberOfDaysInPeriodTime();
    */
};

#endif
