
#include <gtest/gtest.h>
#include "HashTable.hpp"  // Updated path to match structure

class HashTableTest : public ::testing::Test {
protected:
    HashTable* table;

    void SetUp() override {
        table = new HashTable();
    }

    void TearDown() override {
        delete table;
    }
};

// Basic Operations Tests
TEST_F(HashTableTest, InitialState) {
    EXPECT_TRUE(table->isEmpty());
    EXPECT_EQ(table->getNumberOfItems(), 0);
    EXPECT_EQ(table->getSize(), 101);  // Test table size
}

// Add Operation Tests
TEST_F(HashTableTest, AddOperations) {
    HashNode* node1 = new HashNode(20, "John Doe", "1234 Test St", "TestCity", "TS", "12345");
    EXPECT_TRUE(table->add(20, node1));
    EXPECT_EQ(table->getNumberOfItems(), 1);
    EXPECT_FALSE(table->isEmpty());
}

// Collision Handling Tests
TEST_F(HashTableTest, CollisionHandling) {
    // These keys will have same hash (101 % 101 = 0, 202 % 101 = 0)
    HashNode* node1 = new HashNode(101, "Test1", "Address1", "City1", "ST1", "11111");
    HashNode* node2 = new HashNode(202, "Test2", "Address2", "City2", "ST2", "22222");

    EXPECT_TRUE(table->add(101, node1));
    EXPECT_TRUE(table->add(202, node2));
    EXPECT_EQ(table->getNumberOfItems(), 2);
    EXPECT_TRUE(table->contains(101));
    EXPECT_TRUE(table->contains(202));
}

// Remove Operation Tests
TEST_F(HashTableTest, RemoveOperations) {
    HashNode* node = new HashNode(30, "Test", "Address", "City", "ST", "12345");
    table->add(30, node);
    EXPECT_TRUE(table->remove(30));
    EXPECT_FALSE(table->contains(30));
    EXPECT_TRUE(table->isEmpty());
}

// Clear Operation Test
TEST_F(HashTableTest, ClearOperation) {
    HashNode* node1 = new HashNode(40, "Test1", "Address1", "City1", "ST1", "11111");
    HashNode* node2 = new HashNode(50, "Test2", "Address2", "City2", "ST2", "22222");

    table->add(40, node1);
    table->add(50, node2);
    EXPECT_EQ(table->getNumberOfItems(), 2);

    table->clear();
    EXPECT_TRUE(table->isEmpty());
    EXPECT_EQ(table->getNumberOfItems(), 0);
}

// Edge Cases Tests
TEST_F(HashTableTest, EdgeCases) {
    // Test with maximum integer
    HashNode* node1 = new HashNode(INT_MAX, "Max", "Address", "City", "ST", "12345");
    EXPECT_TRUE(table->add(INT_MAX, node1));

    // Test with negative key
    HashNode* node2 = new HashNode(-1, "Negative", "Address", "City", "ST", "12345");
    EXPECT_TRUE(table->add(-1, node2));

    // Test remove non-existent key
    EXPECT_FALSE(table->remove(999));

    // Test contains non-existent key
    EXPECT_FALSE(table->contains(999));
}