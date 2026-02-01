#include <stdio.h>
#define MAX 100

int pq[MAX];
int size = 0;

// insert
void insert(int x) {
    if (size == MAX) return;
    pq[size++] = x;
}

// find index of minimum element
int findMinIndex() {
    if (size == 0) return -1;

    int minIndex = 0;
    for (int i = 1; i < size; i++) {
        if (pq[i] < pq[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

// delete (remove highest priority)
void deletePQ() {
    if (size == 0) {
        printf("-1\n");
        return;
    }

    int minIndex = findMinIndex();
    printf("%d\n", pq[minIndex]);

    pq[minIndex] = pq[size - 1];
    size--;
}

// peek
void peek() {
    if (size == 0) {
        printf("-1\n");
        return;
    }

    int minIndex = findMinIndex();
    printf("%d\n", pq[minIndex]);
}

int main() {
    int n, x;
    char op[10];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", op);

        if (op[0] == 'i') {  // insert
            scanf("%d", &x);
            insert(x);
        }
        else if (op[0] == 'd') {  // delete
            deletePQ();
        }
        else if (op[0] == 'p') {  // peek
            peek();
        }
    }

    return 0;
}