#ifndef SYSTEM_DATABASE_H
#define SYSTEM_DATABASE_H
#include <vector>
#include <string>
#include <iostream>
#include "customer_acc.h"
#include "staff_acc.h"

class system_dataBase
{
public:
    system_dataBase();
    system_dataBase(std::string adr);
    void addPet(pet* Pet);
    bool delPet(int num);
    void addCusAcc(customer_acc* acc);
    void addStaffAcc(staff_acc* acc);
    void addCPet(int num, int pet);
    int petAmount();
    int cusAccAmount();
    int staffAccAmount();
    std::string strict_petGet(int num, int cho);
    std::vector<string> optGet(int num);
    void optSet(int num, std::vector<string> op);
    string getCAccUN(int num);
    string getCAccP(int num);
    string getSAccUN(int num);
    string getSAccP(int num);
    int getCAccW(int num);
    void transactions(system_dataBase* db, int amo, int num, int f);
    void setCAccP(int num, string pass);
    void setSAccP(int num, string pass);
    void getCPetL(int num);


private:
    const int max_pet = 310;
    std::vector<pet*> pets;
    std::vector<string> opt[5];
    std::vector<customer_acc*> c_accs;
    std::vector<staff_acc*> s_accs;
    std::string address;
};

#endif
