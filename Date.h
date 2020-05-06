#ifndef DATE_H
#define DATE_H

#include <iostream>

using namespace std;

class Date
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

    /*
    int calculateNumberOfDaysInMonth();
    void displayDate();
    bool isLeapYear();
    int calculateNumberOfDaysInPeriodTime();
    */
};

#endif
