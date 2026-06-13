#include <stdio.h>
int partition(int a[], int low, int high){
    int pivot = a[low];
    int i = low + 1;
    int j = high;
    int temp;
    while(i <= j)
    {
        while(i <= high && a[i] <= pivot)
            i++;
        while(a[j] > pivot)
            j--;
        if(i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    temp = a[low];
    a[low] = a[j];
    a[j] = temp;
    return j;
}
void quicksort(int a[], int low, int high)
{
    int p;
    if(low < high)
    {
        p = partition(a, low, high);
        quicksort(a, low, p - 1);
        quicksort(a, p + 1, high);
    }
}
int main()
{
    int a[100], n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    quicksort(a, 0, n - 1);
    printf("Sorted Array:\n");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}