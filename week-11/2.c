#include<stdio.h>
#include<stdlib.h>

struct tree{
	int value;
	struct tree* parent;
	int collective;
	struct tree* left;
	struct tree* right;
};

int min = 0;
struct tree* root;
struct tree* newnode(int x)
{
	struct tree* new = malloc(sizeof(struct tree));
	new->value = x;
	new->left=NULL;
	new->right=NULL;
	return new;
}

void insert(int x)
{
	if(root==NULL)
	{
		root = newnode(x);
		root->parent = NULL;
		return;
	}
	struct tree* temp = root;
	while(temp!=NULL)
	{
	//	printf("%d ",temp->value);
		if(x>temp->value)
		{
			if(temp->right!=NULL)
				temp=temp->right;
			else
				{
					temp->right=newnode(x);
					temp->right->parent = temp;
				//	printf("%d  ",temp->value);
					return;
				}
				
		}
		else
		{
			if(temp->left!=NULL)
				temp = temp->left;	
			else
			{
				temp->left=newnode(x);
				temp->left->parent = temp;
			//	printf("%d  ",temp->value);
				return;
			}
		}
	}
	
}

void traverse_collective(struct tree* node)
{
	if(node==NULL)
		return;
	if(node==root)
		{
			node->collective = node->value;
			if(node->left!=NULL)
				traverse_collective(node->left);
			if(node->right!=NULL)
				traverse_collective(node->right);
				return;
			
		}
	
	//printf("%d \n",node->value);
	int a = node->parent->collective; 
	node->collective = node->parent->collective +  node->value;
	if(node->left!=NULL)
		traverse_collective(node->left);
	if(node->right!=NULL)
		traverse_collective(node->right);
}

void traversal(struct tree* temp)
{
	if(temp==NULL)
		return;
	printf("%d ::: %d \n",temp->value,temp->collective);
	traversal(temp->left);
	traversal(temp->right);
}


int main()
{
		insert(25);	
		insert(20);
		insert(30);
		insert(10);
		insert(23);
		insert(35);
		insert(5);
		insert(21);
		insert(32);
	traverse_collective(root);
	traversal(root);
	return 0;
}
