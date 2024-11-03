/**
* @file HashTable.hpp
 * @brief Header file for HashTable implementation
 * @author [Your Name]
 * @date [Current Date]
 */

#ifndef _HASH_TABLE
#define _HASH_TABLE
#define _HASH_TABLE_SIZE 101

#include <string>
#include <vector>

// Define a structure for a node in the hash table
struct HashNode {
 int key;
 std::string fullName;
 std::string address;
 std::string city;
 std::string state;
 std::string zip;

 HashNode* prev;
 HashNode* next;

 // Constructor
 HashNode(int val, std::string myFullName, std::string myAddress,
          std::string myCity, std::string myState, std::string myZip) :
     key(val), fullName(myFullName), address(myAddress), city(myCity),
     state(myState), zip(myZip), prev(nullptr), next(nullptr) {}
};

class HashTable {
private:
 HashNode** table;
 int numberOfItems;

 /**
  * @brief Hash function to calculate index
  * @param key The integer key to hash
  * @return The calculated table index
  */
 int hashFunction(int key) const;

public:
 /**
  * @brief Default constructor
  */
 HashTable();

 /**
  * @brief Destructor
  */
 ~HashTable();

 // Core methods
 HashNode** getTable();
 int getSize();
 bool isEmpty();
 int getNumberOfItems();
 bool add(int key, HashNode* newNode);
 bool remove(int key);
 void clear();
 HashNode* getItem(int key);
 bool contains(int key);
};

#endif