#include "XmlFileWithUsers.h"
#include <cstdlib>

void XmlFileWithUsers::addUserToFile(User user)
{
    int userId = user.getId();
    string name = user.getName();
    string lastName = user.getLastName();
    string nick = user.getNick();
    string password = user.getPassword();

    CMarkup xml;

    bool fileExists = xml.Load(getFileName().c_str());

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("userId", userId);
    xml.AddElem("name", name);
    xml.AddElem("lastName", lastName);
    xml.AddElem("nick", lastName);
    xml.AddElem("password", password);

    xml.Save(getFileName().c_str());
}

vector <User> XmlFileWithUsers::loadUsersFromFile()
{
    User user;
    vector <User> users;

    CMarkup xml;

    bool fileExists = xml.Load( "users.xml" );

    if (!fileExists)
    {
        cout <<"nie mozna otworzyc pliku" << endl;
    }

    xml.FindElem();
    xml.IntoElem();
    while ( xml.FindElem("User") )
    {
        xml.IntoElem();
        xml.FindElem( "userId" );
        user.setId(atoi( MCD_2PCSZ(xml.GetData()) ));
        xml.FindElem( "name" );
        user.setName(xml.GetData());
        xml.FindElem( "lastName" );
        user.setLastName(xml.GetData());
        xml.FindElem( "nick" );
        user.setNick(xml.GetData());
        xml.FindElem( "password" );
        user.setPassword(xml.GetData());

        users.push_back(user);
        xml.OutOfElem();
    }

    return users;
}
