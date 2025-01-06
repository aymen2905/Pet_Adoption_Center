#include <string>
#include <vector>
#include <iostream>
#include "account.h"
#include "system_dataBase.h"
#include "pet.h"

#ifndef STAFF_ACC_H
#define STAFF_ACC_H


class staff_acc: public account {
public:
staff_acc(string un, string pass, string stat):status(stat), account(un, pass) {}
void setStatus(string st);
void setCusPass(customer_acc* c, string pass);
string getStat();
string getPass();
staff_acc* staffAdd(string un, string pass, string stat);
private:
    string status;
};


#endif //EE2010_PROJECT_1_STAFF_ACC_H
