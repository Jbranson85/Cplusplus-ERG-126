/*
This program will calculate power generation for hydroelectric generation.
Also will show power generation for heads 10-28 with 2 meter increments.

Jonathan Branson - Chapter5-#9J_Branson.cpp

*/
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    //Variables
    const double density = 998;//Cant be change inside program
    const double flow_Rate = 20;//Cant be change inside program
    const double grav_Acc = 9.81;//Cant be change inside program
    double power_Gen;
    int head = 14;

    //Calculation
    power_Gen = density * flow_Rate * head * grav_Acc;

    //Formating followed by output
    cout << fixed << showpoint << setprecision(2);//Formating output
    cout << "Head = " << head << " Power Generation = " << power_Gen
         << "\n\n\n";
    //Reset Variables
    head = 0;
    power_Gen = 0;

    //Loop for heads 10 - 28 at 2 meter increments
    for (head = 10; head < 29; head +=2){

        //Calculation
        power_Gen = density * flow_Rate * head * grav_Acc;

        //Formating followed by output
        cout << fixed << showpoint << setprecision(2);//Formating output
        cout << "Head = " << head << " Power Generation = " << power_Gen
             << '\n';
    }

    return 0;
}
