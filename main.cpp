#include <iostream>
#include "Simulator.h"
#include "Tester.h"

int main() {
//    Tester::runTests();


    Simulator simulation = Simulator();
    cout << "Welcome to C++ Bank! How can I help you?\n";
    simulation.mainMenu();
    cout << "Thanks for stopping by!\n";
}
