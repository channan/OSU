/*********************************
 * Program Name: FibonacciNonRecursive.cpp
 * Author: Cody Hannan
 * Date: 3/18/17
 * Description: Copied from https://www.codeproject.com/tips/109443/fibonacci-recursive-and-non-recursive-c, this file
 * contains methods for calculating fibonacci values and displaying those values.
 *********************************/

#include "FibonacciNonRecursive.hpp"
#include <iostream>

FibonacciNonRecursive::FibonacciNonRecursive()
{}

FibonacciNonRecursive::FibonacciNonRecursive(const int &n):n_(&n)
{}

FibonacciNonRecursive::~FibonacciNonRecursive()
{}

int FibonacciNonRecursive::Fibonacci(const int &n)
{
    int first =0;
    int second=1;
    int counter=2;
    while(counter < n) //itirative loop for calculating fibonacci number
    {
        int temp=second;
        second=first+second;
        first=temp;
        ++counter;
    }
    if(n==0)
    {
        return 0;
    }
    else
    {
        return first+second;
    }
}
void FibonacciNonRecursive::PrintFibonacci()
{
    const int result = Fibonacci(*n_);
    std::cout << *n_ << "th fibonacci Number: " << result << std::endl;
}
