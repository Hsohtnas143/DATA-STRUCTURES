#include<stdio.h>

int main()
{
    //BUBBLE SORT
    int a[10] = {10,3,2,1,4,3,5,1,3,5};
    int n=10,temp;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(a[j]>=a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
