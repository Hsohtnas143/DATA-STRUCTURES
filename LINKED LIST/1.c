#include <stdio.h>

int main() {
	int n,a,b,c,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	    scanf("%d %d %d",&a,&b,&c);
	    if(a>b && a>c && b>c){
	        printf("%d\n",b);
	    }
	    else if(a>b && a>c && b<c){
	        printf("%d\n",c);
	    }
	    else if(b>c && b>a && a>c){
	        printf("%d\n",a);
	    }
	}


	return 0;
}

