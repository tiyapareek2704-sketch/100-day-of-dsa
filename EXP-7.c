#include <stdio.h>
#include <stdlib.h>

// -------- BST Node --------
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert into BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

// Inorder Traversal (Display BST)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// -------- Linear Search --------
int linearSearch(int arr[], int n, int key, int *steps) {
    *steps = 0;
    for (int i = 0; i < n; i++) {
        (*steps)++;
        if (arr[i] == key)
            return i;
    }
    return -1;
}

// -------- Binary Search --------
int binarySearch(int arr[], int low, int high, int key, int *steps) {
    *steps = 0;
    while (low <= high) {
        (*steps)++;
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

// -------- Main --------
int main() {
    int arr[10], key;
    int stepsLS, stepsBS;

    printf("Enter 10 elements:\n");
    for (int i = 0; i < 10; i++)
        scanf("%d", &arr[i]);

    printf("Enter element to search: ");
    scanf("%d", &key);

    // -------- Linear Search --------
    int pos1 = linearSearch(arr, 10, key, &stepsLS);

    if (pos1 != -1)
        printf("\nLinear Search: Element found at position %d", pos1 + 1);
    else
        printf("\nLinear Search: Element not found");

    printf("\nSteps taken (Linear Search): %d\n", stepsLS);

    // -------- Sort array for Binary Search --------
    for (int i = 0; i < 10 - 1; i++) {
        for (int j = i + 1; j < 10; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    // -------- Binary Search --------
    int pos2 = binarySearch(arr, 0, 9, key, &stepsBS);

    if (pos2 != -1)
        printf("\nBinary Search: Element found at position %d (sorted array)", pos2 + 1);
    else
        printf("\nBinary Search: Element not found");

    printf("\nSteps taken (Binary Search): %d\n", stepsBS);

    // -------- BST --------
    struct Node* root = NULL;
    for (int i = 0; i < 10; i++)
        root = insert(root, arr[i]);

    printf("\nBST (Inorder Traversal): ");
    inorder(root);

    printf("\n");

    return 0;
}