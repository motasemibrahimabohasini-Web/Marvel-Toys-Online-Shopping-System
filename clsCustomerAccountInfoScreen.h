#pragma once
#include <iomanip>
#include <string>
#include "Customers.h"
#include "clsScreen.h"
#include "clsGlobal.h"
class clsCustomerAccountInfoScreen : protected clsScreen
{
    static void PrintCustomerAccountInfo()
    {
        std::cout << "\n\t\t\t\t\tThe following are the Your details:\n";
        std::cout << "\t\t\t\t\t-----------------------------------";
        std::cout << "\n\t\t\t\t\tYour ID : " << clsGlobal::CurrentCustomer.CustomerID;
        std::cout << "\n\t\t\t\t\tYour Name    : " << clsGlobal::CurrentCustomer.CustomerName;
        std::cout << "\n\t\t\t\t\tYour Address     : " << clsGlobal::CurrentCustomer.CustomerAddress;
        std::cout << "\n\t\t\t\t\tYour Contact        : " << clsGlobal::CurrentCustomer.CustomerContact;
        std::cout << "\n\t\t\t\t\t-----------------------------------\n";
    }
public :
    static void ShowCustomerAccountInfoScreen()
    {
        _DrawScreenHeader("Account Info Screen");
        cout << "\n\t\t\t\t\t-----------------------------------\n";
        cout << "\t\t\t\t\t\tAccount Info ";
        cout << "\n\t\t\t\t\t-----------------------------------\n";

        PrintCustomerAccountInfo();

    }

};

