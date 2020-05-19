#include "Date.h"

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

bool Date::isDateTextCorrect(string dateText)
{
    int dateLenght = dateText.length();
    int requireDateLenght = 10;

    char separator = '-';
    int firstDashPosition = 4;
    int secondDashPosition = 7;

    if (dateLenght != requireDateLenght)
    {
        cout << "podales za dluga badz za krotka date!" << endl << endl;
        return false;
    }
    else if (dateText[firstDashPosition] != separator || dateText[secondDashPosition] != separator)
    {
        cout << "podales date bez myslnikow!" << endl << endl;
        return false;

    }
    for (int i = 0; i < dateLenght; i++)
    {
        if (i >= 0 && i < firstDashPosition && isdigit(dateText[i]) == false)
        {
            cout << "podany rok nie jest liczba!" << endl << endl;
            return false;
        }
        else if (i > firstDashPosition && i < secondDashPosition && isdigit(dateText[i]) == false)
        {
            cout << "podany miesiac nie jest liczba!" << endl << endl;
            return false;
        }
        else if (i > secondDashPosition && isdigit(dateText[i]) == false)
        {
            cout << "podany dzien nie jest liczba!" << endl << endl;
            return false;
        }
    }
    return true;
}
bool Date::isleapYearDateCorrect(string dateText)
{
    int daysOfMonth = 0;
    bool leapYear;

    string yearStr = "";
    string monthStr = "";
    string dayStr = "";
    year = 0;
    month = 0;
    day = 0;

    int yearfirstNumberPosition = 0;
    int monthfirstNumberPosition = 5;
    int dayfirstNumberPosition = 8;

    yearStr = AdditionalMethods::getNumber(dateText,yearfirstNumberPosition);
    monthStr = AdditionalMethods::getNumber(dateText,monthfirstNumberPosition);
    dayStr = AdditionalMethods::getNumber(dateText,dayfirstNumberPosition);

    year = AdditionalMethods::convertStringToInteger(yearStr);
    if (year < 2000)
    {
        cout << "Podales nieprawidlowo rok!" << endl;
        cout << "Obslugiwany zakres dat zaczyna sie od 2000-01-01, a konczy na dniu dzisiejszym!" << endl << endl;
        return false;
    }
    month = AdditionalMethods::convertStringToInteger(monthStr);
    if (month > 12 || month < 1)
    {
        cout << "Podales nieprawidlowo miesiac!" << endl << endl;
        cout << "Mamy 12 miesiecy w roku!" << endl << endl;
        return false;
    }
    day = AdditionalMethods::convertStringToInteger(dayStr);

    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        daysOfMonth = 30;
        if (day > 30 || day < 1)
        {
            cout << "Podales nieprawidlowo dzien miesiaca!" << endl << endl;
            cout << "W podanym miesiacu nie ma tylu dni!" << endl << endl;
            return false;
        }
    }

    else if (month == 02)
    {
        bool leapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

        if (leapYear == 0)
        {
            daysOfMonth = 28;
            if (day > 28)
            {
                cout << "Podales nieprawidlowo dzien miesiaca!" << endl << endl;
                cout << "W podanym miesiacu nie ma tylu dni!" << endl << endl;
                return false;
            }
        }

        else
        {
            daysOfMonth = 29;
            if (day > 29)
            {
                cout << "Podales nieprawidlowo dzien miesiaca!" << endl << endl;
                cout << "W podanym miesiacu nie ma tylu dni!" << endl << endl;
                return false;
            }
        }
    }

    else
    {
        daysOfMonth = 31;
        if (day > 31)
        {
            cout << "Podales nieprawidlowo dzien miesiaca!" << endl << endl;
            cout << "W podanym miesiacu nie ma tylu dni!" << endl << endl;
            return false;
        }
    }
    return true;
}
bool Date::isDateCorrect(string dateStringWithDash)
{
    if (isDateTextCorrect(dateStringWithDash) && isleapYearDateCorrect(dateStringWithDash))
    {
        return true;
    }
    else
    {
        return false;
    }
}
