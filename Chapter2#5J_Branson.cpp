/*
Jonathan Branson Chapter2 #5
Program will determine the output velocity for water flowing through tube.
*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    //Variables
    double output_Velocity, input_Velocity, radius_Output, radius_Input;

    //Inputs and Outputs for Variables needed for equations
    cout << "\nEnter input velocity (ft/sec).\n";
    cin >> input_Velocity;

    cout << "\nEnter the radius of the input of the pipe (in.).\n";
    cin >> radius_Input;

    cout << "\nEnter the radius of the output of the pipe (in.).\n";
    cin >> radius_Output;

    //Calculation for output Velocity
    output_Velocity = ((input_Velocity * 12) * pow(radius_Input / radius_Output,2)) / 12;

    //Output for output velocity
    cout << "\nThe output velocity = " << output_Velocity << " ft/sec"
         << '\n';


    return 0;
}
