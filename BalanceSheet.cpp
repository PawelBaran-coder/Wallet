#include "BalanceSheet.h"

void BalanceSheet::addIncome()
{
    Income income;
    //system("cls");
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

    income.setIncomeId(getNewIncomeId());
    income.setUserId(LOGGED_IN_USER_ID);

    cout << "Podaj warosc przychodu: ";
    income.setIncomeAmount(AdditionalMethods::correctAmount(AdditionalMethods::loadLine()));

    cout << "Czy przychod dotyczy dnia dzisiejszego? (t/n): ";
    cin >> answer;

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
        income.setIncomeDate(AdditionalMethods::convertStringDateToIntegerDate(AdditionalMethods::loadLine()) );
    }

    if (answer == 't')
    {
        cout << "dzisiejsza data to: " << currentdate.getCurrentDateInt() << endl;
        income.setIncomeDate(currentdate.getCurrentDateInt() );
    }

    cin.ignore();

    cout << "Podaj opis przychodu np. wyplata, sprzedaz na allegro itp.: ";

    income.setDescription(AdditionalMethods::loadLine());

    cout << "dodane do wektora" << endl;
    cout << endl << "Id:        " << income.getIncomeId() << endl;
    cout << "Id uzytkownika:    " << income.getUserId() << endl;
    cout << "data przychodu:    " << income.getIncomeDate() << endl;
    cout << "wartosc przychodu: " << income.getIncomeAmount() << endl;
    cout << "opis:              " << income.getDescription() << endl;
    system("pause");
    return income;
}
int BalanceSheet::getNewIncomeId()
{
    if (incomes.empty() == true)
        return 1;
    else
        return incomes.back().getIncomeId() + 1;
}
void BalanceSheet::displayAllIncome()
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
    cout << endl << "Id:                 " << income.getIncomeId() << endl;
    cout << "Id uzytkownika:               " << income.getUserId() << endl;
    cout << "data przychodu:           " << income.getIncomeDate() << endl;
    cout << "wartosc przychodu:     " << income.getIncomeAmount() << endl;
    cout << "opis:              " << income.getDescription() << endl;

}

void BalanceSheet::displayAllIncomes1()
{
    cout << "odczytane z wektora" << endl;
    cout << " liczba zapisanych przychodow w wektorze: " << incomes.size() << endl;
    system("pause");
    for (int i = 0; i < incomes.size(); i++)
    {
        cout << incomes[i].getUserId() << endl;
        cout << incomes[i].getIncomeId() << endl;
        cout << incomes[i].getIncomeAmount() << endl;
        cout << incomes[i].getIncomeDate() << endl;
        cout << incomes[i].getDescription() << endl;
    }
    system("pause");

}
