#ifndef BANK_MANAGEMENT_SIMULATOR_SIMULATOR_H
#define BANK_MANAGEMENT_SIMULATOR_SIMULATOR_H

#include "HashTable.h"
#include "User.h"

class Simulator {
public:
    Simulator();
    ~Simulator();

    void mainMenu();
    void logInMenu();
    void login();
    void login(User*);
    User* createUser();

    void forgotPassword();
    void depositMoney();
    void withdrawMoney();
    void changeInformation();

    std::string passwordCreator();
    bool passwordCheck(const std::string&);
private:
    User* m_loggedInAs;
    HashTable* m_database;
};

#endif //BANK_MANAGEMENT_SIMULATOR_SIMULATOR_H
