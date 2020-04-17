#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User
{
    int userId;
    string name;
    string password;

public:
    void setId(int newId);
    void setName(string newName);
    void setPassword(string newPassword);

    int getId();
    string getName();
    string getPassword();
};




#endif
