#include<stdio.h>
#include<string.h>

long long numk[]={2,22,222,3,33,333,4,44,444,5,55,555,6,66,666,7,77,777,7777,8,88,888,9,99,999,9999,0};

int main()
{  
	char s[100];
	scanf("%[^\n]s",s);
	int i,j,m;
	int n=strlen(s);
	int prev=1;
	for(i=0;i<n;i++)	
	{
		if(s[i]==' '){
		prev=1;
		printf("%lld",numk[26]);	
		continue;
		}

		if(numk[s[i]-'a']%10 == prev%10)
		printf(" ");	

		printf("%lld",numk[s[i]-'a']);	
		prev=numk[s[i]-'a'];

	}
	printf("\n");	
    	return 0;
}

