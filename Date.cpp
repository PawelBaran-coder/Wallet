#include "Date.h"

void Date::setYear(int newYear)
{
    if(newYear >= 0)
        year = newYear;
}
void Date::setMonth(int newMonth)
{
    if(newMonth >= 0)
        month = newMonth;
}
void Date::setDay(int newDay)
{
    if(newDay >= 0)
        day = newDay;
}
void Date::setStartDate(int newStartDate)
{
     if(newStartDate >= 0)
        startDate = newStartDate;
}
void Date::setEndDate(int newEndDate)
{
    if(newEndDate >= 0)
        endDate = newEndDate;
}
int Date::getYear()
{
    return year;
}
int Date::getMonth()
{
    return month;
}
int Date::getDay()
{
    return day;
}
int Date::getStartDate()
{
    return startDate;
}
int Date::getEndDate()
{
    return endDate;
}


int Date::firstDayPreviousMonth()
{
    CurrentDate currentDate;

    string firstDayNumber = "01";
    string previousMonthStr = AdditionalMethods::convertIntegerToString(currentDate.getCurrentMonth() - 1);
    if (currentDate.getCurrentMonth() < 10)
    {
        previousMonthStr = "0" + AdditionalMethods::convertIntegerToString(currentDate.getCurrentMonth() - 1);
    }
    string firstDayStr = currentDate.convertIntYearToString() + previousMonthStr + firstDayNumber;
    int firstDayInt = AdditionalMethods::convertStringToInteger(firstDayStr);
    return firstDayInt;
}
string Date::convertIntegerDateToStringDate(int dateInt)
{
    string dateStringDash = "";
    string dateStringNotDash = "";
    string dateElement ="";
    char separator = '-';

    ostringstream ss;

    ss << dateInt;

    dateStringNotDash = ss.str();

    for (int i=0; i<8; i++)
    {
        dateStringDash+=dateStringNotDash[i];
        if ((i==3) || (i==5))
        {
            dateStringDash+=separator;
        }
    }
    return dateStringDash;
}
int Date::convertStringDateToIntegerDate(string dateStringDash)
{
    string dateStringNotDash = "";
    string dateElement ="";
    int dateInt = 0;

    char separator = '-';

    stringstream ss(dateStringDash);

    while (getline(ss, dateElement, separator))
    {
        dateStringNotDash += dateElement;
    }

    dateInt = atoi(dateStringNotDash.c_str());

    return dateInt;
}
