
struct node{
	int data;
	 struct node *next;
};

void push(struct node** head, int newdata){
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = newdata;
	newnode->next = *head;
	*head = newnode;
}

void printlist(struct node* node){
	while(node!=NULL){
		printf("%d -> ",node->data);
		node = node->next;
	}
	printf("NULL\n");
}

struct node* reverse(struct node** head){
	struct node* prev = NULL;
	struct node* current = *head;
	struct node* next;
	while(current != NULL){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head = prev;
}

int main(){
	struct node* a = NULL;
	int n,x;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&x);
		push(&a,x);
	}
	printf("Original list : ");
	printlist(a);
	reverse(&a);
	printf("Reversed list : ");
	printlist(a);
	return 0;
}
