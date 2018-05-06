/*
 This program is used to show the different types of loop, contains task 1-10.
 Only uses positive and whole numbers

 Jonathan Branson - TenTaskJ_Branson.cpp

*/
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cmath>


using namespace std;

//Prototype functions
void menu();
void validation(string, int &);
void task0();
void task1();
void task2();
void task3();
void task4();
void task5();
void task6();
void task7();
void task8();
void task9();
void continue_Prog (char &);

int main()
{
    char run_Again;//Variable used for continuing program
    do{
        menu();//Call menu function
        continue_Prog(run_Again);//Call function to prompt user to run program again or quit

    }while(run_Again == 'Y');


    return 0;
}

void menu(){

    //Local Variables used for this function
    string input;
    int test_Num;
    //Menu output
    cout << setw(50) <<"Ten Task Program\n\n";
    cout << setw(20) <<"Menu Choices\n";
    cout << "-------------------------\n";

    for(int x = 0; x < 10; x++){

        cout << setw(5) << x << " - Task " << x   << '\n';
    }
    cout << "-------------------------\n";

    //Loop for valid input, run till input is valid
    do{
        cout << "\nEnter Choice\n";
        getline(cin, input);//Gets user input as a string

        validation(input,test_Num);//Call validation function to validate input

    }while(test_Num < 0);//End loop

    //Switch statement for the 10 tasks
    switch(test_Num){

        case 0:
            task0();
            break;

        case 1:
            task1();
            break;

        case 2:
            task2();
            break;

        case 3:
            task3();
            break;

        case 4:
            task4();
            break;

        case 5:
            task5();
            break;

        case 6:
            task6();
            break;

        case 7:
            task7();
            break;

        case 8:
            task8();
            break;

        case 9:
            task9();
            break;

        //Error catcher
        default:
            system("cls");//clears screen
            menu();

    }//End switch

}
/*

    The users input will then be ran through validation to make sure that the input is numbers only and
    is greater than 0 and are whole numbers. The validation is handled by reading input as a string, and the
    parsing the sting into chars. The chars are checked with their ASCII value of the
    character and checked by several statements. If input is valid it will then be converted  to int
    and returned as array_Size. This function will run until valid data is entered. ***This is a working progress,
    still needs more testing, but seems to catch everything so far. If any error are found please inform me.
*/

void validation(string input, int & test_Num){

    //Resets test_Number since it is being used over and over, not necessary but a safe fail
    test_Num = 0;

    //for loop that will loop and check every char one by one for invalid input data
    for(int x = 0; x <  input.length(); x++){



        //If statement to catch Invalid ASCII code/value, only 0-9 and decimal are aloud to be used
        if( (input[x]<= 47) || (input[x] >= 58)){

            cout << "\nINVALID INPUT\n";//Informs user of invalid input
            test_Num = -1;//Sets test number to -1 so when returned back to main, so it will loop again
            break;//Breaks out of for loop as soon as it finds invalid char
        }
        //Check for invalid ex. 00235, 05663, etc.
        else if ((input[0] == 48) && (!(input[1] == 46)) && (input[1] != 0)){

                    cout << "\nINVALID INPUT\n";//Informs user of invalid input
                    test_Num = -1;//Set bool to false, make program loop again
                    break;
                }

    }//End of for loop

    //If all input chars are valid
    if (test_Num > -1){

        //Converts the string to a double, found in Chapter 9 pg. 556
        test_Num = atoi(input.c_str());


        //Used to catch zero, because just zero is a invalid input when by itself
        if ((test_Num < 0)){

            cout << "\nINVALID INPUT\n";//Informs user of invalid input
            test_Num = -1;//Sets test number to -1 so when returned back to main, so it will loop again
        }
    }

}

//Task 1
void task0(){

    //Local variables
    int i = 1;

    cout << "\n\n";
    //Loop till i = 100
    while(i < 101){

        cout << setw(2) << i << " ";
        //new line every ten numbers
        if(i % 10 == 0){

            cout << '\n';
        }
        i++;//counter
    }
}

//Task2
void task1(){

    //Local Variables
    string input;
    int test_Num;
    int number_1;
    int number_2;
    //Loop for validation
    do{
        cout << "\nInput initial number" << '\n';
        getline(cin, input);
        validation(input,test_Num);//Call validation function to validate input


    }while(test_Num < 0);

    number_1 = test_Num;//set number_1 = valid test number

    //Loop for validation
    do{
        cout << "\nInput terminal number" << '\n';
        getline(cin, input);
        validation(input,test_Num);//Call validation function to validate input

    }while(test_Num < 0);

    number_2 = test_Num;//set number_2 = valid test number

    cout << '\n';

    //Loop to get the number in between users input
    for(number_1; number_1 <= number_2; number_1++){

        cout << number_1 << " ";
    }
    cout << '\n';

}

//Task3
void task2(){

    //Local Variables
    string input;
    int test_Num;
    int num_1 = 1;
    int num_2;
    int total = 0;
        //loop for validation
        do{

        cout << "\nInput end number" << '\n';
        getline(cin, input);
        validation(input,test_Num);//Call validation function to validate input

    }while(test_Num < 0);

    num_2 = test_Num;//Set num_2 = valid test number

    cout << '\n';

    //Loop to get the total
    while (num_1 <= num_2){

        total = total  + num_1;
        num_1++;
    }
    //Output total
    cout << "\nTotal of 1 to " << num_2 << " = " << total << '\n';
}

//Task4
void task3(){

    //Local variable
    int i = 100;
    //Loop until i = 2
    while(i > 2){

        //Loop print out number subtracted by 2
        for(i; i >= 2; i = i - 2){

            cout << setw(2) <<  i  << ", ";
        }

    }
    cout << '\n';

}

//Task5
void task4(){

    //Local Variable
    char start = 'A';

    //Loop to print A - Z
    while(start < 'Z'){

        for(start; start <= 'Z'; start++){

            cout << setw(2) << start << ", ";

        }
    }
    cout << '\n';
}

//Task6
void task5(){

    cout << '\n';
    //Loop to find and print x, square root of x, and x squared
    for(int x = 1; x < 26; x++){

       cout << setw(3) << x;
       cout << setw(7) << fixed << showpoint << setprecision(3) << (sqrt(x));
       cout << setw(7) << fixed << noshowpoint << setprecision(0) << pow(x,2);
       cout << '\n';
    }
}

//Task7
void task6(){

    //Local Variables
    string input;
    int test_Num;
    int number_1;
    int number_2;
    int total = 0;
    //Loop for validation
    do{
        cout << "\nInput initial number" << '\n';
        getline(cin, input);
        validation(input,test_Num);//Call validation function to validate input


    }while(test_Num < 0);

    number_1 = test_Num;//Set number_1 = to a valid test number

    //Loop for validation and that second input is larger then first input
    do{
        cout << "\nInput terminal number" << '\n';
        getline(cin, input);
        validation(input,test_Num);//Call validation function to validate input

    }while(test_Num < 0 || test_Num <= number_1);

    number_2 = test_Num;//Set number_2 = to a valid test number

    cout << '\n';

    //Loop to total the number counting up from first to second number
    for(number_1; number_1 <= number_2; number_1++){

        total += number_1;
    }
    cout << "Total = " << total;//print total

}

//Task8
void task7(){

    //Local Variables
    string input;
    int test_Num;
    int total = 0;
    float avg = 0;

    //Loop to get 10 inputs
    for(int x = 0; x < 10; x++){

        //Loop for validation
        do{
        cout << "\nInput a number" << '\n';
        getline(cin, input);
        validation(input,test_Num);//Call validation function to validate input


        }while(test_Num < 0);

    total += test_Num;//Totals the inputs

    }
    avg = float(total) / 10;//Finds average
    cout << "\nThe average = " << avg << '\n';//Prints average

}

//Task9
void task8(){

    //Local Variables
    string input;
    int test_Num;
    int number_1;
    int choices;
    int total = 0;
    float avg = 0;

    //Loop for validation
    do{

        cout << "Input number of values you want to enter." << '\n';
        getline(cin, input);
        validation(input,test_Num);//Call validation function to validate input


    }while(test_Num < 0);

    choices = test_Num;// get choices from valid test_Num

    //Loops for amount of choices user input
    for(int x = 0; x < choices; x++){

        //Loop for validation
        do{
            cout << "\nInput a number" << '\n';
            getline(cin, input);
            validation(input,test_Num);//Call validation function to validate input


        }while(test_Num < 0);

    total += test_Num;//Adds inputs to total
    }
    avg = float(total) / choices;//finds average
    cout << "\The average = " << fixed << showpoint << setprecision(3)
         << avg << '\n';//prints average

}
//Task10
void task9(){

    //Local Variables
    string input;
    int test_Num;
    int number_1;
    int i = 0;
    int total = 0;
    float avg = 0;

    //Loop till exit is met
    do{
        //Loop for validation
         do{

            cout << "Input a number. Enter 999 to quit" << '\n';
            getline(cin, input);
            validation(input,test_Num);//Call validation function to validate input


        }while(test_Num < 0);

        total += test_Num;//Add test_Num to total
        i++;//Counter

    }while(test_Num != 999);//End when total is greater the 20

    total -= 999;//removes the 999
    cout << "\nTotal = " << total << '\n';//Print total
    avg = (float(total)/ i);//finds average
    cout << "\nAverage = " << fixed << showpoint << setprecision(3) <<avg << '\n' ;//Prints and formats average


}

/*
    Function for validation of continue_Prog user input. This function will ask user if the want to run program
    again. Function then checks the input and validates input. It only will take the first letter of what the
    user inputs, and converts it to uppercase. If it is not valid it will run until its valid and will return
    the char back to main for the do while loop to continue or close program.
*/
void continue_Prog(char & run_Again){

    run_Again = ' ';//Reset variable to empty to prepare for user input when program is ran more then once

    cout << "\n\nWould you like to run program again? (Y or N)\n";
    cin >> run_Again;//Gets user input
    cin.sync();//Used to only take first letter or Char of input
    run_Again = toupper(run_Again);//Formats it to uppercase

    //Loop used for validation of user input, checking for Y or N only, runs until correct input is entered
    while ((run_Again != 'Y') && (run_Again != 'N')){

        cout << "\nINVALID INPUT\n"
             << "\nWould you like to run program again (Y or N)\n";
             cin >> run_Again;//Get user input
             cin.sync();//Used to only take first letter or Char of input
             run_Again = toupper(run_Again);//Formats it to uppercase

    }//End of loop

    //If statement to clear screen if user want to run program again
    if (run_Again == 'Y'){

        system("cls");//clears screen
    }
}
