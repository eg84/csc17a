/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * modified by: Evan Grumling
 * Created on September 12, 2016, 1:01 PM
 * Purpose:  XOR swap sort using pointers
 */

//System Libraries
#include <iostream>  //I/O Library
#include <cstdlib>   //Random number generator Library
#include <ctime>     //Time Library
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void fillAry(int *ptr,int);
void prntAry(int *ptr,int,int);
void mrkSort(int *ptr,int);

//Execution Begin Here!
int main(int argc, char** argv) {
    //Initialize the random number generator
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare variables
    int perLine=10;
    const int SIZE=100;
    int *aPtr;
    aPtr = new int[100];
    int array[SIZE];
    
    //Input data
    fillAry(aPtr, SIZE);
    
    //Display initialization
    prntAry(aPtr,SIZE,perLine);
    
    //Process -> Map the input data to the output
    mrkSort(aPtr,SIZE);
    
    //Display/Output solution here
    prntAry(aPtr,SIZE,perLine);

    //Exit stage right!
    return 0;
}

void mrkSort(int *ptr,int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(*(ptr + i)>*(ptr+j)){
                *(ptr + i)=*(ptr + i)^*(ptr + j);
                *(ptr + j)=*(ptr + i)^*(ptr + j);
                *(ptr + i)=*(ptr + i)^*(ptr + j);
            }
        }
    }
}

void prntAry(int *ptr,int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<*(ptr + i)<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void fillAry(int *ptr,int n){
    for(int i=0;i<n;i++){
        *(ptr + i)=rand()%90+10;//Random 2 digit numbers
    }
}
