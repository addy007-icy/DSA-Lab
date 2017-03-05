#include<stdio.h>

struct node {
    int val;
    struct node* next;
} *head;

// Add a node
void instertAtBeg(int d){
    struct node* newNo  =   (struct node*)malloc(sizeof(struct node));
    newNo->val=d;
    newNo->next= (head);
    head = newNo;
    return;
}

// Print the list
void printList()
{
    struct node* curr = head;
    while(curr != NULL){
        printf("%d ",curr->val);
        curr = curr -> next;
    }
    return;
}

// reverse the list
void RevList(struct node* curr, struct node* prev)
{
    if(curr->next == NULL)
    {
        head = curr;
        curr->next = prev;
        return;
    }
    struct node* newNo  =   (struct node*)malloc(sizeof(struct node));
    newNo = curr->next;
    curr->next = prev;
    RevList(newNo,curr);
    return;
}

int main()
{
    instertAtBeg(1);
    instertAtBeg(2);
    instertAtBeg(3);
    instertAtBeg(4);
    instertAtBeg(5);
    instertAtBeg(6);
    printList();
    RevList(head,NULL);
    printf("\n");
    printList();
    return 0;
}
