#include<stdio.h>
int min(int a,int b)
{
    if(a>b)
    {
        return b;
    }
    else
    {
        return a;
    }
}
void print(int matrix[4][4])
{
    for(int i=0;i<4;i++)
    {
        printf("\n");
        for(int j=0;j<4;j++)
        {
            printf("%d ",matrix[i][j]);
        }
    }
}
int main()
{
    int adj_mat[4][4] = {
        {0,3,1000,7},
        {8,0,2,1000},
        {5,1000,0,1},
        {2,1000,1000,0}
    };
    
    for(int k=0;k<4;k++)
    {
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                adj_mat[i][j] = min(adj_mat[i][j],adj_mat[i][k]+adj_mat[k][j]);
            }
        }
        printf("\n");
        print(adj_mat);
    }
    return 0;
}