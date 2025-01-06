#include <string>


#ifndef ACCOUNT_H
#define ACCOUNT_H

using namespace std;

class account {
public:
    account(string un, string pass):userName(un), password(pass) {}
    string getUserN(){
        return userName;
    }
    void setUN(string st){
        userName = st;
    }
    void setPass(string st){
        password = st;
    }
protected:
    string password;
private:
    string userName;
};


#endif //EE2010_PROJECT_1_ACCOUNT_H
