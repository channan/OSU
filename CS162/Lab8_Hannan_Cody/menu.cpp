/*****************************
 * Program Name: menu.cpp
 * Author: Cody Hannan
 * Date: 3/5/17
 * Description: menu options that when called are displayed to the user.
 *******************************/

#include "menu.hpp"
#include <iostream>

using std::cout;
using std::endl;

void menu()
{
    cout << "Welcome to the functions menu!" << endl;
    cout << "1. Search for 0 integer." << endl;
    cout << "2. Sort." << endl;
    cout << "3. Binary search for 0 integer." << endl;
    cout << "4. Exit program." << endl;
    cout << "Menu selection: ";
}
