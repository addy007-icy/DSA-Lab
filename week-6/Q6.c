#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


struct node{
	int data;
	struct node *next;
};

void push(struct node** head, int newdata){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = newdata;
    newnode->next = *head;
    *head = newnode;
}

struct node* sortedMerge(struct node* a, struct node* b){
	struct node* result = NULL;
	if(a==NULL){
		return (b);
	}
	else if(b==NULL){
		return (a);
	}

	if(a->data > b->data){
		result = b;
		result->next = sortedMerge(a,b->next);
	}
	else{
		result = a;
		result->next = sortedMerge(a->next,b);
	}
	return (result);
}

void printlist(struct node* node){
	printf("Sorted list : \n");
	while(node!=NULL){
		printf("%d -> ",node->data);
		node = node->next;
	}
	printf("NULL\n");
}

int main(){
	struct node* a = NULL;
	struct node* b = NULL;
	struct node* result = NULL;
	int n,m,x;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&x);
		push(&a,x);
	}
	scanf("%d",&m);
	while(m--){
		scanf("%d",&x);
		push(&b,x);
	}

	printlist(sortedMerge(a,b));
	return 0;
}
