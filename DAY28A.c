#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Insert into circular linked list
struct Node* insert(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    // If list is empty
    if (head == NULL) {
        newNode->next = newNode; // points to itself
        return newNode;
    }

    struct Node* temp = head;

    // Traverse to last node
    while (temp->next != head) {
        temp = temp->next;
    }

    // Insert at end
    temp->next = newNode;
    newNode->next = head;

    return head;
}

// Traverse circular list
void display(struct Node* head) {
    if (head == NULL)
        return;

    struct Node* temp = head;

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
}

int main() {
    int n, value;
    struct Node* head = NULL;

    // Input number of nodes
    scanf("%d", &n);

    // Input elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = insert(head, value);
    }

    // Display circular linked list
    display(head);

    return 0;
}