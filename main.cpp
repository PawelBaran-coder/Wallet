#include <iostream>
#include "WalletManager.h"

using namespace std;

char wybierzOpcjeZMenuGlownego();
char wybierzOpcjeZMenuUzytkownika();
char wczytajZnak();

int main()
{
    WalletManager walletManager("users.xml", "incomes.xml", "expenses.xml");

    char wybor;

    while (true)
    {
        if (walletManager.isLogIn() == false)
        {
            wybor = wybierzOpcjeZMenuGlownego();

            switch (wybor)
            {
            case '1':
                walletManager.registration();
                break;
            case '2':
                walletManager.logIn();
                break;
            case '8':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            wybor = wybierzOpcjeZMenuUzytkownika();

            switch (wybor)
            {
            case '1':
                walletManager.addIncome();
                break;

            case '2':
                walletManager.addExpense();
                break;

            case '3':
                walletManager.balanceCurrentMonth();
                break;

            case '4':
                walletManager.balancePreviousMonth();
                break;

            case '5':
                walletManager.balancePeriodTime();
                break;
            case '6':
                walletManager.changePasswordLoggedInUser();
                break;
            case '7':
                walletManager.logOut();
                break;
            }
        }
    }
    return 0;
}

char wybierzOpcjeZMenuGlownego()
{
    char choice;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "8. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = AdditionalMethods::loadChar();

    return choice;
}

char wybierzOpcjeZMenuUzytkownika()
{
    char choice;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z biezacego miesiaca" << endl;
    cout << "4. Bilans z poprzedniego miesiaca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;

    cout << "Twoj wybor: ";

    choice = AdditionalMethods::loadChar();

    return choice;
}


/*
int main()
{
    WalletManager walletManager("users.xml", "incomes.xml", "expenses.xml");

    //walletManager.registration();
    walletManager.displayAllUsers();
    walletManager.logIn();
    //walletManager.displayAllIncomes1();
    //walletManager.addIncome();
    //walletManager.addExpense();
    //walletManager.displayAllIncome();
    walletManager.displayIncomesCurrentMonth();
    walletManager.displayExpensesCurrentMonth();
    //walletManager.displayIncomesPreviousMonth();
    //walletManager.displayIncomesPeriodTime();
    //walletManager.changePasswordLoggedInUser();
    walletManager.displayIncomesSum();
    walletManager.displayExpensesSum();
    walletManager.displayIncomesExpensesSum();
    walletManager.logOut();

    return 0;
    */


