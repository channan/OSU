/***************************************************
 ** Program Name: Ant.hpp
 ** Author: Cody Hannan
 ** Date: 1/22/17
 ** Description: This is the header file for the Ant class. It contains the the private variables for the row and columns of the 2d array as well as a double
 ** pointer to the 2d array, boardArray. In public, it contains the constructor and destructor as well as the function prototypes that are defined in Ant.cpp.
 ****************************************************/

#ifndef ANT_HPP
#define ANT_HPP

enum Compass {north,south,east,west}; //enum for keeping track of what direction the ant is facing.

class Ant
{
private:
    int row;
    int col;
    char **boardArray; //double pointer the place in memory that contains the board values
    
public:
    Ant(int, int); //allocates memory for 2d array and initializes board
    ~Ant(); //deallocates allocated memory
    void printBoard(int); //displays board to the user
    char setAntBoard(int,int,Compass); //places ant on the board
    void antTrail(int,int,char); //keeps track of what state of cells should be in the ants trail
};

#endif
