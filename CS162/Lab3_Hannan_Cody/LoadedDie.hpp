/****************************************************
 * Program Name: LoadedDie.hpp
 * Author: Cody Hannan
 * Date: 1/29/17
 * Description: This is the header file for the LoadedDie class which contains the class's function prototypes.
 ******************************************************/

#ifndef LOADEDDIE_HPP
#define LOADEDDIE_HPP

#include <string>
#include "Die.hpp"

using std::string;

class LoadedDie: public Die //function is derived from the Die class. This connects them and now we can use Die's protected variable and inherit its functions
{
public:
    LoadedDie():Die() //we copy Die's constructor since they are the same
    {}
    LoadedDie(int);
    int roll();
    string getType();
};

#endif

