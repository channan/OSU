/**************************************
 * Program name: menu.cpp
 * Author: Cody Hannan
 * Date: 2/9/17
 * Description: Displays menu options to the user.
 **************************************/

#include <iostream>
#include "menu.hpp"

using std::cout;
using std:: endl;

void menu()
{
    cout << "Recursion Functions Menu" << endl;
    cout << "1. Reverse a string." << endl;
    cout << "2. Sum the elements of an array." << endl;
    cout << "3. Find the triangle number of an integer" << endl;
    cout << "4. Exit program." << endl;
    cout << "Please select an option: ";
}
