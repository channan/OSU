/**********************
 * Program Name: menu.cpp
 * Author: Cody Hannan
 * Date: 3/12/17
 * Description: Contains the menu information that is displayed to the user.
 ************************/

#include "menu.hpp"
#include <iostream>

using std::cout;
using std::endl;

void menu()
{
    cout << "Test Menu." << endl;
    cout << "1. Buffer." << endl;
    cout << "2. Palindrome." << endl;
    cout << "3. Exit Program." << endl;
    cout << "Select an option: ";
}
