#include <stdio.h>
typedef struct node nodet;
struct node{
    nodet *next;
    int data;
};

nodet *create(int el){
    nodet *temp;
    temp=(nodet*)malloc(sizeof(nodet));
    temp->data=el;
    temp->next=NULL;
    return temp;
}

void push(nodet **p,int el){
    nodet *temp;
    temp=create(el);
    if((*p)==NULL){
        (*p)=temp;
        temp->next=(*p);
    }
    else{
        nodet *t;
        t=(*p);
        while(t->next != (*p))
            t=t->next;
            t->next=temp;
            temp->next=(*p);
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
    while(t->next != (*p)){
        printf("%d---->",t->data);
        t=t->next;
    }
    printf("%d----->head(%d)\n",t->data,(t->next)->data);
    
}
void del(nodet **p,int k){
    int cnt=2;
    nodet *t;
    t=(*p);
    while(cnt<k){
        t=t->next;
        cnt++;
    }
    nodet *temp;
    temp=t->next;
    t->next=(t->next)->next;
    free(temp);
    (*p)=t->next;
}
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    nodet *head;
    head=NULL;
int i;
    for(i=0;i<n;i++){
        push(&head,i+1);
    }
    while(n!=1){
        disp(&head);
        n--;
        del(&head,k);
    }
    printf("%d\n",head->data);
    return 0;
}
