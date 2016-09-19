/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Evan
 *
 * Created on September 14, 2016, 11:42 PM
 /* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
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
int* fillRndmAry(int);
int* fillIndxAry(int);
void prntAry(int *,int,int);
void prntAry(int *,int *,int,int);
void mrkSort(int *,int *,int);

//Execution Begin Here!
int main(int argc, char** argv) {
    //Initialize the random number generator
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare variables
    int perLine=10;
    const int SIZE=100;
    int utilize=SIZE*0.5;
    int *array,*index;
    
    //Input data
    array = fillRndmAry(utilize);
    index = fillIndxAry(utilize);
    
    //Display initialization
    cout<<"Original Array Output"<<endl;
    prntAry(array,utilize,perLine);
    cout<<"Original Indexed Array Output"<<endl;
    prntAry(index,utilize,perLine);
    cout<<"Array Output utilizing the Index"<<endl;
    prntAry(array,index,utilize,perLine);
    
    //Process -> Map the input data to the output
    mrkSort(array,index,utilize);
    
    //Display/Output solution here
    cout<<"Original Array After Sorting"<<endl;
    prntAry(array,utilize,perLine);
    cout<<"Sorted Indexed Array Output"<<endl;
    prntAry(index,utilize,perLine);
    cout<<"Array Output utilizing the Index after Sorting"<<endl;
    prntAry(array,index,utilize,perLine);
    delete [] array;
    delete [] index;
    //Exit stage right!
    return 0;
}

void mrkSort(int *a,int *indx,int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(*(a + *(indx + i)) > *(a + *(indx + j))){
                *(indx + i)=*(indx + i)^*(indx + j);
                *(indx + j)=*(indx + i)^*(indx + j);
                *(indx + i)=*(indx + i)^*(indx + j);
            }
        }
    }
}

void prntAry(int *a,int *indx,int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout << *(a + *(indx + i))<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void prntAry(int *a,int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<*(a+i)<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

int* fillRndmAry(int n){
    int *a = new int[n];

    for(int i=0;i<n;i++){
        *(a + i)=rand()%90+10;//Random 2 digit numbers

    }
    return a;
}
int* fillIndxAry(int n){
    //Allocate memory
    int *indx = new int[n];
    for(int i=0;i<n;i++){
        *(indx + i)=i;
    }
    return indx;
}