#ifndef _HASH_TABLE
#define _HASH_TABLE

#include <string>

// Define a structure for a node in the hash table
struct HashNode {
    int key;
    std::string fullName;
    std::string address;
    std::string city;
    std::string state;
    std::string zip;
    HashNode* prev; // Not used in this implementation
    HashNode* next;

    // Constructor
    HashNode(int val, const std::string& myFullName, const std::string& myAddress,
             const std::string& myCity, const std::string& myState, const std::string& myZip) :
        key(val), fullName(myFullName), address(myAddress), city(myCity),
        state(myState), zip(myZip), prev(nullptr), next(nullptr) {}
};

class HashTable {
private:
    HashNode** table;        // Pointer to the hash table array
    int numberOfItems;      // Number of items currently in the hash table

    // Hash function to calculate index
    int hashFunction(int key) const;

public:
    static const int HASH_TABLE_SIZE = 101;  // Use static constant for table size

    // Constructor and Destructor
    HashTable();
    ~HashTable();

    // Core methods
    HashNode** getTable();                       // Access the underlying table
    int getSize() const;                         // Get the size of the hash table
    bool isEmpty() const;                        // Check if the hash table is empty
    int getNumberOfItems() const;                // Get the number of items in the hash table
    bool add(int key, HashNode* newNode);       // Add a new node
    bool remove(int key);                        // Remove a node by key
    void clear();                                // Clear the hash table
    HashNode* getItem(int key);                  // Get an item by key
    bool contains(int key) const;                // Check if the key exists
};

#endif
