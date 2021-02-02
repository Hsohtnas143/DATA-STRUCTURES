#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define MAX_SIZE 5

int item, choice, i;
int arr_stack[MAX_SIZE];
int top = 0;
int exit_p = 1;

void push() {
    if (top == MAX_SIZE)
        printf("\n## Stack is Full!");
    else {
        printf("\nEnter The Value to be pushed : ");
        scanf("%d", &item);
        printf("\n## Position : %d , Pushed Value  : %d ", top, item);
        arr_stack[top++] = item;
    }
}

void pop() {
    if (top == 0)
        printf("\n## Stack is Empty!");
    else {
        --top;
        printf("\n## Position : %d , Popped Value  : %d ", top, arr_stack[top]);
    }
}

void display() {
    printf("\n## Stack Size : %d ", top);
    for (i = (top - 1); i >= 0; i--)
        printf("\n## Position : %d , Value  : %d ", i, arr_stack[i]);
}

int main() {
    printf("\nSimple Stack Example - Array and Functions");
    do {
        printf("\n\nStack Main Menu");

        printf("\n1.Push \n2.Pop \n3.Display \nOthers to exit");
        printf("\nEnter Your Choice : ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            default:
                exit_p = 0;
                break;
        }
    } while (exit_p);

    return 0;
}
