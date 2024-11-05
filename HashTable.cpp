
#include <string>   // Include before HashTable.hpp
#include <vector>   // Include before HashTable.hpp
#include "HashTable.hpp"

// Constructor
HashTable::HashTable() : numberOfItems(0) {
    table = new HashNode*[_HASH_TABLE_SIZE];
    for (int i = 0; i < _HASH_TABLE_SIZE; i++) {
        table[i] = nullptr;
    }
}

// Returns pointer to the hash table array
HashNode** HashTable::getTable() {
    return table;
}

// Returns size of hash table
int HashTable::getSize() {
    return _HASH_TABLE_SIZE;
}

// Checks if hash table is empty
bool HashTable::isEmpty() {
    return numberOfItems == 0;
}

// Returns number of items in table
int HashTable::getNumberOfItems() {
    return numberOfItems;
}

// Stub for add method (to be implemented by team member 2)
bool HashTable::add(int key, HashNode* newNode) {
    return false;
}

// Stub for remove method (to be implemented by team member 3)
bool HashTable::remove(int key) {
    return false;
}

// Stub for clear method (to be implemented by team member 3)
void HashTable::clear() {
}

// Stub for getItem method (to be implemented by team member 2)
HashNode* HashTable::getItem(int key) {
    return nullptr;
}

// Stub for contains method (to be implemented by team member 2)
bool HashTable::contains(int key) {
    return false;
}