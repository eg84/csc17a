
/* This program takes in the month, year, and total amount of money collected
 * at the register. The program then calculates the amount of sales tax collected,
 * both county and state, then outputs the financial data into a formatted table.
 */

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    
    string month;       //Holds current month string
    int year;           //Holds 4 digit year
    float totalAmt;     //total sales amount including tax
    float lessTax;      //sales amount minus tax
    float totalTax;     //combined tax amount  
    float stateTax;     //tax taken by state at 4% rate
    float cntyTax;      //tax taken by county at 2% rate
    
    //Get month as a string
    cout << "Enter the month: " << endl;
    cin >> month;
    //Get integer year
    cout << "Enter the 4 digit year: " << endl;
    cin >> year;
    //Get the total amount collected
    cout << "Amount collected: " << endl;
    cin >> totalAmt;
    
    //process inputs
    lessTax = totalAmt / 1.06;
    totalTax = totalAmt - lessTax;
    stateTax = lessTax * 0.04;
    cntyTax = lessTax * 0.02;
    
    //fix decimals
    cout << fixed << setprecision(2);
    //output financial data
    cout << "Date: " << month << ", " << year << endl;
    cout << "--------------------" << endl;
    cout << "Total Collected: " << setw(5) << "$ " << setw(8) << totalAmt << endl;
    cout << "Product sales: " << setw(7) << "$ " << setw(8) << lessTax << endl;
    cout << "State Tax: " << setw(11) << "$ " << setw(8) <<stateTax << endl;
    cout << "County Tax: " << setw(10) << "$ " << setw(8) << cntyTax << endl;
    cout << "total tax: " << setw(11) << "$ " << setw(8) << totalTax << endl;
    
    
    return 0;
}

