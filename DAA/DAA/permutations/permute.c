#include<stdio.h>
#include<string.h>

void swap(char a[],int i,int j)
{
    char temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void permute(char a[], int l, int r)
{
    if(l==r)
    {
        printf("\n%s",a);
    }
    else
    {
        for(int i=l;i<=r;i++)
        {
            swap(a,i,l);
            permute(a,l+1,r);
            swap(a,i,l);
        }
    }
}

int main()
{
    char a[1000];
    printf("\nenter the string : ");
    scanf("%s",a);
    int len = strlen(a);
    permute(a,0,len-1);
    return 0;
}