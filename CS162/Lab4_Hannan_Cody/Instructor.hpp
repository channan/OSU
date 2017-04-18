/******************************************
 * Program Name: Instructor.hpp
 * Author: Cody Hannan
 * Date: 2/5/17
 * Description: Header file for the building class. Contains function prototypes for the implementation file.
 ******************************************/

#ifndef INSTRUCTOR_HPP
#define INSTRUCTOR_HPP

#include "People.hpp"
#include <string>

using std::string;

class Instructor: public People //inherits functions from people class
{
private:
    double rating;
public:
    Instructor(string);
    void getRating();
    void doWork(int);
};

#endif
