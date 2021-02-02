#include<stdio.h>

struct node
{
    int data;
    struct node* prelink;
    struct node* nextlink;
};

struct node* root = NULL;

void append()
{
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("\nenter the data : ");
    scanf("%d",&temp->data);
    temp->nextlink = NULL;
    temp->prelink = NULL;
    if(root == NULL)
    {
        root = temp;
    }
    else
    {
        struct node*p;
        p = root;
        while(p->nextlink!=NULL)
        {
            p = p->nextlink;
        }
        temp->prelink = p;
        p->nextlink = temp;
    }
}
void display()
{
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp = root;
    printf("\n");
    while(temp!= NULL)
    {
        printf("%d ",temp->data);
        temp = temp->nextlink;
    }
    printf("\n");
    //temp->nextlink = 1;
    //printf("%d",temp->nextlink);

}
int length()
{
    struct node* temp;
    temp = root;
    int count = 0;
    while(temp!=NULL)
    {
        count++;
        temp = temp->nextlink;
    }
    return count;
}
void add_at_begin()
{
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("\nenter the data : ");
    scanf("%d",&temp->data);
    temp->nextlink = root;
    temp->prelink = NULL;
    root = temp;

}
void add_at_after()
{
    struct node* temp,*p;
    if(root ==NULL)
    {
        printf("\nLIST IS EMPTY");
    }
    else
    {
        int loc,i=1;
        printf("\nenter the location : ");
        scanf("%d",&loc);
        if(loc > length() || loc<1)
        {
            printf("\nINVALID LOCATION");
        }
        else
        {
            temp = root;
            while(i<loc)
            {
                temp = temp->nextlink;
                i++;
            }
            p = (struct node*)malloc(sizeof(struct node));
            printf("\nenter the data : ");
            scanf("%d",&p->data);
            p->nextlink = temp->nextlink;
            p->prelink = temp;
            temp->nextlink = p;
        }
    }



}


void last()
{
    struct node* temp;
            temp = root;
            while(temp->nextlink!=NULL)
            {
                temp = temp->nextlink;
            }
            temp->prelink->nextlink = NULL;
            temp->prelink = NULL;
            free(temp);
}

void first()
{
    struct node* temp;
    temp = root;
    root = temp->nextlink;
    temp->nextlink = NULL;
    free(temp);
}


void loc()
{
    struct node* temp;
    temp = root;
    int loca,i=1;
    printf("\nenter loc : ");
    scanf("%d",&loca);
    if(loca > length() || loca<1 )
    {
        printf("\nINVALID LOCATION");
    }
    else
    {
        if(loca == 1)
        {
            first();
        }
        else if (loca == length())
        {
            last();
        }
        else
        {
            while(i<loca)
            {
                temp = temp->nextlink;
                i++;
            }
            temp->prelink->nextlink = temp->nextlink;
            temp->nextlink->prelink = temp->prelink;
            temp->nextlink = NULL;
            temp->prelink = NULL;
            printf("\n %d ELEMENT IS DELETED AT LOC %d",temp->data,loca);
            free(temp);
        }
    }
}

void delete_node()
{
    if(root == NULL)
    {
        printf("\nlist is empty");
    }
    else
    {
        int option;
        printf("\n1.enter location\n2.last element\n3.first element\nothers to exit");
        scanf("%d",&option);
        switch(option)
        {
        case 1:
            loc();
            break;
        case 2:
            last();
            break;
        case 3:
            first();
            break;
        default:
            break;
        }
    }
}
void delete_value()
{

}

void reverse_list()
{

}
void swap_two_node()
{

}
void swap_two_nodes()
{

}
void sort_elements()
{

}
void main()
{
    int choice,len;
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
            append();
            break;
        case 2:
            add_at_begin();
            break;
        case 3:
            add_at_after();
            break;
        case 4:
            delete_node();
            break;
        case 5:
            display();
            break;
        case 6:
            len = length();
            printf("\n LENGTH OF LIST IS : %d\n",len);
            break;
        case 7:
            reverse_list();
            break;
        case 8:
            swap_two_nodes();
            break;
        case 9:
            sort_elements();
            break;
        case 10:
            delete_value();
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

