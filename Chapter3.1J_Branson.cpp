//Jonathan Branson
//Chapter 3.1

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    //variables
    int age;
    double hourlyRate;

    //Formatting
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    //Getting input
    cout << "Enter your age as an integer. ";
    cin >> age;
    cout << "\nEnter your hourly rate as a decimal. ";
    cin >> hourlyRate;

    cout << "\nYou entered " << age << " as your age.\n\n"
         << setw(10) << "1234567890\n"
         << setw(10) << age
         << '\n';

    cout << "\nYou entered " << hourlyRate << " as your hourly rate.\n\n"
         << setw(10) << "1234567890\n"
         << setw(10) << hourlyRate
         << '\n';

    age = hourlyRate;

    cout << "\nThe complier simply truncated hourlyRate and stored what it could in age.\n"
         << setw(10) << age
         << '\n';

    cout.setf(ios::scientific);
    cout << "\n" << hourlyRate << "\n";

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(12);

    cout << "\n The cosine of zero is " << cos(0) << "\n\n"
         << "\nThe square root of the hourly rate is approximately " << sqrt(hourlyRate) << "\n"
         << "Goodbye!"
         << endl;

    return 0;
}
