/*********************************
 * Program Name: FibonacciRecursive.hpp
 * Author: Cody Hannan
 * Date: 3/18/17
 * Description: Copied from https://www.codeproject.com/tips/109443/fibonacci-recursive-and-non-recursive-c, this is the
 * header file for the FibonacciRecursive class and contains the class's function protoypes.
 **********************************/

#ifndef FIBONACCIRECURSIVE_HPP
#define FIBONACCIRECURSIVE_HPP

class FibonacciRecursive
{
public:
    FibonacciRecursive(const int &n);
    virtual ~FibonacciRecursive();
    void PrintFibonacci();
private:
    FibonacciRecursive();
    int Fibonacci(const int &n);
    const int *n_;
};

#endif
