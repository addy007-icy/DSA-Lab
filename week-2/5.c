#include<stdio.h>
#include<string.h>
long long int prime[1000];
int a=0;
void primeno(long long int n)//Calculating Prime Number
{
	int prime_check[n];
	int i,j,k;
	for(i = 0;i<n;i++)
	{
		prime_check[i]=1;
	}
	long long in=2;
	for(in=2;in<n;in++)
	{
		
		if(prime_check[in]==1)
		{
			long long int j=in;
			prime[a]=in;
			a++;
			while(j<=n)
			{
				prime_check[j]=0;
				j+=in;
			}
		}
		else
		{
			continue;
		}
	}

}
int main()
{
	long long int n;
	scanf("%lld",&n);
	primeno(n);
	int i,j;
	/*for(i=0;i<a;i++)
	{
		printf("%lld\n",prime[i]);
	}*/
		int count=0;
		for (int i = 0; i < a; ++i)
		{
			while(n%prime[i]==0)
			{
				printf("%lld\n", prime[i]);
				n=n/prime[i];
				count++;
			}
		}
		printf("%d\n", count);

	return 0;
}