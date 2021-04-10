#include<stdio.h>
#include<string.h>
int main()
{
    char s1[1000];
    printf("\nmain string : ");
    scanf("%s",s1);
    int len = strlen(s1);
    char s2[100];
    printf("\nsub string : ");
    scanf("\n%s",s2);
    int len1 = strlen(s2);
    int i=0,j=0,p[100],len2=0;
    while(i<len)
    {
        if(s1[i]==s2[j])
        {
                
            i++;
            j++;
            if(j==len1)
            {
                p[len2++]=i-len1;
                j=0;
                i = p[len2-1]+1;
            }
        }
        else
        {
            i++;
            j=0;
        }
    }
    if(len2>0)
    {
        printf("\npattern found at ");
    }
    else
    {
        printf("\npattern not found");
    }
    for(int i=0;i<len2;i++)
    {
        printf("%d ", p[i]);
    }
    
    
}
