#pragma once
#include <iomanip>
#include <iostream>
using namespace std;
class clsAccessDeniedScreen
{
public :
   static void ShowAccessDenidScreen()
    {
        cout << "\n\t\t\t\t\t-----------------------------------\n";
        cout << "\t\t\t\t\t\tAccess Denied ";
        cout << "\n\t\t\t\t\t-----------------------------------\n";
        std::cout << "\n\nPress any key to go back to Main Menu...";
        system("pause>0");
    }
};

