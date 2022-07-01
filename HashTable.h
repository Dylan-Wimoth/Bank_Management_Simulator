#ifndef BANK_MANAGEMENT_SIMULATOR_HASHTABLE_H
#define BANK_MANAGEMENT_SIMULATOR_HASHTABLE_H

#include<vector>
#include <bits/stdc++.h>
#include "User.h"
using namespace std;

class HashTable {
    int m_buckets;
    vector<User*> m_table;

public:
    HashTable();
    explicit HashTable(int buckets);
    int getBuckets() const{return m_buckets;};
    vector<User*> getTable() {return m_table;};

    void insertItem(User*);
    bool deleteItem(User*);
    void displayHash();
    static int closestPrime(int);
    int findKey(int) const;
};

#endif //BANK_MANAGEMENT_SIMULATOR_HASHTABLE_H
