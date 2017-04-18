/**********************
 * Program Name: Buffer.cpp
 * Author: Cody Hannan
 * Date: 3/12/17
 * Description: Acts as a queue. Contains functions for adding elements, removing elements, and displaying the list, as well
 * as returning values for the head node.
 ************************/

#include "Buffer.hpp"
#include <iostream>
#include <cstdlib>

using std::cout;

void Buffer::add(int number) //adds a new element to the end of the list
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
            nodePtr=nodePtr->next; //nodePtr->next is NULL so nodePtr points to the last node.
        }
        nodePtr->next = new ListNode(number); //creates a new node and puts it after the last node
    }
}

void Buffer::remove(int number) //removes a number from a list
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

void Buffer::displayList() const //outputs a sequence of all values currently stored in the list
{
    ListNode *nodePtr=head; //start at head of list
    while(nodePtr)
    {
        cout << nodePtr->value << "  "; //print the value in the current node
        nodePtr=nodePtr->next; //move on to the next node
    }
}

int Buffer::length()  //outputs a sequence of all values currently stored in the list
{
    ListNode *nodePtr=head;
    int i=0;
    
    while(nodePtr)
    {
        nodePtr=nodePtr->next; //move on to the next node
        i++;
    }
    return i;
}

void Buffer::randomNumAdd(int chance)
{
    int num;
    
    if(chance > (rand() % 100)) //if randome value is below user entered percentage then a random value is added to buffer
    {
        num = rand() % 1000;
        this->add(num);
    }
}

void Buffer::randomNumRemove(int chance)
{
    int num;
    
    if(chance > (rand() % 100)) //if random value is below user entered percentage then value at head node is removed.
    {
        num=this->getHeadNode();
        this->remove(num);
    }
}

void Buffer::clearBuffer() //deallocates the memory used by the list
{
    while(this->getHeadNode())
    {
        this->remove(this->getHeadNode());
    }
}

Buffer::~Buffer() //deallocates the memory used by the list
{
    ListNode *nodePtr=head; //start at head of list
    while (nodePtr != NULL)
    {
        ListNode *garbage = nodePtr; //garbage keeps track of node to be deleted
        nodePtr = nodePtr->next; //move on to next node
        delete garbage;
    }
}


int Buffer::getHeadNode() //returns head node value
{
    ListNode *nodePtr=head;
    
    if(nodePtr==NULL)
    {
        return NULL;
    }
    else
    {
        return nodePtr->value;
    }
}
