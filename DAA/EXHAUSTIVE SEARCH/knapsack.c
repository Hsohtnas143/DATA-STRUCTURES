#include<stdio.h>
#include<math.h>
int items[100];
int max_profit = 0;
int count1 = 0;
void powerSet(int p_w[][2],int noOfItems,int max_weight)
{
    int sum;
    int weight = max_weight;
    int arr[noOfItems];
    int count = 0;
    for(int i=1;i<pow(2,noOfItems);i++)
    {
        sum = 0;
        weight = max_weight;
        count = 0;
        for(int j=0;j<noOfItems;j++)
        {
            if((i & (1<<j)) && (weight>=p_w[j][1]))
            {
                sum+= p_w[j][0];
                printf("\nmax weight %d\n",weight);
                weight-=p_w[j][1];
                arr[count++] = j;
            }
        }
        if(sum>max_profit)
        {
            max_profit = sum;
            count1 = count;
            for(int k=0;k<count;k++)
            {
                items[k] = arr[k];
            }
        }
    }
}
int main()
{
    int noOfItems;
    printf("\nEnter the noOfItems : ");
    scanf("%d",&noOfItems);
    int p_w[noOfItems][2];
    for(int i=0;i<noOfItems;i++)
    {
        printf("\nEnter the profit %d : ",i);
        scanf("%d",&p_w[i][0]);
        printf("\nEnter the weight : ");
        scanf("%d",&p_w[i][1]);
    }
    int max_weight;
    printf("\nEnter the max weight : ");
    scanf("%d",&max_weight);
    powerSet(p_w,noOfItems,max_weight);
    for(int i=0;i<count1;i++)
    {
        printf("%d ",items[i]);
    }
    printf("\n profit : %d",max_profit);
    return 0;
}
