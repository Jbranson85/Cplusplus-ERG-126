/*
This program will let the user enter grades and will find the average of the grades. Is set up
so user can test sets of 6 grades for 4 students. Uses nested loops.
Program includes validation for user input.

Jonathan Branson -  Exercise5.6-#1J_Branson.cpp

*/


#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

using namespace std;

void float_Validation(string, float &, bool &);//Validation for double or float
void invalid_printOut(bool &);//Print out for invalid data

int main()
{
    int results = 4;
    float sum;
    float avg;
    string test_Input;
    bool temp_Invalid;
    float temp_Input;

   for(int x = 1; x <= results; x++){

        sum = 0;

        for(int i = 0; i <= 5; i++){

            do{

                cout << "Enter grade " << i + 1 << " for experiment number " << x << '\n';
                getline(cin, test_Input);//Get input as string

                float_Validation(test_Input, temp_Input, temp_Invalid);//Call validation function

        }while(temp_Invalid == false);//End do while when temp_Invalid returns true from validation function

       sum += temp_Input;

   }
        avg = sum/ 6;
        cout << fixed << showpoint << setprecision(2) << "\nThe average of the grades for experiment "
             << x << " = " << avg << "\n\n";
}

    return 0;
}

/*
   Validation
*/
void float_Validation(string test_Input, float & temp_Input, bool & Invalid){

    //Local Variables
    int check_Dec = 0;//Used for counters for decimals and negative signs
    Invalid = true;

    //Catches empty input
     if (test_Input.empty()){

        test_Input = " ";
    }

     //for loop that will loop and check every char one by one for invalid input data
    for(int x = 0; x < test_Input.length(); x++){

        //If statement to catch Invalid ASCII code/value, only 0-9, decimal and, Negative are aloud to be used
        //Checks for decimal or negative first and wont check rest of the if statement if decimal or neg are used
            if( (test_Input[x] != 46 ) && (test_Input[x] <= 47) || (test_Input[x] >= 58)){

                invalid_printOut(Invalid);//Call out for Invalid Input
                break;//Breaks out of for loop as soon as it finds invalid char
            }
            //Check for more then one decimal entered
            else if (test_Input[x] == 46){

                check_Dec++;//Add one if decimal is entered

                //If to catch if 2 or more decimals are entered
                if(check_Dec > 1){

                    invalid_printOut(Invalid);//Call out for Invalid Input
                    check_Dec = 0;//Reset counter
                    break;//Breaks out of for loop as soon as it finds invalid char
                }
            }


            if ((test_Input[0] == 46) && (test_Input[1] == '\0')){

                    invalid_printOut(Invalid);//Call out for Invalid Input
                    check_Dec = 0;//Reset counter
                    break;//Breaks out of for loop as soon as it finds invalid char

            }


               if ((test_Input[0] == 48) && (!(test_Input[1] == 46)) && (test_Input[1] != 0)){

                    invalid_printOut(Invalid);//Call out for Invalid Input
                    check_Dec = 0;//Reset counter
                    break;
                }


        }//End of for loop

        //If passes int validation test
        if (Invalid != false){

            temp_Input = strtof(test_Input.c_str(),0);//Converts string to float
            check_Dec = 0;//Reset counter

        }


}

//Output for invalid input
void invalid_printOut(bool & Invalid){

    cout << "\nINVALID INPUT\n";//Informs user of invalid input
    Invalid = false;//Set bool to false, make program loop again

}
