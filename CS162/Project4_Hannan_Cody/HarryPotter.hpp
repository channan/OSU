/**********************
 * Program Name: HarryPotter.hpp
 * Author: Cody Hannan
 * Date: 3/5/17
 * Description: Contains function prototypes for child class HarryPotter.
 ************************/

#ifndef HarryPotter_hpp
#define HarryPotter_hpp

#include "Creature.hpp"

class HarryPotter:public Creature
{
public:
    HarryPotter(int a,int s): Creature(a,s) //same contructor as creature is used here, so we copy creature's contructor
    {}
    virtual int attack();
    virtual int defense();
    virtual string getName();
    int count=0;
};

#endif /* HarryPotter_hpp */
