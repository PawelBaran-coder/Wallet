#include "XmlFileIncomes.h"
#include <cstdlib>

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
    xml.AddElem("incomeId", income.getId());
    xml.AddElem("incomeAmount", AdditionalMethods::convertFloatToString(income.getAmount()));
    xml.AddElem("incomeDate", income.getDate());
    xml.AddElem("description", income.getDescription());

    xml.Save(getIncomesFileName().c_str());
}

vector <Income> XmlFileIncomes::loadIncomesFromFile(int loggedInUserId)
{
    Income income;
    vector <Income> incomes;

    CMarkup xml;

    bool fileExists = xml.Load(getIncomesFileName().c_str());

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
            income.setId(atoi( MCD_2PCSZ(xml.GetData()) ));
            xml.FindElem( "incomeAmount" );
            income.setAmount(AdditionalMethods::convertStringToFloat(xml.GetData()) );
            xml.FindElem( "incomeDate" );
            income.setDate(atoi( MCD_2PCSZ(xml.GetData()) ));
            xml.FindElem( "description" );
            income.setDescription(xml.GetData());

            incomes.push_back(income);
        }
        xml.OutOfElem();
    }
    return incomes;
}
