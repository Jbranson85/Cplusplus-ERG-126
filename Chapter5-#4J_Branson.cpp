/*
Program will convert gallons to liters from 10 gal. to 20 gal.

Jonathan Branson - Chapter5-#4J_Branson.cpp
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    //Variable
    double liters;

    //For loop to print conversion for 10 - 20
    for(int x = 10; x < 21; x++){

        cout << fixed << showpoint << setprecision(2);//Formating output
        liters = x * 3.78541;//Calculation
        //Output
        cout << x << " Gallons = " << liters << " Liters"
             << '\n';
    }


    return 0;
}
