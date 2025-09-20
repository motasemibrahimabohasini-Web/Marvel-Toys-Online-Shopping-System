#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "CommonFunctions.h"
#include "Customers.h"
using namespace std;
const string ProductsFileName = "Products.txt";
class Products 
{

public:
    static vector<Products> vProducts;
    int ProductID;
    std::string ProductName;
    double Price;
    bool _MarkToDelete;

    Products(int productId = 0, const std::string& productName = "", double price = 0.0,bool MarkToDelete = false)
        : ProductID(productId), ProductName(productName), Price(price) , _MarkToDelete(MarkToDelete) {
    }
    static Products FindProductByProductID(int ProductID)
    {

        vProducts = LoadProductsDataFromFile();

        for (Products C : vProducts)
        {

            if (C.ProductID == ProductID)
            {

                return C;
            }

        }
        return false;
    }
    static bool ProductExistsByProductName(string ProductName)
    {

        vector <Products> vProducts;
        fstream MyFile;
        MyFile.open(ProductsFileName, ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            Products Product;

            while (getline(MyFile, Line))
            {
                Product = ConvertProductLinetoRecord(Line);
                if (Product.ProductName == ProductName)
                {
                    MyFile.close();
                    return true;
                }
                vProducts.push_back(Product);
            }

            MyFile.close();

        }
        return false;
    }
    static bool ProductExistsByProductID(int ProductID)
    {

        vector <Products> vProducts;
        fstream MyFile;
        MyFile.open(ProductsFileName, ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            Products Product;

            while (getline(MyFile, Line))
            {
                Product = ConvertProductLinetoRecord(Line);
                if (Product.ProductID == ProductID)
                {
                    MyFile.close();
                    return true;
                }
                vProducts.push_back(Product);
            }

            MyFile.close();

        }
        return false;
    }
    static Products ConvertProductLinetoRecord(string Line, string Seperator = "#//#")
    {
        Products Product;
        vector<string> vProductData;
        vProductData = CommonFunctions::SplitString(Line, Seperator);

        Product.ProductID = stoi(vProductData[0]);
        Product.ProductName = vProductData[1];
        Product.Price = stoi(vProductData[2]);


        return Product;
    }
    void AddNewProduct()
    {
        CommonFunctions::AddDataLineToFile(ProductsFileName, ConvertProductRecordToLine(*this));
    }
    static string ConvertProductRecordToLine(Products Product, string Seperator = "#//#")
    {

        string stProductRecord = "";
        stProductRecord += to_string(Product.ProductID) + Seperator;
        stProductRecord += Product.ProductName + Seperator;
        stProductRecord += to_string(Product.Price) + Seperator;
        return stProductRecord;
    }
    static vector <Products> LoadProductsDataFromFile()
    {
        vector <Products> vProducts;
        fstream MyFile;
        MyFile.open(ProductsFileName, ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;


            while (getline(MyFile, Line))
            {
                Products Product = ConvertProductLinetoRecord(Line);
                vProducts.push_back(Product);
            }
            MyFile.close();
        }
        return vProducts;
    }
    bool UpdateProduct()
    {

        vProducts = LoadProductsDataFromFile();
        char Answer = 'n';

        for (Products& C : vProducts)
        {
            if (C.ProductID == ProductID)
            {
                C = *this;
                break;
            }
        }

        SaveProductsDataToFile(vProducts);


        return true;
    }
    void PrintProductCard()
    {
        cout << "\n\t\t\t\t\tThe following are the Product details:\n";
        cout << "--\t\t\t\t\t---------------------------------";
        cout << "\n\t\t\t\t\tProduct ID : " << ProductID;
        cout << "\n\t\t\t\t\tProduct Name    : " << ProductName;
        cout << "\n\t\t\t\t\tProduct Address     : " << Price;
        cout << "\n\t\t\t\t\t-----------------------------------\n";
    }
    vector <Products> SaveProductsDataToFile(vector <Products> vProduct)
    {
        fstream MyFile;
        MyFile.open(ProductsFileName, ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {
            for (Products C : vProduct)
            {

                if (C._MarkToDelete == false)
                {
                    //we only write records that are not marked for delete.  
                    DataLine = ConvertProductRecordToLine(C);
                    MyFile << DataLine << endl;
                }

            }

            MyFile.close();
        }

        return vProduct;
    }
  
    bool MarkProductForDeleteByProductID(int ProductID, vector <Products>& vProducts)
    {

        for (Products& C : vProducts)
        {

            if (C.ProductID == ProductID)
            {
                C._MarkToDelete = true;
                return true;
            }

        }

        return false;
    }
    bool DeleteProduct()
    {

        MarkProductForDeleteByProductID(ProductID, vProducts);
        SaveProductsDataToFile(vProducts);
        //Refresh Users
        vProducts = LoadProductsDataFromFile();

        return true;
    }






};
