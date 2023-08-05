#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 10
struct HashNode {
    int key;
    int value;
};
struct HashTable {
    struct HashNode** table;
};
struct HashTable* createHashTable() {
    struct HashTable* hashTable = (struct HashTable*)malloc(sizeof(struct HashTable));
    hashTable->table = (struct HashNode**)malloc(TABLE_SIZE * sizeof(struct HashNode*));

    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable->table[i] = NULL;
    }
    return hashTable;
}
int hash(int key) {
    return key % TABLE_SIZE;
}
void insert(struct HashTable* hashTable, int key, int value) {
    int index = hash(key);
    int i = 0;

    while (hashTable->table[index] != NULL) {
        index = (index + i) % TABLE_SIZE;
        i++;
    }
    struct HashNode* newNode = (struct HashNode*)malloc(sizeof(struct HashNode));
    newNode->key = key;
    newNode->value = value;
    hashTable->table[index] = newNode;
}
int search(struct HashTable* hashTable, int key) {
    int index = hash(key);
    int i = 0;

    while (hashTable->table[index] != NULL) {
        if (hashTable->table[index]->key == key) {
            return hashTable->table[index]->value;
        }
        index = (index + i) % TABLE_SIZE;
        i++;
    }
    return -1;
}
void display(struct HashTable* hashTable) {
    printf("Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable->table[i] != NULL) {
            printf("%d -> %d\n", hashTable->table[i]->key, hashTable->table[i]->value);
        }
    }
}
int main() {
    struct HashTable* hashTable = createHashTable();
    insert(hashTable, 5, 25);
    insert(hashTable, 12, 144);
    insert(hashTable, 4, 16);
    display(hashTable);
    int keyToSearch = 12;
    int value = search(hashTable, keyToSearch);
    if (value != -1) {
        printf("Value for key %d: %d\n", keyToSearch, value);
    } else {
        printf("Key %d not found.\n", keyToSearch);
    }
    return 0;
}
