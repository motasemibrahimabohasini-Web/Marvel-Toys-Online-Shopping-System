#pragma once
#include <iomanip>
#include <string>
#include "Users.h";
#include "clsScreen.h"
#include "clsGlobal.h"
class clsDeleteUserScreen : protected clsScreen
{
private : 
   static void DeleteUsers()
    {
        int UserID =clsGlobal::ReadID("User ID");
        User User = User::FindUserByUserID(UserID);
        if (User.UserID != 0)
        {

            User.PrintUserCard();
            char Answer = 'n';
            cout << "\n\n\t\t\t\t\tAre you sure you want delete this User? y/n ? ";
            cin >> Answer;
            if (Answer == 'y' || Answer == 'Y')
            {
                if (User.DeleteUser())
                {
                    cout << "\n\n\t\t\t\t\tUser Deleted Successfully.";
                }
                else {
                    cout << "\n\n\t\t\t\t\tError: User could not be deleted.";
                }
            }
        }
        else
        {
            cout << "\n\t\t\t\t\tUser with User ID (" << UserID << ") is Not Found!";
        }

    }
public : 
    static void ShowDeleteUserScreen()
    {
        _DrawScreenHeader("Delete User Screen");
        cout << "\n\t\t\t\t\t-----------------------------------\n";
        cout << "\t\t\t\t\t\tDelete User";
        cout << "\n\t\t\t\t\t-----------------------------------\n";

        DeleteUsers();

    }
};

