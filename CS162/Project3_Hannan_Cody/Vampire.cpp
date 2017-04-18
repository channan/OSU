/**********************
 * Program Name: Vampire.cpp
 * Author: Cody Hannan
 * Date: 2/20/17
 * Description: Contains functions for creature class.
 ************************/

#include "Vampire.hpp"
#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;

int Vampire::attack() //attack roll
{
    return rand() % 12 + 1;
}
int Vampire::defense() //defense roll
{
    if(rand() % 2) //50% chance for vampire ability to occur
    {
        cout << "Vampire's charm succeeded." << endl;
        return 50;
    }
    else
    {
        return rand() % 6 + 1;
    }
}
