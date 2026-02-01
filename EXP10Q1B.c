#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int arr[1000];
    int i, j, temp, key;
    int found = 0;
    int comparisons = 0;

    clock_t start, end;
    double cpu_time_used;

    srand(time(0));

    // Generate 1000 random numbers
    for(i = 0; i < 1000; i++) {
        arr[i] = rand() % 1000;
    }

    // Sort array using bubble sort
    for(i = 0; i < 999; i++) {
        for(j = 0; j < 999 - i; j++) {
            if(arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Print sorted array
    printf("Sorted Array:\n");
    for(i = 0; i < 1000; i++) {
        printf("%d ", arr[i]);

        if((i + 1) % 20 == 0) {
            printf("\n");
        }
    }

    // Input element to search
    printf("\nEnter element to search: ");
    scanf("%d", &key);

    int low = 0;
    int high = 999;

    // Start timer
    start = clock();

    // Binary Search
    while(low <= high) {
        comparisons++;

        int mid = (low + high) / 2;

        if(arr[mid] == key) {
            printf("Element found at position %d\n", mid + 1);
            found = 1;
            break;
        }
        else if(arr[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    // End timer
    end = clock();

    if(found == 0) {
        printf("Element not found\n");
    }

    // Calculate execution time
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Total comparisons = %d\n", comparisons);
    printf("Execution time = %f seconds\n", cpu_time_used);
    printf("Time Complexity = O(log n)\n");

    return 0;
}
