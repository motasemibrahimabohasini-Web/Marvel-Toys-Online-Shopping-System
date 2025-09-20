#pragma once
#include <iomanip>
#include <string>
#include "Users.h";
#include "clsScreen.h"
#include "clsGlobal.h"
class clsAddNewUserScreen : protected clsScreen
{

private :

    static void AddNewUsers()
    {
        char AddMore = 'Y';
        do
        {
            //system("cls");
            cout << "\t\t\t\t\tAdding New User:\n\n";
            User user = ReadNewUser();



            user.AddNewUser();
            cout << "\n\t\t\t\t\tUser Added Successfully, do you want to add more Users? Y/N? ";
            cin >> AddMore;

        } while (toupper(AddMore) == 'Y');

    }
    static User ReadNewUser()
    {
        User User;
        cout << "\t\t\t\t\tEnter Username? ";

        // Usage of std::ws will extract allthe whitespace character
        getline(cin >> ws, User.UserName);

        while (User::UserExistsByUsername(User.UserName))
        {
            cout << "\n\t\t\t\t\tUser with [" << User.UserName << "] already exists, Enter another Account Number? ";
            getline(cin >> ws, User.UserName);
        }


        cout << "\t\t\t\t\tEnter Password? ";
        getline(cin, User.Password);
        while (User.Password.length() < 4)
        {
            cout << "\t\t\t\t\tPassword must be at least 4 characters long. Please enter again: ";
            getline(cin, User.Password);
        }

        User.UserID = CommonFunctions::GenerateNextID(UsersFileName);

        cout << "\t\t\t\t\tIs he Admin? (1 for Yes, 0 for No): ";
        cin >> User.Permissions;
        while (User.Permissions != 0 && User.Permissions != 1)
        {
            cout << "\t\t\t\t\tInvalid input. Please enter 1 for Yes or 0 for No: ";
            cin >> User.Permissions;
        }
        return User;
    }
public : 
    static void ShowAddNewUsersScreen()
    {
        _DrawScreenHeader("Add New Users Screen");
        cout << "\n\t\t\t\t\t-----------------------------------\n";
        cout << "\t\t\t\t\t\tAdd New Users ";
        cout << "\n\t\t\t\t\t-----------------------------------\n";

        AddNewUsers();
    }
};

