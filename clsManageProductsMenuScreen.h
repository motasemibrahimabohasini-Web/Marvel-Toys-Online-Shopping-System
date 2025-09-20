#pragma once
#include <iomanip>
#include <string>
#include "clsAllProductsScreen.h"
#include "clsAddNewProductScreen.h"
#include "clsUpdateProductScreen.h"
#include "clsFindProductScreen.h"
#include "clsDeleteProductScreen.h"


class clsProductMenuScreen : protected clsScreen
{
   
private :
    static enum _enProductMenuOptions
    {
        enProductsList = 1, enAddNewProduct = 2, enUpdateProduct = 3, enFindProduct = 4, enDeleteProduct = 5, enProductMenuOptionsExist = 6

    };

   static void _ShowAllProductsScreen()
    {
       clsAllProductsScreen::ShowAllProductsScreen();
    }
   static void _ShowAddNewProductsScreen()
   {
       clsAddNewProductScreen::ShowAddNewProductsScreen();
   }
   static void _ShowUpdateProductScreen()
   {
       clsUpdateProductScreen::ShowUpdateProductScreen();
   }
   static void _ShowFindProductScreen()
   {
       clsFindProductScreen::ShowFindProductScreen();
   }
   static void  _ShowDeleteProductScreen()
   {
       clsDeleteProductScreen::ShowDeleteProductScreen();
   }
   static void _GoBackToProductMenu() {
       std::cout << "\n\nPress any key to go back to Main Menu...";
       system("pause>0");
       ShowManageProductMenuScreen();
   }
    static void _PerfromProductMenueOption(_enProductMenuOptions ProductMenuOption)
    {
        switch (ProductMenuOption)
        {

        case _enProductMenuOptions::enProductsList:
            system("cls");
            _ShowAllProductsScreen();
            _GoBackToProductMenu();
            break;

        case _enProductMenuOptions::enAddNewProduct:
            system("cls");
            _ShowAddNewProductsScreen();
            _GoBackToProductMenu();
            break;

        case _enProductMenuOptions::enUpdateProduct:
            system("cls");
            _ShowUpdateProductScreen();
            _GoBackToProductMenu();

            break;


        case _enProductMenuOptions::enFindProduct:
            system("cls");
            _ShowFindProductScreen();
            _GoBackToProductMenu();
            break;

        case _enProductMenuOptions::enDeleteProduct:
            system("cls");
            _ShowDeleteProductScreen();
            _GoBackToProductMenu();
            break;
        case _enProductMenuOptions::enProductMenuOptionsExist:
            system("cls");
            


        }
        
        
    }
    static short _ReadProductMenuOption()
    {
        short Choice = 0;
        cout << "  Choose the Product Option [1 to 6]: ";
        cin >> Choice;
        while ((Choice > 6 || Choice < 1) || cin.fail())
        {
            cout << " Invalid input , Choose the Product Option [1 to 6]: ";
            cin.clear(); // reset error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> Choice;
        }

        return Choice;
    }
public :
    static void ShowManageProductMenuScreen()
    {
        system("cls");
        _DrawScreenHeader("Product Menu Screen");
        cout << "\t\t\t\t\t===========================================\n";
        cout << "\t\t\t\t\t\tProducts Menue \n";
        cout << "\t\t\t\t\t===========================================\n";
        cout << "\t\t\t\t\t\t[1] Show Products List.\n";
        cout << "\t\t\t\t\t\t[2] Add New Product.\n";
        cout << "\t\t\t\t\t\t[3] Update Product Info.\n";
        cout << "\t\t\t\t\t\t[4] Find Product.\n";
        cout << "\t\t\t\t\t\t[5] Delete Product.\n";
        cout << "\t\t\t\t\t\t[6] Exit.\n";
        cout << "\t\t\t\t\t===========================================\n";
        _PerfromProductMenueOption((_enProductMenuOptions)_ReadProductMenuOption());
    }
};

