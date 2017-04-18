/******************************
 * Program Name: main.cpp
 * Author: Cody Hannan
 * Date: 2/26/17
 * Description: Displays menu and prompts user for inputs. Displays outputs.
 *******************************/

#include <iostream>
#include "Queue.hpp"
#include "menu.hpp"
#include "inputValidation.hpp"

using std::cout;
using std::endl;
using std::cin;

int main()
{
    Queue queue;
    int option;
    
    while(option!=5) //if option 5 is selected then program ends
    {
        
        menu();
        option=inputValid(1,5,"option"); //checks menu selection
        
        if(option==1) //adds value to back of queue
        {
            int num;
            
            cout << "Please enter a value to be added to the queue: ";
            num=inputValid(0,1000,"number"); //checks user entered number
            queue.addBack(num); //
        }
        if(option==2) //displays value at front of queue
        {
            queue.getFront();
        }
        if(option==3) //removes the front value from the queue
        {
            queue.removeFront();
        }
        if(option==4) //displays contents of queue
        {
            queue.displayList();
        }
    }
return 0;
}
