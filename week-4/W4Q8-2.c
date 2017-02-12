//(i,j,k) and (i,k,j) both are counted
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
	return (*(char *)a - *(char *)b);
}

int main()
{
	int n,i;
	scanf("%d",&n);
	int arr[n];
	for(i=0; i<n; i++){
		scanf("%d",&arr[i]);
	}
	qsort(arr,n,sizeof(int),compare);
	int ct=0;
	for(i=0; i<n; i++){
		int lo=0, hi=n-1;
		int key = arr[i];
		while(lo < hi){
			int sum = arr[lo]+arr[hi];
			if(sum == key){
				if(lo!=i && hi!=i){
					ct++;
				}
				lo++;
			}
			else if(sum > key){
				hi--;
			}
			else{
				lo++;
			}
		}
	}
	printf("%d\n",ct*2);
	return 0;
}
