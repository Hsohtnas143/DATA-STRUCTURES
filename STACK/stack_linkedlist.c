#include<stdio.h>
#include<stdlib.h>
int top=0;
int max = 5;
struct node
{
    int ele;
    struct node* link;
};
struct node* root = NULL;

void insert()
{
    if(top!=max)
    {
        struct node* temp,*p;
        temp = (struct node*)malloc(sizeof(struct node));
        printf("\nENTER THE ELEMENT");
        scanf("%d",&temp->ele);
        temp->link = NULL;
        if(root == NULL)
        {
            root = temp;
            top++;
        }
        else
        {
            struct node* temp1;
            temp1 = root;
            while(temp1!= NULL)
            {
                p = temp1;
                temp1 = temp1->link;
                
            }
            p->link = temp;
            top++;
        }
    }
    
}

void pop()
{
    if(top!=0)
    {
        struct node* temp,*p;
        temp = root;
        p = temp;
        while(temp->link!=NULL)
        {
            p = temp;
            temp = temp->link;
            
        }
        p->link = NULL;
        free(temp);
        top--;
    }
    
    
}

void display()
{
    if(root!=NULL){
    struct node* temp;
    temp = root;
    printf("\n");
    //printf("\n%d\n",top);
    int top1 = top;
    while(temp!=NULL)
    {
        printf("%d ",temp->ele);
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
    printf("\nSTACK\n");
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
