#include <stdio.h>

int main()
{
	long long int n, i, ans=1, m=10000000000ll;
	scanf("%lld",&n);
	for(i=1; i<=n; i++){
		ans = (ans * 2) % m;
	}
	printf("%lld\n",ans);
	return 0;
}
