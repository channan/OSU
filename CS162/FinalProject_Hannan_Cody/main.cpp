/*******************************
 * Program Name: main.cpp
 * Author: Cody Hannan
 * Date: 3/21/17
 * Description: Displays opening message and title to user then creates game object and plays game
 *******************************/

#include <iostream>
#include "Room.hpp"
#include "Game.hpp"

int main()
{
    cout << "                   IT BELONGS IN A MUSEUM!!!!!     " << endl << endl;
    cout << "              Deep in the jungles of south america " << endl;
    cout << "            you find a temple tucked away in an area" << endl;
    cout << "            that the locals warned you not to go near." << endl;
    cout << "         You hear an echo or was it a voice? Following the" << endl;
    cout << "sounds, you find a long forgotten staircase covered in thick growth." << endl;
    cout << "                          You enter." << endl << endl << endl << endl;
    cout << "On the way down you think you hear something: '3 jewels open the way' " << endl; 
    cout << " There is something in the air. You can't stay down here for long." << endl << endl;
    
    Game game;
    game.play();
    
    return 0;
}
