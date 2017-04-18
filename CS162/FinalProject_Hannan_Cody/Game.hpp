/*******************************
 * Program Name: Game.hpp
 * Author: Cody Hannan
 * Date: 3/21/17
 * Description: Functions prototype for Game.cpp and class declaration.
 *******************************/

#ifndef Game_hpp
#define Game_hpp

#include "Room.hpp"
#include "WestRoom.hpp"
#include "CentralRoom.hpp"
#include "NorthRoom.hpp"
#include "EastRoom.hpp"
#include "SouthRoom.hpp"
#include "OpenNorthRoom.hpp"
#include "FinaleRoom.hpp"
#include <vector>
#include <iostream>

using std::vector;
using std::cin;

class Game
{
private:
    Room *center = new CentralRoom;
    Room *west = new WestRoom;
    Room *east = new EastRoom;
    Room *north = new NorthRoom;
    Room *openNorth = new OpenNorthRoom;
    Room *south = new SouthRoom;
    Room *finale = new FinaleRoom;
    Room *currentRoom;
    vector<string> inventory;
public:
    Game() //links room together using Room functions
    {
        //center room
        center->setLeft(west);
        center->setRight(east);
        center->setUp(north);
        center->setDown(south);
        
        //west room
        west->setRight(center);
        
        //east room
        east->setLeft(center);
        
        //south room
        south->setUp(center);
        
        //north room
        north->setUp(finale);
        north->setDown(center);
        
        //finale room
        finale->setDown(north);
    }
    ~Game()
    {
        delete center;
        delete west;
        delete east;
        delete north;
        delete openNorth;
        delete south;
        delete finale;
        //delete currentRoom;
    }
    
    void play();
    void menu();
    void displayInv();
    int checkInv();
};

#endif /* Game_hpp */
