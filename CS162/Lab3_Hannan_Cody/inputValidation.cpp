/****************************************************
 * Program Name: inputValidation.cpp
 * Author: Cody Hannan
 * Date: 1/29/17
 * Description: This is the function that is used to validate user inputs in case they enter something out of range or
 * something that is of the wrong type for a prompted parameter.
 ******************************************************/

#include "inputValidation.hpp"
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int inputValid(int min, int max, string variable) //min and max are used to establish a range of values and variable is used to differentiate each if statement since sometime a different output to the user might be needed depending on the what is being asked
{
    int input=0;
    
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
            }
            else if(input < min || input > max)
            {
                cout << "Please enter a number between " << min << " and " << max << endl; //prompts user for correct range
                cout << "Please select an option: ";
                cin >> input;
            }
        }
    }
    
    if(variable=="sides") //validates input when prompting user for sides of each die
    {
        cin >> input;
        
        while(cin.fail() || input < min || input > max)
        {
            if(cin.fail())
            {
                cout << "Please enter an integer value" << endl;
                cout << "Sides: ";
                cin.clear();
                cin.ignore(1000,'\n');
                cin >> input;
            }
            else if(input < min || input > max)
            {
                cout << "Please enter a number between " << min << " and " << max << endl;
                cout << "Sides: ";
                cin >> input;
            }
        }
    }
    
    if(variable=="loaded") //validates input when prompting user for the type of each die
    {
        cin >> input;
        
        while(cin.fail() || input < min || input > max)
        {
            if(cin.fail())
            {
                cout << "Please enter an integer value" << endl;
                cout << "Loaded?: ";
                cin.clear();
                cin.ignore(1000,'\n');
                cin >> input;
            }
            else if(input < min || input > max)
            {
                cout << "Please enter either " << min << " or " << max << endl;
                cout << "Loaded?: ";
                cin >> input;
            }
        }
    }
    if(variable=="rounds") //validates the input when how many rounds is asked of the user
    {
        cin >> input;
        
        while(cin.fail() || input < min || input > max)
        {
            if(cin.fail())
            {
                cout << "Please enter an integer value" << endl;
                cout << "Rounds: ";
                cin.clear();
                cin.ignore(1000,'\n');
                cin >> input;
            }
            else if(input < min || input > max)
            {
                cout << "Please enter a number between " << min << " and " << max << endl;
                cout << "Rounds: ";
                cin >> input;
            }
        }
    }
   return input; //returns the input after it has passed its respective checks
}
