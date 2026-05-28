#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int A[], int B[], int lb, int mid, int ub)
{
    int i = lb;

    int j = mid + 1;

    int k = lb;

    while(i <= mid && j <= ub)
    {
        if(A[i] <= A[j])
        {
            B[k++] = A[i++];
        }
        else
        {
            B[k++] = A[j++];
        }
    }

    while(i <= mid)
    {
        B[k++] = A[i++];
    }

    while(j <= ub)
    {
        B[k++] = A[j++];
    }

    for(i = lb; i <= ub; i++)
    {
        A[i] = B[i];
    }
}

void mergeSort(int A[], int B[], int lb, int ub)
{
    if(lb < ub)
    {
        int mid = (lb + ub) / 2;

        mergeSort(A, B, lb, mid);

        mergeSort(A, B, mid + 1, ub);

        merge(A, B, lb, mid, ub);
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

        int *temp = (int *)malloc(n * sizeof(int));

        for(i = 0; i < n; i++)
        {
            arr[i] = rand() % 10000;
        }

        start = clock();

        mergeSort(arr, temp, 0, n - 1);

        end = clock();

        time_taken = (double)(end - start) / CLOCKS_PER_SEC;

        printf("n = %d \t Time = %f seconds\n", n, time_taken);

        free(arr);

        free(temp);
    }

    return 0;
}