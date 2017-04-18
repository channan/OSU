/******************************************
 * Program Name: Student.hpp
 * Author: Cody Hannan
 * Date: 2/5/17
 * Description: Header file for the student class. Contains function prototypes for the implementation file.
 ******************************************/

#ifndef STUDENT_HPP
#define STUDENT_HPP

#include "People.hpp"
#include <string>

using std::string;

class Student: public People //inherited public functions from People class
{
private:
    double gpa;
public:
    Student(string);
    void getGPA();
    void doWork(int);
};

#endif
