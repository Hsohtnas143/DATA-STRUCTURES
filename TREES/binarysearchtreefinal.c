
#include<stdio.h>
struct tnode
{
    int data;
    struct tnode* lchild;
    struct tnode* rchild;
};

struct tnode *root = NULL;

struct tnode *parent;

void insert()
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    printf("\nENTER THE DATA : ");
    scanf("%d",&temp->data);
    temp->lchild = NULL;
    temp->rchild = NULL;
    if(root == NULL)
    {
        root = temp;
    }
    else
    {
        struct tnode* temp1 = root,*p;
        int i=2;
        while(temp1!=NULL)
        {
            if(temp->data > temp1->data)
            {
                p = temp1;
                temp1 = temp1->rchild;
                i=0;
            }
            else if(temp->data <= temp1->data)
            {
                p = temp1;
                temp1 = temp1->lchild;
                i=1;
            }
        }
        if(i==0)
        {
            p->rchild = temp;
        }
        else if(i==1)
        {
            p->lchild = temp;
        }

    }

}


void inorder(struct tnode *t)
{
    if(t->lchild)
        inorder(t->lchild);
    printf("%d ",t->data);
    if(t->rchild)
        inorder(t->rchild);
}

void preorder(struct tnode *t)
{

    printf("%d ",t->data);
    if(t->lchild)
        preorder(t->lchild);
    if(t->rchild)
        preorder(t->rchild);
}

void postorder(struct tnode *t)
{


    if(t->rchild)
        postorder(t->rchild);
    printf("%d ",t->data);
    if(t->lchild)
        postorder(t->lchild);
}

void display()
{
    if(root == NULL)
    {
        printf("\nempty");
    }
    else
    {
        struct tnode* temp = root;
    inorder(temp);
    printf("\n");
    printf("\n");
    preorder(temp);
    printf("\n");
    printf("\n");
    postorder(temp);
    printf("\n");
    printf("\n");
    }

}

void length()
{
    struct tnode* temp = root,*temp1 = root;
    while(1)
    {

    }
}

int parent1(int j,int ele)
{
    int i=2;
    //struct tnode* temp = root,*temp1=root,*s,*t
    if(ele == root->data)
    {
        parent = root;
        return 5;
    }
        struct tnode* temp1 = root;
        while(temp1!=NULL)
        {
            if(temp1->data < ele)
            {
                parent = temp1;
                temp1 = temp1->rchild;
                i=1;
            }
            else if(temp1->data > ele)
            {
                parent = temp1;
                temp1 = temp1->lchild;
                i=0;
            }
            else if(temp1->data == ele)
            {
                break;
            }
        }
        if(i==1)
        {
            return i;
            //printf("\nright of %d is %d",parent->data,parent->rchild->data);
        }
        else if(i==0)
        {
            return i;
            //printf("\nleft of %d is %d",parent->data,parent->lchild->data);
        }
        else
        {
            return i;
        }

}

struct tnode* parent3;

int parent2(int j,int ele)
{
    int i=2;
    //struct tnode* temp = root,*temp1=root,*s,*t
    if(ele == root->data)
    {
        parent3 = root;
        return 5;
    }
        struct tnode* temp1 = root;
        while(temp1!=NULL)
        {
            if(temp1->data < ele)
            {
                parent3 = temp1;
                temp1 = temp1->rchild;
                i=1;
            }
            else if(temp1->data > ele)
            {
                parent3 = temp1;
                temp1 = temp1->lchild;
                i=0;
            }
            else if(temp1->data == ele)
            {
                break;
            }
        }
        if(i==1)
        {
            return i;
            //printf("\nright of %d is %d",parent->data,parent->rchild->data);
        }
        else if(i==0)
        {
            return i;
            //printf("\nleft of %d is %d",parent->data,parent->lchild->data);
        }
        else
        {
            return i;
        }

}


void onechild(struct tnode* parent, struct tnode* child, int j, int i)
{
    //printf("\n parent%d child %d",parent->data,child->data);

    if(j==0 && i==0)
    {
        parent->lchild = parent->lchild->lchild;
        child->lchild = NULL;
        free(child);
    }
    else if(j==0 && i==1)
    {
        parent->lchild = parent->lchild->rchild;
        child->rchild = NULL;
        free(child);
    }
    else if(j==1 && i==0)
    {
        parent->rchild = parent->rchild->lchild;
        child->lchild = NULL;
        free(child);
    }
    else if(j==1 && i==1)
    {
        parent->rchild = parent->rchild->rchild;
        child->rchild = NULL;
        free(child);
    }
    else if(j==5 && i==0)
    {
        root->data = root->lchild->data;
        root->lchild = NULL;
        free(root->lchild);
    }
    else if(j==5 && i==1)
    {
        root->data = root->rchild->data;
        root->rchild = NULL;
        free(root->rchild);

    }
}

void nochild(struct tnode* parent, struct tnode* child, int j)
{
    //printf("\n parent%d child %d",parent->data,child->data);

    if(j==0)
    {
        parent->lchild = NULL;
        free(child);
    }
    else if(j==1)
    {
        parent->rchild = NULL;
        free(child);
    }
    else if(j==5)
    {
        root = NULL;
        free(root);
    }
}

void min(struct tnode* child1, struct tnode* temp)
{
    if(child1->lchild)
        min(child1->lchild,temp);
    if(temp->data>child1->data)
    {
        temp->data = child1->data;
    }
    if(child1->rchild)
    {
        min(child1->rchild,temp);
    }
}


void twochild(struct tnode* parent, struct tnode* child, int j)
{
    if(j==0)
    {
        int k= 3;
        struct tnode* temp, *child3;
        temp = (struct tnode*)malloc(sizeof(struct tnode));
        temp->data = parent->lchild->rchild->data;
        min(parent->lchild->rchild,temp);
        //printf("\n\n min %d\n",temp->data);
        k = parent2(k,temp->data);
        if(k==0)
        {
            child3 = parent3->lchild;
            parent3->lchild = NULL;
            if(child3->rchild != NULL)
            {
                parent3->lchild = child3->rchild;
            }
            parent->lchild = child3;

            if(child->rchild == child3)
            {
                child3->rchild = NULL;
            }
            else
            {
                child3->rchild = child->rchild;
            }
            if(child->lchild == child3)
            {
                child3->lchild = NULL;
            }
            else
            {
                child3->lchild = child->lchild;
            }
            child->lchild = NULL;
            child->rchild = NULL;
            free(child);
        }
        else if(k==1)
        {
            child3 = parent3->lchild;
            parent3->lchild = NULL;
            if(child3->rchild != NULL)
            {
                parent3->rchild = child3->rchild;
            }
            parent->lchild = child3;
            if(child->rchild == child3)
            {
                child3->rchild = NULL;
            }
            else
            {
                child3->rchild = child->rchild;
            }
            if(child->lchild == child3)
            {
                child3->lchild = NULL;
            }
            else
            {
                child3->lchild = child->lchild;
            }


            child->lchild = NULL;
            child->rchild = NULL;
            free(child);
        }
    }
    else if(j==1)
    {
        int k= 3;
        struct tnode* temp, *child3;
        temp = (struct tnode*)malloc(sizeof(struct tnode));
        temp->data = parent->rchild->rchild->data;
        min(parent->rchild->rchild,temp);
        //printf("\n\n min %d\n",temp->data);
        k = parent2(k,temp->data);
        if(k==0)
        {
            child3 = parent3->lchild;
            parent3->lchild = NULL;
            if(child3->rchild != NULL)
            {
                parent3->lchild = child3->rchild;
            }
            parent->rchild = child3;

            if(child->rchild == child3)
            {
                child3->rchild = NULL;
            }
            else
            {
                child3->rchild = child->rchild;
            }
            if(child->lchild == child3)
            {
                child3->lchild = NULL;
            }
            else
            {
                child3->lchild = child->lchild;
            }
            child->lchild = NULL;
            child->rchild = NULL;
            free(child);
        }
        else if(k==1)
        {
            child3 = parent3->rchild;
            parent3->rchild = NULL;
            if(child3->rchild != NULL)
            {
                parent3->rchild = child3->rchild;
            }
            parent->rchild = child3;
            if(child->rchild == child3)
            {
                child3->rchild = NULL;
            }
            else
            {
                child3->rchild = child->rchild;
            }
            if(child->lchild == child3)
            {
                child3->lchild = NULL;
            }
            else
            {
                child3->lchild = child->lchild;
            }


            child->lchild = NULL;
            child->rchild = NULL;
            free(child);
        }

    }
    else if(j==5)
    {
        int k= 3;
        struct tnode* temp, *child3;
        temp = (struct tnode*)malloc(sizeof(struct tnode));
        temp->data = parent->rchild->data;
        min(parent->rchild,temp);
        //printf("\n\n min %d\n",temp->data);
        k = parent2(k,temp->data);

        if(k==0)
        {
            child3 = parent3->lchild;
            parent3->lchild = NULL;
            if(child3->rchild != NULL)
            {
                parent3->lchild = child3->rchild;
            }
            child= root;
            root = child3;
            if(child->rchild == child3)
            {
                child3->rchild = NULL;
            }
            else
            {
                child3->rchild = child->rchild;
            }
            if(child->lchild == child3)
            {
                child3->lchild = NULL;
            }
            else
            {
                child3->lchild = child->lchild;
            }
            child->lchild = NULL;
            child->rchild = NULL;
            free(child);
        }
        else if(k==1)
        {
            child3 = parent3->rchild;
            parent3->rchild = NULL;
            if(child3->rchild != NULL)
            {
                parent3->rchild = child3->rchild;
            }
            child = root;
            root = child3;
            if(child->rchild == child3)
            {
                child3->rchild = NULL;
            }
            else
            {
                child3->rchild = child->rchild;
            }
            if(child->lchild == child3)
            {
                child3->lchild = NULL;
            }
            else
            {
                child3->lchild = child->lchild;
            }


            child->lchild = NULL;
            child->rchild = NULL;
            free(child);
        }
    }
}

void delete()
{
    int j=3,ele;
    printf("ENTER THE ELEMENT TO DELETE :");
    scanf("%d",&ele);
    j = parent1(j,ele);
    if(j == 2)
    {
        printf("\nELEMENT NOT FOUND");
    }
    else if(j==0)
    {
        if( (parent->lchild->lchild!=NULL)  && (parent->lchild->rchild!=NULL))
        {
            printf("\n2 child");
            twochild(parent,parent->lchild,j);

        }
        else if( (parent->lchild->lchild!=NULL)  && (parent->lchild->rchild==NULL) )
        {
            int i=0;
            printf("\n1 left child");
            onechild(parent,parent->lchild,j,i);
        }
        else if( (parent->lchild->lchild==NULL)  && (parent->lchild->rchild!=NULL))
        {
            int i=1;
            printf("\n1 right child");
            onechild(parent,parent->rchild,j,i);
        }
        else
        {
            printf("\nno child");
            nochild(parent,parent->lchild,j);
        }
    }
    else if(j==1)
    {
        if( (parent->rchild->lchild!=NULL)  && (parent->rchild->rchild!=NULL))
        {
            printf("\n2 child");
            twochild(parent,parent->rchild,j);
        }
        else if( (parent->rchild->lchild!=NULL)  && (parent->rchild->rchild==NULL) )
        {
            int i=0;
            printf("\n1 left child");
            onechild(parent,parent->lchild,j,i);
        }
        else if( (parent->rchild->lchild==NULL)  && (parent->rchild->rchild!=NULL))
        {
            int i=1;
            printf("\n1 right child");
            onechild(parent,parent->rchild,j,i);
        }
        else
        {
            printf("\nno child");
            nochild(parent,parent->lchild,j);
        }
    }
    else if(j==5)
    {
        if( (parent->lchild!=NULL)  && (parent->rchild!=NULL))
        {
            printf("\n2 child");
            twochild(parent,parent->lchild,j);
        }
        else if( (parent->lchild==NULL)  && (parent->rchild!=NULL) )
        {
            int i=1;
            printf("\n1 right child");
            onechild(parent,parent->rchild,j,i);
        }
        else if( (parent->lchild!=NULL)  && (parent->rchild==NULL))
        {
            int i=0;
            printf("\n1 right child");
            onechild(parent,parent->lchild,j,i);
        }
        else
        {
            printf("\nno child");
            nochild(parent,parent->lchild,j);
        }
    }

}

void main()
{
    int j=2;
    int ele;
    printf("\nBINARY SEARCH TREE\n");
    while(1)
    {
        printf("\n1.insert\n2.delete\n3.display\n4.parent\nothers to exit\nENTER YOUR CHOICE : ");
        int choice;
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delete();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("\nFIND PARENT OF : ");
            scanf("%d",&ele);
            j = parent1(j,ele);
            break;
        default:
            exit(0);
        }
    }
}
