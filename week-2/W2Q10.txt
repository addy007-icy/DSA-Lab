#include <stdio.h>

int main(){
	int m,i;
	scanf("%d",&m);
	while(m--){
		char a[100];
		scanf("%s",a);
		int n = strlen(a);
		for(i=0;i<n;i++){
			a[i] = a[i] - '0';
		}
		int count=0;
		for(i=0;i<n/2;i++){
			if(a[i] > a[n-1-i]){
				count=1;
				break;
			}
		}

		if(count == 1){
			for(i=0;i<=n/2;i++){
				a[n-i-1] = a[i];
			}
		}
		else{
			a[(n-1)/2]++;
			for(i=0;i<=n/2;i++){
				a[n-i-1] = a[i];
			}	
		}

		for(i=0;i<n;i++){
			printf("%d",a[i]);
		}
		printf("\n");
	}
}
