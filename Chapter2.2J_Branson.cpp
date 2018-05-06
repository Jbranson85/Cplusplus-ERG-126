//Jonathan Branson
//Chapter 2.2 Averages three grades
#include <iostream>

using namespace std;

int main()
{
    //declarations
    int grade1;
    int grade2;
    int grade3;
    int sum;
    double average;

    //Assign values to variables
    grade1 = 87;
    grade2 = 93;
    grade3 = 75;

    //Do some math
    sum = grade1 + grade2 + grade3;
    average = sum / 3;

    cout << grade1 << " + " << grade2 << " + " << grade3
         << " = " << sum
         << "\n\n";

    cout << "The average of the three numbers is " << average << "\n";


    return 0;
}
