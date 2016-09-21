/*
 *This program will take in a 2 files, a students answers and the answer key.
 * a function loads the contents of the files into arrays, a separate function
 * compares the 2 arrays and dynamically creates a third array that represents
 * a list of correct and incorrect answers as 1 or 0. A function counts the correct
 * answers and outputs whether the student passed or failed.
 * 
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

//function prototypes
int* compArray(char*, char*, int);
float avgArray(int*, float&, int);
void mrkSort(int *,int);
char* fillArray(ifstream &inFile, const int);
string pOrF(int*, int);
void listAnswers(int*, int);

int main(int argc, char** argv) {
    
    //declare variables
    const int SIZE = 20;        //max size of array
    char *array1;               //pointer to array
    char *array2;
    int *rtAnswrs;              //holds array of right or wrong answers.
                                //1 correct, 0 incorrect 
    ifstream inFile;            //file object
    string fileName1;           //user entered file name
    string fileName2;           //user entered file name
    float total = 0;            //total of array filled from avgArray function
    float average;              //holds value of array average
    
    //get the file name
    cout << "Enter answer sheet file name: " << endl;
    cin >> fileName1;

    //open file1
    inFile.open(fileName1.c_str());
    
    //call function to fill array
    array1 = fillArray(inFile, SIZE);
    
    //close file1 after array1 is filled
    inFile.close();
    
    //get the file name
    cout << "Enter student answers file name: " << endl;
    cin >> fileName2;
    
    //open file2
    inFile.open(fileName2.c_str());
    
    //call fillArray function
    array2 = fillArray(inFile, SIZE);
    
    //close file2 after array2 is filled
    inFile.close();
    
    //call function to compare answers vs key
    rtAnswrs = compArray(array1,array2,SIZE);
    
    //call listAnswers function
    listAnswers(rtAnswrs, SIZE);
    //output pass or fail
    cout << pOrF(rtAnswrs, SIZE) << endl;
    

    //free up memory allocation
    delete [] array2;
    delete [] array1;
    delete [] rtAnswrs;
    
   //end program
    return 0;
}

//lists the question number and whether it is right or wrong
void listAnswers(int *rtAnswrs, int SIZE)
{
        for(int i = 0; i < SIZE; i++)
    {
        if(rtAnswrs[i] == 1)
            cout << "Question " << i + 1 << " correct." << endl; 
        else
            cout << "Question " << i + 1 << " incorrect." << endl;
            
    }
    
}
//adds up correct answers then determines passing grade
string pOrF(int *rtAnswrs, int SIZE)
{
    int amtCorrect = 0;
    float grade;
    
    for(int i = 0; i < SIZE; i++)
    {
        amtCorrect += rtAnswrs[i];
    }
    cout << "incorrect answers: " << SIZE - amtCorrect << endl;
    grade = amtCorrect / static_cast<float>(SIZE);
    cout << "Grade percent: " << grade * 100 << endl;
    if (grade > 0.7)
        return "PASSED";
    else
        return "FAILED";
}
//compares 2 char arrays and returns a pointer to an array that shows if the 
//student got the correct answer.
int* compArray(char *array1, char *array2, int SIZE)
{
    //allocate new array
    int *a = new int[SIZE];
    for(int i = 0; i < SIZE; i++)
    {
        if(array1[i] == array2[i])
            a[i]= 1;
        else
            a[i] = 0;
    }

    return a;
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
char* fillArray(ifstream &inFile, const int SIZE)
{       
	int records = 0;
        
        //allocate new array
        char *a = new char[SIZE];
        
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