/**********************
 * Program Name: Palindrome.hpp
 * Author: Cody Hannan
 * Date: 3/12/17
 * Description: Contains the protoypes for the Palindrome class and also is where the StackNode struct is defined.
 ************************/

#ifndef Palindrome_hpp
#define Palindrome_hpp

#include <stdio.h>

class Palindrome
{
protected:
    struct StackNode //class for StackNode which links each node as each one is created
    {
        char letter;
        StackNode *next;
        StackNode(char letter1, StackNode *next1=NULL)//contructor for the StackNode class
        {
            letter=letter1;
            next=next1;
        }
    };
    StackNode *top;
public:
    Palindrome()
    {
        top=NULL;
    }
    ~Palindrome();
    void push(char);
    char pop();
    bool isEmpty() const;
};

#endif 
