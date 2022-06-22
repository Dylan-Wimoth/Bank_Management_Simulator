#include <iostream>
#include "User.h"
#include "Database.h"

int main() {
    User personOne("dylan", "wilmoth", "random", "41231", 500, 500);

    std::cout << personOne << std::endl;
}
