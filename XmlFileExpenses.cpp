#include "XmlFileExpenses.h"
#include <cstdlib>

void XmlFileExpenses::addExpenseToFile(Expense expense)
{
    CMarkup xml;

    bool fileExists = xml.Load(getExpensesFileName().c_str());

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expense");
    xml.IntoElem();

    xml.AddElem("userId", expense.getUserId());
    xml.AddElem("expenseId", expense.getId());
    xml.AddElem("expenseAmount", AdditionalMethods::convertFloatToString(expense.getAmount()));
    xml.AddElem("expenseDate", expense.getDate());
    xml.AddElem("description", expense.getDescription());

    xml.Save(getExpensesFileName().c_str());
}

vector <Expense> XmlFileExpenses::loadExpensesFromFile(int loggedInUserId)
{
    Expense expense;
    vector <Expense> expenses;

    CMarkup xml;

    bool fileExists = xml.Load(getExpensesFileName().c_str());

    xml.FindElem();
    xml.IntoElem();
    while ( xml.FindElem("Expense") )
    {
        xml.IntoElem();
        xml.FindElem( "userId" );

        if (loggedInUserId == atoi( MCD_2PCSZ(xml.GetData()) ))
        {
            expense.setUserId(atoi( MCD_2PCSZ(xml.GetData()) ));
            xml.FindElem( "expenseId" );
            expense.setId(atoi( MCD_2PCSZ(xml.GetData()) ));
            xml.FindElem( "expenseAmount" );
            expense.setAmount(AdditionalMethods::convertStringToFloat(xml.GetData()) );
            xml.FindElem( "expenseDate" );
            expense.setDate(atoi( MCD_2PCSZ(xml.GetData()) ));
            xml.FindElem( "description" );
            expense.setDescription(xml.GetData());

            expenses.push_back(expense);
        }
        xml.OutOfElem();

    }
    return expenses;
}
