#include "User.h"

std::ostream &operator<<(std::ostream &sout, const User &user) {
    sout << "First Name: " << user.getfirstName() << "\nLast Name: " << user.getLastName() << \
    "\nCheckins: " << user.getChecking() << "\nSavings: " << user.getSavings();

    return sout;
}
