/******************************************
 * Program Name: Building.hpp
 * Author: Cody Hannan
 * Date: 2/5/17
 * Description: Header file for the building class. Contains function prototypes for the implementation file.
 ******************************************/

#ifndef BUILDING_HPP
#define BUILDING_HPP

#include <string>

using std::string;

class Building
{
private:
    string name;
    double size;
    string address;
public:
    Building(string,double,string);
    string getName();
    double getSize();
    string getAddress();
};

#endif
