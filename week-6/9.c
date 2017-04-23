#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}node;

node* mergeSortedList(node **root1, node **root2)
{
	node *root = NULL, *curr;
	node *curr1 = *root1, *curr2 = *root2;
	while(curr1 != NULL && curr2 != NULL){
		node *tmp = (node*)malloc(sizeof(node));
		if(curr1 -> data <= curr2 -> data){
			if(root == NULL){
				tmp -> data = curr1 -> data;
				tmp -> next = NULL;
				root = curr = tmp;
			}
			else{
				tmp -> data = curr1 -> data;
				tmp -> next = NULL;
				curr -> next = tmp;
				curr = curr -> next;
			}
			curr1 = curr1 -> next;
		}
		else{
			if(root == NULL){
				tmp -> data = curr2 -> data;
				tmp -> next = NULL;
				root = curr = tmp;
			}
			else{
				tmp -> data = curr2 -> data;
				tmp -> next = NULL;
				curr -> next = tmp;
				curr = curr -> next;
			}
			curr2 = curr2 -> next;
		}
	}
	while(curr1 != NULL){
		node *tmp = (node*)malloc(sizeof(node));
		tmp -> data = curr1 -> data;
		tmp -> next = NULL;
		curr -> next = tmp;
		curr = tmp;	
		curr1 = curr1 -> next;
	}
	while(curr2 != NULL){
		node *tmp = (node*)malloc(sizeof(node));
		tmp -> data = curr2 -> data;
		tmp -> next = NULL;
		curr -> next = tmp;
		curr = tmp;	
		curr2 = curr2 -> next;
	}
	return root;
}

void InsertAtBeg(node **root, int x)
{
	node *tmp = (node*)malloc(sizeof(node));
	tmp -> data = x;
	tmp -> next = (*root);
	*root = tmp;
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
	node *head1=NULL, *head2=NULL;
	InsertAtBeg(&head1, 8);
	InsertAtBeg(&head1, 6);
	InsertAtBeg(&head1, 3);
	InsertAtBeg(&head1, 2);
	InsertAtBeg(&head2, 9);
	InsertAtBeg(&head2, 7);
	InsertAtBeg(&head2, 4);
	InsertAtBeg(&head2, 1);
	node *head = mergeSortedList(&head1, &head2);
	Print(head);
	//Print(head1);
	//Print(head2);
	freeList(&head1);
	freeList(&head2);
	freeList(&head);
	return 0;
}
