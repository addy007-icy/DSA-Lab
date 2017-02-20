#include <stdio.h>
#include <stdlib.h>

int mergeSort(int arr[],int n){
    int *temp=(int *)malloc(n* sizeof(int));
    return _mergeSort(arr,temp,0,n-1);
}

int _mergeSort(int arr[],int temp[],int left,int right){
    int inv_count=0;

    if(left<right) {
        int mid=(left+right)/2;
        inv_count = _mergeSort(arr, temp, left, mid);
        inv_count += _mergeSort(arr, temp, mid + 1, right);
        inv_count += merge(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}

int merge(int arr[],int temp[],int left,int mid, int right){
    int i=left,j=mid,k=left;
    int inv_count=0;
    while(i<mid && j<=right){
        if(arr[i]<=arr[j])
            temp[k++]=arr[i++];
        else{
            temp[k++]=arr[j];
            int l;
            inv_count=inv_count+(mid-i);
            for(l=i;l<mid;l++)
                printf("%d %d \n",arr[l],arr[j]);

            j++;
        }

    }
    while(i<mid)
        temp[k++]=arr[i++];
    while (j<=right)
        temp[k++]=arr[j++];
    for(i=left;i<=right;i++)
        arr[i]=temp[i];
    return inv_count;
}
int main(){
    int n;
    scanf("%d",&n);
    int i,j;
    int arr[n];
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("NUMBER OF INVERSIONS ARE: %d",mergeSort(arr,n));
    return 0;

}