/*
Jonathan Branson
Finds the relative damage to the road surface
*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{

   double relative_Damage, vehicle_Two, vehicle_One;

   vehicle_Two = 4000;


    cout << "\nEnter in the weight of the vehicle one.\n";
    cin >> vehicle_One;

    relative_Damage = pow((vehicle_Two / vehicle_One), 4);

    cout << "\nYour relative damage to the road surface = " << relative_Damage
         << '\n';


    return 0;
}
