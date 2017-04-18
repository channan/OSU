/*******************************
 * Program Name: SouthRoom.cpp
 * Author: Cody Hannan
 * Date: 3/21/17
 * Description: Implementation file for south room. Contains unique descriptor and item.
 *******************************/

#include "SouthRoom.hpp"

string SouthRoom::itemPickup()
{
    if(grid[4*row/5][col/2]=='@' && pickedUp==0)
    {
        pickedUp++;
        return "Ruby";
    }
    else
    {
        return "";
    }
}

void SouthRoom::comment()
{
    cout << "I think I smell a ruby... must be on the other side of these walls..." << endl;
}

bool SouthRoom::leave()
{
    return false;
}
