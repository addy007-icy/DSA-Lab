#include<stdio.h>
#include <stdlib.h>

int a[10005];
int n;
int binar(int l, int r){
    int mid = (l + r )/2;

    printf("%d\n",a[mid]);
    if(!(a[mid] < a[mid+1] || a[mid] <a [mid-1]))
    {
   //     printf("%d\n",a[mid]);
        return mid;
    }
    if(a[mid]<=a[mid-1] && mid!=1 )
    {
            return binar(l,mid-1);
    }
    if(a[mid]<=a[mid+1] && mid!=n)
    {
        return binar(mid+1,r);
    }
    if(mid == 1 || mid == n) return mid;
    return -1;
}

int main()
{
    scanf("%d",&n);
    int i;
    a[0] = 100000;
    a[n+1] = 100000;
    for(i=1;i<=n;i++)
    scanf("%d",&a[i]);
    printf("%d",binar(1,n)-1);
    return 0;
}
