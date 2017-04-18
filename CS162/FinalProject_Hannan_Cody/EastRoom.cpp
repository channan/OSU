/*******************************
 * Program Name: EastRoom.cpp
 * Author: Cody Hannan
 * Date: 3/21/17
 * Description: Implementation file for east room. Contains unique descriptor and item.
 *******************************/

#include "EastRoom.hpp"

string EastRoom::itemPickup()
{
    if(grid[3*row/4][col/3]=='@' && pickedUp==0)
    {
        pickedUp++;
        return "Sapphire";
    }
    else
    {
        return "";
    }
}

void EastRoom::comment()
{
    cout << "Lot's of Sapphires... looks like most aren't the real deal..." << endl;
    cout << "Maybe there's a real one on the other side of these walls..." << endl;
}

bool EastRoom::leave()
{
    return false;
}
