#include <stdio.h>
int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
void memorization(int max_weight, int noOfItems, int array[noOfItems + 1][max_weight + 1], int p_w[noOfItems][2])
{
    for (int i = 1; i <= noOfItems; i++)
    {
        for (int j = 1; j <= max_weight; j++)
        {
            if (j - p_w[i][1] >= 0)
                array[i][j] = max(array[i - 1][j], array[i - 1][j - p_w[i][1]] + p_w[i][0]);
            else
                array[i][j] = array[i - 1][j];
        }
    }
}
int main()
{
    int noOfItems;
    printf("\nEnter the noOfItems : ");
    scanf("%d", &noOfItems);
    int p_w[noOfItems + 1][2];
    p_w[0][1] = 0;
    p_w[1][0] = 0;
    for (int i = 1; i <= noOfItems; i++)
    {
        printf("\nEnter the profit %d : ", i);
        scanf("%d", &p_w[i][0]);
        printf("\nEnter the weight : ");
        scanf("%d", &p_w[i][1]);
    }
    int max_weight;
    printf("\nEnter the max weight : ");
    scanf("%d", &max_weight);
    int array[noOfItems + 1][max_weight + 1];
    for (int i = 0; i <= noOfItems; i++)
    {
        for (int j = 0; j <= max_weight; j++)
        {
            array[i][j] = 0;
        }
    }
    memorization(max_weight, noOfItems, array, p_w);
    for (int i = 0; i <= noOfItems; i++)
    {
        printf("\n");
        for (int j = 0; j <= max_weight; j++)
        {
            printf("%d ", array[i][j]);
        }
    }
    return 0;
}