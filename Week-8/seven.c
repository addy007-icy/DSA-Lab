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

int main()
{
	int i,n,x;
	scanf("%d",&n);
	int heap[n+1],sz=0;
	for(i=0; i<n; i++){
		scanf("%d",&x);
		insert(heap,x,&sz);
	}
	while(sz != 1){
		delete(heap,&sz);
	}
	for(i=0; i<n; i++){
		printf("%d ",heap[i]);
	}
	printf("\n");
	return 0;
}
