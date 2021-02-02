#include<stdio.h>
#include<stdbool.h>
#include<errno.h>
#include<stdbool.h>

struct node
{
    int data;
    struct node* prelink;
    struct node* nextlink;
};

void append(struct node**root)
{
    struct node* temp,*p;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("\nenter the data : ");
    scanf("%d",&temp->data);
    temp->prelink = NULL;
    temp->nextlink = NULL;
    p = (*root);
    if((*root) == NULL)
    {
        (*root) = temp;
    }
    else
    {
        while(p->nextlink!=NULL)
        {
            p = p->nextlink;
        }
        p->nextlink = temp;
        temp->prelink = p;
    }
}

void display(struct node**root)
{
    struct node* temp = (*root) ;
    printf("\n");
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->nextlink;
    }
}

void length(struct node**root,int *len)
{

}

void add_at_begin(struct node**root)
{

}

void add_at_after(struct node**root)
{

}

void delete_node(struct node**root)
{

}

void delete_value(struct node**root)
{

}

void reverse_list(struct node**root)
{
    if((*root) == NULL)
    {
        printf("\nEMPTY LIST");
    }
    else
    {
        struct node *temp = (*root);
        while(temp->nextlink!=NULL)
        {
            temp = temp->nextlink;
        }
        printf("\n");
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp = temp->prelink;
        }
        printf("\n");
    }
}

void swap_two_node(struct node**root)
{

}

void swap_two_nodes(struct node**root)
{
    if((*root) == NULL)
    {
        printf("\nempty list");
    }
    else
    {
        int choose = 3,i=1;
        struct node *p = (*root),*q;
        while(i<3)
        {
            p = p->nextlink;
            i++;
        }
         q = p->nextlink;
         int temp;
         temp = q->nextlink->prelink;
         q->nextlink->prelink = p->prelink->nextlink;
         p->prelink->nextlink = temp;
         temp = q->nextlink;
         q->nextlink = q->prelink;
         q->prelink = p->prelink;
         p->prelink = p->nextlink;
         p->nextlink = temp;
    }
}

void sort_elements(struct node**root)
{

}

void main()
{
    struct node *root = NULL;
    int choice,len=0;
    while(1)
    {
        printf("\nMENU : \n");
        printf("1.append\n");
        printf("2.add_at_begin\n");
        printf("3.add_at_after\n");
        printf("4.delete_node\n");
        printf("5.display\n");
        printf("6.length\n");
        printf("7.reverse_list\n");
        printf("8.swap_two_nodes\n");
        printf("9.sort_elements\n");
        printf("10.delete value\n");
        printf("11.exit\n\n");
        printf("ENTER YOUR CHOICE : ");
        scanf("%d",&choice);
        printf("\n");
        switch(choice)
        {
        case 1:
            append(&root);
            break;
        case 2:
            add_at_begin(&root);
            break;
        case 3:
            add_at_after(&root);
            break;
        case 4:
            delete_node(&root);
            break;
        case 5:
            display(&root);
            break;
        case 6:
            length(&root,&len);
            printf("\n LENGTH OF LIST IS : %d\n",len);
            break;
        case 7:
            reverse_list(&root);
            break;
        case 8:
            swap_two_nodes(&root);
            break;
        case 9:
            sort_elements(&root);
            break;
        case 10:
            delete_value(&root);
            break;
        case 11:
            exit(1);
            break;
        default:
            printf("\ninvalid choice");
            break;
        }
    }
}
