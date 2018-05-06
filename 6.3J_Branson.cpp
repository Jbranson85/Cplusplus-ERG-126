/*
This program allows user to enter total seconds and will convert to
HH:MM:SS for total seconds.

Jonathan Branson - Exercise6.3 #5
*/

#include <iostream>

using namespace std;

//Prototype for function
int time(int, int&, int&, int&);

int main()
{
    //Variables
    int seconds, hours = 0, mins = 0, secs = 0;

    //Get user input
    cout << "Enter total seconds recorded:" << '\n';
    cin >> seconds;

    //Call function time to get conversion
    time(seconds, hours, mins, secs);

    //Output HH:MM:SS
    cout << seconds << " seconds" << " = " << hours << " Hours " << mins << " Minutes " << " and " << secs << " Seconds" << '\n';

    return 0;
}

//Time function
int time(int seconds, int& hours, int& mins, int& secs){

    //Calculations for find sec, mins, hours
    secs = (seconds % 60);
    mins = (seconds / 60) % 60;
    hours = (seconds / 60) / 60;

    return hours, mins, secs;



}
