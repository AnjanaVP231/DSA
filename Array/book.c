#include <stdio.h>

int main()
{

    // Declare 6D array
    int library[12][5][8][12][8][9];

    int b, f, r, s, row, col;

    printf("Enter Building (1-12): ");
    scanf("%d", &b);

    printf("Enter Floor (1-5): ");
    scanf("%d", &f);

    printf("Enter Room (1-8): ");
    scanf("%d", &r);

    printf("Enter Shelf (1-12): ");
    scanf("%d", &s);

    printf("Enter Row (1-8): ");
    scanf("%d", &row);

    printf("Enter Column (1-9): ");
    scanf("%d", &col);

    // Convert to index (subtract 1 because array starts from 0)
    library[b - 1][f - 1][r - 1][s - 1][row - 1][col - 1] = 1;

    printf("Book selected successfully!\n");

    return 0;
}
