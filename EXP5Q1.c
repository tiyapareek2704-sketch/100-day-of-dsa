#include <stdio.h>

#define MAX 100

int tree[MAX];

// Inorder
void inorder(int i, int n) {
    if (i >= n || tree[i] == -1) return;

    inorder(2*i + 1, n);
    printf("%d ", tree[i]);
    inorder(2*i + 2, n);
}

// Preorder
void preorder(int i, int n) {
    if (i >= n || tree[i] == -1) return;

    printf("%d ", tree[i]);
    preorder(2*i + 1, n);
    preorder(2*i + 2, n);
}

// Postorder
void postorder(int i, int n) {
    if (i >= n || tree[i] == -1) return;

    postorder(2*i + 1, n);
    postorder(2*i + 2, n);
    printf("%d ", tree[i]);
}

int main() {
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements (-1 for NULL):\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &tree[i]);

    printf("Inorder: ");
    inorder(0, n);

    printf("\nPreorder: ");
    preorder(0, n);

    printf("\nPostorder: ");
    postorder(0, n);

    return 0;
}