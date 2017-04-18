/****************************************************
 * Program Name: menu.cpp
 * Author: Cody Hannan
 * Date: 1/29/17
 * Description: This is the game menu. Simply outputs the options to the user so they can see what their options are.
 ******************************************************/

#include "menu.hpp"
#include <iostream>

using std::cout;
using std::endl;

void menu()
{
    cout << "MAIN MENU" << endl;
    cout << "1. Number of sides on die." << endl;
    cout << "2. Type of die." << endl;
    cout << "3. Number of rounds." << endl;
    cout << "4. Play." << endl;
    cout << "5. Quit." << endl;
    cout << "Please select an option: ";
}
