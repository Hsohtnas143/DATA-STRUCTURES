#include <stdio.h>
void choose(int n, int k, int array[n][k])
{

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<k;j++)
        {
            if(j==0 || i==j)
            {
                array[i][j] = 1;
            }
            else
            {
                array[i][j] = array[i-1][j]+array[i-1][j-1];
            }
        } 
    }
}
int main()
{
    int n = 201;
    int k = 100;
    int array[n+1][k+1];
    choose(n+1, k+1,array);
    printf("%d", array[n][k]);
    return 0;
}