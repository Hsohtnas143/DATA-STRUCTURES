#include<stdio.h>
#include<string.h>

void combinations(char a[], char print[], int start, int end, int index, int r)
{
    if(index==r)
    {
        printf("\n");
        for(int j=0;j<r;j++)
        {
            printf("%c",print[j]);
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

int main()
{
    char a[1000];
    printf("\nenter the string : ");
    scanf("%s",a);
    int len = strlen(a);
    printf("\nenter the size : ");
    int r;
    scanf("%d",&r);
    char print[r];
    combinations(a,print,0,len-1,0,r);
    return 0;
}