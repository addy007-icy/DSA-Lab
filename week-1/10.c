#include <stdio.h>

int multiply(int x, int res[], int sz)
{
	int i,carry = 0;
	for(i=0; i<sz; i++){
		int prod = res[i]*x + carry;
		res[i] = prod % 10;
		carry = prod/10;
	}
	while(carry!=0){
		res[sz] = carry%10;
		carry = carry/10;
		sz++;
	}
	return sz;
}

void factorial(int n)
{
	int res[500];
	res[0] = 1;
	int sz = 1;
	for(int x=2; x<=n; x++){
		sz = multiply(x, res, sz);
	}
	printf("Factorial of given number: ");
	for(int i=sz-1; i>=0; i--)
		printf("%d", res[i]);
}

int main()
{
	factorial(100);
	return 0;
}
