/*
Jonathan Branson Chapter 2 #6
Program finds the maximum load that can be placed at the end of a wooden beam.
*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;


int main()
{
    //Variables
    double max_Weight, stress, rect_Moment, distance_Load, half_Height, base, height;

    //Inputs and Output to collect all needed variables for calculations
    cout << "\nEnter the distance of the load from the fixed end (ft).\n";
    cin >> distance_Load;

    cout << "\nEnter the base of the beam (in).\n";
    cin >> base;

    cout << "\nEnter the height of the beam (in).\n";
    cin >> height;

    cout << "\nEnter the stress amount (lbs/in^2).\n";
    cin >> stress;

    //Calculations for all need variables
    rect_Moment = base * pow(height,3) / 12;

    half_Height = .5 * height;

    //Calculations for max_Weight
    max_Weight = stress * rect_Moment / (distance_Load * 12) * half_Height;

    //Output for max weight
    cout << "\nMax weight = " << max_Weight << "lbs"
         << '\n';

    return 0;
}
