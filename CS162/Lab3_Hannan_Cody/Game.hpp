/****************************************************
 * Program Name: Game.hpp
 * Author: Cody Hannan
 * Date: 1/29/17
 * Description: This is the header file for the Game class. Main things that occur here are the private variables are set
 * including the pointers to the Die classes and the score vector is initialized.
 ******************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "LoadedDie.hpp"
#include <vector>

using std::vector;

class Game
{
private:
    int rounds;
    vector<int> score; //stores winner of each round
    Die *p1Ptr; //player one pointer to Die class
    Die *p2Ptr; //player two pointer to Die class
    
public:
    Game()
    {
        vector<int> score; //score vector is initialized in constructor
    }
    Game(int,int,int,int,int); //prototype where user entered parameters to run the game are used to initialize the game.
    ~Game(); //destructor where deallocation of allocated memory takes place
    void play();
    void results();
};

#endif
