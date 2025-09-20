#pragma once
#include <iomanip>
#include <string>

#include "clsAddNewCartScreen.h"
#include "clsAddNewOrderScreen.h"
#include "clsUpdateOrderScreen.h"
#include "clsDeleteOrderScreen.h"
#include "clsFindOrderScreen.h"
#include "clsAllOrdersScreen.h"
class clsManageOrdersMenuScreen : protected clsScreen
{
private:
    enum _enManageOrdersMenuOption {
        ShowOrdersList = 1, AddNewOrder = 2, UpdateOrder = 3,
        FindOrderInfo = 4, DeleteOrder = 5, enManageOrdersMenuOptionExist = 6
    };
    static short _ReadManageOrdersMenuOption() {
        short Choice = 0;
        cout << "  Choose the Manage Orders Menu Option [1 to 6]: ";
        cin >> Choice;
        while ((Choice > 6 || Choice < 1) || cin.fail())
        {
            cout << " Invalid input , Choose the Manage Orders Menu Option [1 to 6]: ";
            cin.clear(); // reset error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> Choice;
        }

        return Choice;
    }
    static void _ShowAllOrdersScreen()
    {
        clsAllOrdersScreen::ShowAllOrdersScreen();
    }
   static void  _ShowAddNewOrdersScreen()
    {

       clsAddNewOrderScreen::ShowAddNewOrdersScreen();
    }
   static void _ShowUpdateOrderScreen()
   {
       clsUpdateOrderScreen::ShowUpdateOrderScreen();
   }
   static void _ShowFindOrderScreen()
   {
       clsFindOrderScreen::ShowFindOrderScreen();
   }
   static void _ShowDeleteOrderScreen()
   {
       clsDeleteOrderScreen::ShowDeleteOrderScreen();
   }

    static void _GoBackToManageOrdersMenu() {
        std::cout << "\n\nPress any key to go back to Main Menu...";
        system("pause>0");
        ShowManageOrdersMenu();
    }
    static void _PerformManageOrdersMenuOption(_enManageOrdersMenuOption ManageOrdersMenuOption) {
        switch (ManageOrdersMenuOption) {
        case ShowOrdersList:
            system("cls");
            _ShowAllOrdersScreen();
            _GoBackToManageOrdersMenu();

            break;
        case AddNewOrder:
            system("cls");
            _ShowAddNewOrdersScreen();
            _GoBackToManageOrdersMenu();
            break;
        case UpdateOrder:
            system("cls");
            _ShowUpdateOrderScreen();
            _GoBackToManageOrdersMenu();
            break;
        case FindOrderInfo:
            _ShowFindOrderScreen();
            _GoBackToManageOrdersMenu();
            break;

        case DeleteOrder:
            system("cls");
            _ShowDeleteOrderScreen();
            _GoBackToManageOrdersMenu();
            break;
        case enManageOrdersMenuOptionExist:
            system("cls");
           
        }
        system("cls");
        
    }
public :
    static void ShowManageOrdersMenu() {
        system("cls");
        _DrawScreenHeader("Manage Orders Menu Screen");
        cout << "\t\t\t\t\t===========================================\n";
        cout << "\t\t\t\t\t\tManage Orders Menu \n";
        cout << "\t\t\t\t\t===========================================\n";
        cout << "\t\t\t\t\t\t[1] Show Orders List.\n";
        cout << "\t\t\t\t\t\t[2] Add New Order.\n";
        cout << "\t\t\t\t\t\t[3] Update Order Info.\n";
        cout << "\t\t\t\t\t\t[4] Find Order.\n";
        cout << "\t\t\t\t\t\t[5] Delete Order.\n";
        cout << "\t\t\t\t\t\t[6] Exit.\n";
        cout << "\t\t\t\t\t===========================================\n";
        _PerformManageOrdersMenuOption((_enManageOrdersMenuOption)_ReadManageOrdersMenuOption());
    }
};

