#include <stdio.h>

int binary(long int prince[],long  int ele,long  int n)
{
	int first = 0;
	int last = n - 1;

	while (first <= last)
	{
		int mid = (first + last) / 2;
		if (ele == prince[mid])
			return 1;
		else if (ele < prince[mid])
			last = mid - 1;
		else
			first = mid + 1;
	}
	return 0;
}

int main()
{
	long int i, n, m, k, count = 0;
	scanf("%ld", &m);
	long int qual[m];
	for (i = 0; i < m; i++)
	{
		scanf("%ld", &qual[i]);
	}
	// for (i = 0; i < m; i++)
	// {
	// 	printf("qual = %d\n", qual[i]);
	// }

	scanf("%ld", &n);
	for (i = 0; i < n; i++)
	{	long int prince[1000];

		long int j = 0;
		
		long int size = 0;
		char c = ' ';
		while (c != '\n')
		{
			scanf("%ld%c", &prince[j++], &c);
			size++;

		}
		// for (k = 0; k < size; k++)
		// {
		// 	printf("prince = %d\n", prince[k]);
		// }
		int flag = 1;

		for (k = 0; k < m; k++)
		{
			int x = binary(prince, qual[k], size);
			if (x == 0)
			{
				flag = 0;
			}
		}
		if (flag == 1)
		{
			count++;
		}
	}
	printf("princes = count = %ld\n", count);
}
