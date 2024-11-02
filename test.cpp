#include <iostream>
#include "HashTable.hpp"

void testFoundation() {
    std::cout << "\n=== Testing HashTable Foundation ===\n";

    // Test 1: Constructor
    std::cout << "Test 1: Creating HashTable..." << std::endl;
    try {
        HashTable ht;
        std::cout << "✓ HashTable created successfully\n";

        // Test 2: Initial state
        std::cout << "\nTest 2: Checking initial state..." << std::endl;
        if (ht.isEmpty()) {
            std::cout << "✓ Table is empty\n";
        } else {
            std::cout << "✗ Table should be empty\n";
        }

        if (ht.getSize() == 0) {
            std::cout << "✓ Size is 0\n";
        } else {
            std::cout << "✗ Size should be 0\n";
        }

        // Test 3: getTable
        std::cout << "\nTest 3: Checking getTable..." << std::endl;
        if (ht.getTable() != nullptr) {
            std::cout << "✓ getTable returns non-null pointer\n";
        } else {
            std::cout << "✗ getTable returns null pointer\n";
        }

    } catch (const std::exception& e) {
        std::cout << "✗ Error: " << e.what() << std::endl;
    }
}

int main() {
    testFoundation();
    return 0;
}