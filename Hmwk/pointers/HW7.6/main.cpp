/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Evan
 *
 * Created on September 19, 2016, 12:43 AM
 */

#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    const int SIZE = 20;
    ifstream inFile;
    string fileName;
    
    cout << "Enter file name: " << endl;
    cin >> fileName;
    
    inFile.open(fileName.c_str());
    
    
    
    inFile.close();
    return 0;
}

int* fillArray(ifstream &inFile, int &records,  const int SIZE)
{
	records = 0;
        int *array = new int[SIZE];
	getline(inFile, *());

	while (!inFile.eof() &&  records < SIZE)
	{
                getline(inFile, );
		//inFile.ignore();
		records++;
	}

        return a;
}