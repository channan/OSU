/***************************************************
 ** Program Name: playAnt.cpp
 ** Author: Cody Hannan
 ** Date: 1/22/17
 ** Description: This is the function for playAnt.cpp that executes the ant's behaviors and uses the Ant class functions to display each step and change the cells
 ** in its trail.
 ****************************************************/

#include "playAnt.hpp"
#include <iostream>

using std::cout;
using std::endl;


void playAnt(int arow, int acol, int brow, int bcol, Compass dir, int steps, int speed)
{
    Ant a1(brow,bcol); //initializes the board
    
    for(int i=0;i<steps;i++) //for loop the will essentially animate the ant's movement. Takes user entered steps to determine number of cycles.
    {
    
        char state=a1.setAntBoard(arow,acol,dir); //place ant on the board and returned value is the state of the cell before the ant was placed.
        int prow=arow; //saves what row ant is placed in
        int pcol=acol; //saves what column ant is placed in
        
        //if statements that account for when the ant tries to move out of the array -- turns around
        if(arow==0&&dir==north)
        {
            dir=south;
            arow++;
        }
        else if(arow==(brow-1)&&dir==south)
        {
            dir=north;
            arow--;
        }
        else if(acol==0&&dir==west)
        {
            dir=east;
            acol++;
        }
        else if(acol==(bcol-1)&&dir==east)
        {
            dir=west;
            acol--;
        }
        
        //direction changes for when the ant walks on a "white" space -- turns right
        else if (state == '.')
        {
            switch (dir)
            {
                case north:
                    dir = east;
                    acol++;
                    break;
                case east:
                    dir = south;
                    arow++;
                    break;
                case south:
                    dir = west;
                    acol--;
                    break;
                case west:
                    dir = north;
                    arow--;
                    break;
            }
        }
        
        //direction changes for when the ant walks on a "black" space -- turns left
        else if(state=='#')
        {
            switch(dir)
            {
                case north:
                    dir = west;
                    acol--;
                    break;
                case west:
                    dir = south;
                    arow++;
                    break;
                case south:
                    dir = east;
                    acol++;
                    break;
                case east:
                    dir = north;
                    arow--;
                    break;
            }
        }
    a1.printBoard(speed); //displays current state of board to the user. User input speed allows user to change how quickly each step displays
    a1.antTrail(prow,pcol,state); //uses values for initial ant placement and what the state was before the ant to determine what color the cell should change to once the ant leaves the space.
    }
}
