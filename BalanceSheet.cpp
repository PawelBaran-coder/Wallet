#include "BalanceSheet.h"

void BalanceSheet::addIncome()
{
    Income income;
    system("cls");
    cout << " >>> DODAWANIE PRZYCHODU <<<" << endl << endl;

    income = enterNewIncomeData();
    incomes.push_back(income);
    xmlFileIncomes.addIncomeToFile(income);

    cout << endl;
    cout << "Nowy przychod zostal dodany!" << endl << endl;
    system("pause");
}

Income BalanceSheet::enterNewIncomeData()
{
    Income income;
    CurrentDate currentdate;
    char answer;
    string dateTemp;

    income.setId(getIncomeNewId());
    income.setUserId(LOGGED_IN_USER_ID);

    cout << "Podaj warosc przychodu: ";
    income.setAmount(AdditionalMethods::correctAmount(AdditionalMethods::loadLine()));

    cout << "Czy przychod dotyczy dnia dzisiejszego? (t/n): ";
    answer = AdditionalMethods::loadChar();

    while (answer != 'n' && answer != 't')
    {
        cout << "podales nieprawidlowa litere" << endl;
        cout << "podaj ponownie odpowiedz: TAK (t) lub NIE (n)" << endl;
        answer = AdditionalMethods::loadChar();
    }
    if (answer == 'n')
    {
        cout << "Podaj date przychodu w formacie rrrr-mm-dd: ";

        dateTemp = AdditionalMethods::loadLine();
        cout << endl;

        while (date.isDateCorrect(dateTemp) == false)
        {
            cout << "Data nieprawidlowa" << endl;
            cout << "Podaj porawna date: " << endl;
            dateTemp = AdditionalMethods::loadLine();
        }
        income.setDate(date.convertStringDateToIntegerDate(dateTemp));
    }
    if (answer == 't')
    {
        cout << "dzisiejsza data to: " << date.convertIntegerDateToStringDate(currentdate.getCurrentDateInt())  << endl;
        income.setDate(currentdate.getCurrentDateInt() );
    }
    cout << "Podaj opis przychodu np. wyplata, sprzedaz na allegro itp.: ";
    income.setDescription(AdditionalMethods::loadLine());

    return income;
}
int BalanceSheet::getIncomeNewId()
{
    if (incomes.empty() == true)
        return 1;
    else
        return incomes.back().getId() + 1;
}
//--------------------------------------------------------------------

void BalanceSheet::displayIncomesCurrentMonth()
{
    CurrentDate currentDate;
    sumIncomes = 0;

    int firstDayCurrentMonth = currentDate.firstDayCurrentMonth();

    cout << endl << "PRZYCHODY W BIEZACYM MIESIACU: " << endl;

    for (int i = 0; i < incomes.size(); i++)
    {
        if (incomes[i].getDate() >= firstDayCurrentMonth)
        {
            cout << "data: " << date.convertIntegerDateToStringDate(incomes[i].getDate())
                 << " wartosc: " << incomes[i].getAmount() << endl;
            sumIncomes += incomes[i].getAmount();
        }
    }
}
void BalanceSheet::displayIncomesPreviousMonth()
{
    CurrentDate currentDate;
    sumIncomes = 0;

    int firstDayCurrentMonth = currentDate.firstDayCurrentMonth();
    int firstDayPreviousMonth = date.firstDayPreviousMonth();

    cout << endl << "PRZYCHODY W POPRZEDNIM MIESIACU: " << endl;
    for (int i = 0; i < incomes.size(); i++)
    {
        if (incomes[i].getDate() < firstDayCurrentMonth && incomes[i].getDate() >= firstDayPreviousMonth)
        {
            cout << "data: " << date.convertIntegerDateToStringDate(incomes[i].getDate())
                 << " wartosc: " << incomes[i].getAmount() << endl;
            sumIncomes += incomes[i].getAmount();
        }
    }
}
void BalanceSheet::displayIncomesPeriodTime()
{
    int startDate = date.getStartDate();
    int endDate = date.getEndDate();
    sumIncomes = 0;

    cout << endl << "PRZYCHODY W PODANYM OKRESIE: od: "
         << date.convertIntegerDateToStringDate(startDate) << " do: "
         << date.convertIntegerDateToStringDate(endDate) << endl;
    for (int i = 0; i < incomes.size(); i++)
    {
        if (incomes[i].getDate() <= endDate && incomes[i].getDate() >= startDate)
        {
            cout << "data: " << date.convertIntegerDateToStringDate(incomes[i].getDate())
                 << " wartosc przychodu: " << incomes[i].getAmount() << endl;
            sumIncomes += incomes[i].getAmount();
        }
    }
}
//-------------------------------EXPENSE-------------------------------------
void BalanceSheet::addExpense()
{
    Expense expense;
    system("cls");
    cout << " >>> DODAWANIE KOSZTU <<<" << endl << endl;

    expense = enterNewExpenseData();
    expenses.push_back(expense);
    xmlFileExpenses.addExpenseToFile(expense);

    cout << endl;
    cout << "Nowy koszt zostal dodany" << endl;
    system("pause");
}

Expense BalanceSheet::enterNewExpenseData()
{
    Expense expense;
    CurrentDate currentdate;
    char answer;
    string dateTemp;

    expense.setId(getExpenseNewId());
    expense.setUserId(LOGGED_IN_USER_ID);

    cout << "Podaj warosc kosztu: ";
    expense.setAmount(AdditionalMethods::correctAmount(AdditionalMethods::loadLine()));

    cout << "koszt dotyczy dnia dzisiejszego? (t/n): ";
    answer = AdditionalMethods::loadChar();

    while (answer != 'n' && answer != 't')
    {
        cout << "podales nieprawidlowa litere" << endl;
        cout << "podaj ponownie odpowiedz: TAK (t) lub NIE (n)" << endl;
        answer = AdditionalMethods::loadChar();
    }
    if (answer == 'n')
    {
        cout << "Podaj date kosztu w formacie rrrr-mm-dd: ";

        dateTemp = AdditionalMethods::loadLine();
        cout << endl;

        while (date.isDateCorrect(dateTemp) == false)
        {
            cout << "Data nieprawidlowa" << endl;
            cout << "Podaj porawna date: " << endl;
            dateTemp = AdditionalMethods::loadLine();
        }
        expense.setDate(date.convertStringDateToIntegerDate(dateTemp));
    }
    if (answer == 't')
    {
        cout << "dzisiejsza data to: " << date.convertIntegerDateToStringDate(currentdate.getCurrentDateInt())  << endl;
        expense.setDate(currentdate.getCurrentDateInt() );
    }
    cout << "Podaj opis kosztu np. wyplata, sprzedaz na allegro itp.: ";
    expense.setDescription(AdditionalMethods::loadLine());

    return expense;
}
int BalanceSheet::getExpenseNewId()
{
    if (expenses.empty() == true)
        return 1;
    else
        return expenses.back().getId() + 1;
}

void BalanceSheet::displayExpensesCurrentMonth()
{
    CurrentDate currentDate;
    sumExpenses = 0;

    int firstDayCurrentMonth = currentDate.firstDayCurrentMonth();
    cout << endl << "WYDATKI W BIEZACYM MIESIACU: " << endl;

    for (int i = 0; i < expenses.size(); i++)
    {
        if (expenses[i].getDate() >= firstDayCurrentMonth)
        {
            cout << "data: " << date.convertIntegerDateToStringDate(expenses[i].getDate())
                 << " wartosc: " << expenses[i].getAmount() << endl;
            sumExpenses += expenses[i].getAmount();
        }
    }
}
void BalanceSheet::displayExpensesPreviousMonth()
{
    CurrentDate currentDate;
    sumExpenses = 0;

    int firstDayCurrentMonth = currentDate.firstDayCurrentMonth();
    int firstDayPreviousMonth = date.firstDayPreviousMonth();

    cout << endl << "WYDATKI W POPRZEDNIM MIESIACU: " << endl;
    for (int i = 0; i < expenses.size(); i++)
    {
        if (expenses[i].getDate() < firstDayCurrentMonth && expenses[i].getDate() >= firstDayPreviousMonth)
        {
            cout << "data: " << date.convertIntegerDateToStringDate(expenses[i].getDate())
                 << " wartosc: " << expenses[i].getAmount() << endl;
            sumExpenses += expenses[i].getAmount();
        }
    }
}
void BalanceSheet::displayExpensesPeriodTime()
{
    int startDate = date.getStartDate();
    int endDate = date.getEndDate();
    sumExpenses = 0;

    cout << endl << "WYDATKI W PODANYM OKRESIE: od "
         << date.convertIntegerDateToStringDate(startDate)
         << " do " << date.convertIntegerDateToStringDate(endDate) << endl;
    for (int i = 0; i < expenses.size(); i++)
    {
        if (expenses[i].getDate() <= endDate && expenses[i].getDate() >= startDate)
        {
            cout << "data: " << date.convertIntegerDateToStringDate(expenses[i].getDate())
                 << " wartosc: " << expenses[i].getAmount() << endl;
            sumExpenses += expenses[i].getAmount();
        }
    }
}
//---------------------------------------------------------------------------
void BalanceSheet::setPeriodTime()
{
    int startDate;
    int endDate;
    string startDateStr;
    string endDateStr;

    cout << "Podaj date poczatkowa w formacie rrrr-mm-dd: ";

    startDateStr = AdditionalMethods::loadLine();

    while (date.isDateCorrect(startDateStr) == false)
    {
        cout << "Data nieprawidlowa" << endl;
        cout << "Podaj porawna date: " << endl;
        startDateStr = AdditionalMethods::loadLine();
    }
    startDate = date.convertStringDateToIntegerDate(startDateStr);
    date.setStartDate(startDate);

    cout << "Podaj date koncowa w formacie rrrr-mm-dd: ";

    endDateStr = AdditionalMethods::loadLine();

    while (date.isDateCorrect(endDateStr) == false)
    {
        cout << "Data nieprawidlowa" << endl;
        cout << "Podaj porawna date: " << endl;
        endDateStr = AdditionalMethods::loadLine();
    }
    endDate = date.convertStringDateToIntegerDate(endDateStr);
    date.setEndDate(endDate);
}

void BalanceSheet::displayIncomesSum()
{
    cout << endl <<"SUMA PRZYCHODOW: " << sumIncomes << "zl";
}
void BalanceSheet::displayExpensesSum()
{
    cout << endl << "SUMA WYDATKOW: " << sumExpenses << "zl";
}
void BalanceSheet::displayIncomesExpensesSum()
{
    float incomesExpensesSum = sumIncomes - sumExpenses;
    cout << endl << "SUMA PRZYCHODOW I WYDATKOW: " << incomesExpensesSum << "zl" << endl;
}
