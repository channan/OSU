/*******************************
 * Program Name: FinaleRoom.hpp
 * Author: Cody Hannan
 * Date: 3/21/17
 * Description: Contains function prototypes for implementation file and class declaration.
 *******************************/

#ifndef FinaleRoom_hpp
#define FinaleRoom_hpp

#include "Room.hpp"

class FinaleRoom: public Room
{
private:
    int pickedUp=0;
public:
    FinaleRoom(): Room() //adds to basic room to make finale room unique
    {
        grid[row-2][col/2+1]='#';
        grid[row-2][col/2-1]='#';
        grid[row-1][col/2]='.';
        
        grid[row/2][col/2]='I';
    }
    
    virtual string itemPickup();
    virtual void comment();
    virtual bool leave();
};


#endif /* FinaleRoom_hpp */
