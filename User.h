#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User
{
    int userId;
    string name;
    string lastName;
    string nick;
    string password;

public:
    void setId(int newId);
    void setName(string newName);
    void setLastName(string newLastName);
    void setNick(string newNick);
    void setPassword(string newPassword);

    int getId();
    string getName();
    string getLastName();
    string getNick();
    string getPassword();
};




#endif
