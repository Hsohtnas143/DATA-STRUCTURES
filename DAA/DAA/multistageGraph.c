#include<stdio.h>
int main()
{
    // int n = 12;
    // int graph[12][12] = {
    //     {0,9,7,3,2,0,0,0,0,0,0,0},
    //     {0,0,0,0,0,4,2,1,0,0,0,0},
    //     {0,0,0,0,0,2,7,0,0,0,0,0},
    //     {0,0,0,0,0,0,0,11,0,0,0,0},
    //     {0,0,0,0,0,0,11,8,0,0,0,0},
    //     {0,0,0,0,0,0,0,0,6,5,0,0},
    //     {0,0,0,0,0,0,0,0,4,3,0,0},
    //     {0,0,0,0,0,0,0,0,0,5,6,0},
    //     {0,0,0,0,0,0,0,0,0,0,0,4},
    //     {0,0,0,0,0,0,0,0,0,0,0,2},
    //     {0,0,0,0,0,0,0,0,0,0,0,5},
    //     {0,0,0,0,0,0,0,0,0,0,0,0},
    // };
    int n;
    printf("\nEnter no. of vertices : ");
    scanf("%d",&n);
    int graph[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            graph[i][j] = 0;
        }
    }
    int i=0;
    int connections,index,weight;
    while(i<n)
    {
        printf("\nEnter the no. of connections for %d\nIf there is no connection press 0 : \n",i+1);
        scanf("%d",&connections);
        for(int j=0;j<connections;j++)
        {
            printf("\n%d to :",i+1);
            scanf("%d",&index);
            printf("\nweight : ");
            scanf("%d",&weight);
            graph[i][index-1] = weight;
        }
        i++;

    }
    int dp[2][n];
    int min = 10000;
    int sum = 0;
    int vertex;
    dp[1][n-1] = 0;
    dp[0][n-1] = n-1+1;
    for(int i = n-2;i>=0;i--)
    {
        vertex = i;
        for(int j=0;j<n;j++)
        {
            if(graph[i][j] != 0)
            {
                sum = graph[i][j]+dp[1][j];
                if(sum < min)
                {
                    min = sum;
                    vertex = j;
                }
            }
        }
        dp[1][i] = min;
        dp[0][i] = vertex+1;
        min = 10000;
    }
    // for(int i=0;i<2;i++)
    // {
    //     printf("\n");
    //     for(int j=0;j<n;j++)
    //     {
    //         printf("%d ",dp[i][j]);
    //     }
    // }
    printf("\npath is : %d->",1);
    int j=0;
    while(j<n-1)
    {
        printf("%d ->",dp[0][j]);
        j = dp[0][j]-1;
        
    }

    return 0;
}