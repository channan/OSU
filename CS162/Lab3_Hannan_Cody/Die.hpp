/****************************************************
 * Program Name: Die.hpp
 * Author: Cody Hannan
 * Date: 1/29/17
 * Description: This is the header file the Die class. This is the parent class of LoadedDie so some things needed to be set
 * up here for LoadedDie to be used effectively. Like using protected variables rather than private or using virtual
 * functions since they share similar functions but they work differently.
 ******************************************************/

#ifndef DIE_HPP
#define DIE_HPP

#include <string>

using std::string;

class Die
{
protected: //lets us use this variable in the derived LoadedDie class as well
    int sides;
    
public:
    Die() //default contructor initializes die with minimum number of sides
    {
        sides=4;
    }
    Die(int);
    virtual int roll(); //same function is in the LoadedDie class and virtual keeps any overwriting from occuring
    int getSides();
    virtual string getType(); //same function is in the LoadedDie class and virtual keeps any overwriting from occuring
    };

#endif
