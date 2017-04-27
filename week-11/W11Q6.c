#include<stdio.h>
/*
int mini(int a,int b)
{
	if(a<b)
		return a;
	return b;
}
int n;
int ans = 10000;
int min_coins(int N ,int arr[],int min)
{
	int i=0;
	//int minn = 10000;
	if(N<arr[0])
		return;
		
	printf("  %d  %d  \n",N,min);
	
		
	for(i=0;i<n-1;i++)
	{
		if(N<arr[i])
			return;
		if(N==arr[i])
			{
				printf("Kadamba %d %d\n",i+1,min+1);
				ans = mini(ans,min+1);
				return;
			}
		else
		{
			min_coins(N-arr[i],arr,min+1);
		}
	}
	
	//return mini(minn,ans);
}

int main()
{

	scanf("%d",&n);
	int arr[n];
	int i,j;
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	int N;
	scanf("%d",&N);
	
min_coins(N,arr,0);
	printf("\n\n%d",ans);
	
	return 0;
}*/
int n;
int minCoins(int coins[], int m, int V)
{
   // base case
   if (V == 0) return 0;
 
   // Initialize result
   int res = 10000;
 
   int i;// Try every coin that has smaller value than V
   for ( i=0; i<m; i++)
   {
     if (coins[i] <= V)
     {
         int sub_res = minCoins(coins, m, V-coins[i]);
 
         // Check for INT_MAX to avoid overflow and see if
         // result can minimized
         if (sub_res != 10000 && sub_res + 1 < res)
            res = sub_res + 1;
     }
   }
   return res;
}
 
// Driver program to test above function
int main()
{
    scanf("%d",&n);
	int arr[n];
	int i,j;
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	int N;
	scanf("%d",&N);
    printf( "Minimum coins required is %d"
         , minCoins(arr, n, N));
    return 0;
}
