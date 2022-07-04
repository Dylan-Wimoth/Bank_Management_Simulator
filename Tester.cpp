#include "Tester.h"

//Runs all tests
void Tester::runTests() {
    assertTrue(testUserConstructors(), "User Constructors");
    assertTrue(testHashTableConstructor(), "Hash Table Constructors");
    assertTrue(samePassword(), "Inserting with Same Password");
    assertTrue(deleteOnlyAccountInChain(), "Deleting Only Account in Chain");
    assertTrue(deleteLastAccountInChain(), "Deleting Last Account in Chain");
    assertTrue(deleteMiddleAccountInChain(), "Deleting Middle Account in Chain");
    assertTrue(testPasswords(),"Password Requirements");
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

//Tests inserting users with same password. Ensures chaining works
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

bool Tester::deleteOnlyAccountInChain() {
    HashTable hash;

    User* random = new User();
    hash.insertItem(random);

    //If nothing was deleted, test failed
    if (!hash.deleteItem(random)){
        delete random;
        return false;
    }

    //If there are any nodes in the table, test failed
    for (int i = 0; i < hash.getBuckets(); i++){
        if (hash.getTable()[i] != nullptr){
            return false;
        }
    }

    return true;
}

bool Tester::deleteLastAccountInChain() {
    HashTable hash;

    User* random = new User();
    User* random2 = new User();

    hash.insertItem(random);
    hash.insertItem(random2);

    //If user wasn't deleted, test failed
    if (!hash.deleteItem(random2)){
        delete random;
        delete random2;
        return false;
    }

    //If random's next is not nullptr, test failed
    //  (user/user pointer wasn't deleted)
    if (random->getNext()){
        delete random;
        return false;
    }

    delete random;
    delete random2;
    return true;

}

bool Tester::deleteMiddleAccountInChain() {
    HashTable hash;

    User* random = new User();
    User* random2 = new User();
    User* random3 = new User();

    hash.insertItem(random);
    hash.insertItem(random2);
    hash.insertItem(random3);

    //If user wasn't deleted, test failed
    if (!hash.deleteItem(random2)){
        delete random;
        delete random2;
        delete random3;
        return false;
    }

    //First item in chain does not properly point to next item
    if (random->getNext() != random3){
        delete random;
        delete random3;
        return false;
    }

    //Last item in chain doesn't point to item before the one that
    //  was deleted
    if (random3->getPrev() != random || random3->getNext()){
        delete random;
        delete random3;
        return false;
    }

    return true;
}

bool Tester::testPasswords() {
    Simulator testSim = Simulator();

    if (testSim.passwordCheck("1234")){
        return false;
    }

    //wrong length
    if (testSim.passwordCheck("P#ssw0rd")){
        return false;
    }

    //No uppercase
    if (testSim.passwordCheck("p#ssw0rd1234")){
        return false;
    }

    //No special char
    if (testSim.passwordCheck("passw0rd1234")){
        return false;
    }

    //No Lowercase letters
    if (testSim.passwordCheck("PASSW0RD1234")){
        return false;
    }

    //Follows parameters
    if (testSim.passwordCheck("P#ssw0rd1234")){
        return true;
    }

    return false;
}
