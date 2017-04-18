/**********************
 * Program Name: Barbarian.hpp
 * Author: Cody Hannan
 * Date: 3/5/17
 * Description: Contains function prototypes for child class Barbarian. 
 ************************/

#ifndef Barbarian_hpp
#define Barbarian_hpp

#include "Creature.hpp"

class Barbarian:public Creature
{
public:
    Barbarian(int a,int s): Creature(a,s) //same contructor as creature is used here, so we copy creature's contructor
    {}
    virtual int attack();
    virtual int defense();
    virtual string getName();
};

#endif /* Barbarian_hpp */
