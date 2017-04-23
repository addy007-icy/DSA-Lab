#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


char s[50];

int top = -1;
int tp = -1;

typedef struct et tree;

struct et
{
    char value;
    struct et *left;
    struct et *right;
};

tree *st[50]; //stack holding tree pointers

int isOperator(char c)
{
    if (c == '+' || c == '-' ||
            c == '*' || c == '/' )
        return 1;
    return 0;
}

void postorder(tree *t)
{
    if (t)
    {
        postorder(t->left);
        postorder(t->right);
        printf("%c", t->value);

    }
}
void preorder(tree *t)
{
    if (t)
    {
        printf("%c", t->value);
        preorder(t->left);
        preorder(t->right);
    }
}

tree* newNode(int v)
{
    tree *temp = (tree*)malloc(sizeof(tree));
    temp->left = temp->right = NULL;
    temp->value = v;
    return temp;
};

tree* constructTree(char postfix[])
{
    tree *st[50];
    tree *t, *t1, *t2;

    for (int i = 0; i < strlen(postfix); i++)
    {
        if (!isOperator(postfix[i]))
        {
            t = newNode(postfix[i]);
            st[++tp] = t;
        }
        else
        {
            t = newNode(postfix[i]);

            t1 = st[tp];
            tp--;
            t2 = st[tp];
            tp--;

            t->right = t1;
            t->left = t2;

            st[++tp] = t;
        }
    }

    t = st[tp];
    tp--;;

    return t;
}


int push(char elem)
{
    s[++top] = elem;
}

char pop()
{
    return (s[top--]);
}

int pr(char elem)
{
    switch (elem)
    {
    case '#': return 0;
    case '(': return 1;
    case '+':
    case '-': return 2;
    case '*':
    case '/': return 3;
    }
}

void main()
{
    char infx[50], pofx[50], ch, elem;
    int i = 0, k = 0;

    scanf("%s", infx);
    push('#');

    while ( (ch = infx[i++]) != '\0')
    {
        if ( ch == '(')
            push(ch);
        else if (isalnum(ch))
            pofx[k++] = ch;
        else if ( ch == ')')
        {
            while ( s[top] != '(')
                pofx[k++] = pop();
            elem = pop();
        }
        else
        {
            while ( pr(s[top]) >= pr(ch) )
                pofx[k++] = pop();
            push(ch);
        }
    }
    while ( s[top] != '#')
        pofx[k++] = pop();
    pofx[k] = '\0';

    tree* r = constructTree(pofx);
    printf("Postfix : ");
    postorder(r);
    printf("\n");
    printf("Prefix  : ");
    preorder(r);
    printf("\n");


}
