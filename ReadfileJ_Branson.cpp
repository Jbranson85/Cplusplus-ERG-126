/*
Jonathan Branson - ReadfileJ_Branson.cpp

This program will read and print the file.

*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
    //hold file and input
    string fileName = "F:\\C++\\ERG_126\\week9\\myFile.txt";
    string line;

    //input file stream object
    ifstream inFile;

    //open the file
    inFile.open(fileName.c_str());

    //Catches if open file does not exist
    if (!inFile.fail()){

        cout << "A file named " << fileName << " does exist.\n\n"
             << "It is located on the Drive C within the dolder DataFiles. \n\n";

    }
    else{

        cout << "The file was not successfully opened.";
        exit(1);
    }
    //Loop to print file
    while(getline(inFile,line)){

        cout << line << '\n';
    }
    //close file
    inFile.close();

    cout << "\n\nGoodBye\n";


    return 0;
}
