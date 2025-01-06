#include <string>
#include <fstream>
#include <iostream>
#include "system_dataBase.h"

#ifndef PET_H
#define PET_H


using namespace std;

class pet {
public:
    pet(int petNum);
    pet(string type, string breed, string name, string age, string gender);
    string getType();
    string getBreed();
    string getName();
    string getAge();
    string getGender();
private:
    string type;
    string breed;
    string name;
    string age;
    string gender;
};


#endif //PET_H
