// C++ program to find surpasser count of each element
// in array
//#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
//using namespace std;

/* Function to merge the two haves arr[l..m] and
   arr[m+1..r] of array arr[] */
int merge(int arr[], int l, int m, int r,
         int *hm)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];

    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0, j = 0, k = l;
    int c = 0;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            // increment inversion count of L[i]
            hm[L[i]] += c;
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = R[j++];

            // inversion found
            c++;
        }
    }

    /* Copy the remaining elements of L[], if
    there are any */
    while (i < n1)
    {
        hm[L[i]] += c;
        arr[k++] = L[i++];
    }

    /* Copy the remaining elements of R[], if
    there are any */
    while (j < n2)
        arr[k++] = R[j++];
}

/* l is for left index and r is right index of
the sub-array of arr to be sorted */
int mergeSort(int arr[], int l, int r,
              int *hm)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m, hm);
        mergeSort(arr, m + 1, r, hm);
        merge(arr, l, m, r, hm);
    }
}

/* Function to print an array */
void printArray(int arr[], int n)
{
    int i;
    for ( i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void findSurpasser(int arr[], int n)
{
    // To store inversion count for elements
   int *hm=(int *)malloc(1000* sizeof(int));

    // To store copy of array
    int dup[n];
    //memcpy(dup, arr, n*sizeof(arr[0]));
    int i;
    for(i=0;i<n;i++){
        dup[i]=arr[i];
    }

    // Sort the copy and store inversion count
    // for each element.
    mergeSort(dup, 0, n - 1, hm);

    printf("Surpasser Count of array is \n");
    for (i = 0; i < n; i++)
        printf("%d ", (n-i-1)-((n - 1) - i - hm[arr[i]]));
}

/* Driver program to test above functions */
int main()
{
   // int arr[] = { 2, 7, 5, 3, 0, 8, 1 };
    int arr[]={5,8,1,6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Given array is \n");
    printArray(arr, n);

    findSurpasser(arr, n);

    return 0;
}