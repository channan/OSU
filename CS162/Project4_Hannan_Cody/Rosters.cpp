/**********************
 * Program Name: Rosters.cpp
 * Author: Cody Hannan
 * Date: 3/5/17
 * Description: Contains functions for adding elements, removing elements, and displaying the list, as well as returning
 * member names for the head node.
 ************************/

#include "Rosters.hpp"
#include <iostream>

using std::cout;
using std::endl;

void Rosters::add(string fighter) //adds a new element to the end of the list
{
    if(fighter=="Vampire")
    {
        character = new Vampire(1,18);
    }
    
    if(fighter=="Barbarian")
    {
        character = new Barbarian(0,12);
    }
    
    if(fighter=="BlueMen")
    {
        character = new BlueMen(3,12);
    }
    
    if(fighter=="Medusa")
    {
        character = new Medusa(3,8);
    }
    
    if(fighter=="HarryPotter")
    {
        character = new HarryPotter(0,10);
    }
    
    if(head==NULL) //list is empty
    {
        head = new ListNode(character);
    }
    
    else //list is not empty. Uses nodePtr to traverse the list
    {
        ListNode *nodePtr = head;
        while (nodePtr->next != NULL)
        {
            nodePtr=nodePtr->next; //nodePtr->next is nullptr so nodePtr points to the last node.
        }
        
        nodePtr->next = new ListNode(character); //creates a new node and puts it after the last node
    }
}

void Rosters::remove(string fighter) //removes a number from a list
{
    ListNode *nodePtr, *previousNodePtr;
    
    if(!head) //if the list is empty, nothing happens
    {
        return;
    }
    
    if((head->creature)->getName()==fighter) //determine if the first node is the one to delete
    {
        nodePtr = head;
        head = head->next;
        delete nodePtr->creature;
        delete nodePtr;
    }
    
    else
    {
        nodePtr = head; //sets the nodePtr to the head of the list
        
        while(nodePtr != NULL && nodePtr->creature->getName() != fighter) //skips nodes whose value member is not a number
        {
            previousNodePtr = nodePtr;
            nodePtr = nodePtr->next;
        }
        
        if(nodePtr) //link the previous node to the node after nodePtr, then delete nodePtr
        {
            previousNodePtr->next = nodePtr->next;
            delete nodePtr->creature;
            delete nodePtr;
        }
    }
}

void Rosters::frontToBack(string fighter) //removes a number from a list
{
    ListNode *nodePtr, *previousNodePtr;
    
    if(!head) //if the list is empty, nothing happens
    {
        return;
    }
    
    if(head->creature->getName()==fighter) //determine if the first node is the one to delete
    {
        nodePtr = head;
        head = head->next;
        delete nodePtr->creature;
        delete nodePtr;
        add(fighter);
    }
    
    else
    {
        nodePtr = head; //sets the nodePtr to the head of the list
        
        while(nodePtr != NULL && nodePtr->creature->getName() != fighter) //skips nodes whose value member is not a number
        {
            previousNodePtr = nodePtr;
            nodePtr = nodePtr->next;
        }
        
        if(nodePtr) //link the previous node to the node after nodePtr, then delete nodePtr
        {
            previousNodePtr->next = nodePtr->next;
            delete nodePtr->creature;
            delete nodePtr;
            add(fighter);
            
        }
    }
}

void Rosters::displayList() const //outputs a sequence of all values currently stored in the list
{
    ListNode *nodePtr=head; //start at head of list
    while(nodePtr)
    {
        cout << nodePtr->creature->getName() << endl; //print the value in the current node
        nodePtr=nodePtr->next; //move on to the next node
    }
}

Rosters::~Rosters() //deallocates the memory used by the list
{
    ListNode *nodePtr=head; //start at head of list
    while (nodePtr != NULL)
    {
        ListNode *garbage = nodePtr; //garbage keeps track of node to be deleted
        nodePtr = nodePtr->next; //move on to next node
        delete garbage->creature;
        delete garbage;
    }
    
    delete character;
}

string Rosters::getHeadNode() //returns head node value
{
    ListNode *nodePtr=head;
    return nodePtr->creature->getName();
}

bool Rosters::empty() const //checks if queue is empty
{
    if(head==NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
