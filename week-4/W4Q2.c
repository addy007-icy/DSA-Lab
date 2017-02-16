#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int a[10005];
int main()
{
    int n;
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    qsort(a,n,sizeof(int),cmpfunc);
    int curc=1;
    int maxc=1;
    int maxid = a[0];
    for(i=1;i<n;i++)
    {
        if(a[i] == a[i-1]){
            curc++;
        }
        else
        {
            curc=1;
        }
        if(curc > maxc)
        {
            maxc=curc;
            maxid=a[i];
        }
    }
    printf("%d ",maxid);
    return 0;
}
