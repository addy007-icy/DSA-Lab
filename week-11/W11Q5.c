#include<stdio.h>

long long int poww(int a,int b)
{
	if(b==0)
		return 1;
	if(b%2==0)
		return poww(a,b/2)*poww(a,b/2);
	else
		return poww(a,b/2)*poww(a,b/2)*a;
}

int main()
{
	int num,pow;
	scanf("%d %d",&num,&pow);
	long long int ans = poww(num,pow);
	printf("ans  :: \n :: %lld",ans);
	return 0;
}
