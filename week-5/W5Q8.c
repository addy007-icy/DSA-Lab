#include <stdio.h>

int swap( int *x,  int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int modulo(int arr[], int n)
{
	int index = 0, i, j, swapped = 1;
	while (index < n && swapped == 1)
	{	swapped = 0;
		for (j = index+1 ; j < n; j++)
		{
			if (( arr[j] % 2 ) == 0)
			{	//printf("arr[j] = %d arr[%d] = %d\n", arr[j],index,arr[index]);
				swap(&arr[j], &arr[index]);
				index++;
				swapped = 1;
			}
		
		}
	}
}



int main()
{
	int i, n, j;
	scanf("%d", &n);
	int arr[n];
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	modulo(arr, n);

	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);

	return 0;

}
