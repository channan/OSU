/*******************************
 * Program Name: Room.cpp
 * Author: Cody Hannan
 * Date: 3/21/17
 * Description: Mostly contains getter and setter functions to be used by game class. Acts as abstract base class for other room types.
 *******************************/

#include "Room.hpp"

void Room::displayRoom()
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cout << grid[i][j];
        }
        cout << endl;
    }
}

//getter functions
Room* Room::getLeft()
{
    return left;
}
Room* Room::getRight()
{
    return right;
}
Room* Room::getUp()
{
    return up;
}
Room* Room::getDown()
{
    return down;
}

//setter functions
void Room::setLeft(Room* left)
{
    this->left=left;
}
void Room::setRight(Room* right)
{
    this->right=right;
}
void Room::setUp(Room* up)
{
    this->up=up;
}
void Room::setDown(Room* down)
{
    this->down=down;
}

//room change functinos
bool Room::changeRoomLeft()
{
    if(grid[row/2][0]=='@')
    {
        grid[row/2][0]='.';
        return true;
    }
    else
    {
        return false;
    }
}
bool Room::changeRoomRight()
{
    if(grid[row/2][col-1]=='@')
    {
        grid[row/2][col-1]='.';
        return true;
    }
    else
    {
        return false;
    }
}

bool Room::changeRoomUp()
{
    if(grid[0][col/2]=='@')
    {
        grid[0][col/2]='.';
        return true;
    }
    else
    {
        return false;
    }
}
bool Room::changeRoomDown()
{
    if(grid[row-1][col/2]=='@')
    {
        grid[row-1][col/2]='.';
        return true;
    }
    else
    {
        return false;
    }
}

//player location functions
void Room::placePlayer(int x, int y)
{
    grid[x][y]='@';
}
int Room::getPlayerXCor()
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(grid[i][j]=='@')
            {
                return i;
            }
        }
    }
    return 0;
}
int Room::getPlayerYCor()
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(grid[i][j]=='@')
            {
                return j;
            }
        }
    }
    return 0;
}

/*virtual string itemPickup()=0;
virtual void comment()=0;
virtual bool leave()=0;*/


//player movement
void Room::movePlayer(int move)
{
    int x=this->getPlayerXCor(),y=this->getPlayerYCor();
    
    grid[x][y]='.';
    
    if(move==1) //moved player left
    {
        y--;
        
        if(grid[x][y]=='#')
        {
            y++;
        }
    }
    else if(move==2) //moves player right
    {
        y++;
        
        if(grid[x][y]=='#')
        {
            y--;
        }
    }
    else if(move==3) //moves player up
    {
        x--;
        
        if(grid[x][y]=='#')
        {
            x++;
        }
    }
    else if(move==4) //moves player down
    {
        x++;
        
        if(grid[x][y]=='#')
        {
            x--;
        }
    }
    
    this->placePlayer(x,y);
}
