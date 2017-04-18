/**********************
 * Program Name: Fight.cpp
 * Author: Cody Hannan
 * Date: 2/20/17
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
    health1=ptr1->getStrength(); //gets health values
    health2=ptr2->getStrength();
    
    while(health1>0 && health2>0)
    {
        target=rand() % 2 + 1; //determines who attacks
        
        if(target==2)
        {
            cout << "Fighter one attacks" << endl;
            
        }
        else
        {
            cout << "Fighter two attacks" << endl;
        }

        damage1=ptr2->attack()-ptr1->defense()-ptr1->getArmor(); //determines the damage
        damage2=ptr1->attack()-ptr2->defense()-ptr2->getArmor();
        
        if(damage1<0)
        {
            damage1=0;
        }
        if(damage2<0)
        {
            damage2=0;
        }

        if(target==2)
        {
            health2=health2-damage2; //subtracts the damage from the fighters health
            ptr2->setStrength(health2);
            cout << "Fighter two strength is now " << health2 << endl;
        }
        else
        {
            health1=health1-damage1;
            ptr1->setStrength(health1);
            cout << "Fighter one strength is now " << health1 << endl;
        }
    }
    
    if(health1<=0) //returns the winner
    {
        return 2;
    }
    if(health2<=0)
    {
        return 1;
    }
    
    return 0;
}





