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
		printf("Stack already empty\n");
	}
	else if(size == 1){
		printf("%d removed\n",heap[0]);
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
		printf("%d removed\n",heap[size]);		
	}
}

int main()
{
	int heap[105], sz = 0, choice, num;
	printf("1. Insert a number\n2. Delete Maximum Number\n3. Find Maximum\n4. Exit\n");
	while(1){
		scanf("%d",&choice);
		if(choice == 1){
			printf("Element to insert: ");
			scanf("%d",&num);
			insert(heap, num, &sz);
		}
		else if(choice == 2){
			delete(heap, &sz);			
		}
		else if(choice == 3){
			int max = findMax(heap,sz); 
			if(max != -1){
				printf("max=%d\n",max);
			}
		}
		else{
			printf("Exiting\n");
			break;
		}
	}	
	return 0;
}
