#include<stdio.h>
int ele;
struct stack{
    int max;
    int a[100];
    int top;
};
int push(struct stack *s)
{
    if(s->top == s->max)
    {
        printf("\nSTACK IS FULL");
    }
    else
    {
        printf("\nEnter the element to be pushed : ");
        scanf("%d",&ele);
        printf("\n Position : %d , Pushed Value  : %d ", s->top, ele);
        s->a[s->top] = ele;
        s->top ++;
    }
}
int pop(struct stack *s)
{
    if(s->top == 0)
    {
        printf("\nSTACK IS EMPTY");
    }
    else
    {
        --s->top;
        printf("\n Position : %d , Popped Value  : %d ", s->top, ele);
    }
}
int display(struct stack *s)
{
    printf("\nNo. of elements in stack : %d",s->top);
    for(int i=0;i<s->top;i++){
        printf("\nPosition : %d , value : %d",i,s->a[i]);
    }
}
int main()
{
    struct stack *s;
    s = (struct stack*)malloc(1*sizeof(struct stack));
    printf("STACK_STRUCTURE_POINTER WITH FUNCTIONS");
    printf("\nenter the max size of stack : ");
    scanf("%d",&s->max);
    s->top = 0;
    int choice,exit = 1,ele;
    do
    {
        printf("\nMenu\n1.Push\n2.Pop\n3.Display items\nothers to exit");
        printf("\nEnter ur choice : ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            push(s);
            break;
        case 2:
            pop(s);
            break;
        case 3:
            display(s);
            break;
        default:
            exit = 0;
            break;
        }

    }while(exit);
}
