//Jonathan Branson
//Chapter 3.3
//It is possible to change the data type of an expression using casting

#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main()
{
    int num1, num2;

    cout << "Enter two integer values. ";
    cin >> num1 >> num2;

    cout << setiosflags(ios::fixed) << setprecision(4);

    cout << "The cast floating point sum is " << double(num1 + num2) << '\n';

    cout << "The integer sum is " << (num1 + num2) << '\n'
         << '\n';

    return 0;
}
