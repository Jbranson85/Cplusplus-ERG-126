/*
Jonathan Branson -  Chapter 2 #1
Finds the Area of a triangle.
*/

#include <iostream>
#include <iomanip>
#include <cmath>



using namespace std;

int main()
{
    //Variables
    float height, base, area;

    //Input - Output to find height and base
    cout << "\nEnter in the height of the Triangle.\n";
    cin >> height;

    cout << "\nEnter in the base of the Triangle.\n";
    cin >> base;

    //Equation for area of triangle
    area = .5 * base * height;

    //Output for the area
    cout.precision(2);
    cout << "\nThe area of the triangle = " << area << '\n';

    return 0;
}
