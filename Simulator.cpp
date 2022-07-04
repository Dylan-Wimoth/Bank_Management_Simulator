#include "Simulator.h"

Simulator::Simulator() {
    m_database = new HashTable();
    m_loggedInAs = nullptr;
}

Simulator::~Simulator() {
    delete m_database;
}

//Adjust while loop so it checks if the simulator is logged in
// if logged in, show different menu for user
void Simulator::mainMenu() {
    int userChoice = -1;

    while (userChoice != 4) {
        do {
            cout << "1) Login\n2) New Customer\n3) Forgot Password\n4) Quit\n";
            cout << "Choice: ";
            cin >> userChoice;
            cout << endl;
        } while (userChoice < 1 || userChoice > 5);

        if (userChoice == 1) {
            login();
        } else if (userChoice == 2) {
            User *newUser = createUser();
            //logIn(newUser);
        }
    }
}

User *Simulator::login() {
    return nullptr;
}

User *Simulator::login(User* ) {
    return nullptr;
}

//Creates user and adds them to database.
//  Logs in after user is created
User *Simulator::createUser() {
    std::string firstName, lastName, email, ssn, password, userResponse = "";

    do{
        cout << "First Name:";
        cin >> firstName;
        cout << "Is " << firstName << " correct?\n";
        cout << "(y/n):";
        cin >> userResponse;
    }while(userResponse != "y" && userResponse != "Y");

    do{
        cout << "Last Name:";
        cin >> lastName;
        cout << "Is " << lastName << " correct?\n";
        cout << "(y/n):";
        cin >> userResponse;
    }while(userResponse != "y" && userResponse != "Y");

    do{
        password = passwordCreator();
        cout << "Is " << password << " correct?\n";
        cout << "(y/n):";
        cin >> userResponse;
    }while(userResponse != "y" && userResponse != "Y");

    do{
        cout << "Email:";
        cin >> email;
        cout << "Is " << email << " correct?\n";
        cout << "(y/n):";
        cin >> userResponse;
    }while(userResponse != "y" && userResponse != "Y");

    do{
        cout << "Social Security Number:";
        cin >> ssn;
        cout << "Is " << ssn << " correct?\n";
        cout << "(y/n):";
        cin >> userResponse;
    }while(userResponse != "y" && userResponse != "Y");

    User* newUser = new User(firstName,lastName,password,email,ssn);
    m_database->insertItem(newUser);
    cout << "Account Created!\n";
    return newUser;
}

//Prompts the User to enter password information
std::string Simulator::passwordCreator() {
    cout << "\nPasswords must fit the following requirements:\n-At least 12 characters\n"
            "-Mixture of upper and lowercase Letters\n-Mixture of letters and numbers\n"
            "-At least one special character (!,@,#,?)\n\n";

    std::string password;

    do {
        cout << "Enter Password:";
        cin >> password;
    }while(!passwordCheck(password));

    return password;
}

//Returns true if the password fits the requirements set by
//  passwordCreator();
bool Simulator::passwordCheck(std::string password) {
    bool upperCase,lowerCase,specialChar = false;

    for (char letter : password){
        //There is an uppercase letter
        if (isupper(letter)){
            upperCase = true;
        }

        //There is a lowercase letter
        if (islower(letter)){
            lowerCase = true;
        }

        //There is a special character
        if (letter == '!' || letter == '@' || letter == '#' || letter == '?'){
            specialChar = true;
        }
    }

    if (password.length() >= 12 && upperCase && lowerCase && specialChar){
        return true;
    }

    return false;
}
