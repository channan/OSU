/**************************************
 * Program Name: Item.hpp
 * Author: Cody Hannan
 * Date: 2/5/17
 * Description: Header file for item class. Contains the default constructor for item and function prototypes. 
 **************************************/

#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

using std::string;

class Item
{
private:
    string name;
    string unit;
    int quantity;
    double price;
    
public:
    Item() //default constructor creates "empty" items
    {
        name="Empty";
        unit="N/A";
        quantity=NULL;
        price=NULL;
    }
    Item(string, string, int, double);
    string getName();
    string getUnit();
    int getQuantity();
    double getPrice();
    double totalPrice();
};

#endif
