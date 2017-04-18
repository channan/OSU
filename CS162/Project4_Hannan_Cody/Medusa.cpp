/**********************
 * Program Name: Medusa.cpp
 * Author: Cody Hannan
 * Date: 3/5/17
 * Description: Contains functions for creature class.
 ************************/

#include "Medusa.hpp"
#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;

int Medusa::attack() //attack roll
{
    int die1,die2;
    
    die1=rand() % 6 + 1;
    die2=rand() % 6 + 1;
    
    if(die1+die2==12) //if 12 is rolled medusa's ability is activated
    {
        cout << "Medusa uses glare." << endl;
        return 1000;
    }
    else
    {
        return die1+die2;
    }
}
int Medusa::defense() //defense roll
{
    return rand() % 6 + 1;
}
string Medusa::getName()
{
    return "Medusa";
}
