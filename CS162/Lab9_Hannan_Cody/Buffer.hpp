/**********************
 * Program Name: NumberList.hpp
 * Author: Cody Hannan
 * Date: 3/12/17
 * Description: Contains the function prototypes for the buffer class. Also contains the declaration and definition of
 * struct class ListNode.
 ************************/

#ifndef Buffer_hpp
#define Buffer_hpp

#include <stdio.h>

class Buffer //declares a class for the list node
{
protected:
    struct ListNode //declares a class for the list node
    {
        double value;
        ListNode *next;
        ListNode(double value1, ListNode *next1=NULL) //constructor for the list node class
        {
            value=value1;
            next=next1;
        }
    };
    ListNode *head; //list head pointer
public:
    Buffer() //constructor for the NumberList class
    {
        head=NULL;
    }
    ~Buffer(); //destructor
    void add(int);
    void remove(int);
    void displayList() const;
    void randomNumAdd(int);
    void randomNumRemove(int);
    int length();
    int getHeadNode();
    void clearBuffer();
};

#endif
