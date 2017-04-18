/************************************
 * Program name: inputValidation.cpp
 * Author: Cody Hannan
 * Date: 2/19/17
 * Description: Contains validation methods for user inputs.
 ***********************************/

#include "inputValidation.hpp"
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;

double inputValid(string variable) //variable is used to differentiate each if statement since sometime a different output to the user might be needed depending on the what is being asked
{
    double input=0;
    
    if(variable=="number") //used for validating the input when selecting menu option
    {
        cin >> input; //takes input
        
        while(cin.fail()) //while loop starts if value is of the wrong type
        {
            cout << "\nPlease enter a double value: "; //prompts user for correct type
            cin.clear(); //clears the cin buffer
            cin.ignore(1000,'\n'); //ignores anything that is missed
            cin >> input; //takes a new input from the user
        }
    }
    
    return input;//returns the input after it has passed its respective checks
}
