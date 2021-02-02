//queue without pointer and with functions
#include<stdio.h>

struct queue{
	int arr[5];
	int r;
	int f;
};

struct queue insert(struct queue q){
	if(q.r==4){
		printf("Queue is full\n");
		return q;
	}
	int num;
	printf("Enter number: ");
	scanf("%d",&num);
	q.r++;
	q.arr[q.r] = num;
	return q;
	
}

struct queue deleteQ(struct queue q){
	if(q.f==q.r){
		printf("Queue is empty\n");
		return q;
	}
	q.r--;
	int num;
	num = q.arr[0];
	printf("%d is deleted from queue\n",num);
	for(int i=0;i<q.r+1;i++){
		q.arr[i] = q.arr[i+1];
	}
	return q;
}

void print(struct queue q){
	if(q.f==q.r){
		printf("Queue is empty\n");
		
	}else{
		for(int i=0;i<q.r+1;i++){
			printf("%d\n",q.arr[i]);
		}
	}
}


int main(){
	int op;
	struct queue q;
	q.f = -1;
	q.r = -1;
	
	do{
		printf("1. Insert\n2. Delete\n3. Print\n0. Exit\n");
		scanf("%d",&op);
		switch(op){
			case 1:
				q = insert(q);
				break;
			case 2:
				q = deleteQ(q);
				break;
			case 3:
				print(q);
				break;
			case 0:
				break;
			default:
				printf("Invalid input\n");
		}
	}while(op!=0);
}
