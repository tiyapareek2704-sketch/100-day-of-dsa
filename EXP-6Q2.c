#include <stdio.h>

#define MAX 100

int heap[MAX];
int size = 0;

// Swap
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Insert
void insert(int value) {
    size++;
    heap[size] = value;

    int i = size;

    while (i > 1 && heap[i / 2] < heap[i]) {
        swap(&heap[i / 2], &heap[i]);
        i = i / 2;
    }
}

// Heapify
void heapify(int i) {
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= size && heap[left] > heap[largest])
        largest = left;

    if (right <= size && heap[right] > heap[largest])
        largest = right;

    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        heapify(largest);
    }
}

// Delete Root
void deleteRoot() {
    if (size == 0) {
        printf("Heap is empty\n");
        return;
    }

    heap[1] = heap[size];
    size--;

    heapify(1);
}

// Display
void display() {
    for (int i = 1; i <= size; i++)
        printf("%d ", heap[i]);
}

// Main
int main() {
    insert(50);
    insert(30);
    insert(40);
    insert(10);
    insert(5);

    printf("Heap: ");
    display();

    deleteRoot();

    printf("\nAfter Deletion: ");
    display();

    return 0;
}