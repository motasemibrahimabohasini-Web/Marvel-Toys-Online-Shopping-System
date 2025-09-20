#pragma once
#include "clsAddNewCartScreen.h"

class clsAddNewOrderScreen : protected clsScreen
{
private :
    static void AddNewOrders()
    {
        clsAddNewcartScreen::ShowAddNewCartScreen();

    }
public :
	static void ShowAddNewOrdersScreen()
    {
        _DrawScreenHeader("Add New Orders Screen");
        cout << "\n\t\t\t\t\t-----------------------------------\n";
        cout << "\t\t\t\t\t\tAdd New Orders ";
        cout << "\n\t\t\t\t\t-----------------------------------\n";

        AddNewOrders();
    }
};

