#ifndef DATE_H
#define DATE_H

#include <iostream>
#include "CurrentDate.h"

using namespace std;

class Date
{
    int year;
    int month;
    int day;
    int daysInMonth;
    int dateInt;
    string dateStr;
    //CurrentDate currentDate;

public:

     //CurrentDate currentDate;

    //Date()

    void setYear(int newYear);
    void setMonth(int newMonth);
    void setDay(int newDay);

    int getYear();
    int getMonth();
    int getDay();

    int firstDayPreviousMonth();
    /*
    int calculateNumberOfDaysInMonth();
    void displayDate();
    bool isLeapYear();
    int calculateNumberOfDaysInPeriodTime();
    */
};

#endif
