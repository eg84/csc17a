/*
 *This program will take in a file, load its contents into an array, then sort 
 * the array. Program will produce the lowest number, highest number, total of
 * the array, and the average of the array.
 */

/* 
 * File:   main.cpp
 * Author: Evan
 *
 * Created on September 19, 2016, 12:43 AM
 */

//libraries
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*
 * 
 */
//function prototypes
float avgArray(int*, float&, int);
void xorSort(int *,int);
int* fillArray(ifstream &inFile, const int);

int main(int argc, char** argv) {
    
    //declare variables
    const int SIZE = 20;       //max size of array
    int *array;                //pointer to array
    ifstream inFile;           //file object
    string fileName;           //user entered file name
    float total = 0;           //total of array filled from avgArray function
    float average;             //holds value of array average
    
    //get the file name
    cout << "Enter file name: " << endl;
    cin >> fileName;

    //open file1
    inFile.open(fileName.c_str());
    
    //call functions
    array = fillArray(inFile, SIZE);
    
    //close file1 after array1 is filled
    inFile.close();
    
    //call sort and average functions
    xorSort(array, SIZE);
    average = avgArray(array,total,SIZE);
   
    cout << "The lowest number in the array is " << array[0] << endl;
    cout << "The Highest number in the array is " << array[SIZE - 1] << endl;
    cout << "The average number in the array is " << average << endl;
    cout << "The total of all the numbers in the array is " << total <<endl;
    //free up memory allocation
    delete [] array;
    
   //end program
    return 0;
}

//totals all numbers in a array and averages them
float avgArray(int*a, float &total, int size)
{
    float avg = 0;
    for(int i = 0; i < size; i++)
    {
        total += *(a + i);
    }
     avg = total / size;
    return avg;
}
//dynamically allocates an array then fills it with numbers from a file
int* fillArray(ifstream &inFile, const int SIZE)
{       
	int records = 0;
        
        //allocate new array
        int *a = new int[SIZE];
        
        cout << "loading file...." << endl;
        //while read position is not at the end of the file and less than the
        //total size of the array
	while (!inFile.eof() &&  records < SIZE)
	{
            //add number to the array
            inFile >> *(a + records);
            //increment array position
		records++;
	}
        //return the pointer to the array
        return a;
}
//sorts array from lowest to highest using XOR swap method
void xorSort(int *a,int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(*(a+i)>*(a+j)){
                *(a + i)=*(a + i)^*(a + j);
                *(a + j)=*(a + i)^*(a + j);
                *(a + i)=*(a + i)^*(a + j);
            }
        }
    }
}