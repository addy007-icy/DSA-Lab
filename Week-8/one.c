#include <stdio.h>
#include <stdlib.h>

typedef struct stackNode
{
	int data;
	struct stackNode *next;
}stackNode;

typedef struct queue
{
	stackNode *st1;
	stackNode *st2;
}queue;

void push(stackNode **top, int x)
{
	stackNode* tmp = (stackNode*)malloc(sizeof(stackNode));
	if(tmp != NULL){
		tmp -> data = x;
		tmp -> next = *top;
		*top = tmp;
	}
	else{
		printf("Stack overflow\n");
		return;
	}
}

int pop(stackNode** top)
{
	if(*top == NULL){
		printf("Stack Underflow\n");
		return -999;
	}
	else{
		stackNode *tmp;
		tmp = *top;
		int res = tmp -> data;
		*top = tmp -> next;
		free(tmp);
		printf("tmp=%p\n",tmp);
		return res;
	}
}

void enqueue(queue* q, int x)
{
	push(&q -> st1, x);
}

int dequeue(queue* q)
{
	int x;
	if(q -> st1 == NULL && q -> st2 == NULL){
		printf("Queue Empty\n");
		return -999;
	}
	if(q -> st2 == NULL){
		while(q -> st1 != NULL){
			x = pop(&q -> st1);
			push(&q -> st2, x);
		}
	}
	x = pop(&q -> st2);
	return x;
}

void print(stackNode* st1, stackNode* st2)
{
	if(st1 == NULL){
		printf("Stack 1 is empty\n");
	}
	else{
		printf("Stack1 : ");
		while(st1 != NULL){
			printf("%d ",st1 -> data);
			st1 = st1 -> next;
		}
		printf("\n");
	}
	if(st2 == NULL){
		printf("Stack 2 is empty\n");
	}
	else{
		printf("Stack2 : ");
		while(st2 != NULL){
			printf("%d ",st2 -> data);
			st2 = st2 -> next;
		}
		printf("\n");
	}
}

int main()
{
	queue *q = (queue*)malloc(sizeof(queue));
	q -> st1 = NULL;
	q -> st2 = NULL;
	printf("Following Operations are supported: \n");
	printf("a. Insert an element (enqueue) \n");
	printf("b. Delete an element (dequeue) \n");
	printf("c. Print the elements of the stack(1. stack1 & 2. stack2)\n");
	printf("d. Exit\n");
	while(1){
		char choice;
		scanf(" %c",&choice);
		if(choice == 'a'){
			int x;
			scanf("%d",&x);
			enqueue(q,x);
		}
		else if(choice == 'b'){
			int x = dequeue(q);
			printf("%d dequeued\n",x);
		}
		else if(choice == 'c'){
			print(q -> st1, q -> st2);
		}
		else{
			printf("Exiting\n");
			break;
		}
	}
	return 0;
}
