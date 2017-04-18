/**********************
 * Program Name: main.cpp
 * Author: Cody Hannan
 * Date: 3/12/17
 * Description: Contains the testing program and navigation menu. Prompts user for buffer input and output percentages and
 * rounds. Also prompts user for string for where a palidrome of the string is then created.
 ************************/

#include <iostream>
#include <vector>
#include <string>
#include "Buffer.hpp"
#include "menu.hpp"
#include "Palindrome.hpp"
#include "inputValidation.hpp"
#include <cstdlib>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;

int main()
{
    int option=0, rounds, length, addingPerc, removingPerc;
    double avgLength, prevAvgLength=0;
    Buffer buffer;
    string word;
    Palindrome palindrome;

    srand(time(0));
    
    while(option!=3)
    {
        menu(); //displayes test menu to user
        option = inputValid(1,3,"option"); //checks input
        
        if(option==1)
        {
            cout << "\nPlease enter the number of rounds: "; //prompts user for rounds
            rounds=inputValid(1,10000,"option");
            
            cout << "Please enter the percentage of adding to buffer: "; //prompts user for add percentage
            addingPerc=inputValid(0,100,"option");
            
            cout << "Please enter the percentage of removing from the buffer: "; //prompts user for remove percentage
            removingPerc=inputValid(0,100,"option");
            cout << endl;
            
            for(int i=1;i<=rounds;i++)
            {
                buffer.randomNumAdd(addingPerc); //calls function from buffer object and possibly adds a random generated value to the buffer
                buffer.randomNumRemove(removingPerc); //calls function from buffer object and possibly removes the front value.
                
                length=buffer.length(); //checks length after addition and removal
                avgLength=(prevAvgLength*(i-1)+length)/i; //calculates overall average length
                prevAvgLength=avgLength; //stores current avg lenth to be used as previous length in next round
                
                cout << "Round " << i << ": Length is " << length << "." << endl;
                cout << "Round " << i << ": Average length is " << avgLength << "." << endl;
            }
            
            buffer.clearBuffer();
            cout << endl;
        }
        
        if(option==2)
        {
            cout << "\nPlease enter a string: "; //prompts user for a string
            cin >> word;
            
            for(int i=0;i<word.length();i++) //adds string to palindrome object as individual characters
            {
                palindrome.push(word.at(i));
            }
            
            cout << "The palindrome is: " << word;
            
            for(int i=0;i<word.length();i++) //removes characters from stack and displays each value to user
            {
                cout << palindrome.pop();
            }
            
            cout << endl << endl;
        }
    }
    return 0;
}
