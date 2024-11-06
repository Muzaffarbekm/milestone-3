cmake_minimum_required(VERSION 3.10)
project(HashTableProject)

set(CMAKE_CXX_STANDARD 17)

# Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Find Threads package
find_package(Threads REQUIRED)

# Add HashTable library
add_library(HashTableLib HashTable.cpp)

# Executable for milestone3
add_executable(milestone3 milestone3.cpp)
target_link_libraries(milestone3 HashTableLib)

# Unit Tests
enable_testing()
find_package(GTest REQUIRED)

if(GTEST_FOUND)
    include_directories(${GTEST_INCLUDE_DIRS})
    add_executable(HashTableTest HashTableTest.cpp)
    target_link_libraries(HashTableTest HashTableLib ${GTEST_LIBRARIES} Threads::Threads)
    add_test(NAME HashTableTest COMMAND HashTableTest)
else()
    message(WARNING "Google Test not found! Unit tests will not be built.")
endif()
