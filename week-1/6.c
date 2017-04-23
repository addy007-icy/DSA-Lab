#include <stdio.h>

int main()
{
	long long int n,c,p,i,ans=1;
	scanf("%lld %lld %lld",&c, &n, &p);
	for(i=1; i<=n; i++){
		ans = (ans * c) % p;
	}
	printf("%lld\n",ans);
	return 0;
}
