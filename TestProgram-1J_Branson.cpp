/*
Test Problem #1

This program will calculate the interest and new principle for the user. The user will input
the original principle, rate, time(years), and will calculate the interest. With the interest
the program will then calculate the new principle after adding the interest. The program also has
input validation, so users can only input 0-9 and decimal point (See validation function for more
details).

Jonathan Branson - TestProgram-1J_Branson.cpp
*/

#include <iostream>
#include <iomanip>
#include <string>  //Used for strings and for loop to check validation
#include <cstdlib> //Used for converting sting to double using atof-Chapter 9 pg.556

using namespace std;

//Prototype functions
void validation (string, double &);//Validation function user input
void getContinue_Prog(char &);//Validation function for user to continue or end program
double interest_Gained (double, double, double);//Finding interest function
double final_Principle(double, double);//Finding total principle function

int main()
{

    string test_Input;//Variable used for testing input
    double test_Number;//This double will be used over and over for testing Validation
    double principle, rate, time, interest;//Double Variables used for program
    char continue_Prog = 'Y';//Used for user to run program again or quit

    //Main Loop to run until user decides to quit
    while(continue_Prog == 'Y'){

        //Start of first loop, principle
        do{
            cout << "\nEnter the principle amount.\n";
            getline(cin,test_Input);//Gets input as a string

            validation(test_Input, test_Number);//Call function Validation to check user input

        }while(test_Number < 0);//End first loop once input is valid

        principle = test_Number;//Set principle equal to valid input

        //Start of second loop, Rate
        do{
            cout << "\nEnter the Rate amount.\n";
            getline(cin,test_Input);//Gets input as a string

            validation(test_Input, test_Number);//Call function Validation to check user input

        }while(test_Number < 0);//End second loop once input is valid

        rate = test_Number;//Set rate equal to valid input

        //Start of third loop, time
        do {

            cout << "\nEnter the time amount(Years)\n";
            getline(cin, test_Input);//Gets input as a string

            validation(test_Input, test_Number);//Call function Validation to check user input

        }while(test_Number < 0);//End third loop once input is valid

        time = test_Number;//Set time equal to valid input

        //Calls interest_Gain function, that will return the value for interest
        interest = interest_Gained(principle, rate, time);

        //Final Output
        cout << fixed << showpoint << setprecision(2);//Formating for output
        cout << "\n\n***************************************"
             << "\nYour principle = $" << principle
             << "\nYour Interest earned = $" << interest
             //Calls function final_Principle, and return the value for total principle
             << "\nYour principle is now = $" << final_Principle(principle,interest)
             << "\n***************************************"
             << '\n';

        continue_Prog = ' '; //Reset variable to empty to prepare for user input

        //Call getContinue_Pro function to get and validate user input - returns user input
        getContinue_Prog(continue_Prog);

        //Switch statement for user input to run program again or end program, input comes from getContinue_Prog function
        switch(continue_Prog){

            //If user enters Y
            case 'Y':

                system("cls");//clears screen
                break;//Break from switch statement

            //If user enter N
            case 'N':

                break;//Break from switch statement, will end program

            //Catch input if validation fails and will end program
            default:

                cout << "\nERROR!!!\n"
                     << "Restart Program";
                exit(0);

        }//End of switch

    }//End of main loop

    return 0;
}

/*
This is the validation function, it keeps user from entering input that they should not,
it currently is working and will catch everything from letters to special characters. It uses
the ASCII code/value to determine if input in valid. *This is a working progress I have been working
on for few weeks now, so it my still not be 100% yet.
*/
void validation(string test_Input , double & test_Number)
{

    int check_Input;//Variable that will be used to convert char into ASCII code
    int  count_Dec;

    //Resets test_Number since it is being used over and over, not necessary but a safe fail
    test_Number = 0;

    //for loop that will loop and check every char one by one for invalid input data
    for(int x = 0; x <  test_Input.length(); x++){

        check_Input = int (test_Input[x]);//Converting the char to int to find ASCII code/value

        //If statement to catch Invalid ASCII code/value, only 0-9 and decimal are aloud to be used
        if((check_Input != 46 ) && (check_Input <= 47) || (check_Input >= 58)){

            cout << "\nINVALID INPUT\n";//Informs user of invalid input
            test_Number = -1;//Sets test number to -1 so when returned back to main, so it will loop again
            break;//Breaks out of for loop as soon as it finds invalid char
        }

        //Check for more then one decimal in the input
        else if(check_Input == 46){

                count_Dec++;//counter for every time a decimal is found

                //If statement catch more then one decimal is entered
                if(count_Dec > 1){

                    cout << "\nINVALID INPUT\n";//Informs user of invalid input
                    test_Number =-1;//Sets test number to -1 so when returned back to main, so it will loop again
                    count_Dec = 0;//Reset counter
                    break;//Breaks out for loop
                }
        }

    }//End of for loop

    //If all input chars are valid
    if (test_Number > -1){

        //Converts the string to a double, found in Chapter 9 pg. 556
        test_Number = atof(test_Input.c_str());
        count_Dec = 0;//Reset counter

        //Used to catch zero, because just zero is a invalid input when by itself
        if (test_Number == 0){

            cout << "\nINVALID INPUT\n";//Informs user of invalid input
            test_Number = -1;//Sets test number to -1 so when returned back to main, so it will loop again
        }
    }
}
/*
Function for validation of continue_Prog user input. This function will ask user if the want to run program
again. Function then checks the input and validates input. It only will take the first letter of what the
user inputs, and converts it to uppercase. If it is not valid it will run until its valid and will return
the char back to main for the switch statement to continue or close program.
*/
void getContinue_Prog(char & continue_Prog){

    cout << "\nWould you like to run program again? (Y or N)\n";
    cin >> continue_Prog;//Gets user input
    cin.sync();//Used to only take first letter or Char
    continue_Prog = toupper(continue_Prog);//Formats it to uppercase

    //Loop used for validation of user input, checking for Y or N only, runs until correct input is entered
    while ((continue_Prog != 'Y') && (continue_Prog != 'N')){

        cout << "\nINVALID INPUT\n"
             << "\nWould you like to run program again (Y or N)\n";
             cin >> continue_Prog;//Get user input
             cin.sync();//Used to only take first letter or Char
             continue_Prog = toupper(continue_Prog);//Formats it to uppercase

    }//End of loop

}

/*
Function for interest_Gained calculation, it will take the inputs from the main and will
returns the interest calculation amount to the main. returns principle * rate * time value
*/
double interest_Gained(double principle, double rate, double time){

    return principle * rate * time;
}

/*
Function for final_Principle calculation, it will take the input and the interest found
and will return the final principle amount to the main. returns principle + interest value
*/
double final_Principle(double principle, double interest){

    return principle + interest;
}
