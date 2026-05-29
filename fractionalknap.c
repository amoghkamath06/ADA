#include <stdio.h>

void sort(int profit[], int wt[], float ratio[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(ratio[j] < ratio[j + 1])
            {
                float temp = ratio[j];
                ratio[j] = ratio[j + 1];
                ratio[j + 1] = temp;

                int t = profit[j];
                profit[j] = profit[j + 1];
                profit[j + 1] = t;

                t = wt[j];
                wt[j] = wt[j + 1];
                wt[j + 1] = t;
            }
        }
    }
}

float fractionalKnapsack(int W, int wt[], int profit[], int n)
{
    float ratio[n];

    for(int i = 0; i < n; i++)
    {
        ratio[i] = (float)profit[i] / wt[i];
    }

    sort(profit, wt, ratio, n);

    float totalProfit = 0;

    for(int i = 0; i < n; i++)
    {
        if(wt[i] <= W)
        {
            totalProfit = totalProfit + profit[i];

            W = W - wt[i];
        }
        else
        {
            float fraction = (float)W / wt[i];

            totalProfit = totalProfit + (profit[i] * fraction);

            break;
        }
    }

    return totalProfit;
}

int main()
{
    int n, W;

    printf("Enter number of items : ");

    scanf("%d", &n);

    int wt[n], profit[n];

    printf("Enter weights : \n");

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &wt[i]);
    }

    printf("Enter profits : \n");

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &profit[i]);
    }

    printf("Enter capacity : ");

    scanf("%d", &W);

    float result = fractionalKnapsack(W, wt, profit, n);

    printf("Maximum Profit = %.2f", result);

    return 0;
}