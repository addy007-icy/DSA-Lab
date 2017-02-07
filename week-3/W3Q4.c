#include<stdio.h>

int pre[104][104];


int main()
{  
	int n;
	scanf("%d",&n);
	int i,j,m;
	for(i=1;i<=n;i++)	
		for(j=1;j<=n;j++)
		{
			scanf("%d",&pre[i][j]);		
		}
	
	for(i=1;i<=n;i++)	
		for(j=1;j<=n;j++)
		{
			pre[i][j]=pre[i][j-1]+pre[i-1][j]-pre[i-1][j-1]+pre[i][j];	
		}
		
	long long maxsum= -100000000;
	
	
	for( m=1;m<=n;m++)
		for(i=1;i<=n-m;i++)	
			for(j=1;j<=n-m;j++)
			{
				if(maxsum<pre[i+m][j+m]+pre[i][j]-pre[i+m][j]-pre[i][j+m])
					maxsum=pre[i+m][j+m]+pre[i-1][j-1]-pre[i+m-1][j-1]-pre[i-1][j+m-1];	
			}
	printf("%lld\n",maxsum);
    return 0;
}
