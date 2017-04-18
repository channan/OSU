/******************************************
 * Program Name: Student.cpp
 * Author: Cody Hannan
 * Date: 2/5/17
 * Description: Student class implementation file. Mostly information is stored here. The constructor copies the people constructor and inits another value for GPA. The do work function outputs how much work the student did.
 ******************************************/

#include "Student.hpp"
#include <iostream>

using std::cout;
using std::endl;

Student::Student(string n):People(n) //copies contructor from people class
{
    gpa = (rand() % 401)/100; //outputs random gpa
}
void Student::getGPA()
{
    cout << "   GPA: " << gpa << endl << endl;
}
void Student::doWork(int h) //takes random parameter to determine work done by student
{
    cout << name << " did " << h << " hours of homework." << endl << endl;
}

