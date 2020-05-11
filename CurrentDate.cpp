#include "CurrentDate.h"
#include "AdditionalMethods.h"

CurrentDate::CurrentDate()
{
    SYSTEMTIME st;
    GetSystemTime(&st);

    currentYear = st.wYear;
    currentMonth = st.wMonth;
    currentDay = st.wDay;
}
int CurrentDate::getCurrentYear()
{
    return currentYear;
}
int CurrentDate::getCurrentMonth()
{
    return currentMonth;
}
int CurrentDate::getCurrentDay()
{
    return currentDay;
}
string CurrentDate::convertIntYearToString()
{
    currentYearStr = AdditionalMethods::convertIntegerToString(currentYear);
    return currentYearStr;
}
string CurrentDate::convertIntMonthToString()
{
    currentMonthStr = AdditionalMethods::convertIntegerToString(currentMonth);
    if (currentMonth < 10)
    {
        currentMonthStr = "0" + AdditionalMethods::convertIntegerToString(currentMonth);
    }
    return currentMonthStr;
}
string CurrentDate::convertIntDayToString()
{
    currentDayStr = AdditionalMethods::convertIntegerToString(currentDay);
    if (currentDay < 10)
    {
        currentDayStr = "0" + AdditionalMethods::convertIntegerToString(currentDay);
    }
    return currentDayStr;
}
void CurrentDate::convertCurrentDateStringElementsToInt()
{
    currentDateStr = convertIntYearToString() + convertIntMonthToString() + convertIntDayToString();
    currentDateInt = AdditionalMethods::convertStringToInteger(currentDateStr);
}
int CurrentDate::getCurrentDateInt()
{
    convertCurrentDateStringElementsToInt();
    return currentDateInt;
}
