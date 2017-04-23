#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}node;

void InsertAtBeg(node **root, int x)
{
	node *tmp = (node*)malloc(sizeof(node));
	tmp -> data = x;
	tmp -> next = (*root);
	*root = tmp;
} 

void InsertAtEnd(node **root, int x)
{
	node *curr = *root;
	node *tmp = (node*)malloc(sizeof(node));
	tmp -> data = x;
	tmp -> next = NULL;
	while(curr -> next != NULL){
		curr = curr->next;
	}
	curr -> next = tmp;
}

void Insert(node **root, int x, int y)
{
	node *curr = *root;
	node *tmp = (node*)malloc(sizeof(node));
	tmp -> data = x;
	while((curr -> next) -> data != y){
		curr = curr->next;
	}
	tmp -> next = curr -> next;
	curr -> next = tmp;
}

void Print(node *root)
{
	node *curr = root;
	while(curr != NULL){
		printf("%d ", curr -> data);
		curr = curr -> next;
	}
	printf("\n");
}

void freeList(node **root)
{
	node *curr = *root;
	node *tmp;
	while(curr != NULL){
		tmp = curr;
		curr = curr -> next;
		free(tmp);
	}
}

int main()
{
	node *head = NULL;
	InsertAtBeg(&head, 2);
	InsertAtEnd(&head, 5);
	InsertAtBeg(&head, 9);
	InsertAtEnd(&head, 4);
	Insert(&head, 3, 5);
	Print(head);
	freeList(&head);
	return 0;
}
