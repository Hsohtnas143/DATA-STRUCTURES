#include<stdio.h>
#include<math.h>
struct Point
{
    float x,y;
};
float distance(int i,int j,struct Point p[])
{
    return sqrt( (pow((p[j].x - p[i].x),2)) + (pow((p[j].y - p[i].y),2)) );
}
void main()
{
    struct Point p[] = {{1, 2},{3, 4},{3, 7},{1, 6},{9, 7},{5, 6},{8, 8.5},{9, 9.5},{2.4, 6.3}};
    int len = sizeof(p)/sizeof(struct Point);
    float min=10000,d;
    int index1=-1,index2=-1;
    for(int i=0;i<len-1;i++)
    {
        for(int j=i+1;j<len;j++)
        {
            d = distance(i,j,p);
            if(d<min)
            {
                min = d;
                index1 = i;
                index2 = j;
            }
        }
    }
    printf("%d %d\n",index1,index2);
    printf("{%.2f, %.2f},{%.2f, %.2f}",p[index1].x,p[index1].y,p[index2].x,p[index2].y);
    printf("\nand the distance is : %f",min);
}
