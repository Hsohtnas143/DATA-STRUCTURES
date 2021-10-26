#include<stdio.h>
#include <math.h> 
int min(int n, int dp[n][n],int dimensions[n+1],int row,int col)
{
    int sum = 0;
    int flag = 0;
    double min = INFINITY;
    int index;
    for(int i=0;i<col-row;i++)
    {
        sum = dp[row][i+row]+dp[row+i+1][col]+(dimensions[row]*dimensions[row+i+1]*dimensions[col+1]);
        if(sum<min)
        {
            min = sum;
            index = row+i;
        }
        flag = 1;
    }
    if(flag==0)
    {
        return 0;
    }
    dp[col][row] = index;
    return min;
}
int main()
{
    int n;
    printf("\nEnter no. of matrices: ");
    scanf("%d",&n);
    int dimensions[n+1];
    for(int i=0;i<=n;i++)
    {
        printf("\nEnter %d dimension : ",i);
        scanf("%d",&dimensions[i]);
    }
    int dp[n][n];
    int i = 0,j=0;
    int row=0,col=0;
    while(i<n&&j<n)
    {
        dp[row][col] = min(n,dp,dimensions,row,col);
        if(col==n-1)
        {
            row = i;
            j++;
            col = j;
        }
        else
        {
            row++;
            col++;
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("\n");
        for(int j=0;j<n;j++)
        {
            printf("%d ",dp[i][j]);
        }
    }
    printf("\n");
    int q = 0;
    for(int i=0;i<n;i++)
    {
        printf("\n");
        for(int j=q;j<=dp[i][0];j++)
        {
            q = j+1;
            printf("%d ",j);
        }
    }
    
    return 0;
}