#include <stdio.h>

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void printMin(int heap[], int sz)
{
    if(sz == 0)
        printf("Heap Empty\n");
    else
        printf("min = %d\n",heap[0]);
}

void insert(int heap[], int x, int* sz)
{
	*sz = *sz + 1;
	int size = *sz, idx = size-1, par = (idx-1)/2;
	heap[idx] = x;
	while(idx != 0){
		if(heap[par] > heap[idx]){
			swap(&heap[par], &heap[idx]);
		}
		idx = par;
		par = (idx-1)/2;
	}
}

void delete(int heap[], int x, int* sz)
{
    int i, size = *sz;
    for(i=0; i<size; i++){
        if(heap[i] == x){
            break;
        }
    }
    //printf("%d %d\n",x,i);
    if(i == size-1){
        (*sz)--;
        return;
    }
    else{
        swap(&heap[i], &heap[size-1]);
        (*sz)--;
        size--;
        int curr = i, par = (i-1)/2, ch1 = 2*i+1, ch2 = 2*i+2;
        if(curr !=0 && heap[curr] < heap[par]){
            while(curr != 0){
                if(heap[curr] < heap[par]){
                    swap(&heap[curr], &heap[par]);
                }
                else{
                    break;
                }
                par = (curr-1)/2;
            }
        }
        else{
            while(ch1 < size){
			    if(ch2 >= size){
				    if(heap[curr] > heap[ch1]){
					    swap(&heap[curr], &heap[ch1]);
					    curr = ch1;
					    ch1 = curr*2+1;
					    ch2 = curr*2+2;
				    }
				    else{
					    break;
				    }
			    }
			    else{
				    if(heap[ch1] <= heap[ch2]){
					    if(heap[curr] > heap[ch1]){
						    swap(&heap[curr], &heap[ch1]);
						    curr = ch1;
						    ch1 = curr*2+1;
						    ch2 = curr*2+2;
					    }
					    else{
						    break;
					    }
				    }
				    else{
					    if(heap[curr] > heap[ch2]){
						    swap(&heap[curr], &heap[ch2]);
						    curr = ch2;
						    ch1 = curr*2+1;
						    ch2 = curr*2+2;
					    }
					    else{
						    break;
					    }
				    }
			    }
		    }
        }
    }
}

int main()
{
    int q,type,x,heap[105],sz=0;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&type);
        if(type == 1){
            scanf("%d",&x);
            insert(heap,x,&sz);
        }
        else if(type == 2){
            scanf("%d",&x);
            delete(heap,x,&sz);
        }
        else if(type == 3){
            printMin(heap,sz);
        }
    }
    return 0;
}
