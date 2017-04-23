#include <stdio.h>
typedef struct node nodet;
struct node{
    nodet *next;
    int val;
};

nodet *create(int el){
    nodet *temp;
    temp=(nodet*)malloc(sizeof(nodet));
    temp->val=el;
    temp->next=NULL;
    return temp;
}
void push(nodet **stack,int el){
    nodet *temp;
    temp=create(el);

    if((*stack)==NULL){
        (*stack)=temp;
        return;
    }
    else{
        temp->next=(*stack);
        (*stack)=temp;
    }
}

int pop(nodet **s){
    if((*s)==NULL){
        printf("Underflow");
        return -1;
    }
    else{
        nodet *temp;
        int ret;
        temp=(*s);
        ret=temp->val;
        (*s)=(*s)->next;
        free(temp);
        return ret;
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
        printf("%d------>",t->val);
        t=t->next;
    }

    printf("%d\n",t->val);
}

int main()
{
int i;
char str[100];
nodet *head;
head=NULL;
scanf("%s",str);
int len=strlen(str);
if(len%2 !=0){
    printf("Invalid\n");
    return;
}
for(i=0;i<len;i++){
    if(str[i]=='(')
        push(&head,0);
    else{
        if(head==NULL)
            push(&head,1);
        else if((head->val)==0){
            pop(&head);
            continue;
        }
        else
            push(&head,1);
    }
}
int count=0;
int t;
while(head!=NULL){
    t=pop(&head);
    //printf("Popped %d\n",t);
    //disp(&head);
    if(t==(head->val))
        count++;
    else
        count+=2;
    pop(&head);
}
printf("%d\n",count);
disp(&head);
return 0;
}
