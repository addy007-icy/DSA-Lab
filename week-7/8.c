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
    
    printf("%d----->NULL\n",t->val);
}

int main()
{
    int n;
    int size=0;
    scanf("%d",&n);
    nodet *head;
    head=NULL;
    int el;
    int count=0;
    for(int i=0;i<n;i++){
        scanf("%d",&el);
        if(head==NULL){
            size++;
            push(&head,el);
            disp(&head);
            continue;
        }
        else if(el<=head->val){
            count+=size;
            size++;
            push(&head,el);
          //  disp(&head);
        }
       else{
            count+=size;
            if(head != NULL){
            while(1){
                size--;
                pop(&head);
                if(head==NULL)
                    break;
                }
            }
            push(&head,el);
            size++;
        }
        disp(&head);
        printf("%d\n",size);
    }
    printf("Answer %d\n",count);
return 0;
}
