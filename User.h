#ifndef BANK_MANAGEMENT_SIMULATOR_USERS_H
#define BANK_MANAGEMENT_SIMULATOR_USERS_H

#include <iostream>

class User {
public:
    User(int checking = 0, int savings = 0){
        m_firstName = "firstName";
        m_lastName = "lastName";
        m_email = "email";
        m_ssn = "111-11-1111";
    }

    User(std::string firstName, std::string lastName, std::string email, std::string ssn, int checking = 0, int savings = 0){
        m_firstName = firstName;
        m_lastName = lastName;
        m_email = email;
        m_ssn = ssn;
    }

    std::string getfirstName() const {return m_firstName;};
    std::string getLastName() const {return m_lastName;};
    std::string getEmail() const {return m_email;};
    std::string getSsn() const {return m_ssn;} //return a hash of ssn
    int getChecking() const {return m_checking;};
    int getSavings() const {return m_savings;};

    friend std::ostream& operator<<(std::ostream& sout, const User &user);

private:
    std::string m_firstName;
    std::string m_lastName;
    std::string m_email;
    std::string m_ssn;
    int m_checking;
    int m_savings;
};


#endif //BANK_MANAGEMENT_SIMULATOR_USERS_H
