/****************************************************
 * Program Name: Die.cpp
 * Author: Cody Hannan
 * Date: 1/29/17
 * Description: This the implementation file for the Die class. The primary function here is roll, which returns a random
 * value based on the user entered sides value. It also has getter functions for sides and type.
 ******************************************************/

#include <cstdlib>
#include "Die.hpp"

Die::Die(int s) //contructor uses user input value for sides to set the value for Die's private variable
{
    sides=s;
}
int Die::roll() //rolls the die
{
    return rand() % sides + 1;
}
int Die::getSides() //returns sides value of the die
{
    return sides;
}
string Die::getType() //returns the type of die
{
    return "normal";
}

