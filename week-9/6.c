#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node Node;
struct node
{
    char data;
    Node* left, * right;
};

Node* newNode(char data);

int search(char arr[], int strt, int end, int value);

Node* buildUtil(char in[], char post[], int inStrt,
                int inEnd, int *pIndex)
{
    if (inStrt > inEnd)
        return NULL;

    Node *node = newNode(post[*pIndex]);
    (*pIndex)--;

    if (inStrt == inEnd)
        return node;

    int iIndex = search(in, inStrt, inEnd, node->data);

    node->right = buildUtil(in, post, iIndex + 1, inEnd, pIndex);
    node->left = buildUtil(in, post, inStrt, iIndex - 1, pIndex);

    return node;
}

Node *buildTree(char in[], char post[], int n)
{
    int pIndex = n - 1;
    return buildUtil(in, post, 0, n - 1, &pIndex);
}

int search(char arr[], int strt, int end, int value)
{
    int i;
    for (i = strt; i <= end; i++)
    {
        if (arr[i] == value)
            break;
    }
    return i;
}

Node* newNode(char data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

void preOrder(Node* node)
{
    if (node == NULL) return;
    printf("%c ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}

int main()
{
    char in[100];
    char post[100];
    scanf("%s", in);
    scanf("%s", post);

    int n = strlen(in);

    Node *root = buildTree(in, post, n);

    printf("Preorder = ");
    preOrder(root);

    return 0;
}