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

int hashCode(int tableSize, string key){
    int hash {}, x {0}, ascii {};
    int ht_length = key.length();
    for(x = 0; x < ht_length; x++){
        ascii = (int)key[x];
        hash = hash + (ascii * x);
        //hash = (hash << 5) + hash + ascii;
    }
    return hash;
    
}

/**
 * @brief Determines if the hash table contains the given key
 * 
 * @param hashTable 
 * @param key 
 * @param tableSize 
 * @return int 
 */
int containsHashTable(HashTable * hashTable, string key, int tableSize){
    int hash = hashCode(tableSize, key);
    int i {}, d {}, original {};
    i = hash % tableSize;
    if(hashTable->elements[i].name == key){
        return hashTable->elements[i].priority;
    }
    original = i;
    d = hash % (tableSize / 2);
    i = i + d;

    while(i != original){
        if(hashTable->elements[i].name == key){
            return hashTable->elements[i].priority;
        }
        i = i + d;
    }
    return -1;
    
}

void insertHashTable(HashTable * hashTable, Condition condition, int tableSize){
    int location {}, hash {}, k {};
    hash = hashCode(tableSize, condition.name);
    location = hash % tableSize;
    if(hashTable->elements[location].priority == 0){
        hashTable->elements[location].name = condition.name;
        hashTable->elements[location].priority = condition.priority;
    }else{
        k = hash % (tableSize / 2);
        location = location + k;
        while(hashTable->elements[location].priority != 0){
            location = location + k;
        }
        hashTable->elements[location].name = condition.name;
        hashTable->elements[location].priority = condition.priority;
    }
}