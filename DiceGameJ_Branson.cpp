/*
The program will role 2 dice 100 times and get total value of the dice each role. It then
will keep track of how many time 2 - 12 was the total amount on the dice.

Jonathan Branson - Dice game Quiz-#2
*/

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <ctime>


using namespace std;

//PhotoType for function
int random(int& , int& , int& , int& , int& , int& , int& ,
            int& , int& , int& , int& );


int main()
{
    //Variables
    int two = 0, three = 0, four = 0, five = 0, six = 0, seven = 0, eight = 0, nine = 0,
        ten = 0, eleven = 0, twelve = 0;

    cout << "Welcome to the Dice Game" << '\n';

    //Call random function to roll the dice 100 times and get totals
    random(two, three, four, five, six, seven, eight, nine, ten,  eleven, twelve);

    //Print out totals for each number 2 - 12
    cout << setw(10) << "\n\nNumbers Rolled " << setw(25) << "Total Times Rolled" << '\n';
    cout << "----------------------------------------" << '\n';
    cout << setw(7) << "2" << setw(25) << two << "\n\n" << setw(7) << "3" << setw(25) << three << "\n\n"
         << setw(7) << "4" << setw(25) << four << "\n\n" << setw(7) << "5" << setw(25) << five << "\n\n"
         << setw(7) << "6" << setw(25) << six << "\n\n" << setw(7) << "7" << setw(25) << seven << "\n\n"
         << setw(7) << "8" << setw(25) << eight << "\n\n" << setw(7) << "9" << setw(25) << nine << "\n\n"
         << setw(7) << "10" << setw(25) << ten << "\n\n" << setw(7) << "11" << setw(25) << eleven << "\n\n"
         << setw(7) << "12" << setw(25) << twelve << "\n\n";


    return 0;
}

int random (int& two, int& three, int& four, int& five, int& six, int& seven, int& eight,
            int& nine, int& ten, int& eleven, int& twelve){

    //Local Variables
    int rng_Value1, rng_Value2, total;

    //Generates the first seed value
    srand(time(NULL));

    //Loop for 100 rolls of the dice
    for(int x = 0; x < 100; x++){

        //first die
        rng_Value1 = rand() % (7 - 1) + 1;

        //second die
        rng_Value2 = rand() % (7 - 1) + 1;

        //Total amount on the dice
        total = rng_Value1 + rng_Value2;

        //Prints each roll
        //cout << "\n" << rng_Value1 << " " << rng_Value2;

         //Switch statement to keep track of the totals
        switch (total){

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
            case 10:
                    ten++;
                    break;
            case 11:
                    eleven++;
                    break;
            case 12:
                    twelve++;
                    break;
            default:

                    break;

        }

    }

}
