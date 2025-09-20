#include <string>
#include "Users.h";
#include "clsScreen.h"
#include "clsGlobal.h"
class clsUpdateCustomerScreen : protected clsScreen
{
private :
    static Customer ReadUpdateCustomer()
    {
        Customer Customer;
        cout << "\t\t\t\t\tEnter Customer Name? ";

        // Usage of std::ws will extract allthe whitespace character
        getline(cin >> ws, Customer.CustomerName);


        cout << "\t\t\t\t\tEnter Address? ";
        getline(cin, Customer.CustomerAddress);
        while (Customer.CustomerAddress.length() < 4)
        {
            cout << "\t\t\t\t\tAdress must be at least 4 characters long. Please enter again: ";
            getline(cin, Customer.CustomerAddress);
        }

        cout << "\t\t\t\t\tEnter Contact :  ";
        cin >> Customer.CustomerContact;
        while (cin.fail())
        {
            cout << "\t\t\t\t\tInvalid Input! ,Enter Contact :  ";
            cin.clear(); // reset error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> Customer.CustomerContact;
        }
      
        cout << "\n\t\t\t\t\tEnter password :  ";
        getline(cin>>ws, Customer.Password);
        while (Customer.Password.length() < 4)
        {
            cout << "\t\t\t\t\tpassword must be at least 4 characters long. Please enter again: ";
            getline(cin, Customer.Password);
        }
        string Password = "";
        cout << "\t\t\t\t\tConfirm password :  ";
        getline(cin>> ws, Password);
        while (Password != Customer.Password)
        {
            cout << "\t\t\t\t\tWrong password confirm ! Confirm Password :  ";
            getline(cin, Password);
        }
      
        return Customer;
    }
   static void UpdateCustomers()
    {
        int CustomerID =clsGlobal::ReadID("Customer ID");
        Customer Customer = Customer::FindCustomerByCustomerID(CustomerID);
        if (Customer.CustomerID != 0)
        {
            char Answer;

            Customer.PrintCustomerCard();
            cout << "\n\n\t\t\t\t\tAre you sure you want update this client? y/n ? ";
            cin >> Answer;
            if (Answer == 'y' || Answer == 'Y')
            {
                Customer = ReadUpdateCustomer();
                Customer.CustomerID = CustomerID;
                if (Customer.UpdateCustomer())
                {
                    cout << "\n\n\t\t\t\t\tCustomer Updated Successfully.";
                }
                else {
                    cout << "\n\n\t\t\t\t\tError: Customer could not be updated.";
                }



            }
        }
        else
        {
            cout << "\n\t\t\t\t\tCustomer with Customer ID (" << CustomerID << ") is Not Found!";
        }


    }
public :
   static void ShowUpdateCustomerScreen()
    {
        _DrawScreenHeader("Update Customer Info Screen");
        cout << "\n\t\t\t\t\t-----------------------------------\n";
        cout << "\t\t\t\t\t\tUpdate Customer Info";
        cout << "\n\t\t\t\t\t-----------------------------------\n";
        UpdateCustomers();
    }
   
};

