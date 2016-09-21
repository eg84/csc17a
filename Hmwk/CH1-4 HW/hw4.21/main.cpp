/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

/*
 * no negative values
 */
int main() {
    int select;         //INPUT selected menu option
    float radius;       //INPUT radius of circle
    float length;       //INPUT length of rectangle
    float width;        //INPUT width of rectangle
    float height;       //INPUT height of triangle
    float base;         //INPUT base of triangle
    float area = 0;     //OUTPUT calculated area 
    
    
    do{ //Display menu
        cout << "\n\nGeometry Calculator" << endl;
        cout << "**************************" << endl;
        cout << "1. Calculate the Area of a Circle" << endl;
        cout << "2. Calculate the Area of a Rectangle" << endl;
        cout << "3. Calculate the Area of a Triangle" << endl;
        cout << "4. Quit" << endl;
        cout << "\nEnter your choice (1-4):" << endl;
        cin >> select;
        
        while(select < 1 || select > 4) //validate input is between 1 and 4
        {
            cout << "Invalid choice. Please try again" << endl;
            cout << "1. Calculate the Area of a Circle" << endl;
            cout << "2. Calculate the Area of a Rectangle" << endl;
            cout << "3. Calculate the Area of a Triangle" << endl;
            cout << "4. Quit" << endl;
            cout << "\nEnter your choice (1-4):" << endl;
            cin >> select;
        }   
        
        if (select == 1)
        {
            cout << "Calculate the Area of a Circle\n\nEnter the radius:" << endl;
            cin >> radius;
            while(radius < 0)
            {
                cout << "Please enter a valid positive number"
            }
            //using formula pi times radius squared
            area = radius * radius * 3.14159;
            //display the calculated area
            cout << "The area of the circle is " << area << endl;
        }
        else if (select == 2)
        {
            cout << "Calculate the Area of a Rectangle\n\nEnter the length" 
                    << " then the width:" << endl;
            cin >> length >> width;
            area = length * width;
            cout << "The area of the Rectangle is " << area << endl;
        }
        else if (select == 3)
        {
            cout << "Calculate the Area of a Triangle\n\nEnter the height" 
                    << " then the base followed by the enter key" << endl;
            cin >> height >> base;
            area = height * base * 0.5;
            cout << "The area of the Rectangle is " << area << endl;
        }
    }while(select != 4);//breaks out of loop is user selects 4
    //say goodbye outside of do while loop
    cout << "\nThank you for using the Geometry Calculator.";
            
    return 0;
}

