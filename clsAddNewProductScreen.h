#pragma once
#include <iomanip>
#include <string>
#include "Users.h"
#include "clsScreen.h"
#include "clsGlobal.h"
#include "Products.h"
class clsAddNewProductScreen : protected clsScreen
{
private : 
    static Products _ReadNewProduct()
    {
        Products Product;
        cout << "Enter Product Name? ";

        // Usage of std::ws will extract allthe whitespace character
        getline(cin >> ws, Product.ProductName);

        while (Products::ProductExistsByProductName(Product.ProductName))
        {
            cout << "\nProduct with [" << Product.ProductName << "] already exists, Enter another Product Name? ";
            getline(cin >> ws, Product.ProductName);
        }


        cout << "Enter Price? ";
        cin >> Product.Price;
        while (cin.fail() || Product.Price <= 0)
        {
            cout << "Invalid Input!, Enter Price? ";
            cin.clear(); // reset error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> Product.Price;

        }

        Product.ProductID = CommonFunctions::GenerateNextID(ProductsFileName);


        return Product;
    }
    static void _AddNewProducts()
    {
        char AddMore = 'Y';
        do
        {
            //system("cls");
            cout << "Adding New Product:\n\n";
            Products Product = _ReadNewProduct();



            Product.AddNewProduct();
            cout << "\nProduct Added Successfully, do you want to add more Products ? Y/N? ";
            cin >> AddMore;

        } while (toupper(AddMore) == 'Y');

    }
public : 

    static void ShowAddNewProductsScreen()
    {
        
        cout << "\n\t\t\t\t\t-----------------------------------\n";
        cout << "\t\t\t\t\t\tAdd New Products Screen";
        cout << "\n\t\t\t\t\t-----------------------------------\n";

        _AddNewProducts();
    }
};

