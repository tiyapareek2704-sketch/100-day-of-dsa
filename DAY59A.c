#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Search element in inorder
int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

int postIndex;

// Build tree
struct Node* buildTree(int inorder[], int postorder[], int start, int end) {
    if (start > end)
        return NULL;

    // Pick last element from postorder
    int curr = postorder[postIndex--];
    struct Node* node = newNode(curr);

    // If only one node
    if (start == end)
        return node;

    int pos = search(inorder, start, end, curr);

    // IMPORTANT: build right first
    node->right = buildTree(inorder, postorder, pos + 1, end);
    node->left  = buildTree(inorder, postorder, start, pos - 1);

    return node;
}

// Preorder traversal
void preorder(struct Node* root) {
    if (root == NULL) return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int inorder[n], postorder[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &postorder[i]);

    postIndex = n - 1;

    struct Node* root = buildTree(inorder, postorder, 0, n - 1);

    preorder(root);

    return 0;
}