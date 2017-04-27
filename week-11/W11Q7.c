#include<stdio.h>

int fac(int n,int r)
{
	if(n==r)
		return 1;
	if(r==1)
		return n;
	return fac(n-1,r-1)+fac(n-1,r);
}

int main()
{
	int n,r;
	scanf("%d %d",&n,&r);
	int ans = fac(n,r);
	printf("%d",ans);
	return 0;
}
