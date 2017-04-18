/******************************************
 * Program Name: University.hpp
 * Author: Cody Hannan
 * Date: 2/5/17
 * Description: The header file for the University class. Contains the function prototypes for the implementation file. Contains vector of pointers for buildings and another for people.
 ******************************************/

#ifndef UNIVERSITY_HPP
#define UNIVERSITY_HPP

#include <vector>
#include <string>
#include <iostream>
#include "Building.hpp"
#include "People.hpp"

using std::vector;
using std::string;
using std::cout;

class University
{
private:
    vector <Building*> buildings; //vector that building pointers are stored in
    vector <People*> people; //vector that people pointers are stored in
    string name;
    int peopleSize=0;
public:
    University() //constructor that names the database after the relevant university
    {
        cout << "Oregon State University" ;
    }
    void printBuildings();
    void printPeople();
    void addStudent(People*);
    void addInstructor(People*);
    void addBuildings(Building*);
    void work();
};

#endif
