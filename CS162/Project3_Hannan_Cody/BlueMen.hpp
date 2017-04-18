/**********************
 * Program Name: BlueMen.hpp
 * Author: Cody Hannan
 * Date: 2/20/17
 * Description: Contains function prototypes for child class BlueMen.  
 ************************/

#ifndef BlueMen_hpp
#define BlueMen_hpp

#include "Creature.hpp"

class BlueMen:public Creature
{
public:
    BlueMen(int a,int s): Creature(a,s) //same contructor as creature is used here, so we copy creature's contructor
    {}
    virtual int attack();
    virtual int defense();
};

#endif /* BlueMen_hpp */
