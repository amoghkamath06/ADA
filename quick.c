#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int a[], int lb, int ub)
{
    int pivot = a[lb];

    int i = lb;

    int j = ub;

    while(i < j)
    {
        while(a[i] <= pivot && i < ub)
        {
            i++;
        }

        while(a[j] > pivot)
        {
            j--;
        }

        if(i < j)
        {
            int temp = a[i];

            a[i] = a[j];

            a[j] = temp;
        }
    }

    a[lb] = a[j];

    a[j] = pivot;

    return j;
}

void quickSort(int a[], int lb, int ub)
{
    if(lb < ub)
    {
        int k = partition(a, lb, ub);

        quickSort(a, lb, k - 1);

        quickSort(a, k + 1, ub);
    }
}

int main()
{
    int n, i;

    clock_t start, end;

    double time_taken;

    srand(time(NULL));

    for(n = 10000; n <= 50000; n += 10000)
    {
        int *arr = (int *)malloc(n * sizeof(int));

        for(i = 0; i < n; i++)
        {
            arr[i] = rand() % 10000;
        }

        start = clock();

        quickSort(arr, 0, n - 1);

        end = clock();

        time_taken = (double)(end - start) / CLOCKS_PER_SEC;

        printf("n = %d \t Time = %f seconds\n", n, time_taken);

        free(arr);
    }

    return 0;
}