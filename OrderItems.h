#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
#include "Products.h"
#include "Customers.h"
#include "Orders.h"

const string OrderItemsFileName = "OrderItems.txt";
class OrderItem {
private:

    static vector<OrderItem> vOrderItems;
public:

    int _OrderItemID;
    int NumberOfItems;
    int OrderID;
    int CustomerID;
    int ProductID;
    float TotalPrice;
    string ProductName;
    string CustomerName;
    bool _MarkForDelete;




    OrderItem(int orderId = 0, const int& customerId = 0, int numberOfItems = 0, int OrderItemID = 0, bool MarkForDelete = false)
        : OrderID(orderId), CustomerID(customerId), NumberOfItems(numberOfItems), _OrderItemID(OrderItemID), _MarkForDelete(MarkForDelete) {
    }


    static OrderItem FindOrderItemByOrderItemID(int OrderItemID)
    {

        vOrderItems = LoadOrderItemsDataFromFile();

        for (OrderItem C : vOrderItems)
        {

            if (C._OrderItemID == OrderItemID)
            {

                return C;
            }

        }
        return false;
    }
    static vector <OrderItem> FindOrderItemByOrderID(int OrderID)
    {

        vOrderItems = LoadOrderItemsDataFromFile();

        vector<OrderItem>vOrderItemsByOrderID;
        for (OrderItem C : vOrderItems)
        {

            if (C.OrderID == OrderID)
            {


                vOrderItemsByOrderID.push_back(C);
            }

        }
        return vOrderItemsByOrderID;
    }
    //static bool OrderItemExistsByOrderItemName(string OrderItemName)
    //{

    //    vector <OrderItems> vOrderItems;
    //    fstream MyFile;
    //    MyFile.open(OrderItemsFileName, ios::in);//read Mode

    //    if (MyFile.is_open())
    //    {
    //        string Line;
    //        OrderItems OrderItem;

    //        while (getline(MyFile, Line))
    //        {
    //            OrderItem = ConvertOrderItemLinetoRecord(Line);
    //            if (OrderItem.OrderIte == OrderItemName)
    //            {
    //                MyFile.close();
    //                return true;
    //            }
    //            vOrderItems.push_back(OrderItem);
    //        }

    //        MyFile.close();

    //    }
    //    return false;
    //}
    static OrderItem ConvertOrderItemLinetoRecord(string Line, string Seperator = "#//#")
    {
        OrderItem OrderItem;
        vector<string> vOrderItemData;
        vOrderItemData = CommonFunctions::SplitString(Line, Seperator);

        OrderItem._OrderItemID = stoi(vOrderItemData[0]);
        OrderItem.NumberOfItems = stoi(vOrderItemData[1]);
        OrderItem.CustomerID = stoi(vOrderItemData[2]);
        OrderItem.ProductID = stoi(vOrderItemData[3]);
        OrderItem.OrderID = stoi(vOrderItemData[4]);


        return OrderItem;
    }
    void AddNewOrderItem()
    {
        _OrderItemID = CommonFunctions::GenerateNextID(OrderItemsFileName);
        CommonFunctions::AddDataLineToFile(OrderItemsFileName, ConvertOrderItemRecordToLine(*this));
    }
    static string ConvertOrderItemRecordToLine(OrderItem OrderItem, string Seperator = "#//#")
    {

        string stOrderItemRecord = "";
        stOrderItemRecord += to_string(OrderItem._OrderItemID) + Seperator;
        stOrderItemRecord += to_string(OrderItem.NumberOfItems) + Seperator;
        stOrderItemRecord += to_string(OrderItem.CustomerID) + Seperator;
        stOrderItemRecord += to_string(OrderItem.ProductID) + Seperator;
        stOrderItemRecord += to_string(OrderItem.OrderID) + Seperator;
        return stOrderItemRecord;
    }
    static vector <OrderItem> LoadOrderItemsDataFromFile()
    {
        vector <OrderItem> vOrderItems;
        fstream MyFile;
        MyFile.open(OrderItemsFileName, ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;


            while (getline(MyFile, Line))
            {
                OrderItem OrderItem = ConvertOrderItemLinetoRecord(Line);
                vOrderItems.push_back(OrderItem);
            }
            MyFile.close();
        }
        return vOrderItems;
    }
    static vector <OrderItem> LoadOrderItemsDataFromFileByOrderID(Order CurrentOrder)
    {
        vector <OrderItem> vOrderItems;
        fstream MyFile;
        MyFile.open(OrderItemsFileName, ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;


            while (getline(MyFile, Line))
            {
                OrderItem OrderItem = ConvertOrderItemLinetoRecord(Line);
                if (OrderItem.OrderID == CurrentOrder.OrderID)
                {
                    CurrentOrder.TotalAmlount += OrderItem.TotalPrice;
                    vOrderItems.push_back(OrderItem);
                }
            }
            MyFile.close();
        }
        return vOrderItems;
    }
    bool UpdateOrderItem()
    {

        vOrderItems = LoadOrderItemsDataFromFile();
        char Answer = 'n';

        for (OrderItem& C : vOrderItems)
        {
            if (C._OrderItemID == _OrderItemID)
            {
                C = *this;
                break;
            }
        }

        SaveOrderItemsDataToFile(vOrderItems);


        return true;
    }
    void PrintOrderItemCard()
    {
        cout << "\n\t\t\t\t\tThe following are the OrderItem details:\n";
        cout << "--\t\t\t\t\t---------------------------------";
        cout << "\n\t\t\t\t\tOrderItem ID : " << _OrderItemID;
        cout << "\n\t\t\t\t\tOrderItem Name    : " << ProductName;
        cout << "\n\t\t\t\t\tOrderItem Address     : " << CustomerName;
        cout << "\n\t\t\t\t\tNumber Of Items        : " << NumberOfItems;
        cout << "\n\t\t\t\t\tTotal Price        : " << TotalPrice;
        cout << "\n\t\t\t\t\t-----------------------------------\n";
    }
    vector <OrderItem> SaveOrderItemsDataToFile(vector <OrderItem> vOrderItem)
    {
        fstream MyFile;
        MyFile.open(OrderItemsFileName, ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {
            for (OrderItem C : vOrderItem)
            {

                if (C._MarkForDelete == false)
                {
                    //we only write records that are not marked for delete.  
                    DataLine = ConvertOrderItemRecordToLine(C);
                    MyFile << DataLine << endl;
                }

            }

            MyFile.close();
        }

        return vOrderItem;
    }

    bool MarkOrderItemForDeleteByOrderItemID(int OrderItemID, vector <OrderItem>& vOrderItems)
    {

        for (OrderItem& C : vOrderItems)
        {

            if (C._OrderItemID == OrderItemID)
            {
                C._MarkForDelete = true;
                return true;
            }

        }

        return false;
    }
    bool DeleteOrderItem()
    {

        MarkOrderItemForDeleteByOrderItemID(_OrderItemID, vOrderItems);
        SaveOrderItemsDataToFile(vOrderItems);
        //Refresh Users
        vOrderItems = LoadOrderItemsDataFromFile();

        return true;
    }
    void PrintOrderItemsRecordLine()
    {
        cout << "| " << setw(15) << left << _OrderItemID;
        cout << "| " << setw(10) << left << OrderID;
        cout << "| " << setw(20) << left << ProductName;
        cout << "| " << setw(20) << left << NumberOfItems;
        cout << "| " << setw(15) << left << TotalPrice;
        cout << "| " << setw(20) << left << CustomerName;
    }

};
