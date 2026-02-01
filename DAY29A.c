#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Insert at end
struct Node* insert(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Get length
int getLength(struct Node* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

// Rotate right by k
struct Node* rotate(struct Node* head, int k) {
    if (head == NULL || head->next == NULL)
        return head;

    int len = getLength(head);
    k = k % len;

    if (k == 0)
        return head;

    struct Node* temp = head;

    // Go to last node
    while (temp->next != NULL)
        temp = temp->next;

    // Make circular
    temp->next = head;

    // Move to (len - k)th node
    int steps = len - k;
    temp = head;
    for (int i = 1; i < steps; i++) {
        temp = temp->next;
    }

    // New head
    struct Node* newHead = temp->next;

    // Break circular link
    temp->next = NULL;

    return newHead;
}

// Display list
void display(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, value, k;
    struct Node* head = NULL;

    // Input
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = insert(head, value);
    }

    scanf("%d", &k);

    // Rotate
    head = rotate(head, k);

    // Output
    display(head);

    return 0;
}