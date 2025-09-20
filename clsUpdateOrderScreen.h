#pragma once
#include "clsCustomerBillScreen.h"
class clsUpdateOrderScreen : protected clsScreen
{
private : 
  
    static OrderItem ReadUpdateOrder(vector <OrderItem> vOrderItems)
    {
        int OrderItemID = 0;
        Order Order;
        cout << "Enter OrderItem ID  You want to update ? ";
        cin >> OrderItemID;
        OrderItem TempOI;

        // Usage of std::ws will extract allthe whitespace character


        for (OrderItem O : vOrderItems)
        {
            if (OrderItemID == O._OrderItemID)
            {


                return O;

            }


        }



        return OrderItem();
    }
   static void UpdateOrder()
    {
        int OrderID = clsGlobal::ReadID("Order ID");

        clsGlobal::CurrentOrder = Order();
        clsGlobal::CurrentOrder = Order::FindOrderByOrderID(OrderID);

        if (clsGlobal::CurrentOrder.OrderID != 0)
        {
            vector <OrderItem>vOrderItems = OrderItem::LoadOrderItemsDataFromFileByOrderID(clsGlobal::CurrentOrder.OrderID);


            char Answer;
            clsGlobal::CurrentOrder.PrintOrderCard();



            cout << "\n\nAre you sure you want update this Order? y/n ? ";
            cin >> Answer;

            if (Answer == 'y' || Answer == 'Y')
            {
                clsCustomerBillScreen::ShowBillScreen();
                OrderItem O = ReadUpdateOrder(vOrderItems);
                system("cls");
                clsAllProductsScreen::ShowAllProductsScreen();


                cout << "Inter the ID Product You want : ";
                cin >> O.ProductID;
                while (!Products::ProductExistsByProductID(O.ProductID)) {
                    cout << "There is no Product with ProductD : " + to_string(O.ProductID) + " , Inter the ID Product You want : " << endl;
                    cin >> O.ProductID;
                }

                cout << "Inter the number Of items You want : ";
                cin >> O.NumberOfItems;



                char Answer = 'n';
                cout << "Are You sure You want to Update this Item [n,y]: ? ";
                cin >> Answer;
                if (Answer == 'y' || Answer == 'Y')
                {

                    if (O.UpdateOrderItem())
                    {
                        clsGlobal::CurrentOrder.NumberOfItems = 0;
                        clsGlobal::CurrentOrder.TotalAmlount = 0;
                        vOrderItems = OrderItem::LoadOrderItemsDataFromFileByOrderID(OrderID);
                        for (OrderItem O : vOrderItems)
                        {
                            clsGlobal::CurrentOrder.NumberOfItems += O.NumberOfItems;
                            clsGlobal::CurrentOrder.TotalAmlount += O.NumberOfItems * Products::FindProductByProductID(O.ProductID).Price;
                        }
                        clsGlobal::CurrentOrder.UpdateOrder();
                        cout << "Order Updated Successfully!";
                        clsCustomerBillScreen::ShowBillScreen();
                    }
                    else
                    {
                        cout << "Error on updated Order";
                    }







                }
            }




        }
        else {
            cout << "there is no Order with Order ID : "+to_string(OrderID)+"";
        }
       
    }

public :
    static void ShowUpdateOrderScreen()
    {
        _DrawScreenHeader("Update Order Info Screen  ");
        cout << "\n\t\t\t\t\t-----------------------------------\n";
        cout << "\t\t\t\t\t\tUpdate Order Info ";
        cout << "\n\t\t\t\t\t-----------------------------------\n";
        UpdateOrder();
    }

};

