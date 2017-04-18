/****************************************************
 * Program Name: Game.cpp
 * Author: Cody Hannan
 * Date: 1/29/17
 * Description: This is the implementation file for the Game class. It uses the user inputted parameters to create the Die
 * and LoadedDie objects. It runs the game for some number of rounds storing who wins each time in a vector. The results are
 * then displayed to the user.
 ******************************************************/

#include "Game.hpp"
#include <iostream>
#include <vector> //needed for storing who wins each round

using std::cout;
using std::endl;
using std::cin;

Game::Game(int s1,int s2, int l1, int l2, int r) //uses user input values to create the Die or LoadedDie classes and stores the number of rounds in a private variable.
    {
        if(l1==1)
        {
            p1Ptr = new LoadedDie(s1); //allocates memory for a LoadedDie object. The pointer is a private variable.
        }
        else
        {
            p1Ptr = new Die(s1);
        }
        if(l2==1)
        {
            p2Ptr = new LoadedDie(s2);
        }
        else
        {
            p2Ptr = new Die(s2);
        }
        rounds=r;
    }

Game:: ~Game() //deallocates the previously allocated memory to avoid memory leaks
{
    delete p1Ptr;
    delete p2Ptr;
}
    
void Game::play() //runs the game
    {
        int rollScore1,rollScore2;
        
        for(int i=0;i<rounds;i++)
        {
            rollScore1=p1Ptr->roll(); //rolls die for player 1
            rollScore2=p2Ptr->roll(); //rolls die for player 2
            if(rollScore1<rollScore2) //checks which was higher
            {
                score.push_back(2); //if player 2 wins then a 2 is added to the vector
            }
            else
            {
                score.push_back(1);
            }
        }
    }
    
void Game::results() //outputs the final results to the user
    {
        int player1=0,player2=0;
        string winner,type1,type2;
        
        for(int i=0;i<rounds;i++) //tallies up who won each round
        {
            if(score[i]==1)
            {
                player1++;
            }
            else
            {
                player2++;
            }
        }
        if(player1<player2) //determines the winner
        {
            winner="player two";
        }
        else
        {
            winner="player one";
        }
        
        //displays results to user
        cout << "Results:" << endl;
        cout << "The winner is " << winner << " after " << rounds << " rounds." << endl << endl;
        cout << "Player one had a " << p1Ptr->getSides() << " sided " << p1Ptr->getType() << " die" << " and won " << player1 << " rounds." <<endl;
        cout << "Player two had a " << p2Ptr->getSides() << " sided " << p2Ptr->getType() << " die" << " and won " << player2 << " rounds." <<endl << endl;
    }

