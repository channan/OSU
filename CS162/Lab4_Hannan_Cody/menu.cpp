/******************************************
 * Program Name: menu.cpp
 * Author: Cody Hannan
 * Date: 2/5/17
 * Description: menu function. Displays menu to the user.
 ******************************************/

#include "menu.hpp"
#include <iostream>

using std::cout;
using std::endl;

void menu()
{
    cout << " Database." << endl;
    cout << "1. Display building information." << endl;
    cout << "2. Display student and instructor information." << endl;
    cout << "3. Choose a person to do work." << endl;
    cout << "4. Exit program." << endl;
    cout << "Please select an option: ";
}
