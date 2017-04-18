/**********************
 * Program Name: NumberList.hpp
 * Author: Cody Hannan
 * Date: 2/19/17
 * Description: Contains the function prototypes for the NumberList class. Also contains the declaration and definition of
 * struct class ListNode.
 ************************/

#ifndef NumberList_hpp
#define NumberList_hpp

#include <stdio.h>

class NumberList //declares a class for the list node
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
    NumberList() //constructor for the NumberList class
    {
        head=NULL;
    }
    ~NumberList(); //destructor
    void add(double number);
    void remove(double number);
    void displayList() const;
    double getHeadNode();
    double getTailNode();
};

#endif 
