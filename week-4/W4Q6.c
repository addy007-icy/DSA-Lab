#include<stdio.h>
#include <stdlib.h>
int a[10005];
int n,X;
int binar(int x)
{
    int l,r;
    l=1; r=n;
    while (l <= r)
      {
        int m = l + (r-l)/2;

        if (a[m] == x)
            return 1;

        if (a[m] < x)
            l = m + 1;
        else
             r = m - 1;
      }
    return 0;
}
int main()
{
    scanf("%d%d",&n,&X);
    int i;
    for(i=1;i<=n;i++)
    scanf("%d",&a[i]);
    for(i=1;i<=n;i++)
    {
        if(binar(X-a[i]) == 1)
        {
                printf("Yes\n");
                return 0;
        }
    }
    printf("No\n");
    return 0;
}
