#include "HashTable.h"

#include <utility>

HashTable::HashTable(){
    m_buckets = 51;

    //Makes each element nullptr
    for (int i = 0; i < m_buckets; i++){
        m_table.push_back(nullptr);
    }
}

HashTable::HashTable(int buckets){
    //Finds closest prime number < original number
    m_buckets = closestPrime(buckets);

    //Makes each element nullptr
    for (int i = 0; i < m_buckets; i++){
        m_table.push_back(nullptr);
    }
}

HashTable::~HashTable(){
    for (int i = 0; i < m_buckets; i++){
        //If there is a user at thar array
        if (m_table[i] != nullptr){
            User* curr = m_table[i];

            //Keep deleting users in the chain
            while(curr) {
                User* next = curr->getNext();
                delete curr;
                curr = next;
            }

            //Set index back to nullptr
            m_table[i] = nullptr;
        }
    }
}

//Makes password into a value that will fit in the array
int HashTable::findKey(int hashedValue) const{
    //If the value is negative, make it positive
    if (hashedValue < 0){
        hashedValue *= -1;
    }

    return (hashedValue % m_buckets);
}

//Inserts item into array
void HashTable::insertItem(User* customer){
    int key = findKey(customer->getPassword());

    //If nothing is in that bucket, put it there
    if (m_table[key] == nullptr){
        m_table[key] = customer;
    } else{
        User* temp = m_table[key];

        //Get the last node in the chain
        while (temp->getNext() != nullptr){
            temp = temp->getNext();
        }

        //insert node into chain
        temp->setNext(customer);
        customer->setPrev(temp);
    }
}


bool HashTable::findItem(User* customer) const {
    int key = findKey(customer->getPassword());

    //No one is at index, throw error
    if (m_table[key] == nullptr){
        throw 1;
    } else {
        User* temp = m_table[key];

        //Check each user in chain
        while (temp){
            if (temp == customer){
                return true;
            }
            temp = temp->getNext();
        }

        //No user was found. Throw error
        throw 1;
    }
}

bool HashTable::findItem(std::string email, std::string password) const {
    int hashedPassword = User::hashString(std::move(password));
    int key = findKey(hashedPassword);

    if (m_table[key] == nullptr){
        throw 1;
    } else {
        User* temp = m_table[key];

        //Check each user in chain
        while (temp){
            if (temp->getEmail() == email){
                return true;
            }
            temp = temp->getNext();
        }

        //No user was found. Throw error
        throw 1;
    }
}

//Deletes a customer from the hashtable
bool HashTable::deleteItem(User* customer) {
    int key = findKey(customer->getPassword());

    if (m_table[key] == nullptr){
        return false;
    //On correct index, now look for correct customer in chain
    }else{
        User* temp = m_table[key];

        //Finds user in chain
        while (temp != customer){
            temp = temp->getNext();
        }

        //Only account in chain
        if (!temp->getNext() && !temp->getPrev()){
            delete temp;
            m_table[key] = nullptr;
        //First account in chain
        } else if (!temp->getPrev() && temp->getNext()){
            m_table[key] = temp->getNext();
            delete temp;
        //Account is in middle or end of chain
        } else {
            //Sets next node for the previous node to temp's next node
            temp->getPrev()->setNext(temp->getNext());

            //If there is a node after temp, set node's prev attribute
            //  1 -> 2 -> 3 becomes 1 -> 3
            if (temp->getPrev()->getNext() != nullptr){
                temp->getPrev()->getNext()->setPrev(temp->getPrev());
            }

            delete temp;
        }

        return true;
    }
}

//Finds the closest prime number (less than) relative to what the user
//  types in
int HashTable::closestPrime(int bucketInput){
    // All prime numbers are odd except two
    if (bucketInput & 1)
        bucketInput -= 2;
    else
        bucketInput--;

    int i, j;
    for (i = bucketInput; i >= 2; i -= 2){
        if (i % 2 == 0)
            continue;
        for (j = 3; j <= sqrt(i); j += 2){
            if (i % j == 0)
                break;
        }
        if (j > sqrt(i))
            return i;
    }

    // It will only be executed when n is 3
    return 2;
}

//Goes through each user stored in the hash and displays them
void HashTable::displayHash(){
    for (int i = 0; i < m_buckets; i++){
        cout << i << ":" << endl;

        //Print user(s) in index
        if (m_table[i] != nullptr){
            cout << *m_table[i] << endl;

            //There are more users in the chain to print
            if (m_table[i]->getNext() != nullptr){
                User* temp = m_table[i];

                //Keep going down the chain printing the users
                while (temp->getNext() != nullptr){
                    temp = temp->getNext();
                    cout << *temp << endl;
                }

            }

        //No user in index
        }else{
            cout << "Empty\n";
        }
    }
}
