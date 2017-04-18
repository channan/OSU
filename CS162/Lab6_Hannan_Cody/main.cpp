/**********************
 * Program Name: main.cpp
 * Author: Cody Hannan
 * Date: 2/19/17
 * Description: Primarily constains the menu system for changing elements within the linked list.
 ************************/

#include <iostream>
#include "NumberList.hpp"
#include "inputValidation.hpp"

using std::cout;
using std::cin;
using std::endl;

int main()
{
    NumberList list;
   
    cout << "Welcome to my linked list!" << endl;
    
    double number;
    char choice='y', headsTails='i';
    
    
    while(choice == 'y') //loops the menu
    {
        while(choice == 'y') //loops the enter number function
        {
            cout << "Enter a number: "; //prompts user for a number
            number=inputValid("number"); //chekcs entered value
            list.add(number); //calls function for adding element
        
            choice='i'; //resets choice value
            while(choice!='y' && choice!='n') //loops if user doesn't enter correct value
            {
                cout << "Do you want another num(y or n): ";
                cin >> choice;
                
                if(choice!='y' && choice!='n')
                {
                    cout << "Please enter y or n for yes or no respectively.";
                }
                cout << endl;
            }
        }
    
        cout << "Your linked list is: ";
        list.displayList(); //calls display list function
        
        while(headsTails!='h' && headsTails!='t') //loops if incorrect value is entered
        {
            cout << "\nDo you want to get head or tail node value (h or t): ";
            cin >> headsTails;
          
            if(headsTails=='h') //outputs head node
            {
                cout << "\nHead node is: " << list.getHeadNode() << endl;
            }
          
            else if(headsTails=='t') //outputs tail node
            {
                cout << "\nTail node is: " << list.getTailNode() << endl;
            }
            else
            {
                cout << "Please enter h or t for head node or tail node respectively." << endl;
            }
        }
        
        headsTails='i'; //resets headTails value
        
        while(headsTails!='h' && headsTails!='t') //loops if user entered incorrect value
        {
            cout << "Do you want to delete head or tail node (h or t): ";
            cin >> headsTails;
            cout << endl;
          
            if(headsTails=='h') //removes head node
            {
                list.remove(list.getHeadNode());
                cout << "The new head node is " << list.getHeadNode() << endl;
            }
            else if(headsTails=='t') //removes tail node
            {
                list.remove(list.getTailNode());
                cout << "The new tail node is " << list.getTailNode() << endl;
            }
            else
            {
                cout << "Please enter h or t for head node or tail node respectively." << endl;
            }
        }
        
        headsTails='i'; //resets headsTails value
        choice='i'; //resets choice value
        
        while(choice!='y' && choice!='n') //loops if user doesn't enter y or n
        {
            cout << "Do you want to do this again (y or n): ";
            cin >> choice;
            
            if(choice!='y' && choice!='n')
            {
                cout << "Please enter y or n for yes or no respectively.";
            }
            cout << endl;
        }
    }
    
    return 0;
}
