/**********************
 * Program Name: Palindrome.cpp
 * Author: Cody Hannan
 * Date: 3/12/17
 * Description: Acts as a stack. Contains functions for adding elements and removing elements.
 ************************/

#include "Palindrome.hpp"
#include <iostream>

void Palindrome::push(char letter) //adds character to stack
{
    top=new StackNode(letter, top);
}

char Palindrome::pop() //removes character from stack
{
    StackNode *temp;
    char letter;
    
    if(isEmpty())
    {
        return ' ';
    }
    else
    {
        letter=top->letter; //value from top of stack is removed
        temp=top;
        top=top->next;
        delete temp;
        
        return letter; //function returns removed character
    }
}

bool Palindrome::isEmpty() const //checks is stack is empty
{
    return top==NULL;
}

Palindrome::~Palindrome() //destructor deallocates nodes
{
    StackNode * garbage = top;
    while (garbage!=NULL)
    {
        top=top->next;
        garbage->next=NULL;
        delete garbage;
        garbage=top;
    }
}
