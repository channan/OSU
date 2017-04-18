/************************************
 * Program name: inputValidation.cpp
 * Author: Cody Hannan
 * Date: 2/26/17
 * Description: Contains validation methods for user inputs.
 ***********************************/

#include "inputValidation.hpp"
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;

int inputValid(int min, int max, string variable) //variable is used to differentiate each if statement since sometime a different output to the user might be needed depending on the what is being asked
{
    int input=0;
    
    if(variable=="option") //used for validating the input when selecting menu option
    {
        cin >> input; //takes input
        
        while(cin.fail()||input<min||input>max) //while loop starts if value is of the wrong type
        {
            if(cin.fail())
            {
                cout << "\nPlease enter an integer value: "; //prompts user for correct type
                cin.clear(); //clears the cin buffer
                cin.ignore(1000,'\n'); //ignores anything that is missed
                cin >> input; //takes a new input from the user

            }
            if(input<min||input>max)
            {
                cout << "\nPlease enter a value between " << min << " and " << max << ": ";
                cin >> input;
            }
        }
    }
    
    if(variable=="number") //used for validating the input when inputting a number
    {
        cin >> input; //takes input
        
        while(cin.fail()||input<min||input>max) //while loop starts if value is of the wrong type
        {
            if(cin.fail())
            {
                cout << "\nPlease enter an integer value: "; //prompts user for correct type
                cin.clear(); //clears the cin buffer
                cin.ignore(1000,'\n'); //ignores anything that is missed
                cin >> input; //takes a new input from the user
                
            }
            if(input<min||input>max)
            {
                cout << "\nPlease enter a value between " << min << " and " << max << ": ";
                cin >> input;
            }
        }
    }

    
    return input;//returns the input after it has passed its respective checks
}
