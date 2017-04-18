/*******************************
 * Program Name: WestRoom.cpp
 * Author: Cody Hannan
 * Date: 3/21/17
 * Description: Implementation file for west room. Contains unique descriptor and item.
 *******************************/

#include "WestRoom.hpp"

string WestRoom::itemPickup()
{
    if(grid[row/3][col/3]=='@' && pickedUp==0)
    {
        pickedUp++;
        return "Emerald";
    }
    else
    {
        return "";
    }
}

void WestRoom::comment()
{
    cout << "Wow look at all the the Emeralds! Wait... most of these look fake..." << endl;
    cout << "I wonder which one is the real one?" << endl;
}

bool WestRoom::leave()
{
    return false;
}
