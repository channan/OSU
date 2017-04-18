/**********************
 * Program Name: Fight.hpp
 * Author: Cody Hannan
 * Date: 3/5/17
 * Description: Contains function prototypes for the fight class. Also is where the private creature class pointer variables
 * are defined.
 ************************/

#ifndef Fight_hpp
#define Fight_hpp

#include <string>
#include "Creature.hpp"
#include "Vampire.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"

using std::string;

class Fight
{
private:
    Creature *ptr1; //initializes creature pointers. since we dont know which fighter the user will pick
    Creature *ptr2;
public:
    Fight(string,string);
    ~Fight();
    int winner();
    
};

#endif
