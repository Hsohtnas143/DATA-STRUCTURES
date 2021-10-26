#include <stdio.h>
#include<stdlib.h>
struct queue
{
    int arr[100];
    int rear;
};
void enqueue(struct queue *q, int ele)
{
    q->arr[(q->rear)++] = ele;
    printf("\nele %d\n",ele);
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
   int visited[7];
    for(int i=0;i<n;i++)
    {
        visited[i] = 0;
    }
    enqueue(&q,index1);
    visited[index1] = 1;
    while(q.rear!=0)
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
    int n = 7;
    int graph[7][7] = {
{0, -1, -1, 4, 0, 0, 0, },
{-1, 0, 0, 0, 0, 6, 0, },
{-1, 0, 0, -1, -1, 0, 0, },
{4, 0, -1, 0, 0, 8, 0, },
{0, 0, -1, 0, 0, 7, 9, },
{0, 6, 0, 8, 7, 0, 0, },
{0, 0, 0, 0, 9, 0, 0, }

    };
    int val = cycle(n, graph, 0, 3);
    printf("\nval = %d\n", val);
    return 0;
}