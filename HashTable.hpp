/**
* @file HashTable.hpp
 * @brief Header file for HashTable implementation using separate chaining
* @authors Muzaffarbek Muratov,Rishika Bharodiya, Arpan Rakeshbhai Savani
 * @date 11/02/2024
 */
#ifndef HASH_TABLE_HPP
#define HASH_TABLE_HPP

#include <string>

class HashTable {
private:
    // Hash table size (prime number for better distribution)
    static const int TABLE_SIZE = 101;

    /**
     * @brief Node structure for separate chaining
     */
    struct Node {
        std::string key;
        Node* next;
        Node(const std::string& k) : key(k), next(nullptr) {}
    };

    Node** table;    // Array of pointers to nodes
    int size;        // Current number of elements in table

    /**
     * @brief Hash function to calculate index for a given key
     * @param key The key to hash
     * @return The calculated hash index
     */
    int hashFunction(const std::string& key);

public:
    /**
     * @brief Constructor - Initializes empty hash table
     */
    HashTable();

    /**
     * @brief Destructor - Cleans up all allocated memory
     */
    ~HashTable();

    // Disable copy constructor and assignment operator
    HashTable(const HashTable&) = delete;
    HashTable& operator=(const HashTable&) = delete;

    bool add(std::string key);
    bool remove(std::string key);
    bool contains(std::string key);
    void clear();
    bool isEmpty();
    int getSize();
    std::string* getTable();
};

#endif // HASH_TABLE_HPP