#include<stdio.h>
int count = 0;
int swap(int a[],int k,int j)
{
    int temp = a[k];
    a[k] = a[j];
    a[j] = temp;
    count++;
}
int quick(int a[], int l, int h)
{
    int p = a[l];
    int k=0;
        for(int j=1+l;j<=h;j++)
        {
            if(a[j]<p)
            {
                k++;
                swap(a,k+l,j);
            }
        }
        swap(a,k+l,l);
    //printf("\n%d\n",k);
    if(l<k+l-1)
    {
        quick(a,l,k+l-1);

    }
    if(k+l+1<h)
    {
        quick(a,k+l+1,h);
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
    //int a[7] = {7,54,4,1,3,100,9};
    quick(a,0,n-1);
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n no of swaps : %d",count);
}
