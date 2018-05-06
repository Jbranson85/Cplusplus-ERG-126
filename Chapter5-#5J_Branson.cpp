/*
This program will convert meters from feet, at increments of 3 ft.

Jonathan Branson - Chapter5-#5J_Branson.cpp

*/
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    //Variable
    double meters;

    //For loop for conversion from 3 to 30 at 3ft increments
    for (int x = 3; x < 31; x += 3){

        cout << fixed << showpoint << setprecision(2);//Formating output
        meters = x / 3.28;//Calculation
        //Output
        cout << x << " Feet = " << meters << " Meters"
             << '\n';

    }
    return 0;
}
