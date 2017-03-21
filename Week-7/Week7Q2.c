#include <stdio.h>
#include<stdlib.h>
typedef struct node nodet;

struct node{
    int data;
    nodet *next;
};

void push(nodet **p){
    int el;
    scanf("%d",&el);
    nodet *temp;
    temp=(nodet*)malloc(sizeof(nodet));
    temp->data=el;
    temp->next=NULL;

    if((*p) == NULL){
        (*p)=temp;
    }
    else{
        temp->next=(*p);
        (*p)=temp;
    }

}

void disp(nodet **p){
    nodet *temp;
    temp=(*p);
    if((*p)==NULL){
        printf("Empty List\n");
        return;
    }
    while(temp->next != NULL){
        printf("%d----->",temp->data);
        temp=temp->next;
    }
    printf("%d\n",temp->data);
}
void fix(nodet **p){
   if(  (*p)==NULL || (*p)->next==NULL)
    return;

    nodet *prev,*cur,*nxt;
    prev=*p;
    cur=prev->next;

    (*p)=cur;

    while(1){
        nxt=cur->next;
        cur->next=prev;

        if(nxt==NULL || nxt->next==NULL){
            prev->next=nxt;
            break;
        }

        prev->next=nxt->next;

        prev=nxt;
        cur=prev->next;

    }


}


int main()
{
    int n,i;
    nodet *head;
    head=NULL;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        push(&head);

    disp(&head);
    fix(&head);
    disp(&head);
    return 0;
}
