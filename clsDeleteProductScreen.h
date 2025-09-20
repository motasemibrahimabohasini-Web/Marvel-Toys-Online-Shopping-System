#pragma once
#include <iomanip>
#include <string>
#include "Users.h"
#include "clsScreen.h"
#include "clsGlobal.h"
#include "Products.h"
class clsDeleteProductScreen :protected clsScreen
{
private : 
    static void DeleteProduct()
    {
        int ProductID =clsGlobal:: ReadID("Product ID");
        Products Product = Products::FindProductByProductID(ProductID);
        if (Product.ProductID != 0)
        {

            Product.PrintProductCard();
            char Answer = 'n';
            cout << "\n\nAre you sure you want delete this Product? y/n ? ";
            cin >> Answer;
            if (Answer == 'y' || Answer == 'Y')
            {
                if (Product.DeleteProduct())
                {
                    cout << "\n\nProduct Deleted Successfully.";
                }
                else {
                    cout << "\n\nError: Product could not be deleted.";
                }
            }
        }
        else
        {
            cout << "\nProduct with Product ID (" << ProductID << ") is Not Found!";
        }

    }
public :
    static void ShowDeleteProductScreen()
    {
        _DrawScreenHeader("Delete Product Screen");
        cout << "\n\t\t\t\t\t-----------------------------------\n";
        cout << "\t\t\t\t\t\tDelete Product ";
        cout << "\n\t\t\t\t\t-----------------------------------\n";

        DeleteProduct();

    }
};

