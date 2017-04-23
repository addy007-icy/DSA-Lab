#include <stdio.h>
#include <stdlib.h>


typedef struct Node node;

struct Node
{
	char data;
	node *left;
	node *right;
};

void insert(node ** tree, char val)
{
    node *temp = NULL;
    if(!(*tree))
    {
        temp = (node *)malloc(sizeof(node));
        temp->left = temp->right = NULL;
        temp->data = val;
        *tree = temp;
        return;
    }

    if( (int)val != (int)(*tree)->data)			// storing the characters in the let tree only, if dupclicacy is found dont store
    {
        insert(&(*tree)->left, val);
    }
    // else if((int)val > (int)(*tree)->data)
    // {
    //     insert(&(*tree)->right, val);
    // }

}

void print(node *root)
{
	if (root)
	{
		
		printf("%c", root->data);
		print(root->left);
		//print(root->right);
	}
}
int main()
{
	node *root = NULL;
	int i;
	char arr[50];
	scanf("%s", arr);
	for (i = 0; arr[i] != '\0'; i++)
	{
		insert(&root,arr[i]);
	}
	print(root);

}