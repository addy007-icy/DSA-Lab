//Program to count the number of 1s in the binary representation of N.
#include <stdio.h>

int main()
{
	long long int n;
	scanf("%lld", &n);
	long long int m = n, ct=0;
	while(m>0){
		int rem = m%2;
		m = m/2;
		if(rem == 1) 
			ct++;
	}	
	printf("%lld\n",ct);
	return 0;
}
