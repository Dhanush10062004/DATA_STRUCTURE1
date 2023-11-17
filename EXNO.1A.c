#include <stdio.h>
#include <stdlib.h>
#include<conio.h>

#define SIZE 100

// Structure for representing a node in separate chaining
struct Node {
    int key;
    struct Node* next;
};

// Hashing function rskjJGkvfh
int hashFunction(int key, int tableSize) {
    return key % tableSize;
}

// Separate Chaining Collision Resolution
void separateChaining(int keys[], int n, int tableSize) {
    struct Node* hashTable[tableSize];

    // Initialize the hash table with NULL
    for (int i = 0; i < tableSize; i++) {
        hashTable[i] = NULL;
    }

    // Insert keys into the hash table using separate chaining
    for (int i = 0; i < n; i++) {
        int index = hashFunction(keys[i], tableSize);

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->key = keys[i];
        newNode->next = NULL;

        if (hashTable[index] == NULL) {
            hashTable[index] = newNode;
        } else {
            newNode->next = hashTable[index];
            hashTable[index] = newNode;
        }
    }

    // Display the hash table with separate chaining
    printf("\nHash Table with Separate Chaining:\n");
    for (int i = 0; i < tableSize; i++) {
        printf("%d: ", i);

        struct Node* current = hashTable[i];
        while (current != NULL) {
            printf("%d -> ", current->key);
            current = current->next;
        }

        printf("NULL\n");
    }
}

// Linear Probing Collision Resolution
void linearProbing(int keys[], int n, int tableSize) {
    int hashTable[tableSize];

    // Initialize the hash table with -1
    for (int i = 0; i < tableSize; i++) {
        hashTable[i] = -1;
    }

    // Insert keys into the hash table using linear probing
    for (int i = 0; i < n; i++) {
        int index = hashFunction(keys[i], tableSize);

        while (hashTable[index] != -1) {
            index = (index + 1) % tableSize;
        }

        hashTable[index] = keys[i];
    }

    // Display the hash table with linear probing
    printf("\nHash Table with Linear Probing:\n");
    for (int i = 0; i < tableSize; i++) {
        printf("%d: %d\n", i, hashTable[i]);
    }
}

// Quadratic Probing Collision Resolution
void quadraticProbing(int keys[], int n, int tableSize) {
    int hashTable[tableSize];

    // Initialize the hash table with -1
    for (int i = 0; i < tableSize; i++) {
        hashTable[i] = -1;
    }

    // Insert keys into the hash table using quadratic probing
    for (int i = 0; i < n; i++) {
        int index = hashFunction(keys[i], tableSize);
        int quadraticStep = 1;

        while (hashTable[index] != -1) {
            index = (index + quadraticStep * quadraticStep) % tableSize;
            quadraticStep++;
        }

        hashTable[index] = keys[i];
    }

    // Display the hash table with quadratic probing
    printf("\nHash Table with Quadratic Probing:\n");
    for (int i = 0; i < tableSize; i++) {
        printf("%d: %d\n", i, hashTable[i]);
    }
}

// Double Hashing Collision Resolution
void doubleHashing(int keys[], int n, int tableSize) {
    int hashTable[tableSize];

    // Initialize the hash table with -1
    for (int i = 0; i < tableSize; i++) {
        hashTable[i] = -1;
    }

    // Define a second hash function
    int secondHashFunction(int key) {
        return 7 - (key % 7);
    }

    // Insert keys into the hash table using double hashing
    for (int i = 0; i < n; i++) {
        int index = hashFunction(keys[i], tableSize);
        int stepSize = secondHashFunction(keys[i]);

        while (hashTable[index] != -1) {
            index = (index + stepSize) % tableSize;
        }

        hashTable[index] = keys[i];
    }

    // Display the hash table with double hashing
    printf("\nHash Table with Double Hashing:\n");
    for (int i = 0; i < tableSize; i++) {
        printf("%d: %d\n", i, hashTable[i]);
    }
int main() {
    int n;

    // Input the size of the hash table
    printf("Enter the size of the hash table: ");
    scanf("%d", &n);

    int keys[n];

    // Input array elements to be inserted into the hash table
    printf("Enter %d elements to be inserted into the hash table:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &keys[i]);
    }

    // Choose the collision resolution technique
    int choice;
    printf("\nChoose the collision resolution technique:\n");
    printf("1. Separate Chaining\n");
    printf("2. Linear Probing\n");
    printf("3. Quadratic Probing\n");
    printf("4. Double Hashing\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            separateChaining(keys, n, SIZE);
            break;
        case 2:
            linearProbing(keys, n, SIZE);
            break;
        case 3:
            quadraticProbing(keys, n, SIZE);
            break;
        case 4:
            doubleHashing(keys, n, SIZE);
            break;
        default:
            printf("Invalid choice.\n");
            return 1; // Return an error code
    }

    return 0;
}