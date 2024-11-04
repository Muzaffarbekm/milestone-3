#include <iostream>
#include "HashTable.hpp"

int main() {
    // Create a HashTable instance
    HashTable hashTable;

    // Create some HashNode objects
    HashNode* node1 = new HashNode(1, "Joy Doe", "123 Elm St", "Springfield", "IL", "62701");
    HashNode* node2 = new HashNode(2, "Josh Smith", "496 Geneva St", "Springfield", "IL", "62702");

    // Add nodes to the hash table
    if (hashTable.add(node1->key, node1)) {
        std::cout << "Added node with key " << node1->key << std::endl;
    } else {
        std::cout << "Failed to add node with key " << node1->key << std::endl;
    }

    if (hashTable.add(node2->key, node2)) {
        std::cout << "Added node with key " << node2->key << std::endl;
    } else {
        std::cout << "Failed to add node with key " << node2->key << std::endl;
    }

    // Test if the nodes are in the hash table
    if (hashTable.contains(1)) {
        std::cout << "Node with key 1 found." << std::endl;
    } else {
        std::cout << "Node with key 1 not found." << std::endl;
    }

    if (hashTable.contains(2)) {
        std::cout << "Node with key 2 found." << std::endl;
    } else {
        std::cout << "Node with key 2 not found." << std::endl;
    }

    // Test removing nodes
    if (hashTable.remove(1)) {
        std::cout << "Removed node with key 1." << std::endl;
        delete node1; // Free allocated memory only after confirming removal
    } else {
        std::cout << "Failed to remove node with key 1." << std::endl;
    }

    if (hashTable.remove(2)) {
        std::cout << "Removed node with key 2." << std::endl;
        delete node2; // Free allocated memory only after confirming removal
    } else {
        std::cout << "Failed to remove node with key 2." << std::endl;
    }

    // Test if nodes are removed
    if (!hashTable.contains(1)) {
        std::cout << "Node with key 1 not found after removal." << std::endl;
    }

    if (!hashTable.contains(2)) {
        std::cout << "Node with key 2 not found after removal." << std::endl;
    }

    // You can add more tests for robustness
    // For example, trying to add duplicate keys:
    if (!hashTable.add(node1->key, node1)) {
        std::cout << "Duplicate key " << node1->key << " not added." << std::endl;
    }

    // Optionally, delete hashTable if implemented in HashTable destructor
    return 0;
}
