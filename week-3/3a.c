#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size,n,m;
    scanf("%d",&size);
    n = size;
    m = size;
    int a[size][size];
    int l = 0;
    int k = 0;
    int i;
    int num = 1;

    while(l < n && k < m)
    {
        for(i = l; i < n; i++)
        {
            a[k][i] = num;
            num++;
        }
        k++;

        for(i = k; i < m; i++)
        {
            a[i][n-1] = num;
            num++;
        }
        n--;
        if(k < m)
        {
            for(i = n-1; i >= l; i--)
            {
                a[m-1][i] = num;
                num++;
            }
            m--;
        }

        if(l < n)
        {
            for(i = m-1; i >= k; i--)
            {
                a[i][l] = num;
                num++;
            }
            l++;
        }

    }
    int j;
    for(i = 0; i < size; i++){
        for(j = 0; j < size; j++)
        printf("%d ",a[i][j]);
        printf("\n");
    }
    return 0;
}
