#include <stdio.h>

typedef struct{
	char name[30];
	char branch[20];
	double cgpa;
	int year;
	int group;
}student;

int main()
{
	int n,i;
	scanf("%d",&n);
	student std[n];
	int grp[4]={0}, ans[n+1];
	for(i=0; i<n; i++){
		scanf("%s %d",std[i].name, &std[i].group);
		grp[std[i].group]++;
	}
	for(i=1; i<=3; i++)
		grp[i] = grp[i-1]+grp[i];
	for(i=n-1; i>=0; i--){
		ans[grp[std[i].group]]=i;
		grp[std[i].group]--;
	}
	for(i=1; i<=n; i++){
		printf("%s\n",std[ans[i]].name);
	}
	return 0;
}
