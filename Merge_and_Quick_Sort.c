#include <stdio.h>

void merge(int arr[], int low, int mid, int high) {
    int i, j, k;
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++){
        L[i] = arr[low + i];
    }
    for (j = 0; j < n2; j++){
        R[j] = arr[mid + 1 + j];
    }
    i=0;
    j=0;
    k=low;
    while (i < n1 && j < n2) {
        if (L[i] < R[j]) {
            arr[k] = L[i];
            i++;
        } 
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    } 
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        
        int mid = (low + high) / 2;

       
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1,high);

       
        merge(arr, low, mid, high);
    }
}


void swap(int arr[],int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}


int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low-1 ; 
    int j;

     for(j=low;j<high;j++)
     {
        if(arr[j] < pivot){
            i++;
           swap(arr,i, j);
         }
    }
    
    swap(arr,i+1,high);
    return i+1;
}


void quickSort(int arr[], int low, int high) {
    if (low < high) {
        
        int pi = partition(arr, low, high);

        
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Given array is \n");
    printArray(arr, n);

    mergeSort(arr, 0, n - 1);

    printf("\nSorted array using Merge Sort is \n");
    printArray(arr, n);

    int arr2[] = {10, 7, 8, 9, 1, 5};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    printf("\nGiven array is \n");
    printArray(arr2, n2);

    quickSort(arr2, 0, n2-1);

    printf("\nSorted array using Quick Sort is \n");
    printArray(arr2, n2);
    return 0;
}