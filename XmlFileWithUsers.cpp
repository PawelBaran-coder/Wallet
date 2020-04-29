#include "XmlFileWithUsers.h"
#include <cstdlib>

void XmlFileWithUsers::addUserToFile(User user)
{
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
    xml.AddElem("userId", user.getId());
    xml.AddElem("name", user.getName());
    xml.AddElem("lastName", user.getLastName());
    xml.AddElem("nick", user.getNick());
    xml.AddElem("password", user.getPassword());

    xml.Save(getFileName().c_str());
}

vector <User> XmlFileWithUsers::loadUsersFromFile()
{
    User user;
    vector <User> users;

    CMarkup xml;

    bool fileExists = xml.Load(getFileName().c_str());

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

void XmlFileWithUsers::addAllUsersToFile(vector <User> &users)
{
    CMarkup xml;

    xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
    xml.AddElem("Users");
    xml.IntoElem();
    for ( int i=0; i<users.size(); ++i )
    {
        xml.AddElem( "User" );
        xml.IntoElem();
        xml.AddElem( "userId", users[i].getId() );
        xml.AddElem( "name", users[i].getName() );
        xml.AddElem( "lastName", users[i].getLastName() );
        xml.AddElem( "nick", users[i].getNick() );
        xml.AddElem( "password", users[i].getPassword() );
        xml.OutOfElem();
    }
    xml.Save(getFileName().c_str());
}
