/*
 *This program gets the number of units sold from the user. An Series of 
 * if..else if statements check the number of units to determine a discount.
 * 10-19 units receives a discount of 20%
 * 20-49 units get 30%
 * 50-99 units get 40%
 * 100+ units get 50%
 * Calculations are based on the base price of $99 multiplied by the discount
 * percentage multiplied by the number of units. 
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

/*
 * 
 */
int main() {
    const int PRICE = 99;       //price per unit
    int amtSold;                //number of units sold
    float tIncome;              //total income
    
    //ask user for number of units sold
    cout << "How many software packages were sold?" << endl;
    cin >> amtSold;
    //loop to validate input is greater than 0
    while(amtSold < 1)
    {
        cout << "Number must be greater than 0." << endl;
        cout << "How many software packages were sold? " << endl;
        cin >> amtSold;
    }
    //takes off discounted amount based on number of units sold. 
    if (amtSold < 10)
    {
        tIncome = PRICE * amtSold;
        cout << "The total cost of the purchase is: " << tIncome << endl; 
    }
    else if (amtSold > 9 && amtSold < 20)
    {
        tIncome = (PRICE * .80) * amtSold;
        cout << "The total cost of the purchase is: " << tIncome << endl;
    }
    else if (amtSold > 19 && amtSold < 50)
    {
        tIncome = (PRICE * .70) * amtSold;
        cout << "The total cost of the purchase is: " << tIncome << endl;
    }
    else if (amtSold > 49 && amtSold < 100) 
    {
        tIncome = (PRICE * .60) * amtSold;
        cout << "The total cost of the purchase is: " << tIncome << endl;
    }
    else if (amtSold > 99)    
    {
        tIncome = (PRICE * .50) * amtSold;
        cout << "The total cost of the purchase is: " << tIncome << endl;
    }
    else
        cout "Something went wrong! Try again." << endl;
                
    return 0;
}

