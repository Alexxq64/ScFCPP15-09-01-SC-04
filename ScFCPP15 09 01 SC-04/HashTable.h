#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class HashTable {
private:
    pair<string, string>* table; // array of key-value pairs
    int memSize; // size of the hash table
    int count; // number of elements in the hash table

    int hashFunc(string key); // hash function using multiplication method
    int quadraticProbing(int index, int i); // quadratic probing collision resolution method
public:
    HashTable(int size); // constructor with table size parameter
    ~HashTable(); // destructor

    void add(string key, string value); // add a key-value pair into the hash table
    string find(string key); // find for a value based on a key
    void del(string key); // del a key-value pair from the hash table
};