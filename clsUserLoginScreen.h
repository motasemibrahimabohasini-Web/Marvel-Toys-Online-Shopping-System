#pragma once
#include <iomanip>
#include <string>
#include "clsUserMenuScreen.h"

class clsUserLoginScreen : protected clsScreen
{

private :
    static void _ShowUserMenuScreen()
    {
        clsUserMenuScreen::ShowUsersMenuScreen();
    }
    static User LoginUser() {

        string Username;
        cout << "\t\t\t\t\tUsername : ";
        getline(cin >> ws, Username);

        while (Username.length() < 5)
        {

            cout << "\n\t\t\t\t\tInvalid input Username should cintain 5 characters at least!  \n";
            cout << "\t\t\t\t\tUsername : ";
            getline(cin >> ws, Username);

        }
        string Password;
        cout << "\t\t\t\t\tPassword : ";
        cin >> Password;

        while (Password.length() < 5)
        {

            cout << "\n\t\t\t\t\tInvalid input Password should cintain 5 characters at least!  \n";
            cout << "\t\t\t\t\tPassword : ";
            cin >> Password;

        }

        return User::FindUserByUsernameandPassword(Username, Password);

    }

public : 
    static void ShowLoginUserScreen()
    {
        _DrawScreenHeader("Login User Screen");
        int counter = 5;
        if (clsGlobal::CurrentUser.UserID == 0)
        {
            do
            {

                clsGlobal::CurrentUser = LoginUser();
                counter--;
                if (counter > 0 && clsGlobal::CurrentUser.UserID == 0)
                {
                    cout << "\t\t\t\t\tInvalid Username or Password :  \n";
                    cout << "\t\t\t\t\tYou have " + to_string(counter) + " attempts left....\n" << endl;
                }
                if (counter == 0)
                {

                    cout << "\t\t\t\t\tYou have bein trying for 5 times Contact Your admin." << endl;
                    return;

                }


            } while (clsGlobal::CurrentUser.UserID == 0);
            _ShowUserMenuScreen();
        }
        else {
            _ShowUserMenuScreen();
        }

    }
};

