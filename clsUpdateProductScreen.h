#pragma once
#include <iomanip>
#include <string>
#include "Users.h"
#include "clsScreen.h"
#include "clsGlobal.h"
#include "Products.h"
class clsUpdateProductScreen
{
    static Products ReadUpdateProduct()
    {
        Products Product;
        cout << "Enter Product Name :  ";

        // Usage of std::ws will extract allthe whitespace character
        getline(cin >> ws, Product.ProductName);

        while (Product.ProductName.length() < 3)
        {
            cout << "\nInvalid! Product Name Should have at least 3 characters Enter Valid Product Name? ";
            getline(cin >> ws, Product.ProductName);
        }


        cout << "Enter Price? ";
        cin >> Product.Price;
        while (Product.Price <= 0)
        {
            cout << "Price Can't be 0 Or Less Please Enter valid Price :  ";
            cin >> Product.Price;
        }
        return Product;
    }
    static void UpdateProducts()
    {
        int ProductID =clsGlobal::ReadID("Product ID");
        Products Product = Products::FindProductByProductID(ProductID);

        if (Product.ProductID != 0)
        {



            char Answer;
            Product.PrintProductCard();
            cout << "\n\nAre you sure you want update this Product? y/n ? ";
            cin >> Answer;
            if (Answer == 'y' || Answer == 'Y')
            {
                Product = ReadUpdateProduct();
                Product.ProductID = ProductID;
                if (Product.UpdateProduct())
                {
                    cout << "\n\nProduct Updated Successfully.";
                }
                else {
                    cout << "\n\nError: Product could not be updated.";
                }



            }
        }
        else {
            cout << "\nProduct with Product ID (" << ProductID << ") is Not Found!";
        }



    }
public : 

    static void ShowUpdateProductScreen()
    {
        
        cout << "\n\t\t\t\t\t-----------------------------------\n";
        cout << "\t\t\t\t\t\tUpdate Product Info Screen";
        cout << "\n\t\t\t\t\t-----------------------------------\n";
        UpdateProducts();
    }
};

