#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <time.h>

void insort(long int *arr, long int n)
{	long int i, j;
	long int index;

	for (i = 1; i < n; i++)
	{
		long int key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}


int swap(long int *x, long int *y)
{
	long int temp = *x;
	*x = *y;
	*y = temp;
}

int bs(long int *arr, long int n)
{
	long int i, j;

	for (i = 0; i < n - 1; i++)
	{	int swapped = 0;
		for (j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
			}
		}

	}

}

int bbs(long int *arr, long int n)				
{
	long int start = 0,i;
	long int end = n - 1;
	int swapped = 1;
	while (swapped)
	{
		swapped = 0;

		for (i = start; i < end; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				swap(&arr[i], &arr[i + 1]);
				swapped = 1;
			}
		}

		if(!swapped)
		{
			break;
		}
		
		swapped = 0;
		end--;

		for(i=end-1;i>=start;i--)
		{
			if (arr[i] > arr[i + 1])
			{
				swap(&arr[i], &arr[i + 1]);
				swapped = 1;
			}
		}
		++start;
	}

}

int main(char argc, char *argv[])
{
	long int i, j;
	long int *array;
	clock_t start_t,end_t;
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

	if (strcmp(argv[2], "insort") == 0)
	{	
		insort(array, atoi(argv[1]));
		for (i = 0; i < 10; i++)
			printf("%ld\n", array[i]);	
											//insorted output
		end_t = clock();
	}

	if (strcmp(argv[2], "bbs") == 0)
	{
		bbs(array, atoi(argv[1]));
		for (i = 0; i < 10; i++)
			printf("%ld\n", array[i]);		//bidirectional bubble sorted output 
		end_t = clock();
	}

	if (strcmp(argv[2], "bs") == 0)
	{
		bs(array, atoi(argv[1]));
		for (i = 0; i < 10; i++)
			printf("%ld\n", array[i]);			//bubble sorted output
		end_t = clock();
	}

	total_t = (double)(end_t-start_t)/CLOCKS_PER_SEC;		//computing time
	printf("Time taken for the %s function = %f\n", argv[2], total_t);
	return 0;

}
