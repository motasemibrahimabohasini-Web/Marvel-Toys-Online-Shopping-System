#pragma once
#include <iomanip>
#include <string>
#include "Users.h";
#include "clsScreen.h"
#include "clsGlobal.h"
#include"clsAllUsersScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsFindUserScreen.h";
class clsManageUsersMenuScreen : protected clsScreen
{
private:
    enum _enManageUsersMenuOption {
        ShowUsersList = 1, AddNewUser = 2, UpdateUser = 3,
        FindUserInfo = 4, DeleteUser = 5, enManageUsersMenuOptionExist = 6
    };
    static short _ReadManageUsersMenuOption() {
        short Choice = 0;
        cout << "\t\t\t\t\tChoose the Manage Users Menu Option [1 to 6]: ";
        cin >> Choice;
        while ((Choice > 6 || Choice < 1) || cin.fail())
        {
            cout << "\t\t\t\t\tInvalid input , Choose the Manage Users Menu Option [1 to 6]: ";
            cin.clear(); // reset error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> Choice;
        }

        return Choice;
    }
    static void _ShowAllUsersScreen()
    {
        clsAllUsersScreen::ShowAllUsersScreen();
    }
    static void  _ShowAddNewUsersScreen()
    {

        clsAddNewUserScreen::ShowAddNewUsersScreen();
    }
    static void _ShowUpdateUserScreen()
    {
        clsUpdateUserScreen::ShowUpdateUserScreen();
    }
    static void _ShowFindUserScreen()
    {
        clsFindUserScreen::ShowFindUserScreen();
    }
    static void _ShowDeleteUserScreen()
    {
        clsDeleteUserScreen::ShowDeleteUserScreen();
    }

    static void _GoBackToManageUsersMenu() {
        std::cout << "\n\nPress any key to go back to Main Menu...";
        system("pause>0");
        ShowManageUsersMenu();
    }
    static void _PerformManageUsersMenuOption(_enManageUsersMenuOption ManageUsersMenuOption)
    {
        switch (ManageUsersMenuOption) {
        case ShowUsersList:
            system("cls");
            _ShowAllUsersScreen();
            _GoBackToManageUsersMenu();

            break;
        case AddNewUser:
            system("cls");
            _ShowAddNewUsersScreen();
            _GoBackToManageUsersMenu();
            break;
        case UpdateUser:
            system("cls");
            _ShowUpdateUserScreen();
            _GoBackToManageUsersMenu();
            break;
        case FindUserInfo:
            _ShowFindUserScreen();
            _GoBackToManageUsersMenu();
            break;

        case DeleteUser:
            system("cls");
            _ShowDeleteUserScreen();
            _GoBackToManageUsersMenu();
            break;
        case enManageUsersMenuOptionExist:
            
            break;
        }
    }
    



public:
    static void ShowManageUsersMenu() {
       
        system("cls");
        _DrawScreenHeader("Manage Users Menu Screen");
        cout << "\t\t\t\t\t===========================================\n";
        cout << "\t\t\t\t\t\tManage Users Menu \n";
        cout << "\t\t\t\t\t===========================================\n";
        cout << "\t\t\t\t\t\t[1] Show Users List.\n";
        cout << "\t\t\t\t\t\t[2] Add New User.\n";
        cout << "\t\t\t\t\t\t[3] Update User Info.\n";
        cout << "\t\t\t\t\t\t[4] Find User.\n";
        cout << "\t\t\t\t\t\t[5] Delete User.\n";
        cout << "\t\t\t\t\t\t[6] Exit.\n";
        cout << "\t\t\t\t\t===========================================\n";
        _PerformManageUsersMenuOption((_enManageUsersMenuOption)_ReadManageUsersMenuOption());
    }
};

