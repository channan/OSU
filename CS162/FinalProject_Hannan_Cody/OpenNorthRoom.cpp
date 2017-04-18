/*******************************
 * Program Name: OpenNorthRoom.cpp
 * Author: Cody Hannan
 * Date: 3/21/17
 * Description: Implementation file for opened north room. Contains unique descriptor and item.
 *******************************/

#include "OpenNorthRoom.hpp"

string OpenNorthRoom::itemPickup()
{
    return "";
}

void OpenNorthRoom::comment()
{
    cout << "Looks like that door has opened on the other side..." << endl;
}

bool OpenNorthRoom::leave()
{
    return false;
}
