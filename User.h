#ifndef BANK_MANAGEMENT_SIMULATOR_USERS_H
#define BANK_MANAGEMENT_SIMULATOR_USERS_H

#include <iostream>

class User {
public:
    User(){
        m_firstName = "firstName";
        m_lastName = "lastName";
        m_password = hashString("1");
        m_email = "email";
        m_ssn = hashString("111111111");
        m_checking = 0;
        m_savings = 0;
    }

    User(std::string firstName, std::string lastName, std::string password, std::string email, std::string ssn){
        m_firstName = std::move(firstName);
        m_lastName = std::move(lastName);
        m_password = hashString(password);
        m_email = std::move(email);
        m_ssn = hashString(ssn);
        m_checking = 0;
        m_savings = 0;
    }

    //Getters
    std::string getFirstName() const {return m_firstName;};
    std::string getLastName() const {return m_lastName;};
    int getPassword() const {return m_password;};
    std::string getEmail() const {return m_email;};
    int getSsn() const {return m_ssn;} //return a hash of ssn
    int getChecking() const {return m_checking;};
    int getSavings() const {return m_savings;};
    User* getPrev() {return m_prev;};
    User* getNext() {return m_next;};

    //setters
    void setFirstName(std::string firstName){m_firstName = firstName;};
    void setLastName(std::string lastName){m_lastName = lastName;};
    void setEmail(std::string email){m_email = email;};
    void setChecking(int checking){m_checking = checking;};
    void setSavings(int savings){m_savings = savings;};
    void setNext(User* next){m_next = next;};
    void setPrev(User* prev){m_prev = prev;};

    //Overloaded << operator that prints first, last, checkings, savings
    friend std::ostream& operator<<(std::ostream& sout, const User &user);
    int hashString(std::string);

private:
    std::string m_firstName;
    std::string m_lastName;
    int m_password;
    std::string m_email;
    int m_ssn;
    int m_checking;
    int m_savings;

    //Used for Hashtable
    User* m_prev = nullptr;
    User* m_next = nullptr;
};

#endif //BANK_MANAGEMENT_SIMULATOR_USERS_H
