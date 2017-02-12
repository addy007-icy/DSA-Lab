#include <stdio.h>

int findindex(int arr[], int l, int h)
{
	if(h<l)
		return 0;
	if(h == l)
		return arr[l];
	int m = l + (h-l)/2;
	if(m < h && arr[m+1] < arr[m])
		return m+1;
	if(m > l && arr[m] < arr[m -1])
		return m;
	if(arr[m] < arr[h])
		findindex(arr,l,m-1);
	else
		findindex(arr,m+1,h);
}

int main()
{
	int i, j, k = 0;
	int n ;
	scanf("%d", &n);
	int arr[n];
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	int ans = findindex(arr, 0, n - 1);

	printf("Pivot = %d element\n", ans+1);
	return 0;
}