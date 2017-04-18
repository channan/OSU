/*****************************
 * Program Name: main.cpp
 * Author: Cody Hannan
 * Date: 3/5/17
 * Description: Prompts for user inputs in order to call proper files and output files with inputted name. Displays menu and provides user with different options between search a file for the value 0, sorting the file contents, and using binary search.
 ******************************/

#include <iostream>
#include <fstream>
#include <string>
#include "functions.hpp"
#include <vector>
#include "menu.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::string;
using std::ofstream;

int main()
{
    int integer,option,position,min=1,max=4;
    vector<int> array;
    string fileName,sortedFileName;
        
    while(option!=4)
    {
        menu();
        cin >> option;
        
        while(cin.fail()||option<min||option>max) //while loop starts if value is of the wrong type
        {
            if(cin.fail())
            {
                cout << "\nPlease enter an integer value: "; //prompts user for correct type
                cin.clear(); //clears the cin buffer
                cin.ignore(1000,'\n'); //ignores anything that is missed
                cin >> option; //takes a new input from the user
                
            }
            else if(option<min||option>max) //prompts user for values within correct range
            {
                cout << "\nPlease enter a value between " << min << " and " << max << ": ";
                cin >> option;
            }
        }

        cout << endl;
        
        if(option==1) //searchs array for 0 and returns position
        {
            cout << "Please enter the name of the file: ";
            cin >> fileName;
            cout << endl;
            
            ifstream inputFile;
            inputFile.open(fileName.c_str());
            
            if(inputFile)
            {
                cout << fileName << " opened successfully.\n\n";
            }
            else
            {
                cout << fileName << " not found.\n";
            }
            
            while (inputFile>>integer) //reads file for integers and continues until it reaches eof
            {
                array.push_back(integer); //adds each integer from file to an array
            }
            
            position=searchList(array,array.size(),0); //array is passed to search function and position is returned
            
            if(position==-1)
            {
                cout << "The value 0 could not be found within the file." << endl << endl;
            }
            else
            {
                cout << "The zero is located at position " << position << "." << endl << endl;
            }
            inputFile.close();
            array.clear();
        }
        if(option==2) //sorts array from prompted file
        {
            cout << "Please enter the name of the file you wish to sort: ";
            cin >> fileName;
            cout << endl;
            
            ifstream inputFile;
            inputFile.open(fileName.c_str());
            
            if(inputFile)
            {
                cout << fileName << " opened successfully.\n";
            }
            else
            {
                cout << fileName << " not found.\n";
            }
            
            while (inputFile>>integer) //reads file
            {
                array.push_back(integer); //adds contents of file to array
            }
            
            sort(array,array.size()); //passes array to sort function
            
            cout << "Please enter the name of the new file where the sorted values will be stored: ";
            cin >> sortedFileName; //user is prompted for an output file name
            cout << endl;
            
            ofstream outputFile;
            outputFile.open(sortedFileName.c_str());
            
            for(int i=0;i<array.size();i++)
            {
                outputFile << array[i] << " "; //contents of array are written to output file
                
            }
            
            cout << "Data successfully written to " << sortedFileName << endl << endl;
            
            inputFile.close();
            outputFile.close();
            array.clear();
        }
        if(option==3) //using binary search function to search array for 0
        {
            cout << "Please enter the name of the file (must be a sorted file for search to work properly): ";
            cin >> fileName;
            cout << endl;
            
            ifstream inputFile;
            inputFile.open(fileName.c_str());
            
            if(inputFile)
            {
                cout << fileName << " opened successfully.\n";
            }
            else
            {
                cout << fileName << " not found.\n";
            }
            
            while (inputFile>>integer)
            {
                array.push_back(integer); //contents of file are added to array
            }
            
            position=binarySearch(array,array.size(),0); //binary search returns position of 0 within the array
            
            if(position==-1)
            {
                cout << "The value could not be found within the file." << endl << endl;
            }
            else
            {
                cout << "The zero is located at position " << position << "." << endl << endl;
            }
            inputFile.close();
            array.clear();
        }
    }
    return 0;
}


