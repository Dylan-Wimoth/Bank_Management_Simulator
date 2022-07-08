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
            cout << "\n1) Login\n2) New Customer\n3) Forgot Password\n4) Quit\n";
            cout << "Choice:";
            cin >> userChoice;
            cout << endl;
        } while (userChoice < 1 || userChoice > 5);

        if (userChoice == 1) {
            login();
        } else if (userChoice == 2) {
            User *newUser = createUser();
            login(newUser);
        } else if (userChoice == 3) {
            forgotPassword();
        }
    }
}

//If simulator is logged in as someone, display log in menu
void Simulator::logInMenu() {
    if (m_loggedInAs){
        int userChoice = -1;

        cout << "\nWelcome, " << m_loggedInAs->getFirstName() << " " << m_loggedInAs->getLastName() << endl;
        while (userChoice != 6 && userChoice != 5) {
            do {
                cout << "\nWhat would you like to do?\n";
                cout << "1) Account Details\n";
                cout << "2) Deposit Money\n";
                cout << "3) Withdraw Money\n";
                cout << "4) Update Personal Information\n";
                cout << "5) Delete Account\n";
                cout << "6) Log out\n";
                cout << "Choice:";
                cin >> userChoice;
                cout << endl;
            } while (userChoice < 1 || userChoice > 6);

            if (userChoice == 1) {
                cout << *m_loggedInAs << "\n";
            } else if (userChoice == 2) {
                depositMoney();
            } else if (userChoice == 3) {
                try{
                    withdrawMoney();
                }
                catch (int e){
                    cout << "ERROR " << e << ": Amount is too large\n";
                }
            } else if (userChoice == 4) {
                changeInformation();
            } else if (userChoice == 5) {
                int deleteAccountChoice = -1;

                do {
                    cout << "Are you sure you want to delete your account?\n";
                    cout << "1) Yes\n2) No\n";
                    cin >> deleteAccountChoice;
                } while (deleteAccountChoice != 1 && deleteAccountChoice != 2);

                if (deleteAccountChoice == 1){
                    m_database->deleteItem(m_loggedInAs);
                    m_loggedInAs = nullptr;
                }
            }
        }
    }

    m_loggedInAs = nullptr;
}

//Used when a user logs in with their information
//  goes to log in menu if they log in
void Simulator::login() {
    std::string email, password;
    User* temp = nullptr;

    cout << "Enter email:";
    cin >> email;
    cout << "Enter Password:";
    cin >> password;

    try{
        temp = m_database->findItem(email, password);
    }

    catch (int e){
        cout << "ERROR " << e << ": Account could not be found.\n";
        return;
    }

    m_loggedInAs = temp;
    logInMenu();
}

//Used when a user creates a new account. Automatically logs in
// goes to log in menu
void Simulator::login(User* customer) {
    try {
        m_database->findItem(customer);
    }

    catch (int e){
        cout << "ERROR " << e << ": Account could not be found.\n";
        return;
    }

    m_loggedInAs = customer;
    logInMenu();
}

//Determines if person is in system
//  if so, they can change their password
void Simulator::forgotPassword() {
    std::string ssn, password;
    User* customer = nullptr;

    cout << "What is your ssn?";
    cin >> ssn;

    try {
        customer = m_database->findItem(ssn);
    }

    //Account is not in database
    catch (int e){
        cout << "ERROR " << e << ": Account could not be found.\n";
        return;
    }

    password = passwordCreator();
    m_database->moveItem(customer, password);
    cout << "Password changed.\n";

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

void Simulator::depositMoney() {
    int userChoice = -1;
    int amount = 0;

    //What account
    do {
     cout << "1) Checking\n2) Savings\n";
     cin >> userChoice;
    } while (userChoice < 1 || userChoice > 2);

    //How much to be deposited
    do {
        cout << "How much?\n";
        cin >> amount;
    } while (amount < 0);

    if (userChoice == 1)
        m_loggedInAs->setChecking(m_loggedInAs->getChecking() + amount);
    else
        m_loggedInAs->setSavings(m_loggedInAs->getSavings() + amount);

    cout << "$" << amount << " deposited!\n";
}

void Simulator::withdrawMoney() {
    int userChoice = -1;
    int amount = 0;

    //What account
    do {
        cout << "1) Checking\n2) Savings\n";
        cin >> userChoice;
    } while (userChoice < 1 || userChoice > 2);

    //How much to be withdrawn
    do {
        cout << "How much?\n";
        cin >> amount;
    } while (amount < 0);

    if (userChoice == 1){
        m_loggedInAs->checkingCheck(amount) ? m_loggedInAs->setChecking(m_loggedInAs->getChecking() - amount) : throw 2;
    }
    else{
        m_loggedInAs->savingsCheck(amount) ? m_loggedInAs->setSavings(m_loggedInAs->getSavings() - amount) : throw 2;
    }
}

void Simulator::changeInformation() {
    int userChoice = -1;
    std::string changedValue;

    cout << "What would you like to change?\n";
    do {
        cout << "1) First name\n";
        cout << "2) Last name\n";
        cout << "3) Password\n";
        cout << "4) Email\n";
        cin >> userChoice;
    } while (userChoice < 0 || userChoice > 4);

    if (userChoice == 1){
        cout << "Enter new first name:";
        cin >> changedValue;
        m_loggedInAs->setFirstName(changedValue);

        cout << "First name changed.\n";
    } else if (userChoice == 2){
        cout << "Enter new last name:";
        cin >> changedValue;
        m_loggedInAs->setLastName(changedValue);

        cout << "Last name changed.\n";
    } else if (userChoice == 3){
        m_database->displayHash();
        changedValue = passwordCreator();
        m_database->moveItem(m_loggedInAs, changedValue);
        m_database->displayHash();

        cout << "Password changed.\n";
    } else{
        cout << "Enter new email:";
        cin >> changedValue;
        m_loggedInAs->setEmail(changedValue);

        cout << "Email changed.\n";
    }

}
