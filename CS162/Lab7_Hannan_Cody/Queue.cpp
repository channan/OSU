/********************************
 * Program Name: Queue.cpp
 * Author: Cody Hannan
 * Date: 2/26/17
 * Description: Implementation file for Queue class. Defines function from header file, which includes the functions for queue operations.
 ********************************/

#include "Queue.hpp"
#include <iostream>

using std::cout;
using std::endl;

Queue::Queue() //initializes queue
{
    front=NULL;
    back=front;
    prev=front;
}

Queue::~Queue() //deallocates memory upon exit of program
{
    QueueNode *nodePtr=front;
    for(int i=0;i<nodeCounter;i++)
    {
        QueueNode *garbage=nodePtr;
        nodePtr=nodePtr->next;
        delete garbage;
    }
}

void Queue::addBack(int num) //adds value to back of queue
{
    if(empty()&&nodeCounter==0) //checks if queue is empty and is if no other nodes have been made
    {
        front=new QueueNode(num); //if so creates new node
        back=front;
        prev=front;
        nodeCounter++;
    }
    else if(prev->value==-1) //checks if queue has a sentinel
    {
        back=back->next; //back takes previous front space
        back->value=num; //new value is assigned
    }
    else
    {
        back->next=new QueueNode(num); //inits new node
        prev=back; //saves previous node
        back=back->next; //back equals new node
        back->next=front; //back is linked to the front
        nodeCounter++; //adds 1 to node counter
    }
    counter++; //keeps track for display
}

void Queue::removeFront() //empties front node value
{
    if(empty()) //checks is empty
    {
        cout << "The queue is empty.\n";
    }
    else
    {
        front->value=-1; //set value to -1
        prev=front; //saves in previous
        front=front->next; //moves front to next value
        counter--; //decrements counter for display
    }
}

bool Queue::empty() const //checks if queue is empty
{
    if(front==NULL)
    {
        return true;
    }
    else if(front->value==-1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Queue::displayList() const //outputs a sequence of all values currently stored in the list
{
    QueueNode *nodePtr=front; //starts at front of queue
    
    if(empty())
    {
        cout << "The queue is empty.\n";
    }
    else
    {
        cout << "The values in the queue are:" << endl;
        
        for(int i=0;i<counter;i++)
        {
            cout << nodePtr->value << "  "; //print the value in the current node
            nodePtr=nodePtr->next; //move on to the next node
        }
        cout << endl;
    }
}

void Queue::getFront() const //displays the value at the front of the queue
{
    QueueNode *nodePtr=front;
    cout << "The value at the front is: " << nodePtr->value << endl;
}
