#pragma once
#include <iomanip>
#include <string>
#include "Users.h";
#include "clsScreen.h"
#include "clsGlobal.h"
class clsFindCustomerScreen:protected clsScreen
{
private :
    static void FindCustomer()
    {
        int CustomerID = clsGlobal::ReadID("Customer ID");
        Customer Customer = Customer::FindCustomerByCustomerID(CustomerID);

        if (Customer.CustomerID != 0)
        {
            Customer.PrintCustomerCard();
        }
        else
        {
            cout << "\n\t\t\t\t\tCustomer with Customer ID (" << CustomerID << ") is Not Found!";
        }
    }
public:
    static void ShowFindCustomerScreen()
    {
        _DrawScreenHeader("Find Customer Info Screen");
        cout << "\n\t\t\t\t\t-----------------------------------\n";
        cout << "\t\t\t\t\t\tFind Customer Info";
        cout << "\n\t\t\t\t\t-----------------------------------\n";

        FindCustomer();
    }

};

