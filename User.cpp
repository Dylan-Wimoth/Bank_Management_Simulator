#include "User.h"

std::ostream &operator<<(std::ostream &sout, const User &user) {
    sout << "First Name: " << user.getFirstName() << "\nLast Name: " << user.getLastName() << \
    "\nCheckins: " << user.getChecking() << "\nSavings: " << user.getSavings();

    return sout;
}

//Takes user string input and turns it into a hashed number
//Important for ssn and passwords as they do not was to be stored
//  as plain values
int User::hashString(std::string input) {
    std::hash<std::string> hash_obj;
    return hash_obj(input);
}
