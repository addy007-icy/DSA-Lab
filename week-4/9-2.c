#include<stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int t;
    char s[500];
    scanf("%[^\n]s",s);
    int n=strlen(s);
    char temp;
    int i;
    for( i=0;i<n/2;i++)
    {
            temp=s[i];;
            s[i] = s[n-i-1];
            s[n-i-1]=temp;
    }

    int r=0;
    int l=0;
    for( i=0;i<n;i++)
    {

        if(s[i]== ' ')
        {
            r=i-1;
            int ps=0;
            while( ps <= ((r-l)/2) )
            {
                temp=s[l+ps];
                s[l+ps] = s[r-ps];
                s[r-ps]=temp;
                ps++;
            }
            l=i+1;
        }

    }
    r=n-1;
    int ps=0;
    while( ps <= ((r-l)/2) )
            {
                temp=s[l+ps];
                s[l+ ps] = s[r-ps];
                s[r-ps]=temp;
                ps++;
            }
    printf("%s",s);

    return 0;
}
