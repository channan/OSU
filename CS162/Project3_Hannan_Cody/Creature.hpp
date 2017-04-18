/**********************
 * Program Name: Creature.hpp
 * Author: Cody Hannan
 * Date: 2/20/17
 * Description: Contains function prototypes for Creature base class. 
 ************************/

#ifndef CREATURE_HPP
#define CREATURE_HPP

class Creature
{
protected:
    int armor;
    int strength;
public:
    Creature(int,int);
    virtual int attack()=0; //pure virtual functions will be overwritten by child classes
    virtual int defense()=0;
    int getArmor();
    int getStrength();
    void setStrength(int);
};

#endif
