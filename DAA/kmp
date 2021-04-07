#include<stdio.h>
#include<string.h>
void pi_table(char str[], int pi[], int len)
{
	int i=0,j=1;
	pi[0] = 0;
	while(j<len)
	{
		if(str[i] == str[j])
		{
			pi[j] = i+1;
			i++;
			j++;
		}
		else if(i==0)
		{
			pi[j] = 0;
			j++;
		}
		else
		{
			i = pi[i-1];
		}
	}
}


void KMP(char str[], char sub_str[], int pi[], int len, int len1)
{
	int i=0,j=0,count=0;
	while(i<len && j<len1)
	{
		if(str[i] == sub_str[j])
		{
			i++;
			j++;
			if(j==len1)
			{
			    printf("\nfound at index %d ",i-len1);
			    count++;
			    j = pi[j-1];
			}
		}
		else if(j!=0)
		{
			j = pi[j-1];
		}
		else
		{
			i++;
		}
	}
	if(count==0)
	{
	    printf("\nnot found");
	}
}

int main()
{
	char str[1000];
	char sub_str[1000];
	printf("\nenter string : ");
	scanf("%s",str);
	printf("\enter the sub-string : ");
	scanf("%s",sub_str);
	int len = strlen(str);
	int len1 = strlen(sub_str);
	int pi[len1];
	pi_table(sub_str,pi,len1);
	KMP(str,sub_str,pi,len,len1);

}
