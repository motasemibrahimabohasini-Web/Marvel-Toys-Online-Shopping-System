#pragma once

class clsFindOrderScreen : protected clsScreen
{
private :
    static void FindOrder()
    {
        clsGlobal::CurrentOrder = Order::FindOrderByOrderID(clsGlobal::ReadID("Order ID"));

        if (clsGlobal::CurrentOrder.OrderID != 0)
        {
            clsCustomerBillScreen::ShowBillScreen();
            clsGlobal::CurrentOrder = NULL;
        }
        else
        {
            cout << "\nOrder with Order ID (" << clsGlobal::CurrentOrder.OrderID << ") is Not Found!";
        }
    }

public :
   static  void ShowFindOrderScreen()
    {
       _DrawScreenHeader("Find Order Screen");
        cout << "\n\t\t\t\t\t-----------------------------------\n";
        cout << "\t\t\t\t\t\tFind Order";
        cout << "\n\t\t\t\t\t-----------------------------------\n";

        FindOrder();
    }


};

