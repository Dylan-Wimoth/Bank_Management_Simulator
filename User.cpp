#include "User.h"

User::User(){
    m_firstName = "firstName";
    m_lastName = "lastName";
    m_password = hashString("1");
    m_email = "email";
    m_ssn = hashString("111111111");
    m_checking = 0;
    m_savings = 0;
}

User::User(std::string firstName, std::string lastName, std::string password, std::string email, std::string ssn){
    m_firstName = std::move(firstName);
    m_lastName = std::move(lastName);
    m_password = hashString(password);
    m_email = std::move(email);
    m_ssn = hashString(ssn);
    m_checking = 0;
    m_savings = 0;
}

User::~User(){
    m_firstName = "";
    m_lastName = "";
    m_password = 0;
    m_email = "";
    m_ssn = 0;
    m_checking = 0;
    m_savings = 0;
}

//Displays user information in readable format
std::ostream &operator<<(std::ostream &sout, const User &user) {
    sout << "First Name: " << user.getFirstName() << "\nLast Name: " << user.getLastName() << \
    "\nEmail: " << user.getEmail() << "\nCheckins: $" << user.getChecking() << "\nSavings: $" << user.getSavings();

    return sout;
}

//Takes user string input and turns it into a hashed number
//Important for ssn and passwords as they do not was to be stored
//  as plain values
int User::hashString(std::string input) {
    std::hash<std::string> hash_obj;
    return hash_obj(input);
}

//Makes sure withdraw amount is not greater than what's
//  in the account
bool User::checkingCheck(int withdrawAmount) {
    if (withdrawAmount > m_checking)
        return false;

    return true;
}

//Makes sure withdraw amount is not greater than what's
//  in the account
bool User::savingsCheck(int withdrawAmount) {
    if (withdrawAmount > m_savings)
        return false;

    return true;
}
