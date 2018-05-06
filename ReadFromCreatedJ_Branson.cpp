/*
Jonathan Branson - CreateFileJ_Branson.cpp

This program will read that file that was created from the file we
created.

*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
    //Hold the file and variables for data the is being read
    string fileName = "F:\\C++\\ERG_126\\week9\\myNewFile.txt";
    string firstName;
    double hourlyRate, sum = 0;

    //ifstream object
    ifstream inFile;

    //Open file
    inFile.open(fileName.c_str());

    //Catches if file not found
    if (!inFile.fail()){

        cout << "A file named " << fileName << " does exist.\n\n"
             << "It is located on the Drive C within the dolder DataFiles. \n\n";

    }
    else{

        cout << "The file was not successfully opened.";
        exit(1);
    }

    //Reads file and collects the data and prints it
    while (inFile.good()){

        inFile >> firstName;
        inFile >> hourlyRate;
        sum += hourlyRate;

        if (inFile.good()){

            cout << firstName << " " << hourlyRate << '\n';
        }
    }

    cout << "\nSum of the hourly rares is " << sum << '\n';

    //Close file
    inFile.close();

    cout << "\n\nData has been successfully displayed.\n";

    return 0;
}
