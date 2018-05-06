/*
Jonathan Branson - Lesson 2 quiz

The program will find the distance between two points.
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    //Variables for points needed
    double x_1, x_2, y_1, y_2, d;

    //Input/ Output to get all values
    cout << "\nEnter x value for for first point.\n";
    cin >> x_1;

    cout << "\nEnter y value for the second point.\n";
    cin >> y_1;

    cout << "\nEnter x value for the second point\n";
    cin >> x_2;

    cout << "\nEnter y value for the second point\n";
    cin >> y_2;

    //Calculations for the distance between two points
    d = sqrt((pow((x_2 - x_1), 2) + pow((y_2 - y_1), 2)));


    cout <<  setprecision(3) << "The distance between two points = " << d
         << '\n';

    return 0;
}
