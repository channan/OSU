/*******************************
 * Program Name: WestRoom.hpp
 * Author: Cody Hannan
 * Date: 3/21/17
 * Description: Contains functions prototypes for implementation file and class declaration.
 *******************************/

#ifndef WestRoom_hpp
#define WestRoom_hpp

#include "Room.hpp"

class WestRoom: public Room
{
private:
    int pickedUp=0;
public:
    WestRoom(): Room() //adds to basic room to make west unique
    {
        grid[row/2+1][col-2]='#';
        grid[row/2-1][col-2]='#';
        grid[row/2][col-1]='.';
        
        grid[row/3][col/3]='E';
        grid[row/3][2*col/3]='E';
        grid[2*row/3][col/3]='E';
        grid[2*row/3][2*col/3]='E';
    }
    
    virtual string itemPickup();
    virtual void comment();
    virtual bool leave();
    
    
    
};

#endif /* WestRoom_hpp */
