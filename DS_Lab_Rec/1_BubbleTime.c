#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Bubble Sort Function
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int sizes[] = {10000, 20000, 30000, 40000, 50000,
                   60000, 70000, 80000, 90000, 100000};

    int i, j;

    // Seed random generator
    srand(time(NULL));

    printf("----- Experimental Time Complexity (Bubble Sort) -----\n");

    for(i = 0; i < 10; i++) {
        int n = sizes[i];

        // Dynamic array allocation
        int *arr = (int *)malloc(n * sizeof(int));

        if(arr == NULL) {
            printf("Memory allocation failed\n");
            return 0;
        }

        // Generate random numbers
        for(j = 0; j < n; j++) {
            arr[j] = rand() % 100000;   // Random values
        }

        // Start time
        clock_t start = clock();

        // Perform sorting
        bubbleSort(arr, n);

        // End time
        clock_t end = clock();

        // Calculate time
        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("Input Size: %d \t Time Taken: %f seconds\n", n, time_taken);

        free(arr);
    }

    return 0;
}
