#pragma once


#include "clsAllProductsScreen.h"
class clsAddNewcartScreen : protected clsScreen
{
private : 
    static vector <OrderItem> ReadNewOrderItems()
    {
        char Answer = 'n';
        vector <OrderItem> vOrderItems;
        OrderItem OrderItem;
        do {

            OrderItem.CustomerID =clsGlobal::CurrentCustomer.CustomerID;
            cout << "\t\t\t\t\tEnter Product ID depend on the screen of products :  ";
            cin >> OrderItem.ProductID;
            while (!Products::ProductExistsByProductID(OrderItem.ProductID))
            {
                cout << "\n\t\t\t\t\tProduct with ID [" << OrderItem.ProductID << "] does not exist, Enter another Product ID? ";
                cin >> OrderItem.ProductID;
            }




            cout << "\t\t\t\t\tEnter Number Of Items? ";
            cin >> OrderItem.NumberOfItems;
            while (OrderItem.NumberOfItems <= 0)
            {
                cout << "\t\t\t\t\tNumber Of Items Can't be 0 Or Less Please Enter valid Price :  ";
                cin >> OrderItem.NumberOfItems;
            }

            OrderItem.TotalPrice = Products::FindProductByProductID(OrderItem.ProductID).Price * OrderItem.NumberOfItems;

            vOrderItems.push_back(OrderItem);
            cout << "\t\t\t\t\tDo you want to add more Order Items? Y/N? ";
            cin >> Answer;
        } while (toupper(Answer) == 'Y');

        return  vOrderItems;
    }
    static void AddNewOrderItems()
    {
       clsAllProductsScreen::ShowAllProductsScreen();
        char AddMore = 'Y';
        do
        {
            //system("cls");
            cout << "\t\t\t\t\tAdding New Order Item:\n\n";
            vector <OrderItem> vOrderItems = ReadNewOrderItems();

            if (!vOrderItems.empty())
            {
                for (OrderItem OrderItem : vOrderItems)
                {
                   clsGlobal::CurrentOrder.TotalAmlount += OrderItem.TotalPrice;
                   clsGlobal::CurrentOrder.NumberOfItems += OrderItem.NumberOfItems;

                }
               clsGlobal::CurrentOrder.CustomerID = clsGlobal::CurrentCustomer.CustomerID;
               clsGlobal::CurrentOrder.AddNewOrder();
                for (OrderItem OrderItem : vOrderItems)
                {
                    OrderItem.CustomerID = 1;
                    OrderItem.OrderID =clsGlobal::CurrentOrder.OrderID;
                    OrderItem.AddNewOrderItem();

                }

                cout << "\n\t\t\t\t\tOrder Item(s) Added Successfully, do you want to add Another Order? Y/N? ";
                cin >> AddMore;
               
            }
            else
            {
                break;
            }

        } while (toupper(AddMore) == 'Y');

    }
public : 
    static void ShowAddNewCartScreen()
    {
        _DrawScreenHeader("Add New Cart Screen");
        cout << "\n\t\t\t\t\t-----------------------------------\n";
        cout << "\t\t\t\t\t\tAdd New Cart Screen";
        cout << "\n\t\t\t\t\t-----------------------------------\n";

        AddNewOrderItems();
    }
};

