/****************************************************
 * Program Name: LoadedDie.cpp
 * Author: Cody Hannan
 * Date: 1/29/17
 * Description: This is the implementation file for LoadedDie. It works very similary to Die, but roll of course works
 * differently and getType would return its corresponding type.
 ******************************************************/

#include "LoadedDie.hpp"
#include <cstdlib>

LoadedDie::LoadedDie(int s): Die(s) //same contructor as Die is used here, so we copy Die's contructor
    {}

int LoadedDie::roll() //rolls the loaded die
    {
        //has a 50% chance of rolling the max number of sides
        if((rand() % 2)==1)
        {
            return rand() % sides + 1;
        }
        else
        {
            return sides;
        }
    }
string LoadedDie::getType() //returns the LoadedDie's type
    {
        return "loaded";
    }
    


