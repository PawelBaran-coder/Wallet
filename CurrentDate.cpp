#include "CurrentDate.h"

int CurrentDate::getCurrentYear()
{
    setCurrentDate();
    return currentYear;
}
int CurrentDate::getCurrentMonth()
{
    setCurrentDate();
    return currentMonth;
}
int CurrentDate::getCurrentDay()
{
    setCurrentDate();
    return currentDay;
}
void CurrentDate::setCurrentDate()
{
    SYSTEMTIME st;
    GetSystemTime(&st);

    currentYear = st.wYear;
    currentMonth = st.wMonth;
    currentDay = st.wDay;
}
