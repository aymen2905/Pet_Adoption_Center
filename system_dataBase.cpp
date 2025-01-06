#include "include\system_dataBase.h"




using namespace std;

// Default constructor
system_dataBase::system_dataBase()
{
    // Initializes an empty database
}

// Parameterized constructor to set the facility address
system_dataBase::system_dataBase(string adr)
{
    this->address = adr;// Assign the provided address to the database
}

// Adds a pet object to the database if the limit is not exceeded
void system_dataBase::addPet(pet* Pet)
{
    if(pets.size() < this->max_pet)// Check the limit of pets in the database
        pets.push_back(Pet);// Add the pet to the vector
    else
        cout << "you cannot add any more pets" << endl;// Display a message if the
        //limit is reached
}

bool system_dataBase::delPet(int num)
{
    this->pets.erase(this->pets.begin()+num);
    return true;
}

// Returns the total number of pets in the database
int system_dataBase::petAmount()
{
    return pets.size();// Size of the vector containing pet objects
}


// Retrieves a specific attribute of a pet based on the given index and choice
string system_dataBase::strict_petGet(int num, int cho)
{
    switch(cho)// Attribute selection based on 'cho'
    {
    case 0:
        return this->pets[num]->getType();// Return the type of the pet
        break;
    case 1:
        return this->pets[num]->getBreed();// Return the breed of the pet
        break;
    case 2:
        return this->pets[num]->getName();// Return the name of the pet
        break;
    case 3:
        return this->pets[num]->getAge();// Return the age of the pet
        break;
    case 4:
        return this->pets[num]->getGender();// Return the gender of the pet
        break;
    }
}

// Retrieves the options list for a given filter category
vector<string> system_dataBase::optGet(int num)
{
    return this->opt[num];// Return the vector of options
}

// Sets the options list for a given filter category
void system_dataBase::optSet(int num, vector<string> op)
{
    this->opt[num] = op;// Assign the vector of options to the correspondingcategory
}

// Adds a customer account to the database
void system_dataBase::addCusAcc(customer_acc* acc)
{
    this->c_accs.push_back(acc);// Add the customer account to the vector
}

// Adds a staff account to the database
void system_dataBase::addStaffAcc(staff_acc* acc)
{
    this->s_accs.push_back(acc);// Add the staff account to the vector
}

// Returns the total number of customer accounts
int system_dataBase::cusAccAmount()
{
    return c_accs.size();// Size of the vector containing customer accounts
}

// Returns the total number of staff accounts
int system_dataBase::staffAccAmount()
{
    return s_accs.size();// Size of the vector containing staff accounts
}

// Retrieves the username of a specific customer account
string system_dataBase::getCAccUN(int num)
{
    string un = this->c_accs[num]->getUserN();
    return un;// Return the username of the specified customer account
}

// Retrieves the password of a specific customer account
string system_dataBase::getCAccP(int num)
{
    string p = this->c_accs[num]->getPass();
    return p;// Return the password of the specified customer account
}

// Retrieves the username of a specific staff account
string system_dataBase::getSAccUN(int num)
{
    string un = this->s_accs[num]->getUserN();
    return un;// Return the username of the specified staff account
}
// Retrieves the password of a specific staff account
string system_dataBase::getSAccP(int num)
{
    string p = this->s_accs[num]->getPass();
    return p;// Return the password of the specified staff account
}

// Retrieves the wallet balance of a specific customer account
int system_dataBase::getCAccW(int num)
{
    int w = this->c_accs[num]->getWallet();
    return w;// Return the wallet balance of the specified customer account
}

// Handles financial transactions for customer accounts
void system_dataBase::transactions(system_dataBase* db, int amo, int num, int f)
{
    switch(f)// Transaction type based on 'f'
    {
    case 1:
        db->c_accs[num]->deposit(amo);// Deposit money to the account
        break;
    case 2:
        db->c_accs[num]->donate(amo);// Deduct money as a donation
        break;
    }
}

// Updates the password of a specific customer account
void system_dataBase::setCAccP(int num, string pass)
{
   this->c_accs[num]->setPass(pass);// Set the new password
}

void system_dataBase::setSAccP(int num, string pass)
{
    this->s_accs[num]->setPass(pass);
}

// Retrieves the list of pets owned by a specific customer account
void system_dataBase::getCPetL(int num)
{
    this->c_accs[num]->getPets();// Call the getPets method of the customer account
}

// Adds a pet to a specific customer account
void system_dataBase::addCPet(int num, int pet)
{
    this->c_accs[num]->addPet(this->pets[pet]);// Add the pet object to the
    //customer's pet list
}
