#pragma once

class clsAllOrdersScreen : protected clsScreen
{

private :

public :
    static void ShowAllOrdersScreen()
    {

        vector <Order> vOrders = Order::LoadOrdersDataFromFile();
        _DrawScreenHeader("Show All Orders Screen");
        cout << "\n\t\t\t\t\tOrders List (" << vOrders.size() << ") Order(s).";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << "| " << left << setw(15) << "Order ID";
        cout << "| " << left << setw(20) << "Number Of Items";
        cout << "| " << left << setw(15) << "Total Amount";
        cout << "| " << left << setw(20) << "Customer Name";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vOrders.size() == 0)
            cout << "\t\t\t\tNo Orders Available In the System!";
        else

            for (Order Order : vOrders)
            {
                if (Order.CustomerID != 0)
                {
                    Order.CustomerName = Customer::FindCustomerByCustomerID(Order.CustomerID).CustomerName;
                }
                Order.PrintOrderRecordLine();
                cout << "\n\n";
            }

        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;


    }
};

