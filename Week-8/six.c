#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void insert(int heap[], int x, int* sz)
{
	*sz = *sz + 1;
	int size = *sz, idx = size-1, par = (idx-1)/2;
	heap[idx] = x;
	while(idx != 0){
		if(heap[par] < heap[idx]){
			swap(&heap[par], &heap[idx]);
		}
		idx = par;
		par = (idx-1)/2;
	}
}

int findMax(int heap[], int sz)
{
	if(sz == 0){
		printf("Heap Empty\n");
		return -1;
	}
	else{
		return heap[0];
	}
}

void delete(int heap[], int *sz)
{
	int size = *sz;
	if(size == 0){
		printf("Invalid input\n");
	}
	else if(size == 1){
		*sz = *sz - 1;
	}
	else{
		swap(&heap[0], &heap[size-1]);
		*sz = *sz - 1;
		size--;
		int curr = 0, par1 = 1, par2 = 2;
		while(par1 < size || par2 < size){
			if(par2 >= size){
				if(heap[curr] < heap[par1]){
					swap(&heap[curr], &heap[par1]);
					curr = par1;
					par1 = curr*2+1;
					par2 = curr*2+2;
				}
				else{
					break;
				}
			}
			else{
				if(heap[par1] >= heap[par2]){
					if(heap[curr] < heap[par1]){
						swap(&heap[curr], &heap[par1]);
						curr = par1;
						par1 = curr*2+1;
						par2 = curr*2+2;
					}
					else{
						break;
					}
				}
				else{
					if(heap[curr] < heap[par2]){
						swap(&heap[curr], &heap[par2]);
						curr = par2;
						par1 = curr*2+1;
						par2 = curr*2+2;
					}
					else{
						break;
					}
				}
			}
		}
	}
}

void print(int heap[], int sz)
{
	int i;
	for(i=0; i<sz; i++){
		printf("%d ",heap[i]);
	}
	printf("\n");
}

int main()
{
	int i, heap[105], backup[105], sz1 = 0, sz2 = 0, num;
	char choice;
	printf("a. Insert a number\nb. Print elements of max heap\nc. Find kth largest element\nd. Exit\n");
	while(1){
		scanf(" %c",&choice);
		if(choice == 'a'){
			printf("Element to insert: ");
			scanf("%d",&num);
			insert(heap, num, &sz1);
			insert(backup, num, &sz2);
		}
		else if(choice == 'b'){
			print(heap, sz1);			
		}
		else if(choice == 'c'){
			printf("Input k: ");
			scanf("%d",&num);
			num--;
			while(num--){
				delete(heap,&sz1);
			}
			printf("%d\n",heap[0]);
			sz1 = sz2;
			for(i=0; i<sz1; i++){
				heap[i] = backup[i];
			}
		}
		else{
			printf("Exiting\n");
			break;
		}
	}
	return 0;
}
