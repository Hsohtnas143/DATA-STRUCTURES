#include <stdio.h>
#include <math.h>
//0/1-knapsack greedy method
int main()
{
    int n = 7;
    int weights[] = {2, 3, 4, 5,8,10,16};
    int profits[] = {3, 4, 5, 6,1,40,3};
    int max_weight = 20;
    int max_profit = 0;
    float p_w[n];
    for (int i = 0; i < n; i++)
    {
        p_w[i] = (float)profits[i] / (float)weights[i];
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%f ", p_w[i]);
    }
    float max = 0;
    int index;
    while (1)
    {
        max = 0;
        for (int i = 0; i < n; i++)
        {
            if (p_w[i] > max && p_w[i] != -1)
            {
                max = p_w[i];
                index = i;
            }
        }
        if (weights[index] <= max_weight)
        {
            max_profit += profits[index];
            max_weight -= weights[index];
            p_w[index] = -1;
        }
        else
        {
            break;
        }
    }
    printf("\nans = %d", max_profit);
}