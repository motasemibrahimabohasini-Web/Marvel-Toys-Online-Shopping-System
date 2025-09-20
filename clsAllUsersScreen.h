#pragma once
#include <iomanip>
#include <string>
#include "Users.h";
#include "clsScreen.h"
#include "clsGlobal.h"
class clsAllUsersScreen : protected clsScreen
{
private :
    static void PrintUserRecordLine(User User)
    {
        cout << "| " << setw(15) << left << User.UserID;
        cout << "| " << setw(15) << left << User.UserName;
        cout << "| " << setw(20) << left << User.Password;
        cout << "| " << setw(12) << left << User.Permissions;

    }
public : 
    static void ShowAllUsersScreen()
    {
        vector <User> vUsers = User::LoadUsersDataFromFile(UsersFileName);
     
        cout << "\n\t\t\t\t\tUser List (" << vUsers.size() << ") User(s).";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << "| " << left << setw(15) << "User ID";
        cout << "| " << left << setw(15) << "Username";
        cout << "| " << left << setw(20) << "Password";
        cout << "| " << left << setw(12) << "Permissions";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vUsers.size() == 0)
            cout << "\t\t\t\tNo Users Available In the System!";
        else

            for (User User : vUsers)
            {

                PrintUserRecordLine(User);
                cout << endl;
            }

        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;
    }
};

