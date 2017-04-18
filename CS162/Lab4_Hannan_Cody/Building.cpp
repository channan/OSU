/******************************************
 * Program Name: Building.cpp
 * Author: Cody Hannan
 * Date: 2/5/17
 * Description: Building class implementation file. Mostly information is stored here, so the function consist of getter functions. The constructor uses parameters to initialize its private variables
 ******************************************/

#include "Building.hpp"

Building::Building(string n, double s, string a) //inits private variables using overloaded constructor
{
    name=n;
    size=s;
    address=a;
}

//getter functions
string Building::getName()
{
    return name;
}
double Building::getSize()
{
    return size;
}
string Building::getAddress()
{
    return address;
}

