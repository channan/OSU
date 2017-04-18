/*******************************
 * Program Name: SouthRoom.hpp
 * Author: Cody Hannan
 * Date: 3/21/17
 * Description: Contains function prototypes for implementation file and class declaration.
 *******************************/

#ifndef SouthRoom_hpp
#define SouthRoom_hpp

#include "Room.hpp"

class SouthRoom: public Room
{
private:
    int pickedUp=0;

public:
    SouthRoom(): Room() //adds to basic room to make south unique
    {
        grid[1][col/2+1]='#';
        grid[1][col/2-1]='#';
        grid[0][col/2]='.';
        
        for(int i=1;i<25;i++)
        {
            grid[row/3][i]='#';
        }
        
        for(int i=33;i>10;i--)
        {
            grid[2*row/3][i]='#';
        }
        
        grid[4*row/5][col/2]='R';
    }
    
    virtual string itemPickup();
    virtual void comment();
    virtual bool leave();
};

#endif /* SouthRoom_hpp */
