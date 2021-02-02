#include<stdio.h>
int count =0;
int merge_sort(int a[],int l,int m,int h)
{
    int k=0;
    for(int i=l;i<h+1;i++)
    {
        for(int j=k;j<h-m;j++)
        {
            if(a[i]>=a[m+1+j])
            {
                int temp = a[m+1+j];
                for(int p = m+1+j;p > i;p--)
                {
                    a[p] = a[p-1];
                }
                a[i] = temp;
                count++;
                k+=1;
                break;
            }
        }
    }
    k=0;
}

int merge(int l, int h, int a[])
{
    if(l<h)
    {
        int m = (l+h)/2;
        merge(l,m,a);
        merge(m+1,h,a);
        //printf("\n l = %d m = %d h = %d",l,m,h);
        merge_sort(a,l,m,h);
    }


}
int main()
{
    int n;
    printf("ENTER THE LENGTH OF THE ARRAY : ");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

   //int  a[7] = {1,2,3,1,1,2,1};
    merge(0,n-1,a);
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\nno of swaps : %d ",count);
}
