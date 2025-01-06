#include "include\pet.h"


using namespace std;

// Constructor that initializes a pet object based on the pet number
pet::pet(int petNum) {

    if(petNum > 300)
    {
        throw std::runtime_error("Invalid pet number!");
    }

    string line;// Temporary variable to store each line from the file

    // Open and read the 'type.txt' file to set the type of the pet
    ifstream t_file("type.txt");
    for(int i=0; i < petNum; i++)
    {
        if(getline(t_file, line)) {
            this->type = line;// Set the type for this pet
        }
        else
            cout << "error";// Display an error if unable to read the line
    }
    t_file.close();

    // Open and read the 'breed.txt' file to set the breed of the pet
    ifstream b_file("breed.txt");
    for(int i=0; i < petNum; i++)
    {
        if(getline(b_file, line)) {
            this->breed = line;// Set the breed for this pet
        }
        else
            cout << "error";// Display an error if unable to read the line
    }
    b_file.close();

    // Open and read the 'name.txt' file to set the name of the pe
    ifstream n_file("name.txt");
    for(int i=0; i < petNum; i++)
    {
        if(getline(n_file, line)) {
            this->name = line;// Set the name for this pet
        }
        else
            cout << "error";// Display an error if unable to read the line

    }
    n_file.close();

    // Open and read the 'age.txt' file to set the age of the pet
    ifstream a_file("age.txt");
    for(int i=0; i < petNum; i++)
    {
        if(getline(a_file, line)) {
            this->age = line;// Set the age for this pet
        }
        else
            cout << "error";// Display an error if unable to read the line
    }
    a_file.close();

    // Open and read the 'gender.txt' file to set the gender of the pet
    ifstream g_file("gender.txt");
    for(int i=0; i < petNum; i++)
    {
        if(getline(g_file, line)) {
            this->gender = line;// Set the gender for this pet
        }
        else
            cout << "error";// Display an error if unable to read the line
    }
    g_file.close();
}


// Constructor to initialize a pet object with given attributes
pet::pet(string type, string breed, string name, string age, string gender) {

    if(type[0] >= 'a' && type[0] <= 'z')
    {
        type[0] = type[0] - ('a' - 'A');
    }

    this->type = type;// Set the pet type
    this->breed = breed;// Set the pet breed
    this->name = name;// Set the pet name
    this->age = age;// Set the pet age
    this->gender = gender;// Set the pet gender
}



string pet::getType() {return type;}// Getter for pet type
string pet::getBreed() {return breed;}// Getter for pet breed
string pet::getName() {return name;}// Getter for pet name
string pet::getAge() {return age;}// Getter for pet age
string pet::getGender() {return gender;}// Getter for pet gender
