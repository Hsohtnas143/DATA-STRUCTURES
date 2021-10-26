#include<stdio.h>
#include<math.h>
void comb(int arr[],int n,int size)
{
    int count = 0;
    int arr1[size];
    for(int i=1;i<pow(2,n);i++)
    {
        count = 0;
        //printf("\n");
        for(int j=0;j<n;j++)
        {
            if((i & 1<<j) != 0)
            {
                arr1[count++] = j;
                //printf("%d ",arr[j]);
            }
        }
        if(count == size)
        {
            for(int k=0;k<count;k++)
            {
                printf("%d ",arr[arr1[k]]);
            }
            printf("\n");
        }
        
    }   

}
int main()
{
    int n;
    printf("\nEnter the length : ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int size;
    printf("\nenter the size : ");
    scanf("%d",&size);
        comb(arr,n,size);
    return 0;
}

