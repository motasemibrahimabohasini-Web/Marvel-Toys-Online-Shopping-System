#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include "CommonFunctions.h"


    

using namespace std;
const string OrdersFileName = "Orders.txt";
class Order{
private:
   
    static vector<Order> vOrders;
    
public:
    
    int OrderID;
    int NumberOfItems;
    double TotalAmlount;
    int CustomerID;
    string CustomerName;
   
    bool MarkForDelete;


    Order(int orderId = 0, double totalAmount = 0, int numberOfItems = 0, int customerID = 0, bool markfordelete = false)
        : OrderID(orderId), TotalAmlount(totalAmount), NumberOfItems(numberOfItems), CustomerID(customerID), MarkForDelete(markfordelete) {
    }


    static bool OrderExistsByOrderID(int OrderID)
    {

        vector <Order> vOrders;
        fstream MyFile;
        MyFile.open(OrdersFileName, ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            Order Order;

            while (std::getline(MyFile, Line))
            {
                Order = ConvertOrderLinetoRecord(Line);
                if (Order.OrderID == OrderID)
                {
                    MyFile.close();
                    return true;
                }
                vOrders.push_back(Order);
            }

            MyFile.close();

        }
        return false;
    }
    static Order ConvertOrderLinetoRecord(string Line, string Seperator = "#//#")
    {
        Order Order;
        vector<string> vOrderData ;
    
        vOrderData = CommonFunctions::SplitString(Line, Seperator);

        Order.OrderID = stoi(vOrderData[0]);
        Order.NumberOfItems = stoi(vOrderData[1]);
        Order.TotalAmlount = stoi(vOrderData[2]);
        Order.CustomerID = stoi(vOrderData[3]);


        return Order;
    }
    static vector <Order> LoadOrdersDataFromFile()
    {
        vector <Order> vOrders;
        fstream MyFile;
        MyFile.open(OrdersFileName, ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;


            while (getline(MyFile, Line))
            {
                Order Order = ConvertOrderLinetoRecord(Line);
                vOrders.push_back(Order);
            }
            MyFile.close();
        }
        return vOrders;
    }
    static string ConvertOrderRecordToLine(Order Order, string Seperator = "#//#")
    {

        string stOrderRecord = "";
        stOrderRecord += to_string(Order.OrderID) + Seperator;
        stOrderRecord += to_string(Order.NumberOfItems) + Seperator;
        stOrderRecord += to_string(Order.TotalAmlount) + Seperator;
        stOrderRecord += to_string(Order.CustomerID) + Seperator;
        return stOrderRecord;
    }
    void AddNewOrder()
    {
        OrderID = CommonFunctions::GenerateNextID(OrdersFileName);
        CommonFunctions::AddDataLineToFile(OrdersFileName, ConvertOrderRecordToLine(*this));
    }
    static Order FindOrderByOrderID(int OrderID)
    {

        vOrders = LoadOrdersDataFromFile();

        for (Order C : vOrders)
        {

            if (C.OrderID == OrderID)
            {

                return C;
            }

        }
        return Order();
    }
    vector <Order> SaveOrdersDataToFile(vector <Order> vOrders)
    {
        fstream MyFile;
        MyFile.open(OrdersFileName, ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {
            for (Order C : vOrders)
            {

                if (C.MarkForDelete == false)
                {
                    //we only write records that are not marked for delete.  
                    DataLine = ConvertOrderRecordToLine(C);
                    MyFile << DataLine << endl;
                }

            }

            MyFile.close();
        }

        return vOrders;
    }
    bool UpdateOrder()
    {

        vOrders = LoadOrdersDataFromFile();
        char Answer = 'n';

        for (Order& C : vOrders)
        {
            if (C.OrderID == OrderID)
            {
                C = *this;
                break;
            }
        }

        SaveOrdersDataToFile(vOrders);


        return true;
    }
    bool MarkOrderForDeleteByOrderID(int UserID, vector <Order>& vOrders)
    {

        for (Order& C : vOrders)
        {

            if (C.OrderID == UserID)
            {
                C.MarkForDelete = true;
                return true;
            }

        }

        return false;
    }
    void PrintOrderCard()
    {
        cout << "\n\t\t\t\t\tThe following are the Order details:\n";
        cout << "--\t\t\t\t\t---------------------------------";
        cout << "\n\t\t\t\t\tOrder ID : " << OrderID;
        cout << "\n\t\t\t\t\tNumber Of Items    : " << NumberOfItems;
        cout << "\n\t\t\t\t\tTotal Amount     : " << TotalAmlount;
        cout << "\n\t\t\t\t\tTotal Amount     : " << CustomerName;
        cout << "\n\t\t\t\t\t-----------------------------------\n";
    }
    bool DeleteOrder()
    {

        MarkOrderForDeleteByOrderID(OrderID, vOrders);
        SaveOrdersDataToFile(vOrders);
        //Refresh Users
        vOrders = LoadOrdersDataFromFile();

        return true;
    }
    void PrintOrderRecordLine()
    {
        cout << "| " << setw(15) << left << OrderID;
        cout << "| " << setw(20) << left << NumberOfItems;
        cout << "| " << setw(15) << left << TotalAmlount;
        if (CustomerID == 0)
        {
            cout << "| " << setw(20) << left << "";
        }
        else {
            cout << "| " << setw(20) << left << CustomerName;

        }


    }

};