#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Queue for level order
struct Node* queue[100];
int front = 0, rear = -1;

void enqueue(struct Node* node) {
    queue[++rear] = node;
}

struct Node* dequeue() {
    return queue[front++];
}

// Function to print right view
void rightView(struct Node* root) {
    if (root == NULL) return;

    enqueue(root);

    while (front <= rear) {
        int size = rear - front + 1;

        for (int i = 0; i < size; i++) {
            struct Node* curr = dequeue();

            // Print last node of this level
            if (i == size - 1) {
                printf("%d ", curr->data);
            }

            if (curr->left != NULL)
                enqueue(curr->left);

            if (curr->right != NULL)
                enqueue(curr->right);
        }
    }
}

// Build tree from level order input
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = newNode(arr[0]);
    enqueue(root);

    int i = 1;

    while (i < n) {
        struct Node* curr = dequeue();

        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            enqueue(curr->left);
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            enqueue(curr->right);
        }
        i++;
    }

    return root;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    front = 0; rear = -1;  // reset queue
    struct Node* root = buildTree(arr, n);

    front = 0; rear = -1;  // reset queue again
    rightView(root);

    return 0;
}