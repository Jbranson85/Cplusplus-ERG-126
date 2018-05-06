#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    double temp_F, temp_C;

    cout << "\nEnter in degrees in Celsius to convert to Fahrenheit.\n";
    cin >> temp_C;

    temp_F = (9.0 / 5.0) * temp_C + 32.0;

    cout << "\nThe temperature converted = " << temp_F << "F"
         << '\n';

    return 0;
}
