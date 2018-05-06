/*
This program ask user to enter in the water head for a hydroelectric generation
and determiners the head site.

Jonathan Branson - Chapter42-#7.cppp
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    //Variables
    double water_Head;
    char continue_1 = 'Y';

    //Main loop for the program
    while(continue_1 == 'Y'){

        cout << "\nEnter in the water's head.\n";
        cin >> water_Head;
        //If statements to check the water head
        if (water_Head < 10){

            cout << "This is a low-head site.\n";
        }
        else if (water_Head > 20){

            cout << "This is a high-head site.\n";
        }
        else {

            cout << "This site is between a low and high-head site.\n";
        }

        //Reset continue
        continue_1 = ' ';


        //Loop to confirm user wants to run program again, includes error checking for user entry
        while ((continue_1 != 'Y') && (continue_1 != 'N')){

                cout << "\n\nWould you like check again? (Y/N)\n";
                cin >> continue_1;

                if (continue_1 == 'Y'){

                    //Clear Console screen
                    system("cls");

                }
            }
    }
    return 0;
}
