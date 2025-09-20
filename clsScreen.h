#pragma once
#include <iostream>
#include "clsGlobal.h"


using namespace std;

class clsScreen
{
protected:
    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
      
        if (clsGlobal::CurrentCustomer.CustomerID == 0 && clsGlobal::CurrentUser.UserID != 0)
        {
            cout << "\t\t\t\t\tCurrent User : "+clsGlobal::CurrentUser.UserName;
        }
        if (clsGlobal::CurrentUser.UserID == 0 && clsGlobal::CurrentCustomer.CustomerID != 0)
        {
            cout << "\t\t\t\t\tCurrent Customer : " + clsGlobal::CurrentCustomer.CustomerName;
        }

        
    
        cout << "\n\t\t\t\t\t___________________________________________";
        cout << "\n\n\t\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t___________________________________________\n\n";
    }


};