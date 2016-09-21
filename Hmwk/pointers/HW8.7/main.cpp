/*
 * This program will search for a name in a string array and return its position
 * within the array. The program first sorts the array in alphabetical order,
 * then preforms a search for the name.
 */

/* 
 * File:   main.cpp
 * Author: Evan
 *
 * Created on September 20, 2016, 1:37 PM
 */

#include <iostream>
#include <string>

using namespace std;

 
//function prototypes
void selectionSort (string array[], int);
int binarySearch(const string array[], int, string);

int main(int argc, char** argv) {
    
    //declare variables
    string nameF;               //the query name 
    int result;                 //the position of the name
    const int NUM_NAMES = 20;	//number of elements in array
    string names[NUM_NAMES] = { "Collins, Bill", "Smith, Bart", "Allen, Jim",
                                "Griffin, Jim", "Stamey, Marty", "Rose, Geri",
                                "Taylor, Terri", "Johnson, Jill", "Allison, Jeff",
                                "Looney, Joe", "Wolfe, Bill", "James, Jean", 
                                "Weaver, Jim", "Pore, Bob", "Rutherford, Greg",
                                "Javens, Renee", "Harrison, Rose", "Setzer, Cathy",
                                "Pike, Gordon", "Holland, Beth"};
    
    //get search parameter
    cout << "Enter name to find: " << endl;
    getline(cin, nameF);
    
    cout << "Searching for: " << nameF << endl;

    //call sort function
    selectionSort(names,NUM_NAMES);
    
    //call search function
    result = binarySearch(names, NUM_NAMES, nameF);
    
    //display array position information
    cout << "Array Position: names[" << result << "]" << endl;
    return 0;
}

//sorts an array of strings
void selectionSort (string array[], int size)
{
	int startScan, 
		minIndex;
	string	minValue;
 
	for (startScan = 0; startScan < (size - 1); startScan++)
	{
		minIndex = startScan;
		minValue = array[startScan];
		for(int index = startScan + 1; index < size; index++)
		{
			if (array[index] < minValue)
			{
				minValue = array[index];
				minIndex = index;
			}
		}
		array[minIndex] = array[startScan];
		array[startScan] = minValue;
	}
}
//binary search for string in a sorted array
int binarySearch(const string array[], int numElems, string value)
{
	int first = 0,				//First array element
            last = numElems - 1,    		//Last array element
            middle, 				//Midpoint of search
            position = -1;			//Position of search value
	bool found = false;			//flag
	while (!found && first <= last)
	{
		middle = (first + last) /2;     //calculate midpoint
		if (array[middle] == value)	//if value is found at midpoint
		{
			found=true;
			position = middle;
		}
		else if (array[middle] > value)	//if value is in lower half
			last = middle - 1;
		else
			first = middle +  1; 	//if value is in upper half
	}
        if (position > -1)
            cout << "Name Found." << endl;
        else
            cout << "Name not Found." << endl;
        
	return position;
}