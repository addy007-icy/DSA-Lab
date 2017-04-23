#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int a=0,arr[n];
	
	for(a=0;a<n;a++)
		scanf("%d",&arr[a]);
	
	qsort(arr,n,sizeof(int),cmpfunc);
	int sub=0,ans=0;
	while(arr[n-m]!=0)
	{
		ans+=arr[n-m];
		int dum=arr[n-m];
		for(a=n-m;a<n;a++)
			arr[a]-=dum;
		qsort(arr,n,sizeof(int),cmpfunc);
	}
	
	printf("%d",ans);
	
return 0;
}
