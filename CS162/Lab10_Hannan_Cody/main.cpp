/***********************************
 * Program Name: main.cpp
 * Author: Cody Hannan
 * Date: 3/18/17
 * Description: Copied from https://www.codeproject.com/tips/109443/fibonacci-recursive-and-non-recursive-c, this file calls
 * the functions for recursive and non recursive loops for returning values from the fibonacci sequence as well as methods
 * for measuring calculation time using inspiration from http://www.cplusplus.com/reference/ctime/clock/.
 ***********************************/


#include <iostream>
#include <stdlib.h>
#include "FibonacciRecursive.hpp"
#include "FibonacciNonRecursive.hpp"
#include <time.h>      
#include <math.h>

using namespace std;
void Usage()
{
    cout<<"Correct Usage:"<<endl;
    cout<<"./Fibonacci [n]"<<endl;
}
int main()
{
    try
    {
        clock_t t1,t2;
        
        int n=10;
        cout<<"Finding '"<<n<<"'th "<<"fibonacci number...."<<endl;
        
        //outputs corresponding fibonacci number using a recursive method and displays the calculation time
        t1=clock();
        cout<<"\nCalling Recursive Fibonacci implementation"<<endl;
        FibonacciRecursive fr(n);
        fr.PrintFibonacci();
        t1=clock()-t1;
        cout << "This function took " << t1/1000000.0 << " seconds to complete." << endl;
        
        //outputs corresponding fibonacci number using a non recursive method and displays the calculation time
        t2=clock();
        cout<<"\nCalling Non-Recursive Fibonacci implementation"<<endl;
        FibonacciNonRecursive fnr(n);
        fnr.PrintFibonacci();
        t2=clock()-t2;
        cout << "This function took " << t2/1000000.0 << " seconds to complete." << endl << endl;
        
        cout << "Done!!!!" << endl;
        return 0;
    }
    catch(...)
    {
        cout<<"Oops an error occured! Please check usage"<<endl;
        Usage();
        return 1;
    }
}
