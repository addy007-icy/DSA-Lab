#include <stdio.h>
typedef struct node nodet;
struct node{
    int data;
    nodet *next;
};

void push(nodet **nt,int el){
    nodet *temp;
    temp=(nodet*)malloc(sizeof(temp));
    
    temp->data=el;
    temp->next=(*nt);
    (*nt)=temp;
}

void pop(nodet **nt){
    nodet *temp;
    temp=(*nt);
    (*nt)=(*nt)->next;
    free(temp);
}

void display(nodet *nt){
    if(nt==NULL)
        printf("Empty\n");
    else{
        while(nt->next != NULL){
            printf("%d----->",nt->data);
            nt=nt->next;
        }
        printf("%d\n",nt->data);
    }
}
void swag(nodet **p,int m,int k){
    nodet *t;
    nodet *temp,*cur;
    cur=NULL;
    
    t=(*p);
    if(k!=1){
        int cnt=1;
        while(cnt<k){
            cnt++;
            if(t==NULL){
                printf("Illegal");
                return;
            }
            cur=t;
            t=t->next;
        }
    }
    printf("%d %d\n",cur->data,t->data);
    temp=t;
    nodet *fal,*gal;
    gal=t;
    fal=cur;
    while(m--){
       // printf("IN");
       t=t->next;
       temp->next=cur;
       cur=temp;
       temp=t;
       printf("%d %d\n",cur->data,temp->data);
    }   
    gal->next=t;
    fal->next=cur;
    
    
}

int main()
{
    nodet *l;
    l=NULL;
    int n;
    scanf("%d",&n);
    int i;
    int el;
    
    for(i=0;i<n;i++){
        scanf("%d",&el);
        push(&l,el);
        }
    display(l);
    int m,k;
    scanf("%d %d",&m,&k);
    swag(&l,m,k);
    display(l);
    return 0;
}
