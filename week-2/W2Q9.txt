#include<stdio.h>

int l1,hi_index;
int leastindex=10000;
int n;
int maxindex = -1;
int str_len(char s[])
{
	int i = 0;
	while(s[i]!='\0')
	{
		i++;
	}	
	return i;
}

int min(int a,int b)
{
	if(a<b)
		return a;
	else
		return b;		
}

int max(int a,int b)
{
	if(a<b)
		return b;
	else
		return a;
}

int binary_str_leastindex(char list[][100],char check_str[],int start,int end)
{
	if(start>end)
	{
		//printf("\n");
		return 0;
	}

	int l = (start + end)/2;
	int l2 = str_len(list[l]);
	//printf("%d l here \n",l);
	int i=0,j=0;
	if(l2==l1)
	{
			while(i<l1&&j<l2&&list[l][i]==check_str[j])
		{
			i++;
			j++;
		}
		if(i==l2)
		{
			leastindex = min(leastindex,l);
			maxindex = max(maxindex,l);
			binary_str_leastindex(list,check_str,start,l-1);
			binary_str_leastindex(list,check_str,l+1,end);
		}
		else
		{
			if(list[l][i]>check_str[j])
			{
				binary_str_leastindex(list,check_str,start,l-1);	
			}
			else
			{
				binary_str_leastindex(list,check_str,l+1,end);	
			}
		}

	}
	else
	{
		if(l1<l2)
		{
			while(list[l][i]==check_str[j]&&i<l1)
			{
				i++;
				j++;
			}
			if(i==l1)
			{
				binary_str_leastindex(list,check_str,start,l-1);
			}
			else
			{
				if(list[l][i]>check_str[j])
			{
				binary_str_leastindex(list,check_str,start,l-1);	
			}
			else
			{
				binary_str_leastindex(list,check_str,l+1,n);	
			}
			}
		}
		else
		{
			while(list[l][i]==check_str[j]&&j<l2)
			{
				i++;
				j++;
			}
			if(j==l2)
			{
				binary_str_leastindex(list,check_str,start,l-1);
			}
			else
			{
				if(list[l][i]>check_str[j])
			{
				binary_str_leastindex(list,check_str,start,l-1);	
			}
			else
			{
				binary_str_leastindex(list,check_str,l+1,n);	
			}
			}
		}
	}
}


int main()
{
	scanf("%d",&n);
	char list[n][100];
	char check_str[100];
	int i,j;
	for(i = 0;i<n;i++)
	{	
		scanf("%s",list[i]);
	}

	scanf("%s",check_str);
	l1 = str_len(check_str);
	binary_str_leastindex(list,check_str,0,n-1);
	printf("leastindex:%d\n", leastindex);

	//binary_str_maxindex(list,check_str,0,n);
	printf("maxindex:%d\n", maxindex);

	int ans = maxindex - leastindex + 1;

	printf("count:%d\n", ans);
	return 0;
}