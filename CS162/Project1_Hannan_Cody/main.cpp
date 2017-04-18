/***************************************************
 ** Program Name: main.cpp
 ** Author: Cody Hannan
 ** Date: 1/22/17
 ** Description: This is the main function. This is where the user is asked to input values for the different parameters that are needed for the playAnt function.
 ** It includes a menu and input validation methods.
 ****************************************************/

#include "playAnt.hpp"
#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    int arow=-1,acol=-1,brow=0,bcol=0,steps=0,placement=0,speed=0,choice=0;
    char direction='a';
    Compass dir;
    std::vector<int> storedChoices; //using to keep track of whether or not the user has entered values for all parameter before running the program.

    while (cin.fail()||(choice!=1&&choice!=2&&choice!=3&&choice!=4&&choice!=5&&choice!=6)) //input validation method. If the user enters a parameter outside of what is expected then this will continue to loop until they do.
    {
        //menu
        cout << "Welcome to Main Menu." << endl;
        cout << "1. Quit." << endl;
        cout << "2. Change board size." <<endl;
        cout << "3. Change ant start location and direction." << endl;
        cout << "4. Change ant steps." << endl;
        cout << "5. Change ant speed." << endl;
        cout << "6. Run Program." << endl;
        cout << "Menu option choice: ";
        cin >> choice;
        cout << endl;
    
        if(cin.fail()) //accounts for if the user enters a non int value
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Please enter integer values." << endl <<endl;
            continue;
        }
        if((choice!=1&&choice!=2&&choice!=3&&choice!=4&&choice!=5&&choice!=6)) //account for enters a number that isnt a menu option.
        {
            //cin.clear();
            //cin.ignore(1000, '\n');
            cout << "Please enter an integer that corresponds to what is shown for the menu options" << endl << endl;
        }
        
        switch(choice) //takes users menu choice and takes them to that area to enter the parameters or run the program
        {
            case 1: //quits program
            {
                break; //skips everything an ends the program
            }
            
            case 2: //board rows and columns
            {
                //resets value so that while loop will start and new values can be entered
                brow=0;
                bcol=0;
                
                while(cin.fail()||brow<3||bcol<3)//input validation method. Accounts for non integers and min size
                {
                    cout << "Please enter the number of rows and columns for the field." << endl;
                    cout << "Rows: ";
                    cin >> brow;
                    cout << "Columns: ";
                    cin >> bcol;
                    cout << endl;
        
                    if(cin.fail()) //accounts for non ints
                    {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "Please enter integer values." << endl << endl;
                        continue;
                    }
                    if(brow<2||bcol<2) //accounts for too small of a board
                    {
                        cout << "Please enter values that are 2 or more." << endl << endl;
                    }
                }
                storedChoices.push_back(2); //stores that this menu option was selected
                choice=0; //resets choice value so that menu loop repeats
                break;
            }
    
            case 3: //changing ant starting coordinates and direction
            {
                
                //resets value so that while loop will start and new values can be entered
                arow=-1;
                acol=-1;
                placement=0;
                direction='a';

                while(cin.fail()||(placement!=1&&placement!=2)) //user input validation method. Accounts for non integer inputs and if user enter a 1 or a 2.
                {
                    cout << "Would you like to manually place the ant or have it be randomly placed?" << endl;
                    cout << "Manual [1] or Random [2]: ";
                    cin >> placement;
                    cout << endl;
        
                    if(cin.fail()) //accounts for non ints
                    {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "Please enter either integer 1 to manually place the ant or integer 2 to randomly place the ant." << endl <<endl;
                        continue;
                    }
                    if((placement!=1&&placement!=2)) //account for if the user doesn't enter a 1 or a 2
                    {
                        cout << "Please enter either integer 1 to manually place the ant or integer 2 to randomly place the ant." << endl << endl;
                    }
                }
    
                //if the user chose manual placement
                if(placement==1)
                {
                    while(cin.fail()||arow<1||acol<1||arow>brow-2||acol>bcol-2) //user input validation method. Accounts for the user entering non integer values and values that are no within the bounds of the previously set field parameters
                    {
                        cout << "Please enter the row and column values for where you'd like the ant to start." << endl;
                        cout << "Row: ";
                        cin >> arow;
                        cout << "Column: ";
                        cin >> acol;
                        cout << endl;
            
                        if(cin.fail()) //checks for non int values
                        {
                            cin.clear();
                            cin.ignore(1000, '\n');
                            cout << "Please enter integer values." << endl << endl;
                            continue;
                        }
            
                        if(arow<1||acol<1||arow>brow-2||acol>bcol-2) //checks for values outside of field bounds
                        {
                            cout<<"Please enter non negative integers that are at least a space away from the edge of the board."<<endl<<endl;
                        }
                    }
                }
                
                //if user chose random placement -- randomly places ant
                else
                {
                    srand(time(0));
                    arow = rand() % (brow -2);
                    acol = rand() % (bcol -2);
                }
                
                
                while(direction!='n'&&direction!='s'&&direction!='e'&&direction!='w') //user input validation method to account for when the user does not enter a direction with the proper syntax.
                {
                    cout << "What will be the ant's starting direction?" << endl;
                    cout << "North[n], South[s], East[e], or West[w]: ";
                    cin >> direction;
                    cout << endl;
              
                    //sets dir based on entered value
                    if(direction=='n')
                    {
                        dir=west; //when ant is placed playAnt check its direction and moves it based on what space it started in (which should be white), so it turns left right away. This makes it appear that its entered dir is east when north is what was entered. This accounts for that and makes the ant move the way the user would expect based on what value was entered.
                    }
                    else if(direction=='s')
                    {
                        dir=east;
                    }
                    else if(direction=='e')
                    {
                        dir=north;
                    }
                    else if(direction=='w')
                    {
                        dir=south;
                    }
                    else //if user didn't enter the proper value
                    {
                        cout<<"Please enter either n, s, e, or w for north, south, east, and west respectively." << endl << endl;
                    }
                }
                storedChoices.push_back(3); //stores that this menu option was selected
                choice=0; //resets choice value so that menu loop repeats
                break;
            }

            case 4: //changes how many steps ant takes
            {
                //resets value so that while loop will start and new values can be entered
                steps=0;
                
                while(cin.fail()||steps<1) //user input validation method. Account for user non entering an int value and not entering at least 1 step
                {
                    cout << "How many steps would you like the ant to take?" << endl;
                    cout << "Steps: ";
                    cin >> steps;
                    cout << endl;
        
                    if(cin.fail()) //accounts for non int values
                    {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "Please only enter an integer value." << endl<<endl;
                        continue;
                    }
        
                    if(steps<1) //acounts for not entering at least one step
                    {
                        cout<<"Please enter only non negative values that are a least 1."<<endl<<endl;
                    }
                }
                storedChoices.push_back(4); //stores that this menu option was selected
                choice=0; //resets choice value so that loop repeats
                break;
            }
    
            case 5: //changes speed that ant moves
            {
                speed=0;
                
                while(cin.fail()||speed<20) //user input validation method. Account for user non entering an int value and not entering at least 1 millisecond.

                {
                    cout << "At what speed would you like the ant to move?" << endl;
                    cout << "Milliseconds between each move: ";
                    cin >> speed;
                    cout <<endl;
        
                    if(cin.fail()) //accounts for when non ints are entered
                    {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "Please only enter an integer value." << endl <<endl;
                        continue;
                    }
        
                    if(speed<20) //accounts for speeds that are too fast
                    {
                        cout<<"Please enter only non negative values that are a least 20."<<endl<<endl;
                    }
                }
                storedChoices.push_back(5); //records that this menu option had been chosen
                choice=0; //reset choice value so that menu loop can repeat
                break;
            }
    
            case 6: //runs program once other parameters are set
            {
                int antrow=arow,antcol=acol,boardrow=brow,boardcol=bcol,antsteps=steps,time=speed,twos=0,threes=0,fours=0,fives=0;
                Compass facing=dir;
                
                //checks how many time other menu options were entered
                for(int i=0;i<storedChoices.size();i++)
                {
                    if(storedChoices[i]==2)
                    {
                        twos++;
                    }
                    if(storedChoices[i]==3)
                    {
                        threes++;
                    }
                    if(storedChoices[i]==4)
                    {
                        fours++;
                    }
                    if(storedChoices[i]==5)
                    {
                        fives++;
                    }
                }
                
                if(twos>0&&threes>0&&fours>0&&fives>0) //if menu options have been entered at least once then all parameters should be set and program should be ready to run
                {
                playAnt(antrow,antcol,boardrow,boardcol,facing,antsteps,time);
                }
                
                else //otherwise user is told to finish entering all parameters
                {
                    cout << "Please finish entering all parameters before trying to run the program." << endl << endl;
                }
                
                choice=0; //resets choice value to restart menu loop
                break;
            }
                
        }
    }
    return 0;
}
