/**********************
 * Program Name: HarryPotter.hpp
 * Author: Cody Hannan
 * Date: 2/20/17
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
};

#endif /* HarryPotter_hpp */
