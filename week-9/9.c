#include <stdio.h>
#include <string.h>
#include <limits.h>

int min (int a, int b)
{
    return (a < b) ? a : b;
}

int minPalPartion(char *str)
{
    int n = strlen(str);

    int C[n];
    int P[n][n];

    int i, j, k, L;

    for (i = 0; i < n; i++)
    {
        P[i][i] = 1;
    }

    for (L = 2; L <= n; L++)
    {
        for (i = 0; i < n - L + 1; i++)
        {
            j = i + L - 1;

            if (L == 2)
                P[i][j] = (str[i] == str[j]);
            else
                P[i][j] = (str[i] == str[j]) && P[i + 1][j - 1];
        }
    }

    for (i = 0; i < n; i++)
    {
        if (P[0][i] == 1)
            C[i] = 0;
        else
        {
            C[i] = INT_MAX;
            for (j = 0; j < i; j++)
            {
                if (P[j + 1][i] == 1 && 1 + C[j] < C[i])
                    C[i] = 1 + C[j];
            }
        }
    }
    int c = 0;
    for (i = 0; i <n; i++)
    {
        for (j = n - 1; j >= i; j--)
        {
            if (P[i][j] == 1)
            {
                for (k = i; k <= j; k++)
                {
                    printf("%c", str[k]);
                }
                c++;
                if (c == C[n - 1] + 1)
                    return C[n - 1];
            }
            printf("\n");
        }
    }


    return C[n - 1];
}

int main()
{
    char str[256];
    scanf("%s", str);
    printf("\nMin number of strings with Palindrome Partitioning is %d",
           minPalPartion(str) + 1);
    return 0;
}