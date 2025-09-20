#pragma once
#include <iomanip>
#include <string>
#include "Users.h";
#include "clsScreen.h"
#include "clsGlobal.h"
class clsFindUserScreen : protected clsScreen
{
private:
    static void FindUser()
    {
        User User = User::FindUserByUserID(clsGlobal::ReadID("User ID"));

        if (User.UserID != 0)
        {
            User.PrintUserCard();
        }
        else
        {
            cout << "\n\t\t\t\t\tUser with User ID (" << User.UserID << ") is Not Found!";
        }
    }
public :
   static void ShowFindUserScreen()
    {
        _DrawScreenHeader("Find User Screen");
        cout << "\n\t\t\t\t\t-----------------------------------\n";
        cout << "\t\t\t\t\t\tFind User";
        cout << "\n\t\t\t\t\t-----------------------------------\n";

        FindUser();
    }
};

