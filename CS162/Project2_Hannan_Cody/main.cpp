/**********************************************
 * Program Name: main.cpp
 * Author: Cody Hannan
 * Date: 2/5/17
 * Description: Primarily prompts user for parameter inputs. Uses user selection from menu options to navigate if statements that run program.
 ***********************************************/

#include "menu.hpp"
#include "List.hpp"
#include <iostream>
#include "inputValidation.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::getline;

int main()
{
    List list; //initializes list opject
    int option, q, l,tally=0;
    double p;
    string n, u;
    
    while(option!=4) //if 4 is selected the program ends
    {
        menu(); //displays menu
        option=inputValid(1,4,"option"); //checks input for menu selection
        cout << endl;
    
        if(option==1) //prompts user for item parameters then adds them to the list
        {
            cout << "What is the item?" << endl;
            cout << "Item: ";
            cin.ignore(20,'\n');
            getline(cin,n);
            cout << endl;
        
            cout << "What are its units?" << endl;
            cout << "Units: ";
            getline(cin,u);
            cout << endl;
        
            cout << "What is its price?" << endl;
            cout << "Price: $";
            p=inputValid(0,1000000000,"price"); //checks user input
            cout << endl;
        
            cout << "How many?" << endl;
            cout << "Quantity: ";
            q=inputValid(0,1000000000,"quantity"); //checks user input
            cout << endl;

            list.addItem(n,u,q,p);
            tally++; //keeps track of how many items have been added
        }
        if (option==2) //prompts user for item location in list that user would like removed
        {
            cout << "At which location is the item you would like to remove? ";
            l=inputValid(1,tally,"option"); //checks user input
            cout << endl;
                
            list.removeItem(l-1);
            tally--;
        }
        if(option==3) //displays the list to the user
        {
            list.displayList();
        }
    }
    
    return 0;
}
