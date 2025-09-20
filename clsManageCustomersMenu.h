#pragma once
#include <iomanip>
#include <string>
#include "Users.h";
#include "clsScreen.h"
#include "clsGlobal.h"
#include "clsAllCustomersScreen.h"
#include "clsAddNewCustomerScreen.h"
#include "clsUpdateCustomerScreen.h"
#include "clsFindCustomerScreen.h"
#include "clsDeleteCustomerScreen.h"
class clsManageCustomersMenu : protected clsScreen
{
private:
    static enum enManageCustomersMenu
    {
        ShowCustomersList = 1, enAddNewCustomer = 2, enUpdateCustomer = 3, enFindCustomerInfo = 4, enDeleteCustomer = 5, enManageCustomersMenuExist = 6

    };
    static void _GoBackToManageCustomersMenu() {
        std::cout << "\n\nPress any key to go back to Main Menu...";
        system("pause>0");
        ShowManageCustomersMenu();
    }
    static  void _PerfromManageCustomersMenueOption(enManageCustomersMenu CustomersMenuOption)
    {
        switch (CustomersMenuOption)
        {

        case enManageCustomersMenu::ShowCustomersList:
            system("cls");
           clsAllCustomersScreen::ShowAllCustomersScreen();
            _GoBackToManageCustomersMenu();
            break;

        case enManageCustomersMenu::enAddNewCustomer:
            system("cls");
            clsAddNewCustomerScreen::ShowAddNewCustomersScreen();
            _GoBackToManageCustomersMenu();
            break;

        case enManageCustomersMenu::enUpdateCustomer:
            system("cls");
            clsUpdateCustomerScreen::ShowUpdateCustomerScreen();
            _GoBackToManageCustomersMenu();
            break;

        case enManageCustomersMenu::enFindCustomerInfo:
            system("cls");
           clsFindCustomerScreen::ShowFindCustomerScreen();
            _GoBackToManageCustomersMenu();
            break;

        case    enManageCustomersMenu::enDeleteCustomer:
            system("cls");
           clsDeleteCustomerScreen::ShowDeleteCustomerScreen();
            _GoBackToManageCustomersMenu();
            break;
        case enManageCustomersMenu::enManageCustomersMenuExist:
            system("cls");
            
        }
       

    }
    static short _ReadManageCustomersMenuOption()
    {
        short Choice = 0;
        cout << "\t\t\t\t\tChoose the Manage Customers Menu Option [1 to 6]: ";
        cin >> Choice;
        while ((Choice > 6 || Choice < 1) || cin.fail())
        {
            cout << "\t\t\t\t\tInvalid input , Choose the Manage Customers Menu Option [1 to 6]: ";
            cin.clear(); // reset error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> Choice;
        }

        return Choice;
    }
  
public:
    static  void ShowManageCustomersMenu()
    {
        system("cls");
       
        _DrawScreenHeader("Manage Customers Menu Screen");
        std::cout << "\t\t\t\t\t===========================================\n";
        std::cout << "\t\t\t\t\t\tManage Customers Menue \n";
        std::cout << "\t\t\t\t\t===========================================\n";
        std::cout << "\t\t\t\t\t\t[1] Show Customers List.\n";
        std::cout << "\t\t\t\t\t\t[2] Add New Customer.\n";
        std::cout << "\t\t\t\t\t\t[3] Update Customer Info.\n";
        std::cout << "\t\t\t\t\t\t[4] Find Customer.\n";
        std::cout << "\t\t\t\t\t\t[5] Delete Customer.\n";
        std::cout << "\t\t\t\t\t\t[6] Exit.\n";
        std::cout << "\t\t\t\t\t===========================================\n";
        _PerfromManageCustomersMenueOption((enManageCustomersMenu)_ReadManageCustomersMenuOption());
    }

};

