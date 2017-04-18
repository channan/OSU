/**********************
 * Program Name: main.cpp
 * Author: Cody Hannan
 * Date: 3/5/17
 * Description: Executes program. Prompts user for the fighters and creates a Fight object to determine winner
 ************************/

#include "Creature.hpp"
#include "Vampire.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"
#include "Fight.hpp"
#include "menu.hpp"
#include "inputValidation.hpp"
#include <iostream>
#include <cstdlib>
#include "Rosters.hpp"

using std::cout;
using std::endl;
using std::cin;

int main()
{
    srand(time(0)); //allows rand function to actually be random. Is used in creature classes
    
    int option,choice,num=0,score1=0,score2=0;
    string fighter1,fighter2,fighter;
    Rosters team1,team2,losers;
    
    while (option!=5)
    {
        mainMenu();
        option=inputValid(1,5,"option"); //checks for proper input
        
        if(option==1) //has user select fighter to battle
        {
            fightersMenu();
            
            cout << "\nFighter 1: ";
            
            cin >> fighter1;
            
            while(fighter1!="Vampire" && fighter1!="Barbarian" && fighter1!="BlueMen" && fighter1!="Medusa" && fighter1!="HarryPotter")
            {
                cout << "That is not one of the available fighters." << endl;
                cout << "Fighter 1: ";
                cin >> fighter1;
            }
            
            cout << "Fighter 2: ";
            
            cin >> fighter2;
            
            while(fighter2!="Vampire" && fighter2!="Barbarian" && fighter2!="BlueMen" && fighter2!="Medusa" && fighter2!="HarryPotter")
            {
                cout << "That is not one of the available fighters." << endl;
                cout << "Fighter 2: ";
                cin >> fighter2;
            }
            
            cout << endl;
            
            Fight battle(fighter1,fighter2); //creates fight object
            
            if(battle.winner()==1) //outputs winner
            {
                cout << "Winner of the battle is fighter 1: " << fighter1 << "!" << endl << endl;
            }
            else
            {
                cout << "Winner of the battle is fighter 2: " << fighter2 << "!" << endl << endl;
            }
        }
        
        if(option==2) //creates teams
        {
            cout << "Please enter the number of fighters for each team: ";
            cin >> num;
            cout << endl;
                    
            fightersMenu();
                    
            cout << "Team 1:" << endl;
            for(int i=1;i<num+1;i++)
            {
                cout << "Fighter " << i << ": ";
                cin>>fighter;
                
                while(fighter!="Vampire" && fighter!="Barbarian" && fighter!="BlueMen" && fighter!="Medusa" && fighter!="HarryPotter")
                {
                    cout << "That is not one of the available fighters." << endl;
                    cout << "Fighter " << i << ": ";
                    cin >> fighter;
                }

                team1.add(fighter); //adds fighter to team 1
            }
                    
            cout << "Team 2:" << endl;
            for(int i=1;i<num+1;i++)
            {
                cout << "Fighter " << i << ": ";
                cin>>fighter;
                
                while(fighter!="Vampire" && fighter!="Barbarian" && fighter!="BlueMen" && fighter!="Medusa" && fighter!="HarryPotter")
                {
                    cout << "That is not one of the available fighters." << endl;
                    cout << "Fighter " << i << ": ";
                    cin >> fighter;
                }
                        
                team2.add(fighter); //adds fighter to team 2
            }
        }
        if(option==3)
        {
            while(!team1.empty() && !team2.empty())
            {
                fighter1=team1.getHeadNode(); //checks for fighters that are up
                fighter2=team2.getHeadNode();
                        
                Fight battle(fighter1,fighter2);
                        
                cout << "\nTeam 1 fighter: " << fighter1 << " VS Team 2 fighter: " << fighter2 << endl;
                        
                if(battle.winner()==1) //outputs winner
                {
                    cout << "Winner of the battle is team 1 fighter: " << fighter1 << "!" << endl << endl;
                    team1.frontToBack(fighter1); //winner goes to back of line
                    losers.add(fighter2); //loser goes to loser roster
                    team2.remove(fighter2); //loser is removed from team
                    score1++;
                    cout << "Team1: " << score1 << endl;
                    cout << "Team2: " << score2 << endl << endl;
                }
                else
                {
                    cout << "Winner of the battle is team 2 fighter: " << fighter2 << "!" << endl << endl;
                    team2.frontToBack(fighter2);
                    losers.add(fighter1);
                    team1.remove(fighter1);
                    score2++;
                    cout << "Team 1: " << score1 << endl;
                    cout << "Team 2: " << score2 << endl;
                }
            }
            
            if(score1<score2)
            {
                cout << "\nTeam 2 wins!!" << endl << endl;
            }
            else
            {
                cout << "Team 1 wins!!" << endl << endl;
            }
            
        }
        if(option==4)
        {
            cout << "\nLast tournament's fallen fighters:" << endl;
            losers.displayList();
            cout << endl;
        }
    }
    return 0;
}
