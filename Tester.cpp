#include "Tester.h"

//Runs all tests
void Tester::runTests() {
    assertTrue(testUserConstructors(), "User Constructors");
    assertTrue(testHashTableConstructor(), "Hash Table Constructors");
    assertTrue(samePassword(), "Inserting with Same Password");
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
    if (defaultUser.getFirstName() != "firstName" || defaultUser.getLastName() != "lastName"){
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
    if (overloadedUser.getFirstName() != "Joe" || overloadedUser.getLastName() != "Williams"){
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

    return true;
}

//Makes sure constructors initialize nullptr user pointers
bool Tester::testHashTableConstructor() {
    HashTable hash1;
    HashTable hash2(100);

    for (int i = 0; i < hash1.getBuckets(); i++){
        if (hash1.getTable()[i] != nullptr)
            return false;
    }

    for (int i = 0; i < hash2.getBuckets(); i++){
        if (hash2.getTable()[i] != nullptr)
            return false;
    }

    return true;
}

bool Tester::samePassword() {
    HashTable hash;

    User* random = new User();
    User* random2 = new User("Gary", "Wilkinson", "1", "email@random", "111111111");
    User* random3 = new User();

    hash.insertItem(random);
    hash.insertItem(random2);
    hash.insertItem(random3);

    if (hash.getTable()[8] == random && hash.getTable()[8]->getNext() == random2 &&
        hash.getTable()[8]->getNext()->getNext() == random3) {

        delete random;
        delete random2;
        delete random3;
        return true;
    }

    delete random;
    delete random2;
    delete random3;

    return false;


}
