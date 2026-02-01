#include <stdio.h>
#define MAX 100

int heap[MAX];
int size = 0;

// swap function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// heapify up
void heapifyUp(int i) {
    while (i != 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// heapify down
void heapifyDown(int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;

    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(smallest);
    }
}

// insert
void insert(int x) {
    if (size == MAX) return;

    heap[size] = x;
    heapifyUp(size);
    size++;
}

// extract min
void extractMin() {
    if (size <= 0) {
        printf("-1\n");
        return;
    }

    int root = heap[0];
    printf("%d\n", root);

    heap[0] = heap[size - 1];
    size--;

    heapifyDown(0);
}

// peek
void peek() {
    if (size <= 0) {
        printf("-1\n");
    } else {
        printf("%d\n", heap[0]);
    }
}

int main() {
    int n, x;
    char op[20];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", op);

        if (op[0] == 'i') {  // insert
            scanf("%d", &x);
            insert(x);
        }
        else if (op[0] == 'e') {  // extractMin
            extractMin();
        }
        else if (op[0] == 'p') {  // peek
            peek();
        }
    }

    return 0;
}