/*******************************
 * Program Name: NorthRoom.hpp
 * Author: Cody Hannan
 * Date: 3/21/17
 * Description: Contains function prototypes for implementation file and class declaration.
 *******************************/

#ifndef NorthRoom_hpp
#define NorthRoom_hpp

#include "Room.hpp"

class NorthRoom: public Room
{
public:
    NorthRoom(): Room() //adds to basic room to make north unique
    {
        grid[1][col/2+1]='#';
        grid[1][col/2-1]='#';
        grid[0][col/2]='#';
        grid[1][col/2]='#';
        
        grid[row-2][col/2+1]='#';
        grid[row-2][col/2-1]='#';
        grid[row-1][col/2]='.';
        
        grid[row/4][col/3]='#';
        grid[row/4][2*col/3]='#';
        grid[row/2][col/3]='#';
        grid[row/2][2*col/3]='#';
        grid[3*row/4][col/3]='#';
        grid[3*row/4][2*col/3]='#';
        
    }
    
    virtual string itemPickup();
    virtual void comment();
    virtual bool leave();
};


#endif /* NorthRoom_hpp */
