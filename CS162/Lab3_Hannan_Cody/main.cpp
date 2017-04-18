/****************************************************
 * Program Name: main.cpp
 * Author: Cody Hannan
 * Date: 1/29/17
 * Description: This is where the user input is primarily done. The program asks for die sides, type of die, and how many
 * rounds. It then runs the game and outputs the results.
 ******************************************************/

#include <iostream>
#include "Game.hpp"
#include "menu.hpp"
#include "inputValidation.hpp"
#include <vector> //used for keeping track of what menu options have been used
#include <cstdlib> //needed for srand
#include <ctime>

using std::cout;
using std::endl;
using std::cin;
using std::vector;

int main()
{
    int s1,s2,r,l1,l2,option;
    vector<int> previous;
    srand(time(0)); //needed for rand in the die classes
    
    while(option !=5) //if user enters 5 it ends the program
    {
        menu(); //displays menu options
        option=inputValid(1,5,"option"); //checks what user enters
        cout << endl;
        
        if(option == 1) //asks for how many sides each die will have
        {
            s1=0;
            s2=0;
            cout << "How many sides will player one's die have?" << endl;
            cout << "Sides: ";
            s1=inputValid(4,120,"sides"); //validates input
            cout << endl;
            cout << "How many sides will player two's die have?" << endl;
            cout << "Sides: ";
            s2=inputValid(4,120,"sides"); //validates input
            cout << endl;
            previous.push_back(option); //records that this option has been selected.
        }
        if(option ==2) //asks if die is loaded
        {
            l1=0;
            l2=0;
            cout << "Will player one's die be loaded? (1=yes and 0=no)" << endl;
            cout << "Loaded?: ";
            l1=inputValid(0,1,"loaded"); //checks input
            cout << endl;
            cout << "Will player two's die be loaded? (1=yes and 0=no)" << endl;
            cout << "Loaded?: ";
            l2=inputValid(0,1,"loaded"); //checks input
            cout << endl;
            previous.push_back(option); //records that this option has been selected
        }
        if(option == 3) //asks for how many rounds
        {
            r=0;
            cout << "How many rounds do you want the game to last?" << endl;
            cout << "Rounds: ";
            r=inputValid(1,10000,"rounds"); //checks input
            cout << endl;
            previous.push_back(option); //records that option has been selected.
        }
        if(option == 4) //runs game
        {
            int ones=0,twos=0,threes=0;
            
            //tallies each menu option that was recorded
            for(int i=0;i<previous.size();i++)
            {
                if(previous[i]==1)
                {
                    ones++;
                }
                if(previous[i]==2)
                {
                    twos++;
                }
                if(previous[i]==3)
                {
                    threes++;
                }
            }
            
            if(ones!=0&&twos!=0&&threes!=0) //checks that all options have been selected at least once
            {
                Game war(s1,s2,l1,l2,r); //initializes game
                war.play(); //runs game
                war.results(); //displays results to user
            }
            else
            {
                cout << "Please finish setting the game parameters before selecting play." << endl;
                cout << endl;
            }
        }
    }
    return 0;
}

