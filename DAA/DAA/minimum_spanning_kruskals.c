//KRUSKALS
#include <stdio.h>
#include <math.h>
#include<stdlib.h>
struct queue
{
    int arr[100];
    int rear;
};
void enqueue(struct queue *q, int ele)
{
    q->arr[(q->rear)++] = ele;
}
void dequeue(struct queue *q)
{
    for(int i=0;i<(q->rear)-1;i++)
    {
        q->arr[i] = q->arr[i+1];
    }
    (q->rear)--;
}
int cycle(int n, int graph[n][n], int index1, int index2)
{
    struct queue q;
    q.rear = 0;
    int visited[n];
    for(int i=0;i<n;i++)
    {
        visited[i] = 0;
    }
    enqueue(&q,index1);
    visited[index1] = 1;
    while(q.rear)
    {
        for(int i = 0;i<n;i++)
        {
            if(graph[q.arr[0]][i]==-1 && visited[i]==0)
            {
                if(i == index2)
                {
                    return 0;
                }
                else
                {
                    enqueue(&q,i);
                    visited[i] = 1;
                }
            }
        }
        dequeue(&q);
    }
    return 1;
}
int main()
{
    int n;
    printf("\nEnter the no. of vertices : ");
    scanf("%d",&n);
    int graph[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            graph[i][j] = 0;
        }
    }
    int connections,index,weight;
    for(int i=0;i<n;i++)
    {
        printf("\nEnter the connections for %d :",i);
        scanf("%d",&connections);
        for(int j=0;j<connections;j++)
        {
            printf("\nEnter %d to :",i);
            scanf("%d",&index);
            printf("\nweight : ");
            scanf("%d",&weight);
            graph[i][index] = weight;
            graph[index][i] = weight;
        }
    }
    // int n = 7;
    // int graph[7][7] = {
    //     {0,5,1,4,0,0,0},
    //     {5,0,0,0,0,6,0},
    //     {1,0,0,3,2,0,0},
    //     {4,0,3,0,0,8,0},
    //     {0,0,2,0,0,7,9},
    //     {0,6,0,8,7,0,0},
    //     {0,0,0,0,9,0,0}
    //     };

    double min = INFINITY;
    int sum = 0;
    int index1, index2;
    int count = 0;
    int flag = 0;
    while (count != n - 1)
    {
        min = INFINITY;
        flag = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if ((graph[i][j] != 0) && (graph[i][j] < min) && (graph[i][j] != -1) && (cycle(n, graph, i, j)))
                {
                    min = graph[i][j];
                    index1 = i;
                    index2 = j;
                    flag = 1;
                }
            }
        }
        if (flag == 1)
        {
            sum += graph[index1][index2];
            for (int i = 0; i < n; i++)
            {
                printf("\n{");
                for (int j = 0; j < n; j++)
                {
                    printf("%d, ", graph[i][j]);
                }
                printf("},");
            }
            printf("\n index1 = %d index2 = %d value = %d  %d\n", index1, index2, graph[index1][index2], cycle(n, graph, index1, index2));
            if (graph[index1][index2] != -1)
            {
                graph[index1][index2] = -1;
                graph[index2][index1] = -1;
                count++;
            }
        }
    }
    printf("%d", sum);
}