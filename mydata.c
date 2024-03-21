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
typedef struct {
    KeyValuePair* table[TABLE_SIZE];
} HashTable;

// Hash function
int hash(char* key) {
    int hash = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        hash += key[i];
    }
    return hash % TABLE_SIZE;
}

// Initialize the hash table
void initHashTable(HashTable* ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht->table[i] = NULL;
    }
}

// Insert or update a key-value pair into the hash table
void insertOrUpdate(HashTable* ht, char* key, int value) {
    int index = hash(key);
    
    // Check if the key already exists
    KeyValuePair* current = ht->table[index];
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            // Key exists, update value
            current->value = value;
            return;
        }
        current = current->next;
    }
    
    // Key does not exist, insert new key-value pair
    KeyValuePair* new_pair = (KeyValuePair*)malloc(sizeof(KeyValuePair));
    new_pair->key = strdup(key);
    new_pair->value = value;
    new_pair->next = ht->table[index];
    ht->table[index] = new_pair;
}

// Retrieve the value associated with a key
int get(HashTable* ht, char* key) {
    int index = hash(key);
    KeyValuePair* current = ht->table[index];
    
    // Search for the key in the hash table
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }
    
    return -1; // Key not found
}
