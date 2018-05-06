//Jonathan Branson
//Chapter2.1 Prints out Initials and Salary

#include <iostream>

using namespace std;

int main()
{
    //Declaration Statements

    char myFirstInitial;
    char myMiddleInitial;
    char myLastInitial;

    int myAge;
    double mySalary;

    //Assignment statements follow
    myFirstInitial = 'M';
    myMiddleInitial = 'W';
    myLastInitial = 'F';
    myAge = 59;
    mySalary = 62559.98;

    cout << "\n\nMy Initials are " << myFirstInitial
         << myMiddleInitial << myLastInitial
         << "\n\n";

    //Some formatting for the decimal number follows
    cout.setf(ios::fixed); //decimals are fixed to precision desired
    cout.setf(ios::showpoint); //Always show the decimal point
    cout.precision(4); //Set for 4 decimal places to show..not really needed here...two would be enough

    cout << "My salary is: $" << mySalary << "\n\n";

    //So lets make it 2 decimals
    cout.precision(2); //Set two 2 decimals
    cout << "My salary to correct to two decimal places is: $" << mySalary
         << "\n\n";

    return 0;
}
