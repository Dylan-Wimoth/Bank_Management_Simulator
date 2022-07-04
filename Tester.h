#ifndef BANK_MANAGEMENT_SIMULATOR_TESTER_H
#define BANK_MANAGEMENT_SIMULATOR_TESTER_H

#include "User.h"
#include "HashTable.h"
#include "Simulator.h"

using namespace std;

//Used to run tests on program
class Tester {
public:
    static void runTests();
    static void assertTrue(bool condition, const std::string& test);
    static bool testUserConstructors();
    static bool testHashTableConstructor();
    static bool samePassword();
    static bool deleteOnlyAccountInChain();
    static bool deleteLastAccountInChain();
    static bool deleteMiddleAccountInChain();
    static bool findAccountTest();
    static bool findAccountWithEmailTest();
    static bool testPasswords();
};

#endif //BANK_MANAGEMENT_SIMULATOR_TESTER_H
