#pragma once

#include "clsCustomerBillScreen.h"
class clsDeleteOrderScreen : protected clsScreen
{
    static void DeleteOrder()
    {
        int OrderID = clsGlobal::ReadID("Order ID");
        clsGlobal::CurrentOrder = Order::FindOrderByOrderID(OrderID);
        vector <OrderItem> vOrderItems = OrderItem::FindOrderItemByOrderID(OrderID);
        if (clsGlobal::CurrentOrder.OrderID != 0)
        {
            char Answer = 'n';
           clsCustomerBillScreen::ShowBillScreen();
            cout << "\n\nAre you sure you want delete this Order? y/n ? ";
            cin >> Answer;
            if (Answer == 'y' || Answer == 'Y')
            {
                for (OrderItem O : vOrderItems)
                {
                    O.DeleteOrderItem();
                }
                if (clsGlobal::CurrentOrder.DeleteOrder())
                {
                    clsGlobal::CurrentOrder = NULL;
                    cout << "\n\nOrder Deleted Successfully.";
                }
                else {
                    cout << "\n\nError: Order could not be deleted.";
                }
            }
        }
        else
        {
            cout << "\nOrder with Order ID (" << OrderID << ") is Not Found!";
        }

    }
public :
    static void ShowDeleteOrderScreen()
    {
        
        cout << "\n\t\t\t\t\t-----------------------------------\n";
        cout << "\t\t\t\t\t\tDelete Order Screen";
        cout << "\n\t\t\t\t\t-----------------------------------\n";

        DeleteOrder();

    }
};

