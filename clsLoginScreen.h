#pragma once
#include "clsUserLoginScreen.h"
#include "clsCustoemrsLoginScreen.h"
using namespace std;
class clsLoginScreen : protected clsScreen
{
private:
    enum enLoginOption {
        enLoginUserScreen = 1,
        enLginCustomersScreen = 2,
        enShowEndScreen = 3
    };
   static short _ReadLoginOption() {
        short Choice = 0;
        cout << "\t\t\t\t\tChoose the Login Option [1 or 2]: ";
        cin >> Choice;
        while ((Choice > 3 || Choice < 1) || cin.fail())
        {
            cout << "\t\t\t\t\tInvalid input , Choose the Login Option [1 or 2]: ";
            cin.clear(); // reset error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> Choice;
        }

        return Choice;
    }
    static void _PerformLoginMenuOption(enLoginOption MainMenuOption) {

        switch (MainMenuOption) {
        case enLoginOption::enLoginUserScreen:
            system("cls");
            clsGlobal::CurrentCustomer = Customer();
            _ShowLoginUserScreen();
            _GoBackToMainMenu();
            break;

        case enLoginOption::enLginCustomersScreen:
            system("cls");
            clsGlobal::CurrentUser = User();
            _ShowLoginCustomerScreen();
            _GoBackToMainMenu();
            break;
        case enLoginOption::enShowEndScreen:
        {
            system("cls");
            _ShowEndScreen();

        }

        }
        system("cls");
        _ShowEndScreen();
    }
    static void _GoBackToMainMenu() {
  
        ShowMainMenu();
    }
   static void _ShowEndScreen()
    {
        cout << "\n\t\t\t\t\t-----------------------------------\n";
        cout << "\t\t\t\t\t\tProgram Ends :-)";
        cout << "\n\t\t\t\t\t-----------------------------------\n";
    }

   static void _ShowLoginUserScreen()
   {
       clsUserLoginScreen::ShowLoginUserScreen();

   }
   static void  _ShowLoginCustomerScreen()
       {
       clsCustomerLoginScreen::ShowLoginCustomerScreen();
   }
public : 

    static void ShowMainMenu() {
        system("cls");
        _DrawScreenHeader("Main Menu");
        std::cout << "\t\t\t\t\t===========================================\n";
        std::cout << "\t\t\t\t\t\tLogin Options Menu\n";
        std::cout << "\t\t\t\t\t===========================================\n";
        std::cout << "\t\t\t\t\t\t[1] Log in as User.\n";
        std::cout << "\t\t\t\t\t\t[2] Log in as Customer.\n";
        std::cout << "\t\t\t\t\t\t[3] Close Program.\n";
        std::cout << "\t\t\t\t\t===========================================\n";
        _PerformLoginMenuOption(static_cast<enLoginOption>(_ReadLoginOption()));
    }
};

