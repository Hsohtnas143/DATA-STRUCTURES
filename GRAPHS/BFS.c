#include<stdio.h>
int front =0;
int rear = 0;
int k=0;
int n=6;
int enqueue(int queue[n],int val)
{
    
    if(rear<n)
    {
        queue[rear] = val;
        rear++;
    }
    
}

int dequeue(int queue[n])
{
    if(rear>-1)
    {
        for(int i=front;i<rear;i++)
        {
            queue[i] = queue[i+1];
        }
        rear--;
    }
    
}

int check_visited(int visited_list[n],int val)
{
    for(int i=0;i<n;i++)
    {
        if(visited_list[i] == val)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    
}

int check_queue(int val,int queue[rear])
{
    for(int i=0;i<=rear;i++)
    {
        if(queue[i] == val)
        {
            return 1;
        }
        else 
        {
            return 0;
        }
    }
}

int main()
{
    int n=6;
    int adj_matrix[][6] = {{0,1,1,0,0,1},{1,0,0,1,1,0},{1,0,0,0,1,0},{0,1,0,0,0,1},{0,1,1,0,0,1},{1,0,0,1,1,0}};
    //BFS
    int visited_list[6]={0,0,0,0,0,0};
    int queue[n];
    enqueue(queue,1);
    visited_list[1-1] = 1;
    int i=0,val;
    int a,b;
    while(i<n)
    {
        val = queue[front];
        for(int j=1;j<n+1;j++)
        {
            if(adj_matrix[val-1][j-1] == 1)
            {
                a = check_visited(visited_list,j);
                b = check_queue(j,queue);
                if(a==0 && b==0)
                {
                    enqueue(queue,j);
                    visited_list[j-1] = 1;
                }
                
            }
        }
        printf("%d ",queue[front]);
        dequeue(queue);
        i++;
    }
    
    
}
