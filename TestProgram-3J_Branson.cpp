/*
This program will allow user to input 5 grades, and then will calculate the average
of the 5 grades. It will then determine what grades are above average.  The program
also has input validation, so users can only input 0-9 and decimal point
(See validation function for more details).

Jonathan Branson- TestProgram-3J_Branson.cpp

*/
#include <iostream>
#include <iomanip>
#include <string>  //Used for strings and for loop to check validation
#include <cstdlib> //Used for converting sting to double using atof-Chapter 9 pg.556


using namespace std;

//Prototype functions
void user_Input(double &, double &, double &, double &, double &);//Function for user input
void validation (string, double &);//Validation function user input
double average(double, double, double, double, double);//Function to calculate the average
void output(double, double, double, double, double, double);//Function to display all output
void continue_Prog (char &);//Function for user input to run program again

//Main function
int main()
{
    char run_Again;//Variable used to run program again or close

    //Variables for grades and average
    double grade_1, grade_2, grade_3, grade_4, grade_5, avg;

    do{
        //Calls function for user input for grades, and returns grades
        user_Input(grade_1,grade_2,grade_3,grade_4,grade_5);

        //Calls function to do the calculation for average using the grades
        avg = average(grade_1, grade_2, grade_3, grade_4, grade_5);

        //Calls function for output and find what grades are above average
        output(grade_1, grade_2, grade_3, grade_4, grade_5, avg);

        continue_Prog(run_Again);

    }while(run_Again == 'Y');//End of loop, Ends when user choice is N



    return 0;
}
/*
This function is used to get user input and return grades to main. It works with the
validation function to get valid input for the grades.
*/

void user_Input(double & grade_1, double & grade_2, double & grade_3,double & grade_4,double & grade_5){

    //Local Variables used for this function
    string input;
    double test_Num;

    //For loop to get user input for the five grades
    for(int x = 0; x < 5; x++){

        //Loop for valid input, run till input is valid
        do{
            cout << "\nEnter Grade\n";
            getline(cin, input);//Gets user input as a string

            validation(input,test_Num);//Call validation function to validate input

        }while(test_Num < 0);//End loop

        //Switch statement to get each grade 1-5 from valid test_Num returned
       switch(x){

            //Grade 1
            case 0:
                grade_1 = test_Num;
                break;
            //Grade 2
            case 1:
                grade_2 = test_Num;
                break;
            //Grade 3
            case 2:
                grade_3 = test_Num;
                break;
            //Grade 4
            case 3:
                grade_4 = test_Num;
                break;
            //Grade 5
            case 4:
                grade_5 = test_Num;
                break;
            //Error catcher
            default:
                cout << "\nERROR!!!\n"
                     << "Restart Program";
                exit(0);
        }//End for loop

    }
}
/*
This is the input and validation function, it keeps user from entering input that they should not,
it currently is working and will catch everything from letters to special characters. It uses
the ASCII code/value to determine if input in valid. *This is a working progress I have been working
on for few weeks now, so it my still not be 100% yet.
*/
void validation(string input, double & test_Num){

    int check_Input;//Variable that will be used to convert char into ASCII code
    int  count_Dec;

    //Resets test_Number since it is being used over and over, not necessary but a safe fail
    test_Num = 0;

    //for loop that will loop and check every char one by one for invalid input data
    for(int x = 0; x <  input.length(); x++){

        check_Input = int (input[x]);//Converting the char to int to find ASCII code/value

        //If statement to catch Invalid ASCII code/value, only 0-9 and decimal are aloud to be used
        if((check_Input != 46 ) && (check_Input <= 47) || (check_Input >= 58)){

            cout << "\nINVALID INPUT\n";//Informs user of invalid input
            test_Num = -1;//Sets test number to -1 so when returned back to main, so it will loop again
            break;//Breaks out of for loop as soon as it finds invalid char
        }

        //Check for more then one decimal in the input
        else if(check_Input == 46){

                count_Dec++;//counter for every time a decimal is found

                //If statement catch more then one decimal is entered
                if(count_Dec > 1){

                    cout << "\nINVALID INPUT\n";//Informs user of invalid input
                    test_Num =-1;//Sets test number to -1 so when returned back to main, so it will loop again
                    count_Dec = 0;//Reset counter
                    break;//Breaks out for loop
                }
        }

    }//End of for loop

    //If all input chars are valid
    if (test_Num > -1){

        //Converts the string to a double, found in Chapter 9 pg. 556
        test_Num = atof(input.c_str());
        count_Dec = 0;//Reset counter

        //Used to catch zero, because just zero is a invalid input when by itself
        if (test_Num == 0){

            cout << "\nINVALID INPUT\n";//Informs user of invalid input
            test_Num = -1;//Sets test number to -1 so when returned back to main, so it will loop again
        }
    }

}

//This function is sent the 5 grades and the in the return statement does the calculation for the average
double average(double grade_1, double grade_2, double grade_3, double grade_4, double grade_5){

    //Return the avg of the 5 grades
    return (grade_1 + grade_2 + grade_3 + grade_4 + grade_5) / 5;
}

//This function handles the out for the program. It also will check for grades above average.
void output(double grade_1, double grade_2, double grade_3, double grade_4, double grade_5, double avg){

    //Output for the five grades
    cout << "\n\nGrades = " << grade_1 << ", " << grade_2 << ", "
         << grade_3 << ", " << grade_4 << ", " << grade_5
         << '\n';

    //Output for average
    cout << "\nAverage = " << avg
         << '\n';

    //Output for what grades are above average
    cout << "\nGrades that are above average"
         << "\n-----------------------------";

    //Checks each grade to see if it is above average and prints grade
    if (grade_1 > avg){

        cout << "\n\tGrade 1 - " << grade_1;
    }
    if (grade_2 > avg){

        cout << "\n\tGrade 2 - " << grade_2;
    }
    if (grade_3 > avg){

        cout << "\n\tGrade 3 - " << grade_3;
    }
    if (grade_4 > avg){

        cout << "\n\tGrade 4 - " << grade_4;
    }
    if (grade_5 > avg){

        cout << "\n\tGrade 5 - " << grade_5;
    }
    //If not grades are above the avg, output none
    if ((grade_1 <= avg) && (grade_2 <= avg) && (grade_3 <= avg) && (grade_4 <= avg) && (grade_5 <= avg)){

        cout << "\n\n\t   None";
    }

    cout << "\n\n";

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
