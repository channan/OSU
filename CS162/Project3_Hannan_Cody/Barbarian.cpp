/**********************
 * Program Name: Barbarian.cpp
 * Author: Cody Hannan
 * Date: 2/20/17
 * Description: Contains functions for creature class.
 ************************/

#include "Barbarian.hpp"
#include <cstdlib>

int Barbarian::attack() //attack roll
{
    int die1,die2;
    
    die1=rand() % 6 + 1;
    die2=rand() % 6 + 1;
    
    return die1+die2;
}
int Barbarian::defense() //defense roll
{
    int die1,die2;
    
    die1=rand() % 6 + 1;
    die2=rand() % 6 + 1;
    
    return die1+die2;
}

