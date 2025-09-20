#pragma once
#include <iomanip>
#include <string>
#include "Users.h"
#include "clsScreen.h"
#include "clsGlobal.h"
#include "Products.h"
class clsAllProductsScreen : protected clsScreen
{
private :
    static void _PrintProductRecordLine(Products Product)
    {
        cout << "\t\t\t\t| " << setw(15) << left << Product.ProductID;
        cout << "| " << setw(20) << left << Product.ProductName;
        cout << "| " << setw(15) << left << Product.Price;

    }

public  :
    static void ShowAllProductsScreen()
    {

        _DrawScreenHeader("Show All Products Screen");
        vector <Products> vProducts = Products::LoadProductsDataFromFile();
        
        cout << "\n\t\t\t\t\tProduct List (" << vProducts.size() << ") Product(s).";
        cout << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
        cout << "\t\t\t\t| " << left << setw(15) << "ID";
        cout << "| " << left << setw(20) << "Name";
        cout << "| " << left << setw(15) << "Price";
        cout << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vProducts.size() == 0)
            cout << "\t\t\t\tNo Products Available In the System!";
        else

            for (Products Product : vProducts)
            {

                _PrintProductRecordLine(Product);
                cout << "\n\n";
            }

        cout << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
    }
};

