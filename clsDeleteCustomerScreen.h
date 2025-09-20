#pragma once
#include <iomanip>
#include <string>
#include "Users.h";
#include "clsScreen.h"
#include "clsGlobal.h"
class clsDeleteCustomerScreen : protected clsScreen
{
private : 
   static void DeleteCustomer()
    {
        int CustomerID = clsGlobal::ReadID("Customer ID");
        Customer Customer = Customer::FindCustomerByCustomerID(CustomerID);
        if (Customer.CustomerID != 0)
        {

            Customer.PrintCustomerCard();
            char Answer = 'n';
            cout << "\n\n\t\t\t\t\tAre you sure you want delete this Customer? y/n ? ";
            cin >> Answer;
            if (Answer == 'y' || Answer == 'Y')
            {
                if (Customer.DeleteCustomer())
                {
                    cout << "\n\n\t\t\t\t\tCustomer Deleted Successfully.";
                }
                else {
                    cout << "\n\n\t\t\t\t\tError: Customer could not be deleted.";
                }
            }
        }
        else
        {
            cout << "\n\t\t\t\t\tCustomer with Customer ID (" << CustomerID << ") is Not Found!";
        }

    }
public:
    static void ShowDeleteCustomerScreen()
    {
        _DrawScreenHeader("\t\t\t\t\tDelete Customer Screen");
        cout << "\n\t\t\t\t\t-----------------------------------\n";
        cout << "\t\t\t\t\t\tDelete Customer ";
        cout << "\n\t\t\t\t\t-----------------------------------\n";

        DeleteCustomer();

    }
};

