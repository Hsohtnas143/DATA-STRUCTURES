#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct point
{
    float x,y;
};

void quickSort(struct point p[],int left,int right,int decide)
{
    if(decide == 0)
    {
        float pivot = p[left].x;
        int k = left;
        for(int i=left+1;i<right;i++)
        {
            if(pivot > p[i].x)
            {
                k++;
                struct point temp = p[i];
                p[i] = p[k];
                p[k] = temp;
            }
        }
        struct point temp = p[left];
        p[left] = p[k];
        p[k] = temp;
        if(k-1 >= left)
        {
            quickSort(p,left,k-1,1);
        }
        else if(k+1<= right)
        {
            quickSort(p,k+1,right,1);
        }
    }
    else if(decide == 1)
    {
        float pivot = p[left].y;
        int k = left;
        for(int i=left+1;i<right;i++)
        {
            if(pivot > p[i].y)
            {
                k++;
                struct point temp = p[i];
                p[i] = p[k];
                p[k] = temp;
            }
        }
        struct point temp = p[left];
        p[left] = p[k];
        p[k] = temp;
        if(k-1 >= left)
        {
            quickSort(p,left,k-1,1);
        }
        else if(k+1<= right)
        {
            quickSort(p,k+1,right,1);
        }
    }
}


void sort_x(struct point p[], int n)
{
    quickSort(p,0,n,0);
}

void sort_y(struct point p[], int n)
{
    quickSort(p,0,n,1);
}


float BRUTE(struct point p[],int left,int right)
{
    double min = INFINITY;
    float d;
    for(int i=left;i<right;i++)
        {
            for(int j=i+1;j<=right;j++)
            {
                d = sqrt(pow(p[j].x - p[i].x , 2)+pow(p[j].y - p[i].y ,2));

        printf("\n d : %f\n",d);
                if(d<min)
                {
                    min = d;
                }
            }
        }
        printf("\n min : %f\n",min);
        return min;
}

float divideConqor(struct point p[],int left,int right)
{
    if((right-left) <= 3)
    {
        printf("\n left = %d right = %d\n",left,right);
        return BRUTE(p,left,right);
        
    }
    int mid = (left+right)/2;
    struct point midPoint = p[mid];
    
    float dl =  divideConqor(p,left,mid);
    float dr =  divideConqor(p,mid+1,right);

    float d = dl>dr?dr:dl;

    struct point strip[right-left];
    int j = 0;
    for(int i=left; i<=right;i++)
    {
        if(fabsf(p[i].x - midPoint.x) <d)
        {
            strip[j++] = p[i];
        }
    }
    
    sort_y(strip,j);

    
    float d1 = BRUTE(strip,0,j);
    return d>d1?d1:d;
}

int main()
{
    int n = 6;
    // printf("\nEnter the no. of points : ");
    // scanf("%d",&n);
    //struct point p[n];
    struct point p[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    
    // for(int i=0;i<n;i++)
    // {
    //     printf("\nEnter x and y for %d : ",i+1);
    //     scanf("%f",&p[i].x);
    //     scanf("%f",&p[i].y);
    // }
    sort_x(p,n);
    float q = divideConqor(p,0,n-1);
    printf("\n f = %f",q);
    return 0;
}