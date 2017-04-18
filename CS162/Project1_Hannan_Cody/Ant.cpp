/***************************************************
 ** Program Name: Ant.cpp
 ** Author: Cody Hannan
 ** Date: 1/22/17
 ** Description: This is the board.cpp file. It contains a contructor that allocates memory for a 2d array and inits the board, a print function to display the
 ** current state of the board to the user, a destructor for deallocating the array to combat any memory leaks, a function for placing the ant, and another that
 ** changes the state of cells its previously been in.
 ****************************************************/

#include "Ant.hpp"
#include <iostream>
#include <thread> //needed for this_thread::sleep_for
#include <chrono> //needed for chrono::milliseconds()

using std::endl;
using std::cout;

Ant::Ant(int x, int y) //takes user input for initializing the rows and columns of the field within which the ant will move.
{
    row=x;
    col=y;
    
    boardArray=new char*[x]; //allocates space within memory for the 2d array that will be used to store values for the current state of the board.
    for(int i=0;i<x;i++)
    {
        boardArray[i]=new char[y];
    }
    
    for(int i=0;i<row;i++) //initializes board to be "blank"
    {
        for(int j=0;j<col;j++)
        {
            boardArray[i][j]='.';
        }
    }
}

void Ant::printBoard(int speed) //prints the current state of the board. Uses a user inputted value for speed that controls how much time there is in between each output to the user.
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cout << boardArray[i][j];
        }
        cout << endl;
    }
    cout << endl;
    
    std::this_thread::sleep_for (std::chrono::milliseconds(speed)); //the function that controls speed in milliseconds. Uses the thread and chrono libraries
    
}

Ant::~Ant() //destructor for board. Handles any memory leaks due to allocating space in memory in contructor.
{
    for(int i = 0; i < col; ++i)
    {
        delete [] boardArray[i];
    }
    delete [] boardArray;
}

char Ant::setAntBoard(int row,int col, Compass dir) //uses user inputted coordinate values to place the ant within the initialized board along with starting direction.
{
    char state;
    
    state=boardArray[row][col]; //records the previous state of the cell before the ant is placed.
    boardArray[row][col]='*';
    
    return state; //returns what use to be the state of the cell before the ant was placed.
}

void Ant::antTrail(int row, int col, char state) //changes the state of the cell where the ant last was. Uses values that were recorded before the ant was in the cell to determine what the state of the cell should after the ant leaves.
{
    if(state=='.')
    {
        boardArray[row][col]='#';
    }
    else if(state=='#')
    {
        boardArray[row][col]='.';
    }
}
