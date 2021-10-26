#include<stdio.h>
#include<string.h>

void swap(char string[],int a,int b)
{
    char f = string[a];
    string[a] = string[b];
    string[b] = f;
}

void permute(char string[],int left, int right)
{
    if(left == right)
    {
        printf("\n%s",string);
    }
    for(int i=left;i<=right;i++)
    {
        swap(string,left,i);
        permute(string,left+1,right);
        swap(string,left,i);
    }
}

int main()
{
    char string[100];
    scanf("%s",string);
    int len = strlen(string);
    permute(string,0,len-1);
    return 0;
}