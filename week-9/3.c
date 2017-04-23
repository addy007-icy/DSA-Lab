#include <stdio.h>
#include <stdlib.h>

typedef struct Node node;

struct Node
{
	int data;
	node *left;
	node *right;
};

void print(node *root)
{
	if (root)
	{

		printf("%d", root->data);
		print(root->left);
		//print(root->right);
	}
}

void insert(node ** tree, int val)
{
	node *temp = NULL;
	if (!(*tree))
	{
		temp = (node *)malloc(sizeof(node));
		temp->left = temp->right = NULL;
		temp->data = val;
		*tree = temp;
		return;
	}

	if ( val != (*tree)->data)			// storing the characters in the let tree only, if dupclicacy is found dont store
	{
		insert(&(*tree)->left, val);
	}
	// else if((int)val > (int)(*tree)->data)
	// {
	//     insert(&(*tree)->right, val);
	// }

}

int height(node *root, int h)
{
	if (root != NULL)
	{
		h++;
		//printf("h = %d\n", h);
		height(root->left, h);
	}
	else
		return h;
}
int main()
{
	int arr[9][9] = {{8, 3, 5, 4, 1, 6, 9, 2, 7},
					{2, 9, 6, 8, 5, 7, 4, 3, 1},
					{4, 1, 7, 2, 9, 3, 6, 5, 8},
					{5, 6, 9, 1, 3, 4, 7, 8, 2},
					{1, 2, 3, 6, 7, 8, 5, 4, 9},
					{7, 4, 8, 5, 2, 9, 1, 6, 3},
					{6, 5, 2, 7, 8, 1, 3, 9, 4},
					{9, 8, 1, 3, 4, 5, 2, 7, 6},
					{3, 7, 4, 9, 6, 2, 8, 1, 1}};
	int i, j, k;
	// for (i = 0; i < 9; i++)
	// {
	// 	for (j = 0; j < 9; j++)
	// 	{
	// 		scanf("%d", &arr[i][j]);
	// 		if (arr[i][j] > 9 || arr[i][j] < 1)
	// 		{
	// 			return 0;
	// 		}
	// 	}
	// }

	for (i = 0; i < 9; i++)				//for checking rows
	{
		node *root = NULL;

		for (j = 0; j < 9; j++)
		{
			insert(&root, arr[i][j]);
		}
		int h = height(root, 0);
		if (h != 9)
		{
			printf("NO\n");
			return 0;
		}
	}

	for (i = 0; i < 9; i++)				//for checking columns
	{
		node *root = NULL;

		for (j = 0; j < 9; j++)
		{
			insert(&root, arr[j][i]);
		}
		int h = height(root, 0);
		if (h != 9)
		{
			printf("NO\n");
			return 0;
		}
	}

	for (k = 0; k < 9; k += 3)				//for checking every 3x3 square
	{
		int sum0 = 0;
		int sum1 = 0;
		int sum2 = 0;

		for (i = k; i < k + 3; i++)
		{

			for (j = 0; j < 3; j++)
			{
				sum0 += arr[i][j];
			}

			for (j = 3; j < 6; j++)
			{
				sum1 += arr[i][j];
			}

			for (j = 6; j < 9; j++)
			{
				sum2 += arr[i][j];
			}

		}

		if (sum0 != 45)
		{
			printf("NO\n");
			return 0;
		}
		if (sum1 != 45)
		{
			printf("NO\n");
			return 0;
		}
		if (sum2 != 45)
		{
			printf("NO\n");
			return 0;
		}
	}

	printf("YES\n");
}