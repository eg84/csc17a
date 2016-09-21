/*This program will receive a pizza diameter as input, it will then calculate 
 * the number of slices the pizza should be divided into by dividing the total 
 * area of the pizza 

 * Author: Evan Grumling
 *
 * Created on September 7, 2016, 12:43 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

const float PI = 3.14159;
int main() {
    const float SLICE = 14.125; //area of one slice
    float dPizza = 0;               //INPUT diameter of pizza
    float radius = 0;               //the radius of the pizza
    float area = 0;                 //area of the entire pizza
    float slices = 0;               //how many slices per pizza
    //get user input
    cout << "Enter diameter of the pizza:" << endl;
    cin >> dPizza;
    //calculate radius, area, and number of slices
    radius = dPizza / 2;
    area = radius * radius * PI;    //area of entire pizza
    slices = area / SLICE;
    //rounds data to one decimal place
    cout << fixed << setprecision(1);
    //output number of slices pizza can be divided into
    cout << "The pizza should contain " << slices << " slices." << endl;
   
    return 0;
}

