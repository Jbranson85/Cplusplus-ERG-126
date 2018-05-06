/*
Program ask user for two points and will calculate the mid-point for the x and y
for the two points.

Jonathan Branson - Chapter3-#3J_Branson.cpp

*/

#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    //Variables
    double x_1, y_1, x_2, y_2, midpoint_X, midpoint_Y;

    char continue_1 = 'Y';

    //Loop to run until user is done
    while(continue_1 == 'Y'){

        //User Input
        cout << "\nEnter in your X followed by Y for each Point(Press enter after each number)\n";
        cin >> x_1 >> y_1 >> x_2 >> y_2;

        /*While loop to check for correct entry by using the cin fail
          Cin fail will keep the loop from becoming infinite loop if wrong data is entered
          Will ask user to Re-enter data if incorrect...still working process
        */
        while (cin.fail()){

                cin.clear();//clears the cin
                cin.ignore();//Ignores input
                cout << "\nINVAID INPUT."
                     << "\nEnter in your X followed by Y for each Point(Press enter after each number)\n";
                cin >> x_1 >> y_1 >> x_2 >> y_2;
         }

        //Calculations for midpoints
        midpoint_X = (x_1 + x_2) / 2;
        midpoint_Y = (y_1 + y_2) / 2;

        //Output for mid points
        cout << "\nPoint 1 = " << "(" << x_1 << "," << y_1 << ")" << " and"
             << " Point 2 = " << "(" << x_2 << "," << y_2 << ")" << " and the"
             << " Midpoint = " << "(" << midpoint_X << "," << midpoint_Y << ")"
             << '\n';

        //Reset continue variable to empty, to keep program running
            continue_1 = ' ';

        //Loop to confirm user wants to run program again, includes error checking for user entry
        while ((continue_1 != 'Y') && (continue_1 != 'N')){

                cout << "\n\nWould you like to find another midpoint? (Y/N)\n";
                cin >> continue_1;

                if (continue_1 == 'Y'){

                    //Clear Console screen
                    system("cls");
                }
            }




    }

    return 0;
}
