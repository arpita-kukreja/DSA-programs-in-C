#include <stdio.h>


void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}


void selectionSort(int arr[], int n) {
    int i, j, min_idx;
   
    for (i = 0; i < n-1; i++) {
       
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        
        swap(&arr[min_idx], &arr[i]);
    }
}


void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        // Last i elements are already in place
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
        }
    }
}


void printArray(int arr[], int size) {
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++) 
	{
		key = arr[i];
		j = i - 1;


		while (j >= 0 && arr[j] > key) 
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}


int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    printf("Original array: \n");
    printArray(arr, n);
    
    selectionSort(arr, n);
    printf("Array sorted with Selection Sort: \n");
    printArray(arr, n);
    int arr1[] = {32,63,21,11,4,23,70};
    int n1= sizeof(arr1)/sizeof(arr1[0]);
    printf("Original array: \n");
    printArray(arr1, n1);
    bubbleSort(arr1, n1);
    printf("Array sorted with Bubble Sort: \n");
    printArray(arr1, n1);
    int arr2[] = {35,97,24,48,91};
    int n2= sizeof(arr2)/sizeof(arr2[0]);
    printf("Original array: \n");
    printArray(arr2, n2);
    insertionSort(arr2, n2);
    printf("Array sorted with Inertion Sort: \n");
    printArray(arr2, n2) ; 
    return 0;
}