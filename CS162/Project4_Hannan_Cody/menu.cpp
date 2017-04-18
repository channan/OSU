/**********************
 * Program Name: menu.cpp
 * Author: Cody Hannan
 * Date: 3/5/17
 * Description: Menu that is displayed to the user
 ************************/

#include "menu.hpp"
#include <iostream>

using std::cout;
using std::endl;

void mainMenu()
{
    cout << "Welcome to Fantasy Combat!" << endl;
    cout << "1. Battle two fighters." << endl;
    cout << "2. Setup tournament" << endl;
    cout << "3. Run tournament." << endl;
    cout << "4. Display fallen fighters." << endl;
    cout << "5. Exit program." << endl;
    cout << "Select a menu option: ";
}

void fightersMenu()
{
    cout << "\nChoose your fighters!" << endl;
    cout << "Your choices are: " << endl;
    cout << "Vampire" << endl;
    cout << "Barbarian" << endl;
    cout << "BlueMen" << endl;
    cout << "Medusa" << endl;
    cout << "HarryPotter" << endl;
}
