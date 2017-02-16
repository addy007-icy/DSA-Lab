#include <stdio.h>

int find(int arr[], int n)
{
	int index = 0, count = 1, i;
	for (i = 1; i < n; i++)
	{
		if (arr[index] == arr[i])
		{
			count++;
		}
		else
		{
			count--;
		}
		if (count == 0)
		{
			index = i;
			count = 1;
		}

	}
	return arr[index];
}

int major(int arr[],int x,int n)
{
	int i,count = 0;
	for(i=0;i<n;i++)
	{
		if(arr[i] == x)
		{
			count++;
		}
	}
	if(count >n/2)
		printf("%d\n", x);
	else
		printf("None\n");
	return 0;

}

int main(char argc, char *argv[])
{
	int i, n;
	scanf("%d", &n);
	int arr[n];
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);			// use moore's vote algorithm
	int x = find(arr, n);
	major(arr,x,n);

	return 0;

}