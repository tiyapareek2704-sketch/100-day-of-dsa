#include <stdio.h>
#define SIZE 10



int hashTable[SIZE];

// Hash function
int hashFunction(int key) {
    int last3 = key % 1000;
    return last3 % SIZE;
}

// Initialize table
void init() {
    for(int i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}

// Insert with Linear Probing
void insert(int key) {
    int index = hashFunction(key);
    int startIndex = index;

    while(hashTable[index] != -1) {
        index = (index + 1) % SIZE;

        // Table full condition
        if(index == startIndex) {
            printf("Hash Table is FULL! Cannot insert %d\n", key);
            return;
        }
    }

    hashTable[index] = key;
    printf("Inserted %d at index %d\n", key, index);
}

// Delete operation
void deleteKey(int key) {
    int index = hashFunction(key);
    int startIndex = index;

    while(hashTable[index] != -1) {
        if(hashTable[index] == key) {
            hashTable[index] = -1;
            printf("Deleted %d\n", key);
            return;
        }

        index = (index + 1) % SIZE;

        if(index == startIndex)
            break;
    }

    printf("Element not found\n");
}

// Search operation
void search(int key) {
    int index = hashFunction(key);
    int startIndex = index;

    while(hashTable[index] != -1) {
        if(hashTable[index] == key) {
            printf("Found %d at index %d\n", key, index);
            return;
        }

        index = (index + 1) % SIZE;

        if(index == startIndex)
            break;
    }

    printf("Element not found\n");
}

// Display table
void display() {
    printf("\nHash Table:\n");
    for(int i = 0; i < SIZE; i++) {
        if(hashTable[i] == -1)
            printf("%d --> EMPTY\n", i);
        else
            printf("%d --> %d\n", i, hashTable[i]);
    }
}

int main() {
    int choice, key;
    init();

    while(1) {
        printf("\n1.Insert\n2.Delete\n3.Search\n4.Display\n5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter SAP-ID: ");
                scanf("%d", &key);
                insert(key);
                break;
            case 2:
                printf("Enter SAP-ID: ");
                scanf("%d", &key);
                deleteKey(key);
                break;
            case 3:
                printf("Enter SAP-ID: ");
                scanf("%d", &key);
                search(key);
                break;
            case 4:
                display();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}