/*
This program allows user to enter length, width, and depth of a pool
to find the perimeter, volume, and underground surface area of a pool.

Program has so error test for user input, not 100%, but work pretty while

Jonathan Branson - Chapter3-#6J_Branson.cpp
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    //Variables and char variable for loops
    double length, width, depth, perimeter,
           volume, volume_Gal, surface_Area;

    char continue_1 = 'Y';

    //Loop for whole program
    while(continue_1 == 'Y'){

            //Input for length
            cout << "\nEnter the length of the pool.\n";
            cin >> length;

            /*While loop to check for correct entry by using the cin fail
              Cin fail will keep the loop from becoming infinite loop if wrong data is entered
              Will ask user to Re-enter data if incorrect...still working process
            */
            while (cin.fail()){

                cin.clear();//clears the cin
                cin.ignore();//Ignores input
                cout << "\nINVAID INPUT."
                     << "\nEnter the length of the pool.\n";
                cin >> length;
            }

            //Input for width..contains same error loop..check lines 28-30 for info
            cout << "\nEnter the width of the pool\n";
            cin >> width;
            while (cin.fail()){

                cin.clear();
                cin.ignore();
                cout << "\nINVAID INPUT."
                     <<"\nEnter the width of the pool\n";
                cin >> width;
            }

            //Input for depth..contains same error loop..check lines 28-30 for info
            cout << "\nEnter the depth of the pool\n";
            cin >> depth;
            while (cin.fail()){

                cin.clear();
                cin.ignore();
                cout << "\nINVAID INPUT."
                     << "\nEnter the depth of the pool\n";
                cin >> depth;
            }

            //Calculations for perimeter, volume(cubic ft), Gallons, Underground surface area
            perimeter = 2 * (length + width);
            volume = (length * width * depth);
            volume_Gal = volume * 7.48052;
            surface_Area = perimeter * volume;

            //Output
            cout << "\nPerimeter = " << perimeter << " Feet"
                 << "\nVolume = " << volume <<" Cubic Feet" << " or " << volume_Gal << " Gallons"
                 << "\nUnderground Surface Area = " << surface_Area << " Square Feet"
                 << '\n';

            //Reset continue variable to empty, to keep program running
            continue_1 = ' ';

            //Loop to confirm user wants to run program again, includes error checking for user entry
            while ((continue_1 != 'Y') && (continue_1 != 'N')){

                cout << "\n\nWould you like to check another pool? (Y/N)\n";
                cin >> continue_1;

                if (continue_1 == 'Y'){

                    //Clear Console screen
                    system("cls");
                }
           }
    }
    return 0;
}
