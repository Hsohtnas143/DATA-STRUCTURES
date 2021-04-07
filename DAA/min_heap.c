#include<stdio.h>
#include<stdlib.h>
struct tnode
{
    int data;
    struct tnode* lchild;
    struct tnode* rchild;
};


struct queue
{
    struct tnode* qu[100000];
    int front;
    int rear;
};

struct tnode * root = NULL;




void print_binary_tree2D(struct tnode *root,int space)
{
	if(root == NULL)
	{
		// printf("\n Binary Tree has no root  \n");		 as it is recursive call this will print more then one time
		return;
	}
	space  = space + 5;
	print_binary_tree2D(root->rchild,space);
	for (int i=5 ; i< space;i++)
	{
		printf(" ");
	}
	printf(" %d ", root->data);
	printf("\n");
	print_binary_tree2D(root->lchild,space);

}




void enqueue(struct tnode * temp, struct queue* q)
{
    q->qu[q->front] = temp;
    (q->front)++;
}

void dequeue(struct queue* q)
{
    for(int i = q->rear ; i<q->front ; i++)
    {
        q->qu[i] = q->qu[i+1];
    }
    (q->front)--;
}

struct tnode* parent(struct tnode* temp)
{
    if(temp == root)
    {
        return temp;
    }
    else
    {
        struct tnode* temp1 = root,*temp2;
        struct queue* q1;
        q1 = (struct queue*)malloc(sizeof(struct queue));
        q1->front = 0;
        q1->rear = 0;
        enqueue(temp1,q1);
        while(q1->front!=q1->rear)
        {
            temp2  = q1->qu[0];
            if(temp2->lchild == temp)
            {
                return temp2;
            }
            else if(temp2->rchild == temp)
            {
                return temp2;
            }
            else
            {
                enqueue(temp2->lchild,q1);
                enqueue(temp2->rchild,q1);
                dequeue(q1);

            }
        }
    }

}


void swap(struct tnode* temp1, struct tnode* temp2, struct queue* q)
{
    int first=0,second=0;
    for(int i=0;i<q->front;i++)
    {
        if(q->qu[i] == temp1)
        {
            first = i;
        }
        if(q->qu[i] == temp2)
        {
            second = i;
        }
    }
    struct tnode * temp3 = q->qu[first];
    q->qu[first] = q->qu[second];
    q->qu[second] = temp3;
}



void heap1(struct tnode* temp, struct queue* q)
{
    struct tnode* temp1,*temp2,*temp3,*temp4;
    temp1 = parent(temp);

    if(temp1->data > temp->data)
    {
        if(temp1->lchild == temp)
        {
            if(temp1 == root)
            {
                temp3 = temp->lchild;
                temp4 = temp->rchild;
                temp->lchild = temp1;
                temp->rchild = temp1->rchild;
                temp1->lchild = temp3;
                temp1->rchild = temp4;
                root = temp;
                swap(root,temp,q);
                printf("\n heap1\n");

                return;
            }
            else
            {
                temp2 = parent(temp1);
                if(temp2->lchild == temp1)
                {
                    temp3 = temp->lchild;
                    temp4 = temp->rchild;
                    temp->lchild = temp2->lchild;
                    temp2->lchild = temp;
                    temp->rchild = temp1->rchild;
                    temp1->lchild = temp3;
                    temp1->rchild = temp4;
                    printf("\n heap2\n");
                    swap(temp1,temp,q);
                    heap1(temp,q);
                }
                else if(temp2->rchild == temp1)
                {
                    temp3 = temp->lchild;
                    temp4 = temp->rchild;
                    temp->lchild  = temp2->rchild;
                    temp2->rchild = temp;
                    temp->rchild = temp1->rchild;
                    temp1->lchild = temp3;
                    temp1->rchild = temp4;
                    printf("\n heap3\n");
                    swap(temp1,temp,q);
                    heap1(temp,q);
                }
            }
        }
        else if(temp1->rchild == temp)
        {
            if(temp1 == root)
            {
                temp3 = temp->lchild;
                temp4 = temp->rchild;
                temp->rchild = temp1;
                temp->lchild = temp1->lchild;
                temp1->lchild = temp3;
                temp1->rchild = temp4;
                root = temp;
                printf("\n heap4\n");
                swap(root,temp,q);
                return;
            }
            else
            {
                temp2 = parent(temp1);
                if(temp2->lchild == temp1)
                {
                    temp3 = temp->lchild;
                    temp4 = temp->rchild;
                    temp->rchild = temp2->lchild;
                    temp->lchild = temp1->lchild;
                    temp2->lchild = temp;
                    temp1->lchild = temp3;
                    temp1->rchild = temp4;
                    printf("\n heap5\n");
                    swap(temp1,temp,q);
                    heap1(temp,q);
                }
                else if(temp2->rchild == temp1)
                {
                    temp3 = temp->lchild;
                    temp4 = temp->rchild;
                    temp->rchild = temp2->rchild;
                    temp2->rchild = temp;
                    temp->lchild = temp1->lchild;
                    temp1->lchild = temp3;
                    temp1->rchild = temp4;
                    printf("\n heap6\n");
                    swap(temp1,temp,q);

                    heap1(temp,q);
                }
            }
        }
    }
    else
    {
        printf("\n no heap\n");
        return;
    }

}

void display(struct tnode* temp)
{
    printf("%d ",temp->data);
    if(temp->lchild)
        display(temp->lchild);
    if(temp->rchild)
        display(temp->rchild);
}

void insert(struct queue* q)
{
    struct tnode* temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    printf("\nenter the val : ");
    scanf("%d",&temp->data);
    temp->lchild = NULL;
    temp->rchild = NULL;
    if(root == NULL)
    {
        root = temp;
        enqueue(root,q);
    }
    else
    {
        int i=0;
        struct tnode* temp1;
        while(1)
        {
            temp1 = q->qu[i];
            printf("\n inse %d \n",temp1->data);
            //printf("hi");
            if(temp1->lchild == NULL)
            {
                //printf("hi1");
                temp1->lchild = temp;
                enqueue(temp,q);
                print_binary_tree2D(root,10);
                //display(root);
                printf("\n");
                heap1(temp,q);
                print_binary_tree2D(root,10);
                //display(root);
                //temp2 = parent(temp);

                break;
            }
            else if(temp1->rchild == NULL)
            {
                //printf("hi2");
                temp1->rchild = temp;
                enqueue(temp,q);
                print_binary_tree2D(root,10);
                //display(root);
                printf("\n");
                heap1(temp,q);
                print_binary_tree2D(root,10);
                //display(root);
                //temp2 = parent(temp);
                //printf("%d pare\n",temp2->data);

                break;
            }
            else if(temp1->rchild!=NULL && temp1->lchild!=NULL)
            {
                //dequeue(q);
                //printf("hi3");
                i++;

            }
        }

    }
}



void main()
{
    struct queue* q;
    q = (struct queue*)malloc(sizeof(struct queue));
    q->front = 0;
    q->rear = 0;
    int ch;
    while(1)
    {
        printf("\n1.insert 2. display");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            insert(q);
            break;
        case 2:
            display(root);
            break;
        default:
            exit(0);
            break;
        }
    }
}
