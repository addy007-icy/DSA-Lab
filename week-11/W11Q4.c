#include<stdio.h>

int max(int a,int b)
{
	if(a<b)
		return b;
	else
		return a;
}

int maxi(int a,int b,int c)
{
	return max(max(a,b),c);
}
 
int maxcrosssubarray(int arr[],int low,int mid,int high)
{
	int left_sum=-10000;
	int right_sum =-10000;
	
	int i,j;
	int sum = 0;
	for(i=mid;i>=low;i--)
	{
		sum+=arr[i];
		if(sum>left_sum)
			left_sum = sum;
	}
	
	sum = 0;
	
	for(i=mid+1;i<=high;i++)
	{
		sum+=arr[i];
		if(sum>right_sum)
			right_sum = sum;
	}
	
	//printf("%d %d %d %d\n",low,high,left_sum,right_sum);
	
	
	if(left_sum>=0&&right_sum>=0)
		return left_sum + right_sum;
	else if(left_sum>=0&&right_sum<0)
		return left_sum;	
	else if(left_sum<0&&right_sum>0)
		return right_sum;
	else
		{
			return arr[mid];
		}
	
}

int maxsubarray(int arr[],int low,int high)
{
	if(low==high)
	{
		return arr[low];
	}
	else
	{
		int mid = low + (high-low)/2;
		return maxi(maxsubarray(arr,low,mid),maxsubarray(arr,mid+1,high),maxcrosssubarray(arr,low,mid,high));	
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	int arr[n];
	int i,j;
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	int ans = maxsubarray(arr,0,n-1);
	printf("%d",ans);
	return 0;
}
