#include<stdio.h>
#include<math.h>
struct Point
{
    float x,y;
};

int check(int print[],int count,int j)
{
    int f=0;
    for(int i=0;i<count;i++)
    {
        if(print[i] == j)
        {
            f=1;
            break;
        }
    }
    return f;
}

void print_(struct Point p[], int print[],int count)
{
    printf("\npoints are : ");
    int j=0;
    for(int i=0;i<count;i++)
    {
        j = print[i];
        printf("(%.1f,%.1f)\n ",p[j].x,p[j].y);
    }
}

int CONVEX_HULL(struct Point p[], int len, int print[])
{
    float line1,line2;
    int left,right,i,j,k,flag,c=1,count=0;
    for(i=0;i<len-1;i++)
    {
        for(j=i+1;j<len;j++)
        {
            flag=0;
            left=0;
            right=0;
            for(k=0;k<len;k++)
            {
                if(k==i || k==j)
                {
                    continue;   
                }
                line1 = (((p[j].y-p[i].y)/(p[j].x-p[i].x))*(p[k].x-p[i].x))+p[i].y;
                if(line1>p[k].y)
                {
                    right++;
                }
                else if(line1<p[k].y)
                {
                    left++;
                }
                if(left>0 && right>0)
                {
                    flag=1;
                    break;
                    
                }
            }
            if(flag==0)
            {
                c=1;
                c = check(print,count,i);
                if(c==0)
                {
                    print[count++] = i;
                    c=1;
                }
                c = check(print,count,j);
                if(c==0)
                {
                    print[count++] = j;
                    c=1;
                }
            }
        }
    }
    return count;
}

void main()
{
    struct Point p[] = {{1, 2},{4, 3},{3, 7},{6, 1},{7, 9},{5, 6},{8, 8.5},{9, 9.5},{2.4, 6.3}};
    int len = sizeof(p)/sizeof(struct Point);
    int print[len];
    int count;
    count = CONVEX_HULL(p,len,print);
    print_(p,print,count);
}
