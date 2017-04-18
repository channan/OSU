/**************************************
 * Program name: recursionFunctions.cpp
 * Author: Cody Hannan
 * Date: 2/9/17
 * Description: Contains the recursive functions for the assignment.
 **************************************/

#include "recursionFunctions.hpp"
#include <iostream>

using std::string;
using std::cout;
using std::endl;

void reverse(string x) //reverses a string
{
    if(x.size()==0)
    {
        cout << "\n";
    }
    else
    {
        cout << x[x.size()-1]; //outputs the last character of the string
        x.erase((x.size()-1)); //deletes the last character
        reverse(x); //passes the string through the function again which is now down a character
    }
}

int sum(int array[], int size) //sums an array
{
    if(size==0)
    {
        return 0;
    }
    else
    {
        return array[size-1]+sum(array,size-1); //essentially counts down through the array and sums each value
    }
}

int triangleNum(int N) //calculates triangle number
{
    if(N==0)
    {
        return 0;
    }
    else
    {
        return N+triangleNum(N-1); //similar to sum but counts down from entered number and sums each value
    }
}
