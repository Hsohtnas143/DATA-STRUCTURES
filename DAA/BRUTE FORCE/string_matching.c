

#include <stdio.h>
#include <string.h>
void main()
{
    char s1[1000];
    char s2[1000];
    printf("\nenter the main string : ");
    scanf("%s",s1);
    printf("\nenter the sub-string : ");
    scanf("%s",s2);
    int len = strlen(s1);
    int len1 = strlen(s2);
    int flag=0,p[100],count=0;
    for(int i=0; i<(len-len1)+1; i++)
    {
        flag = 1;
        for(int j=0;(j<len1 && flag==1 ); j++)
        {
            if(s1[i+j] != s2[j])
            {
                flag = 0;
            }
        }
        if(flag==1)
        {
            p[count++] = i;
        }
    }
    if(count>0)
    {
        printf("\nfound at index");
        for(int i=0;i<count;i++)
        {
            printf("%d ",p[i]);
        }
        printf("\n%d times",count);
    }
    else
    {
        printf("\nnot found");
    }
    
}

