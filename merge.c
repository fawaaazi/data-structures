#include <stdio.h>
void mergeSort(int arr[],int left,int right);
void merge(int arr[],int left,int mid,int right);
int main() {
    int arr[100];
    int n;
    int i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    mergeSort(arr,0,n-1);
    printf("Sorted array:\n");
    for(i=0;i<n;i++){
    	printf("%d\t",arr[i]);
    }	
    
    
}

void mergeSort(int arr[],int left,int right) {
    if (left < right) {
        int mid =left+(right-left)/2;

       
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}

void merge(int arr[],int left,int mid,int right) {
    int n1 =mid-left + 1;
    int n2=right-mid;
    int j,i,k;
	
    
    int L[n1], R[n2];
    for (i=0;i < n1; i++){
        L[i]=arr[left+i];
       } 
    for (j=0;j<n2;j++){
        R[j]=arr[mid+1+j];
	}
    i=0;
    j=0;
    k=left;
    while (i < n1 && j < n2) {
        if (L[i]<=R[j]) {
            arr[k]=L[i];
            i++;
        } else {
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    while (i<n1) {
        arr[k]=L[i];
        i++;
        k++;
    }


    while (j<n2) {
        arr[k]=R[j];
        j++;
        k++;
    }
}

