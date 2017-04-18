/*******************************************
 * Program name: List.hpp
 * Author: Cody Hannan
 * Date: 2/5/17
 * Description: Header file for list class. Contains the constructor and destructor as well as the function prototypes that are defined in the implementation file.
 *******************************************/

#ifndef List_hpp
#define List_hpp

#include <iostream> 
#include "Item.hpp"

using std::cout;
using std::endl;

class List
{
private:
    Item** shoppingList; //double pointer to shoppinglist array
    int listSize=0;
    
public:
    List() //list starts at a capacity of 4 items
    {
        shoppingList = new Item*[4];
        for(int i=0;i<4;i++)
        {
            shoppingList[i] = new Item;
        }
    }
    ~List() //deallocates previously allocated array and objects to prevent memory leaks
    {
        for(int i=0;i<4;i++)
        {
            delete shoppingList[i];
        }
        
        if(listSize>3)
        {
            for(int i=4;i<listSize;i++)
            {
                delete shoppingList[i];
            }
        }
        delete [] shoppingList;
    }
    void addItem(string,string,int,double);
    void removeItem(int);
    void displayList();
    bool operator==(Item&);
};

#endif 
