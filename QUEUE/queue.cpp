#include <stdio.h>

struct queue{
	int f;
	int r;
	int arr[5];
	int max;
};

struct queue insert(struct queue q){
	int ele;
	if(q.f==q.max){
		printf("Queue is full.\n");
	}else{
		printf("Enter element: ");
		scanf("%d",&ele);
		for(int i=q.f;i>0;i--){
			q.arr[i] = q.arr[i-1];
		}
		q.arr[q.r] = ele;
		q.f++;
	}
	return q;
}

struct queue pop(struct queue q){
	if(q.f==q.r){
		printf("Queue is empty.\n");
	}else{
		q.f--;
	}
	return q;
}

void print(struct queue q){
	if(q.f==q.r){
		printf("Queue is empty.\n");
	}else{
		printf("- - - - - - - -\n");
		for(int i=0;i<q.f;i++){
			printf("%d\n",q.arr[i]);
		}
		printf("- - - - - - - -\n");
	}
}

int main(){
	
	struct queue q;
	int ch;
	q.max = 5;
	q.f = 0;
	q.r = 0;
	do{
		printf("Menu\n1. Insert\n2. Pop\n3. Print\n4. Exit\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				q = insert(q);
				break;
			case 2:
				q = pop(q);
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
