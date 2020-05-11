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

    xml.AddElem("userId", income.getUserId());
    xml.AddElem("incomeId", income.getIncomeId());
    xml.AddElem("incomeAmount", AdditionalMethods::convertFloatToString(income.getIncomeAmount()));
    xml.AddElem("incomeDate", income.getIncomeDate());
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
            cout << "userId: "<< income.getUserId() << endl;
            xml.FindElem( "incomeId" );
            income.setIncomeId(atoi( MCD_2PCSZ(xml.GetData()) ));
            cout << "incomeId: "<< income.getIncomeId() << endl;
            xml.FindElem( "incomeAmount" );
            income.setIncomeAmount(AdditionalMethods::convertStringToFloat(xml.GetData()) );
            cout << "incomeAmount: "<< income.getIncomeAmount() << endl;
            xml.FindElem( "incomeDate" );
            income.setIncomeDate(atoi( MCD_2PCSZ(xml.GetData()) ));
            cout << "incomeDate: "<< income.getIncomeDate() << endl;
            xml.FindElem( "description" );
            income.setDescription(xml.GetData());
            cout << "description: "<< income.getDescription() << endl;
            system("pause");
            incomes.push_back(income);
        }
        xml.OutOfElem();

    }
    system("pause");
    return incomes;
}
