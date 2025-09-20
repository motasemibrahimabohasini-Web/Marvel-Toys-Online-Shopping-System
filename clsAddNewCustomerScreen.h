#pragma once
#include <iomanip>
#include <string>
#include "Users.h";
#include "clsScreen.h"
#include "clsGlobal.h"
class clsAddNewCustomerScreen : protected clsScreen
{
private : 
    static Customer ReadNewCustomer()
    {
        Customer Customer;
        cout << "\t\t\t\t\tEnter Customer Name? ";

        // Usage of std::ws will extract allthe whitespace character
        getline(cin >> ws, Customer.CustomerName);

        while (Customer.CustomerName.length() < 5)
        {
            cout << "\n\t\t\t\t\tCustomer name at least should have 5 characters,Enter Valid Name :  ";
            getline(cin >> ws, Customer.CustomerName);
        }
        while (Customer::CustomerExistsByCustomerName(Customer.CustomerName))
        {
            cout << "\n\t\t\t\t\tCustomer with [" << Customer.CustomerName << "] already Used, Enter another Name :  ";
            getline(cin >> ws, Customer.CustomerName);
        }


        cout << "\t\t\t\t\tEnter Address :  ";
        getline(cin, Customer.CustomerAddress);
        while (Customer.CustomerAddress.length() < 4)
        {
            cout << "\t\t\t\t\tAddress must be at least 4 characters long. Please enter again: ";
            getline(cin, Customer.CustomerAddress);
        }

        cout << "\t\t\t\t\tEnter password :  ";
        getline(cin, Customer.Password);
        while (Customer.Password.length() < 4)
        {
            cout << "\t\t\t\t\tpassword must be at least 4 characters long. Please enter again: ";
            getline(cin, Customer.Password);
        }
        string Password = "";
        cout << "\t\t\t\t\tConfirm password :  ";
        getline(cin, Password);
        while (Password != Customer.Password)
        {
            cout << "\t\t\t\t\tWrong password confirm ! Confirm Password :  ";
            getline(cin, Password);
        }


        Customer.CustomerID = CommonFunctions::GenerateNextID(CustomersFileName);
        cout << "\t\t\t\t\tEnter Contact :  ";
        cin >> Customer.CustomerContact;
        while (cin.fail())
        {
            cout << "\t\t\t\t\tInvalid Input! ,Enter Contact :  ";
            cin.clear(); // reset error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> Customer.CustomerContact;
        }


        return Customer;
    }
    static void AddNewCustomers()
    {
        char AddMore = 'Y';
        do
        {
            //system("cls");
            cout << "\t\t\t\t\tAdding New Customer:\n\n";
            Customer Customer = ReadNewCustomer();



            Customer.AddNewCustomer();
            cout << "\n\t\t\t\t\tCustomer Added Successfully, do you want to add more Customers? Y/N? ";
            cin >> AddMore;

        } while (toupper(AddMore) == 'Y');

    }
public :

   static void ShowAddNewCustomersScreen()
    {
        _DrawScreenHeader("Add New Customers Screen");
        cout << "\n\t\t\t\t\t-----------------------------------\n";
        cout << "\t\t\t\t\t\tAdd New Customers ";
        cout << "\n\t\t\t\t\t-----------------------------------\n";

        AddNewCustomers();
    }
};

