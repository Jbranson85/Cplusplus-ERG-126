/*
Jonathan Branson - Final Project - Final-Project-J_Branson.cpp

This program will create a data file with ten names and phone numbers. User
then will be able to create a copy the file, create encrypt and decrypt the file, search
the the file by phone number, add and delete entries in the data file, and user can
print any of the files.

**Program also includes a option to delete the files, so that they can be re-created by the
program without restarting program or manually deleting the files.

**Program also has user input validation.

*/

//Libraries
#include <iostream>
#include <fstream>
//#include <cstdlib>
#include <string>
//#include <stdio.h>
#include <windows.h>
//#include <stdlib.h>
#include <vector>

using namespace std;

//Function Prototypes
void create_File();
void copy_File();
void encrypt_File();
void decrypt_File();
void add();
void find_Entry();
void name_Validation(string &, bool &);//Validation for names
void phone_Validation(string &, bool &);//Validation for phone number
void invalid_Output(bool &);
void print_Files();
void delete_Files();

//Function for menu
void menu(){

    //User choice Variable
    int menu_Choice;

    //Loop for valid input
    do{
        //Print Menu
        cout << "\n\n***********MENU OPTIONS***********" << '\n'
             << "*  <1> - Create Main File        *" << '\n'
             << "*  <2> - Print Files             *" << '\n'
             << "*  <3> - Create Copy File        *" << '\n'
             << "*  <4> - Create Encrypted File   *" << '\n'
             << "*  <5> - Create Decrypted File   *" << '\n'
             << "*  <6> - Search File             *" << '\n'
             << "*  <7> - Add/Delete Entry        *" << '\n'
             << "*  <8> - Delete Files            *" << '\n'
             << "*  <9> - Close Program           *" << '\n'
             << "**********************************\n" << '\n';

        //Get Choice
        cin >> menu_Choice;

        //Switch for user menu choice
        switch(menu_Choice){

            //Used for wrong input - ex. a, b, c, etc
            case 0:

                cout << "\n!!INVAILD INPUT!!";
                cin.clear();
                cin.ignore();
                break;
            //Create
            case 1:
                system("CLS");//Clear console
                create_File();//Call create_File function
                break;

            case 2:
                system("CLS");//Clear console
                print_Files();
                break;
            //Copy
            case 3:
                system("CLS");//Clear console
                copy_File();//Call copy_File function
                break;
            //Encrypt
            case 4:
                system("CLS");//Clear console
                encrypt_File();//Call encrypt_File function
                break;

            //Decrypt
            case 5:
                system("CLS");//Clear console
                decrypt_File();//Call decrypt_File function
                break;
            //Find
            case 6:
                system("CLS");//Clear console
                find_Entry();//Call find_Entry function
                break;
            //Add delete
            case 7:
                system("CLS");//Clear console
                add();//Call add function, also does the deleting
                break;
            //Delete files
            case 8:
                system("CLS");
                delete_Files();
                break;
             //Quit program
             case 9:
                cout << "\nProgram Closing in 3 seconds\n\n";

                //Its the final count down
                for(int x = 3; x > 0; x--){

                    cout << x << '\n' ;
                    Sleep(1000);//sleep for 1000 ms
                }

                cout << "\nGOODBYE\n";
                exit(0);
                break;

            default:

                cout << "\n!!INVAILD INPUT!!";


        }

    }while((menu_Choice < 1) || (menu_Choice > 8));
}

//Create file function
void create_File(){



    string file_Name = "datafile.txt";

    char continue_Program;


    ofstream outFile;

    //Used to check if file already exist, and inform user that it will overwrite if ran again
    if(fstream{"datafile.txt"}){

        cout << "\n!WARNING - RUNNING THIS WILL OVERWRITE YOU FILE!";

        //Loop to validate user input
        do{

            cout << "\nWould you like to create the File? (Y or N)\n";
            cin >> continue_Program;

            //Change input to upper
            continue_Program = toupper(continue_Program);


        }while((continue_Program != 'Y') && (continue_Program != 'N'));

        //User input = yes
        if(continue_Program == 'N'){

            Sleep(1000);//sleep for 2000ms
            system("CLS");//Clear console
            outFile.close();//close file
            //Call create file function
            outFile.close();//close file
            menu();
        }
    }


    outFile.open(file_Name.c_str());

    //If outfile.fails
    if (outFile.fail()){

        cout << "\n!!ERROR HAS OCCUARED!!\n";
        menu();
    }

    //If file is good, will input data to file
    if (outFile.good()){

        cout << file_Name << " was Successfully Created\n";

        outFile << "James Brown 555-6666" << '\n'
                << "Jake Miller 222-3333" << '\n'
                << "Sam Guy 589-4568" << '\n'
                << "Chris Carter 478-5684" << '\n'
                << "Don Dee 987-4305" << '\n'
                << "Green Wilson 774-2565" << '\n'
                << "Will Bee 334-6849" << '\n'
                << "Hank Grim 774-0235" << '\n'
                << "Johnny Bee 867-5309" << '\n'
                << "Mike Carr 440-8468" << '\n';


                Sleep(1000);//sleep for 2000ms
                system("CLS");//Clear console
                outFile.close();//close file
                menu();//Return to menu
    }
}

//Copy file function
void copy_File(){

    //Variables for files, input, and user input
    string file_Name = "datafile.txt";
    string file_Backup = "datafile.bak.txt";
    string line;
    char continue_Program;

    //input file stream object
    ifstream inFile;
    //output file stream object
    ofstream outFile;

    //open the file
    inFile.open(file_Name.c_str());
     //Opens the file
    outFile.open(file_Backup.c_str());

    //Catches if inFile does not exist
    if(inFile.fail()){

        cout << "\n!ERROR! " << file_Name << " DOES NOT EXIST!\n";

        //Loop to validate user input
        do{

            cout << "\nWould you like to create the File? (Y or N)\n";
            cin >> continue_Program;

            //Change input to upper
            continue_Program = toupper(continue_Program);


        }while((continue_Program != 'Y') && (continue_Program != 'N'));

        //User input = yes
        if(continue_Program == 'Y'){

            //Call create file function
            inFile.close();//close file
            outFile.close();//close file
            create_File();
        }

        //User input = no
        else{

            cout << "\nProgram will not work without creating a file first.\n";
            Sleep(1000);//sleep for 2000 ms
            system("CLS");//Clear console
            inFile.close();//close file
            outFile.close();//close file
            menu();//Return to menu
        }
    }

   //If file is good then input data to the new file
   if (outFile.good()){

        cout << '\n' << file_Backup << " was Successfully Created\n";

        while(getline(inFile,line)){

           //Gets line from file
           outFile << line << '\n';
        }

        cout << "\nCopy was Created\n";
        Sleep(1000);//sleep for 2000ms
        system("CLS");//Clear console
        inFile.close();//close file
        outFile.close();//close file
        menu();//Return to menu
    }
}

//Data encrypting function
void encrypt_File(){

    //Variables for files, input, and user input
    string file_Name = "datafile.txt";
    string file_Encrypt = "datafile.encrypted.txt";
    char continue_Program;

    //Vector arrays
    vector<string> first_Name;
    vector<string> last_Name;
    vector<string> phone_Num;
    vector<string> encrypt_First;
    vector<string> encrypt_Last;
    vector<string> encrypt_Num;

    //Strings used to fill arrays from file
    string first;
    string last;
    string phone;
    string e_First;
    string e_Last;
    string e_Num;


    //Temp variables
    string check;
    string insert_Name;

    //input file stream object
    ifstream inFile;
    //output file stream object
    ofstream outFile;

    //open the file
    inFile.open(file_Name.c_str());
     //Opens the file
    outFile.open(file_Encrypt.c_str());

    //Catches if inFile does not exist
    if(inFile.fail()){

        cout << "\n!ERROR! " << file_Name << " DOES NOT EXIST!\n";

        //Loop to validate user input
        do{

            cout << "\nWould you like to create the File? (Y or N)\n";
            cin >> continue_Program;

            continue_Program = toupper(continue_Program);


        }while((continue_Program != 'Y') && (continue_Program != 'N'));

        //User input = yes
        if(continue_Program == 'Y'){


            inFile.close();//close file
            outFile.close();//close file
            create_File();//Call create file function
        }

        //User input = no
        else{

            cout << "\nProgram will not work without creating a file first.\n";
            Sleep(1000);//sleep for 2000 ms
            system("CLS");//Clear console
            inFile.close();//close file
            outFile.close();//close file
            menu();//Return to menu
        }
    }

   //If file good, start to encrypt file
   if (outFile.good()){

        cout << '\n' << file_Encrypt << " was Successfully Created!\n\n";

        //Gets input from file to place in arrays
        while(inFile >> first >> last >> phone){

                first_Name.push_back(first);
                last_Name.push_back(last);
                phone_Num.push_back(phone);
        }


        //Encrypting First Name Array
        for (int i = 0; i < first_Name.size(); i++){

            insert_Name = "";
            check = first_Name[i];

            //Loop to change each char of the first name
            for (int z = 0; z < check.length(); z++){

                insert_Name += (check[z] + 7);//Changing the ASCII CODE
            }

            encrypt_First.push_back(insert_Name);
        }
        //Encrypting Last Name Array
        for (int i = 0; i < last_Name.size(); i++){

            insert_Name = "";
            check = last_Name[i];

            //Loop to change each char of the last name
            for(int z = 0; z < check.length(); z++){

                insert_Name += (check[z] + 7);//Changing the ASCII CODE
            }

            encrypt_Last.push_back(insert_Name);
        }

        //Encrypting Phone number Array
        for (int i = 0; i < phone_Num.size(); i++){

            insert_Name = "";
            check = phone_Num[i];

            //Loop to change each char of the phone number
            for(int z = 0; z < check.length(); z++){

                insert_Name += (check[z] + 7);//Changing the ASCII CODE

            }

            encrypt_Num.push_back(insert_Name);
        }

        //Inputing Encrypting data into a file
        for(int t = 0; t < encrypt_First.size(); t++){


            outFile << encrypt_First[t] << " " << encrypt_Last[t] << " " << encrypt_Num[t] << '\n';
        }

        cout << "\nEncryption Done\n";
        Sleep(1000);//sleep for 2000ms
        system("CLS");//Clear console
        inFile.close();//close file
        outFile.close();//close file

        //Clearing vector for memory
        first_Name.clear();
        last_Name.clear();
        phone_Num.clear();
        encrypt_First.clear();
        encrypt_Last.clear();
        encrypt_Num.clear();

        menu();//Return to menu


    }
}
//Data decrypting function
void decrypt_File(){

    //Variables for files, input, and user input
    string file_Name = "datafile.encrypted.txt";
    string file_Encrypt = "datafile.decrypted.txt";

    char continue_Program;

    //Temp variables
    string check;
    string insert_Name;

    //Vector arrays
    vector<string> encrypt_First;
    vector<string> encrypt_Last;
    vector<string> encrypt_Num;
    vector<string> decrypt_First;
    vector<string> decrypt_Last;
    vector<string> decrypt_Num;

    //Strings used to fill arrays from file
    string e_First;
    string e_Last;
    string e_Num;
    string d_first;
    string d_last;
    string d_phone;

    //input file stream object
    ifstream inFile;
    //output file stream object
    ofstream outFile;

    //open the file
    inFile.open(file_Name.c_str());
     //Opens the file
    outFile.open(file_Encrypt.c_str());

    //Catches if inFile does not exist
    if(inFile.fail()){

        cout << "\n!ERROR! " << file_Name << " DOES NOT EXIST!\n";

        //Loop to validate user input
        do{

            cout << "\nWould you like to create the File? (Y or N)\n";
            cin >> continue_Program;

            continue_Program = toupper(continue_Program);


        }while((continue_Program != 'Y') && (continue_Program != 'N'));

        //User input = yes
        if(continue_Program == 'Y'){

            //Call create file function
            inFile.close();//close file
            outFile.close();//close file
            encrypt_File();
        }

        //User input = no
        else{

            cout << "\nProgram will not work without creating a file first.\n";
            Sleep(1000);//sleep for 2000 ms
            system("CLS");//Clear console
            inFile.close();//close file
            outFile.close();//close file
            menu();//Return to menu
        }
    }

   if (outFile.good()){



        cout << '\n' << file_Encrypt << " was Successfully Created\n\n";

        //Gets input from file to place in arrays
        while(inFile >> e_First >> e_Last >> e_Num){

                encrypt_First.push_back(e_First);
                encrypt_Last.push_back(e_Last);
                encrypt_Num.push_back(e_Num);
        }

        //Decrypting First Name Array
        for (int i = 0; i < encrypt_First.size(); i++){

            insert_Name = "";
            check = encrypt_First[i];

            //Loop to Decrypt first name
            for (int z = 0; z < check.length(); z++){

                insert_Name += (check[z] - 7);//Decrypt  first name
            }

            decrypt_First.push_back(insert_Name);//Inserting decrypt first name into array
        }

        //Decrypting Last Name Array
        for (int i = 0; i < encrypt_Last.size(); i++){

            insert_Name = "";
            check = encrypt_Last[i];

            //Loop to Decrypt last name
            for(int z = 0; z < check.length(); z++){

                insert_Name += (check[z] - 7);//Decrypt last name
            }

            decrypt_Last.push_back(insert_Name);//Inserting decrypted last name into array
        }

        //Decrypting Phone number Array
        for (int i = 0; i < encrypt_Num.size(); i++){

            insert_Name = "";
            check = encrypt_Num[i];

            //Loop to Decrypt phone number
            for(int z = 0; z < check.length(); z++){

                insert_Name += (check[z] - 7);//Decrypt phone number
            }

            decrypt_Num.push_back(insert_Name);//Inserting decrypted phone number into array
        }

        //Inputing Decrypting data into a file
        for(int t = 0; t < decrypt_First.size(); t++){

            //Insert decrypted in a file
            outFile << decrypt_First[t] << " " << decrypt_Last[t] << " " << decrypt_Num[t] << '\n';
        }

        cout << "\nDecryption Done\n";
        Sleep(1000);//sleep for 2000ms
        system("CLS");//Clear console
        inFile.close();//close file
        outFile.close();//close file

        //Clearing the vectors
        encrypt_First.clear();
        encrypt_Last.clear();
        encrypt_Num.clear();
        decrypt_First.clear();
        decrypt_Last.clear();
        decrypt_Num.clear();

        menu();//Return to menu
    }

}

//Add and delete entry function
void add(){

    //Local Variables
    string first, last, phone, find_Line, line, test_Name, test_Num;
    char continue_Choice, continue_Program, add_del;
    string file_Name = "datafile.txt";
    int counter = 0;
    bool name_Invalid, phone_Invalid;

    //output file stream object
    ofstream outFile;

    //open file with append to add to file
    outFile.open("datafile.txt", ios::app);

     //Catches if inFile does not exist
    if(outFile.fail()){

        cout << "\n!ERROR! " << file_Name << " DOES NOT EXIST!\n";

        //Loop to validate user input
        do{

            cout << "\nWould you like to create the File? (Y or N)\n";
            cin >> continue_Program;

            continue_Program = toupper(continue_Program);


        }while((continue_Program != 'Y') && (continue_Program != 'N'));

        //User input = yes
        if(continue_Program == 'Y'){

            //Call create file function
            create_File();
        }

        //User input = no
        else{

            cout << "\nProgram will not work without creating a file first.\n";
            Sleep(1000);//sleep for 2000 ms
            system("CLS");//Clear console
            outFile.close();//close file
            menu();//Return to menu
        }
    }

    //Check and get input for add or delete
    do{

       cout << "\nDo you want to add or delete entry(A = Add, D = Delete)? ";
       cin >> add_del;

        add_del = toupper(add_del);

    }while((add_del != 'A') && (add_del != 'D'));

    //Adding entry
    if(add_del == 'A'){

        //Main loop for adding entry
        do{

            //Get and Test first name
            do{

                cout << "\nEnter First Name: ";
                cin >> test_Name;
                name_Validation(test_Name,name_Invalid);//Call name Validation function

            }while(name_Invalid == false);

            first = test_Name;//Set first name with valid test name

            //Get and Test last name
            do{

                cout << "\nEnter Last Name: ";
                cin >> test_Name;
                name_Validation(test_Name, name_Invalid);//Call name Validation function

            }while(name_Invalid == false);

            last = test_Name;//Set last name with valid test name

            //Get and Test phone number
            do{

                cout << "\nEnter Phone Number (ex. 867-6309) ";
                cin >> test_Num;
                phone_Validation(test_Num, phone_Invalid);//Call phone Validation function

            }while(phone_Invalid == false);

            phone = test_Num;//Set phone number with valid test number

            outFile << first << " " << last << " " << phone << '\n';

         //Loop to validate user input to continue to add another name
            do{

                cout << "\nWould you like to add another entry? (Y or N)\n";
                cin >> continue_Choice;

                continue_Choice = toupper(continue_Choice);//Change to upper


            }while((continue_Choice != 'Y') && (continue_Choice != 'N'));

        }while(continue_Choice == 'Y');

        outFile.close();//close file
    }
    //Delete entry
    else{

            outFile.close();//close file

            //in and out file objects
            ifstream inFile;
            ofstream outFile;

            //Open files
            inFile.open("datafile.txt");
            outFile.open("temp.txt");//Temp file

            //Get and test first name
            do{

                cout << "\nEnter First Name: ";
                cin >> test_Name;
                name_Validation(test_Name,name_Invalid);//Call name Validation function

            }while(name_Invalid == false);

            first = test_Name;//Set first name with valid test name

            //Get and test last name
           do{

                cout << "\nEnter Last Name: ";
                cin >> test_Name;
                name_Validation(test_Name, name_Invalid);//Call name Validation function


            }while(name_Invalid == false);

            last = test_Name;//Set last name with valid test name

            //Get and test phone number
            do{

                cout << "\nEnter Phone Number (ex. 867-6309) ";
                cin >> test_Num;
                phone_Validation(test_Num, phone_Invalid);//Call phone Validation function

            }while(phone_Invalid == false);

            phone = test_Num;//Set phone number with valid test number

            //Combine input to one string
            find_Line += (first + string(" ") + last + string(" ")+ phone);

            //Check file for entry
            while(getline(inFile,line)){

                //If line is not equal to user input
                if(line != find_Line){

                    //Write to temp file to remove entry
                    outFile << line << endl;
                }
                //Used to determine in entry was not in the file
                else{

                    counter++;
                }
            }

            //Checks for valid input or if input was not there
            if(counter == 0){

                cout << "\n!ENTRY IS NOT IN FILE!\n";
            }
            //If entry was deleted
            else{

                cout << "\nData file has been changed.\n";

            }
            //Close files
            inFile.close();
            outFile.close();

            //Remove old datafile and replace with temp.txt
            remove("datafile.txt");
            rename("temp.txt", "datafile.txt");
    }

    Sleep(1000);//sleep for 2000 ms
    system("CLS");//Clear console
    outFile.close();//close file
    menu();//Return to menu

}
void find_Entry(){

    //Local Variables
    char continue_Program;
    string file_Name = "datafile.txt", search_Num, first, last, phone,test_Num;
    int counter = 0;
    bool phone_Invalid;

    //input file stream object
    ifstream inFile;

    //open infile
    inFile.open(file_Name.c_str());

        //Catch infail if fail does not exist
        if(inFile.fail()){

        cout << "\n!ERROR! " << file_Name << " DOES NOT EXIST!\n";

        //Loop to validate user input
        do{

            cout << "\nWould you like to create the File? (Y or N)\n";
            cin >> continue_Program;

            continue_Program = toupper(continue_Program);


        }while((continue_Program != 'Y') && (continue_Program != 'N'));

        //User input = yes
        if(continue_Program == 'Y'){

            //Call create file function
            create_File();
        }

        //User input = no
        else{

            cout << "\nProgram will not work without creating a file first.\n";
            Sleep(1000);//sleep for 2000 ms
            system("CLS");//Clear console
            inFile.close();//close file
            menu();//Return to menu
        }
    }

    //Get user input for phone number
    do{

        cout << "\nEnter Phone Number (ex. 867-6309) ";
        cin >> test_Num;
        phone_Validation(test_Num, phone_Invalid);//Call Validation for phone number

    }while(phone_Invalid == false);

    //Set search num to valid number
    search_Num = test_Num;

    while(inFile.good()){

            //Get input from file
            inFile >> first;
            inFile >> last;
            inFile >> phone;

          //If number is found
          if(search_Num == phone){

              cout << "\nThe entry with the number " << search_Num << " is: "
                   << first << " " <<last << '\n';
              counter++;//Used to check if entry was not found
          }
    }

    //Checks if entry is not found
    if (counter == 0){

        cout << '\n' << search_Num << " Was not found.\n";
    }
}

//Function for name validation
void name_Validation(string & test_Name, bool & name_Invalid){

    name_Invalid = true;

    //Test for empty input for name
    if(test_Name.empty()){

        //set to empty to be caught by for loop
        test_Name = " ";
    }

    //Loop to check test name for invalid characters
    for(int x = 0; x < test_Name.length(); x++){

        if((test_Name[x] < 65) || (test_Name[x] > 91) && (test_Name[x] < 97) || (test_Name[x] > 122)){

            cout << "\n!INVALID INPUT!\n";
            name_Invalid = false;
            break;
        }
    }

    //Change caps of the test name so first letter to uppercase and rest is lowercase
    if(name_Invalid == true){

            //Formating first name
            for(int i = 0; i < test_Name.length(); i++){

                test_Name[i] = tolower(test_Name[i]);
                test_Name[0] = toupper(test_Name[0]);
            }
    }
}
//Phone Validation Function
void phone_Validation(string & test_Num, bool & phone_Invalid){


    phone_Invalid = true;

    //Test for empty
    if(test_Num.empty()){

        //set to empty to be caught by for loop
        test_Num = " ";
    }
    //Test for length so its not greater then 8 or less then 8 letters
    if(test_Num.length() != 8){

        //set to empty to be caught by for loop
        test_Num = " ";
    }

    //Loop to check phone number
    for(int x = 0; x < test_Num.length(); x++){

        //Statements to check and catch ever number in the phone number
        if((test_Num[0] < 48) || (test_Num[0] > 57)){

            invalid_Output(phone_Invalid);//call invalid_Output
            break;
        }
        if((test_Num[1] < 48) || (test_Num[1] > 57)){

            invalid_Output(phone_Invalid);//call invalid_Output
            break;
        }
        if((test_Num[2] < 48) || (test_Num[2] > 57)){

            invalid_Output(phone_Invalid);//call invalid_Output
            break;
        }
        //Check for the dash
        if(test_Num[3] != 45){

            invalid_Output(phone_Invalid);//call invalid_Output
            break;
        }
        if((test_Num[4] < 48) || (test_Num[4] > 57)){

            invalid_Output(phone_Invalid);//call invalid_Output
            break;
        }
        if((test_Num[5] < 48) || (test_Num[5] > 57)){

            invalid_Output(phone_Invalid);//call invalid_Output
            break;
        }
        if((test_Num[6] < 48) || (test_Num[6] > 57)){

            invalid_Output(phone_Invalid);//call invalid_Output
            break;
        }
        if((test_Num[7] < 48) || (test_Num[7] > 57)){

            invalid_Output(phone_Invalid);//call invalid_Output
            break;
        }
    }
}

//Invalid Output function
void invalid_Output(bool & phone_Invalid){

    cout << "\nINVALID INPUT\n";
    phone_Invalid = false;//bool expression that is returned

}

void print_Files(){

    int menu_Choice;
    char continue_Print,continue_Program;
    string line, file_Name;
    //input file stream object
    ifstream inFile;

    do{
        cout << "\n\n**********PRINT MENU**************" << '\n'
             << "*   <1> - Main data file         *" << '\n'
             << "*   <2> - Copied file            *" << '\n'
             << "*   <3> - Encrypted file         *" << '\n'
             << "*   <4> - Decrypted file         *" << '\n'
             << "*   <5> - Return to Main Menu    *" << '\n'
             << "**********************************\n" << '\n';

        cin >> menu_Choice;

        switch(menu_Choice){

            //Used for wrong input - ex. a, b, c, etc
            case 0:

                cout << "\n!!INVAILD INPUT!!";
                cin.clear();
                cin.ignore();
                break;

            case 1:

                system("CLS");//Clear console
                file_Name = "datafile.txt";

                //open the file
                inFile.open(file_Name.c_str());

                //Catches if inFile does not exist
                if(inFile.fail()){

                    cout << "\n!ERROR! " << file_Name << " DOES NOT EXIST!\n";

                    //Loop to validate user input
                    do{

                        cout << "\nWould you like to create the File? (Y or N)\n";
                        cin >> continue_Program;

                        //Change input to upper
                        continue_Program = toupper(continue_Program);


                    }while((continue_Program != 'Y') && (continue_Program != 'N'));

                    //User input = yes
                    if(continue_Program == 'Y'){

                        //Call create file function
                        create_File();
                    }

                    //User input = no
                    else{

                        cout << "\nProgram will not work without creating a file first.\n";
                        Sleep(1000);//sleep for 2000 ms
                        system("CLS");//Clear console
                        inFile.close();//close file
                        menu();//Return to menu
                    }
                }

                //Loop to print file
                while(getline(inFile,line)){

                cout << line << '\n';

                }

                //close file
                inFile.close();
                break;


            case 2:

                system("CLS");//Clear console
                file_Name = "datafile.bak.txt";

                //open the file
                inFile.open(file_Name.c_str());

                //Catches if inFile does not exist
                if(inFile.fail()){

                    cout << "\n!ERROR! " << file_Name << " DOES NOT EXIST!\n";

                    //Loop to validate user input
                    do{

                        cout << "\nWould you like to create the File? (Y or N)\n";
                        cin >> continue_Program;

                        //Change input to upper
                        continue_Program = toupper(continue_Program);


                    }while((continue_Program != 'Y') && (continue_Program != 'N'));

                    //User input = yes
                    if(continue_Program == 'Y'){

                        //Call create file function
                        create_File();
                    }

                    //User input = no
                    else{

                        cout << "\nProgram will not work without creating a file first.\n";
                        Sleep(1000);//sleep for 2000 ms
                        system("CLS");//Clear console
                        inFile.close();//close file
                        menu();//Return to menu
                    }
                }

                //Loop to print file
                while(getline(inFile,line)){

                    cout << line << '\n';

                }
                //close file
                inFile.close();
                break;
            case 3:

                 system("CLS");//Clear console
                 file_Name = "datafile.encrypted.txt";

                //open the file
                inFile.open(file_Name.c_str());

                //Catches if inFile does not exist
                if(inFile.fail()){

                    cout << "\n!ERROR! " << file_Name << " DOES NOT EXIST!\n";

                    //Loop to validate user input
                    do{

                        cout << "\nWould you like to create the File? (Y or N)\n";
                        cin >> continue_Program;

                        //Change input to upper
                        continue_Program = toupper(continue_Program);


                    }while((continue_Program != 'Y') && (continue_Program != 'N'));

                    //User input = yes
                    if(continue_Program == 'Y'){

                        //Call create file function
                        create_File();
                    }

                    //User input = no
                    else{

                        cout << "\nProgram will not work without creating a file first.\n";
                        Sleep(1000);//sleep for 2000 ms
                        system("CLS");//Clear console
                        inFile.close();//close file
                        menu();//Return to menu
                    }
                }

                //Loop to print file
                while(getline(inFile,line)){

                    cout << line << '\n';

                }
                //close file
                inFile.close();
                break;

            case 4:

                system("CLS");//Clear console
                file_Name = "datafile.decrypted.txt";

                //open the file
                inFile.open(file_Name.c_str());

                //Catches if inFile does not exist
                if(inFile.fail()){

                    cout << "\n!ERROR! " << file_Name << " DOES NOT EXIST!\n";

                    //Loop to validate user input
                    do{

                        cout << "\nWould you like to create the File? (Y or N)\n";
                        cin >> continue_Program;

                        //Change input to upper
                        continue_Program = toupper(continue_Program);


                    }while((continue_Program != 'Y') && (continue_Program != 'N'));

                    //User input = yes
                    if(continue_Program == 'Y'){

                        //Call create file function
                        decrypt_File();
                    }

                    //User input = no
                    else{

                        cout << "\nProgram will not work without creating a file first.\n";
                        Sleep(1000);//sleep for 2000 ms
                        system("CLS");//Clear console
                        inFile.close();//close file
                        menu();//Return to menu
                    }
                }

                //Loop to print file
                while(getline(inFile,line)){

                    cout << line << '\n';

                }
                //close file
                inFile.close();
                break;

            case 5:
                    system("CLS");//Clear console
                    menu();
                    break;

            default:

                    cout << "\n!INVAILD INPUT!\n";
                    break;
        }

        //Loop to validate user input
        do{

            cout << "\nWould you like to print another the File? (Y or N)\n";
            cin >> continue_Print;

            //Change input to upper
            continue_Print = toupper(continue_Print);

        }while((continue_Print != 'Y') && (continue_Print != 'N'));

        system("CLS");//Clear console

    }while(continue_Print != 'N');

    if (continue_Print == 'N'){

        system("CLS");//Clear console
        menu();
    }

}
//Function to delete files
void delete_Files(){

    int menu_Choice;

    do{
        cout << "\n!!!WARNING - Permanently deletes the files!!!\n"
             << "Files can be re-created back at the Main Menu\n";

        cout << "\n\n**********DELETE MENU***************" << '\n'
             << "*   <1> - Delete Main file         *" << '\n'
             << "*   <2> - Delete Copied file       *" << '\n'
             << "*   <3> - Delete Encrypted file    *" << '\n'
             << "*   <4> - Delete Decrypted file    *" << '\n'
             << "*   <5> - Delete all Files         *" << '\n'
             << "*   <6> - Return to Main Menu      *" << '\n'
             << "************************************\n" << '\n';

         cin >> menu_Choice;


        switch(menu_Choice){

             //Used for wrong input - ex. a, b, c, etc
            case 0:

                cout << "\n!!INVAILD INPUT!!\n";
                cin.clear();
                cin.ignore();
                break;

            case 1:
                system("CLS");
                remove("datafile.txt");//Removes file
                cout << "\ndatefile.txt has been deleted\n";
                break;

            case 2:
                system("CLS");
                remove("datefile.bak.txt");//Removes file
                cout << "\ndatefile.bak.txt has been deleted\n";
                break;

            case 3:
                system("CLS");
                remove("datafile.encrypted.txt");//Removes file
                cout << "\ndatafile.encrypted.txt has been deleted\n";
                break;

            case 4:
                system("CLS");
                remove("datafile.decrypted.txt");//Removes file
                cout << "\ndatafile.decrypted.txt has been deleted\n";
                break;

            case 5:
                system("CLS");
                remove("datafile.txt");//Removes file
                remove("datefile.bak.txt");//Removes file
                remove("datafile.decrypted.txt");//Removes file
                remove("datafile.encrypted.txt");//Removes file
                cout << "\nAll files have been deleted\n";
                break;

            case 6:
                system("CLS");
                menu();//Return to menu

            default:
                cout << "\n!INVAILD INPUT!\n";
                break;
        }

    }while(true);

}
int main()
{

    menu();//Call menu function
    return 0;
}
