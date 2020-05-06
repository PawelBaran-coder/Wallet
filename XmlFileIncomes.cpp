#include "XmlFileIncomes.h"
#include <cstdlib>
/*
int XmlFileIncomes::getLastIncomeId()
{
    getLastIncomeIdFromFile();
    return lastIncomeID;
}

int XmlFileIncomes::getLastIncomeIdFromFile()
{
    lastIncomeID = 0;
    Income income;

    CMarkup xml;

    bool fileExists = xml.Load(getIncomesFileName().c_str());

    if (!fileExists)
    {
        cout <<"nie mozna otworzyc pliku" << endl;
        system("pause");
    }

    xml.FindElem();
    xml.IntoElem();
    while ( xml.FindElem("Income") )
    {
        xml.IntoElem();
        xml.FindElem( "incomeId" );
        income.setIncomeId(atoi( MCD_2PCSZ(xml.GetData()) ));

        xml.OutOfElem();
    }
}
*/
void XmlFileIncomes::addIncomeToFile(Income income)
{
    CMarkup xml;

    bool fileExists = xml.Load(getIncomesFileName().c_str());

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("incomeId", income.getIncomeId());
    xml.AddElem("userId", income.getUserId());
    xml.AddElem("incomeDate", income.getIncomeDate());
    xml.AddElem("incomeAmount", income.getIncomeAmount());
    xml.AddElem("description", income.getDescription());

    xml.Save(getIncomesFileName().c_str());
}

vector <Income> XmlFileIncomes::loadIncomesFromFile(int loggedInUserId)
{
    Income income;
    vector <Income> incomes;

    CMarkup xml;

    bool fileExists = xml.Load(getIncomesFileName().c_str());

    if (!fileExists)
    {
        cout <<"nie mozna otworzyc pliku" << endl;
        system("pause");

    }

    xml.FindElem();
    xml.IntoElem();
    while ( xml.FindElem("Income") )
    {
        xml.IntoElem();
        xml.FindElem( "userId" );
        if (loggedInUserId == atoi( MCD_2PCSZ(xml.GetData()) ))
        {
            income.setUserId(atoi( MCD_2PCSZ(xml.GetData()) ));
            xml.FindElem( "incomeId" );
            income.setIncomeId(atoi( MCD_2PCSZ(xml.GetData()) ));
            xml.FindElem( "incomeDate" );
            income.setIncomeDate(atoi( MCD_2PCSZ(xml.GetData()) ));
            xml.FindElem( "incomeAmount" );
            income.setIncomeAmount(atoi( MCD_2PCSZ(xml.GetData()) ));
            xml.FindElem( "description" );
            income.setDescription(xml.GetData());
            incomes.push_back(income);
        }
        xml.OutOfElem();

    }
    cout << "jestes po wczytaniu przychodow z pliku" << endl;
    system("pause");
    return incomes;
    cout << "jestes po wczytaniu przychodow z pliku" << endl;
    system("pause");
}
