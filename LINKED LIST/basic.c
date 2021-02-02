#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* link;
};
struct node *root = NULL;

void append()
{
    struct node* temp,*p;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("\nenter the data : ");
    scanf("%d",&temp->data);
    temp->link = NULL;
    if(root == NULL)
    {
        root = temp;
    }
    else
    {
        p = root;
        while(p->link!=NULL)
        {
            p = p->link;
        }
        p->link = temp;
    }
}
int length()
{
    int count = 0;
    struct node* temp;
    temp = root;
    if(temp == NULL)
    {
        return count;
    }
    else
    {
        while(temp!=NULL)
        {
            count++;
            temp = temp->link;
        }
        return count;
    }
}

void add_at_begin()
{
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("\nenter the data : ");
    scanf("%d",&temp->data);
    if(root == NULL)
    {
        root = temp;
        temp->link = NULL;
    }
    else
    {
        temp->link = root;
        root = temp;
    }
}

void add_at_after()
{
    int i = 1;
    struct node* temp,*p;
    int loc;
    if (root == NULL)
    {
        printf("\nLIST IS EMPTY\n");
    }
    else
    {
        printf("\nenter the location : ");
        scanf("%d",&loc);
        if(loc > length() || loc <= 0)
        {
            printf("\nINVALID LOCATION ");
        }
        else
        {
            p = root;
            while(i<loc)
            {
                p = p->link;
                i++;
            }
            temp = (struct node*)malloc(sizeof(struct node));
            printf("\nenter the data : ");
            scanf("%d",&temp->data);
            temp->link = p->link;
            p->link = temp;

        }
    }

}

void delete_node()
{
    if(root == NULL)
    {
        printf("\nLIST IS EMPTY\n");
    }
    else
    {
        struct node* temp;
    int loc;
    printf("\nenter the location to delete : ");
    scanf("%d",&loc);

    if(loc>length() || loc <=0)
    {
        printf("\nINVALID LOCATION");
    }
    else if(loc == 1)
    {
        temp = root;
        root = temp->link;
        temp->link = NULL;
        free(temp);
    }
    else
    {
        struct node* p = root,*q;
        int i = 1;
        while(i<loc-1)
        {
            p = p->link;
            i++;
        }
        q = p->link;
        p->link = q->link;
        q->link = NULL;
        free(q);
    }
    }

}

void display()
{
    struct node* temp;
    temp = root;
    if( temp == NULL)
    {
        printf("\nLIST IS EMPTY\n");
    }
    else
    {

        while(temp!=NULL)
        {
            printf("%d-->",temp->data);
            temp = temp->link;
        }
    }
}



void swap_two_nodes()
{
    if(root == NULL)
    {
        printf("\nLIST IS EMPTY\n");
    }
    else
    {
        int l;
        printf("\nenter adjacent nodes : ");
        scanf("%d",&l);
        struct node* p,*q,*r;
        p = (struct node*)malloc(sizeof(struct node));
        p = root;
        int i= 1;
        while(i<l-1)
        {
            p = p->link;
            i++;
        }
        q = p->link;
        r = q->link;
        q->link = r->link;
        r->link = q;
        p->link = r;
    }

}

void swap_two_node(int l)
{
    struct node* p,*q,*r;
    p = (struct node*)malloc(sizeof(struct node));
    p = root;
    int i= 1;
    while(i<l)
    {
        p = p->link;
        i++;
    }
    int temp = p->data;
    p->data = p->link->data;
    p->link->data = temp;
}

void sort_elements()
{
    if(root == NULL)
    {
        printf("\nLIST IS EMPTY\n");
    }
    else
    {
        struct node* temp;
        temp = (struct node*)malloc(sizeof(struct node));
        int i,j;
        for(i = 0; i<length()-1; i++)
        {
            int count =0;
            temp = root;
            for(j = 0; j<length()-1-i; j++)
            {
                count++;
                if(temp->data > temp->link->data)
                {
                    swap_two_node(count);
                }
                temp = temp->link;
            }
        }
    }

}
void delete_value()
{
    if(root == NULL)
    {
        printf("\nLIST IS EMPTY\n");
    }
    else
    {
        int value;
        printf("\nenter the value to be deleted : ");
        scanf("%d",&value);
        struct node* temp;
        temp = (struct node*)malloc(sizeof(struct node));
        temp = root;
        int f=0,count = 1;
        int l = length();
        while(l--)
        {
            if(temp->data == value)
            {
                f=1;
                break;
            }
            else
            {
                temp = temp->link;
                count++;
            }

        }
        if(f==1)
        {
            struct node* p;
            p = (struct node*)malloc(sizeof(struct node));
            if(temp == root)
            {
                temp = root;
                root = temp->link;
                temp->link = NULL;
                free(temp);
            }
            else
            {
                p = root;
                while(p->link != temp)
                {
                    p = p->link;
                }
                p->link = temp->link;
                temp->link = NULL;
                free(temp);
                printf("\n value %d is deleted at node %d ",value,count);
            }

        }
        else
        {
            printf("\nvalue not found");
        }
    }
}

void reverse_list()
{
    if(root == NULL)
    {
        printf("\nLIST IS EMPTY\n");
    }
    else
    {
        struct node *p,*temp = root;
        int len = length();
        int i = 1,k;
        while(i<len)
        {
            k =1;
            p = root;
            while(k<len)
            {
                p = p->link;
                k++;
            }
            int temp1 = temp->data;
            temp->data = p->data;
            p->data = temp1;
            temp = temp->link;
            len--;
            i++;
        }

    }
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
        default:
            printf("\ninvalid choice");
        }
    }
}
