/*
This program will print a calender for the month of November 2017

Jonathan Branson - CalenderJ_Branson.cpp
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    //Output for Month and days
    cout << setw(45) << "November 2017" << "\n\n";
    cout << setw(10) << "Sun" << setw(10) << "Mon" << setw(10) << "Tues" << setw(10)
         << setw(10) << "Weds" << setw(10) << "Thurs" << setw(10) << "Fri" << setw(10) << "Sat"
         << '\n';


    //Loop to place outputs for days of the month
    for(int x = 1; x < 31; x++){

        //Starting point
        if(x == 1){

            cout << setw(40) << "1";
        }

        //Used for new line going from Saturday to Sunday
        else if((x == 5) || (x == 12) || (x == 19) || (x == 26)){

            cout << '\n';
            cout << setw(10) << x ;
        }
        //Used for everything else
        else{

            cout << setw(10) << x ;
        }

    }

    cout << '\n';

    return 0;
}
