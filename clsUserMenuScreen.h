#pragma once
#include "clsManageProductsMenuScreen.h"
#include "clsManageOrdersMenuScreen.h"
#include "clsLoginScreen.h"
#include "clsAdminMenuScreen.h"

class clsUserMenuScreen : protected clsScreen
{
    
private :
    enum _enUserMenuOption {
        ProductsMenu = 1, OrdersMenu = 2, AdminMenu = 3, enUserMenuOptionExist = 4
    };
    static short _ReadUserMenuOption() {
        short Choice = 0;
        cout << "\t\t\t\t\tChoose the User Menu Option [1 to 4]: ";
        cin >> Choice;
        while ((Choice > 4 || Choice < 1) || cin.fail())
        {
            cout << "\t\t\t\t\tInvalid input , Choose The User Menu Option [1 to 4]: ";
            cin.clear(); // reset error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> Choice;
        }
        return Choice;
    }
    static void PerformUserMenuOption(_enUserMenuOption UserMenuOption) {
        switch (UserMenuOption) {
        case ProductsMenu:
            system("cls");
            _ShowProductMenuScreen();
            _GoBackToUserMenuScreen();

            break;
        case OrdersMenu:
            system("cls");
            _ShowManageOrdersMenuScreen();
             _GoBackToUserMenuScreen();

            break;
        case AdminMenu:
            system("cls");
            _ShowAdminMenuScreen();
            _GoBackToUserMenuScreen();
            break;
        case _enUserMenuOption::enUserMenuOptionExist:
            system("cls");
            

        }
       
    }

    static void _GoBackToUserMenuScreen() {

        ShowUsersMenuScreen();
    }

    static void _ShowProductMenuScreen()
    {
        clsProductMenuScreen::ShowManageProductMenuScreen();
    }
    static void _ShowManageOrdersMenuScreen()
    {
        clsManageOrdersMenuScreen::ShowManageOrdersMenu();
    }
    static void _ShowAdminMenuScreen()
    {
        clsAdminMenuScreen::ShowAdminMenu();
    }
    
    

public : 
    static  void ShowUsersMenuScreen() {

        system("cls");
        _DrawScreenHeader("Users Menu Screen");
        cout << "\t\t\t\t\t===========================================\n";
        cout << "\t\t\t\t\t\tUsers Menu \n";
        cout << "\t\t\t\t\t===========================================\n";
        cout << "\t\t\t\t\t\t[1] Manage Products.\n";
        cout << "\t\t\t\t\t\t[2] Manage Orders.\n";
        cout << "\t\t\t\t\t\t[3] Admin Menu (Admin Only).\n";
        cout << "\t\t\t\t\t\t[4] Exit.\n";
        cout << "\t\t\t\t\t===========================================\n";





        PerformUserMenuOption((_enUserMenuOption)_ReadUserMenuOption());
    }
};

