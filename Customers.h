#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "CommonFunctions.h"
#include "OrderItems.h"
#include <iomanip>


using namespace std;
const string CustomersFileName = "Customers.txt";

class Customer {
private:
    
    
public:
    
 
    static vector<Customer> vCustomers;
    static enum enCustomersMenu
    {
        enAddNewOrder = 1, enDisplayBill = 2  , enCustomerAccountInfo =3, enCustomersMenuExit = 4

    };
    int CustomerID;
    string CustomerName;
    string Password;
    string CustomerAddress;
    int CustomerContact;
    bool _MarkForDelete;

    Customer(int id = 0, const string& customername = "",string password="", const string& address = "", int contact = 0, bool markForDelete = false)
        : CustomerID(id), CustomerName(customername),Password(password), CustomerAddress(address), CustomerContact(contact), _MarkForDelete(markForDelete) {

    }












    static Customer FindCustomerByUsernameandPassword(string Username, string Password)
    {

        vCustomers = LoadCustomersDataFromFile();

        for (Customer C : vCustomers)
        {

            if ((C.CustomerName == Username) && (C.Password == Password))
            {

                return C;
            }

        }
        return Customer();
    }
    // Search customer by ID
    static bool CustomerExistsByCustomerName(string CustomerName)
    {

        vector <Customer> vCustomers;
        fstream MyFile;
        MyFile.open(CustomersFileName, ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            Customer Customer;

            while (getline(MyFile, Line))
            {
                Customer = ConvertCustomerLinetoRecord(Line);
                if (Customer.CustomerName == CustomerName)
                {
                    MyFile.close();
                    return true;
                }
                vCustomers.push_back(Customer);
            }

            MyFile.close();

        }
        return false;
    }
    static Customer ConvertCustomerLinetoRecord(string Line, string Seperator = "#//#")
    {
        Customer Customer;
        vector<string> vCustomerData;
        vCustomerData = CommonFunctions::SplitString(Line, Seperator);

        Customer.CustomerID = stoi(vCustomerData[0]);
        Customer.CustomerName = vCustomerData[1];
        Customer.Password = vCustomerData[2];
        Customer.CustomerAddress = vCustomerData[3];
        Customer.CustomerContact = stoi(vCustomerData[4]);

        return Customer;
    }
    static vector <Customer> LoadCustomersDataFromFile()
    {
        vector <Customer> vCustomers;
        fstream MyFile;
        MyFile.open(CustomersFileName, ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;


            while (getline(MyFile, Line))
            {
                Customer customer = ConvertCustomerLinetoRecord(Line);
                vCustomers.push_back(customer);
            }
            MyFile.close();
        }
        return vCustomers;
    }
    static string ConvertCustomerRecordToLine(Customer Customer, string Seperator = "#//#")
    {

        string stCustomerRecord = "";
        stCustomerRecord += to_string(Customer.CustomerID) + Seperator;
        stCustomerRecord += Customer.CustomerName + Seperator;
        stCustomerRecord += Customer.Password + Seperator;
        stCustomerRecord += Customer.CustomerAddress + Seperator;
        stCustomerRecord += to_string(Customer.CustomerContact) + Seperator;
        return stCustomerRecord;
    }
    void AddNewCustomer()
    {
        CommonFunctions::AddDataLineToFile(CustomersFileName, ConvertCustomerRecordToLine(*this));
    }
    static Customer FindCustomerByCustomerID(int CustomerID)
    {

        vCustomers = LoadCustomersDataFromFile();

        for (Customer C : vCustomers)
        {

            if (C.CustomerID == CustomerID)
            {

                return C;
            }

        }
        return false;
    }
    static Customer FindCustomerByCustomerameAndPassword(string Customername , string Password)
    {

        vCustomers = LoadCustomersDataFromFile();

        for (Customer C : vCustomers)
        {

            if ((C.CustomerName == Customername) && ( C.Password == Password) )
            {

                return C;
            }

        }
        return Customer();
    }
    vector <Customer> SaveCustomersDataToFile( vector <Customer> vCustomers)
    {
        fstream MyFile;
        MyFile.open(CustomersFileName, ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {
            for (Customer C : vCustomers)
            {

                if (C._MarkForDelete == false)
                {
                    //we only write records that are not marked for delete.  
                    DataLine = ConvertCustomerRecordToLine(C);
                    MyFile << DataLine << endl;
                }

            }

            MyFile.close();
        }

        return vCustomers;
    }
    bool UpdateCustomer()
    {

        vCustomers = LoadCustomersDataFromFile();
        char Answer = 'n';

        for (Customer& C : vCustomers)
        {
            if (C.CustomerID == CustomerID)
            {
                C = *this;
                break;
            }
        }

        SaveCustomersDataToFile( vCustomers);

      
        return true;
    }
    bool MarkCustomerForDeleteByCustomerID(int UserID, vector <Customer>& vCustomers)
    {

        for (Customer& C : vCustomers)
        {

            if (C.CustomerID == UserID)
            {
                C._MarkForDelete = true;
                return true;
            }

        }

        return false;
    }
    void PrintCustomerCard()
    {
       std::cout << "\n\t\t\t\t\tThe following are the Customer details:\n";
       std::cout << "--\t\t\t\t\t---------------------------------";
       std::cout << "\n\t\t\t\t\tCustomer ID : " <<  CustomerID;
       std::cout << "\n\t\t\t\t\tCustomer Name    : " << CustomerName;
       std::cout << "\n\t\t\t\t\tCustomer Address     : " << CustomerAddress;
       std::cout << "\n\t\t\t\t\tCustomer Contact        : " << CustomerContact;
       std::cout << "\n\t\t\t\t\t-----------------------------------\n";
    }
    void PrintCustomerRecordLine()
    {
        cout << "| " << setw(15) << left << CustomerID;
        cout << "| " << setw(20) << left << CustomerName;
        cout << "| " << setw(15) << left << CustomerContact;
        cout << "| " << setw(40) << left << CustomerAddress;

    }
    bool DeleteCustomer()
    {

        MarkCustomerForDeleteByCustomerID(CustomerID, vCustomers);
        SaveCustomersDataToFile(vCustomers);
        //Refresh Users
        vCustomers = LoadCustomersDataFromFile();

        return true;
    }
};

