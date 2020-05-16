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
    cout << "Nowy przychod zostal dodany" << endl;
    system("pause");
}

Income BalanceSheet::enterNewIncomeData()
{
    Income income;
    CurrentDate currentdate;
    char answer;

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
        cin >> answer;
    }
    if (answer == 'n')
    {
        cout << "Podaj date przychodu w formacie rrrr-mm-dd: ";
//NALEZY JESZCZE SPRAWDZIC POPRAWNOSC PODANEJ DATY
        income.setDate(AdditionalMethods::convertStringDateToIntegerDate(AdditionalMethods::loadLine()) );
    }
    if (answer == 't')
    {
        cout << "dzisiejsza data to: " << currentdate.getCurrentDateInt() << endl;
        income.setDate(currentdate.getCurrentDateInt() );
    }
    cout << "Podaj opis przychodu np. wyplata, sprzedaz na allegro itp.: ";
    income.setDescription(AdditionalMethods::loadLine());

    cout << "dodane do wektora" << endl << endl;
    cout << "Id przychodu:      " << income.getId() << endl;
    cout << "Id uzytkownika:    " << income.getUserId() << endl;
    cout << "data przychodu:    " << income.getDate() << endl;
    cout << "wartosc przychodu: " << income.getAmount() << endl;
    cout << "opis:              " << income.getDescription() << endl;
    system("pause");
    return income;
}
int BalanceSheet::getIncomeNewId()
{
    if (incomes.empty() == true)
        return 1;
    else
        return incomes.back().getId() + 1;
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
    cout << "Nowy przychod zostal dodany" << endl;
    system("pause");
}

Expense BalanceSheet::enterNewExpenseData()
{
    Expense expense;
    CurrentDate currentdate;
    char answer;

    expense.setId(getExpenseNewId());
    expense.setUserId(LOGGED_IN_USER_ID);

    cout << "Podaj warosc kosztu: ";
    expense.setAmount(AdditionalMethods::correctAmount(AdditionalMethods::loadLine()));

    cout << "Czy koszt dotyczy dnia dzisiejszego? (t/n): ";
    answer = AdditionalMethods::loadChar();

    while (answer != 'n' && answer != 't')
    {
        cout << "podales nieprawidlowa litere" << endl;
        cout << "podaj ponownie odpowiedz: TAK (t) lub NIE (n)" << endl;
        cin >> answer;
    }

    if (answer == 'n')
    {
        cout << "Podaj date kosztu w formacie rrrr-mm-dd: ";
//NALEZY JESZCZE SPRAWDZIC POPRAWNOSC PODANEJ DATY
        expense.setDate(AdditionalMethods::convertStringDateToIntegerDate(AdditionalMethods::loadLine()) );
    }

    if (answer == 't')
    {
        cout << "dzisiejsza data to: " << currentdate.getCurrentDateInt() << endl;
        expense.setDate(currentdate.getCurrentDateInt() );
    }

    cout << "Podaj opis kosztu np. jedzenie, mieszkanie, transport itp.: ";
    expense.setDescription(AdditionalMethods::loadLine());

    cout << "dodane do wektora" << endl << endl;
    cout << "Id kosztu:      " << expense.getId() << endl;
    cout << "Id uzytkownika: " << expense.getUserId() << endl;
    cout << "data kosztu:    " << expense.getDate() << endl;
    cout << "wartosc kosztu: " << expense.getAmount() << endl;
    cout << "opis:           " << expense.getDescription() << endl;
    system("pause");
    return expense;
}
int BalanceSheet::getExpenseNewId()
{
    if (expenses.empty() == true)
        return 1;
    else
        return expenses.back().getId() + 1;
}
void BalanceSheet::displayAllExpensesItr()
{
    system("cls");
    if (!expenses.empty())
    {
        cout << "             >>> KOSZTY <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++)
        {
            displayExpense(*itr);
        }
        cout << endl;
    }
    else
    {
        cout << endl << "Ksiazka kosztow jest pusta." << endl << endl;
    }
    system("pause");
}
void BalanceSheet::displayExpense(Expense expense)
{
    cout << endl << "Id:                 " << expense.getId() << endl;
    cout << "Id uzytkownika:               " << expense.getUserId() << endl;
    cout << "data kosztu:           " << expense.getDate() << endl;
    cout << "wartosc kosztu:     " << expense.getAmount() << endl;
    cout << "opis:              " << expense.getDescription() << endl;
}
void BalanceSheet::displayExpensesCurrentMonth()
{
    CurrentDate currentDate;

    int firstDayCurrentMonth = currentDate.firstDayCurrentMonth();

    for (int i = 0; i < expenses.size(); i++)
    {
        if (expenses[i].getDate() >= firstDayCurrentMonth)
        {
            cout << "data: " << expenses[i].getDate() << endl;
            cout << "wartosc kosztu: " << expenses[i].getAmount() << endl;
        }
    }
}
void BalanceSheet::displayExpensesPreviousMonth()
{
    CurrentDate currentDate;
    Date date;

    int firstDayCurrentMonth = currentDate.firstDayCurrentMonth();
    int firstDayPreviousMonth = date.firstDayPreviousMonth();

    for (int i = 0; i < expenses.size(); i++)
    {
        if (expenses[i].getDate() < firstDayCurrentMonth && expenses[i].getDate() >= firstDayPreviousMonth)
        {
            cout << "data: " << expenses[i].getDate() << endl;
            cout << "wartosc kosztu: " << expenses[i].getAmount() << endl;
        }
    }
}
void BalanceSheet::displayExpensesPeriodTime()
{
    int startingDate;
    int endDate;

    cout << "Podaj date poczatkowa w formacie rrrr-mm-dd: ";
    startingDate = AdditionalMethods::convertStringDateToIntegerDate(AdditionalMethods::loadLine());
    cout << "Podaj date koncowa w formacie rrrr-mm-dd: ";
    endDate = AdditionalMethods::convertStringDateToIntegerDate(AdditionalMethods::loadLine());

    for (int i = 0; i < expenses.size(); i++)
    {
        if (expenses[i].getDate() <= endDate && expenses[i].getDate() >= startingDate)
        {
            cout << "data: " << expenses[i].getDate() << endl;
            cout << "wartosc kosztu: " << expenses[i].getAmount() << endl;
        }
    }
}

//--------------------------------------------------------------------
void BalanceSheet::displayAllIncomesItr()
{
    system("cls");
    if (!incomes.empty())
    {
        cout << "             >>> INCOMES <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++)
        {
            displayIncome(*itr);
        }
        cout << endl;
    }
    else
    {
        cout << endl << "Ksiazka przychodow jest pusta." << endl << endl;
    }
    system("pause");
}
void BalanceSheet::displayIncome(Income income)
{
    cout << endl << "Id:                 " << income.getId() << endl;
    cout << "Id uzytkownika:               " << income.getUserId() << endl;
    cout << "data przychodu:           " << income.getDate() << endl;
    cout << "wartosc przychodu:     " << income.getAmount() << endl;
    cout << "opis:              " << income.getDescription() << endl;
}
void BalanceSheet::displayAllIncomes()
{
    cout << "odczytane z wektora" << endl;
    cout << " liczba zapisanych przychodow w wektorze: " << incomes.size() << endl;

    for (int i = 0; i < incomes.size(); i++)
    {
        cout << incomes[i].getUserId() << endl;
        cout << incomes[i].getId() << endl;
        cout << incomes[i].getAmount() << endl;
        cout << incomes[i].getDate() << endl;
        cout << incomes[i].getDescription() << endl;
    }
    system("pause");
}
void BalanceSheet::displayIncomesCurrentMonth()
{
    CurrentDate currentDate;

    int firstDayCurrentMonth = currentDate.firstDayCurrentMonth();

    for (int i = 0; i < incomes.size(); i++)
    {
        if (incomes[i].getDate() >= firstDayCurrentMonth)
        {
            cout << "data: " << incomes[i].getDate() << endl;
            cout << "wartosc przychodu: " << incomes[i].getAmount() << endl;
        }
    }
}
void BalanceSheet::displayIncomesPreviousMonth()
{
    CurrentDate currentDate;
    Date date;

    int firstDayCurrentMonth = currentDate.firstDayCurrentMonth();
    int firstDayPreviousMonth = date.firstDayPreviousMonth();

    for (int i = 0; i < incomes.size(); i++)
    {
        if (incomes[i].getDate() < firstDayCurrentMonth && incomes[i].getDate() >= firstDayPreviousMonth)
        {
            cout << "data: " << incomes[i].getDate() << endl;
            cout << "wartosc przychodu: " << incomes[i].getAmount() << endl;
        }
    }
}
void BalanceSheet::displayIncomesPeriodTime()
{
    int startingDate;
    int endDate;

    cout << "Podaj date poczatkowa w formacie rrrr-mm-dd: ";
    startingDate = AdditionalMethods::convertStringDateToIntegerDate(AdditionalMethods::loadLine());
    cout << "Podaj date koncowa w formacie rrrr-mm-dd: ";
    endDate = AdditionalMethods::convertStringDateToIntegerDate(AdditionalMethods::loadLine());

    for (int i = 0; i < incomes.size(); i++)
    {
        if (incomes[i].getDate() <= endDate && incomes[i].getDate() >= startingDate)
        {
            cout << "data: " << incomes[i].getDate() << endl;
            cout << "wartosc przychodu: " << incomes[i].getAmount() << endl;
        }
    }
}
void BalanceSheet::displayIncomesSum()
{

}
void BalanceSheet::displayExpensesSum()
{

}
