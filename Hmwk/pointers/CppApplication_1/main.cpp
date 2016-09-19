/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Modified by: Evan Grumling
 * Created on September 12, 2016, 1:01 PM
 * Purpose:  Database Sort
 */

//System Libraries
#include <iostream>  //I/O Library
#include <cstdlib>   //Random number generator Library
#include <ctime>     //Time Library
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void fillAry(int *,int *,int);
void prntAry(int *ptr1,int,int);
void prntAry(int *ptr1,int *ptr2,int,int);
void mrkSort(int *ptr1,int *ptr2,int);

//Execution Begin Here!
int main(int argc, char** argv) {
    //Initialize the random number generator
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare variables
    int perLine=10;
    const int SIZE=100;
    int utilize=SIZE*0.5;
    int *ptrArray,*index;
    
    //allocate arrays
    ptrArray = new int[SIZE];
    index = new int[SIZE];
    
    //Input data
    fillAry(ptrArray,index,utilize);
    
    //Display initialization
    cout<<"Original Array Output"<<endl;
    prntAry(ptrArray,utilize,perLine);
    cout<<"Original Indexed Array Output"<<endl;
    prntAry(index,utilize,perLine);
    cout<<"Array Output utilizing the Index"<<endl;
    prntAry(ptrArray,index,utilize,perLine);
    
    //Process -> Map the input data to the output
    mrkSort(ptrArray,index,utilize);
    
    //Display/Output solution here
    cout<<"Original Array After Sorting"<<endl;
    prntAry(ptrArray,utilize,perLine);
    cout<<"Sorted Indexed Array Output"<<endl;
    prntAry(index,utilize,perLine);
    cout<<"Array Output utilizing the Index after Sorting"<<endl;
    prntAry(ptrArray,index,utilize,perLine);

    //Exit stage right!
    return 0;
}

void mrkSort(int *ptr,int *index,int n){
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
void prntAry(int *ptrArray,int *index,int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<*(index +i)<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void prntAry(int *ptrArray,int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<*(ptrArray + i)<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void fillAry(int *ptrArray,int *index,int n){
    for(int i=0;i<n;i++){
        *(ptrArray + i)=rand()%90+10;//Random 2 digit numbers
        *(index + i)=i;
    }
}
