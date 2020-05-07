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
