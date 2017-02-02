#include<stdio.h>
#include<string.h>
char boom[100];
int main()
{
	char s[100];
	int n;
	scanf("%[^\n]%*c",s);
	//printf("\n%s\n",s);
	scanf("%d",&n);
	//printf("%d",n);
	int l=strlen(s);
	int i,len=0,j=0;
	char boom[100];
	for(i=0;i<l;i++)
	{
		if(s[i]!=' ')
		{
			boom[len] = s[i];
			len++;
		}
	}
	char ans[len];
	int p = 0;
	for ( i = 0; i < n; ++i)
	{
		while(i+j<len)
		{
			ans[p]=boom[i+j];
			j+=n;
			p++;
		}
		j=0;
		ans[p]='\0';
		printf("\n%s\n",ans);
	}

	   return 0;
}