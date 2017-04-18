/**********************
 * Program Name: main.cpp
 * Author: Cody Hannan
 * Date: 2/20/17
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

using std::cout;
using std::endl;
using std::cin;

int main()
{
    srand(time(0)); //allows rand function to actually be random. Is used in creature classes
    
    int option;
    string fighter1,fighter2;
    
    while (option!=2)
    {
        menu();
        option=inputValid(1,2,"option"); //checks for proper input
        
        if(option==1) //has user select fighter to battle
        {
            cout << "\nChoose your fighters!" << endl;
            cout << "Your choices are: " << endl;
            cout << "Vampire" << endl;
            cout << "Barbarian" << endl;
            cout << "BlueMen" << endl;
            cout << "Medusa" << endl;
            cout << "HarryPotter" << endl;
            
            cout << "\nFighter one: ";
            
            while(fighter1!="Vampire" && fighter1!="Barbarian" && fighter1!="BlueMen" && fighter1!="Medusa" && fighter1!="HarryPotter")
            {
                cin >> fighter1;
                
                if(fighter1!="Vampire" && fighter1!="Barbarian" && fighter1!="BlueMen" & fighter1!="Medusa" && fighter1!="HarryPotter")
                {
                    cout << "That is not one of the available fighters." << endl;
                    cout << "Fighter one: ";
                }
            }
            
            cout << "Fighter two: ";
            
            while(fighter2!="Vampire" && fighter2!="Barbarian" && fighter2!="BlueMen" && fighter2!="Medusa" && fighter2!="HarryPotter")
            {
                cin >> fighter2;
                
                if(fighter2!="Vampire" && fighter2!="Barbarian" && fighter2!="BlueMen" && fighter2!="Medusa" && fighter2!="HarryPotter")
                {
                    cout << "That is not one of the available fighters." << endl;
                    cout << "Fighter two: ";
                }
            }
            
            cout << endl;
            
            Fight battle(fighter1,fighter2); //creates fight object
            
            if(battle.winner()==1) //outputs winner
            {
                cout << "Winner of the battle is fighter one: " << fighter1 << "!" << endl << endl;
            }
            else
            {
                cout << "Winner of the battle is fighter two: " << fighter2 << "!" << endl << endl;
            }
        }
    }

    return 0;
}
