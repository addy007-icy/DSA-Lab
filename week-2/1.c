#include<stdio.h>
#include<string.h>
int main()
{
char s[100];
scanf("%s",s);
int l=strlen(s);
int arr[l-1];
int i;
for(i=0;i<l-1;i++)
{
	arr[i] = (int)s[l-i-2]-48;
	printf("%d",arr[i]);
}
int check=(int)s[i]-48;
printf("\n %d \n",check);
int final=0;
for(i=0;i<l-1;i++)
{
	if(i%2==0)
	{
		arr[i]*=2;
		if(arr[i]>10)
		{
			int x=arr[i]/10;
			int y=arr[i]%10;
			arr[i]=x+y;
		}
	}
	final+=arr[i];
}

final=final+check;
printf("%d",final);
if(final%10==0)
{
printf("Yes");
}
else
{
	printf("No");
}


return 0;
}
