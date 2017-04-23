#include <stdio.h>
#include <string.h>
// using namespace std;
int n, c;
int func(int num, int array[])
{
    int cows = 1, pos = array[0];
    for (int i = 1; i < n; i++)
    {
        if (array[i] - pos >= num)
        {
            pos = array[i];
            cows++;
            if (cows == c)
                return 1;
        }
    }
    return 0;
}
int bs(int array[])
{
    int ini = 0, last = array[n - 1], max = -1;
    while (last > ini)
    {
        //cout<<last<<" "<<ini<<endl;
        int mid = (ini + last) / 2;
        if (func(mid, array) == 1)
        {
            //cout<<mid<<endl;
            if (mid > max)
                max = mid;
            ini = mid + 1;
        }
        else
            last = mid;
    }
    return max;
}
int main()
{
    int t,i,j;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d %d", &n, &c);
        int arr[n];
        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        int index;

        for (i = 1; i < n; i++)
        {
            int key = arr[i];
            j = i - 1;
            while (j >= 0 && arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
        //cout<<" dfsa \n";
        int k = bs(arr);
        printf("%d\n", k);
    }
    return 0;
}
