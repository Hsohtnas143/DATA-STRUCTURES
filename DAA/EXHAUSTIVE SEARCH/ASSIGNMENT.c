#include<stdio.h>
#include<math.h>
int jobs[20];
double min_cost = INFINITY;
void swap(int string[], int a, int b)
{
    int f = string[a];
    string[a] = string[b];
    string[b] = f;
}
void permute(int arr[], int left,int right,int cost[][right+1])
{
    if(left==right)
    {
        int sum = 0;
        for(int i=0;i<=right;i++)
        {
            if(sum>min_cost)
            {
                break;
            }
            sum+= cost[i][arr[i]];
        }
        if(sum<min_cost)
        {
            min_cost = sum;
            for(int i=0;i<=right;i++)
            {
                jobs[i] = arr[i];
            }
        }
    }
    for (int i = left; i <= right; i++)
    {
        swap(arr, left, i);
        permute(arr,left+1,right,cost);
        swap(arr, left, i);
    }
}
int main()
{
    int noOfPersons;
    printf("\nEnter no. of persons : ");
    scanf("%d",&noOfPersons);
    int cost[noOfPersons][noOfPersons];
    int arr[noOfPersons];
    for(int i=0;i<noOfPersons;i++)
    {
        for(int j=0;j<noOfPersons;j++)
        {
            printf("\nEnter the cost for Person-%d and Job-%d : ",i+1,j+1);
            scanf("%d",&cost[i][j]);
        }
        arr[i] = i;
    }
    permute(arr,0,noOfPersons-1,cost);
    printf("\n");
    for(int i=0;i<noOfPersons;i++)
    {
        printf("%d ",jobs[i]);
    }
    printf("\nsum = %.2lf\n",min_cost);
    return 0;
}
