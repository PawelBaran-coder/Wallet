#include "CurrentDate.h"

void CurrentDate::setCurrentYear(int newCurrentYear)
{
    if(newCurrentYear >= 0)
        currentYear = newCurrentYear;
}
void CurrentDate::setCurrentMonth(int newCurrentMonth)
{
    if(newCurrentMonth >= 0)
        currentMonth = newCurrentMonth;
}
void CurrentDate::setCurrentDay(int newCurrentDay)
{
    if(newCurrentDay >= 0)
        currentDay = newCurrentDay;
}
int CurrentDate::getCurrentYear()
{
    return currentYear;
}
int CurrentDate::getCurrentMonth()
{
    return currentMonth;
}
