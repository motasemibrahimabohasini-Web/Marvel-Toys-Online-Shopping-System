#pragma once
#include <iomanip>
#include <string>
#include "Users.h";
#include "clsScreen.h"
#include "clsGlobal.h"
class clsAllCustomersScreen : protected clsScreen
{


public: 
   static void ShowAllCustomersScreen()
    {

        vector <Customer> vCustomers = Customer::LoadCustomersDataFromFile();
        _DrawScreenHeader("List Customers Screen");
        cout << "\n\t\t\t\t\tCustomer List (" << vCustomers.size() << ") Customer(s).";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << "| " << left << setw(15) << "ID";
        cout << "| " << left << setw(20) << "Name";
        cout << "| " << left << setw(15) << "Contact";
        cout << "| " << left << setw(40) << "Adress";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vCustomers.size() == 0)
            cout << "\t\t\t\tNo Customers Available In the System!";
        else

            for (Customer Customer : vCustomers)
            {

                Customer.PrintCustomerRecordLine();
                cout << "\n\n";
            }

        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;
    }
};

