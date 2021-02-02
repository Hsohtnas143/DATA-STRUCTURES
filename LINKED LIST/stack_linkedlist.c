#include<stdio.h>

struct node
{
    int data;
    struct node* link;
};
void insert_node_in_stack(struct node** top)
{
    struct node *temp;
    (temp) = (struct node*)malloc(sizeof(struct node));
    int ele;
    printf("\nenter the data : ");
    scanf("%d",&ele);
    temp->link = (*top);
    temp->data = ele;
    (*top) = temp;

}

void pop_node(struct node** top)
{
    if((*top) == NULL)
    {
        printf("\nEMPTY\n");
    }
    else
    {
        struct node *temp;
        (temp) = (struct node*)malloc(sizeof(struct node));
        temp = (*top);
        printf("\npopped value is %d \n",temp->data);
        (*top) = temp->link;
        temp->link = NULL;
        free(temp);
    }

}
void display(struct node** top)
{
    if((*top) == NULL)
    {
        printf("\nEMPTY\n");
    }
    else
    {
        struct node *temp;
        (temp) = (struct node*)malloc(sizeof(struct node));
        temp = (*top);
        printf("\n");
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp = temp->link;
        }
        printf("\n");
    }

}
void main()
{
    struct node *top = NULL;
    while(1)
    {
        printf("\nSTACK\nMENU\n1.INSERT NODE IN STACK\n2.POP NODE\n3.display\nremaining keys for exit\n");
        int choice;
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            insert_node_in_stack(&top);
            break;
        case 2:
            pop_node(&top);
            break;
        case 3:
            display(&top);
            break;
        default:
            exit(0);
            break;
        }
    }

}
