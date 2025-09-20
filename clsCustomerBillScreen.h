#pragma once
#include <iomanip>
#include <string>
#include "Customers.h"
#include "clsScreen.h"
#include "clsGlobal.h"
class clsCustomerBillScreen : protected clsScreen
{
public:
   static void ShowBillScreen()
    {
        vector <OrderItem> vOrderItems = OrderItem::LoadOrderItemsDataFromFileByOrderID(clsGlobal::CurrentOrder.OrderID);
        _DrawScreenHeader("Bill Screen");
        cout << "\n\t\t\t\t\tOrder Items List (" << vOrderItems.size() << ") User(s).";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << "| " << left << setw(15) << "Order Item ID";
        cout << "| " << left << setw(10) << "Order ID";
        cout << "| " << left << setw(20) << "Product Name";
        cout << "| " << left << setw(20) << "Number Of Items";
        cout << "| " << left << setw(15) << "Total Price";
        cout << "| " << left << setw(20) << "Customer Name";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vOrderItems.size() == 0)
            cout << "\t\t\t\tthere is No Order you made!";
        else

            for (OrderItem OrderItem : vOrderItems)
            {
                OrderItem.ProductName = Products::FindProductByProductID(OrderItem.ProductID).ProductName;
                OrderItem.TotalPrice = Products::FindProductByProductID(OrderItem.ProductID).Price * OrderItem.NumberOfItems;
                if (OrderItem.CustomerID != 0)
                {
                    OrderItem.CustomerName = Customer::FindCustomerByCustomerID(OrderItem.CustomerID).CustomerName;
                }

                OrderItem.PrintOrderItemsRecordLine();
                cout << endl;
            }

        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;
    }
};

