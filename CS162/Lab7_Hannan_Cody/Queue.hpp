/**********************************
 * Program Name: Queue.hpp
 * Author: Cody Hannan
 * Date: 2/26/17
 * Description: Header file for Queue class. Contains the function prototypes for queue operations and defines the QueueNode struct within its private section
 *************************/

#ifndef Queue_hpp
#define Queue_hpp

#include <stdio.h>

class Queue
{
private:
    struct QueueNode //defines QueueNode
    {
        int value;
        QueueNode *next;
        QueueNode(int value1, QueueNode *next1=NULL)
        {
            value=value1;
            next=next1;
        }
    };
    QueueNode *front;
    QueueNode *back;
    QueueNode *prev;
    int counter=0;
    int nodeCounter=0;
public:
    Queue(); //constructor
    ~Queue(); //destructor
    void addBack(int);
    void removeFront();
    bool empty() const;
    void displayList() const;
    void getFront() const; //getter function
};

#endif /* Queue_hpp */
