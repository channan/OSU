/**********************
 * Program Name: Medusa.hpp
 * Author: Cody Hannan
 * Date: 2/20/17
 * Description: Contains function prototypes for child class Medusa. 
 ************************/

#ifndef Medusa_hpp
#define Medusa_hpp

#include "Creature.hpp"

class Medusa:public Creature
{
public:
    Medusa(int a,int s): Creature(a,s) //same contructor as creature is used here, so we copy creature's contructor
    {}
    virtual int attack();
    virtual int defense();
};

#endif /* Medusa_hpp */
