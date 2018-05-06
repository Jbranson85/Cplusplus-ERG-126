/*
This program will ask user for initial value and a terminal value and produce
random number between the two.

Jonathan Branson -  Lesson 8 Quiz #1

*/

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <ctime>

using namespace std;

//Prototype for function
int random(int, int);

int main()
{
    //Variables
    int num_1, num_2;

    //Prompt for input for initial value
    cout << "Input a initial value" << '\n';
    cin >> num_1;

    //Prompt for input for terminal value
    cout << "\nInput a terminal value" << '\n';
    cin >> num_2;

    //Call random function
    random(num_1, num_2);

    return 0;
}

int random(int num_1, int num_2){

    //Local variable
    int rng_Value;

    //Generates the first seed value
    srand(time(NULL));

    //Loop to generate 5 random numbers
    for( int x = 0; x < 5; x++){

        //Used to get random number between the initial and terminal value
        rng_Value = rand() % ((num_2 - 1) - (num_1 + 1)) + (num_1 + 1);
        //Output the number
        cout << '\n' << x + 1 << " - "<< rng_Value << '\n';
    }
}
