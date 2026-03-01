#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define X 100
#define Y 100
#define Z 50

int main() {
    static int A[X][Y][Z];
    static int B[X][Y][Z];
    static int C[X][Y][Z];

    int i, j, k;

    srand(time(NULL));

    // Fill arrays with random numbers
    for(i = 0; i < X; i++)
        for(j = 0; j < Y; j++)
            for(k = 0; k < Z; k++) {
                A[i][j][k] = rand() % 100;
                B[i][j][k] = rand() % 100;
            }

    clock_t start, end;
    double time_index, time_pointer;

    // -------------------------------
    // Method 1: Using Normal Indices
    // -------------------------------
    start = clock();

    for(i = 0; i < X; i++)
        for(j = 0; j < Y; j++)
            for(k = 0; k < Z; k++)
                C[i][j][k] = A[i][j][k] + B[i][j][k];

    end = clock();
    time_index = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Time using normal indexing: %f seconds\n", time_index);

    // -------------------------------
    // Method 2: Using Pointers
    // -------------------------------
    int *pA = &A[0][0][0];
    int *pB = &B[0][0][0];
    int *pC = &C[0][0][0];

    start = clock();

    for(i = 0; i < X * Y * Z; i++)
        *(pC + i) = *(pA + i) + *(pB + i);

    end = clock();
    time_pointer = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Time using pointer arithmetic: %f seconds\n", time_pointer);

    // -------------------------------
    // Comparison
    // -------------------------------
    if(time_index > time_pointer)
        printf("Pointer method is slightly faster.\n");
    else if(time_index < time_pointer)
        printf("Indexing method is slightly faster.\n");
    else
        printf("Both methods have similar performance.\n");

    return 0;
}
