/*
Program will ask user number of hours and determine the remaining
bacteria in a culture.

Jonathan Branson - Chapter3-#4J_Branson.cpp

*/


#include <iostream>
#include <cmath>
#include <stdlib.h>

using namespace std;

int main()
{
    //Variables
   double time_Hours, num_Bacteria;
   double eulers_Num = 2.71828;
   char continue_1 = 'Y';

    //Main loop to run until user is done
   while (continue_1 == 'Y'){

    //User Input
    cout << "\nEnter the number of hours.\n";
    cin >> time_Hours;

        /*While loop to check for correct entry by using the cin fail
          Cin fail will keep the loop from becoming infinite loop if wrong data is entered
          Will ask user to Re-enter data if incorrect...still working process
        */
        while (cin.fail()){

                cin.clear();//clears the cin
                cin.ignore();//Ignores input
                cout << "\nINVAID INPUT."
                     << "\nEnter the number of hours.\n";
                cin >> time_Hours;
         }

    num_Bacteria = 300000 * pow(eulers_Num, (-0.032 * time_Hours));

    //Output w/ formatting to include 2 dec. places
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << "The number of Bacteria remaining in the culture = " << num_Bacteria
         << '\n';

     //Reset continue variable to empty, to keep program running
            continue_1 = ' ';

        //Loop to confirm user wants to run program again, includes error checking for user entry
        while ((continue_1 != 'Y') && (continue_1 != 'N')){

                cout << "\n\nWould you like check again for different hour amount? (Y/N)\n";
                cin >> continue_1;

                if (continue_1 == 'Y'){

                    //Clear Console screen
                    system("cls");
                }
            }
   }
    return 0;
}
