/********************************************
 ** Program name: main.cpp
 ** Author: Cody Hannan
 ** Date: 1/15/17
 ** Description: The main function. Utilizes readMatrix and determinant functions to take a user entered 2x2 or 3x3 matrix
 ** and calculate its determinant. It also displays the contents of the matrix and its corresponding determinant value to
 ** the user.
 ********************************************/

#include "readMatrix.hpp"
#include "determinant.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    int size, det;
    
    //asks user for the size of the matrix
    cout << "Please enter the size of the matrix: 4 for 2x2 and 9 for 3x3." << endl;
    cin >> size;
    
    if (size==4 || size==9)
    {
        
        //allocates space for 2D array in memory
        int **array;
        array = new int*[3];
        for(int i = 0; i < 3; ++i)
        {
            array[i] = new int[3];
        }

        readMatrix(array,size); //asks for matrix values and stores them in 2D array
        
        cout << "Matrix:" << endl;
        
        if (size==4) //displays 2x2 matrix values to user
        {
            cout << array[0][0] << "\t" << array[0][1] << endl;
            cout << array[1][0] << "\t" << array[1][1] << endl;
        }
    
        if (size==9) //displays 3x3 matrix values to user
        {
            cout << array[0][0] << "\t" << array[0][1] << "\t" << array[0][2] << endl;
            cout << array[1][0] << "\t" << array[1][1] << "\t" << array[1][2] << endl;
            cout << array[2][0] << "\t" << array[2][1] << "\t" << array[2][2] << endl;
        }

        det=determinant(array,size); //calculates determinant of matrix
        cout << "Determinant: " << det << endl; //displays value to user
        
        //deallocates space for 2D array in memory to avoid memory leaks
        for(int i = 0; i < 3; ++i)
        {
            delete [] array[i];
        }
        delete [] array;
    }
    
    //if user doesn't enter a square matrix an error is displayed 
    else
    {
        cout << "Error: what you entered is not a square matrix." << endl;
    }
        return 0;
}
