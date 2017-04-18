/*****************************
 * Program Name: menu.cpp
 * Author: Cody Hannan
 * Date: 2/26/17
 * Description: Contains menu that is displayed to user
 ***************************/

#include "menu.hpp"
#include <iostream>

using std::cout;
using std::endl;

void menu()
{
    cout << "Queue Menu." << endl;
    cout << "1. Enter a value to be added to the queue." << endl;
    cout << "2. Display first node (front) value." << endl;
    cout << "3. Remove first node (front) value." << endl;
    cout << "4. Display the queue contents." << endl;
    cout << "5. Exit program." << endl;
    cout << "Please select an option: ";
}
