/*
Jonathan Branson -Chapter 3 #2
Finding the volume of a sphere
*/
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    //Variables
    double radius, volume;

    //Output and Input for radius of the sphere
    cout << "\nEnter the radius of the sphere.\n"
         << '\n';
    cin >> radius;

    //Calculation for volume of a sphere
    volume =  4 * M_PI * pow(radius,3) / 3;

    //Output volume of a sphere
    cout << "\nThe volume of the sphere = " << volume
         << '\n';

    return 0;
}
