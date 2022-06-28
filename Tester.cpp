#include "Tester.h"

//Runs all tests
void Tester::runTests() {
    //assertTrue(testUserConstructors(), "User Constructors");
    assertTrue(testUserConstructors(), "User Constructors");
}

//Displays test results
void Tester::assertTrue(bool condition, const std::string& test) {
    if (condition) {
        cout << test << ": Passed\n";
    }else {
        cout << test << ": Failed\n";
    }

}

//Makes sure constructors for Users builds correctly
bool Tester::testUserConstructors() {
    User defaultUser = User();
    User overloadedUser = User("Joe", "Williams", "random123", "Joe.Williams@joe.com", "222424532");

    //Default user check
    if (defaultUser.getfirstName() != "firstName" || defaultUser.getLastName() != "lastName"){
        cout << "Default User Name Failed\n";
        return false;
    }

    if (defaultUser.getPassword() != defaultUser.hashString("1") || defaultUser.getSsn() != defaultUser.hashString("111111111")){
        cout << "Default User ssn or password Failed\n";
        return false;
    }

    if (defaultUser.getChecking() != 0 || defaultUser.getSavings() != 0){
        cout << "Default User Checking/Saving Failed\n";
        return false;
    }

    if (defaultUser.getEmail() != "email"){
        cout << "Default User Email Failed\n";
        return false;
    }

    //overLoadedUser Check
    if (overloadedUser.getfirstName() != "Joe" || overloadedUser.getLastName() != "Williams"){
        cout << "Over Loaded User Name Failed\n";
        return false;
    }

    if (overloadedUser.getPassword() != overloadedUser.hashString("random123") || overloadedUser.getSsn() != overloadedUser.hashString("222424532")){
        cout << "Over Loaded User ssn or password Failed\n";
        return false;
    }

    if (overloadedUser.getChecking() != 0 || overloadedUser.getSavings() != 0){
        cout << "Over Loaded User Checking/Saving Failed\n";
        return false;
    }

    if (overloadedUser.getEmail() != "Joe.Williams@joe.com"){
        cout << "Over Loaded User Email Failed\n";
        return false;
    }
}
