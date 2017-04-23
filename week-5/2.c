#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <time.h>

int swap(long int *x, long int *y)
{
	long int temp = *x;
	*x = *y;
	*y = temp;
}


int merge(long int *arr, long int l, long int m, long int r)
{	long int i , j, k;
	long int n1 = m - l + 1;
	long int n2 = r - m;
	long int l1[n1];
	long int r2[n2];
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

int mergesort(long int arr[], long int l, long int r)
{
	if (l < r)
	{	long int m = l + (r - l) / 2;
		mergesort(arr, l, m);
		mergesort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}


long int getNextGap(long int gap)
{

	gap = (gap * 10) / 13;

	if (gap < 1)
		return 1;
	return gap;
}

void comb(long int *a, long int n)
{
	long int gap = n;

	int swapped = 1;

	while (gap != 1 || swapped == 1)
	{
		gap = getNextGap(gap);

		swapped = 0;
		long int i;
		for ( i = 0; i < n - gap; i++)
		{
			if (a[i] > a[i + gap])
			{
				swap(&a[i], &a[i + gap]);
				swapped = 1;
			}
		}
	}
}




int partition (long int *arr, long int low, long int high)
{
	long int pivot = arr[high];    
	long int i = (low - 1);  
	long int j;

	for ( j = low; j <= high - 1; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}


void quick(long int *arr, long int low, long int high)
{
	if (low < high)
	{
		long int pi = partition(arr, low, high);

		quick(arr, low, pi - 1);
		quick(arr, pi + 1, high);
	}
}



int main(char argc, char *argv[])		
{
	long int i, j;
	long int *array;
	clock_t start_t, end_t;
	double total_t;

	start_t = clock();
	array = (long int *)malloc(atoi(argv[1]) * sizeof(long int));
	srand(time(NULL));

	if(argc < 3)
	{
		printf("USAGE: ./a.out size algorithm\n");
		return 0;
	}

	for (i = 0; i < atoi(argv[1]); i++)
	{
		array[i] = rand() % 10000001;
	}
	printf("unsorted array : \n");
	for (i = 0; i < 10; i++)
		printf("%ld\n", array[i]);	//unsorted output

	printf("\n");
	printf("\n");

	if (strcmp(argv[2], "comb") == 0)
	{
		comb(array, atoi(argv[1]));
		for (i = 0; i < 10; i++)
			printf("%ld\n", array[i]);			//comb sort output
		end_t = clock();
	}

	if (strcmp(argv[2], "merge") == 0)
	{
		mergesort(array, 0, (atoi(argv[1]) - 1));
		for (i = 0; i < 10; i++)
			printf("%ld\n", array[i]);		//merge sorted output
		end_t = clock();
	}

	if (strcmp(argv[2], "quick") == 0)
	{
		quick(array, 0, (atoi(argv[1]) - 1));
		for (i = 0; i < 10; i++)
			printf("%ld\n", array[i]);			//quick sorted output
		end_t = clock();
	}

	total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;		//computing time
	printf("Time taken for the %s function = %f\n", argv[2], total_t);
	return 0;

}
