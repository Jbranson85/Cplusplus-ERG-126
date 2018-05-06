/*
Jonathan Branson
Find the area of a circles
*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{

    double radius, area;

    cout << "\nEnter the radius of the circle.\n";
    cin >> radius;

    area =  M_PI * pow(radius,2);

    cout << "\nThe Area of the circle = " << area
         << '\n';

    return 0;
}
