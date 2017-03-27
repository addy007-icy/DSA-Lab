#include <stdio.h>

int main()
{
	int i,j,n,x,y,fl,ct[10]={0};
	scanf("%d",&n);
	int arr[n];
	for(i=0; i<n; i++){
		scanf("%d",&arr[i]);
	}
	for(i=0; i<n; i++){
		x = arr[i];
		fl = 1;
		while(x > 0){
			y = x%10;
			ct[y]++;
			x = x/10;
		}
		for(j=0; j<10; j++){
			if(ct[j] > 1 || (ct[1] == 1 && j != 1 && ct[j] == 1)){
				fl = 0;
				break;
			}
			else if(j!=0 && ct[j] == 1 && ct[0] == 1){
				fl = 0;
				break;
			}
		}
		if((ct[8]==1 && ct[4]==1 && ct[2]==1) || (ct[6]==1 && ct[3]==1 && ct[2]==1)){
			fl = 0;
		}
		if(fl == 1){
			printf("%d ",arr[i]);
		}
	}
	printf("\n");
	return 0;
}
