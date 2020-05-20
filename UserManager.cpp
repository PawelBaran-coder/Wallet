#include "UserManager.h"

void UserManager::registration()
{
    User user = enterNewUserData();

    users.push_back(user);
    xmlFileWithUsers.addUserToFile(user);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

User UserManager::enterNewUserData()
{
    User user;
    string name;
    string lastName;

    user.setId(getNewUserID());

    cout << "Podaj swoje imie: ";
    name = AdditionalMethods::loadLine();
    user.setName(name);

    cout << "Podaj swoje nazwisko: ";
    lastName = AdditionalMethods::loadLine();
    user.setLastName(lastName);

    string nick;
    do
    {
        cout << "Podaj login: ";
        nick = AdditionalMethods::loadLine();
        user.setNick(nick);
    }
    while (isNick(user.getNick()) == true);

    string password;
    cout << "Podaj haslo: ";
    password = AdditionalMethods::loadLine();
    user.setPassword(password);

    return user;
}

int UserManager::getNewUserID()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

bool UserManager::isNick(string nick)
{
    for (int i = 0; i < users.size(); i++)
    {
        if(users[i].getNick() == nick)
        {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

void UserManager::logIn()
{
    User user;
    string nick = "", password = "";

    cout << endl << "Podaj login: ";

    nick = AdditionalMethods::loadLine();

    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].getNick() == nick)
        {
            for (int attempts = 3; attempts > 0; attempts--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << attempts << ": ";
                password = AdditionalMethods::loadLine();

                if (users[i].getPassword() == password)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    loggedInUserID = users[i].getId();

                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return;
        }
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return;
}

void UserManager::changePasswordLoggedInUser()
{
    cout << loggedInUserID <<endl;
    string newPassword = "";
    cout << "Podaj nowe haslo: ";
    newPassword = AdditionalMethods::loadLine();

    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].getId() == loggedInUserID)
        {
            users[i].setPassword(newPassword);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    xmlFileWithUsers.addAllUsersToFile(users);
}
void UserManager::logOut()
{
    loggedInUserID = 0;
    cout << endl << "Wylogowales sie!" << endl << endl;
}

bool UserManager::isLogIn()
{
    if(loggedInUserID > 0)
        return true;
    else
        return false;
}

int UserManager::getLoggedInUserID()
{
    return loggedInUserID;
}
