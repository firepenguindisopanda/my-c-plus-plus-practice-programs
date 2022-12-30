#ifndef _HASHTABLE_H
#define _HASHTABLE_H
#include <iostream>
#include "DataTypes.h"
#define MAX_ELEMENTS 1000
#define EMPTY ""
using namespace std;

struct HashTable {
    Condition elements [MAX_ELEMENTS];
    int tableSize;
};
HashTable * initHashTable(int tableSize);
void insertHashTable(HashTable * hashTable, Condition condition, int tableSize);
int containsHashTable(HashTable * hashTable, string key, int tableSize);

#endif