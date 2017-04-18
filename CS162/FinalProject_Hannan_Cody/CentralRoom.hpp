/*******************************
 * Program Name: CentralRoom.hpp
 * Author: Cody Hannan
 * Date: 3/21/17
 * Description: Contains function prototypes for implementation file and class declaration.
 *******************************/

#ifndef CentralRoom_hpp
#define CentralRoom_hpp

#include "Room.hpp"

class CentralRoom: public Room
{
public:
    CentralRoom(): Room() //add to basic room to make central room unique
    {
        grid[row/2][col/2]='=';
        grid[row/2+1][col/2]='#';
        grid[row/2+1][col/2+1]='#';
        grid[row/2+1][col/2-1]='#';
        grid[row/2][col/2+1]='#';
        grid[row/2][col/2-1]='#';
        
        grid[row/2+1][1]='#';
        grid[row/2-1][1]='#';
        grid[row/2][0]='.';
        
        grid[row/2+1][col-2]='#';
        grid[row/2-1][col-2]='#';
        grid[row/2][col-1]='.';
        
        grid[1][col/2+1]='#';
        grid[1][col/2-1]='#';
        grid[0][col/2]='.';
        
        grid[row-2][col/2+1]='#';
        grid[row-2][col/2-1]='#';
        grid[row-1][col/2]='.';
    }
    
    virtual string itemPickup();
    virtual void comment();
    virtual bool leave();
};

#endif /* CentralRoom_hpp */
