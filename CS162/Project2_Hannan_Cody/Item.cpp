/****************************************
 * Program Name: Item.cpp
 * Author: Cody Hannan
 * Date: 2/5/17
 * Description: This contains the functions for the item class. They mostly consist of getter functions and an overloaded contructor that user the user inputted parameters to initialize an item object.
 ****************************************/

#include <string>
#include "Item.hpp"

using std::string;

Item::Item(string n, string u, int q, double p) //constructor uses item parameters to initialize item object
{
    name=n;
    unit=u;
    quantity=q;
    price=p;
}
string Item::getName() //return name
{
    return name;
}
string Item::getUnit() //returns unit
{
        return unit;
}
int Item::getQuantity() //returns quantity
{
        return quantity;
}
double Item::getPrice() //returns price
{
    return price;
}
double Item::totalPrice() //return total price
{
    return price*quantity;
}
    

