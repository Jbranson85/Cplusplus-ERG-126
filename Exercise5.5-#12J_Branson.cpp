/*
This program test the rand function for number from 0-9 for a total of 10 numbers

Jonathan Branson - Exercise 5.5-#12J_branson.cpp
*/

#include <iostream>
#include <iomanip>
#include <stdlib.h> //srand doesn't work without this libary..<cmath> doesn't work
#include <ctime>


using namespace std;

int main()
{
    //Variables used
    const int Nums = 10;
    int rand_Value;
    int zero = 0, one = 0, two = 0, three = 0, four = 0,
        five = 0, six = 0, seven = 0, eight = 0, nine = 0;


    srand(time(NULL));//Generates the first seed value

    for(int x = 1 ; x <= Nums; x++){

        rand_Value = rand() % 10;//rand numbers only between 0-9
        cout << rand_Value << '\n';

        //Switch statement to keep track of the rand numbers
        switch (rand_Value){

            case 0:
                    zero++;
                    break;
            case 1:
                    one++;
                    break;
            case 2:
                    two++;
                    break;
            case 3:
                    three++;
                    break;
            case 4:
                    four++;
                    break;
            case 5:
                    five++;
                    break;
            case 6:
                    six++;
                    break;
            case 7:
                    seven++;
                    break;
            case 8:
                    eight++;
                    break;
            case 9:
                    nine++;
                    break;
        }
    }

    //Prints output for total of each number
    cout << "\nZero's = " << zero << '\n'
         << "One's = " << one << '\n'
         << "Two's = " << two << '\n'
         << "Three's = " << three << '\n'
         << "Four's = " << four << '\n'
         << "Five's = " << five << '\n'
         << "Six's = " << six << '\n'
         << "Seven's = " << seven << '\n'
         << "Eight's = " << eight << '\n'
         << "Nine's = " << nine << '\n';



    return 0;
}
