#include <stdio.h>
#include <stdlib.h>

typedef struct stackNode
{
	int data;
	struct stackNode *next;
}stackNode;

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

void pop(stackNode** top)
{
	if((*top) == NULL){
		printf("Stack Underflow\n");
	}
	else{
		stackNode *tmp;
		tmp = *top;
		int res = tmp -> data;
		*top = tmp -> next;
		free(tmp);
	}
}

int getMaxArea(int hist[], int n)
{
	stackNode* top = NULL;
	int max = 0, tp, area, i;
	while(i < n){
		if(top == NULL || hist[top->data] <= hist[i])
			push(&top, i++);
		else{
			tp = top -> data;
			pop(&top);
			area = hist[tp]*(top==NULL ? i: i-(top->data)-1);
			if(max < area)
				max = area;
		}
	}
	while(top != NULL){
		tp = top -> data;
		pop(&top);
		area = hist[tp]*(top==NULL ? i: i-(top->data)-1);
		if(max < area)
			max = area;
	}
	return max;
}

int main()
{
	int n, i;
	scanf("%d",&n);
	int hist[n];
	for(i=0; i<n; i++){
		scanf("%d",&hist[i]);
	} 
	printf("%d\n",getMaxArea(hist,n));
	return 0;
}
