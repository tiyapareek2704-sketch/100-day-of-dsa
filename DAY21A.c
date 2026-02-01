#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, i, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n <= 0) return 0;

    struct Node *head = NULL, *temp = NULL, *newNode;

    // Create head node
    scanf("%d", &value);
    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = value;
    head->next = NULL;
    temp = head;

    // Create remaining nodes
    for (i = 1; i < n; i++) {
        scanf("%d", &value);
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        temp->next = newNode;
        temp = newNode;
    }

    // Traverse and print
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}