#include <stdio.h>

int main() {
    int i, j, k;

    // ----------- 2D ARRAY -----------
    int a[2][2], b[2][2], sum2D[2][2];

    printf("Enter elements of 2D array A (2x2):\n");
    for(i = 0; i < 2; i++)
        for(j = 0; j < 2; j++)
            scanf("%d", &a[i][j]);

    printf("Enter elements of 2D array B (2x2):\n");
    for(i = 0; i < 2; i++)
        for(j = 0; j < 2; j++)
            scanf("%d", &b[i][j]);

    // Index method (2D)
    for(i = 0; i < 2; i++)
        for(j = 0; j < 2; j++)
            sum2D[i][j] = a[i][j] + b[i][j];

    printf("\n2D Addition using Index:\n");
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++)
            printf("%d ", sum2D[i][j]);
        printf("\n");
    }

    // Pointer method (2D)
    printf("\n2D Addition using Pointer:\n");
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++)
            printf("%d ", *(*(a+i)+j) + *(*(b+i)+j));
        printf("\n");
    }

    // ----------- 3D ARRAY -----------
    int x[2][2][2], y[2][2][2], sum3D[2][2][2];

    printf("\nEnter elements of 3D array X (2x2x2):\n");
    for(i = 0; i < 2; i++)
        for(j = 0; j < 2; j++)
            for(k = 0; k < 2; k++)
                scanf("%d", &x[i][j][k]);

    printf("Enter elements of 3D array Y (2x2x2):\n");
    for(i = 0; i < 2; i++)
        for(j = 0; j < 2; j++)
            for(k = 0; k < 2; k++)
                scanf("%d", &y[i][j][k]);

    // Index method (3D)
    for(i = 0; i < 2; i++)
        for(j = 0; j < 2; j++)
            for(k = 0; k < 2; k++)
                sum3D[i][j][k] = x[i][j][k] + y[i][j][k];

    printf("\n3D Addition using Index:\n");
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            for(k = 0; k < 2; k++)
                printf("%d ", sum3D[i][j][k]);
            printf("\n");
        }
        printf("\n");
    }

    // Pointer method (3D)
    printf("3D Addition using Pointer:\n");
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            for(k = 0; k < 2; k++)
                printf("%d ", *(*(*(x+i)+j)+k) + *(*(*(y+i)+j)+k));
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}
