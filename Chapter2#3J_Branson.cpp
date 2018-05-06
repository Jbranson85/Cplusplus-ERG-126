/*
Jonathan Branson - Chapter2 #3
Finds the total numbers of hours for elapsed_time
*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    //Variables
    double total_Distance, avg_Speed, elapsed_Time;

    //Input - Output for total distance and speed
    cout << "\nEnter total distance of the trip.\n";
    cin >> total_Distance;

    cout << "\nEnter average speed traveled.\n";
    cin >> avg_Speed;

    //Calculations
    elapsed_Time = total_Distance / avg_Speed;

    //Output for elapsed time
    cout << "\nThe times that elapsed = " << elapsed_Time << " hours."
         << '\n';


    return 0;
}
