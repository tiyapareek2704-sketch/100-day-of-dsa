#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int arr[1000];
    int i, key;
    int found = 0;
    int comparisons = 0;

    clock_t start, end;
    double cpu_time_used;

    srand(time(0));

    // Generate random numbers
    for(i = 0; i < 1000; i++) {
        arr[i] = rand() % 1000;
    }

    // Print array
    printf("Generated Array:\n");
    for(i = 0; i < 1000; i++) {
        printf("%d ", arr[i]);

        if((i + 1) % 20 == 0) {
            printf("\n");
        }
    }

    // Input search key
    printf("\nEnter element to search: ");
    scanf("%d", &key);

    // Start time
    start = clock();

    // Linear Search
    for(i = 0; i < 1000; i++) {
        comparisons++;

        if(arr[i] == key) {
            printf("Element found at position %d\n", i + 1);
            found = 1;
            break;
        }
    }

    // End time
    end = clock();

    if(found == 0) {
        printf("Element not found\n");
    }

    // Calculate time
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Total comparisons = %d\n", comparisons);
    printf("Execution time = %f seconds\n", cpu_time_used);
    printf("Time Complexity = O(n)\n");

    return 0;
}