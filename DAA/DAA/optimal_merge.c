#include <stdio.h>
struct priority_queue
{
    int arr[100];
    int front;
    int rear;
};

void enqueue(int ele, struct priority_queue *q)
{
    int index = q->rear;
    int flag = 0;
    for (int i = 0; i < q->rear; i++)
    {
        if (q->arr[i] < ele)
        {
            index = i;
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        (q->rear)++;
        for (int i = q->rear - 1; i > index; i--)
        {
            q->arr[i] = q->arr[i - 1];
        }
        q->arr[index] = ele;
    }
    else
    {
        q->arr[(index)] = ele;
        (q->rear)++;
    }
}
int dequeue(struct priority_queue *q)
{
    if(q->rear==0)
    {
        return 0;
    }
    (q->rear)--;
    return q->arr[(q->rear)];
}

int main()
{
    int n = 6;
    int list[6] = {2, 3, 4, 5, 6, 7};
    struct priority_queue q;
    q.front = 0;
    q.rear = 0;
    for (int i = 0; i < n; i++)
    {
        enqueue(list[i], &q);
    }
    int sum = 0,sum1=0,sum3=0;
    while(1)
    {
        sum = dequeue(&q);
        sum1 = dequeue(&q);
        if(sum+sum1 == sum)
        {
            break;
        }
        else
        {
            sum = sum+sum1;
            sum3 = sum3+sum;
            enqueue(sum,&q);
            //printf("\n%d\n",sum);
        }
        
    }
    printf("\n%d\n",sum3);

    return 0;
}