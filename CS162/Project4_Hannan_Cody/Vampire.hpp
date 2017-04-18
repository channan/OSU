/**********************
 * Program Name: Vampire.hpp
 * Author: Cody Hannan
 * Date: 3/5/17
 * Description: Contains function prototypes for child class Vampire.
 ************************/

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include "Creature.hpp"

class Vampire:public Creature
{
public:
    Vampire(int a,int s): Creature(a,s) //same contructor as creature is used here, so we copy creature's contructor
    {}
    virtual int attack();
    virtual int defense();
    virtual string getName();
};

#endif
