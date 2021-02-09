#include<stdio.h>

int temp;

void heapify(int arr[], int size, int i)  
{  
    int largest = i;    
    int left = 2*i + 1;    
    int right = 2*i + 2;    
  
    if (left < size && arr[left] > arr[largest])  
        largest = left;  
  
    if (right < size && arr[right] > arr[largest])  
        largest = right;  

    if (largest != i)  
    {  
        temp = arr[i];  
        arr[i]= arr[largest];   
        arr[largest] = temp;  
        heapify(arr, size, largest);  
    }  
} 

void heapifyMin(int arr[], int size, int i)  
{  
    int largest = i;    
    int left = 2*i + 1;    
    int right = 2*i + 2;    
  
    if (left < size && arr[left] < arr[largest])  
        largest = left;  
  
    if (right < size && arr[right] < arr[largest])  
        largest = right;  
  
    if (largest != i)  
    {  
        temp = arr[i];  
        arr[i]= arr[largest];   
        arr[largest] = temp;  
        heapify(arr, size, largest);  
    }  
} 

void heapSortMax(int arr[], int size)  
{    
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(arr, size, i);
    }  
    for (int i=size-1; i>=0; i--)  
    {  
        temp = arr[0];  
        arr[0]= arr[i];   
        arr[i] = temp;  
        heapify(arr, i, 0);  
    }  
}  


void heapSortMin(int arr[], int size)  
{    
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapifyMin(arr, size, i);
    }  
    for (int i=size-1; i>=0; i--)  
    {  
        temp = arr[0];  
        arr[0]= arr[i];   
        arr[i] = temp;  
        heapifyMin(arr, i, 0);  
    }  
}  


int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("\nEnter the %d elements of the array: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);    
    }
    
    printf("\nThe given array is: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    heapSortMax(arr, n);

    printf("Sorted array in Max Heap Sort is: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    heapSortMin(arr, n);
    
    printf("\nSorted array in Min Heap Sort is: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
