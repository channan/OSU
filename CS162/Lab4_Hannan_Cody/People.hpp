/******************************************
 * Program Name: People.hpp
 * Author: Cody Hannan
 * Date: 2/5/17
 * Description: Header file for the people class. Contains function prototypes for the implementation file. 
 ******************************************/

#ifndef PEOPLE_HPP
#define PEOPLE_HPP

#include <string>
#include <cstdlib>

using std::string;

class People
{
protected: //variables can be used by inherited classes
    string name;
    int age;
    //int hours;
public:
    People(string);
    string getName();
    int getAge();
    virtual void getGPA(); //function is also in student class
    virtual void getRating(); //function is also in instructor class
    virtual void doWork(int); //function is in both student and instructor inherited classes
};

#endif
