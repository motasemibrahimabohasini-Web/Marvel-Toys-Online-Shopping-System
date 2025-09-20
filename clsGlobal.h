#pragma once
#include <iomanip>
#include <iostream>
#include "Users.h"
#include "Customers.h"
#include "Orders.h"
class clsGlobal
{
public:
    static User CurrentUser;
    static Customer CurrentCustomer;
    static Order CurrentOrder;
    static int ReadID(string IDName)
    {
        int Choice = 0;
        cout << "\t\t\t\t\tPlease Enter " + IDName + ": ";
        cin >> Choice;
        while (cin.fail())
        {
            cout << "\t\t\t\t\tInvalid input , Please Enter " + IDName + ":";
            cin.clear(); // reset error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> Choice;
        }
        return Choice;

    }

};
