/*******************************
 * Program Name: NorthRoom.cpp
 * Author: Cody Hannan
 * Date: 3/21/17
 * Description: Implementation file for north room. Contains unique descriptor.
 *******************************/

#include "NorthRoom.hpp"

string NorthRoom::itemPickup()
{
    return "";
}

void NorthRoom::comment()
{
    cout << "This seems to be a main hallway to... somewhere..." << endl;
    cout << "There seems to be a door but it wont budge..." << endl;
    cout << "That certainly seems like a place to hide something valuable." << endl;
    cout << "There must be another way to open it... maybe I should check the other chambers." << endl;
}

bool NorthRoom::leave()
{
    return false;
}
