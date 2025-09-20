#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include "Orders.h"
#include "CommonFunctions.h"


using namespace std;
const string UsersFileName = "Users.txt";
class User {
private:
    static vector<User> vUsers;
    string filename = "Users.txt";

public:


    int UserID;
    string UserName;
    string Password;
    int Permissions;
    bool _MarkForDelete;



    User(int userId = 0, const string& userName = "", const string& password = "", int permissions = 0, bool  MarkForDelete = false)
        : UserID(userId), UserName(userName), Password(password), Permissions(permissions), _MarkForDelete(MarkForDelete) {
    }

    void AddNewUser()
    {
        CommonFunctions::AddDataLineToFile(UsersFileName, ConvertUserRecordToLine(*this));
    }
    bool DeleteUser()
    {

        MarkUserForDeleteByUserName(User::UserID, vUsers);
        SaveUsersDataToFile(UsersFileName, vUsers);
        //Refresh Users 
        vUsers = LoadUsersDataFromFile(UsersFileName);

        return true;
    }

    bool UpdateUser()
    {

        vUsers = LoadUsersDataFromFile(UsersFileName);
        char Answer = 'n';

        for (User& C : vUsers)
        {
            if (C.UserID == UserID)
            {
                C = *this;
                break;
            }
        }

        SaveUsersDataToFile(UsersFileName, vUsers);

       
        return true;
    }
    static string ConvertUserRecordToLine(User User, string Seperator = "#//#")
    {

        string stUserRecord = "";
        stUserRecord += to_string(User.UserID) + Seperator;
        stUserRecord += User.UserName + Seperator;
        stUserRecord += User.Password + Seperator;
        stUserRecord +=to_string( User.Permissions )+ Seperator;
        return stUserRecord;
    }
    static bool UserExistsByUserID(int UserID, string FileName)
    {

        vector <User> vUsers;
        fstream MyFile;
        MyFile.open(FileName, ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            User User;

            while (getline(MyFile, Line))
            {
                User = ConvertUserLinetoRecord(Line);
                if (User.UserID == UserID)
                {
                    MyFile.close();
                    return true;
                }
                vUsers.push_back(User);
            }

            MyFile.close();

        }
        return false;
    }
    static bool UserExistsByUsername(string Username)
    {

        vector <User> vUsers;
        fstream MyFile;
        MyFile.open(UsersFileName, ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            User User;

            while (getline(MyFile, Line))
            {
                User = ConvertUserLinetoRecord(Line);
                if (User.UserName == Username)
                {
                    MyFile.close();
                    return true;
                }
                vUsers.push_back(User);
            }

            MyFile.close();

        }
        return false;
    }

    void PrintUserCard()
    {
        cout << "\n\t\t\t\t\tThe following are the User details:\n";
        cout << "--\t\t\t\t\t---------------------------------";
        cout << "\n\t\t\t\t\tUser ID : " << UserID;
        cout << "\n\t\t\t\t\tUsername     : " << UserName;
        cout << "\n\t\t\t\t\tPassword         : " << Password;
        cout << "\n\t\t\t\t\tPermissions        : " << Permissions;
        cout << "\n\t\t\t\t\t-----------------------------------\n";
    }
    static User FindUserByUserID(int UserID)
    {

        vUsers = LoadUsersDataFromFile(UsersFileName);

        for (User C : vUsers)
        {

            if (C.UserID == UserID)
            {

                return C;
            }

        }
        return false;
    }
    static User FindUserByUsernameandPassword(string Username,string Password)
    {

        vUsers = LoadUsersDataFromFile(UsersFileName);

        for (User C : vUsers)
        {

            if ((C.UserName == Username )&&( C.Password == Password))
            {

                return C;
            }

        }
        return User();
    }
    vector <User> SaveUsersDataToFile(string FileName, vector <User> vUsers)
    {
        fstream MyFile;
        MyFile.open(FileName, ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {
            for (User C : vUsers)
            {

                if (C._MarkForDelete == false)
                {
                    //we only write records that are not marked for delete.  
                    DataLine = ConvertUserRecordToLine(C);
                    MyFile << DataLine << endl;
                }

            }

            MyFile.close();
        }

        return vUsers;
    }
    bool MarkUserForDeleteByUserName(int UserID, vector <User>& vUsers)
    {

        for (User& C : vUsers)
        {

            if (C.UserID == UserID)
            {
                C._MarkForDelete = true;
                return true;
            }

        }

        return false;
    }
    static User ConvertUserLinetoRecord(string Line, string Seperator = "#//#")
    {
        User User;
        vector<string> VUserData;
        VUserData = CommonFunctions::SplitString(Line, Seperator);

        User.UserID = stoi(VUserData[0]);
        User.UserName = VUserData[1];
        User.Password = VUserData[2];
        User.Permissions = stoi(VUserData[3]);

        return User;
    }
    static vector <User> LoadUsersDataFromFile(string FileName)
    {
        vector <User> vUsers;
        fstream MyFile;
        MyFile.open(FileName, ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            User User;

            while (getline(MyFile, Line))
            {
                User = ConvertUserLinetoRecord(Line);
                vUsers.push_back(User);
            }
            MyFile.close();
        }
        return vUsers;
    }

};












