#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int binary_search(int arr[], int l, int h, int x)
{	if (l <= h)
	{
		int m = l + (h - l) / 2;
		if (x == arr[m])
		{	printf("found at %d\n", m + 1);
			return 0;
		}
		else if (x < arr[m])
		{
			binary_search(arr, l, m - 1, x);
		}
		else
		{
			binary_search(arr, m + 1, h, x);

		}
	}
	else
	return -1;
}

int ternary_search(int arr[], int l, int h, int x)
{	if (l <= h)
	{
		int m1 = l + (h - l) / 3;
		int m2 = l + (h - l) * 2 / 3;
		if (x == arr[m1])
		{	printf("found at %d\n", m1 + 1);
			return 0;
		}
		if (x == arr[m2])
		{	printf("found at %d\n", m2 + 1);
			return 0;
		}
		else if (x < arr[m1])
		{
			ternary_search(arr, l, m1 - 1, x);
		}
		else if ( x > arr[m2])
		{
			ternary_search(arr, m2 + 1, h, x);
		}
		else
		{
			ternary_search(arr, m1 + 1, m2 - 1, x);
		}
	}
	else
	return -1;
}

int main(int argc, char *argv[])
{
	int i, j, k = 0;
	int n, x ;
	if (argc < 2)
	{
		printf("enter t for ternary or b for binary search\n");
		return 0;
	}
	scanf("%d %d", &n, &x);
	int arr[n];
	srand(time(NULL));
	for (i = 0; i < n; i++)
	{
		int k = rand();
		arr[i] = k;
	}
	int ans;
	if (strcmp(argv[1], "t") == 0)
		ans = ternary_search(arr, 0, n - 1, x);
	if (strcmp(argv[1], "b") == 0)
		ans = binary_search(arr, 0, n - 1, x);
	if(ans < 0)
		printf("%d\n", ans);
	return 0;
}