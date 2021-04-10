#include<stdio.h>


void combinations(int a[], int print[], int start, int end, int index, int r)
{
    if(index==r)
    {
        printf("\n");
        for(int j=0;j<r;j++)
        {
            printf("%d",print[j]);
        }
        return;
    }
    else
    {
        for(int i = start; i<=end && end-i+1>= r-index;i++)
        {
            print[index] = a[i];
            combinations(a,print,i+1,end,index+1,r);
        }
    }
}

void main()
{
    printf("\nenter the length : ");
    int len;
    scanf("%d",&len);
    int a[len];
    
    for(int i=0;i<len;i++)
    {
        printf("\n enter the elements witha space : ");
        scanf("%d",&a[i]);
    }
    printf("\nenter the size : ");
    int r;
    scanf("%d",&r);
    int print[r];
    combinations(a,print,0,len-1,0,r);
}
