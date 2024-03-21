// mydata.
#ifndef MYDATA_H
#define MYDATA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 1000

// Define a structure for the key-value pair
typedef struct KeyValuePair {
  char* key;
  int value;
  struct KeyValuePair* next;
} KeyValuePair;

// Define the hash table structure
typedef struct HashTable {
  KeyValuePair* table[TABLE_SIZE];
} HashTable;

// Function prototypes (declare without implementation)
int hash(char* key);
void initHashTable(HashTable* ht);
void insertOrUpdate(HashTable* ht, char* key, int value);
int get(HashTable* ht, char* key);

#endif