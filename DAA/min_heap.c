#include<stdio.h>
#include<math.h>
int HH[1000];
int len1 = 0;
void swap(int first,int second,int a[])
{
	int temp = a[first];
	a[first] = a[second];
	a[second] = temp;
}

void heap(int a[], int i,int len)
{
	int min = -1;
	int l = (2*i)+1;
	int r = (2*i)+2;
	if(len>r)
	{
		if(a[i]>=a[r])
		{
			min = r;
		}
		else
			min= l;
	}
	else if(len>l)
	{
		min = l;
	}
	if(a[i]>=a[min]&&min!=-1)
	{
		swap(i,min,a);
		heap(a,min,len);
	}
	
}


void MAKEHEAP()
{
	
}

int yes=0;

void UNION(int H1[],int H2[],int len)
{
	int HHH[2*len];
	if(H1[0]>H2[0])
	{
		int i;
		for(i=0;i<len;i++)
		{
			HHH[2*i] = H2[i];
			HHH[(2*i)+1] = H1[i];
		}
		for(i=0;i<2*len;i++)
		{
			H1[i] = HHH[i];
		}
	}
	else
	{
		int i;
		for(i=0;i<len;i++)
		{
			HHH[2*i] = H1[i];
			HHH[(2*i)+1] = H2[i];
		}
		for(i=0;i<(2*len);i++)
		{
			H1[i] = HHH[i];
		}
	}
	yes=0;
}



void INSERT(int H[], int x, int len)
{
	int j=0;
	for(j=0;;j++)
	{
		if(pow(2,j)==len)
		{
			break;
		}
		else if(pow(2,j)>len)
		{
			j = j-1;
			break;
		}
	}
	
	if(pow(2,j)!=len || yes==1)
	{
		//printf("\n inside HH ");
		len1 = len - pow(2,j);
		int p;
		int k = pow(2,j);
		if(pow(2,j)==len)
		{
			k = len/2;
			len1 = len/2;
		}
		//printf("\n k is %d ",k);
		for(p = 0;p<len1;p++)
		{
			HH[p] = H[p+k];
		}
		//printf("\n len1 : %d len : %d",len1,len);
	
		int i;
		for(i=(len1/2) ; i>=0;i--)
		{
			heap(HH,i,len1);
		}
		
		yes=1;
		if(yes==1 && pow(2,j)==len)
		{
		//	printf("he");
			goto b;
		}
			
	}
	
	else b:if(HH[0]!='\0' && pow(2,j)==len)
	{
		
		UNION(H,HH,len);
		int i;
		for(i=0;i<len1;i++)
		{
			HH[i] = '\0';
		}
		len1=0;
	}
	else if(pow(2,j)==len && yes==0)
	{
		//printf("\n inside len ");
		{
			//printf("\n inside H ");
			int i;
			for(i=(len/2) ; i>=0 ; i--)
			{
				heap(H,i,len);
			}
		}
		yes=0;
	}
	
	
}

void MINIMUM(int H[],int len)
{
	if(HH[0]<H[0] && len1>0)
		printf("%d",HH[0]);
	else
		printf("%d",H[0]);
}

void EXTRACTMIN(int H[],int len)
{
	int i=0;
	while(pow(len,(1/i)) == 2)
	{
		i++;
	}
	int j;
	for(j=1;j<i;j++)
	{
		l = (2*0)+j;
	}
	
}

void DECREASEKEY(int H[],int x,int k)
{
	
}

void del(int H[],int i,int len)
{
	
	
	
}

void DELETE(int H[],int x, int len)
{
	int i;
	if(len1>0)
	{
		for(i=0;i<len1;i++)
		{
			if(HH[i] == x)
			{
				del(HH,i,len1);
				return;
			}
		}
	}
	if(len>0)
	{
		for(i=0;i<len;i++)
		{
			if(H[i] == x)
			{
				del(H,i,len);
				return;
			}
		}
	}
	
	
	
}



void PRINT(int H[], int len)
{
	if(len>0)
	{
		int i=0;
		printf("\n");
		for(i=0;i<len1;i++)
		{
			printf("%d ",HH[i]);
		}
		printf("\n");
		for(i=0;i<len-len1;i++)
		{
			printf("%d ",H[i]);
		}
	}
	else
	{
		printf("\nempty");
	}
}


// i k - insert k into heap
// d k - delete node k in heap
// p   - print heap
// m   - print min in heap
// x   - extract the min from heap
// r y z - decrease the value with key y by z
// e   - exit program

int main()
{
	char ch;
	int H[1000],x,k,j=1,len=0;
	while(j)
	{
		//printf("o");
		printf("\n enter the character \n i - insert k into the heap\n d - delete node k from the heap\n p - print Binomial heap \n m - print the minimum element in binomial heap \n x - extraxts the minimum element from heap \n r - decreases the value of node with key y by z \n e - exit the program. \n");
		scanf("%c",&ch);
		switch(ch)
		{
			case 'i' :
				printf("\nenter the key to insert : ");
				scanf("%d",&x);
				H[len++] = x;
				INSERT(H,x,len);
				break;
			case 'd' :
				printf("\nenter the key to delete : ");
				scanf("%d",&x);
				DELETE(H,x,len);
				break;
			case 'm' :
				MINIMUM(H,len);
				break;
			case 'p' :
				PRINT(H,len);
				break;
			case 'x' :
				EXTRACTMIN(H,int len);
				break;
			case 'r' :
				DECREASEKEY(H,x,k);
				break;
			case 'e' :
				j=0;
				break;
			default:
				break;
		}
	}
	
	
	
	
}
