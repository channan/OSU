/**********************
 * Program Name: NumberList.cpp
 * Author: Cody Hannan
 * Date: 2/19/17
 * Description: Contains functions for adding elements, removing elements, and displaying the list, as well as returning
 * values for the head node and tail node.
 ************************/

#include "NumberList.hpp"
#include <iostream>

using std::cout;

void NumberList::add(double number) //adds a new element to the end of the list
{
    if(head==NULL) //list is empty
    {
        head = new ListNode(number);
    }
    
    else //list is not empty. Uses nodePtr to traverse the list
    {
        ListNode *nodePtr = head;
        while (nodePtr->next != NULL)
        {
            nodePtr=nodePtr->next; //nodePtr->next is nullptr so nodePtr points to the last node.
        }
        nodePtr->next = new ListNode(number); //creates a new node and puts it after the last node
    }
}

void NumberList::remove(double number) //removes a number from a list
{
    ListNode *nodePtr, *previousNodePtr;
    
    if(!head) //if the list is empty, nothing happens
    {
        return;
    }
    
    if(head->value==number) //determine if the first node is the one to delete
    {
        nodePtr = head;
        head = head->next;
        delete nodePtr;
    }
    
    else
    {
        nodePtr = head; //sets the nodePtr to the head of the list
        
        while(nodePtr != NULL && nodePtr->value != number) //skips nodes whose value member is not a number
        {
            previousNodePtr = nodePtr;
            nodePtr = nodePtr->next;
        }
        
        if(nodePtr) //link the previous node to the node after nodePtr, then delete nodePtr
        {
            previousNodePtr->next = nodePtr->next;
            delete nodePtr;
        }
    }
}

void NumberList::displayList() const //outputs a sequence of all values currently stored in the list
{
    ListNode *nodePtr=head; //start at head of list
    while(nodePtr)
    {
        cout << nodePtr->value << "  "; //print the value in the current node
        nodePtr=nodePtr->next; //move on to the next node
    }
}

NumberList::~NumberList() //deallocates the memory used by the list
{
    ListNode *nodePtr=head; //start at head of list
    while (nodePtr != NULL)
    {
        ListNode *garbage = nodePtr; //garbage keeps track of node to be deleted
        nodePtr = nodePtr->next; //move on to next node
        delete garbage;
    }
}

double NumberList::getHeadNode() //returns head node value
{
    ListNode *nodePtr=head;
    return nodePtr->value;
}

double NumberList::getTailNode() //returns tail node value
{
    ListNode *nodePtr=head,*previousNodePtr;
    while(nodePtr)
    {
        previousNodePtr=nodePtr;
        nodePtr=nodePtr->next;
    }
    return previousNodePtr->value;
}
