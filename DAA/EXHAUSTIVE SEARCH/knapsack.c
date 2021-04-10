#include<stdio.h>
#include<math.h>
struct items
{
    int item_number;
    int value;
    int weight;
};

struct table
{
    int item_numbers[100];
    int length;
    int values;
    int weights;
};
int count=0;

void combinations(struct items a[], int print[], int start, int end, int index, int r,struct table t[])
{
    if(index==r)
    {
        int val=0;
        int weigh = 0;
        if(index==0)
        {
            t[count].item_numbers[0] = 0;
            t[count].weights = 0;
            t[count].values = 0;
            //printf("ϕ");
            count++;
            return;
        }
        for(int j=0;j<r;j++)
        {
            t[count].item_numbers[j] = print[j];
            val+=a[print[j]-1].value;
            weigh+=a[print[j]-1].weight;
            //printf("%d",print[j]);
        }
        t[count].values = val;
        t[count].weights = weigh;
        t[count].length = r;
        count++;
        return;
    }
    else
    {
        for(int i = start; i<=end && end-i+1>= r-index;i++)
        {
            print[index] = a[i].item_number;
            combinations(a,print,i+1,end,index+1,r,t);
        }
    }
}

void subsets(struct items I[], int length,struct table t[],int n)
{
    
    for(int i=0;i<=length;i++)
    {
        int print[i+1];
        combinations(I,print,0,length-1,0,i,t);
    }
    
}


void print_all(struct table t[], int length, int decider, int W)
{
    for(int i=0;i<length;i++)
    {
        printf("\n\n pairs : {");
        for(int j=0;j<t[i].length;j++)
        {
            printf("%d",t[i].item_numbers[j]);
            if(!(j+1==t[i].length))
                printf(", ");
                
        }
        if(i==0)
        {
            printf("ϕ");
        }
        printf("}\n weights : %d",t[i].weights);
        if(decider==1 && W<t[i].weights)
            printf("\n not feasible");
        else
            printf("\n values : $%d ",t[i].values);
        
        
    }
}

void print_max(struct table t[], int length, int W)
{
    int val = 0,index=-1;
    for(int i=0;i<length;i++)
    {
        if(t[i].weights <= W && t[i].values >=val)
        {
            index = i;
            val = t[i].values;
        }
    }
    printf("\n pairs : {");
    for(int j=0;j<t[index].length;j++)
    {
        printf("%d",t[index].item_numbers[j]);
        if(!(j+1==t[index].length))
            printf(", ");
    }
    if(index!=-1)
        printf("}\n\n the maximum value: $%d \nweigth is %d ",t[index].values,t[index].weights);
    else
        printf("\n not exits");
}

void Knapsack(struct items I[], int n, int W)
{
    int length = pow(2,n);
    struct table t[length];
    subsets(I,n,t,length);
    int ch,i,j=1;
    while(j)
    {
        printf("\n\n 1.print all possibilities\n2.print maximum feasible value\n3.print feasible values\npress any key to exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                i=0;
                print_all(t,length,i,W);
                break;
            case 2:
                print_max(t,length,W);
                break;
            case 3:
                i=1;
                print_all(t,length,i,W);
                break;
            default:
                j=0;
                break;
        }
    }
    
    
    
}

void main()
{
    printf("\nenter the number of items : ");
    int n;
    scanf("%d",&n);
    struct items I[n];
    for(int i=0;i<n;i++)
    {
        I[i].item_number = i+1;
        printf("\n enter the value of item_number %d : ",i+1);
        scanf("%d",&I[i].value);
        printf("\n weight of item_number %d : ",i+1);
        scanf("%d",&I[i].weight);
    }
    printf("\n\n PROVIDE THE WEIGHT : ");
    int W;
    scanf("%d",&W);
    Knapsack(I,n,W);
    
}
