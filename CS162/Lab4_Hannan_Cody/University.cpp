/******************************************
 * Program Name: University.cpp
 * Author: Cody Hannan
 * Date: 2/5/17
 * Description: Primary functions are contained here. There are functions here for adding students, instructors, and buildings to the system as well as printing what buildings and people are in the system. There is also a work function for finding out how much work each person did.
 ******************************************/

#include "University.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include "inputValidation.hpp"

using std::cout;
using std::endl;
using std::string;
using std::cin;
using std::ofstream;

void University::printBuildings() //displays buildings to user
{
    for (int i=0;i<buildings.size();i++)
    {
        cout << i+1 << ". Name: " << buildings[i]->getName() << endl;
        cout << "   Size: " << buildings[i]->getSize() << " sq-ft" << endl;
        cout << "   Address: " << buildings[i]->getAddress() << endl << endl;
    }
}
void University::printPeople() //displays people to user
{
    for (int i=0;i<people.size();i++)
    {
        cout << i+1 << ". Name: " << people[i]->getName() << endl;
        cout << "   Age: " << people[i]->getAge() << endl;
        people[i]->getGPA();
        people[i]->getRating();
    }
}
void University::addStudent(People* s) //adds a student to the people vector
{
    people.push_back(s);
}
void University::addInstructor(People* i) //adds an instructor to the people vector
{
    people.push_back(i);
}
void University::addBuildings(Building* b) //adds a building to the buildings vector
{
    buildings.push_back(b);
}
void University::work() //initiates workTime variable and displays a sub menu to the user for selecting who did work
{
    int choice;
    int workTime = rand() % 1001;
    
    for (int i=0;i<people.size();i++)
    {
        cout << i+1 << ". " << people[i]->getName() << endl;
    }
    cout << "Select someone to do work: ";
    choice=inputValid(1,people.size(),"option");
    cout << endl;
    
    people[choice-1]->doWork(workTime);
}
