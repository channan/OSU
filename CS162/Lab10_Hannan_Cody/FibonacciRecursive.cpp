/**********************************
 * Program Name: FibonacciRecursive.cpp
 * Author: Cody Hannan
 * Date: 3/18/17
 * Description: Copied from https://www.codeproject.com/tips/109443/fibonacci-recursive-and-non-recursive-c, this file
 * contains methods for calculating fibonacci values and displaying those values.
 *********************************/

#include "FibonacciRecursive.hpp"
#include <iostream>

FibonacciRecursive::FibonacciRecursive()
{}

FibonacciRecursive::FibonacciRecursive(const int &n):n_(&n)
{}

FibonacciRecursive::~FibonacciRecursive()
{}

int FibonacciRecursive::Fibonacci(const int &n)
{
    if(n==0)
    {
        return 0;
    }
    
    else if(n==1)
    {
        return 1;
    }
    
    return Fibonacci(n-1) + Fibonacci(n-2); //recursive loop that calculates the fibonacci number
}

void FibonacciRecursive::PrintFibonacci()
{
    int FibonaciNum=Fibonacci(*n_);
    std::cout << *n_ << "th fibonaci number: " << FibonaciNum << std::endl;
}
