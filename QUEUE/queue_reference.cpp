#include <stdio.h>

struct queue{
	int f;
	int r;
	int arr[5];
	int max;
};

void insert(struct queue *q){
	if(q->f==q->max){
		printf("Queue if full.\n");
	}else{
		int e;
		printf("Enter element: ");
		scanf("%d",&e);
		for(int i=q->f;i>0;i--){
			q->arr[i] = q->arr[i-1];
		}
		q->arr[q->f] = e;
		q->f++;
	}
}

void pop(struct queue *q){
	if(q->f==q->r){
		printf("Queue is empty.\n");
	}else{
		q->f--;
	}
}

void print(struct queue *q){
	if(q->f==q->r){
		printf("Queue is empty.\n");
	}else{
		for(int i=0;i<q->f;i++){
			printf("%d\n",q->arr[i]);
		}
	}
}

int main(){
	struct queue * q;
	int ch;
	q->f = 0;
	q->r = 0;
	q->max = 5;

	do{
		printf("Menu\n1. Insert\n2. Pop\n3. Print\n4. Exit\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				insert(q);
				break;
			case 2:
				pop(q);
				break;
			case 3:
				print(q);
				break;
			case 4:
				break;
			default:
				printf("Incorrect input.\n");
			
		}
	}while(ch!=4);
}
