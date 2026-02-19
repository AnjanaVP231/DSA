#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble_sort(int *, int);

int main()
{
    int i = 10000;
    srand(time(NULL));

    printf("===============================================\n");
    printf("|  Input Size  |  Bubble Sort Time (seconds) |\n");
    printf("===============================================\n");

    while (i <= 100000)
    {

        int *arr = (int *)malloc(i * sizeof(int));

        // Generate random numbers
        for (int j = 0; j < i; j++)
        {
            arr[j] = rand();
        }

        // Measure Bubble Sort time
        clock_t start = clock();
        bubble_sort(arr, i);
        clock_t end = clock();

        double bubble_time = (double)(end - start) / CLOCKS_PER_SEC;

        printf("|  %-10d |  %-26f |\n", i, bubble_time);

        free(arr);

        i += 10000;
    }

    printf("===============================================\n");

    return 0;
}

// Bubble Sort Function
void bubble_sort(int *a, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
