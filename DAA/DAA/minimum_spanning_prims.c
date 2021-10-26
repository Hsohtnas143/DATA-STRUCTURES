//prims
#include<stdio.h>
#include<math.h>
struct queue
{
    int arr[100];
    int front;
};
void enqueue(int ele,struct queue *q)
{
    q->arr[(q->front)++] = ele;
}
int main()
{
    int n = 7;
    int graph[7][7] = {
        {0, 5, 1, 4, 0, 0, 0},
        {5, 0, 0, 8, 0, 6, 0},
        {1, 0, 0, 3, 2, 0, 0},
        {4, 8, 3, 0, 0, 8, 0},
        {0, 0, 2, 0, 0, 7, 9},
        {0, 6, 0, 8, 7, 0, 0},
        {0, 0, 0, 0, 9, 0, 0}
    };
    int visited[7] = {0,0,0,0,0,0,0};
    double min = INFINITY;
    struct queue q;
    q.front = 0;
    int sum = 0;
    int index1 ,index2;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(graph[i][j]!=0 && graph[i][j]<min)
            {
                min = graph[i][j];
                index1 = i;
                index2 = j;
            }
        }
    }
    enqueue(index1,&q);
    enqueue(index2,&q);
    visited[index1] = 1;
    visited[index2] = 1;
    sum+=graph[index1][index2];
    int count = 2;
    int flag = 0;
    while(count!=n)
    {
        min = INFINITY;
        flag = 0;
        for(int i=0;i<q.front;i++)
        {
            for(int j=0;j<n;j++)
            {
                if((graph[q.arr[i]][j] != 0) && (visited[j]!=1) && (graph[q.arr[i]][j]<min))
                {
                    min = graph[q.arr[i]][j];
                    index1 = q.arr[i];
                    index2 = j;
                    flag = 1;
                }
            }
        }
        if(flag == 1)
        {
            enqueue(index2,&q);
            visited[index2] = 1;
            count++;
            sum+=graph[index1][index2];
        }


    }
    printf("\n%d\n",sum);
}