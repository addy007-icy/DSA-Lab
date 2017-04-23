#include <stdio.h>
#include <stdlib.h>

typedef struct qNode{
	int data;
	struct qNode* next;
}qNode;

typedef struct Queue{
	qNode* front;
	qNode* rear;
}Queue;

typedef struct stack{
	Queue* q1;
	Queue* q2;
}stack;

void enqueue(Queue** q, int x)
{
	qNode* tmp = (qNode*)malloc(sizeof(qNode));
	tmp -> data = x;
	tmp -> next = NULL;
	if((*q) -> rear == NULL)
		(*q) -> front = (*q) -> rear = tmp;
	else{
		(*q) -> rear -> next = tmp;
		(*q) -> rear = tmp;
	}
}

int dequeue(Queue** q)
{
	if((*q) -> front == NULL)
		return -999;
	qNode *tmp = (*q) -> front;
	int x = tmp -> data;
	(*q) -> front = (*q) -> front -> next;
	if((*q) -> front == NULL)
		(*q) -> rear = NULL;
	return x;
}

void push(stack* st, int x)
{
	enqueue(&(st -> q1), x);
}

int pop(stack* st)
{
	int x, data;
	if(st -> q1 == NULL){
		printf("Stack Empty\n");
		return -999;
	}	
	else{
		if((st -> q1 -> front) -> next == NULL){
			x = (st -> q1 -> front) -> data;
			(st -> q1 -> front) = (st -> q1 -> rear) = NULL;
			return x;
		}
		else{
			while((st -> q1 -> front) -> next != NULL){
				x = dequeue(&(st -> q1));
				enqueue(&(st -> q2), x);
			}
			data = dequeue(&(st -> q1));
			while((st -> q2 -> front) != NULL){
				x = dequeue(&(st -> q2));
				enqueue(&(st -> q1), x);
			}
			return data;
		}
	}
}

void print(qNode* q1, qNode* q2)
{
	if(q1 == NULL)
		printf("Queue1 empty\n");
	else{
		printf("Queue1: ");
		while(q1 != NULL){
			printf("%d ",q1 -> data);
			q1 = q1 -> next;
		}
		printf("\n");
	}
	if(q2 == NULL)
		printf("Queue2 empty\n");
	else{
		printf("Queue2: ");
		while(q2 != NULL){
			printf("%d ",q2 -> data);
			q2 = q2 -> next;
		}
		printf("\n");
	}
}

int main()
{
	Queue* q1 = (Queue*)malloc(sizeof(Queue));
	q1 -> front = q1 -> rear = NULL;
	Queue* q2 = (Queue*)malloc(sizeof(Queue));
	q2 -> front = q2 -> rear = NULL;
	stack *st = (stack*)malloc(sizeof(stack));
	st -> q1 = q1;
	st -> q2 = q2;
	printf("Following Operations are supported: \n");
	printf("a. Insert an element (push) \n");
	printf("b. Delete an element (pop) \n");
	printf("c. Print the elements of the queue(1. queue & 2. queue2)\n");
	printf("d. Exit\n");
	while(1){
		char choice;
		scanf(" %c",&choice);
		if(choice == 'a'){
			int x;
			scanf("%d",&x);
			push(st,x);
		}
		else if(choice == 'b'){
			int x = pop(st);
			printf("%d popped\n",x);
		}
		else if(choice == 'c'){
			print(st -> q1 -> front, st -> q2 -> front);
		}
		else{
			printf("Exiting\n");
			break;
		}
	}
	return 0;
}
