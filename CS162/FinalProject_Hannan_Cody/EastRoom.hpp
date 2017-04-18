/*******************************
 * Program Name: EastRoom.hpp
 * Author: Cody Hannan
 * Date: 3/21/17
 * Description: Contains function prototypes for implementation file and class declaration.
 *******************************/

#ifndef EastRoom_hpp
#define EastRoom_hpp


#include "Room.hpp"

class EastRoom: public Room
{
private:
    int pickedUp=0;
public:
    EastRoom(): Room() //add to basic room to make east unique
    {
        grid[row/2+1][1]='#';
        grid[row/2-1][1]='#';
        grid[row/2][0]='.';
        
        grid[row/4][col/3]='S';
        grid[row/4][2*col/3]='S';
        grid[row/2][col/3]='S';
        grid[row/2][2*col/3]='S';
        grid[3*row/4][col/3]='S';
        grid[3*row/4][2*col/3]='S';
        
        for(int i=1;i<25;i++)
        {
            grid[row/3][i]='#';
        }
        
        for(int i=33;i>10;i--)
        {
            grid[2*row/3][i]='#';
        }
    }
    
    virtual string itemPickup();
    virtual void comment();
    virtual bool leave();
    
};


#endif /* EastRoom_hpp */
