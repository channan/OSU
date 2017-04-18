/*************************************
 * Program Name: FibonacciNonRecursive.hpp
 * Author: Cody Hannan
 * Date: 3/18/17
 * Description: Copied from https://www.codeproject.com/tips/109443/fibonacci-recursive-and-non-recursive-c, this is the
 * header file for the FibonacciNonRecursive class and contains the class's function protoypes.
 ************************************/


#ifndef FIBONACCINONRECURSIVE_HPP
#define FIBONACCINONRECURSIVE_HPP

class FibonacciNonRecursive
{
public:
    FibonacciNonRecursive(const int &n);
    virtual ~FibonacciNonRecursive();
    void PrintFibonacci();
private:
    FibonacciNonRecursive();
    int Fibonacci(const int &n);
    const int* n_;
};
#endif
