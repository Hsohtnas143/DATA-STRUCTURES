#include<stdio.h>
//ASSIGNMENT PROBLEM
struct ALL_POSSIBILITIES
{
    int poss[1000];
    int cost;
};
int fact(int n)
{
    int fa=1;
    for(int i=1;i<=n;i++)
    {
        fa*=i;
    }
    return fa;
}
void swap(int matrix[], int i, int j)
{
    int temp = matrix[i];
    matrix[i] = matrix[j];
    matrix[j] = temp;
}

int count = 0;
void permute(int P_J,int cost_matrix[P_J][P_J],int l,int r,struct ALL_POSSIBILITIES A[],int matrix[])
{
    if(l==r)
    {
        int c=0;
        for(int i=0;i<P_J;i++)
        {
            A[count].poss[i] = matrix[i]-1;
            c+=cost_matrix[i][matrix[i]-1];
        }
        A[count++].cost = c;
    }
    else
    {
        for(int i =l;i<=r;i++)
        {
            swap(matrix,i,l);
            permute(P_J,cost_matrix,l+1,r,A,matrix);
            swap(matrix,i,l);
        }
    }
}


void ALL(struct ALL_POSSIBILITIES A[], int len, int P_J, int cost_matrix[P_J][P_J])
{
    for(int i=0;i<len;i++)
    {
        printf("\n\n ASSIGNMENTS : \n");
        for(int j=0;j<P_J; j++)
        {
            printf(" person - %d job - %d cost - %d\n",j+1,A[i].poss[j]+1,cost_matrix[j][A[i].poss[j]]);
        }
        printf("\n cost : %d\n",A[i].cost);
    }
}

void MIN(struct ALL_POSSIBILITIES A[], int len, int P_J, int arr[],int cost_matrix[P_J][P_J])
{
    int index,min=1000;
    int count = 0;
    for(int i=0;i<len;i++)
    {
        if(A[i].cost<min)
        {
            index = i;
            min = A[i].cost;
        }
        else if(A[i].cost==min)
        {
            arr[count++] = i;
        }
    }
    arr[count++] = index;
    for(int i=0;i<count;i++)
    {
        printf("\n\n ASSIGNMENTS : \n");
        for(int j=0;j<P_J; j++)
        {
            printf(" person - %d job - %d cost - %d\n",j+1,A[arr[i]].poss[j]+1,cost_matrix[j][A[arr[i]].poss[j]]);
        }
        printf("\n cost : %d\n",A[arr[i]].cost);
    }
}

void main()
{
    int P_J;
    printf("\nenter the no. of jobs and persons : ");
    scanf("%d",&P_J);
    int cost_matrix[P_J][P_J];
    
    printf("\n fill the below matrix : ");
    printf("\n      ");
    int matrix[P_J];
    for(int i=0;i<P_J;i++)
    {
        printf("    JOB-%d ",i+1);
        matrix[i] = i+1;
    }
    for(int i=0;i<P_J;i++)
    {
        printf("\nPERSON-%d  ",i+1);
        for(int j=0;j<P_J;j++)
        {
            scanf("%d",&cost_matrix[i][j]);
        }
    }
    int len = fact(P_J);
    printf("\n%d\n",len);
    struct ALL_POSSIBILITIES A[len];
    permute(P_J,cost_matrix,0,P_J-1,A,matrix);
    int ch, arr[len];
    while(1)
    {
        printf("\n1.ALL ASSIGNMENTS WITH COST\n2.MIN_COST_ASSIGNMENT\npress any number to exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                ALL(A,len,P_J,cost_matrix);
                break;
            case 2:
                MIN(A,len,P_J,arr,cost_matrix);
                break;
            default:
                return;
                break;
        }
    }

}
