//WAP to implement binary search
#include <stdio.h>
int BS(int a[],int start,int end,int x);
int main() {
    int a[] = {2, 5, 7, 10, 15, 18, 20};
    int n = sizeof(a) / sizeof(a[0]);
    int x ;
    printf("enter element to be searched\n");
    scanf("%d",&x);
    int result = BS(a, 0,n-1, x);
    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found in the array\n");
    return 0;
}

int BS(int a[], int start,int end ,int x)
{
    int mid = (start + end)  / 2;
    if (a[mid] == x)
        return mid;

    if (start== end)
        return -1;
    if (a[mid] < x)
        return BS(a,mid+1,end,x);
        
    else
        return BS(a,start,mid-1,x);
    
   
}