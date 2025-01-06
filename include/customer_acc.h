#include <vector>
#include <string>
#include <iostream>
#include "account.h"
#include "pet.h"

#ifndef CUSTOMER_ACC_H
#define CUSTOMER_ACC_H


class customer_acc: public account {
public:
    customer_acc(string un, string pass): account(un, pass) {}
    void addPet(pet* Pet);
    void getPets();
    string getPass();
    void deposit(int am);
    void donate(int am);
    int getWallet();
    void display_pets(vector<string> p, int x);
private:
    vector<pet*> pets;
    int wallet = 0;
};


#endif //EE2010_PROJECT_1_CUSTOMER_ACC_H
