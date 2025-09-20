#pragma once
#include <iomanip>
#include <string>
#include "Users.h";
#include "clsScreen.h"
#include "clsGlobal.h"
class clsUpdateUserScreen : protected clsScreen
{
private :
    static User ReadUpdateUser()
    {
        User User;
        cout << "\t\t\t\t\tEnter Username? ";

        // Usage of std::ws will extract allthe whitespace character
        getline(cin >> ws, User.UserName);


        cout << "\t\t\t\t\tEnter Password? ";
        getline(cin, User.Password);
        while (User.Password.length() < 4)
        {
            cout << "\t\t\t\t\tPassword must be at least 4 characters long. Please enter again: ";
            getline(cin, User.Password);
        }

        cout << "\t\t\t\t\tIs  Admin? (1 for Yes, 0 for No): ";
        cin >> User.Permissions;
        while (User.Permissions != 0 && User.Permissions != 1)
        {
            cout << "\t\t\t\t\tInvalid input. Please enter 1 for Yes or 0 for No: ";
            cin >> User.Permissions;
        }
        return User;
    }
   
   static void UpdateUsers()
    {
        int UserID =clsGlobal::ReadID("User ID");
        User User = User::FindUserByUserID(UserID);
        {
            char Answer;
            User.PrintUserCard();
            if (User.UserID != 0)
            {
                cout << "\n\n\t\t\t\t\tAre you sure you want update this User? y/n ? ";
                cin >> Answer;
                if (Answer == 'y' || Answer == 'Y')
                {
                    User = ReadUpdateUser();
                    User.UserID = UserID;
                    if (User.UpdateUser())
                    {
                        cout << "\n\n\t\t\t\t\tUser Updated Successfully.";
                    }
                    else {
                        cout << "\n\n\t\t\t\t\tError: User could not be updated.";
                    }



                }
            }
            else {
                cout << "\n\t\t\t\t\tUser with User ID (" << UserID << ") is Not Found!";
            }

        }

    }
public :
    static void ShowUpdateUserScreen()
    {
        _DrawScreenHeader("Update User Info Screen");
        cout << "\n\t\t\t\t\t-----------------------------------\n";
        cout << "\t\t\t\t\t\tUpdate User Info ";
        cout << "\n\t\t\t\t\t-----------------------------------\n";
        UpdateUsers();
    }
};

