#include<stdio.h>
#include<stdlib.h>


// distance between cities
struct Cities
{
    int city1;
    int city2;
    struct Cities *rchild;
    int distance;
};




// distance of paths
struct Distances
{
    int index[100];
    int distance;
    struct Distances *rchild;
};




//initiazing
struct Cities *root = NULL;
struct Distances *root1 = NULL;



int return_distance(int a, int b)
{
    struct Cities * temp = root;
    while(temp!=NULL)
    {
        if(temp->city1 == a && temp->city2==b)
            return temp->distance;
        else if(temp->city1 == b && temp->city2==a)
            return temp->distance;
        else
            temp = temp->rchild;
    }
}



//combinations of cities of size 2
void combinations(int a[], int print[], int start, int end, int index, int r)
{
    if(index==r)
    {
        struct Cities *C;
        C = (struct Cities*)malloc(sizeof(struct Cities));
        C->city1 = print[0];
        C->city2 = print[1];
        C->rchild = NULL;
        if(root==NULL)
        {
            root = C;
        }
        else
        {
            struct Cities *temp=root;
            while(temp->rchild!=NULL)
                temp = temp->rchild;
            temp->rchild = C;
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



//permutations

void swap(int a[],int i,int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
void permute(int a[], int l, int r, int length)
{
    if(l==r)
    {
        struct Distances *D;
        D = (struct Distances*)malloc(sizeof(struct Distances));
        D->rchild = NULL;
        int count = 1;
        int sum =0;
        D->index[0] = 0;
        printf("\n");
        sum = return_distance(0,a[0]);
        for(int j=0;j<length-1;j++)
        {
            sum+=return_distance(a[j],a[j+1]);
            D->index[count++] = a[j];
        }
        sum = sum + return_distance(0,a[length-1]);
        D->distance = sum;
        D->index[count++] = a[length-1];
        D->index[count++] = 0;
        if(root1 == NULL)
        {
            root1 = D;
        }
        else
        {
            struct Distances *temp=root1;
            while(temp->rchild!=NULL)
                temp = temp->rchild;
            temp->rchild = D;
        }
    }
    else
    {
        for(int i=l;i<=r;i++)
        {
            swap(a,i,l);
            permute(a,l+1,r,length);
            swap(a,i,l);
        }
    }
}


void paths(int n, char city_names[][1000])
{
    struct Distances*temp1;
    temp1 = root1;
    printf("\n");
    while(temp1!=NULL)
    {
        for(int i=0;i<n+1;i++)
        {
            printf("%s-> ",city_names[temp1->index[i]]);
        }
        printf("%d",temp1->distance);
        printf("\n");
        temp1 = temp1->rchild;
    }
}


void min_distance(int n, char city_names[][1000])
{
    struct Distances *temp1 = root1;
    printf("\n minimum distance is : ");
    temp1 = root1;
    int min = 99999;
    struct Distances * p_index[100],*p;
    int count = 0;
    while(temp1!=NULL)
    {
        if(temp1->distance<min)
        {
            p= temp1;
            min = temp1->distance;
        }
        else if(min==temp1->distance)
        {
            p_index[count++] = temp1;
        }
        temp1 = temp1->rchild;
    }
    p_index[count] = p;
    for(int i=0;i<=count;i++)
    {
        p = p_index[i];
        for(int j=0;j<n+1;j++)
        {
            printf("%s-> ",city_names[p->index[j]]);
        }
        printf("%d",p->distance);
        printf("\n");
        
    }
}


void main()
{
    int n;
    a:printf("\nenter the no of cities : ");
    scanf("%d",&n);
    if(n<2)
    {
        printf("\n enter greater than 1 :");
        goto a;
    }
    char city_names[n][1000];
    for(int i=0;i<n;i++)
    {
        printf("\nenter the city no. %d : ",i+1);
        scanf("%s",city_names[i]);
    }
 
    // taking indexes of cities for combinations
    int a[n];
    for(int i=0;i<n;i++)
    {
        a[i] = i;
    }
    int print[2];
    combinations(a,print,0,n-1,0,2);
    struct Cities *temp = root;
    while(temp!=NULL)
    {
        printf("\n enter the distance between %s and %s : ",city_names[temp->city1],city_names[temp->city2]);
        scanf("%d",&temp->distance);
        temp = temp->rchild;
    }

    int len1 = n-1;
    int b[len1];
    for(int i=0;i<len1;i++)
    {
        b[i] = i+1;
    }
    
    
    permute(b, 0, len1-1,len1);
    int ch;
    b:printf("\n1. min_distance 2.all_paths any key to exit\n");
    scanf("%d",&ch);
    if(ch==1)
    {
        min_distance(n,city_names);
        goto b;
    }
    else if(ch==2)
    {
        paths(n,city_names);
        goto b;
    }
    return;
    

    
}
