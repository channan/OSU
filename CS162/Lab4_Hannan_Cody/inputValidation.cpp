/************************************
 * Program name: inputValidation.cpp
 * Author: Cody Hannan
 * Date: 2/5/17
 * Description: Contains validation methods for user inputs.
 ***********************************/

#include "inputValidation.hpp"
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;

double inputValid(int min, int max, string variable) //min and max are used to establish a range of values and variable is used to differentiate each if statement since sometime a different output to the user might be needed depending on the what is being asked
{
    double input=0;
    string n,u;
    
    if(variable=="option") //used for validating the input when selecting menu option
    {
        cin >> input; //takes input
        
        while(cin.fail() || input < min || input > max) //while loop starts if its out of range or of the wrong type
        {
            if(cin.fail())
            {
                cout << "Please enter an integer value" << endl; //prompts user for correct type
                cout << "Please select an option: ";
                cin.clear(); //clears the cin buffer
                cin.ignore(1000,'\n'); //ignores anything that is missed
                cin >> input; //takes a new input from the user
                cout << endl;
            }
            else if(input < min || input > max)
            {
                cout << "Please enter a number between " << min << " and " << max << endl; //prompts user for correct range
                cout << "Please select an option: ";
                cin >> input;
                cout << endl;
            }
        }
    }
    
    return input;//returns the input after it has passed its respective checks
}
