#include <stdio.h>

int merge(int arr[], int l, int m, int r)
{	int i , j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	int l1[n1];
	int r2[n2];
	for (i = 0; i < n1; i++)
	{
		l1[i] = arr[l + i];
	}
	for (j = 0; j < n2; j++)
	{
		r2[j] = arr[m + 1 + j];
	}
	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (l1[i] <= r2[j])
		{
			arr[k] = l1[i];
			i++;

		}
		else
		{
			arr[k] = r2[j];
			j++;

		}
		k++;
	}

	while (i < n1)
	{
		arr[k] = l1[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		arr[k] = r2[j];
		j++;
		k++;
	}
}

int mergesort(int arr[], int l, int r)
{
	if (l < r)
	{	int m = l + (r - l) / 2;
		mergesort(arr, l, m);
		mergesort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}


int main()
{
	int i, j, size, k;
	scanf("%d", &size);
	int arr[size];
	for (i = 0; i < size; i++)
	{
		scanf("%d", &arr[i]);
	}

	mergesort(arr, 0, size - 1);
	int flag = 0;

	for (k = 0; k < size; k++)
	{
		for (i = 0, j = size - 1; i < j;)
		{
				if (i != k && j != k)
			{

				int sum = arr[i] + arr[j];
				if (sum == arr[k])
				{
					flag ++;
					// printf("FOUND: %d + %d = %d\n",arr[i],arr[j],arr[k]);
					i++;

				}
				else if (sum < arr[k])
				{
					i++;

				}
				else
				{
					j--;
				}
			}
			if (i == k)
			{
				i++;
			}
			if (j == k)
			{
				j--;
			}
		}
	}
	printf("%d\n", flag);
	return 0;
}