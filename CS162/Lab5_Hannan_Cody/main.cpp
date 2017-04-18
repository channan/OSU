/**************************************
 * Program name: main.cpp
 * Author: Cody Hannan
 * Date: 2/9/17
 * Description: This is where use inputs are prompted and the recursion functions are called. If statements divide the
 * interior of a while statement that keeps the program running. There is an if statement for each menu option.
 **************************************/

#include <iostream>
#include <string>
#include "recursionFunctions.hpp"
#include "menu.hpp"
#include "inputValidation.hpp"

using std::string;
using std::cout;
using std::cin;
using std::endl;


int main()
{
    int *array, *tempArray, option, N;
    
    while(option!=4)
    {
        menu();
        option=inputValid(1,4,"option");
        
        if(option==1) //reverses a string entered by the user
        {
            string reverseString;
            
            cout << "\nPlease enter a string to be reversed: ";
            cin.ignore(2000,'\n'); //flushes the buffer
            getline(cin,reverseString);
            cout << endl;
            
            cout << "Reversed string: ";
            reverse(reverseString); //calls recursive function to reverse string
            cout << endl;
        }
        
        if(option==2) //sums an array
        {
            int count=0, num;
            bool run=true;
            
            array=new int[1]; //for the while loop to work properly this needs to occur before so that there is something to deallocate
            
            cout << "\nEnter integers to be summed. Once all integers have been entered press a non number key to continue the function (a decimal will be rounded down and end the list)." << endl;
            
            while(run) //loop for adding integers to the array.
            {
                tempArray=array; //stores current array values
                
                delete [] array; //deallocates array
                array=new int[count+1]; //creates new array with extra space
                
                for (int i=0;i<count;i++)
                {
                    array[i]=tempArray[i]; //reassigns values from previous array
                }
               
                cin >> num;
                array[count]=num; //sets new value for last space in array
                count++;
                
                if(cin.fail()) //if non int value is entered then loop ends
                {
                    run=false;
                    cin.clear();
                    cin.ignore(2000,'\n');
                }
            }
            
            cout << "\nSum of all the integers: ";
            cout << sum(array,count) << endl << endl; //calls recursive sum function to sum contents of array
            delete [] array; //deallocates array to avoid memory leaks
        }
        
        if(option==3) //calculate triangle number of sum integer
        {
            cout << "\nPlease enter an integer for which you want its triangle number calculated (any decimals will be rounded down): ";
            N=inputValid(0,10000000,"triangle");
            cout << "\nTriangle number: ";
            cout << triangleNum(N) << endl << endl; //calls recursive triangle function
        }
    }
    
    return 0;
}
