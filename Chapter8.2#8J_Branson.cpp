/*
Jonathan Branson - Chapter8.2#8J_Branson.cpp

This program will get input from a file and output the data, and
will also find the MPG for each vehicle.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip>



using namespace std;

int main()
{
    //File and variables
    string fileName = "info.txt";
    int car_Num, miles, gallons;
    double mpg = 0.0;

    //ifstream object
    ifstream inFile;

    //open file
    inFile.open(fileName.c_str());

    //File not found
    if (inFile.fail()){

        cout << "ERROR COULD NOT FIND FILE";
        exit(1);
    }

    cout << "Car #" << setw(22) << "Miles Driven" << setw(21) << "Gallons Used"
         << setw(20) << "Average MPG" <<  '\n';
    cout << "--------------------------------------------------------------------\n";

    //Getting input from file and outputting
    while(inFile >> car_Num >> miles >> gallons){

        //Calculation for MPG
        mpg = static_cast<double> (miles) / static_cast<double> (gallons);

        cout << car_Num << setw(20) <<  miles << setw(21) << gallons << setw(20)
             << fixed << showpoint << setprecision(2) << mpg
             <<'\n';
        cout << "--------------------------------------------------------------------\n";

    }
    //close file
    inFile.close();
    return 0;
}
