/*
Program ask user for input to find inertia for 3 different types
of beams I, Rectangular, and Cylinder.

Jonathan Branson - Chapter4-#5J_Branson.cpp
*/


#include <iostream>
#include <stdlib.h>
#include <cmath>

using namespace std;

int main()
{
    //Variables
    char choice, continue_1 = 'Y';
    double height_Out, height, base, radius, thickness, inertia;

    //Loop for main to run until user is done
    while(continue_1 == 'Y'){

            //Loop in case user does not enter A,B,C
            while ((choice != 'A') && (choice != 'B') && (choice != 'C')){

                     cout << "\nEnter a choice for inertia would you like to check.\n"
                          << "Choices are I-Beam , Rectangular Beam , Cylinder Beam\n"
                          << "\nEnter A for I-Beam\n"
                          << "Enter B for Rectangular Beam\n"
                          << "Enter C for Cylinder Beam\n"
                          << '\n';
                     cin >> choice;

                //Switch statement for menu choices
                switch(choice){

                    case 'A':
                        //Input
                        cout << "\nEnter outside height of the beam.\n";
                        cin >> height_Out;
                        cout << "\nEnter inside height of the beam.\n";
                        cin >> height;
                        cout << "\nEnter base of the beam.\n";
                        cin >> base;
                        cout << "\nEnter thickness of the beam.\n";
                        cin >> thickness;
                        //Calculations
                        inertia = base * pow(height_Out, 3) - (thickness/2) * pow(height, 3) / 12;
                        //Output and formating
                        cout.setf(ios::fixed);
                        cout.precision(2);
                        cout << "\nInertia = " << inertia;
                        break;

                    case 'B':
                        //Input
                        cout << "\nEnter base of the beam.\n";
                        cin >> base;
                        cout << "\nEnter height of the beam.\n";
                        cin >> height;
                        //Calculations
                        inertia = base * pow(height,3) / 12;
                        //Output and formating
                        cout.setf(ios::fixed);
                        cout.precision(2);
                        cout << "\nInertia = " << inertia;
                        break;

                    case 'C':
                        //Input
                        cout << "\nEnter radius of the beam.\n";
                        cin >> radius;
                        //Calculations
                        inertia = M_PI * pow(radius, 4) / 4;
                        //Output and formating
                        cout.setf(ios::fixed);
                        cout.precision(2);
                        cout << "\nInertia = " << inertia;
                        break;

                    default:
                        //Invalid choice output
                        cout << "\nInvalid choice.\n\n";
                }
            }

        //Reset continue and choice variable to empty, to keep program running
        continue_1 = ' ';
        choice = ' ';

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
