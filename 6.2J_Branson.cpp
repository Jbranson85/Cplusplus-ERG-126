/*
Program rounds a number that the user inputs

Jonathan Branson - Exercise 6.2 #11


*/
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

//Function Prototype
double rounding(double);

//Main function
int main()
{
    //Variable
    double number;

    //Prompt for user input
    cout << "Enter a number you would like to round." << '\n';
    cin >> number;

    //Print of for around number call the round function to get out put
    cout << "\n\n" << fixed << number << " rounded at two decimal places = ";
    cout.unsetf(ios_base::fixed);//Removing format
    cout << round(number) << '\n';
    return 0;
}
//Rounding function
double round(double number){

    int new_Num;

    number = number * pow(10,3);

    number = number + 0.5;

    new_Num = static_cast <int>(number);

    number = new_Num / pow(10,3);

    return number;


}
