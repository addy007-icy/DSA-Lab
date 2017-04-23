#include <stdio.h>

long int search(long int *c,long int ele)
{	
	long int i;
	if(c[ele] == ele)
		return ele;
	else
		return 0;
}

long int main()
{
	long int i,n,k=0;
	scanf("%ld", &n);
	long int count=0;
	long int a[n],w[n],c[10000];
	for(i=0;i<10000;i++)
	{
		c[i] = -1;
	}
	for(i=0;i<n;i++)
	{
		scanf("%ld %ld", &a[i], &w[i]);
	}
	for(i=0;i<n;i++)
	{
		if(a[i] != w[i])
		{	
			long int q = search(c,w[i]);	
			if( q == 0)
			{
				c[a[i]] = a[i];
				//printf("%ld\n", a[i]);
				count++;
			}
			else
			{
				c[q] = -1;
			}
			
		}
	}
	// for(i=0;i<n+5;i++)
	// {
	// 	printf("c = %ld\n", c[i]);
	// }
	printf("%ld\n", count);
}