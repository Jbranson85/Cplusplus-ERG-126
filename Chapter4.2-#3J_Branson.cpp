/*
This prgram ask user for two number and then check what one is greater

Jonathan Branson - Chapter4.2-#3J_Branson.cpp
*/


#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    //Variables
    double num_1, num_2;
    char continue_1 ='Y';

    //Main loop for the program to run till user is done
    while (continue_1 == 'Y'){

        cout << "\nEnter two numbers(Press enter after each number).\n";
        cin >> num_1 >> num_2;

        //If statements to check which number is greater
        if (num_1 > num_2){

            cout << "\nNumber 1 is larger then Number 2.\n";
    }

        else{

            cout << "\nNumber 2 is larger then Number 1.\n";
    }
        continue_1 = ' ';

        //Loop to confirm user wants to run program again, includes error checking for user entry
        while ((continue_1 != 'Y') && (continue_1 != 'N')){

                cout << "\n\nWould you like check two numbers again? (Y/N)\n";
                cin >> continue_1;

                if (continue_1 == 'Y'){

                    //Clear Console screen
                    system("cls");

                }
            }

    }

    return 0;
}
