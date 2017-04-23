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

void DeleteAtBeg(node **root)
{
	node *curr = *root;
	if(curr == NULL){
		printf("ERROR: Underflow\n");
		return;
	}
	if(curr -> next == NULL){
		free(curr);
		*root = NULL;
		return;
	}
	node *tmp = curr->next;
	free(curr);
	*root = tmp;
}

void DeleteFromEnd(node **root)
{
	node *curr = *root;
	if(curr == NULL){
		printf("ERROR: Underflow\n");
		return;
	}
	else if(curr->next == NULL){
		free(curr->next);
		*root = NULL;
	}
	else{
		while((curr->next)->next != NULL){
			//printf("%d\n",curr->data);
			curr = curr -> next;
		}
		node *tmp = curr -> next;
		curr -> next = NULL;
		free(tmp);
	}
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
	InsertAtBeg(&head, 9);
	InsertAtBeg(&head, 5);
	DeleteAtBeg(&head);
	InsertAtBeg(&head, 0);
	DeleteFromEnd(&head);
	InsertAtBeg(&head, 4);
	Print(head);
	freeList(&head);
	return 0;
}
