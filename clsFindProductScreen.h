#pragma once
#pragma once
#include <iomanip>
#include <string>
#include "Users.h"
#include "clsScreen.h"
#include "clsGlobal.h"
#include "Products.h"
class clsFindProductScreen : protected clsScreen
{
private : 
    static void FindProduct()
    {
        Products Product = Products::FindProductByProductID(clsGlobal::ReadID("Product ID"));

        if (Product.ProductID != 0)
        {
            Product.PrintProductCard();
        }
        else
        {
            cout << "\nProduct with Product ID (" << Product.ProductID << ") is Not Found!";
        }
    }
public :
    static void ShowFindProductScreen()
    {
        _DrawScreenHeader("Find Product Screen");
        cout << "\n\t\t\t\t\t-----------------------------------\n";
        cout << "\t\t\t\t\t\tFind Product ";
        cout << "\n\t\t\t\t\t-----------------------------------\n";

        FindProduct();
    }
};

