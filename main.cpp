#include <iostream>
#include <fstream>
#include <conio.h>
#include "include\pet.h"
#include "include\system_dataBase.h"
#include "include\staff_acc.h"
#include "include\define.h"
#include <assert.h>
#include <regex>

using namespace std;

system_dataBase* sysDB_1 = new system_dataBase("Egham");// Create a new database object





int main()
{
//    testClass();
    auto_dataGen();// Generate pet data and start the main menu
    staff_acc* stafAcc = new staff_acc("staff", "1234", "CEO");
    sysDB_1->addStaffAcc(stafAcc);
    menu();
    return 0;
}

// Test the functionality of the classes
void testClass()
{
    system("cls");// Clear the console



    cout << "Pet class testing:\n\n";
    // Create and display the first pet object
    cout << "first object created from database:\n";
    pet* pet1 = new pet(1);// Create a pet object with ID 1
    cout << "type: " << pet1->getType() << endl;
    cout << "bteed: " << pet1->getBreed() << endl;
    cout << "name: " << pet1->getName() << endl;
    cout << "age: " << pet1->getAge() << endl;
    cout << "gender: " << pet1->getGender() << endl;


    // Create and display the second pet object
    cout << "\n\nsecond object created from database:\n";
    pet* pet2 = new pet(2);// Create a pet object with ID 2
    cout << "type: " << pet2->getType() << endl;
    cout << "breed: " << pet2->getBreed() << endl;
    cout << "name: " << pet2->getName() << endl;
    cout << "age: " << pet2->getAge() << endl;
    cout << "gender: " << pet2->getGender() << endl;

    try{
        cout << "\n301. object created from database(invalid):\n";
        pet* pet301 = new pet(301);// Create a pet object with ID 301
    }
    catch (exception& e)
    {
        cerr << "exception: " << e.what() << endl;
    }

    cout << "\n\nfirst custom object:\n";
    pet* Cpet1 = new pet("custom_type", "custom_breed", "custom_name", "custom_age", "custom_gender");

    assert(Cpet1->getType() == "Custom_type");
    assert(Cpet1->getBreed() == "custom_breed");
    assert(Cpet1->getName() == "custom_name");
    assert(Cpet1->getAge() == "custom_age");
    assert(Cpet1->getGender() == "custom_gender");

    cout << "type: " << Cpet1->getType() << endl;
    cout << "breed: " << Cpet1->getBreed() << endl;
    cout << "name: " << Cpet1->getName() << endl;
    cout << "age: " << Cpet1->getAge() << endl;
    cout << "gender: " << Cpet1->getGender() << endl;


    cout << "\n\nsecond custom object:\n";
    pet* Cpet2 = new pet("Bug", "ladybug", "Marinette", "7 months", "other");
    cout << "type: " << Cpet2->getType() << endl;
    cout << "breed: " << Cpet2->getBreed() << endl;
    cout << "name: " << Cpet2->getName() << endl;
    cout << "age: " << Cpet2->getAge() << endl;
    cout << "gender: " << Cpet2->getGender() << endl << endl << endl;





    cout << "Account class testing:\n\n";
    cout << "Creating a account object with \"person\" username and \"1234\" password:\n\n";
    account* acc1 = new account("person", "1234");
    cout << "Username: " << acc1->getUserN() << endl << "Password: not accessible from account class\n\n\n";

    cout << "Changing the Username to \"fish\"... \n\n";
    acc1->setUN("fish");
    cout << "New Username: " << acc1->getUserN() << endl << endl << endl;





    cout << "customer account class testing:\n\n";
    cout << "Creating a customer account object with \"Josh\" username and \"0123\" password:\n\n";
    customer_acc* CusAcc = new customer_acc("Josh", "0123");
    cout << "Username: " << CusAcc->getUserN() << endl << "Password: " << CusAcc->getPass() << "\n\n\n";

    cout << "Changing the Username to \"Omar\" and password to \"9012\"... \n\n";
    CusAcc->setUN("Omar");
    CusAcc->setPass("9012");
    cout << "New Username: " << CusAcc->getUserN() << "\nNew Password: " << CusAcc->getPass() << endl << endl;

    cout << "Adding second custom pet object to customer account... \n\n";
    CusAcc->addPet(Cpet2);
    cout << "Customer account pets:\n";
    CusAcc->getPets();

    cout << "\n\nthe initial money in the customer account before any transactions: " << CusAcc->getWallet() << "\n\nafter depisiting 12 to customer account: ";
    CusAcc->deposit(12);
    int w = CusAcc->getWallet();
    assert(w == 12);
    cout << CusAcc->getWallet();
    cout << "\n\nafter donating 5 to customer account: ";
    CusAcc->donate(5);
    w = CusAcc->getWallet();
    assert(w == 12 - 5);
    cout << CusAcc->getWallet() << endl << endl << endl;




    cout << "Staff account testing:\n\n";
    cout << "creating a staff account object with \"Ben\" username, \"1212\" password and \"CEO\" status:\n\n";
    staff_acc* StfAcc = new staff_acc("Ben", "1212", "CEO");
    cout << "Username: " << StfAcc->getUserN() << endl << "Password: " << StfAcc->getPass() << "\nstatus: " << StfAcc->getStat() << "\n\n\n";

    cout << "Changing the Username to \"Luck\", password to \"3434\" and status to \"Manager\"... \n\n";
    StfAcc->setUN("Luck");
    StfAcc->setPass("3434");
    StfAcc->setStatus("Manager");
    cout << "New Username: " << StfAcc->getUserN() << "\nNew Password: " << StfAcc->getPass() << "\nNew Status: " << StfAcc->getStat() << endl << endl;

    cout << "creating staff account object with \"Jesica\" username, \"1234\" password and \"Janitor\" status with another staff account object function:";
    staff_acc* StfAcc1 = StfAcc->staffAdd("Jesica", "1234", "Jenitor");
    cout << "Username: " << StfAcc1->getUserN() << endl << "Password: " << StfAcc1->getPass() << "\nstatus: " << StfAcc1->getStat() << "\n\n\n";




    cout << "\n\n\nsystem_dataBase class testing:";
    // Test system_dataBase functionality
    cout << "\n\nthe amount of pets registered to the system before adding any pets: ";
    cout << sysDB_1->petAmount() << endl;// Display the number of pets in thedatabase

    sysDB_1->addPet(pet1);
    // Add a pet and verify the count
    cout << "\n\nthe amount of pets registered to the system after adding 1 pets: ";
    cout << sysDB_1->petAmount() << endl << endl <<endl;

    sysDB_1->addPet(pet2);
    // Add a pet and verify the count
    cout << "\n\nthe amount of pets registered to the system after adding 2 pets: ";
    cout << sysDB_1->petAmount() << endl << endl <<endl;



    cout << "\n\nthe amount of customer accounts registered to the system before adding any customer accounts: ";
    cout << sysDB_1->cusAccAmount() << endl;

    sysDB_1->addCusAcc(CusAcc);

    cout << "\n\nthe amount of customer accounts registered to the system after adding 1 customer account: ";
    cout << sysDB_1->cusAccAmount() << endl << endl <<endl;



    cout << "\n\nthe amount of staff accounts registered to the system before adding any staff accounts: ";
    cout << sysDB_1->staffAccAmount() << endl;

    sysDB_1->addStaffAcc(StfAcc);

    cout << "\n\nthe amount of staff accounts registered to the system after adding 1 staff account: ";
    cout << sysDB_1->staffAccAmount() << endl << endl <<endl;


    // Access a specific pet's type from the database
    cout << "accessing the type of the first pet(object) in the data base(object): ";
    cout << sysDB_1->strict_petGet(0, 0) << endl << endl;
}
// Automatically generate 300 pet objects and add them to the database
void auto_dataGen()
{
    for(int i=1; i <= 300; i++)
    {
        pet* p = new pet(i);// Create a new pet object with ID i
        sysDB_1->addPet(p);// Add the pet to the system database
    }
}

// Main menu to navigate the system
void menu()
{
    int choice = 0;// Variable to store user choice
    string line = "";// Variable to store input

    while(1)// Infinite loop for the menu
    {
        system("cls");// Clear the console
            // Display menu options
            //cout << sysDB_1->staffAccAmount();
            cout << "*\t\t\t\t\t\t\t     Welcome       \t\t\t\t\t\t*\n*\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t*\n"
                 << "*\t\t\t\t\t\t\t        to         \t\t\t\t\t\t*\n*\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t*\n"
                 << "*\t\t\t\t\t\t\tPet Adoption Center\t\t\t\t\t\t*\n*\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t*\n*\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t*\n"
                 << "************************************************************************************************************************\n\n\n"
                 << "\t\t\t\t\t\t\t1) Adopt a Pet\n\n"
                 << "\t\t\t\t\t\t\t2) account\n\n\n"
                 << "Entry: ";

            cin >> line;// Get user input


            // Exit condition
            if(line == "exit!!")
        {
            abort();// Terminate the program
        }


        // Ensure valid input
        while(line == "")
        {
            system("cls");// Clear the console

            getline(cin, line);// Get input again
            if(!(line == ""))
            {
                break;// Exit the loop if input is valid
            }
        }

        // Process valid choice
        if(!(line.size() > 1))
        {
            choice = stoi(line);// Convert input to integer

            switch(choice)
            {
            case 1:
                adopt_pet();// Call the adopt_pet function
                continue;
            case 2:
                account_menu();// Call the account_menu function
                continue;
            default:
                // Handle invalid choice
                cout << "\t\t\t\t\t\t!!!wrong choice try again!!!\n" <<
                        "\t\t\t\t\t\t       !!press enter!!";
                getline(cin, line);// Wait for user to press enter
                line = " ";
                choice = 0;
                continue;
            }
        }

    }
}

// Facilitates the pet adoption process
void adopt_pet()
{
    system("cls");

    list_options();// Generate options for filtering
    listSel();// Select a pet to adopt

    //lister("all", "all", "all", "all", "all");
}

// Checks if an option exists in the provided list
bool optionEx(vector<string> s, string st)
{
    for(int z=0; z < s.size(); z++)
        {
            string line;
            line = s[z];
            if(st == line)// If the string matches an existing option, return false
                return false;
        }
        return true;// Return true if the string is not found in the list
}

// Lists available pet options based on attributes
void list_options()
{
    vector<string> opts[5];// Array of vectors to store unique options for each
    //attribute
    int pNum = sysDB_1->petAmount();// Get the total number of pets in the database
    // Iterate through all pets in the database
    for(int x=0; x < pNum; x++)
    {
        // Loop through each attribute (type, breed, name, etc.)
        for(int i=0;i<5;i++)
        {
            if(i == 1)// Special case for combining type and breed
            {
                string type = sysDB_1->strict_petGet( x,  0);// Get pet type
                string breed = sysDB_1->strict_petGet( x,  1);// Get pet breed
                string data = type + ":" + breed;// Combine type and breed as a
                //single option

                if(optionEx(opts[1], data))// Check if the option already exists
                {
                    opts[1].push_back(data);// Add the unique type:breed option
                }
            }
            else
            {
                string data = sysDB_1->strict_petGet( x,  i);// Get the attribute
                //value
                if(optionEx(opts[i], data))// Check if the option already exists
                {
                    opts[i].push_back(data);// Add the unique option
                }
            }
        }
    }

    // Save the generated options back to the database
    for(int i=0;i<5;i++)
    {
        sysDB_1->optSet(i, opts[i]);// Set the options for each attribute
    }

                    //option test


    //cout << "\n\n\nnumber of type in the data base: " << sysDB_1->opt[0].size() << endl;
    //cout << "number of breeds: " << opts[1].size() << endl;
    //cout << "type options" << endl;
    //for(int i=0;i<opts[0].size();i++)
    //{
    //    cout << opts[0][i] << endl;
    //}

    //cout << "\n\nbreed options" << endl;
    //for(int i=0;i<opts[1].size();i++)
    //{
    //    cout << opts[1][i] << endl;
    //}

    //cout << "\n\nname options" << endl;
    //for(int i=0;i<opts[2].size();i++)
    //{
    //    cout << opts[2][i] << endl;
    //}

    //cout << "\n\nage options" << endl;
    //for(int i=0;i<opts[3].size();i++)
    //{
    //    cout << opts[3][i] << endl;
    //}

    //cout << "\n\ngender options" << endl;
    //for(int i=0;i<opts[4].size();i++)
    //{
    //    cout << opts[4][i] << endl;
    //}
}

// Allows user to select filters for pet browsing
void listSel()
{
    bool exit = false;// Flag to exit the filtering loop
    string opTy[5] = {"Type", "Breed", "Name", "Age", "Gender"};// Labels for
    //attributes
    int ch[5] = {0, 0, 0, 0, 0};// Stores user choices for each attribute
    while(!exit)// Repeat until user exits
    {
//    for(int z=0;z<5;z++)// Iterate over each attribute
//    {
        system("cls");// Clear the console
        // Display filtering options and handle user selection
//        switch(0)
        {// Filtering logic for each attribute
        // Case for Type
//        case 0:
//            {
            cout << "\t\t\t\t\t\tType options\n\n";
            cout << "\t\t\t";

            vector<string> opts = sysDB_1->optGet(0);// Get available types

            for(int x=0, a=0;x < opts.size();x++)
            {
                a++;
                if(a == 6)// Display 6 options per line
                {
                    cout << "\n\n\t\t\t";
                    a = 0;
                }
                cout << x+1 << ") " << opts[x];
                int leng = opts[x].length();
                for(int i=0; leng+i < 9; i++)
                {
                    cout << " ";
                }
            }

            cout << "\n\n\t\t\t\t\t\t0)All";// Option for selecting all
            cout << "\n\n\t\t\tEnter choice: ";
            cin >> ch[0];// Get user input
            if(ch[0] <= opts.size())// Validate choice
                exit = true;
            }
//            break;
        // Case for Breed
//        case 1:
//            {
//            cout << "\t\t\t\t\t\tBreed options\n\n";
//            cout << "\t\t\t";
//
//            vector<string> opts = sysDB_1->optGet(z);// Get available breeds
//            for(int x=0, a=0;x < opts.size();x++)
//            {
//                a++;
//                if(a == 3)// Display 3 options per line
//                {
//                    cout << "\n\n\t\t";
//                    a = 0;
//                }
//                cout << x+1 << ") " << opts[x];
//                int leng = opts[x].length();
//                for(int i=0; leng+i < 23; i++)
//                {
//                    cout << " ";
//                }
//            }
//
//            cout << "\n\n\t\t\t\t\t\t0)All";// Option for selecting all
//            cout << "\n\n\t\t\tEnter choice: ";
//            cin >> ch[1];// Get user input
//            if(ch[1] <= opts.size())// Validate choice
//                exit = true;
//            }
//            break;
//
//        // Case for Name
//        case 2:
//            {
//            cout << "\t\t\t\t\t\tName options\n\n";
//            cout << "\t\t\t";
//
//            vector<string> opts = sysDB_1->optGet(z);// Get available names
//            for(int x=0, a=0;x < opts.size();x++)
//            {
//                a++;
//                if(a == 5)// Display 5 options per line
//                {
//                    cout << "\n\n\t\t";
//                    a = 0;
//                }
//                cout << x+1 << ") " << opts[x];
//                int leng = opts[x].length();
//                for(int i=0; leng+i < 15; i++)
//                {
//                    cout << " ";
//                }
//            }
//
//            cout << "\n\n\t\t\t\t\t\t0)All";// Option for selecting all
//            cout << "\n\n\t\t\tEnter choice: ";
//            cin >> ch[2];// Get user input
//            if(ch[2] <= opts.size())// Validate choice
//                exit = true;
//            }
//            break;
//
//        // Case for Age
//        case 3:
//            {
//            cout << "\t\t\t\t\t\tAge options\n\n";
//            cout << "\t\t\t\t";
//
//            vector<string> opts = sysDB_1->optGet(z);// Get available ages
//            for(int x=0, a=0;x < opts.size();x++)
//            {
//                a++;
//                if(a == 6)// Display 6 options per line
//                {
//                    cout << "\n\n\t\t\t";
//                    a = 0;
//                }
//                cout << x+1 << ") " << opts[x];
//                int leng = opts[x].length();
//                for(int i=0; leng+i < 9; i++)
//                {
//                    cout << " ";
//                }
//            }
//
//            cout << "\n\n\t\t\t\t\t\t0)All";// Option for selecting all
//            cout << "\n\n\t\t\tEnter choice: ";
//            cin >> ch[3];// Get user input
//            if(ch[3] <= opts.size())// Validate choice
//                exit = true;
//            }
//            break;
//
//        // Case for Gender
//        case 4:
//            {
//            cout << "\t\t\t\t\t\tGender options\n\n";
//            cout << "\t\t\t\t\t";
//
//            vector<string> opts = sysDB_1->optGet(z);// Get available genders
//            for(int x=0, a=0;x < opts.size();x++)
//            {
//                a++;
//                if(a == 6)// Display 6 options per line
//                {
//                    cout << "\n\n\t\t\t\t\t";
//                    a = 0;
//                }
//                cout << x+1 << ") " << opts[x];
//                int leng = opts[x].length();
//                for(int i=0; leng+i < 9; i++)
//                {
//                    cout << " ";
//                }
//            }

//            cout << "\n\n\t\t\t\t\t\t0)All";// Option for selecting all
//            cout << "\n\n\t\t\tEnter choice: ";
//            cin >> ch[4];// Get user input
//            if(ch[4] <= opts.size())// Validate choice
//                exit = true;
//            }
//            break;
//
//        }
//    }

    }
    // Process user selections into filter criteria
    string s[5] = {" ","all", "all", "all", "all"};// Array to store selected filter criteria
    int ok;
//    for(int i=0;i<5;i++)
//    {
        if(ch[0] == 0)// If "All" is selected, set filter to "all"
        {
            s[0] = "all";
        }
        else
        {
            vector<string> o =sysDB_1->optGet(0);// Retrieve options for the
            //attribute
            ok = ch[0]-1;// Adjust index to match vector
            s[0] = o[ok];// Store selected option
        }
//    }

//    if(s[1] != "all")
//        s[1].erase(0,s[0].size()+1);// Remove type prefix from breed filter

    lister(s[0], s[1], s[2], s[3], s[4]);// Pass filters to the lister function
    //for pet browsing

}

// Displays the details of a specific pet and provides options to interact with it
bool display_pets(vector<string> p, int x)
{
    bool exit;// Indicates whether the user wants to exit
    // Display pet details in a formatted manner
    cout << "\t\t           " << x+1 << ") ";
    // Align and display pet number

    string sX = to_string(x+1);
    int leng = sX.length();
    for(int i=0; leng+i < 3; i++)
    {
        cout << " ";
    }
    cout << p[0];// Pet type

    // Align and display pet type
    leng = p[0].length();
    for(int i=0; leng+i < 8; i++)
    {
        cout << " ";
    }
    cout << p[1];// Pet breed

    // Align and display pet breed
    leng = p[1].length();
    for(int i=0; leng+i < 16; i++)
    {
        cout << " ";
    }
    cout << p[2];// Pet name

    // Align and display pet name
    leng = p[2].length();
    for(int i=0; leng+i < 15; i++)
    {
        cout << " ";
    }
    cout << p[3];//pet age

    // Align and display pet age
    leng = p[3].length();
    for(int i=0; leng+i < 9; i++)
    {
        cout << " ";
    }
    cout << p[4] << endl << endl;// Pet gender

    char ch;// User input for choice
    int co;// User input for specific pet

    // Handle different cases based on the pet index
    switch(x)
    {
        case 18:
            cout << "back:ESC\t\t\t\t\t\tchoose a pet:c";
            ch = _getch();// Get user input

            // Check if the user pressed ESC
            if((int)ch == 27)
            {
                exit = true;
                break;
            }
            // Check if the user chose to adopt a pet
            if((int)ch == 99)
            {
                cout << endl << "entry:";
                cin >> co;
                pAddAcc(co);// Add pet to the user's account
            }
            // Pause and refresh the display
            cout << endl;
            system("pause");
            system("cls");
            cout << "\t\t\t    type     breed            name         age      gender\n\n";
            break;
        case 38:
            cout << "back:ESC\t\t\t\t\t\tchoose a pet:c";
            ch = _getch();
            if((int)ch == 27)
            {
                exit = true;
                break;
            }
            if((int)ch == 99)
            {
                cout << endl << "entry:";
                cin >> co;
                pAddAcc(co);
            }
            cout << endl;
            system("pause");
            system("cls");
            cout << "\t\t\t    type     breed            name         age      gender\n\n";
            break;
        case 58:
            cout << "back:ESC\t\t\t\t\t\tchoose a pet:c";
            ch = _getch();
            if((int)ch == 27)
            {
                exit = true;
                break;
            }
            if((int)ch == 99)
            {
                cout << endl << "entry:";
                cin >> co;
                pAddAcc(co);
            }
            cout << endl;
            system("pause");
            system("cls");
            cout << "\t\t\t    type     breed            name         age      gender\n\n";
            break;
        case 78:
            cout << "back:ESC\t\t\t\t\t\tchoose a pet:c";
            ch = _getch();
            if((int)ch == 27)
            {
                exit = true;
                break;
            }
            if((int)ch == 99)
            {
                cout << endl << "entry:";
                cin >> co;
                pAddAcc(co);
            }
            cout << endl;
            system("pause");
            system("cls");
            cout << "\t\t\t    type     breed            name         age      gender\n\n";
            break;
        case 98:
            cout << "back:ESC\t\t\t\t\t\tchoose a pet:c";
            ch = _getch();
            if((int)ch == 27)
            {
                exit = true;
                break;
            }
            if((int)ch == 99)
            {
                cout << endl << "entry:";
                cin >> co;
                pAddAcc(co);
            }
            cout << endl;
            system("pause");
            system("cls");
            cout << "\t\t\t    type     breed            name         age      gender\n\n";
            break;
        case 118:
            cout << "back:ESC\t\t\t\t\t\tchoose a pet:c";
            ch = _getch();
            if((int)ch == 27)
            {
                exit = true;
                break;
            }
            if((int)ch == 99)
            {
                cout << endl << "entry:";
                cin >> co;
                pAddAcc(co);
            }
            cout << endl;
            system("pause");
            system("cls");
            cout << "\t\t\t    type     breed            name         age      gender\n\n";
            break;
        case 138:
            cout << "back:ESC\t\t\t\t\t\tchoose a pet:c";
            ch = _getch();
            if((int)ch == 27)
            {
                exit = true;
                break;
            }
            if((int)ch == 99)
            {
                cout << endl << "entry:";
                cin >> co;
                pAddAcc(co);
            }
            cout << endl;
            system("pause");
            system("cls");
            cout << "\t\t\t    type     breed            name         age      gender\n\n";
            break;
        case 158:
            cout << "back:ESC\t\t\t\t\t\tchoose a pet:c";
            ch = _getch();
            if((int)ch == 27)
            {
                exit = true;
                break;
            }
            if((int)ch == 99)
            {
                cout << endl << "entry:";
                cin >> co;
                pAddAcc(co);
            }
            cout << endl;
            system("pause");
            system("cls");
            cout << "\t\t\t    type     breed            name         age      gender\n\n";
            break;
        case 178:
            cout << "back:ESC\t\t\t\t\t\tchoose a pet:c";
            ch = _getch();
            if((int)ch == 27)
            {
                exit = true;
                break;
            }
            if((int)ch == 99)
            {
                cout << endl << "entry:";
                cin >> co;
                pAddAcc(co);
            }
            cout << endl;
            system("pause");
            system("cls");
            cout << "\t\t\t    type     breed            name         age      gender\n\n";
            break;
        case 198:
            cout << "back:ESC\t\t\t\t\t\tchoose a pet:c";
            ch = _getch();
            if((int)ch == 27)
            {
                exit = true;
                break;
            }
            if((int)ch == 99)
            {
                cout << endl << "entry:";
                cin >> co;
                pAddAcc(co);
            }
            cout << endl;
            system("pause");
            system("cls");
            cout << "\t\t\t    type     breed            name         age      gender\n\n";
            break;
        case 218:
            cout << "back:ESC\t\t\t\t\t\tchoose a pet:c";
            ch = _getch();
            if((int)ch == 27)
            {
                exit = true;
                break;
            }
            if((int)ch == 99)
            {
                cout << endl << "entry:";
                cin >> co;
                pAddAcc(co);
            }
            cout << endl;
            system("pause");
            system("cls");
            cout << "\t\t\t    type     breed            name         age      gender\n\n";
            break;
        case 238:
            cout << "back:ESC\t\t\t\t\t\tchoose a pet:c";
            ch = _getch();
            if((int)ch == 27)
            {
                exit = true;
                break;
            }
            if((int)ch == 99)
            {
                cout << endl << "entry:";
                cin >> co;
                pAddAcc(co);
            }
            cout << endl;
            system("pause");
            system("cls");
            cout << "\t\t\t    type     breed            name         age      gender\n\n";
            break;
        case 258:
            cout << "back:ESC\t\t\t\t\t\tchoose a pet:c";
            ch = _getch();
            if((int)ch == 27)
            {
                exit = true;
                break;
            }
            if((int)ch == 99)
            {
                cout << endl << "entry:";
                cin >> co;
                pAddAcc(co);
            }
            cout << endl;
            system("pause");
            system("cls");
            cout << "\t\t\t    type     breed            name         age      gender\n\n";
            break;
        case 278:
            cout << "back:ESC\t\t\t\t\t\tchoose a pet:c";
            ch = _getch();
            if((int)ch == 27)
            {
                exit = true;
                break;
            }
            if((int)ch == 99)
            {
                cout << endl << "entry:";
                cin >> co;
                pAddAcc(co);
            }
            cout << endl;
            system("pause");
            system("cls");
            cout << "\t\t\t    type     breed            name         age      gender\n\n";
            break;
    }
    return exit;// Return the exit status
}


// Function to list and filter pets based on provided criteria
void lister(string type, string breed, string name, string age, string gender)
{
    bool exit = false;// Flag to control loop termination
    while(!exit)
    {
        system("cls");// Clear the console for a fresh display
        int num = sysDB_1->petAmount();// Get the total number of pets in the
        //database

        vector<string> op = {type, breed, name, age, gender};// Store the filter
        //criteria

        // Display table headers
        cout << "\t\t\t    type     breed            name         age      gender\n\n";

        string choice = "";// Stores filter selection in numeric format

        // Check which filters are set to "all" and add corresponding numbers to
        //`choice`
        if(type == "all")
            choice += "1";
        if(breed == "all")
            choice += "2";
        if(name == "all")
            choice += "3";
        if(age == "all")
            choice += "4";
        if(gender == "all")
            choice += "5";

        // Iterate through each pet in the database
         for(int i=0; i < num; i++)
        {
            vector<string> p;// Vector to store pet attributes

            // Retrieve attributes for the current pet
            for(int y=0;y<5;y++)
            {
                p.push_back(sysDB_1->strict_petGet(i, y));
            }

            // Convert filter choices into numeric values
            int choice1 = stoi(choice);
            // Match pets based on the filter combination
            switch(choice1)
            {
            case 1:// Match based on breed, name, age, and gender
                if(p[1] == breed && p[2] == name && p[3] == age && p[4] == gender)
                {
                    exit = display_pets(p, i);
                }

                break;
            case 2:// Match based on type, name, age, and gender
                if(p[0] == type && p[2] == name && p[3] == age && p[4] == gender)
                {
                    exit = display_pets(p, i);
                }

                break;
            case 3:// Match based on type, breed, age, and gender
                if(p[0] == type && p[1] == breed && p[3] == age && p[4] == gender)
                {
                    exit = display_pets(p, i);
                }

                break;
            case 4:// Match based on type, breed, name, and gender
                if(p[0] == type && p[1] == breed && p[2] == name && p[4] == gender)
                {
                    exit = display_pets(p, i);
                }

                break;
            case 5:// Match based on type, breed, name, and age
                if(p[0] == type && p[1] == breed && p[2] == name && p[3] == age)
                {
                    exit = display_pets(p, i);
                }

                break;
            // Match pets based on different combinations of filters
            case 12:
                if(p[2] == name && p[3] == age && p[4] == gender)
                {
                    exit = display_pets(p, i);
                }

                break;
            case 13:
                if(p[1] == breed && p[3] == age && p[4] == gender)
                {
                    exit = display_pets(p, i);
                }

                break;
            case 14:
                if(p[1] == breed && p[2] == name && p[4] == gender)
                {
                    display_pets(p, i);
                }

                break;
            case 15:
                if(p[1] == breed && p[2] == name && p[3] == age)
                {
                    exit = display_pets(p, i);
                }

                break;
            case 23:
                if(p[0] == type && p[3] == age && p[4] == gender)
                {
                    exit = display_pets(p, i);
                }

                break;
            case 24:
                if(p[0] == type && p[2] == name && p[4] == gender)
                {
                    exit = display_pets(p, i);
                }

                break;
            case 25:
                if(p[0] == type && p[2] == name && p[3] == age)
                {
                    exit = display_pets(p, i);
                }

                break;
            case 34:
                if(p[0] == type && p[1] == breed && p[4] == gender)
                {
                    exit = display_pets(p, i);
                }

                break;
            case 35:
                if(p[0] == type && p[1] == breed && p[3] == age)
                {
                    exit = display_pets(p, i);
                }

                break;
            case 45:
                if(p[0] == type && p[1] == breed && p[2] == name)
                {
                    exit = display_pets(p, i);
                }

                break;
            case 123:
                if(p[3] == age && p[4] == gender)
                {
                    exit = display_pets(p, i);
                }

                break;
            case 124:
                if(p[2] == name && p[4] == gender)
                {
                    exit = display_pets(p, i);
                }

                break;
            case 125:
                if(p[2] == name && p[3] == age)
                {
                    exit = display_pets(p, i);
                }

                break;
            case 134:
                if(p[1] == breed && p[4] == gender)
                {
                    exit = display_pets(p, i);
                }

                break;
            case 135:
                if(p[1] == breed && p[3] == age)
                {
                    exit = display_pets(p, i);
                }

                break;
            case 145:
                if(p[1] == breed && p[2] == name)
                {
                    exit = display_pets(p, i);
                }

                break;
            case 234:
                if(p[0] == type && p[4] == gender)
                {
                    exit = display_pets(p, i);
                }

                break;
            case 235:
                if(p[0] == type && p[3] == age)
                {
                    exit = display_pets(p, i);
                }

                break;
            case 245:
                if(p[0] == type && p[2] == name)
                {
                    exit = display_pets(p, i);
                }

                break;
            case 345:
                if(p[0] == type && p[1] == breed)
                {
                    exit = display_pets(p, i);
                }

                break;
            case 1234:
                if(p[4] == gender)
                {
                    exit = display_pets(p, i);
                }

                break;
            case 1235:
                if(p[3] == age)
                {
                    exit = display_pets(p, i);
                }

                break;
            case 1245:
                if(p[2] == name)
                {
                    exit = display_pets(p, i);
                }

                break;
            case 1345:
                if(p[1] == breed)
                {
                    exit = display_pets(p, i);
                }

                break;
            case 2345:
                if(p[0] == type)
                {
                    exit = display_pets(p, i);
                }

                break;
            case 12345:
                exit = display_pets(p, i);

                break;
            default:
                system("cls");
                cout << "\n\n\n\n\n\t\t\t\t\tno pets found";
            }
            if(exit)
                break;
        }
        if(exit)
            break;
        cout << "back:ESC\t\t\t\t\t\tchoose a pet:c";
        char ch = _getch();
        if((int)ch == 27)
            break;

        if((int)ch == 99)
            {
                int co;
                cout << endl << "entry:";
                cin >> co;
                pAddAcc(co);
            }
        cout << endl;
        system("pause");
    }
}

// Menu for managing customer accounts
void account_menu()
{
    system("cls");// Clear the screen
    int customer_number = NULL;// Stores the customer account number
    int staff_number = NULL;// Stores the staff account number
    string ch;// Input choice
    string userN;// Username
    string passw;// Password

    // Display login options
    do
    {
        system("cls");
        cout << "1) sign in\n\n2) sign up\n\nEntery: ";
        ch = _getch();// Get user input
    }while(!regex_match(ch, regex("[1-2]{1}")));

    int c = stoi(ch);// Convert input to integer
    switch(c)
    {
    case 1:
        system("cls");// Clear the screen
        cout << "enter your User Name: ";

        cin >> userN;// Get username

        cout << "enter your password: ";
        cin >> passw;// Get password
        break;
    case 2:
        system("cls");// Clear the screen
        cout << "enter your User Name: ";

        cin >> userN;// Get username

        cout << "enter your password: ";
        cin >> passw;// Get password

        // Create a new customer account and add it to the system database
        customer_acc* cAcc = new customer_acc(userN, passw);
        sysDB_1->addCusAcc(cAcc);
        cout << "your account has been created";
        system("pause");
        break;
    }
    int category;// Determines if the user is a customer or staff
    int num = sysDB_1->cusAccAmount();// Get total number of customer accounts
    cout << num;
    for(int i=0;i<num; i++)
    {
        if(userN == sysDB_1->getCAccUN(i) && passw == sysDB_1->getCAccP(i))
        {
            customer_number = i;// Assign customer number
            category = 2;// Mark as customer
        }
    }

    num = sysDB_1->staffAccAmount();// Get total number of staff accounts
    cout << num;
    for(int i=0;i<num; i++)
    {
        if(userN == sysDB_1->getSAccUN(i) && passw == sysDB_1->getSAccP(i))
        {
            staff_number = i;// Assign staff number
            category = 1;// Mark as staff
        }
    }
    switch(category)
    {
    case 1:// Staff account menu
        {
        string ch;
        while(1)
        {
            system("cls");// Clear the screen
            cout << "\t\t\t\t\t\t\t\t\t" << userN << "'s account\n\n\n\n"
                 << "- pets in the facility: " << sysDB_1->petAmount() << "/310\n"
                 << "- number of customer accounts: " << sysDB_1->cusAccAmount() << endl
                 << "3) donate\n"
                 << "4) Change the Password\n"
                 << "5) Add a Pet\n"
                 << "6) Delete a pet\n"
                 << "back:B\t\t\t\tEntry: ";
             ch = _getch();
             if(ch == "b")// Exit the menu
                break;
             cout << "\n\n\n";
             int c = stoi(ch);
             switch(c)
             {
             case 4:
                 {
                 string password1;
                 string password2;
                 do
                 {
                 cout <<  "chose a new password:" << password1 << endl << endl << "verifie your new password: " << password2;
                 }while(password1 != password2);
                 sysDB_1->setSAccP(customer_number, password2);// Update password
                 cout << "\n\nyour password has been successfully updated\n";
                 system("pause");
                 }
                 break;
             case 5:
                {
                string type = " ";
                string breed = " ";
                string name = " ";
                string age = " ";
                string gender = " ";
                cout << "please enter the type of the pet: ";
                cin >> type;
                cout << "enter breed: ";
                cin >> breed;
                cout << "enter name: ";
                cin >> name;
                cout << "enter age: ";
                cin >> age;
                cout << "enter gender: ";
                cin >> gender;

                pet* Npet = new pet(type, breed, name, age, gender);
                sysDB_1->addPet(Npet);
                cout << "!!the pet has succesfuly been added!!\n";
                system("pause");
                }
                break;
             case 6:
                {
                int Pnum;
                cout << "please enter the pet code number:";
                cin >> Pnum;
                if(sysDB_1->delPet(Pnum))
                {
                    cout << "the pet has successfully been deleted";
                }
                else
                {
                    cout << "there was an error when deleting the pet";
                }
                cout << endl;
                system("pause");
                }
                break;
             }
        }
        }
        break;
    case 2:// Customer account menu
        {
        string ch;
        while(1)
        {
            system("cls");// Clear the screen
            cout << "\t\t\t\t\t\t\t\t\t" << userN << "'s account\n\n\n\n"
                 << "- wallet: " << sysDB_1->getCAccW(customer_number) << "\n"
                 << "1) My Pets\n"
                 << "2) Deposit\n"
                 << "3) donate\n"
                 << "4) Change the Password\n\n"
                 << "back:B\t\t\t\tEntry: ";
             ch = _getch();
             if(ch == "b")// Exit the menu
                break;
             cout << "\n\n\n";
             int c = stoi(ch);
             switch(c)
             {
             case 1:
                 sysDB_1->getCPetL(customer_number);// List customer pets
                 system("pause");
                 break;
             case 2:
                 int deposit;
                 cout << "you have " << sysDB_1->getCAccW(customer_number) <<"GBP in your account\n\nhow much would you like to deposit: ";
                 cin >> deposit;
                 sysDB_1->transactions(sysDB_1, deposit, customer_number, 1);
                 // Add deposit
                 cout << "your new balance is " << sysDB_1->getCAccW(customer_number) <<"GBP\n";
                 system("pause");
                 break;
             case 3:
                 int donate;
                 cout << "you have " << sysDB_1->getCAccW(customer_number) <<"GBP in your account\n\nhow much would you like to donate: ";
                 cin >> donate;
                 sysDB_1->transactions(sysDB_1, donate, customer_number, 2);
                 // Deduct donation
                 cout << "your new balance is " << sysDB_1->getCAccW(customer_number) <<"GBP\n";
                 system("pause");
                 break;
             case 4:
                 {
                 string password1;
                 string password2;
                 do
                 {
                 cout <<  "chose a new password:";
                 cin >> password1;
                 cout << endl << endl << "verifie your new password: ";
                 cin >> password2;
                 }while(password1 != password2);
                 sysDB_1->setCAccP(customer_number, password2);// Update password
                 cout << "\n\nyour password has been successfully updated\n";
                 system("pause");
                 }
                 break;
             }
        }
        }
        break;

    default:
        cout << "\t\t\t\t\t!!!!!!!!wrong password or user name!!!!!!!!!\n";
        system("pause");
    }

}

// Adds a pet to a customer's account
void pAddAcc(int p)
{
    while(1)//loop until break command
    {
    system("cls");// Clear the screen
    int customer_number = NULL;// Customer number
    string ch;// Input choice
    string userN;// Username
    string passw;// Password

    do
    {
        system("cls");
        cout << "1) sign in\n\n2) sign up\n\nEntery: ";
        ch = _getch();// Get user input
    }while(!regex_match(ch, regex("[1-2]{1}")));

    int c = stoi(ch);// Convert input to integer
    switch(c)
    {
    case 1:
        system("cls");// Clear the screen
        cout << "enter your User Name: ";

        cin >> userN;// Get username

        cout << "enter your password: ";
        cin >> passw;// Get password
        break;
    case 2:
        system("cls");// Clear the screen
        cout << "enter your User Name: ";

        cin >> userN;// Get username

        cout << "enter your password: ";
        cin >> passw;// Get password

        // Create a new customer account and add it to the system database
        customer_acc* cAcc = new customer_acc(userN, passw);
        sysDB_1->addCusAcc(cAcc);

        break;
    }
    int num = sysDB_1->cusAccAmount();// Get total customer accounts
    for(int i=0;i<num; i++)
    {
        if(userN == sysDB_1->getCAccUN(i) && passw == sysDB_1->getCAccP(i))
        {
            customer_number = i;// Assign customer number
        }
    }
    if(userN == sysDB_1->getCAccUN(customer_number) && passw == sysDB_1->getCAccP(customer_number))//confirmation of account existance
    {
        sysDB_1->addCPet(customer_number, p-1);// Add pet to the customer's account
        cout << "this pet has been successfully added to your pets\n";
        system("pause");
        break;
    }
    else
    {
        cout << "wrong details\n";
        system("pause");
    }
    }
}
