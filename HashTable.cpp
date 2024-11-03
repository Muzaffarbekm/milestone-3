/**
 * @file HashTable.cpp
 * @brief Implementation of HashTable methods
 * @authors Muzaffarbek Muratov,Rishika Bharodiya, Arpan Rakeshbhai Savani
 * @date 11/02/2024
 */

#include "HashTable.hpp"
#include <stdexcept>

// Constructor
HashTable::HashTable() : numberOfItems(0) {
    table = new HashNode*[_HASH_TABLE_SIZE];
    for (int i = 0; i < _HASH_TABLE_SIZE; i++) {
        table[i] = nullptr;
    }
}

// Destructor
HashTable::~HashTable() {
    clear();  // Clean up all nodes
    delete[] table;
    table = nullptr;
}

// Hash function
int HashTable::hashFunction(int key) const {
    return key % _HASH_TABLE_SIZE;
}

// Required method for testing
HashNode** HashTable::getTable() {
    return table;
}

// Get the size of the hash table
int HashTable::getSize() {
    return _HASH_TABLE_SIZE;
}

// Check if hash table is empty
bool HashTable::isEmpty() {
    return numberOfItems == 0;
}

// Get number of items in the hash table
int HashTable::getNumberOfItems() {
    return numberOfItems;
}

// Method stubs for other team members
bool HashTable::add(int key, HashNode* newNode) {
    return false;  // This will be implemented by Person 2
}

bool HashTable::remove(int key) {
    return false;  // This will be implemented by Person 3
}

void HashTable::clear() {
    // This will be implemented by Person 3
}

HashNode* HashTable::getItem(int key) {
    return nullptr;  // This will be implemented by Person 2
}

bool HashTable::contains(int key) {
    return false;  // This will be implemented by Person 2
}