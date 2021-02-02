#include<stdio.h>
void main(){
    int top = 0 ;
    printf("##STACK - - WITHOUT FUNCTIONS##");
    int max,exit = 1;
    printf("\nenter the max size of stack : ");
    scanf("%d",&max);
    int stack[max];
    int ele,choice;
    do{
        printf("\nMenu\n1.Push\n2.Pop\n3.Display items\nothers to exit");
        printf("\nEnter ur choice : ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            if(top == max){
                printf("\nSTACK IS FULL");
            }
            else{
                printf("\nEnter the element to be pushed : ");
                scanf("%d",&ele);
                printf("\n Position : %d , Pushed Value  : %d ", top, ele);
                stack[top++] = ele;
            }
            break;
        case 2:
            if(top == 0){
                printf("\nSTACK IS EMPTY");
            }
            else{
                --top;
                printf("\n Position : %d , Popped Value  : %d ", top, ele);
            }
            break;
        case 3:
            printf("\nNo. of elements in stack : %d",top);
            for(int i=0;i<top;i++){
                printf("\nPosition : %d , value : %d",i,stack[i]);
            }
            break;
        default:
            exit = 0;
            break;
        }
    }while(exit);
}
