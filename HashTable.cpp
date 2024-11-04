/**
 * @file HashTable.cpp
 * @brief Implementation of HashTable methods
 * @authors Muzaffarbek Muratov, Rishika Bharodiya, Arpan Rakeshbhai Savani
 * @date 11/02/2024
 */

#include "HashTable.hpp"
#include <stdexcept>
#include <iostream> // For error output

// Constructor
HashTable::HashTable() : numberOfItems(0) {
    table = new HashNode*[HASH_TABLE_SIZE];
    if (!table) {
        throw std::runtime_error("Memory allocation failed for hash table.");
    }
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        table[i] = nullptr;
    }
}

// Destructor
HashTable::~HashTable() {
    clear();  // Clean up all nodes
    delete[] table; // Free the allocated table
    table = nullptr; // Prevent dangling pointer
}

// Hash function
int HashTable::hashFunction(int key) const {
    return key % HASH_TABLE_SIZE;
}

// Required method for testing
HashNode** HashTable::getTable() {
    return table;
}

// Get the size of the hash table
int HashTable::getSize() const {
    return HASH_TABLE_SIZE;
}

// Check if hash table is empty
bool HashTable::isEmpty() const {
    return numberOfItems == 0;
}

// Get number of items in the hash table
int HashTable::getNumberOfItems() const {
    return numberOfItems;
}

// Add method
bool HashTable::add(int key, HashNode* newNode) {
    if (contains(key)) {
        return false;  // Key already exists
    }

    int index = hashFunction(key);  // Get index using hash function

    // Insert new node at the beginning of the linked list at index
    newNode->next = table[index];
    table[index] = newNode;
    numberOfItems++;  // Increase item count
    return true;
}

// Contains method
bool HashTable::contains(int key) const {
    int index = hashFunction(key);
    HashNode* current = table[index];
    while (current != nullptr) {
        if (current->key == key) {
            return true;  // Key found
        }
        current = current->next;
    }
    return false;  // Key not found
}

// Clear method
void HashTable::clear() {
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        HashNode* current = table[i];
        while (current != nullptr) {
            HashNode* temp = current;
            current = current->next;
            delete temp; // Free the node memory
        }
        table[i] = nullptr; // Set the table slot to nullptr
    }
    numberOfItems = 0; // Reset item count
}

// Remove method 
bool HashTable::remove(int key) {
    int index = hashFunction(key);
    HashNode* current = table[index];
    HashNode* prev = nullptr;

    while (current != nullptr) {
        if (current->key == key) {
            if (prev == nullptr) { // Node to remove is the first in the list
                table[index] = current->next;
            } else {
                prev->next = current->next;
            }
            delete current; // Free the node memory
            numberOfItems--; // Decrease item count
            return true; // Successfully removed
        }
        prev = current;
        current = current->next;
    }
    return false; // Key not found
}

// GetItem method
HashNode* HashTable::getItem(int key) {
    int index = hashFunction(key);
    HashNode* current = table[index];

    while (current != nullptr) {
        if (current->key == key) {
            return current; // Key found, return the node
        }
        current = current->next;
    }
    return nullptr; // Key not found
}
