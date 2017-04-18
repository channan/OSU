/**********************
 * Program Name: BlueMen.hpp
 * Author: Cody Hannan
 * Date: 3/5/17
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
    virtual string getName();
    int count1=0;
    int count2=0;
};

#endif /* BlueMen_hpp */
