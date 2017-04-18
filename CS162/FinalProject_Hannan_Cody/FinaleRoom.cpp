/*******************************
 * Program Name: FinaleRoom.cpp
 * Author: Cody Hannan
 * Date: 3/21/17
 * Description: Implementation file for finale room. Contains unique descriptor and item.
 *******************************/

#include "FinaleRoom.hpp"

string FinaleRoom::itemPickup()
{
    if(grid[row/2][col/2]=='@' && pickedUp==0)
    {
        pickedUp++;
        return "Idol";
    }
    else
    {
        return "";
    }
}

void FinaleRoom::comment()
{
    cout << "Wow and I thought the central chamber was something. Whats that at the center?" << endl;
    cout << "...Is that the artifact?!" << endl;
}

bool FinaleRoom::leave()
{
    return false;
}
