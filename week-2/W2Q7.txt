#include<stdio.h>
int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	int x = n-k+1;
	int arr[n];
	arr[0] = 1;
	int j = 1;
	int q = 2;
	for(j=1;j<=x;j++)
	{
		arr[j] = 0;
	}
	while(j<n)
	{
		arr[j] = q++;
		j++;
	}
	int i;
	for ( i = 0; i < n; ++i)
	{
		printf("%d",arr[i]);
	}
	int lar[n];
	lar[0] = 9;
	j=1;
	for(j=1;j<x;j++)
	{
		lar[j] = 9;
	}
	q=8;
	while(j<n)
	{
		lar[j] = q--;
		j++;
	}
	printf("\n");
	for ( i = 0; i < n; ++i)
	{
		printf("%d",lar[i]);
	}

	return 0;
}