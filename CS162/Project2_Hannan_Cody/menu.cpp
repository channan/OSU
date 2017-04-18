/*************************************
 * Program Name: menu.cpp
 * Author: Cody Hannan
 * Date: 2/5/17
 * Description: This is the menu function. Contains menu options that will be displayed to user.
 ************************************/

#include "menu.hpp"
#include <iostream>

using std::cout;
using std::endl;

void menu()
{
    cout << "Shopping List Menu." << endl;
    cout << "1. Add an item." << endl;
    cout << "2. Remove an item." << endl;
    cout << "3. Display current list." << endl;
    cout << "4. Quit program." << endl;
    cout << "Please select an option: ";
}
