/**********************
 * Program Name: Fight.cpp
 * Author: Cody Hannan
 * Date: 3/5/17
 * Description: Contains functions for initializing the fighters and determining the winner.
 ************************/

#include "Fight.hpp"
#include "Creature.hpp"
#include <string>
#include <cstdlib>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

int target,health1,health2,damage1,damage2;

Fight::Fight(string fighter1, string fighter2) //allocated memory for fighter 1 and 2
{
    if(fighter1=="Vampire")
    {
        ptr1 = new Vampire(1,18);
    }
        
    if(fighter1=="Barbarian")
    {
        ptr1 = new Barbarian(0,12);
    }
        
    if(fighter1=="BlueMen")
    {
        ptr1 = new BlueMen(3,12);
    }
        
    if(fighter1=="Medusa")
    {
        ptr1 = new Medusa(3,8);
    }
        
    if(fighter1=="HarryPotter")
    {
        ptr1 = new HarryPotter(0,10);
    }
        
    if(fighter2=="Vampire")
    {
        ptr2 = new Vampire(1,18);
    }
        
    if(fighter2=="Barbarian")
    {
        ptr2 = new Barbarian(0,12);
    }
        
    if(fighter2=="BlueMen")
    {
        ptr2 = new BlueMen(3,12);
    }
        
    if(fighter2=="Medusa")
    {
        ptr2 = new Medusa(3,8);
    }
        
    if(fighter2=="HarryPotter")
    {
        ptr2 = new HarryPotter(0,10);
    }
}

Fight::~Fight() //deallocates memory when program finishes
{
    delete ptr1;
    delete ptr2;
}

int Fight::winner() //determines the winner
{
    while(ptr1->getStrength()>0 && ptr2->getStrength()>0)
    {
        target=rand() % 2 + 1; //determines who attacks
        
        if(target==2)
        {
            cout << "Fighter 1: " << ptr1->getName() << " attacks" << endl;
            damage2=ptr1->attack()-ptr2->defense()-ptr2->getArmor();
            if(damage2<0)
            {
                damage2=0;
            }
            ptr2->setStrength(ptr2->getStrength()-damage2);
            cout << "Fighter 2: " << ptr2->getName() << " strength is now " << ptr2->getStrength() << endl;
            ptr2->defense();
        }
        else
        {
            cout << "Fighter 2: " << ptr2->getName() << " attacks" << endl;
            damage1=ptr2->attack()-ptr1->defense()-ptr1->getArmor();
            if(damage1<0)
            {
                damage1=0;
            }
            ptr1->setStrength(ptr1->getStrength()-damage1);
            cout << "Fighter 1: " << ptr1->getName() << " strength is now " << ptr1->getStrength() << endl;
            ptr1->defense();
        }
    }
    
    if(ptr1->getStrength()<=0) //returns the winner
    {
        return 2;
    }
    else if(ptr2->getStrength()<=0)
    {
        return 1;
    }
    
    return 0;
}





