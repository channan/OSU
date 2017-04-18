/**************************************
 * Program name: inputValidation.cpp
 * Author: Cody Hannan
 * Date: 2/9/17
 * Description: Checks user input and makes sure it fits given parameters. Contains if statements that follow a general
 * template to account for whether or not the value inputted by the user is of the right type and is within the correct
 * range.
 **************************************/

#include "inputValidation.hpp"
#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int inputValid(int min, int max, string variable) //min and max are used to establish a range of values and variable is used to differentiate each if statement since sometime a different output to the user might be needed depending on the what is being asked
{
    int input=0;
    string n,u;
    
    if(variable=="option") //used for validating the input when selecting menu option
    {
        cin >> input; //takes input
        
        while(cin.fail() || input < min || input > max) //while loop starts if its out of range or of the wrong type
        {
            if(cin.fail())
            {
                cout << "\nPlease enter an integer value" << endl; //prompts user for correct type
                cout << "Please select an option: ";
                cin.clear(); //clears the cin buffer
                cin.ignore(1000,'\n'); //ignores anything that is missed
                cin >> input; //takes a new input from the user
            }
            else if(input < min || input > max)
            {
                cout << "\nPlease enter a number between " << min << " and " << max << endl; //prompts user for correct range
                cout << "Please select an option: ";
                cin >> input;
            }
        }
    }
    
    if(variable=="triangle") //used for validating the input when inputting a number for the triangle function
    {
        cin >> input; //takes input
        
        while(cin.fail() || input < min || input > max) //while loop starts if its out of range or of the wrong type
        {
            if(cin.fail())
            {
                cout << "\nPlease enter an integer value" << endl; //prompts user for correct type
                cout << "Number: ";
                cin.clear(); //clears the cin buffer
                cin.ignore(1000,'\n'); //ignores anything that is missed
                cin >> input; //takes a new input from the user
            }
            else if(input < min || input > max)
            {
                cout << "\nPlease enter a number between " << min << " and " << max << endl; //prompts user for correct range
                cout << "Number: ";
                cin >> input;
            }
        }
    }

    return input;
}


