/********************************************
 ** Program name: determinant.cpp
 ** Author: Cody Hannan
 ** Date: 1/15/17
 ** Description: Cpp file for the determinant function. Calculates the determinant of the 2D array that is passed to it.
 ********************************************/

#include "determinant.hpp"

int determinant(int **array,int size) 
{
    if (size==4) //if user entered array is 2x2 then those coordinates are checked and the determinant is calculated
    {
        int a=array[0][0], b=array[0][1], c=array[1][0], d=array[1][1];
        return a*d-b*c;
    }
    
    else //otherwise its a 3x3 array, in which case those coordinates are checked and the determinant is calculated
    {
        int a=array[0][0], b=array[0][1], c=array[0][2], d=array[1][0], e=array[1][1], f=array[1][2], g=array[2][0], h=array[2][1], i=array[2][2];
        return a*e*i+b*f*g+c*d*h-c*e*g-b*d*i-a*f*h;
    }
}

