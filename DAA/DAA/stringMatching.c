#include<stdio.h>
#include<string.h>
int main()
{
  char str1[1000];
  char str2[1000];
  printf("\nEnter main string : ");
  scanf("%s",str1);
  printf("\nEnter the sub-string : ");
  scanf("%s",str2);
  int len1 = strlen(str1);
  int len2 = strlen(str2);
  int flag;
  int matches[100];
  int count =0;
  for(int i=0;i<(len1-len2+1);i++)
  {
    flag = 1;
    for(int j=0;j<len2 && flag == 1;j++)
    {
      if(str1[i+j] != str2[j])
        flag = 0;
    }
    if(flag == 1)
      matches[count++] = i;
  }
  if(count>0)
  {
    for(int i=0;i<count;i++)
    {
      printf("\nMatches at %d\n",matches[i]);
    }
  }
  return 0;
}