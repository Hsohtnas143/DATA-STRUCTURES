#include<stdio.h>
struct stack1{
    int max;
    int a[100];
    int top;

    };
int main()
{
    printf("STACK_STRUCTURE WITHOUT FUNCTIONS");
    struct stack1 s;
    printf("\nenter the max size of stack : ");
    scanf("%d",&s.max);
    s.top = 0;
    int ele,choice,exit = 1;
    do{
        printf("\nMenu\n1.Push\n2.Pop\n3.Display items\nothers to exit");
        printf("\nEnter ur choice : ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            if(s.top == s.max){
                printf("\nSTACK IS FULL");
            }
            else{
                printf("\nEnter the element to be pushed : ");
                scanf("%d",&ele);
                printf("\n Position : %d , Pushed Value  : %d ", s.top, ele);
                s.a[s.top] = ele;
                s.top ++;
            }
            break;
        case 2:
            if(s.top == 0){
                printf("\nSTACK IS EMPTY");
            }
            else{
                --s.top;
                printf("\n Position : %d , Popped Value  : %d ", s.top, ele);
            }
            break;
        case 3:
            printf("\nNo. of elements in stack : %d",s.top);
            for(int i=0;i<s.top;i++){
                printf("\nPosition : %d , value : %d",i,s.a[i]);
            }
            break;
        default:
            exit = 0;
            break;
        }
    }while(exit);
}
