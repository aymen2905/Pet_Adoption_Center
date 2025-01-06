#include "include\customer_acc.h"

void display_Cpets(vector<string> p,int x);
// Adds a pet to the customer's list of pets
void customer_acc::addPet(pet* Pet)
{
    this->pets.push_back(Pet);// Add the pet to the vector
}

// Displays all pets owned by the customer
void customer_acc::getPets()
{

    int num = pets.size();// Get the number of pets
    cout << "\t\t\t    type     breed            name         age      gender\n\n";
    for(int i=0;i < num; i++)// Get the number of pets
    {
        vector<string> p;// Temporary vector to hold pet details

        // Retrieve each pet attribute
        p.push_back(this->pets[i]->getType());// Get pet type
        p.push_back(this->pets[i]->getBreed());// Get pet breed
        p.push_back(this->pets[i]->getName());// Get pet name
        p.push_back(this->pets[i]->getAge());// Get pet age
        p.push_back(this->pets[i]->getGender());// Get pet gender

        display_Cpets(p, i);// Display the pet details
    }
}

// Displays the details of a single pet in a formatted manner
void display_Cpets(vector<string> p, int x)
{
    cout << "\t\t\t" << x+1 << ") " << p[0];// Display pet type


    // Format and display each attribute with proper alignment
    int leng = p[0].length();
    for(int i=0; leng+i < 9; i++)
    {
        cout << " ";
    }
    cout << p[1];// Pet breed

    leng = p[1].length();
    for(int i=0; leng+i < 15; i++)
    {
        cout << " ";
    }
    cout << p[2];// Pet name

    leng = p[2].length();
    for(int i=0; leng+i < 15; i++)
    {
        cout << " ";
    }
    cout << p[3];// Pet age

    leng = p[3].length();
    for(int i=0; leng+i < 10; i++)
    {
        cout << " ";
    }
    cout << p[4] << endl << endl;// Pet gender
}

// Increases the customer's wallet balance
void customer_acc::deposit(int am)
{
    this->wallet += am;
}

// Decreases the customer's wallet balance
void customer_acc::donate(int am)
{
    this->wallet -= am;
}

// Returns the customer's password
string customer_acc::getPass()
 {
     return this->password;
 }

// Returns the customer's wallet balance
int customer_acc::getWallet()
{
    return wallet;
}
