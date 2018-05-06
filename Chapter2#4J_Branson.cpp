/*
Jonathan Branson - Chapter 2 #4
Finds the sum of a sequence
*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    //Variables
    int n, a, d;
    double sum;

    //Input and Output needed for equation
   cout << "\nEnter the number of integers to be added.\n";
   cin >> n;

   cout << "\nEnter the first integer number.\n";
   cin >> a;

   cout << "\nEnter the difference between each number.\n";
   cin >> d;

   //Calculation
   sum = (n/2) * (2 * a + (n-1) * d);

   //Output the sum of the sequence
   cout << "\nThe sum of the sequence = " << sum
        << '\n';


    return 0;
}
