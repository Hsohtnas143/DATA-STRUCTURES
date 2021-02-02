#include<stdio.h>

int main()
{
    //SELECTIONSORT
    int a[10] = {10,3,2,1,4,3,5,1,3,5};
    int n=10,min,temp,p;
    for(int i=0;i<n;i++)
    {
        p=i;
        min = a[i];
        for(int j=i;j<n;j++)
        {
            if(a[j]<=min)
            {
                p = j;
                min = a[j];
                printf("\n%d , p = %d\n",a[p],p);
            }
        }
        temp = a[p];
        a[p] = a[i];
        a[i] = temp;
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
