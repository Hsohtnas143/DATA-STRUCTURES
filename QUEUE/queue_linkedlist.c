#include<stdio.h>
#include<stdlib.h>
int front=0;
int rear = 0;
int max=5;
struct node
{
  int data;
  struct node* link;
};

struct node* root = NULL;

void insert()
{
    if(rear == max)
    {
        printf("\nqueue is full");
    }
    else
    {
        struct node* temp;
        temp = (struct node*)malloc(sizeof(struct node));
        temp->link = NULL;
        printf("\nenter the element : ");
        scanf("%d",&temp->data);
        if(root == NULL)
        {
            root = temp;
            rear++;
        }
        else
        {
            struct node *temp1,*p;
            temp1 = root;
            while(temp1!=NULL)
            {
                p = temp1;
                temp1 = temp1->link;
            }
            p->link = temp;
            rear++;
        }
    }
}

int pop()
{
    if(rear>0)
    {
        struct node* temp = root;
        root = temp->link;
        free(temp);
        rear--;
        
    }
    else
    {
        printf("\nno elements to pop");
    }
}

int display()
{
    if(rear)
    {
        struct node*temp = root;
        printf("\n");
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp = temp->link;
        }
        printf("\n");
    }
    else
    {
        printf("\nno elements");
    }
}

int main()
{
    int i=1,choice;
    printf("\nQUEUE\n");
    while(i)
    {
        printf("\nMenu\n1.insert\n2.pop\n3.Display items\nothers to exit");
        printf("\nEnter ur choice : ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
            insert();
            break;
            case 2:
            pop();
            break;
            case 3:
            display();
            break;
            default:
            i=0;
            break;
        }
    }
}
