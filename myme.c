#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mydata.h"  // Include the header to access declarations
#define TABLE_SIZE 1000



int main() {
  HashTable myHashTable;
  initHashTable(&myHashTable);

  // Insert key-value pairs
  insertOrUpdate(&myHashTable, "apple", 40);
  insertOrUpdate(&myHashTable, "banana", 66);


  // Retrieve values
  int appleValue = get(&myHashTable, "apple");
  int bananaValue = get(&myHashTable, "banana");



  printf("apple value: %d\n", appleValue);
  printf("banana value: %d\n", bananaValue);
  return 0;
}
