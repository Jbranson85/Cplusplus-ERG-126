/*
Jonathan Branson - Chapter8.2#7J_Branson.cpp

This program reads a file and the outputs social number,
name, and gross pay from the input data.

*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    //Holds file
    string fileName = "info.txt";
    //Variables
    char f_Name;
    string Name, Social;
    double hourly_Rate, gross_Pay = 0;
    int hours;
    //ifstream Object
    ifstream inFile;
    //Open file
    inFile.open(fileName.c_str());
    //Catches when file not found
    if (inFile.fail()){

        cout << "ERROR COULD NOT FIND FILE";
        exit(1);
    }

    cout << "Social" << setw(20) << "Name" << setw(21) << "Gross Pay" << '\n';
    cout << "----------------------------------------------------\n";

    //Read and get input from the file
    while(inFile >> f_Name >> Name >> Social >> hourly_Rate >> hours){

        //Calculation for gross pay
        gross_Pay = hourly_Rate * hours;

        //Outputs the data
        cout  << fixed << showpoint << setprecision(2) << Social << setw(10)
              << f_Name << " " << Name << "\t" << setw(15) << gross_Pay
              << '\n';
        cout << "----------------------------------------------------\n";
    }

    //Close file
    inFile.close();
    return 0;
}
