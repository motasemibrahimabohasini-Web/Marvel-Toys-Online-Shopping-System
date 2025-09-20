#pragma once
#include <iomanip>
#include <string>
#include "Users.h";
#include "clsScreen.h"
#include "clsGlobal.h"
#include "clsAccessDeniedScreen.h"
#include "clsManageCustomersMenu.h"
#include "clsManageUsersMenuScreen.h"
#include "clsUserMenuScreen.h"
class clsAdminMenuScreen : protected clsScreen
{
private :
    enum enAdminMenuOption {
        enCustomersMenu = 1, enUsersMenu = 2, enAdminMenuOptionExist = 3
    };
    static short _ReadAdminMenuOption() {
        short Choice = 0;
        cout << "\t\t\t\t\tChoose the Admin Option[1 to 3]: ";
        cin >> Choice;
        while ((Choice > 3 || Choice < 1) || cin.fail())
        {
            cout << "\t\t\t\t\tInvalid input , Choose the Admin Option [1 to 3]: ";
            cin.clear(); // reset error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> Choice;
        }

        return Choice;
    }
    static void _GoBackToAdminMenu() {
   
        ShowAdminMenu();
    }
    static void _PerformAdminMenuOption(enAdminMenuOption AdminMenuOption) {
        switch (AdminMenuOption) {
        case enCustomersMenu:
            system("cls");
            clsManageCustomersMenu::ShowManageCustomersMenu();
            _GoBackToAdminMenu();


            break;
        case enUsersMenu:
            system("cls");
           clsManageUsersMenuScreen::ShowManageUsersMenu();
            _GoBackToAdminMenu();

            break;

        case enAdminMenuOptionExist:
            system("cls");
         

        }
     
        
    }
public : 
    static void ShowAdminMenu() {
        system("cls");
        if (clsGlobal::CurrentUser.Permissions != 1)
        {   
            clsAccessDeniedScreen::ShowAccessDenidScreen();

            return;
        }


        _DrawScreenHeader("Admin Menu Screen");
        cout << "\t\t\t\t\t===========================================\n";
        cout << "\t\t\t\t\t\tAdmin Menu \n";
        cout << "\t\t\t\t\t===========================================\n";
        cout << "\t\t\t\t\t\t[1] Manage Customers.\n";
        cout << "\t\t\t\t\t\t[2] Manage Users.\n";
        cout << "\t\t\t\t\t\t[3] Exit.\n";
        cout << "\t\t\t\t\t===========================================\n";
        _PerformAdminMenuOption((enAdminMenuOption)_ReadAdminMenuOption());
    }
};

