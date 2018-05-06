/*
Jonathan Branson - creatfileJ_Branson.cpp

this program will create a file and input data into the file.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
    //hold the file and input
    string fileName = "F:\\C++\\ERG_126\\week9\\myNewFile.txt";
    string line;

    //out stream object
    ofstream outFile;

    //Opens the file
    outFile.open(fileName.c_str());

    //Catches if file falls
    if (outFile.fail()){

        cout << "The file was not Successfully opened.";
        exit(1);
    }
    //Data added to the file
    outFile << "Matt   " << 24.55 << '\n'
            << "Debbie " << 12.78 << '\n'
            << "Anna   " << 10.05 << '\n'
            << "Sam    " << 12.86 << '\n'
            << "Bobby  " << 45.17 << '\n';

    //Close file
    outFile.close();

    cout << "\n\nDada has been successfully written to the file.\n";

    return 0;
}
