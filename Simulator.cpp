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
            login(newUser);
        }
    }
}

//User when a user logs in with their information
void Simulator::login() {

}

//Used when a user creates a new account. Automatically logs in
void Simulator::login(User* customer) {
    try {
        m_database->findItem(customer);
    }

    catch (int e){
        cout << "ERROR: Account could not be found.\n";
        return;
    }

    m_loggedInAs = customer;
}

//Creates user and adds them to database.
//  Logs in after user is created
User* Simulator::createUser() {
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

    //Creates user object
    User* newUser = new User(firstName,lastName,password,email,ssn);
    //Inserts user into the database
    m_database->insertItem(newUser);
    cout << "Account Created!\n";
    //Returns the user so simulation can log in
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
bool Simulator::passwordCheck(const std::string& password) {
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
