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
	int i, j, n, k;
	scanf("%d", &n);
	int arr[n];
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	mergesort(arr, 0, n - 1);

	int flag = 0;

	for (k = 0; k < n; k++)
	{	//printf("%d\n", k);
		for (i = 0, j = n - 1; i < j;)
		{	
				if (i != k && j != k)
			{	//printf("%d %d\n", i, j);
				int sum = arr[i] + arr[j];
				if (sum == arr[k])
				{
					flag ++;
					// printf("%d + %d = %d\n",arr[i],arr[j],arr[k]);
					//break;
					i++;

				}
				else if (sum < k)
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
	if (flag == 0)
		printf("NOT FOUND ");
	else
		printf("number of triplets -> %d\n", flag);
	return 0;
}