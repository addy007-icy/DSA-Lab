#include<stdio.h>
#include<stdlib.h>

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int main(){
	int n =11,k=0,i,j,n1=4;
	int A1[] = { 2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8 };
	int A2[] = { 2,1,8,3},*A3;
	
	qsort(A1,11,sizeof(int),cmpfunc);
	
	A3 = (int*) malloc(n*sizeof(int));
	
	for(i=0;i<n1;i++){
		for(j=0;j<n;j++){
			if(A2[i] == A1[j]) {
				A3[k++] = A2[i];
				A1[j] = -123;
			}
		}
	}
	
	for(i=0;i<n;i++){
		if(A1[i]!=-123) A3[k++] = A1[i];
	}
	
	for(i=0;i<n;i++){
		printf("%d ",A3[i]);
	}
	
	 
	
	return 0;
}
