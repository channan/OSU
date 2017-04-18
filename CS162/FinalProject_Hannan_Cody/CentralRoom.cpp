/*******************************
 * Program Name: CenterRoom.cpp
 * Author: Cody Hannan
 * Date: 3/21/17
 * Description: Implementation file for central room. Contains unique descriptor and function for leaving.
 *******************************/

#include "CentralRoom.hpp"

string CentralRoom::itemPickup()
{
    return "";
}

void CentralRoom::comment()
{
    cout << "Wow what a chamber! Hmm four passage ways..." << endl;
    cout << "Some of the less fearful locals said there might be a major artifact down here..." << endl;
    cout << "If I need to leave, I should be able to use the staircase I came down on." << endl;
}

bool CentralRoom::leave()
{
    if(grid[row/2][col/2]=='@')
    {
        cout << "\nLet's get out of here..." << endl;
        return true;
    }
    else
    {
        return false;
    }
}
