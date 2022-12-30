#include <iostream>
#include <stdlib.h>
#include <cstring>
#include "DataTypes.h"
#include "HashTable.h"
using namespace std;

HashTable * initHashTable(int tableSize) {
    HashTable * hashTable = new HashTable;
    hashTable->tableSize = tableSize;
    for (int i = 0; i < tableSize; i++) {
        hashTable->elements[i].name = EMPTY;
        hashTable->elements[i].priority = 0;
    }
    return hashTable;
}