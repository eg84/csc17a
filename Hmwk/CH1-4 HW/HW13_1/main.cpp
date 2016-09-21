/*This program will take in the actual value of a property and calculate the
 * assessment value and the amount of tax to be assessed. It will then output
 * that information.
 */

#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    const float ASSESS = 0.6;       //percentage of property within assessment value
    const float PROP_TAX = 0.64;    //property tax rate
    float propVal;                  //Total value of property
    float asVal;                    //assessment value of property
    float taxAmt;                   //amount to pay in taxes
    
    //get property value from user
    cout << "Input actual value of property";
    cin >> propVal;
    
    //assessment value is property value multiplied by property tax rate 
    asVal = propVal * ASSESS;
    //tax rate is $0.64 for every $100 of assessment value
    taxAmt = asVal / 100 * PROP_TAX;
    
    cout << fixed << setprecision(2);
    cout << "Assessment value of the property:" << asVal << endl;
    cout << "The property tax amount to be paid:" << taxAmt << endl;
   return 0;
}