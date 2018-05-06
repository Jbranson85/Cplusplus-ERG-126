/*
Jonathan Branson - Program 5.17 - Program-5.17J_Branson.cpp
*/

#include <iostream>
#include <stdlib.h> //srand doesn't work without this libary..<cmath> doesn't work
#include <ctime>


using namespace std;

int main()
{
    const int Nums = 10;
    double rand_Value;


    srand(time(NULL));//Generates the first seed value

    for(int x = 1 ; x <= Nums; x++){

        rand_Value = rand();
        cout << rand_Value << '\n';
    }


    return 0;
}
