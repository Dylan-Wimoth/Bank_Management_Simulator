//#include "HashTable.h"
//
//HashTable::HashTable(int buckets){
//    m_buckets = buckets;
//    table = new list<User*>[m_buckets];
//}
//
//void HashTable::insertItem(int key) {
//    int index = hashFunction(key);
//    table[index].push_back(key);
//}
//
//void HashTable::deleteItem(int key) {
//    // get the hash index of key
//    int index = hashFunction(key);
//
//    // find the key in (index)th list
//    list <int> :: iterator i;
//    for (i = table[index].begin();
//         i != table[index].end(); i++) {
//        if (*i == key)
//            break;
//    }
//
//    // if key is found in hash table, remove it
//    if (i != table[index].end())
//        table[index].erase(i);
//}
//
//// function to display hash table
//void HashTable::displayHash() {
//    for (int i = 0; i < BUCKET; i++) {
//        cout << i;
//        for (auto x : table[i])
//            cout << " --> " << x;
//        cout << endl;
//    }
//}
