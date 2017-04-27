#include<stdio.h>
#include<stdlib.h>

struct tree{
	int value;
	int nos;
	struct tree* left;
	struct tree* right;
	struct tree* parent;
};

struct tree* newnode(int x)
{
	struct tree* new = malloc(sizeof(struct tree));
	new->value = x;
	new->left=NULL;
	new->right=NULL;
	return new;
}


struct tree* root;

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


struct tree* search(int x)
{
	if(root==NULL)
	{
		return NULL;
	}
	struct tree* temp = root;
	while(temp->value!=x)
	{
		//printf("Kaaa%d   \n",temp->value);
		if(x>temp->value)
		{
			temp=temp->right;
			//printf("Kaaa%d   \n",temp->value);
		}
		else
		{
			temp = temp->left;
			//printf("Kaaa%d   \n",temp->value);	
		}
	}
	return temp;
}

int finding_leaf(struct tree* node,struct tree* prev)
{
	//("Kadamba");
	int a,b,c;
	//a=10000;
	//printf(" %d \n",node->value);
	
	if(node->left==NULL&&node->right==NULL)
		return 0;
			
	if(node->parent!=NULL&&node->parent!=prev)
		 a = 1 + finding_leaf(node->parent,node); 
	if(node->left!=NULL&&node->left!=prev)
		 b = 1 + finding_leaf(node->left,node);
	if(node->right!=NULL&&node->right!=prev)
		 c = 1+ finding_leaf(node->right,node);
	
	if(a<b)
	{
		if(a<c)
		{
			return a;
		}
	}
	else
	{
		if(b<c)
		{
			return b;
		}
		else
		{
			return c;
		}
	}
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
	
	int ans;
	scanf("%d",&ans);
	struct tree* anss = search(ans);
	int kadamba = finding_leaf(anss,NULL);
	printf("\n%d\n",kadamba);
	
	return 0;
}
