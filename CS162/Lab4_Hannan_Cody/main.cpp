/******************************************
 * Program Name: main.cpp
 * Author: Cody Hannan
 * Date: 2/5/17
 * Description: This is the main function. The people and building are instatiated here and the menu is displayed so the user can make selections as to what they want to see displayed.
 ******************************************/

#include "University.hpp"
#include "People.hpp"
#include "Student.hpp"
#include "Instructor.hpp"
#include "menu.hpp"
#include <cstdlib>
#include <fstream>
#include "inputValidation.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::ofstream;

int main()
{
    srand(time(0)); //needed as a seed for when rand is called
    int option;
    
    while(option!=4) //if user selects option 4 then program ends
    {
        University osu; //university object is created
        menu(); //menu is displayed to user
        option=inputValid(1,4,"option");
        cout << endl;
        
        //building are instatiated and added to the system
        Building mcc("Milne Computer Center",23441,"1800 SW CAMPUS WAY CORVALLIS, OR 97331");
        Building ael("Aero Engineering Lab",3637,"852 SW 30TH STREET CORVALLIS, OR 97331");
        osu.addBuildings(&mcc);
        osu.addBuildings(&ael);
        
        //people are instatiated and added to the system
        Student s1("Bart Simpson");
        Instructor I1("Edna Krabappel");
        osu.addStudent(&s1);
        osu.addInstructor(&I1);
        
        if(option==1) //displays buildings in system
        {
            osu.printBuildings();
        }
        
        if(option==2) //displays people in system
        {
            osu.printPeople();
        }
        
        if(option==3) //brings up a sub menu to find out how many hours a student did homework or an instructor graded papers
        {
            osu.work();
        }
    }
    
    return 0;
}

                              
