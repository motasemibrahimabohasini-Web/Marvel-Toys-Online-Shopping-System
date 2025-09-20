#pragma once
#include <iomanip>
#include <string>
#include "Customers.h"
#include "clsScreen.h"
#include "clsGlobal.h"
#include "clsAddNewCartScreen.h"
#include "clsCustomerBillScreen.h"
#include "clsCustomerAccountInfoScreen.h"
class clsCustomersMenuOption : protected clsScreen
{
private: 
    static void GoBackToCustomersMenu() {
        std::cout << "\n\nPress any key to go back to Main Menu...";
        system("pause>0");
        ShowCustomersMenu();
    }
    static void PerfromCustomersMenueOption(Customer::enCustomersMenu CustomersMenuOption)
    {
        switch (CustomersMenuOption)
        {
        case Customer::enCustomersMenu::enAddNewOrder:
            system("cls");
            clsAddNewcartScreen::ShowAddNewCartScreen();
            GoBackToCustomersMenu();
            break;

        case Customer::enCustomersMenu::enDisplayBill:
            system("cls");
            clsCustomerBillScreen::ShowBillScreen();
            GoBackToCustomersMenu();
            break;
        case Customer::enCustomerAccountInfo:
            system("cls");
          clsCustomerAccountInfoScreen::ShowCustomerAccountInfoScreen();
            GoBackToCustomersMenu();
        case Customer::enCustomersMenuExit:
            system("cls");
            

        }
    }
    static short ReadCustomersMenuOption()
    {
        short Choice = 0;
        cout << "\t\t\t\t\tChoose the Customers Menu Option [1 to 3]: ";
        cin >> Choice;
        while ((Choice > 4 || Choice < 1) || cin.fail())
        {
            cout << "\t\t\t\t\tInvalid input , Choose the Customers Menu Option [1 to 4]: ";
            cin.clear(); // reset error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> Choice;
        }
        return Choice;
    }


public : 
    static void ShowCustomersMenu()
    {
 

        system("cls");
        _DrawScreenHeader("Customers Menu Screen");
        std::cout << "\t\t\t\t\t===========================================\n";
        std::cout << "\t\t\t\t\t\t Customers Menue\n";
        std::cout << "\t\t\t\t\t===========================================\n";
        std::cout << "\t\t\t\t\t\t[1] Add New Order.\n";
        std::cout << "\t\t\t\t\t\t[2] Display Bill.\n";
        std::cout << "\t\t\t\t\t\t[3] Account Info.\n";
        std::cout << "\t\t\t\t\t\t[4] Exit.\n";
        std::cout << "\t\t\t\t\t===========================================\n";
        PerfromCustomersMenueOption((Customer::enCustomersMenu)ReadCustomersMenuOption());
    }
};

