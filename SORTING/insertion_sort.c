#include<stdio.h>

int main()
{
    //INSERTION SORT
    int a[10] = {10,3,2,1,4,3,5,1,3,5};
    int n=10,count=0,val,temp,p;
    for(int i=0;i<n;i++)
    {
        val = a[i];
        p = i;
        for(int j=i;j>0;j--)
        {
            if(a[i]<a[j-1])
            {
                p = j-1;
            }
        }
        temp = a[i];
        for(int k=i;k>p;k--)
        {
            a[k] = a[k-1];
        }
        a[p] = temp;
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
