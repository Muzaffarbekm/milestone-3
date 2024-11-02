/**
 * @file HashTable.cpp
 * @brief Implementation of HashTable methods
 * @authors Muzaffarbek Muratov,Rishika Bharodiya, Arpan Rakeshbhai Savani
 * @date 11/02/2024
 */

#include "HashTable.hpp"
#include <stdexcept>

HashTable::HashTable() : size(0) {
    try {
        // Allocate array of Node pointers
        table = new Node*[TABLE_SIZE];

        // Initialize all table entries to nullptr
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = nullptr;
        }
    } catch (const std::bad_alloc& e) {
        // Handle memory allocation failure
        throw std::runtime_error("Failed to allocate memory for hash table");
    }
}

HashTable::~HashTable() {
    // Clean up all nodes
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* current = table[i];
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    // Delete the array of pointers
    delete[] table;
    table = nullptr;  // Good practice to nullptr deleted pointers
}

int HashTable::hashFunction(const std::string& key) {
    unsigned long hash = 5381;  // Initial hash value (DJB2 algorithm)

    // Calculate hash value
    for (char c : key) {
        hash = ((hash << 5) + hash) + c;  // hash * 33 + c
    }

    // Ensure hash is within table bounds
    return hash % TABLE_SIZE;
}

std::string* HashTable::getTable() {
    // Required for testing - returns pointer to the table
    return reinterpret_cast<std::string*>(table);
}

// Added these basic implementations for testing
bool HashTable::isEmpty() {
    return size == 0;
}

int HashTable::getSize() {
    return size;
}

// Add stubs for other required methods (they'll be implemented by team members)
bool HashTable::add(std::string key) {
    // This will be implemented by Person 2
    return false;
}

bool HashTable::contains(std::string key) {
    // This will be implemented by Person 2
    return false;
}

bool HashTable::remove(std::string key) {
    // This will be implemented by Person 3
    return false;
}

void HashTable::clear() {
    // This will be implemented by Person 3
}