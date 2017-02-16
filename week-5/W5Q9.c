#include <stdio.h>

int swap( int *x,  int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int modulo(int arr[], int n)
{
	int mod = 0, index = 0, i, j;
	while (index < n)
	{
		for (j = 0; j < n; ++j)
		{
			if (( arr[j] % 10 ) == mod)
			{
				swap(&arr[j], &arr[index]);
				index++;
			}

		}
		mod++;
	}

}



int main()
{
	int i, n, j;
	scanf("%d", &n);
	int arr[n];
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	for (i = 1; i < n; i++)
	{
		int key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)		//sort the given array on O(n^2)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}

	for (i = 0; i < n; i++)
		printf("%d\n ", arr[i]);

	modulo(arr, n);

	

	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);

	return 0;

}
