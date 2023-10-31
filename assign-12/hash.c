#include <stdio.h>
#include <stdlib.h>

// Structure to represent key-value pairs
typedef struct KeyValue
{
  int key;
  int value;
} KeyValue;

// Structure to represent a hash table
typedef struct HashTable
{
  KeyValue *table;
  int size;
  int count; // To keep track of the number of items
} HashTable;

// Hash function to map keys to indices
int hash(int key, int size)
{
  return key % size;
}

// Initialize the hash table
HashTable *initialize(int size)
{
  HashTable *hashTable = (HashTable *)malloc(sizeof(HashTable));
  hashTable->size = size;
  hashTable->count = 0;
  hashTable->table = (KeyValue *)malloc(sizeof(KeyValue) * size);

  for (int i = 0; i < size; i++)
  {
    hashTable->table[i].key = -1; // Initialize keys to -1 to indicate empty slots
  }

  return hashTable;
}

// Insert a key-value pair into the hash table
void insert(HashTable *hashTable, int key, int value)
{
  int index = hash(key, hashTable->size);

  while (hashTable->table[index].key != -1)
  {
    // Linear probing: move to the next slot if the current one is occupied
    index = (index + 1) % hashTable->size;
  }

  hashTable->table[index].key = key;
  hashTable->table[index].value = value;
  hashTable->count++;
}

// Remove an item from the hash table
void removeItem(HashTable *hashTable, int key)
{
  int index = hash(key, hashTable->size);

  while (hashTable->table[index].key != key)
  {
    if (hashTable->table[index].key == -1)
    {
      // Key not found
      printf("Key %d not found in the hashtable.\n", key);
      return;
    }
    // Linear probing: move to the next slot
    index = (index + 1) % hashTable->size;
  }

  // Mark the slot as empty
  hashTable->table[index].key = -1;
  hashTable->count--;
  printf("Key %d removed from the hashtable.\n", key);
}

// Check the size of the hash table
int getSize(HashTable *hashTable)
{
  return hashTable->count;
}

// Display the hash table
void display(HashTable *hashTable)
{
  printf("Hashtable Contents:\n");
  for (int i = 0; i < hashTable->size; i++)
  {
    if (hashTable->table[i].key != -1)
    {
      printf("Key: %d, Value: %d\n", hashTable->table[i].key, hashTable->table[i].value);
    }
  }
}

int main()
{
  int dynamicSize;
  printf("Enter the size of hash table: ");
  scanf("%d", &dynamicSize);

  HashTable *hashTable = initialize(dynamicSize);
  int choice;
  int key, value;

  while (1)
  {
    printf("\nMENU:\n");
    printf("1. Insert item in the Hashtable\n");
    printf("2. Remove item from the Hashtable\n");
    printf("3. Check the size of Hashtable\n");
    printf("4. Display Hashtable\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("Enter key and value to insert: ");
      scanf("%d %d", &key, &value);
      insert(hashTable, key, value);
      printf("Item inserted successfully.\n");
      break;
    case 2:
      printf("Enter key to remove: ");
      scanf("%d", &key);
      removeItem(hashTable, key);
      printf("Item removed successfully.\n");
      break;
    case 3:
      printf("Size of Hashtable: %d\n", getSize(hashTable));
      break;
    case 4:
      display(hashTable);
      break;
    case 5:
      free(hashTable->table);
      free(hashTable);
      exit(0);
    default:
      printf("Invalid choice. Please try again.\n");
    }
  }

  return 0;
}
