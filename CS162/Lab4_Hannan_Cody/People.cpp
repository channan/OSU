/******************************************
 * Program Name: People.cpp
 * Author: Cody Hannan
 * Date: 2/5/17
 * Description: People class implementation file. Mostly information is stored here, so the function consist of getter functions. The constructor uses parameter for name to initialize its persons name. Age is random.
 ******************************************/

#include "People.hpp"
#include <iostream>

using std::cout;


People::People(string n)
{
    name=n;
    age = rand() % 47 + 18; //outputs random number between 18 and 65
}

//getter functions
string People::getName()
{
    return name;
}
int People::getAge()
{
    return age;
}
void People::getGPA()
{
    cout << ""; //is overwritten by students fucntion
}
void People::getRating()
{
    cout << ""; //is overwritten by students function
}
void People::doWork(int h) //do work function is called again in inherited classes
{}

