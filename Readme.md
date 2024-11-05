# Hash Table Implementation - Milestone 3

## @Authors: 
- Muzaffarbek Muratov
- Rishika Bharodiya
- Arpan Rakeshbhai Savani

# Overview
A C++ implementation of a hash table with unit tests using Google Test. This project supports basic hash table operations, collision handling, and JSON-based test case processing.

### The project includes:

1. **HashTable.hpp** and **HashTable.cpp**: Implementation of the hash table.
2. **HashTableTest.cpp**: Unit tests using Google Test.
3. **milestone3.cpp**: A program that reads and processes JSON test cases.

### Features
1. **Basic Hash Table Operations**: add, remove, getItem, contains, clear, isEmpty, getNumberOfItems.
2. **Collision Handling**: Uses separate chaining with doubly linked lists.
3. **Unit Testing**: Comprehensive tests using Google Test.
4. **JSON Processing:** Reads and processes test cases from JSON files.

### Project Structure:
``` HashTableProject/
├── HashTable.hpp
├── HashTable.cpp
├── HashTableTest.cpp
├── milestone3.cpp
├── json.hpp
├── milestone3.json
├── additional_tests.json
└── README.md
└── CMakeLists.txt
```

```
HashTable.hpp: Header file for the HashTable class.

HashTable.cpp: Implementation of the HashTable class.

HashTableTest.cpp: Unit tests for the HashTable class using Google Test.

milestone3.cpp: Program that processes JSON test cases.

json.hpp: Single-header JSON library by nlohmann.

milestone3.json and additional_tests.json: JSON files containing test cases.

README.md: This documentation file. 

```

### Dependencies
1. C++17 or higher: The project uses C++17 features.
2. Google Test (gtest): For running unit tests.
3. nlohmann/json: json.hpp




### Compiling the HashTable Library
First, compile the HashTable.cpp file into an object file:
``` g++ -std=c++17 -c HashTable.cpp ```

This command generates HashTable.o, which will be used in subsequent compilations.


### Compiling and Running milestone3:
Place `json.hpp` in the same directory as your source files or specify the include path during compilation.

### Compile the Executable
``` g++ -std=c++17 milestone3.cpp HashTable.o -o milestone3 -I. ```

### Run the Program
```./milestone3 ```

------------

### Compiling and Running the Tests
1. Install Google Test

### Linux:
```
sudo apt-get install libgtest-dev
sudo apt-get install cmake  # Required to build Google Test
cd /usr/src/gtest
sudo cmake CMakeLists.txt
sudo make
sudo cp *.a /usr/lib

```

### macOS (using Homebrew):
```
brew install googletest

```

### Windows:

``` Download Google Test from GitHub.
Build the library using CMake or include the source files directly in your project.
```

### Compile the Test Executable
``` Replace <gtest_include_path> and <gtest_lib_path> with the actual paths on your system. ```

### Linux:
``` 
g++ -std=c++17 HashTableTest.cpp HashTable.cpp -o HashTableTest \
    -pthread -lgtest -lgtest_main 
```
**On Linux systems, if Google Test is installed in standard locations, you might not need to specify include and library paths.**


### macOS:

```
g++ -std=c++17 HashTableTest.cpp HashTable.cpp -o HashTableTest \
    -I/usr/local/opt/googletest/include \
    -L/usr/local/opt/googletest/lib \
    -lgtest -lgtest_main -pthread

```

**Adjust paths if Google Test is installed elsewhere, e.g., /opt/homebrew/opt/googletest for Apple Silicon Macs.**

### Windows:

```
g++ -std=c++17 HashTableTest.cpp HashTable.cpp -o HashTableTest \
    -I<path_to_gtest_include> \
    -L<path_to_gtest_lib> \
    -lgtest -lgtest_main -pthread

```
**Ensure that the MinGW or equivalent g++ compiler is properly configured with access to the Google Test libraries.**

## Run the Tests
``` ./HashTableTest  ```
On Windows, run HashTableTest.exe





