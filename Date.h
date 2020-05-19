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
    int startDate;
    int endDate;

    bool isDateTextCorrect(string dateText);
    bool isleapYearDateCorrect(string dateText);

public:

    void setStartDate(int newStartDate);
    void setEndDate(int newEndDate);

    int getStartDate();
    int getEndDate();

    int firstDayPreviousMonth();
    string convertIntegerDateToStringDate(int dateInt);
    int convertStringDateToIntegerDate(string dateStringDash);
    bool isDateCorrect(string dateStringWithDash);

};

#endif
