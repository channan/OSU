/**********************
 * Program Name: BlueMen.cpp
 * Author: Cody Hannan
 * Date: 2/20/17
 * Description: Contains functions for creature class.
 ************************/

#include "BlueMen.hpp"
#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;

int BlueMen::attack() //attack roll
{
    int die1,die2;
    
    die1=rand() % 10 + 1;
    die2=rand() % 10 + 1;
    
    return die1+die2;
}
int BlueMen::defense() //defense roll
{
    int die1,die2,die3;
    
    if(strength>8) //takes away defense die as blue men lose health
    {
        die1=rand() % 6 + 1;
        die2=rand() % 6 + 1;
        die3=rand() % 6 + 1;
    }
    else if(strength>4)
    {
        cout << "Blue men have lost some defense." << endl;
        die1=rand() % 6 + 1;
        die2=rand() % 6 + 1;
        die3=0;
    }
    else
    {
        cout << "Blue men have lost most of their defense." << endl;
        die1=rand() % 6 + 1;
        die2=0;
        die3=0;
    }
    
    return die1+die2+die3;
}
