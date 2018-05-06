/*
User inputs hours work and program will determine salary.

Jonathan Branson - Chapter4-#4J_Branson.cpp

*/

#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    //Variables
    double hours, salary;
    char continue_1 = 'Y';

    //Main Loop, Runs until user is done
    while(continue_1 == 'Y'){

        //Users Hours input
        cout << "\nEnter number of hours worked.\n";
        cin >> hours;

        /*While loop to check for correct entry by using the cin fail
          Cin fail will keep the loop from becoming infinite loop if wrong data is entered
          Will ask user to Re-enter data if incorrect...still working process
        */
        while (cin.fail()){

                cin.clear();//clears the cin
                cin.ignore();//Ignores input
                cout << "\nINVAID INPUT."
                     << "\nEnter the number of hours worked.\n";
                cin >> hours;
         }

        //If statements to determine if user get overtime or entered invalid number(Negative number)
        if ((hours >= 0) && (hours <= 40)){

            salary = hours * 12.00;
            cout.setf(ios::fixed);
            cout.precision(2);
            cout << "\nYour salary is $" << salary
                 << '\n';
        }

        else if (hours > 40){

            salary = 40 * 12.00;
            hours = hours - 40;
            salary += (hours * 17.00);
            cout.setf(ios::fixed);
            cout.precision(2);
            cout << "\nYour salary is $" << salary
                 << '\n';
        }

        else {
            cout << "Invalid Amount"
                 << '\n';
        }

        //Reset continue variable to empty, to keep program running
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
