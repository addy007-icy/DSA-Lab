#include<stdio.h>
#include<string.h>

int a[10][10];

int pupd(int x,int y){
	int i,j;i=x-1;j=y;
	for(;i>=1;i--){
	if(a[i][j]==1) return 0;
	}
	i=x+1;j=y;
	for(;i<=8;i++){
	if(a[i][j]==1) return 0;
	}
	return 1;
}

int plr(int x,int y){
	int i,j;i=x;j=y-1;
	for(;j>=1;j--){
	if(a[i][j]==1) return 0;
	}
	i=x;j=y+1;
	for(;j<=8;j++){
	if(a[i][j]==1) return 0;
	}
	return 1;
}

int pekd(int x,int y){
	int i,j;i=x-1;j=y-1;
	for(;j>=1 && i>=1;j--,i--){
	if(a[i][j]==1) return 0;
	}
	i=x+1;j=y+1;
	for(;j<=8 && i<=8;j++,i++){
	if(a[i][j]==1) return 0;
	}
	return 1;
}



int psecondd(int x,int y){
	int i,j;i=x-1;j=y+1;
	for(;j<=8 && i>=1;j++,i--){
	if(a[i][j]==1) return 0;
	}
	i=x+1;j=y-1;
	for(;i<=8 && j>=1;j--,i++){
	if(a[i][j]==1) return 0;
	}
	return 1;
}


int possible(int x,int y){
	if(pupd(x,y)==0) return 0;
	if(plr(x,y)==0) return 0;
	if(pekd(x,y)==0) return 0;
	if(psecondd(x,y)==0) return 0;
	return 1;
}


int main()
{  
	
	int i,j;
	
	for(i=1;i<=8;i++)
	{
		for(j=1;j<=8;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}

	for(i=1;i<=8;i++)
	{
		for(j=1;j<=8;j++)
		{
			if(a[i][j]==1){
				if(possible(i,j) == 0)
				{
					printf("NO\n");
					return 0;
				}
			}
		}
	}
	printf("YES\n");
    	return 0;
}

