/******************************************
 * Program Name: Instructor.cpp
 * Author: Cody Hannan
 * Date: 2/5/17
 * Description: Instructor class implementation file. Mostly information is stored here. The constructor copies the people constructor and inits another value for rating. The do work function outputs how much work the instructor did.
 ******************************************/

#include "Instructor.hpp"
#include <iostream>

using std::cout;
using std::endl;

Instructor::Instructor(string n):People(n) //copies contructor from people class
{
    rating = (rand() % 501)/100; //generates random number for rating
}
void Instructor::getRating()
{
    cout << "   Rating: " << rating << endl << endl;
}
void Instructor::doWork(int h) //takes random parameter to determine how much work instructor did
{
    cout << "Instructor " << name << " graded papers for " << h << " hours." << endl << endl;
}

