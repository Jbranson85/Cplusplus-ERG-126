/*
Test Program #2

This program is used to find the square root of real numbers. If the user uses a
negative number output will show a imaginary number. This program also uses functions
for testing all the data, so the main() mostly just calls the functions and keep program
running. The program also has input validation, so users can only input 0-9, negative sign,
and decimal point (See user_Input function for more details). Each function has details with
what is being done in each and where it will go next.

Jonathan Branson - TestProgram-2J_Branson.cpp

*/

#include <iostream>
#include <iomanip>
#include <string>  //Used for strings and for loop to check validation
#include <cstdlib> //Used for converting sting to double using atof-Chapter 9 pg.556
#include <cmath> //Used for calculations

using namespace std;

//Prototype functions
void user_Input();//Function for getting and validates user input
void check_Sign(double);//Function to check if input is positive or negative value
void pos_Num(double);//Function for positive number, does calculation, output value
void neg_Num(double);//Function for negative number, does calculation, output value
void continue_Prog (char &);//Function for user input to run program again

//Main Function
int main()
{
    char run_Again;//Variable used to run program again or close

    //Loop for main program
    do{
        user_Input();//Calls Function for user_Input
        continue_Prog(run_Again);//Call Function for user input to run program again

    }while(run_Again == 'Y');//End of loop, Ends when user choice is N

    return 0;
}
/*
This is the input and validation function, it keeps user from entering input that they should not,
it currently is working and will catch everything from letters to special characters. It uses
the ASCII code/value to determine if input in valid. *This is a working progress I have been working
on for few weeks now, so it my still not be 100% yet.
*/
void user_Input (){

    //Local variables to this function
    int check_Input, count_Dec = 0, count_Neg = 0;
    string input;
    bool invalid;//Used for do while loop for valid input
    //Variable that will be passed to next function
    double user_Num;

    //Main loop for Checking valid input
    do{

        cout << "\nEnter in a real number.\n";
        getline(cin, input);//Get input as string
        invalid = true;//Set bool value to true

        //For loop to check each char/letter in the String/Input
        for(int x = 0; x < input.length(); x++){

            //Convert char into int to check ASCII value
            check_Input = int (input[x]);

            //If statement to check for invalid input
            if((check_Input != 46 ) && (check_Input != 45) && (check_Input <= 47) || (check_Input >= 58)){

                cout << "\nINVALID INPUT\n";//Informs user of invalid input
                invalid = false;//Set bool to false, make program loop again
                break;//Breaks out of for loop as soon as it finds invalid char
            }
            //Check for duplicates of decimal usage
            else if(check_Input == 46){

                count_Dec++;//add to count every time decimal is used

                //If to catch if 2 or more decimals are entered
                if(count_Dec > 1){

                    cout << "\nINVALID INPUT\n";//Informs user of invalid input
                    invalid = false;//Set bool to false, make program loop again
                    count_Dec = 0;//Reset counter
                    break;//Breaks out of for loop as soon as it finds invalid char
                }
            }
            //Check for duplicates of negative signs
            else if (check_Input == 45){

                //add to count every time negative is used
                count_Neg++;

                //If to catch if 2 or more decimals are entered
                if (count_Neg > 1){

                    cout << "\nINVALID INPUT\n";//Informs user of invalid input
                    invalid = false;//Set bool to false, make program loop again
                    count_Neg = 0;//Reset counter
                    break;//Breaks out of for loop as soon as it finds invalid char
                }
            }

            //Checks if negative is not at the start of the number
            if ((check_Input == 45) && (x > 0)){

                cout << "\nINVALID INPUT\n";//Informs user of invalid input
                invalid = false;//Set bool to false, make program loop again
                count_Neg = 0;//Reset counter
                break;//Breaks out of for loop as soon as it finds invalid char
            }
        }//End of for loop

        //If input is valid
        if (invalid != false){

            invalid = true;//set bool to true to end loop
            user_Num = atof(input.c_str());//Convert string to a double
        }

    }while(invalid == false);//End main loop once invalid equals true

    check_Sign(user_Num);//Call/Move to check_Sign function and sending user input
}

//Function that checks user input (user_Num) for positive or negative number
void check_Sign(double user_Num){

    //If statement for numbers greater and equal to zero
    if (user_Num >= 0){

        pos_Num(user_Num);//Call/Move to pos_Num function sending user input
    }
    //If statement for numbers less then zero
    else if (user_Num < 0){

        neg_Num(user_Num);//Call/Move to neg_Num function sending user input
    }
}

//Function for positive numbers calculates square root and prints result
void pos_Num(double user_Num){

    double user_Num_pos;//Local variable
    user_Num_pos = sqrt(user_Num);//Find square root of user input and initialize variable

    cout << fixed << showpoint << setprecision(2);//Formating for output
    //Output user number and square root value
    cout << "\nThe square root of " << user_Num << " is " << user_Num_pos << "."
         << '\n';
}

//Function for negative calculates square root and prints result
void neg_Num(double user_Num){

    double user_Num_neg;//Local variable
    //Find square root of user input and initialize variable using absolute value then taking square root
    user_Num_neg = sqrt(abs(user_Num));

    cout << fixed << showpoint << setprecision(2);//Formating for output
    //Output user number and square root value with a i after since number is imaginary
    cout << "\nThe square root of " << user_Num << " is " << user_Num_neg << "i."
         << '\n';
}

/*
Function for validation of continue_Prog user input. This function will ask user if the want to run program
again. Function then checks the input and validates input. It only will take the first letter of what the
user inputs, and converts it to uppercase. If it is not valid it will run until its valid and will return
the char back to main for the switch statement to continue or close program.
*/
void continue_Prog(char & run_Again){

    run_Again = ' ';//Reset variable to empty to prepare for user input when program is ran more then once

    cout << "\nWould you like to run program again? (Y or N)\n";
    cin >> run_Again;//Gets user input
    cin.sync();//Used to only take first letter or Char
    run_Again = toupper(run_Again);//Formats it to uppercase

    //Loop used for validation of user input, checking for Y or N only, runs until correct input is entered
    while ((run_Again != 'Y') && (run_Again != 'N')){

        cout << "\nINVALID INPUT\n"
             << "\nWould you like to run program again (Y or N)\n";
             cin >> run_Again;//Get user input
             cin.sync();//Used to only take first letter or Char
             run_Again = toupper(run_Again);//Formats it to uppercase

    }//End of loop

    //If statement to clear screen if user want to run program again
    if (run_Again == 'Y'){

        system("cls");//clears screen
    }
}
