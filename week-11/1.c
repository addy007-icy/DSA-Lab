#include<stdio.h>
#include<stdlib.h>

struct tree{
	int value;
	struct tree* parent;
	struct tree* left;
	struct tree* right;
};

struct tree* newnode(int x)
{
	struct tree* new = malloc(sizeof(struct tree));
	new->value = x;
	new->left=NULL;
	new->right=NULL;
	return new;
}

struct tree* root = NULL;

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

int height_node(struct tree* temp)
{
	if(temp==NULL) return 0;
	
	int count = 0;
	
	while(temp!=root)
	{
		temp= temp->parent;
		count++;
	}
	return count;
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

struct tree* common(int x,int y)
{
	//printf("sadasdas kadambads");
	struct tree* t1 = search(x);
	struct tree* t2 = search(y);
	
	//printf(" kadambads");
	
	int h1 = height_node(t1);
	
	int h2 = height_node(t2);
	
	printf("%d %d\n",h1,h2);
	
	if(h1>h2)
	{
		while(h1!=h2)
		{
			t1=t1->parent;
			h1--;
		}
	}
	else if(h1<h2)
	{
		while(h1!=h2)
		{
			t1=t1->parent;
			h2--;
		}
	}
	else
	{
		while(t1!=t2)
		{
			t1 = t1->parent;
			t2 = t2->parent;
		}
	}
	
	while(t1!=t2)
	{
		t1 = t1->parent;
		t2= t2->parent;
	}
	return t1;
}

void traversal(struct tree* temp)
{
	if(temp==NULL)
		return;
	printf("%d\n",temp->value);
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
	
	
//	traversal(root);
	
	struct tree* ans;// = common(5,23);
	ans= common(21,10);
	printf("%d ",ans->value);
	
	return 0;
}
