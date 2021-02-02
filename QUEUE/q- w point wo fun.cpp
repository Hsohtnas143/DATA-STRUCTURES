//queue without functions and with pointers

#include <stdio.h>
#include <stdlib.h>

struct queue{
	int arr[5];
	int f;
	int r;
};

int main(){
	int op,num;
	struct queue * q;
	q = (struct queue *)malloc(sizeof(struct queue));
	q->f = -1;
	q->r = -1;
	do{
		printf("1. Insert\n2. Delete\n3. Print\n0. Exit\n");
		scanf("%d",&op);
		switch(op){
			case 1:
//				insert
				if(q->r==4){
					printf("Queue is full\n");
					break;
				}
				printf("Enter a number: ");
				scanf("%d",&num);
				q->r++;
				q->arr[q->r] = num;
				break;
			case 2:
				
//				delete
				if(q->f==q->r){
					printf("Queue is empty\n");
					break;
				}
				q->r--;
				int del;
				del = q->arr[0];
				for(int i=0;i<q->r+1;i++){
					q->arr[i] = q->arr[i+1];
				}
				printf("%d is deleted from queue\n",del);
				break;
			case 3:
//				print
				for(int i=0;i<q->r+1;i++){
					printf("%d\n",q->arr[i]);
				}
				break;
			case 0:
				break;
			default:
				printf("Invalid input\n");
		}
	}while(op!=0);
}
