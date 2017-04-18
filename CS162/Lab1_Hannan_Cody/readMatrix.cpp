/********************************************
 ** Program name: readMatrix.cpp
 ** Author: Cody Hannan
 ** Date: 1/15/17
 ** Description: Cpp file for the readMatrix function. Asks user for matrix values and then stores those
 ** values in a 2D array.
 ********************************************/

#include "readMatrix.hpp"
#include <iostream>
#include <cmath> //needed for sqrt 

using std::cout;
using std::cin;
using std::endl;

void readMatrix(int **array, int size)
{
    cout << "Please enter " << size << " numbers to populate the matrix." << endl; //asks user to enter matrix values
    
    for(int i=0;i<sqrt(size);i++)
    {
        for(int j=0;j<sqrt(size);j++)
        {
            cin >> array[i][j]; //entered values are stored in 2D array
        }
    }
}

