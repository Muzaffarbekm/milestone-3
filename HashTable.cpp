
#include <string>
#include <vector>
#include <stdexcept>  // for error handling
#include "HashTable.hpp"

// Sets up an empty hash table with all nullptr entries
HashTable::HashTable() : numberOfItems(0) {
    try {
        table = new HashNode*[_HASH_TABLE_SIZE];
        for (int i = 0; i < _HASH_TABLE_SIZE; i++) {
            table[i] = nullptr;
        }
    } catch (const std::bad_alloc& e) {
        // Handle memory allocation failure
        throw std::runtime_error("Failed to initialize hash table: Out of memory");
    }
}

// Gets the table array - needed for printing contents
HashNode** HashTable::getTable() {
    if (!table) {
        throw std::runtime_error("Hash table not properly initialized");
    }
    return table;
}

// Returns the size of our hash table
int HashTable::getSize() {
    return _HASH_TABLE_SIZE;
}

// Checks if table has any items in it
bool HashTable::isEmpty() {
    return numberOfItems == 0;
}

// Returns how many items we've added to the table
int HashTable::getNumberOfItems() {
    return numberOfItems;
}

// Basic hash function - maps key to table index
int hashFunction(int key) {
    // Handle negative keys by making them positive
    if (key < 0) {
        key = -key;
    }
    return key % _HASH_TABLE_SIZE;
}

// Adds a new item to the hash table
bool HashTable::add(int key, HashNode* newNode) {
    // Error checking
    if (!table) {
        throw std::runtime_error("Hash table not properly initialized");
    }
    if (!newNode) {
        throw std::invalid_argument("Cannot add null node to hash table");
    }

    // Verify the key matches the node's key
    if (key != newNode->key) {
        throw std::invalid_argument("Key mismatch in add operation");
    }

    // Don't add if key already exists
    if (contains(key)) {
        return false;
    }

    try {
        // Calculate hash index
        int index = hashFunction(key);

        // Handle collision by adding to front of chain
        if (table[index]) {
            newNode->next = table[index];
            table[index]->prev = newNode;
        }

        table[index] = newNode;
        numberOfItems++;
        return true;

    } catch (const std::exception& e) {
        throw std::runtime_error("Failed to add node: " + std::string(e.what()));
    }
}

// Removes an item with the given key
bool HashTable::remove(int key) {
    if (!table) {
        throw std::runtime_error("Hash table not properly initialized");
    }

    try {
        int index = hashFunction(key);
        HashNode* current = table[index];

        while (current) {
            if (current->key == key) {
                // Update head of chain if needed
                if (current == table[index]) {
                    table[index] = current->next;
                }

                // Update links
                if (current->prev) {
                    current->prev->next = current->next;
                }
                if (current->next) {
                    current->next->prev = current->prev;
                }

                delete current;
                numberOfItems--;
                return true;
            }
            current = current->next;
        }
        return false;

    } catch (const std::exception& e) {
        throw std::runtime_error("Failed to remove node: " + std::string(e.what()));
    }
}

// Removes all items from the table
void HashTable::clear() {
    if (!table) {
        throw std::runtime_error("Hash table not properly initialized");
    }

    try {
        for (int i = 0; i < _HASH_TABLE_SIZE; i++) {
            while (table[i]) {
                HashNode* temp = table[i];
                table[i] = table[i]->next;
                delete temp;
            }
        }
        numberOfItems = 0;
    } catch (const std::exception& e) {
        throw std::runtime_error("Failed to clear table: " + std::string(e.what()));
    }
}

// Gets the item with the given key
HashNode* HashTable::getItem(int key) {
    if (!table) {
        throw std::runtime_error("Hash table not properly initialized");
    }

    try {
        int index = hashFunction(key);
        HashNode* current = table[index];

        while (current) {
            if (current->key == key) {
                return current;
            }
            current = current->next;
        }
        return nullptr;

    } catch (const std::exception& e) {
        throw std::runtime_error("Failed to get item: " + std::string(e.what()));
    }
}

// Checks if an item with the given key exists
bool HashTable::contains(int key) {
    try {
        return getItem(key) != nullptr;
    } catch (const std::exception& e) {
        throw std::runtime_error("Failed to check containment: " + std::string(e.what()));
    }
}