#include <stdio.h>

int main()
{
	int i,j,n,k,mi,ma,ans=0;
	scanf("%d %d",&n,&k);
	int arr[n];
	for(i=0; i<n; i++){
		scanf("%d",&arr[i]);
	}	
	for(i=0; i<=n-k; i++){
		mi = ma = arr[i];
		for(j=1; j<k; j++){
			if(arr[i+j] < mi)
				mi = arr[i+j];
			if(arr[i+j] > ma)
				ma = arr[i+j];
		}
		ans = ans + mi + ma;
	}
	printf("%d\n",ans);
	return 0;
}
