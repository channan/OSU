/*******************************
 * Program Name: Room.hpp
 * Author: Cody Hannan
 * Date: 3/21/17
 * Description: Function prototypes for Room.cpp and class declaration.
 *******************************/

#ifndef Room_hpp
#define Room_hpp

#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;


class Room
{
protected:
    Room *left;
    Room *right;
    Room *up;
    Room *down;
    char **grid;
    int col=35;
    int row=20;
    
public:
    Room() //allocates spaces for grid and assigns values
    {
        this->left=NULL;
        this->right=NULL;
        this->up=NULL;
        this->down=NULL;
                
        grid=new char*[row];
        for(int i=0;i<row;i++)
        {
            grid[i]=new char[col];
        }
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(i==0 || i==row-1)
                {
                    grid[i][j]='#';
                }
                else if(j==0 || j==col-1)
                {
                    grid[i][j]='#';
                }
                else
                {
                    grid[i][j]='.';
                }
            }
        }
    }
    ~Room()
    {
        for(int i=0;i<row;i++)
        {
            delete [] grid[i];
        }
        delete [] grid;
        
        /*delete left;
        delete right;
        delete up;
        delete down;*/
    }
    
    void displayRoom();
    
    //getter functions
    Room* getLeft();
    Room* getRight();
    Room* getUp();
    Room* getDown();
    
    //setter functions
    void setLeft(Room* left);
    void setRight(Room* right);
    void setUp(Room* up);
    void setDown(Room* down);
    
    //room change functions
    bool changeRoomLeft();
    bool changeRoomRight();
    bool changeRoomUp();
    bool changeRoomDown();
    
    //player location functions
    void placePlayer(int x, int y);
    int getPlayerXCor();
    int getPlayerYCor();
    
    //abstract functions
    virtual string itemPickup()=0;
    virtual void comment()=0;
    virtual bool leave()=0;
    
    //player movement
    void movePlayer(int move);
    
};
#endif 
