/*******************************
 * Program Name: Game.cpp
 * Author: Cody Hannan
 * Date: 3/21/17
 * Description: Where main game progression functions reside
 *******************************/

#include "Game.hpp"

void Game::play()
{
    int health=500,option=0,state;
    string item;
    
    currentRoom=center;
    currentRoom->placePlayer(9,17); //places character at start
    
    while(health>0 && option!=5 && !currentRoom->leave())
    {
        if(currentRoom->changeRoomLeft()) //changes to left room
        {
            currentRoom=currentRoom->getLeft();
            currentRoom->placePlayer(10,33);
        }
        if(currentRoom->changeRoomRight()) //changes to right room
        {
            currentRoom=currentRoom->getRight();
            currentRoom->placePlayer(10,1);
        }
        if(currentRoom->changeRoomUp()) //changes to up room
        {
            currentRoom=currentRoom->getUp();
            currentRoom->placePlayer(18,17);
        }
        if(currentRoom->changeRoomDown()) //changes to down room
        {
            currentRoom=currentRoom->getDown();
            currentRoom->placePlayer(1,17);
        }
        
        currentRoom->leave(); //checks if player is leaving by staircase
        currentRoom->displayRoom();
        currentRoom->comment(); //outputs unique room descriptor
        item=currentRoom->itemPickup(); //if user walks over item its picked up and stored in item variable
        
        if(item!="")
        {
            inventory.push_back(item); //item is stored in inventory
        }
        state=this->checkInv(); //checks inventory
        cout << "Health: " << health << endl;
        this->displayInv();
        this->menu();
        cin >> option;
        
        while(cin.fail() || option<=0 || option>5) //input validation
        {
            cin >> option;
            
            if(cin.fail())
            {
                cin.clear();
                cin.ignore(1000,'\n');
                cout << "\nInvalid option. Reenter: ";
                //cin >> option;
            }
            else if(option>5 || option<=0)
            {
                cout << "\nInvalid option. Reenter: ";
                //cin >> option;
            }
        }
        
        currentRoom->movePlayer(option);
        
        if(state==2) //once player has grabbed idol
        {
            health--;
            health--;
            health--;
            health--;
        }
        else //normal health drain
        {
            health--;
        }
    }
    
    if(health<=0)
    {
        cout << "You died..." << endl << endl;
    }
}

void Game::menu()
{
    cout << "Actions Menu." << endl;
    cout << "1. Move left." << endl;
    cout << "2. Move right." << endl;
    cout << "3. Move up." << endl;
    cout << "4. Move down." << endl;
    cout << "5. Exit game." << endl;
    cout << "Menu selection: ";
}

void Game::displayInv()
{
    cout << "Inventory: ";
    for(int i=0;i<inventory.size();i++)
    {
        cout << inventory[i] << " ";
    }
    cout << endl;
}

int Game::checkInv() //checks inventory to see what items user currenlty has. Is used to change rooms and health states
{
    int points=0;
    
    for(int i=0;i<inventory.size();i++)
    {
        if(inventory[i]=="Emerald")
        {
            points++;
        }
        else if(inventory[i]=="Ruby")
        {
            points++;
        }
        else if(inventory[i]=="Sapphire")
        {
            points++;
        }
        else if(inventory[i]=="Idol")
        {
            points++;
        }
    }
    
    if(points==3) 
    {
        cout << "I think I heard a passage open..." << endl;
        
        openNorth->setUp(finale);
        openNorth->setDown(center);
        
        center->setUp(openNorth);
        
        finale->setDown(openNorth);
        
        return 1;
    }
    if(points==4)
    {
        cout << "Alright I got the Idol. The air seems to have gotten thicker.... I better get out of here!" << endl;
        cout << "Your health is dropping rapidly!!" << endl;
        return 2;
    }
    
    return 0;
}

