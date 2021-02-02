#include<stdio.h>
#include<stdlib.h>
struct tnode
{
  int data;
  struct tnode* lchild;
  struct tnode* rchild;
};

struct tnode* root = NULL;

struct queue
{
    struct tnode* dat[1000000];
    int front;
    int rear;
};


void push(struct queue*a, struct tnode*val)
{
    a->dat[a->rear] = val; 
    (a->rear)++;
}

void pop(struct queue*a)
{
    if(a->front!=a->rear)
    {
        for(int i=0;i<(a->rear-1);i++)
        {
            a->dat[i] = a->dat[i+1];
        }
        (a->rear)--;
    }
}

void insert(struct queue *a)
{
    struct tnode* temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    printf("\nenter the data : ");
    scanf("%d",&temp->data);
    temp->lchild = NULL;
    temp->rchild = NULL;
    if(root == NULL)
    {
        root = temp;
        push(a,root);
    }
    else
    {
        struct tnode* temp1;
        
        while(1)
        {
            temp1 = (a->dat[a->front]);
            if(temp1->lchild == NULL)
            {
                temp1->lchild = temp;
                push(a,temp);
                break;
            }
            else if(temp1->rchild == NULL)
            {
                temp1->rchild = temp;
                push(a,temp);
                break;
            }
            if((temp1->lchild !=NULL) && (temp1->rchild!=NULL))
            {
                pop(a);
            }
            
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

void display(struct tnode*t)
{
    inorder(t);
}

int COUNT =10;
void print2DUtil(struct tnode *root, int space) 
{ 
    // Base case 
    if (root == NULL) 
        return; 
  
    // Increase distance between levels 
    space += COUNT; 
  
    // Process right child first 
    print2DUtil(root->rchild, space); 
  
    // Print current node after space 
    // count 
    printf("\n"); 
    for (int i = COUNT; i < space; i++) 
        printf(" "); 
    printf("%d\n", root->data); 
  
    // Process left child 
    print2DUtil(root->lchild, space); 
}



void printing()
{
    if(root==NULL)
    {
        printf("\nno elements");
    }
    else
    {
        struct queue *b;
    b = (struct queue*)malloc(sizeof(struct queue));
    b->front = 0;
    b->rear = 0;
    b->dat[(b->rear)++] = root;
    struct tnode *temp;
    while((b->rear)>0)
    {
        temp = b->dat[b->front];
        printf("%d ",temp->data);
        if(temp->lchild)
            push(b,temp->lchild);
        if(temp->rchild)
            push(b,temp->rchild);
        pop(b);
        
    }
    printf("\n");
    }
    
    
    
}

void check(struct tnode* adress,int ele)
{
    if(ele == 200)
    {
        if(root->lchild==NULL && root->rchild==NULL)
        {
            adress->lchild = root;
            adress->data = 1;
        }
        else
        {
            struct queue *b;
            b= (struct queue*)malloc(sizeof(struct queue));
            b->front =0;
            b->rear = 0;
            push(b,root);
            struct tnode*temp;
            while((b->rear)>0)
            {
                temp = b->dat[b->front];
                if(temp->lchild)
                {
                    push(b,temp->lchild);
                    adress->lchild = temp;
                    adress->data = 2;
                }
                if(temp->rchild)
                {
                    push(b,temp->rchild);
                    adress->lchild = temp;
                    adress->data = 3;
                }
                pop(b);
            }
        }
    }
    else
    {
        if(root->data == ele)
        {
            adress->lchild = root;
            adress->data = 1;
        }
        else
        {
            struct queue* b;
            b = (struct queue*)malloc(sizeof(struct queue));
            b->front = 0;
            b->rear = 0;
            push(b,root);
            struct tnode* temp;
            while((b->rear)>0)
            {
                temp = b->dat[b->front];
                if(temp->lchild->data == ele)
                {
                    adress->lchild = temp;
                    adress->rchild = NULL;
                    adress->data = 2;
                    break;
                }
                else if(temp->rchild->data == ele)
                {
                    adress->lchild = temp;
                    adress->rchild = NULL;
                    adress->data = 3;
                    break;
                
                }
                else if(temp->lchild !=ele && temp->lchild !=NULL )
                {
                    push(b,temp->lchild);
                }
                else if(temp->rchild!=ele && temp->rchild!=NULL)
                {
                    push(b,temp->rchild);
                }
                pop(b);
            }
        }
    }
}


void delete_by_value()

{
    if(root == NULL)
    {
        printf("\nno elements");
    }
    else
    {
        int ele,i,j;
        printf("\nenter the element");
        scanf("%d",&ele);
        struct tnode* address_node,*last_node;
        address_node = (struct tnode*)malloc(sizeof(struct tnode));
        last_node = (struct tnode*)malloc(sizeof(struct tnode));
        printf("\nnow");
        check(address_node,ele);
        check(last_node,200);
        i = address_node->data;
        j = last_node->data;
        //printf("\n%d %d\n",last_node->lchild->data,last_node->rchild->data);
        printf("\nherere");
        printf("\n%d adress , %d position",address_node->lchild->data,address_node->data);
        printf("\n%d adress-last , %d position",last_node->lchild->data,last_node->data);
        
        if(i==1||i==2||i==3)
        {
            printf("\nelement found");
            if(i==1 && j==1)
            {
                root = NULL;
            }
            else if(i==1 &&(j==2 || j==3))
            {
                if(j==2)
                {
                    address_node->lchild->data = last_node->lchild->lchild->data;
                    last_node->lchild->lchild = NULL;
                    free(last_node->lchild->lchild);
                }
                if(j==3)
                {
                    address_node->lchild->data = last_node->lchild->rchild->data;
                    last_node->lchild->rchild = NULL;
                    free(last_node->lchild->rchild);
                }
                
            }
            else if(i==2 &&(j==2 || j==3))
            {
                if(j==2)
                {
                    address_node->lchild->lchild->data = last_node->lchild->lchild->data;
                    last_node->lchild->lchild = NULL;
                    free(last_node->lchild->lchild);
                }
                if(j==3)
                {
                    address_node->lchild->lchild->data = last_node->lchild->rchild->data;
                    last_node->lchild->rchild = NULL;
                    free(last_node->lchild->rchild);
                }
            }
            else if(i==3 && (j==2||j==3))
            {
                if(j==2)
                {
                    address_node->lchild->rchild->data = last_node->lchild->lchild->data;
                    last_node->lchild->lchild = NULL;
                    free(last_node->lchild->lchild);
                }
                if(j==3)
                {
                    address_node->lchild->rchild->data = last_node->lchild->rchild->data;
                    last_node->lchild->rchild = NULL;
                    free(last_node->lchild->rchild);
                }
            }
        }
        
    }
}



int main()
{
    struct queue *a;

    a = (struct queue*)malloc(sizeof(struct queue));
    a->front = 0;
    a->rear = 0;
    struct tnode *t = root;
    int choice;
    while(1)
    {
        printf("\nTREE\n1.INSERT\n2.DELETE\n3.DISPLAY\nOTHERS TO EXIT\nENTER THE OPTION : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            insert(a);
            break;
        case 2:
            delete_by_value();
            break;
        case 3:
            printing();
            //display(t);
            break;
        default:
            exit(0);
            break;
        }
    }
    
    print2DUtil(t,0);
    //inorder(t);
}

