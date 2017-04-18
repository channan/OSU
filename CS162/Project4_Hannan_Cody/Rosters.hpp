/**********************
 * Program Name: Rosters.hpp
 * Author: Cody Hannan
 * Date: 3/5/17
 * Description: Contains the function prototypes for the Rosters class. Also contains the declaration and definition of
 * struct class ListNode.
 ************************/

#ifndef Rosters_hpp
#define Rosters_hpp

#include "Creature.hpp"
#include "Vampire.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"

class Rosters //declares a class for the list node
{
protected:
    struct ListNode //declares a class for the list node
    {
        Creature *creature;
        ListNode *next;
        ListNode(Creature *fighter, ListNode *next1=NULL) //constructor for the list node class
        {
            creature=fighter;
            next=next1;
        }
    };
    ListNode *head;
    Creature *character;
public:
    Rosters() //constructor for the Rosters class
    {
        head=NULL;
    }
    ~Rosters(); //destructor
    void add(string);
    void remove(string);
    void frontToBack(string);
    void displayList() const;
    string getHeadNode();
    bool empty() const;
};

#endif
