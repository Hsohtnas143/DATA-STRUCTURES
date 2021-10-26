#include <stdio.h>

int check(int n,int val, int index, int locations[n])
{
    val++;
    for(int i=0;i<index;i++)
    {
        if(val == locations[i] || val == locations[index-1]+1 || val == locations[index-1]-1)
        {
            return 0;
        }
    }
    return 1;
}
void nqueen( int n, int array[n][n], int queens[n], int locations[n])
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (queens[i] == 1)
        {
            count++;
        }
    }

    if (count == 0)
    {
        queens[0] = 1;
        locations[0] = 0;
        count++;
        nqueen(n,array, queens, locations);
    }
    else
    {
        int flag = 0;
        for (int i = count; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                flag = 0;
                for (int k = 0; k < count; k++)
                {
                    if ((j == locations[k]) || (j == locations[count - 1] + 1) || (j == locations[count - 1] - 1))
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    queens[count] = 1;
                    locations[count++] = j;
                    
                    break;
                }
            }
            if (flag == 1)
            {
                int flag1 = 0;
                for (int p = count - 1; p >= 0; p--)
                {
                    if (locations[p] < n-1 && check(n,locations[p],p,locations))
                    {
                        locations[p]++;
                        flag1 = 1;
                        break;
                    }
                    else
                    {
                        if(p>0)
                        {
                            locations[p] = -1;
                            queens[p] = 0;
                        }
                        else
                        {
                            return;
                        }
                        
                    }
                }
                if (flag1 == 1)
                {
                    flag1 = 0;
                    nqueen(n,array, queens, locations);
                }
                else
                {
                    return;
                }
            }
        }
    }
}

int main()
{
    int n;
    printf("\nEnter the array size : ");
    scanf("%d",&n);
    int array[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            array[i][j] = 0;
        }
    }
    int queens[n];
    int locations[n];
    nqueen(n,array, queens, locations);
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        array[i][locations[i]] = 1;
    }
    for(int i=0;i<n;i++)
    {
        printf("\n");
        for(int j=0;j<n;j++)
        {
            printf("%d ",array[i][j]);
        }
    }
    printf("\n");
    return 0;
}