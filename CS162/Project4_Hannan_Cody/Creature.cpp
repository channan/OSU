/**********************
 * Program Name: Creature.cpp
 * Author: Cody Hannan
 * Date: 3/5/17
 * Description: Contains functions for creature class.
 ************************/

#include "Creature.hpp"

Creature::Creature(int a,int s) //constructor for armor and strength
{
    armor=a;
    strength=s;
}
int Creature::getArmor() //getter functions
{
    return armor;
}
int Creature::getStrength()
{
    return strength;
}
void Creature::setStrength(int s) //setter function for strength
{
    strength=s;
}
