/**********************
 * Program Name: HarryPotter.cpp
 * Author: Cody Hannan
 * Date: 2/20/17
 * Description: Contains functions for creature class.
 ************************/

#include "HarryPotter.hpp"
#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;

int HarryPotter::attack() //attack roll
{
    int die1,die2,i=0;
    
    die1=rand() % 6 + 1;
    die2=rand() % 6 + 1;
    
    if(strength<0 && i<1) //if harry loses all health he is revived with double health
    {
        setStrength(20);
        i++;
        cout << "Harry Potter is brought back by Hogwarts." << endl;
    }
    
    return die1+die2;
}
int HarryPotter::defense() //defense roll
{
    int die1,die2;
    
    die1=rand() % 6 + 1;
    die2=rand() % 6 + 1;
    
    return die1+die2;
}
