#include <stdio.h>
#include <string.h>

int main()
{
	int n,i,j;
	scanf("%d",&n);
	char name[n][55];
	int len, sum, binaryOnes[n], freq[15]={0}, ct;
	for(i=0; i<n; i++){
		scanf(" %s",name[i]);
		len = strlen(name[i]);
		sum = 0, ct = 0;
		for(j=0; j<len; j++){
			sum += name[i][j];
		}
		printf("%d ",sum);
		while(sum > 0){
			if(sum%2 == 1)
				ct++;
			sum = sum/2;
		}
		printf(" %d\n",ct);
		binaryOnes[i] = ct;
		freq[ct]++;
	}
	for(i=0; i<=14; i++){
		if(i!=0)
			freq[i] += freq[i-1];
	}
	char ans[n+1][55];
	for(i=n-1; i>=0; i--){
		strcpy(ans[freq[binaryOnes[i]]],name[i]);
		freq[binaryOnes[i]]--;
	}
	for(i=1; i<=n; i++){
		printf("%s\n",ans[i]);
	}
	return 0;
}
