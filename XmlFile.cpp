#include "XmlFile.h"
#include <fstream>

string XmlFile::getFileName()
{
    return FILE_NAME_USERS;
}
/*
string XmlFile::getIncomesFileName()
{
    return FILE_NAME_INCOMES;
}

string XmlFile::getExpensesFileName()
{
    return FILE_NAME_EXPENSES;
}
*/

/*
bool XmlFile::isEmpty()
{
    bool emptyFile = true;
    fstream XmlFile;
    XmlFile.open(getFileName().c_str(), ios::app);

    if (XmlFile.good() == true)
    {
        XmlFile.seekg(0, ios::end);
        if (XmlFile.tellg() != 0)
            emptyFile = false;
    }

    XmlFile.close();
    return emptyFile;

}
*/
