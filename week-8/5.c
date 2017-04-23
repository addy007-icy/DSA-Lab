#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stacknode
{
	char data;
	struct stacknode* next;
}stacknode; 

void push(stacknode **top, char x)
{
	stacknode* tmp = (stacknode*)malloc(sizeof(stacknode));
	tmp -> data = x;
	tmp -> next = *top;
	*top = tmp;
}

int pop(stacknode **top)
{
	if(*top == NULL)
		return -1;
	stacknode* tmp = *top;
	*top = (*top) -> next;
	free(tmp);
	return 0;
}

int main()
{
	stacknode* top = NULL;
	int max = 0, ct = 0, curr = 0, i;
	char str[105];
	scanf("%s",str);
	int len = strlen(str);
	for(i=0; i<len; i++){
		if(str[i] == '('){
			push(&top, str[i]);
		}
		else{
			if(pop(&top) != -1){
				curr += 2;
			}
			else{
				if(curr > max){
					max = curr;
					curr = 0;
					ct = 1;
				}
				else if(curr != 0 && curr == max){
					curr = 0;
					ct++;
				}
			}
		}
	}
	if(curr > max){
		max = curr;
		ct = 1;
	}
	else if(curr == max){
		ct++;
	}
	if(max == 0){
		printf("0 1\n");
	}
	else{
		printf("%d %d\n",max, ct);
	}
	return 0;
}
