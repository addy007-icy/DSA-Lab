#include <stdio.h>
typedef struct node nodet;
struct node{
    nodet *next;
    nodet *prev;
    int data;
};

nodet *create(int da){
    nodet *temp;
    temp=(nodet*)malloc(sizeof(nodet));
    temp->next=NULL;
    temp->prev=NULL;
    temp->data=da;
    return temp;
}


void ib(nodet **p){
    int el;
    scanf("%d",&el);
    nodet *temp=create(el);
    if((*p)==NULL){
        (*p)=temp;
        temp->next=temp;
        temp->prev=temp;
        return;
    }
    nodet *r;
    temp->next=(*p);
    ((*p)->prev)->next=temp;
    temp->prev=(*p)->prev;
    (*p)=temp;
}

void ie(nodet **p){
    int el;
    scanf("%d",&el);
    nodet *temp=create(el);
    if((*p)==NULL){
        (*p)=temp;
        temp->next=(*p);
        temp->prev=(*p);
        return;
    }
    else{
        nodet *r;
        r=(*p);
        while(r->next != (*p))
            r=r->next;
        r->next=temp;
        temp->prev=r;
        temp->next=(*p);
        (*p)->prev=temp;
    }

}

void im(nodet **p,int i){
    int cnt=2;
    int el;
    scanf("%d",&el);
    nodet *temp;
    temp=create(el);
    nodet *r;
    r=(*p);
    if((*p)==NULL){
        printf("Illegal Index");
        return;
    }
    while(cnt<i){
        r=r->next;
        if(r== (*p)){
            printf("Illeagal Index");
            return;
        }
        cnt++;
    }
    temp->next=r->next;
    temp->prev=r;
    (r->next)->prev=temp;
    r->next=temp;


}

void disp(nodet **p){
    if((*p)==NULL){
        printf("Empty\n");
        return;
    }
    nodet *temp;
    temp=(*p);
    while(temp->next != (*p)){
        printf("%d---->",temp->data);
        temp=temp->next;
    }
    printf("%d---->%d(head)\n",temp->data,(temp->next)->data);
}

int main()
{
    int ch;
    nodet *head=NULL;
    int in;
    do{
        scanf("%d",&ch);
        disp(&head);
        switch(ch){
            case 1:
                    ib(&head);
                    break;
            case 2:ie(&head);
                    break;
            case 3:scanf("%d",&in);
                    if(in==1)
                        ib(&head);
                    else
                        im(&head,in);
                    break;
            case 4:
                    break;
        }
    }while(ch>=1 && ch<=4);
    return 0;
}
