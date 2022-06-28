#ifndef BANK_MANAGEMENT_SIMULATOR_TESTER_H
#define BANK_MANAGEMENT_SIMULATOR_TESTER_H

#include "User.h"
#include "HashTable.h"

using namespace std;

//Used to run tests on program
class Tester {
public:
    void runTests();
    void assertTrue(bool condition, const std::string& test);
    bool testUserConstructors();
};

#endif //BANK_MANAGEMENT_SIMULATOR_TESTER_H
