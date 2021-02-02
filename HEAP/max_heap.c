#include<stdio.h>
int n=10;
int swap(int i,int min,int a[n])
{
    int temp = a[i];
    a[i] = a[min];
    a[min] = temp;
}

int heapify(int a[10],int i)
{
    int l = (2*i)+1;
    int r = (2*i)+2;
    int max =-1;
    if(n>r)
    {
        if(a[l]<=a[r])
        {
            max = r;
        }
        else 
        {
            max = l;
        }
    }
    else if(n>l)
    {
        max = l;
    }
    if(a[i]<=a[max] && max!=-1)
    {
        swap(i,max,a);
        heapify(a,max);
        
    }
}

int main()
{
    int a[10] = {4,3,2,1,4,3,21,6,7,8};
    for(int i=n/2;i>=0;i--)
    {
        heapify(a,i);
    }
    for(int i=0;i<10;i++)
    {
        printf("%d ",a[i]);
    }
}
