#include<stdio.h>
#include<string.h>

void swap(int a[],int i,int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void permute(int a[], int l, int r, int length)
{
    if(l==r)
    {
        printf("\n");
        for(int i=0;i<length;i++)
        {
            printf("%d ",a[i]);
        }
    }
    else
    {
        for(int i=l;i<=r;i++)
        {
            swap(a,i,l);
            permute(a,l+1,r,length);
            swap(a,i,l);
        }
    }
}

void main()
{
    int len;
    printf("\nenter the length  : ");
    scanf("%d",&len);
    int a[len];
    for(int i=0;i<len;i++)
    {
        printf("\nenter the element of index %d : ",i);
        scanf("%d",&a[i]);
    }
    permute(a,0,len-1,len);
}
