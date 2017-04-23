#include <stdio.h>
typedef struct node nodet;
struct node{
    nodet *next;
    int data;
};


int check(nodet **p){
    nodet *s,*t;
    int len=1;
    s=(*p);
    t=s;
    while(t->next != NULL){
        len++;
        t=t->next;
    }
    printf("Length %d\n",len);
    len/=2;
    int i=0;
    while(i<len){
        if(s->data != t->data)
            return 0;
        i++;
    }
    return 1;

}

nodet *create(int el){
    nodet *temp;
    temp=(nodet*)malloc(sizeof(nodet));
    temp->data=el;
    temp->next=NULL;
    return temp;
}

void ib(nodet **p,int el){
    nodet *temp;
    temp=create(el);
    if((*p)==NULL)
       (*p)=temp;
     else{
         temp->next=(*p);
         (*p)=temp;
     }
}

void disp(nodet **p){
    if((*p)==NULL){
        printf("Empty\n");
        return;
    }
    nodet *t;
    t=(*p);
    while(t->next != NULL){
        printf("%d------>",t->data);
        t=t->next;
    }

    printf("%d\n",t->data);
}



int main()
{
nodet *head;
head=NULL;
int n,el,i;
scanf("%d",&n);
for(i=0;i<n;i++){
    disp(&head);
    scanf("%d",&el);
    ib(&head,el);
}
disp(&head);
int k;
k=check(&head);
printf("%d\n",k);
return 0;
}
