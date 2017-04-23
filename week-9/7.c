// C++ program for implementation of Heap Sort
#include <stdio.h>

typedef struct ob O;

struct ob
{
    int data;
    int r;
    int c;
};

void swap(O *x, O *y)
{
    O temp = *x;
    *x = *y;
    *y = temp;
}
void heapify(O *arr, int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l].data < arr[largest].data)
        largest = l;

    if (r < n && arr[r].data < arr[largest].data)
        largest = r;

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(O *arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void printArray(O *arr, int n)
{
    for (int i = 0; i < n; ++i)
        printf("%d %d %d\n", arr[i].data, arr[i].r, arr[i].c);
}

int main()
{   int i, j, n, m, c = 0;
    scanf("%d %d", &n, &m);
    O a[(n * m)];                       //space complexity = O(3n) ~~ O(n);
    int arr[n][m];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &arr[i][j]);
            a[c].data = arr[i][j];
            a[c].r = i;
            a[c].c = j;
            c++;
        }
    }

    heapSort(a, n * m);

    printArray(a, n * m);
}