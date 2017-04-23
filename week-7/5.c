#include <stdio.h>

typedef struct node nodet;

struct node{
    nodet *next;
    nodet *prev;
    int data;
};

nodet *create(int el){
    nodet *temp;
    temp=(nodet*)malloc(sizeof(nodet));
    temp->data=el;
    temp->next=NULL;
    temp->prev=NULL;
    return temp;
}

void ib(nodet **p,int el){
    nodet *temp;
    temp=create(el);
    if((*p)==NULL){
        (*p)=temp;
        temp->next=NULL;
        temp->prev=NULL;
        return;
    }
    else{
        temp->next=(*p);
        temp->prev=NULL;
        (*p)->prev=temp;
        (*p)=temp;
        
    }
}

void ie(nodet **p,int el){
    nodet *temp;
    temp=create(el);
    if((*p)==NULL){
        (*p)=temp;
        temp->next=NULL;
        temp->prev=NULL;
        return;
    }
    else{
        nodet *r;
        r=(*p);
        while(r->next != NULL)
            r=r->next;
        temp->prev=r;
        r->next=temp;
        temp->next=NULL;
    }
}

void disp(nodet **p)
{
    if((*p)==NULL){
        printf("Empty\n");
        return;
    }
    nodet *t;
    t=(*p);
    while(t->next != (NULL)){
        printf("%d---->",t->data);
        t=t->next;
    }
    printf("%d\n",t->data);
    
}
void revi(nodet **p){
    nodet *temp;
    temp=NULL;
    nodet *cur;
    cur=(*p);
    while(cur !=NULL){
        temp=cur->prev;
        cur->prev=cur->next;
        cur->next=temp;
        cur=cur->prev;
    }
    if(temp!=NULL)
        (*p)=temp->prev;
}

void revr(nodet **p){
    nodet *rest;
    rest=(*p)->next;
    if( (*p)==NULL)
        return;
    if(rest==NULL)
        return;
    revr(&rest);
    nodet *t;
    t=(*p)->prev;
    ((*p)->next)->next=(*p);
    rest->prev=NULL;
    (*p)->prev=((*p)->next);
    (*p)->next=t;
    (*p)=rest;
    }

int main()
{
    nodet *head;
    head=NULL;
    int choice,el;
    do{
        scanf("%d",&choice);
        disp(&head);
        switch(choice){
            case 1:scanf("%d",&el);
                    ib(&head,el);
                    break;
            case 2:scanf("%d",&el);
                    ie(&head,el);
                    break;
            case 3:revi(&head);
                    break;
            case 4:revr(&head);
                    break;
        }
    }while(choice>=1 && choice<=4);
    return 0;
}
