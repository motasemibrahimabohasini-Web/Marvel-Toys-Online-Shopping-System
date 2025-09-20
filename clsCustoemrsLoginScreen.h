#pragma once
#include <iomanip>
#include <string>
#include "Customers.h"
#include "clsScreen.h"
#include "clsGlobal.h"
#include "clsCustomersMenuOptionScreen.h"
#include <string>
class clsCustomerLoginScreen : protected clsScreen
{

private:

    static Customer LoginCustomer() {

        string Customername;
        cout << "\t\t\t\t\tCustomername : ";
        getline(cin >> ws, Customername);

        while (Customername.length() < 5)
        {

            cout << "\n\t\t\t\t\t Invalid input Customername should cintain 5 characters at least!  \n";
            cout << "\t\t\t\t\tCustomername : ";
         
            getline(cin >> ws, Customername);

        }
        string Password;
        cout << "\t\t\t\t\tPassword : ";
        cin >> Password;

        while (Password.length() < 5)
        {

            cout << "\n\t\t\t\t\t Invalid input Password should cintain 5 characters at least!  \n";
            cout << "\t\t\t\t\tPassword : ";
            cin >> Password;

        }

        return Customer::FindCustomerByCustomerameAndPassword(Customername, Password);

    }

public:
    static void ShowLoginCustomerScreen()
    {
        _DrawScreenHeader("Login Customer Screen");
        int counter = 5;
        if (clsGlobal::CurrentCustomer.CustomerID == 0)
        {
            do
            {

                clsGlobal::CurrentCustomer = LoginCustomer();
                counter--;
                if (counter > 0 && clsGlobal::CurrentCustomer.CustomerID == 0)
                {
                    cout << "\t\t\t\t\tInvalid Customername or Password :  \n";
                    cout << "\t\t\t\t\tYou have " + to_string(counter) + " attempts left....\n" << endl;
                }
                if (counter == 0)
                {

                    cout << "\t\t\t\t\tYou have bein trying for 5 times Contact Your admin." << endl;
                    return;

                }


            } while (clsGlobal::CurrentCustomer.CustomerID == 0);
            clsCustomersMenuOption::ShowCustomersMenu();
        }
        else {
            clsCustomersMenuOption::ShowCustomersMenu();
        }

    }
};