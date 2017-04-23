#include <stdio.h>

int main()
{
	int n,i;
	scanf("%d",&n);
	int arr[n];
	for(i=0; i<n; i++)
		scanf("%d",&arr[i]);
	int fl=0, ct=0, max=0, tmp1=-1, tmp2=-1, ans = -1;
	for(i=0; i<=n; i++){
		if(i==n){
			if(i-tmp2 > max){
				max = i-tmp2;
				ans = tmp1;
			}
		}
		else if(arr[i] == 0){
			if(i-tmp2 > max){
				max = i-tmp2;
				ans = tmp1;
			}
			tmp2 = tmp1;
			tmp1 = i;
		}
	}
	printf("%d\n",ans);
	return 0;
}
