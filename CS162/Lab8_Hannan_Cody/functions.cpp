/*****************************
 * Program Name: functions.cpp
 * Author: Cody Hannan
 * Date: 3/5/17
 * Description: Contains algorithms for searching an array for a value, sorting an array, and using binary search to search an array for a value.
 *******************************/

#include "functions.hpp"

int searchList(vector<int> list, int size, int value) //search algorithm from pg605 of text
{
    int index = 0;
    int position = -1;
    bool found = false;
    
    while (index<size && !found) //checks that search index is still within array and it has not been found
    {
        if(list[index]==value) //if value is found
        {
            found=true;
            position=index;
        }
        index++;
    }
    return position;
}

int binarySearch(vector<int> array, int size, int value) //binary search algorithm from pg607 of text
{
    int first=0, last=size-1, middle, position=-1;
    bool found=false;
    
    while(!found && first<=last)
    {
        middle=(first+last)/2; //finds middle value
        if(array[middle]==value) //if middle value equals the search value
        {
            found=true;
            position=middle;
        }
        else if(array[middle]>value) //if value is less then middle
        {
            last=middle-1; //cuts the search range in half
        }
        else //if value is more than middle
        {
            first=middle+1; //cuts the search range in half
        }
    }
    return position;
}

void sort(vector<int>& array, int size) //sort algorithm from pg620 of text
{
    int startScan, minIndex, minValue;
    
    for(startScan=0;startScan<(size-1);startScan++)
    {
        minIndex=startScan; //sets initial min Index
        minValue=array[startScan]; //sets initial min value
        
        for(int index=startScan+1;index<size;index++)
        {
            if(array[index]<minValue) //if the index value is less than the min value
            {
                minValue=array[index]; //updates min value and min index
                minIndex=index;
            }

        }
        array[minIndex]=array[startScan];
        array[startScan]=minValue; 
    }
}
